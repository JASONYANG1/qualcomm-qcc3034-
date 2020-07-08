
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_power_manager_charger_configuration_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_POWER_MANAGER_CHARGER_CONFIGURATION_CONFIG_DEF_H_
#define _SINK_POWER_MANAGER_CHARGER_CONFIGURATION_CONFIG_DEF_H_

#include "config_definition.h"

typedef struct {
    unsigned short precharge_current:8;
    unsigned short trickle_charge_current:8;
} charger_mode_currents_structure_t;

typedef struct {
    unsigned short trickle_charge_timeout;
    unsigned short precharge_timeout;
    unsigned short fast_charge_timeout;
} charger_safety_structure_t;

typedef struct {
    unsigned short padding:5;
    unsigned short ext_fast:1;
    unsigned short ext_resistor_value:10;
} external_charger_structure_t;

typedef struct {
    unsigned short period_charger_progress:8;
    unsigned short current_external_devices:8;
    unsigned short padding:4;
    unsigned short debounce_time:2;
    unsigned short iterm_ctrl:2;
    unsigned short pre_fast_threshold:2;
    unsigned short standby_fast_hysteresis:2;
    unsigned short default_vfloat:4;
} charger_progress_structure_t;

typedef struct {
    unsigned short padding:15;
    unsigned short vsel_fast_charge:1;
} voltage_selectors_structure_t;

#define EXTERNAL_CHARGER_CONFIG_BLK_ID 1192

typedef struct {
    external_charger_structure_t ext_charger_struct;
} external_charger_config_def_t;

#define CHARGER_PROGRESS_CONFIG_BLK_ID 1197

typedef struct {
    charger_progress_structure_t chg_progress_struct;
} charger_progress_config_def_t;

#define CHARGER_CURRENTS_CONFIG_BLK_ID 1203

typedef struct {
    charger_mode_currents_structure_t mode_currents;
} charger_currents_config_def_t;

#define CHARGER_SAFETY_CONFIG_BLK_ID 1208

typedef struct {
    charger_safety_structure_t chg_safety;
} charger_safety_config_def_t;

#define VOLTAGE_SELECT_CONFIG_BLK_ID 1215

typedef struct {
    voltage_selectors_structure_t voltage_selectors;
} voltage_select_config_def_t;

#endif /* _SINK_POWER_MANAGER_CHARGER_CONFIGURATION_CONFIG_DEF_H_ */
