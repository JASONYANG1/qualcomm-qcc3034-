
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_usb_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_USB_CONFIG_DEF_H_
#define _SINK_USB_CONFIG_DEF_H_

#include "config_definition.h"

#define SINK_USB_READONLY_CONFIG_BLK_ID 1027

typedef struct {
    unsigned short device_class;
    unsigned short audio_always_on:1;
    unsigned short plugin_type:3;
    unsigned short deconfigured_timeout:4;
    unsigned short attach_timeout:4;
    unsigned short plugin_index:4;
    unsigned short padding:15;
    unsigned short pause_when_switching_source:1;
} sink_usb_readonly_config_def_t;

#define SINK_USB_WRITEABLE_CONFIG_BLK_ID 1034

typedef struct {
    unsigned short usb_main_volume;
    unsigned short usb_aux_volume;
} sink_usb_writeable_config_def_t;

#endif /* _SINK_USB_CONFIG_DEF_H_ */
