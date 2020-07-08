/****************************************************************************
Copyright (c) 2016 - 2019 Qualcomm Technologies International, Ltd.


FILE NAME
    audio_input_spdif.c

DESCRIPTION
    Message dispatcher.
*/
#include <stdlib.h>

#include <message.h>
#include <audio_plugin_if.h>
#include <audio_plugin_music_variants.h>
#include <audio_input_common.h>
#include <vmtypes.h>
#include <print.h>

#include "audio_input_spdif_private.h"
#include "audio_input_spdif.h"
#include "audio_input_spdif_connect.h"
#include "audio_input_spdif_broadcast.h"

static void dummyHandler(Task task, Message message, audio_input_context_t* ctx);
static void disconnected(Task task, Message message, audio_input_context_t* ctx);
static void start(Task task, Message message, audio_input_context_t* ctx);
static void handleForwardingCreate(Task task, Message message, audio_input_context_t* ctx);
static void handleForwardingStart(Task task, Message message, audio_input_context_t* ctx);
static void handleForwardingDestroy(Task task, Message message, audio_input_context_t* ctx);
static void handleDisconnectReq(Task task, Message message, audio_input_context_t* ctx);
static void cleanContextData(void);
static void setUpStateHandlers(void);
static audio_input_context_t *spdif_ctx = NULL;

const A2dpPluginTaskdata csr_spdif_decoder_plugin = {{AudioPluginSpdifMessageHandler}, SPDIF_DECODER, BITFIELD_CAST(8, 0)};
const A2dpPluginTaskdata csr_ba_spdif_decoder_plugin = {{AudioPluginSpdifMessageHandler}, BA_SPDIF_DECODER, BITFIELD_CAST(8, 0)};

static const audio_input_state_table_t spdif_state_table =
{
    {
        [audio_input_idle] = {[audio_input_connect_req] = AudioInputSpdifConnectHandler},
        [audio_input_connecting] = {[audio_input_connect_complete] = AudioInputCommonFadeInCompleteHandler, [audio_input_forward_created] = handleForwardingCreate, [audio_input_forward_started] = handleForwardingStart},
        [audio_input_connected] = {[audio_input_disconnect_req] = handleDisconnectReq, [audio_input_forward_req] = start},
        [audio_input_disconnecting] = {[audio_input_disconnect_complete] = disconnected, [audio_input_forward_stopped] = handleForwardingDestroy, [audio_input_forward_destroyed] = disconnected},
        [audio_input_forwarding_setup] = {[audio_input_forward_created] = handleForwardingCreate, [audio_input_forward_started] = handleForwardingStart, [audio_input_connect_complete] = AudioInputCommonFadeInCompleteHandler, [audio_input_error] = AudioInputCommonFadeOutCompleteHandler},
        [audio_input_forwarding] = {[audio_input_forward_stop_req] = AudioInputCommonForwardStop, [audio_input_disconnect_req] = handleDisconnectReq},
        [audio_input_forwarding_tear_down] = {[audio_input_forward_stopped] = handleForwardingDestroy, [audio_input_forward_destroyed] = AudioInputSpdifConnect, [audio_input_connect_complete] = AudioInputCommonFadeInCompleteHandler},
        [audio_input_forwarding_disconnect] = {[audio_input_disconnect_complete] = AudioInputCommonForwardStop, [audio_input_forward_stopped] = handleForwardingDestroy, [audio_input_forward_destroyed] = disconnected},
        [audio_input_error_state] = {[audio_input_disconnect_req] = dummyHandler}
    }
};


static void cleanContextData(void)
{
    free(spdif_ctx);
    spdif_ctx = NULL;
}

static void start(Task task, Message message, audio_input_context_t* ctx)
{
    AudioInputCommonForwardStart(task, message, ctx);
    ChainDestroy(ctx->chain);
    ctx->chain = NULL;
}


static void handleForwardingCreate(Task task, Message message, audio_input_context_t* ctx)
{
    if (AudioInputCommonTaskIsBroadcaster(task))
    {
        audioInputSpdifBroadcastStart(task, message, ctx);
    }
    else
    {
        AudioInputCommonForwardHandleCreateCfm(task, message, ctx);
    }
}

static void handleForwardingStart(Task task, Message message, audio_input_context_t* ctx)
{
    if (AudioInputCommonTaskIsBroadcaster(task))
    {
        audioInputSpdifBroadcastStartChain(task, message, ctx);
    }
    else
    {
        AudioInputCommonForwardHandleStartCfm(task, message, ctx);
    }
}

static void disconnected(Task task, Message message, audio_input_context_t* ctx)
{
    AudioInputCommonFadeOutCompleteHandler(task, message, ctx);
}

static void dummyHandler(Task task, Message message, audio_input_context_t* ctx)
{
    UNUSED(task);
    UNUSED(message);
    UNUSED(ctx);
}

static void handleForwardingDestroy(Task task, Message message, audio_input_context_t* ctx)
{
    if (AudioInputCommonTaskIsBroadcaster(task))
    {
        audioInputSpdifBroadcastDestroy(task, ctx->ba.plugin, ctx);
    }
    else
    {
        AudioInputCommonForwardDestroy(task, message, ctx);
    }
}

static void handleDisconnectReq(Task task, Message message, audio_input_context_t* ctx)
{
    if (AudioInputCommonTaskIsBroadcaster(task))
    {
        audioInputSpdifBroadcastStop(task, ctx);
    }
    else
    {
        AudioInputCommonDisconnectHandler(task, message, ctx);
    }
}

audio_input_context_t* AudioInputSpdifGetContext(void)
{
    return spdif_ctx;
}

static void setUpStateHandlers(void)
{
    spdif_ctx = calloc(1, sizeof(audio_input_context_t));
    AudioInputCommonSetStateTable(&spdif_state_table, spdif_ctx);
}

void AudioPluginSpdifMessageHandler(Task task, MessageId id, Message message)
{
    PRINT(("audio_input_spdif handler id 0x%x\n", (unsigned)id));
    
    switch(id)
    {
        case AUDIO_PLUGIN_CONNECT_MSG:
        {
            PanicNotNull(spdif_ctx);
            setUpStateHandlers();
            break;
        }
        
        #ifdef HOSTED_TEST_ENVIRONMENT
        case AUDIO_PLUGIN_TEST_RESET_MSG:
            cleanContextData();
            return;
        #endif

        case AUDIO_PLUGIN_SET_GROUP_VOLUME_MSG:
            if (AudioInputCommonTaskIsBroadcaster(task))
            {
                /* Broadcast the volume change to all receivers. */
                AudioPluginForwardingVolumeChangeInd(spdif_ctx->ba.plugin);
            }
            break;    
        
        default:     
            break;
    }
    
    AudioInputCommonMessageHandler(task, id, message, spdif_ctx);
    
    /* Must only free context after transition to state audio_input_idle */
    if (spdif_ctx && spdif_ctx->state == audio_input_idle)
        cleanContextData();
}

