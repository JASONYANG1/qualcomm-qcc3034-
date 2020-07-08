
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_audio_routing_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_AUDIO_ROUTING_CONFIG_DEF_H_
#define _SINK_AUDIO_ROUTING_CONFIG_DEF_H_

#include "config_definition.h"

typedef struct {
    unsigned short mic_bias_0_voltage;
    unsigned short mic_bias_1_voltage;
} mic_bias_drive_settings_t;

typedef struct {
    unsigned short voice_quality;
    unsigned short music_quality;
} audio_quality_settings_t;

typedef struct {
    unsigned short padding:2;
    unsigned short enableMixingOfVoiceAndAudio:1;
    unsigned short use_two_mic_back_channel:1;
    unsigned short use_one_mic_back_channel:1;
    unsigned short force_resampling_of_tones:1;
    unsigned short manual_source_selection:1;
    unsigned short audio_input_routing:2;
    unsigned short dut_input:3;
    unsigned short spdif_supported_data_types:4;
} AudioPluginFeatures_t;

typedef struct {
    unsigned short threshold;
    unsigned short trigger_time;
} silence_detect_settings_t;

typedef struct {
    audio_mic_params_t mic_1;
    audio_mic_params_t mic_2;
    audio_mic_params_t mic_3;
    audio_mic_params_t mic_4;
    audio_mic_params_t mic_5;
    audio_mic_params_t mic_6;
} common_mic_params_t_t;

typedef struct {
    analogue_input_params_t analogue_in;
} common_analogue_params_t;

typedef struct {
    unsigned short filter;
    unsigned short freq;
    unsigned short gain;
    unsigned short Q;
} user_eq_band_t;

typedef struct {
    unsigned short preGain;
    user_eq_band_t bands[5];
} user_eq_bank_t;

#define SINK_AUDIO_READONLY_CONFIG_BLK_ID 552

typedef struct {
    audio_quality_settings_t audio_quality;
    AudioPluginFeatures_t PluginFeatures;
    mic_bias_drive_settings_t mic_bias_drive_voltage;
    common_mic_params_t_t common_mic_params;
    analogue_input_params_t analogue_input;
    silence_detect_settings_t SilenceDetSettings;
    unsigned short AudioAmpUnmuteTime_ms;
    unsigned short AudioAmpMuteTime_ms;
    unsigned short audio_switch_delay_after_disconn;
    unsigned short TwsAudioActiveDelay_ms;
    unsigned short aux_out_detect:8;
    unsigned short AudioActivePIO:8;
    unsigned short AudioMutePIO:8;
    unsigned short PowerOnPIO:8;
    unsigned short seqSourcePriority2:4;
    unsigned short seqSourcePriority1:4;
    unsigned short voice_mic_b:4;
    unsigned short voice_mic_a:4;
    unsigned short seqSourcePriority6:4;
    unsigned short seqSourcePriority5:4;
    unsigned short seqSourcePriority4:4;
    unsigned short seqSourcePriority3:4;
    unsigned short UseLowPowerAudioCodecs:1;
    unsigned short TwsSlaveAudioRouting:2;
    unsigned short TwsMasterAudioRouting:2;
    unsigned short defaultSource:3;
    unsigned short seqSourcePriority8:4;
    unsigned short seqSourcePriority7:4;
    unsigned short padding:11;
    unsigned short useSram:1;
    unsigned short AudioRenderingMode:1;
    unsigned short AssumeAutoSuspendOnCall:1;
    unsigned short CompanderBandSelection:2;
} sink_audio_readonly_config_def_t;

#define SINK_AUDIO_WRITEABLE_CONFIG_BLK_ID 586

typedef struct {
    unsigned short requested_audio_source;
    user_eq_bank_t PEQ;
} sink_audio_writeable_config_def_t;

#endif /* _SINK_AUDIO_ROUTING_CONFIG_DEF_H_ */
