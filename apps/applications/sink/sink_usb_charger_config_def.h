
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_usb_charger_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_USB_CHARGER_CONFIG_DEF_H_
#define _SINK_USB_CHARGER_CONFIG_DEF_H_

#include "config_definition.h"

typedef struct {
    unsigned short current;
    unsigned short padding:8;
    unsigned short disable_leds:1;
    unsigned short power_off:1;
    unsigned short vsel:1;
    unsigned short charge:1;
    unsigned short charger_config:4;
} sink_charge_current_t;

#define SINK_USB_POWER_READONLY_CONFIG_BLK_ID 1040

typedef struct {
    sink_charge_current_t charge[11];
} sink_usb_power_readonly_config_def_t;

#endif /* _SINK_USB_CHARGER_CONFIG_DEF_H_ */
