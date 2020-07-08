
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_led_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_LED_CONFIG_DEF_H_
#define _SINK_LED_CONFIG_DEF_H_

#include "config_definition.h"

typedef struct {
    unsigned short Event;
    unsigned short Speed:8;
    unsigned short OverideLED:8;
    unsigned short SpeedAction:1;
    unsigned short Colour:3;
    unsigned short FilterType:3;
    unsigned short FollowerLEDDelay:4;
    unsigned short FilterToCancel:5;
    unsigned short padding:15;
    unsigned short OverideDisable:1;
} LEDFilter_t;

typedef struct {
    unsigned short OffTime:8;
    unsigned short OnTime:8;
    unsigned short TimeOut:8;
    unsigned short RepeatTime:8;
    unsigned short LED_A:8;
    unsigned short DimTime:8;
    unsigned short OverideDisable:1;
    unsigned short Colour:3;
    unsigned short NumFlashes:4;
    unsigned short LED_B:8;
} LEDPattern_t;

typedef struct {
    unsigned short state;
    LEDPattern_t pattern;
} LEDStatePattern_t;

typedef struct {
    unsigned short event;
    LEDPattern_t pattern;
} LEDEventPattern_t;

typedef struct {
    unsigned short TriCol_b:8;
    unsigned short TriCol_a:8;
    unsigned short padding:8;
    unsigned short TriCol_c:8;
} PioTriColLeds_t;

#define SINK_LED_STATE_PATTERN_CONFIG_BLK_ID 771

typedef struct {
    LEDStatePattern_t pStatePatterns[1];
} sink_led_state_pattern_config_def_t;

#define SINK_LED_EVENT_PATTERN_CONFIG_BLK_ID 855

typedef struct {
    LEDEventPattern_t pEventPatterns[1];
} sink_led_event_pattern_config_def_t;

#define SINK_LED_EVENT_FILTER_CONFIG_BLK_ID 884

typedef struct {
    LEDFilter_t pEventFilters[1];
} sink_led_event_filter_config_def_t;

#define SINK_LED_READONLY_CONFIG_BLK_ID 960

typedef struct {
    PioTriColLeds_t TriColLeds;
    unsigned short padding:2;
    unsigned short ChargerTerminationLEDOveride:1;
    unsigned short ResetLEDEnableStateAfterReset:1;
    unsigned short QueueLEDEvents:1;
    unsigned short OverideFilterPermanentlyOn:1;
    unsigned short LedTimeMultiplier:2;
    unsigned short LedEnablePIO:8;
} sink_led_readonly_config_def_t;

#define SINK_LED_SESSION_CONFIG_BLK_ID 967

typedef struct {
    unsigned short padding:15;
    unsigned short gLEDSEnabled:1;
} sink_led_session_config_def_t;

#endif /* _SINK_LED_CONFIG_DEF_H_ */
