
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_configure_dsp_capability_ids_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_CONFIGURE_DSP_CAPABILITY_IDS_CONFIG_DEF_H_
#define _SINK_CONFIGURE_DSP_CAPABILITY_IDS_CONFIG_DEF_H_

#include "config_definition.h"

typedef struct {
    unsigned short original_cap_id;
    unsigned short new_cap_id;
} dsp_capability_ids_entry_t;

#define DSP_CAPABILITY_IDS_TABLE_CONFIG_BLK_ID 1677

typedef struct {
    dsp_capability_ids_entry_t new_cap_id_entry[1];
} dsp_capability_ids_table_config_def_t;

#endif /* _SINK_CONFIGURE_DSP_CAPABILITY_IDS_CONFIG_DEF_H_ */
