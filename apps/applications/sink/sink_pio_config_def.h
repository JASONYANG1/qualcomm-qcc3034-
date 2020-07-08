
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_pio_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_PIO_CONFIG_DEF_H_
#define _SINK_PIO_CONFIG_DEF_H_

#include "config_definition.h"

typedef struct {
    unsigned short pio_function:8;
    unsigned short pio_num:8;
} pio_function_pattern_t;

#define PIO_WRITEABLE_CONFIG_BLK_ID 92

typedef struct {
    unsigned short padding:15;
    unsigned short user_pio_state:1;
} pio_writeable_config_def_t;

#define PIO_READONLY_CONFIG_BLK_ID 97

typedef struct {
    unsigned short pio_invert_0_15;
    unsigned short pio_invert_16_31;
    unsigned short pio_invert_32_47;
    unsigned short pio_invert_48_63;
    unsigned short pio_invert_64_79;
    unsigned short pio_invert_80_95;
    unsigned short pio_mapping_0_15;
    unsigned short pio_mapping_16_31;
    unsigned short pio_mapping_32_47;
    unsigned short pio_mapping_48_63;
    unsigned short pio_mapping_64_79;
    unsigned short pio_mapping_80_95;
    unsigned short pio_debounce_group_0_0_15;
    unsigned short pio_debounce_group_0_16_31;
    unsigned short pio_debounce_group_0_32_47;
    unsigned short pio_debounce_group_0_48_63;
    unsigned short pio_debounce_group_0_64_79;
    unsigned short pio_debounce_group_0_80_95;
    unsigned short pio_debounce_group_1_0_15;
    unsigned short pio_debounce_group_1_16_31;
    unsigned short pio_debounce_group_1_32_47;
    unsigned short pio_debounce_group_1_48_63;
    unsigned short pio_debounce_group_1_64_79;
    unsigned short pio_debounce_group_1_80_95;
    unsigned short pio_debounce_group_0_time_between_checks:8;
    unsigned short pio_debounce_group_0_num_checks:8;
    unsigned short pio_debounce_group_1_time_between_checks:8;
    unsigned short pio_debounce_group_1_num_checks:8;
    unsigned short padding:7;
    unsigned short pio_debounce_group_0_enable_button_mappings:1;
    unsigned short user_pio:8;
} pio_readonly_config_def_t;

#define CONFIGURE_PIO_FUNCTION_CONFIG_BLK_ID 128

typedef struct {
    pio_function_pattern_t pio_function_array[1];
} configure_pio_function_config_def_t;

#endif /* _SINK_PIO_CONFIG_DEF_H_ */
