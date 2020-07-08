
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_avrcp_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_AVRCP_CONFIG_DEF_H_
#define _SINK_AVRCP_CONFIG_DEF_H_

#include "config_definition.h"

#define AVRCP_READONLY_CONFIG_BLK_ID 977

typedef struct {
    unsigned short padding:14;
    unsigned short EnableAvrcpAudioSwitching:1;
    unsigned short avrcp_enabled:1;
} avrcp_readonly_config_def_t;

#endif /* _SINK_AVRCP_CONFIG_DEF_H_ */
