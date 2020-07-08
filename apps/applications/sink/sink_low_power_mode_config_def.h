
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_low_power_mode_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_LOW_POWER_MODE_CONFIG_DEF_H_
#define _SINK_LOW_POWER_MODE_CONFIG_DEF_H_

#include "config_definition.h"

#define SINK_LOW_POWER_MODE_READONLY_CONFIG_BLK_ID 1226

typedef struct {
    unsigned short dormant_nfc:3;
    unsigned short dormant_xio:13;
} sink_low_power_mode_readonly_config_def_t;

#endif /* _SINK_LOW_POWER_MODE_CONFIG_DEF_H_ */
