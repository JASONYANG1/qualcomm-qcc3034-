
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_dsp_capabilities_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_DSP_CAPABILITIES_CONFIG_DEF_H_
#define _SINK_DSP_CAPABILITIES_CONFIG_DEF_H_

#include "config_definition.h"

#define DSP_CAPS_CONFIG_BLK_ID 972

typedef struct {
    unsigned short padding:13;
    unsigned short aptxAdaptiveDecoderProcessing:1;
    unsigned short OffloadCeltEncoder:1;
    unsigned short OffloadAptxDecoder:1;
} dsp_caps_config_def_t;

#endif /* _SINK_DSP_CAPABILITIES_CONFIG_DEF_H_ */
