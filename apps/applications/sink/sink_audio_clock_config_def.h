
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_audio_clock_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_AUDIO_CLOCK_CONFIG_DEF_H_
#define _SINK_AUDIO_CLOCK_CONFIG_DEF_H_

#include "config_definition.h"

typedef struct {
    unsigned short input_use_case;
    unsigned short voice_use_case;
    unsigned short prompt_use_case;
    unsigned short feature_use_case;
    unsigned short mixer_use_case;
    unsigned short output_use_case;
    unsigned short aec_use_case;
    unsigned short clock_rate;
} audio_clock_pattern_t;

#define SINK_AUDIO_CLOCK_CONFIG_BLK_ID 1241

typedef struct {
    unsigned short default_rate;
} sink_audio_clock_config_def_t;

#define SINK_AUDIO_CLOCK_TABLE_CONFIG_BLK_ID 1246

typedef struct {
    audio_clock_pattern_t audio_clock_array[1];
} sink_audio_clock_table_config_def_t;

#endif /* _SINK_AUDIO_CLOCK_CONFIG_DEF_H_ */
