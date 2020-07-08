
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_usb_proprietary_charger_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_USB_PROPRIETARY_CHARGER_CONFIG_DEF_H_
#define _SINK_USB_PROPRIETARY_CHARGER_CONFIG_DEF_H_

#include "config_definition.h"

typedef struct {
    unsigned short dplus;
    unsigned short dminus;
    unsigned short tolerance;
    unsigned short current;
    unsigned short padding:12;
    unsigned short disable_leds:1;
    unsigned short power_off:1;
    unsigned short vsel:1;
    unsigned short charge:1;
} sink_proprietary_charge_current_t;

#define SINK_USB_POWER_PROPRIETARY_READONLY_CONFIG_BLK_ID 1066

typedef struct {
    sink_proprietary_charge_current_t proprietary_charge[1];
} sink_usb_power_proprietary_readonly_config_def_t;

#endif /* _SINK_USB_PROPRIETARY_CHARGER_CONFIG_DEF_H_ */
