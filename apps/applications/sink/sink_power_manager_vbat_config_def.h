
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_power_manager_vbat_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_POWER_MANAGER_VBAT_CONFIG_DEF_H_
#define _SINK_POWER_MANAGER_VBAT_CONFIG_DEF_H_

#include "config_definition.h"

typedef struct {
    unsigned short limit;
    unsigned short event;
    unsigned short padding:5;
    unsigned short sources:3;
    unsigned short notify_period:8;
} vbat_battery_threshold_config_t;

#define SINK_POWER_SETTINGS_VBAT_CONFIG_BLK_ID 1118

typedef struct {
    sink_power_config_vbat_t config_p_vbat;
    vbat_battery_threshold_config_t bat_events[6];
} sink_power_settings_vbat_config_def_t;

#endif /* _SINK_POWER_MANAGER_VBAT_CONFIG_DEF_H_ */
