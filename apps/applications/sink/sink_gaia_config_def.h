
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_gaia_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_GAIA_CONFIG_DEF_H_
#define _SINK_GAIA_CONFIG_DEF_H_

#include "config_definition.h"

typedef struct {
    unsigned short padding:8;
    unsigned short pio:8;
} gaia_pio_pattern_t;

#define GAIA_READ_ONLY_CONFIG_BLK_ID 1014

typedef struct {
    unsigned short StoreCurrentPEQSettingsTimeout_s;
    unsigned short padding:10;
    unsigned short GaiaRemainConnected:1;
    unsigned short GaiaEnableSession:1;
    unsigned short dfu_partition:4;
} gaia_read_only_config_def_t;

#define GAIA_PIO_TRANSLATION_CONFIG_BLK_ID 1020

typedef struct {
    gaia_pio_pattern_t gaia_pio_array[1];
} gaia_pio_translation_config_def_t;

#endif /* _SINK_GAIA_CONFIG_DEF_H_ */
