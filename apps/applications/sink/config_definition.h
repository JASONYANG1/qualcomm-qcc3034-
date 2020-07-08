
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    config_definition.h

DESCRIPTION 
    Header file for the configuration definition.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _CONFIG_DEFINITION_H_
#define _CONFIG_DEFINITION_H_

#include <csrtypes.h>

const void *ConfigDefinitionGetConstData(void);
uint16 ConfigDefinitionGetConstDataSize(void);

typedef struct {
    unsigned short padding:7;
    unsigned short enable_24_bit_resolution:1;
    unsigned short pre_amp:1;
    unsigned short instance:2;
    unsigned short gain:5;
} analogue_input_params_t;

typedef struct {
    unsigned short instance:2;
    unsigned short bias_config:2;
    unsigned short gain:5;
    unsigned short pio:7;
    unsigned short padding:14;
    unsigned short channel:1;
    unsigned short is_digital:1;
} audio_mic_params_t;

typedef struct {
    unsigned short current_limit_threshold;
    unsigned short current_recovery_threshold;
    unsigned short current_limit_read_period;
    unsigned short negative_current_step:8;
    unsigned short positive_current_step:8;
} current_determination_structure_t;

typedef struct {
    unsigned short period_no_chg;
    unsigned short period_chg:8;
    unsigned short source:8;
} power_adc_t;

typedef struct {
    power_adc_t adc;
} power_vref_config_t;

typedef struct {
    power_adc_t adc;
    unsigned short padding:15;
    unsigned short ignore_increase_no_chg:1;
} power_vbat_config_t;

typedef struct {
    power_adc_t adc;
    unsigned short limits[7];
    unsigned short ics:8;
    unsigned short pio:8;
    unsigned short padding:11;
    unsigned short raw_limits:1;
    unsigned short delay:4;
} power_vthm_config_t;

typedef struct {
    power_adc_t adc;
} power_vchg_config_t;

typedef struct {
    power_vref_config_t vref;
} power_config_vref_t;

typedef struct {
    power_config_vref_t p_config_vref;
} sink_power_config_vref_t;

typedef struct {
    power_vbat_config_t vbat;
} power_config_vbat_t;

typedef struct {
    power_config_vbat_t p_config_vbat;
} sink_power_config_vbat_t;

typedef struct {
    power_vthm_config_t vthm;
} power_config_vthm_t;

typedef struct {
    power_config_vthm_t p_config_vthm;
} sink_power_config_vthm_t;

typedef struct {
    power_vchg_config_t vchg;
} power_config_vchg_t;

typedef struct {
    power_config_vchg_t p_config_vchg;
} sink_power_config_vchg_t;

#endif /* _CONFIG_DEFINITION_H_ */
