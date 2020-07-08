
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_tones_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_TONES_CONFIG_DEF_H_
#define _SINK_TONES_CONFIG_DEF_H_

#include "config_definition.h"

typedef struct {
    unsigned short event;
    unsigned short padding:8;
    unsigned short tone:8;
} tone_config_type_t;

#define SINK_TONE_WRITEABLE_CONFIG_BLK_ID 665

typedef struct {
    tone_config_type_t gEventTones[1];
} sink_tone_writeable_config_def_t;

#define CONFIGTONE_RDATA_CONFIG_BLK_ID 761

typedef struct {
    unsigned short gVariableTones[1];
} configtone_rdata_config_def_t;

#define SINK_TONE_READONLY_CONFIG_BLK_ID 766

typedef struct {
    unsigned short padding:6;
    unsigned short MuteToneFixedVolume:1;
    unsigned short QueueEventTones:1;
    unsigned short QueueVolumeTones:1;
    unsigned short PlayLocalVolumeTone:1;
    unsigned short PlayTonesAtFixedVolume:1;
    unsigned short FixedToneVolumeLevel:5;
} sink_tone_readonly_config_def_t;

#endif /* _SINK_TONES_CONFIG_DEF_H_ */
