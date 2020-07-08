/****************************************************************************
Copyright (c) 2016 - 2019 Qualcomm Technologies International, Ltd.


FILE NAME
    audio_input_spdif_connect.c

DESCRIPTION
    Implementation of AUDIO_PLUGIN_CONNECT_MSG message for spdif source.
    Remaining message handlers are implemented in audio_input_common library.
*/

#include <operators.h>
#include <audio.h>
#include <audio_config.h>
#include <audio_mixer.h>
#include <audio_ports.h>
#include <print.h>

#include "audio_input_spdif_broadcast.h"
#include "audio_input_spdif_private.h"
#include "audio_input_spdif_connect.h"
#include "audio_input_spdif_driver.h"
#include "audio_input_spdif_chain_config.h"
#include "audio_input_common.h"


#define SPDIF_SAMPLE_SIZE            (24)
#define TTP_BUFFER_SIZE             (4096)
#define TTP_BUFFER_SIZE_BROADCASTER (1024)
#define SPDIF_BA_KICK_PERIOD (5000)

typedef enum
{
    spdif_source_left,
    spdif_source_right,
    spdif_source_interleaved

} spdif_source_t;

static A2dpPluginConnectParams *getConnectParamsFromMessage(Message message);
static kymera_chain_handle_t createChain(Task task, uint32 sample_rate);
static void createSources(audio_input_context_t *ctx);
static Source createSpdifSource(spdif_source_t source_type);
static void configureSpdifSource(Source source);
static void synchroniseSpdifSources(Source left_source, Source right_source);
static void connectSourcesToChain(audio_input_context_t *ctx);
static void connectChainToMixer(audio_input_context_t *ctx);


/****************************************************************************
DESCRIPTION
    AUDIO_PLUGIN_CONNECT_MSG message handler.
    It creates Kymera chain and connects it to audio mixer.
*/
void AudioInputSpdifConnectHandler( Task task,
                                    Message connect_message,
                                    audio_input_context_t *ctx)
{
    A2dpPluginConnectParams *connect_params = getConnectParamsFromMessage(connect_message);

    PRINT(("AudioInputSpdifConnect\n"));

    AudioInputCommonDspPowerOn();
    OperatorsFrameworkSetKickPeriod(AudioInputCommonGetKickPeriod());

    /* The Spdif is a variable sample rate input, dynamically changing the 
    buffer size each time the sample rate changes is not possible with current  
    architecture. Hence the configuration item max sample rate is used which 
    indicates the maximum sample rate that will be used when using the variable
    rate input, the buffer allocation for the operators are done only once
    using this configuration item.*/

    ctx->sample_rate = AudioConfigGetMaxSampleRate();
    ctx->tws.mute_until_start_forwarding = connect_params->peer_is_available;
    
    AudioInputCommonSetMusicProcessingContext(ctx, connect_params);
    
    AudioInputSpdifConnect(task, connect_message, ctx);
}

void AudioInputSpdifConnect(Task task, Message msg, audio_input_context_t *ctx)
{
    if (!AudioInputCommonTaskIsBroadcaster(task))
    {
        ctx->chain = createChain(task, ctx->sample_rate);
        ChainConnect(ctx->chain);

        createSources(ctx);
        
        connectSourcesToChain(ctx);
    
        connectChainToMixer(ctx);    
      
        ChainStart(ctx->chain);
    
        AudioInputCommonConnect(ctx, task);
    }
    else
    {
        PRINT(("spdif broadcast\n"));
        
        ctx->ba.plugin = getConnectParamsFromMessage(msg)->ba_output_plugin;

        OperatorsFrameworkSetKickPeriod(SPDIF_BA_KICK_PERIOD); 

        ctx->chain = createChain(task, ctx->sample_rate);
        
        ChainConnect(ctx->chain);
        
        createSources(ctx);
        
        connectSourcesToChain(ctx);
        
        audioInputSpdifBroadcastCreate(task, ctx->ba.plugin, ctx);
        
        SetAudioBusy(task);
    }
}

A2dpPluginConnectParams *getConnectParamsFromMessage(Message message)
{
    const AUDIO_PLUGIN_CONNECT_MSG_T* connect_message = (const AUDIO_PLUGIN_CONNECT_MSG_T*)message;

    return (A2dpPluginConnectParams *)connect_message->params;
}

