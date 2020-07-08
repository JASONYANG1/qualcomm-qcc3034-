
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_ble_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_BLE_CONFIG_DEF_H_
#define _SINK_BLE_CONFIG_DEF_H_

#include "config_definition.h"

#define SINK_BLE_READONLY_CONFIG_BLK_ID 982

typedef struct {
    unsigned short LeAuthenticatedPayloadTO_s;
    unsigned short padding:5;
    unsigned short BleMaxCentralConn:2;
    unsigned short BleMaxPeripheralConn:2;
    unsigned short BleAdvertisingFilters:7;
} sink_ble_readonly_config_def_t;

#endif /* _SINK_BLE_CONFIG_DEF_H_ */
