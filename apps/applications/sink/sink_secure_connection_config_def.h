
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_secure_connection_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_SECURE_CONNECTION_CONFIG_DEF_H_
#define _SINK_SECURE_CONNECTION_CONFIG_DEF_H_

#include "config_definition.h"

#define SINK_SEC_READONLY_CONFIG_BLK_ID 1220

typedef struct {
    unsigned short BrEdrAuthenticatedPayloadTO_s;
    unsigned short padding:14;
    unsigned short SecureConnectionMode:2;
} sink_sec_readonly_config_def_t;

#endif /* _SINK_SECURE_CONNECTION_CONFIG_DEF_H_ */
