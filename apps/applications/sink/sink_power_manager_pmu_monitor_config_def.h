
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_power_manager_pmu_monitor_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_POWER_MANAGER_PMU_MONITOR_CONFIG_DEF_H_
#define _SINK_POWER_MANAGER_PMU_MONITOR_CONFIG_DEF_H_

#include "config_definition.h"

#define SINK_PMU_MON_CONFIG_CONFIG_BLK_ID 1101

typedef struct {
    unsigned short min_charge_i;
    unsigned short max_charge_i;
    unsigned short monitor_period_active;
    unsigned short monitor_period_idle;
    unsigned short monitor_period_nopwr;
    unsigned short no_incr_i_temp:8;
    unsigned short charger_i_step:8;
    unsigned short padding:8;
    unsigned short decr_i_temp:8;
} sink_pmu_mon_config_config_def_t;

#endif /* _SINK_POWER_MANAGER_PMU_MONITOR_CONFIG_DEF_H_ */
