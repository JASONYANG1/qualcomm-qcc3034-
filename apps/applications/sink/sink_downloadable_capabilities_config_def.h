
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_downloadable_capabilities_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_DOWNLOADABLE_CAPABILITIES_CONFIG_DEF_H_
#define _SINK_DOWNLOADABLE_CAPABILITIES_CONFIG_DEF_H_

#include "config_definition.h"

typedef struct {
    unsigned short bundle_filename[25];
    unsigned short padding:8;
    unsigned short available_on_processor:8;
} cap_bundle_table_entry_t;

#define DOWNLOADABLE_DSP_CAPS_CONFIG_BLK_ID 1335

typedef struct {
    cap_bundle_table_entry_t bundle_file_entry[13];
} downloadable_dsp_caps_config_def_t;

#endif /* _SINK_DOWNLOADABLE_CAPABILITIES_CONFIG_DEF_H_ */
