
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_pbap_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_PBAP_CONFIG_DEF_H_
#define _SINK_PBAP_CONFIG_DEF_H_

#include "config_definition.h"

#define PBAP_READ_ONLY_CONFIG_BLK_ID 1009

typedef struct {
    unsigned short padding:15;
    unsigned short pbap_enabled:1;
} pbap_read_only_config_def_t;

#endif /* _SINK_PBAP_CONFIG_DEF_H_ */
