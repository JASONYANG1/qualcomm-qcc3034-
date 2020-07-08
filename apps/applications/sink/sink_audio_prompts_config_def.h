
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_audio_prompts_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_AUDIO_PROMPTS_CONFIG_DEF_H_
#define _SINK_AUDIO_PROMPTS_CONFIG_DEF_H_

#include "config_definition.h"

typedef struct {
    unsigned short event;
    unsigned short cancel_queue_play_immediate:1;
    unsigned short sco_block:1;
    unsigned short state_mask:14;
    unsigned short padding:8;
    unsigned short prompt_id:8;
} audio_prompts_config_type_t;

#define SINK_AUDIOPROMPTS_READONLY_CONFIG_BLK_ID 612

typedef struct {
    unsigned short LanguageConfirmTime_s;
    unsigned short num_audio_prompt_languages;
    unsigned short padding:13;
    unsigned short VoicePromptPairing:1;
    unsigned short VoicePromptNumbers:1;
    unsigned short DisableAudioPromptTerminate:1;
} sink_audioprompts_readonly_config_def_t;

#define SINK_AUDIOPROMPTS_WRITEABLE_CONFIG_BLK_ID 619

typedef struct {
    unsigned short num_audio_prompts;
    unsigned short padding:11;
    unsigned short audio_prompts_enabled:1;
    unsigned short audio_prompt_language:4;
} sink_audioprompts_writeable_config_def_t;

#define SINK_AUDIOPROMPTS_CONFIG_BLK_ID 625

typedef struct {
    audio_prompts_config_type_t audioPromptEvents[1];
} sink_audioprompts_config_def_t;

#endif /* _SINK_AUDIO_PROMPTS_CONFIG_DEF_H_ */
