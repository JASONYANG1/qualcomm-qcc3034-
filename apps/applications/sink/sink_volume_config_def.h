
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_volume_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_VOLUME_CONFIG_DEF_H_
#define _SINK_VOLUME_CONFIG_DEF_H_

#include "config_definition.h"

typedef struct {
    signed short no_of_steps;
    signed short dB_min;
    signed short volume_knee_value_1;
    signed short dB_knee_value_1;
    signed short volume_knee_value_2;
    signed short dB_knee_value_2;
    signed short dB_max;
    unsigned short padding:15;
    unsigned short volume_curve_label:1;
} vol_mod_gain_curve_t;

typedef struct {
    unsigned short Tone:8;
    unsigned short A2dpGain:8;
    unsigned short DecVol:4;
    unsigned short IncVol:4;
    unsigned short VolGain:8;
} VolMapping_t;

#define SINK_VOLUME_WRITEABLE_CONFIG_BLK_ID 493

typedef struct {
    vol_mod_gain_curve_t volgroup_config[2];
    VolMapping_t gVolMaps[16];
    unsigned short padding:15;
    unsigned short gVolButtonsInverted:1;
} sink_volume_writeable_config_def_t;

#define SINK_VOLUME_READONLY_CONFIG_BLK_ID 546

typedef struct {
    unsigned short StoreCurrentSinkVolSrcTimeout_s;
    unsigned short padding:13;
    unsigned short VolumeChangeCausesUnMute:1;
    unsigned short AdjustVolumeWhilstMuted:1;
    unsigned short MuteSpeakerAndMic:1;
} sink_volume_readonly_config_def_t;

#endif /* _SINK_VOLUME_CONFIG_DEF_H_ */
