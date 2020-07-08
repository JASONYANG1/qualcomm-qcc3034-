
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_inquiry_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_INQUIRY_CONFIG_DEF_H_
#define _SINK_INQUIRY_CONFIG_DEF_H_

#include "config_definition.h"

typedef struct {
    signed short tx_power;
    signed short threshold;
    signed short diff_threshold;
    unsigned short cod_filter_hi;
    unsigned short cod_filter_lo;
    signed short conn_threshold;
    signed short conn_diff_threshold;
    unsigned short timeout:8;
    unsigned short max_responses:8;
    unsigned short pair_on_pdl_reset:1;
    unsigned short try_all_discovered:1;
    unsigned short dont_pair_if_in_pdl:1;
    unsigned short connect_if_in_pdl:1;
    unsigned short num_results:4;
    unsigned short resume_timeout:8;
} rssi_pairing_t;

typedef struct {
    unsigned short page_scan_interval;
    unsigned short page_scan_window;
    unsigned short inquiry_scan_interval;
    unsigned short inquiry_scan_window;
} radio_config_type_t;

#define SINK_INQUIRY_READONLY_CONFIG_BLK_ID 438

typedef struct {
    rssi_pairing_t rssi;
    radio_config_type_t radio;
    unsigned short InquiryTimeout_s;
} sink_inquiry_readonly_config_def_t;

#endif /* _SINK_INQUIRY_CONFIG_DEF_H_ */
