
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_power_manager_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_POWER_MANAGER_CONFIG_DEF_H_
#define _SINK_POWER_MANAGER_CONFIG_DEF_H_

#include "config_definition.h"

#define SINK_POWER_MANAGER_WRITEABLE_CONFIG_BLK_ID 1090

typedef struct {
    unsigned short padding:15;
    unsigned short lbipmenable:1;
} sink_power_manager_writeable_config_def_t;

#define SINK_GAS_GAUGE_ACTIONS_CONFIG_BLK_ID 1095

typedef struct {
    unsigned short max_volume_limit;
    unsigned short padding:13;
    unsigned short action_when_battery_less_than_gas_gauge0:3;
} sink_gas_gauge_actions_config_def_t;

#endif /* _SINK_POWER_MANAGER_CONFIG_DEF_H_ */