/****************************************************************************
DESCRIPTION
    Create Kymera chain for spdif decoder.
*/
static kymera_chain_handle_t createChain(Task task, uint32 sample_rate)
{
    kymera_chain_handle_t chain;
    Operator spdif_op;
    Operator ttp_pass_op;
    Operator iir_resamp_op;
    const chain_config_t *chain_config = AudioInputSpdifGetChainConfig();
    chain = PanicNull(ChainCreate(chain_config));
    ttp_latency_t ttp_latency;
    uint16 ttp_buffer_size = TTP_BUFFER_SIZE;

    spdif_op = ChainGetOperatorByRole(chain, spdif_decoder_role);
    MessageOperatorTask(spdif_op, AudioInputSpdifGetDriverHandlerTask());
    
    iir_resamp_op = ChainGetOperatorByRole(chain, spdif_iir_resampler_role);
    OperatorsResamplerSetConversionRate(iir_resamp_op, sample_rate, AudioConfigGetMaxSampleRate());
    
    ttp_pass_op = ChainGetOperatorByRole(chain, spdif_ttp_passthrough_role);
    
    if (!AudioInputCommonTaskIsBroadcaster(task))
    {        
        ttp_latency = AudioConfigGetWiredTtpLatency();
        OperatorsStandardSetLatencyLimits(ttp_pass_op,
                                          TTP_LATENCY_IN_US(ttp_latency.min_in_ms),
                                          TTP_LATENCY_IN_US(ttp_latency.max_in_ms));
    }
    else
    {       
        ttp_latency.target_in_ms = TTP_WIRED_BA_LATENCY_IN_MS;
        OperatorsStandardSetLatencyLimits(ttp_pass_op,
                                          TTP_BA_MIN_LATENCY_LIMIT_US,
                                          TTP_BA_MAX_LATENCY_LIMIT_US);
        ttp_buffer_size = TTP_BUFFER_SIZE_BROADCASTER;
    }
    
    OperatorsConfigureTtpPassthrough(ttp_pass_op, TTP_LATENCY_IN_US(ttp_latency.target_in_ms), sample_rate, operator_data_format_pcm);
    OperatorsStandardSetBufferSizeWithFormat(ttp_pass_op, ttp_buffer_size, operator_data_format_pcm);
   
    return chain;
}



/****************************************************************************
DESCRIPTION
    Helper function to create sources.
*/
static void createSources(audio_input_context_t *ctx)
{
    Sink interleaved_sink = ChainGetInput(ctx->chain, spdif_input_interleaved);

    if(interleaved_sink)
    {
        PRINT(("Spdif input source: interleaved\n"));
        ctx->left_source = createSpdifSource(spdif_source_interleaved);
    }
    else
    {
        PRINT(("Spdif input source: two channel\n"));
        ctx->left_source = createSpdifSource(spdif_source_left);
        ctx->right_source = createSpdifSource(spdif_source_right);

        synchroniseSpdifSources(ctx->left_source, ctx->right_source);
    }
}

/****************************************************************************
DESCRIPTION
    Creates and configures selected spdif source.
*/
static Source createSpdifSource(spdif_source_t source_type)
{
    Source source = 0;
    audio_instance spdif_audio_instance = AudioConfigGetSpdifAudioInstance();

    switch(source_type)
    {
        case spdif_source_left:
        {
            source = StreamAudioSource(AUDIO_HARDWARE_SPDIF, spdif_audio_instance, SPDIF_CHANNEL_A);
            break;
        }

        case spdif_source_right:
        {
            source = StreamAudioSource(AUDIO_HARDWARE_SPDIF, spdif_audio_instance, SPDIF_CHANNEL_B);
            break;
        }

        case spdif_source_interleaved:
        {
            source = StreamAudioSource(AUDIO_HARDWARE_SPDIF, spdif_audio_instance, SPDIF_CHANNEL_A_B_INTERLEAVED);
            break;
        }

        default:
            Panic();
    }

    PanicNull(source);
    configureSpdifSource(source);

    return source;
}

/****************************************************************************
DESCRIPTION
    Configures spdif source.
*/
static void configureSpdifSource(Source source)
{
    PanicFalse(SourceConfigure(source, STREAM_AUDIO_SAMPLE_SIZE, SPDIF_SAMPLE_SIZE));
    PanicFalse(SourceConfigure(source, STREAM_SPDIF_AUTO_RATE_DETECT, TRUE));
    PanicFalse(SourceConfigure(source, STREAM_SPDIF_CHNL_STS_REPORT_MODE, TRUE));
}

/****************************************************************************
DESCRIPTION
    Helper function for synchronising spdif sources.
*/
static void synchroniseSpdifSources(Source left_source, Source right_source)
{
    PRINT(("Spdif input: synchronise sources\n"));
    PanicFalse(SourceSynchronise(left_source, right_source));
}

/****************************************************************************
DESCRIPTION
    Connect inputs to the operators chain.
*/
static void connectSourcesToChain(audio_input_context_t *ctx)
{
    Sink interleaved_sink = ChainGetInput(ctx->chain, spdif_input_interleaved);

    if(interleaved_sink)
    {
        PanicNull(StreamConnect(ctx->left_source, interleaved_sink));
    }
    else
    {
        PanicNull(StreamConnect(ctx->left_source, ChainGetInput(ctx->chain, spdif_input_left)));
        PanicNull(StreamConnect(ctx->right_source, ChainGetInput(ctx->chain, spdif_input_right)));
    }
}

/****************************************************************************
DESCRIPTION
    Connect the operators chain to the mixer.
*/
static void connectChainToMixer(audio_input_context_t *ctx)
{
    audio_mixer_connect_t connect_data;

    connect_data.left_src = ChainGetOutput(ctx->chain, spdif_output_left);
    connect_data.right_src = ChainGetOutput(ctx->chain, spdif_output_right);
    connect_data.connection_type = CONNECTION_TYPE_MUSIC;
    connect_data.sample_rate = ctx->sample_rate;
    connect_data.channel_mode = CHANNEL_MODE_STEREO;
    connect_data.variable_rate = FALSE;

    ctx->mixer_input = AudioMixerConnect(&connect_data);

    PanicFalse(ctx->mixer_input != audio_mixer_input_error_none);
}
