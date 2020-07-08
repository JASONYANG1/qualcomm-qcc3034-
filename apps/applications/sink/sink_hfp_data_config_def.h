
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_hfp_data_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_HFP_DATA_CONFIG_DEF_H_
#define _SINK_HFP_DATA_CONFIG_DEF_H_

#include "config_definition.h"

typedef struct {
    unsigned short event;
    unsigned short at_cmd;
} at_commands_events_t;

typedef struct {
    unsigned short data;
} at_command_data_t;

typedef struct {
    unsigned short padding:6;
    unsigned short pwr_source:1;
    unsigned short batt_level:1;
    unsigned short sms:1;
    unsigned short raw_text:1;
    unsigned short caller_name:1;
    unsigned short codec_bandwidths:2;
    unsigned short supported_codecs:3;
} hfp_qtil_features_t;

typedef struct {
    unsigned short padding:8;
    unsigned short battery_charge:2;
    unsigned short roaming_status:2;
    unsigned short signal_strength:2;
    unsigned short service:2;
} hfp_optional_indicators_t;

typedef struct {
    unsigned short supported_hfp_codecs_def;
    unsigned short hf_indicators_mask_def;
    hfp_qtil_features_t qtil_supported_features_def;
    hfp_optional_indicators_t optional_indicators_def;
    unsigned short padding:1;
    unsigned short multipoint_def:1;
    unsigned short extended_errors_def:1;
    unsigned short disable_nrec_def:1;
    unsigned short supported_profile_def:3;
    unsigned short supported_features_def:9;
    unsigned short link_loss_interval_def:8;
    unsigned short link_loss_time_def:8;
} hfp_init_params_t;

typedef struct {
    unsigned short bandwidth_low;
    unsigned short bandwidth_high;
    unsigned short max_latency;
    unsigned short voice_settings;
    unsigned short retransmission_effort;
} hfp_audio_params_t;

typedef struct {
    unsigned short padding:6;
    unsigned short ForceEV3S1ForSco2:1;
    unsigned short LNRCancelsVoiceDialIfActive:1;
    unsigned short EnableSyncMuteMicrophones:1;
    unsigned short AutoAnswerOnConnect:1;
    unsigned short ActionOnCallTransfer:2;
    unsigned short audio_plugin:4;
} sink_hfp_features_config_t;

typedef struct {
    unsigned short MuteRemindTime;
    unsigned short NwsServiceIndicatorRepeatTime_s;
    unsigned short MissedCallIndicateTime_s;
    unsigned short MissedCallIndicateAttempts;
} sink_hfp_feature_timeouts_t;

typedef struct {
    unsigned short IncomingRingPIO:8;
    unsigned short CallActivePIO:8;
    unsigned short padding:8;
    unsigned short OutgoingRingPIO:8;
} sink_hfp_pio_data_t;

typedef struct {
    hfp_audio_params_t audio_params;
    unsigned short padding:5;
    unsigned short additional_audio_params:1;
    unsigned short packet_types:10;
} HFP_features_type_t;

#define SINK_HFP_DATA_READONLY_CONFIG_BLK_ID 46

typedef struct {
    sink_hfp_features_config_t hfp_features_config;
    sink_hfp_feature_timeouts_t hfp_feature_timeouts;
    sink_hfp_pio_data_t hfp_pio_data;
    HFP_features_type_t hfp_supported_features;
    hfp_init_params_t hfp_init_params;
    unsigned short padding:12;
    unsigned short hfp_default_volume:4;
} sink_hfp_data_readonly_config_def_t;

#define SINK_HFP_AT_COMMANDS_CONFIG_BLK_ID 70

typedef struct {
    at_command_data_t at_commands[1];
} sink_hfp_at_commands_config_def_t;

#define SINK_HFP_EVENT_AT_COMMAND_TABLE_CONFIG_BLK_ID 74

typedef struct {
    at_commands_events_t event_at_commands[1];
} sink_hfp_event_at_command_table_config_def_t;

#define SINK_HFP_DATA_WRITEABLE_CONFIG_BLK_ID 78

typedef struct {
    unsigned short phone_number[10];
} sink_hfp_data_writeable_config_def_t;

#endif /* _SINK_HFP_DATA_CONFIG_DEF_H_ */
