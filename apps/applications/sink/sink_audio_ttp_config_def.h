
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_audio_ttp_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_AUDIO_TTP_CONFIG_DEF_H_
#define _SINK_AUDIO_TTP_CONFIG_DEF_H_

#include "config_definition.h"

typedef struct {
    unsigned short target_ttp_latency_ms;
    unsigned short minimum_ttp_latency_ms;
    unsigned short maximum_ttp_latency_ms;
} ttp_latency_params_t;

typedef struct {
    ttp_latency_params_t a2dp_latency;
    ttp_latency_params_t tws_latency;
    ttp_latency_params_t wired_latency;
} ttp_latency_selector_t;

#define AUDIO_TTP_CONFIG_BLK_ID 1322

typedef struct {
    ttp_latency_selector_t ttp_latency_parameters;
} audio_ttp_config_def_t;

#endif /* _SINK_AUDIO_TTP_CONFIG_DEF_H_ */
