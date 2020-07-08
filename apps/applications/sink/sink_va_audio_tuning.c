/****************************************************************************
Copyright (c) 2019 Qualcomm Technologies International, Ltd.


FILE NAME
    sink_va_audio_tuning.c

DESCRIPTION
    The file contains the implementation details of all the interface and helper functions to the sink VA audio tuning functionality

*/

/*!
@file   sink_va_audio_tuning.c
@brief  Interface to the voice assistant functionality in the sink app

*/
#include "sink_va_audio_tuning.h"
#ifdef ENABLE_VA_AUDIO_TUNING
#include "sink_hfp_data.h"
#include "sink_audio_routing.h"

#include <panic.h>
#include <source.h>
#include <voice_assistant_audio_manager.h>

static void sinkVaAudioTuningMessageHandler(Task task, MessageId id, Message message);
static void sinkVaAudioTuningModeConfig( va_audio_mgr_feature_config_t*, va_audio_mgr_audio_config_t*);
static const TaskData sink_va_audio_tuning_task = {sinkVaAudioTuningMessageHandler};
static bool sink_va_audio_tuning_mode_enabled = FALSE;
static Source va_audio_tuning_source = NULL;
/*
 * Return the task associated with Voice Assistant
*/
#define sinkVaAudioTuningGetTask() ((Task)&sink_va_audio_tuning_task)
#ifndef UNUSED
#define UNUSED(x) ((void)x)
#endif
/* Set the msbc codec bitpool */
#define VA_MSBC_ENCODER_BITPOOL_VALUE 26

/*****************************************************************************/
static void sinkVaConfigureSource(Source source)
{
    va_audio_tuning_source = source;
    MessageStreamTaskFromSource(source, sinkVaAudioTuningGetTask());
    SourceConfigure(source, VM_SOURCE_MESSAGES, VM_MESSAGES_SOME);
}

/*****************************************************************************/
static void sinkVaAudioTuningMessageHandler(Task task, MessageId id, Message msg)
{
    UNUSED(task);

    switch(id)
    {
        case MESSAGE_MORE_DATA:
        {
            Source source = ((MessageMoreData *) msg)->source;
            uint16 size = SourceSize(source);
            SourceDrop(source, size);
        }
        break;

        case VA_AUDIO_MGR_CAPTURE_IND:
        {
            VA_AUDIO_MGR_CAPTURE_IND_T* ind = (VA_AUDIO_MGR_CAPTURE_IND_T*) msg;
            sinkVaConfigureSource(ind->src);

            Source source=ind->src;
            uint16 size = SourceSize(source);
            SourceDrop(source, size);
        }
        break;

        default:
        break;
    }
}
/****************************************************************************
NAME
    sinkVaAudioTuningModeConfig

DESCRIPTION
    This function is called to populate the feature_config and audio_config

RETURNS
    void
*/
static void sinkVaAudioTuningModeConfig( va_audio_mgr_feature_config_t *feature_config, va_audio_mgr_audio_config_t *audio_config )
{
    audio_config->mic_config.mic_a = sinkAudioGetMic1Params();
    audio_config->mic_config.mic_b = sinkAudioGetMic2Params();
    audio_config->codec_config.codec_type = va_audio_mgr_codec_msbc;
    audio_config->codec_config.bitpool_size = VA_MSBC_ENCODER_BITPOOL_VALUE;
    audio_config->cvc_type = sinkHfpDataGetAudioPlugin();
    feature_config->trigger_type =va_audio_mgr_trigger_button;
    feature_config->pre_roll_interval = 0;
    feature_config->phrase_index=0;
}

/*****************************************************************************/
bool SinkVaAudioTuningIsModeEnabled(void)
{
    return sink_va_audio_tuning_mode_enabled;
}
/*****************************************************************************/
void SinkVaAudioTuningEnterMode(void)
{
    if(!SinkVaAudioTuningIsModeEnabled())
    {
       /*Audio manager might have been initialised by AMA/GAA*/
        VaAudioMgrDeInit();
        va_audio_mgr_feature_config_t feature_cfg;
        va_audio_mgr_audio_config_t audio_cfg;
        sinkVaAudioTuningModeConfig(&feature_cfg, &audio_cfg);
        if(TRUE != VaAudioMgrInit(sinkVaAudioTuningGetTask()) )
            Panic();
        if(va_audio_mgr_status_success != VaAudioMgrConfigure(&feature_cfg, &audio_cfg))
            Panic();
        if(va_audio_mgr_status_success !=VaAudioMgrEnable())
            Panic();
        if(va_audio_mgr_status_success !=VaAudioMgrStartCapture(0))
            Panic();
        sink_va_audio_tuning_mode_enabled = TRUE;
    }
}
/*****************************************************************************/

void SinkVaAudioTuningExitMode(void)
{
    if(SinkVaAudioTuningIsModeEnabled())
    {
        VaAudioMgrStopCapture(); 
        VaAudioMgrDisable();
        MessageStreamTaskFromSource(va_audio_tuning_source, NULL);
        sink_va_audio_tuning_mode_enabled = FALSE;
    }
}
/*****************************************************************************/
#endif/* ENABLE_VA_AUDIO_TUNING*/




    
	
	
