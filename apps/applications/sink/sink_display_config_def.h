
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_display_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_DISPLAY_CONFIG_DEF_H_
#define _SINK_DISPLAY_CONFIG_DEF_H_

#include "config_definition.h"

#define SINK_DISPLAY_CONFIG_BLK_ID 1236

typedef struct {
    unsigned short disp_backlight_pio:8;
    unsigned short disp_reset_pio:8;
} sink_display_config_def_t;

#endif /* _SINK_DISPLAY_CONFIG_DEF_H_ */
