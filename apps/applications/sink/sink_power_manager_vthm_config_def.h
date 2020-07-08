
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_power_manager_vthm_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_POWER_MANAGER_VTHM_CONFIG_DEF_H_
#define _SINK_POWER_MANAGER_VTHM_CONFIG_DEF_H_

#include "config_definition.h"

typedef struct {
    unsigned short current;
    unsigned short disable_leds:1;
    unsigned short power_off:1;
    unsigned short vsel:1;
    unsigned short charge:1;
    unsigned short termination_type:3;
    unsigned short charger_vthm_region:4;
    unsigned short termination_voltage:5;
} charger_configuration_settings_t;

#define SINK_POWER_SETTINGS_VTHM_CONFIG_BLK_ID 1151

typedef struct {
    sink_power_config_vthm_t config_p_vthm;
} sink_power_settings_vthm_config_def_t;

#define CHARGER_CONTROL_CONFIG_BLK_ID 1166

typedef struct {
    charger_configuration_settings_t temperature_regions[8];
} charger_control_config_def_t;

#endif /* _SINK_POWER_MANAGER_VTHM_CONFIG_DEF_H_ */
