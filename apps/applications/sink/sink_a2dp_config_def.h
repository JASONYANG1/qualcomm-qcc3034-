
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_a2dp_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_A2DP_CONFIG_DEF_H_
#define _SINK_A2DP_CONFIG_DEF_H_

#include "config_definition.h"

#define A2DP_CONFIG_BLK_ID 33

typedef struct {
    unsigned short A2dpConnectionUpdateDelay_ms;
    unsigned short A2dpLinkLossReconnectionTime_s;
    unsigned short DefaultA2dpVolume;
    unsigned short EnableA2dpMediaOpenOnConnection:1;
    unsigned short sbc_uses_medium_bitpool:1;
    unsigned short EnableA2dpStreaming:1;
    unsigned short a2dpclass:2;
    unsigned short aptx_ad_a2dp_cap:4;
    unsigned short A2dpOptionalCodecsEnabled:7;
} a2dp_config_def_t;

#define A2DP_SESSION_CONFIG_BLK_ID 41

typedef struct {
    unsigned short padding:4;
    unsigned short dither_bypass:1;
    unsigned short compander_bypass:1;
    unsigned short spatial_enhance_bypass:1;
    unsigned short bass_enhance_bypass:1;
    unsigned short user_eq_bypass:1;
    unsigned short eq_flat_enable:1;
    unsigned short speaker_eq_bypass:1;
    unsigned short subwoofer_bypass:1;
    unsigned short audio_enhancement_disable:1;
    unsigned short selected_eq_bank:3;
} a2dp_session_config_def_t;

#endif /* _SINK_A2DP_CONFIG_DEF_H_ */
