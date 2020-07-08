
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_dut_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_DUT_CONFIG_DEF_H_
#define _SINK_DUT_CONFIG_DEF_H_

#include "config_definition.h"

#define SINK_DUT_READONLY_CONFIG_BLK_ID 488

typedef struct {
    unsigned short padding:8;
    unsigned short dut_pio:8;
} sink_dut_readonly_config_def_t;

#endif /* _SINK_DUT_CONFIG_DEF_H_ */
