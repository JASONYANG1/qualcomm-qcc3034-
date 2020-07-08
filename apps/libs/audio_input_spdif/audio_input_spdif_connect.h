/****************************************************************************
Copyright (c) 2016 - 2019  Qualcomm Technologies International, Ltd.


FILE NAME
    audio_input_spdif_connect.h

DESCRIPTION
    Handler for AUDIO_PLUGIN_CONNECT_MSG message for spdif source.
*/

#ifndef AUDIO_INPUT_SPDIF_CONNECT_H_
#define AUDIO_INPUT_SPDIF_CONNECT_H_

#include <message.h>
#include <audio_plugin_if.h>
#include <audio_input_common.h>

void AudioInputSpdifConnectHandler( Task task, Message msg, audio_input_context_t *ctx);

void AudioInputSpdifConnect( Task task,  Message msg, audio_input_context_t *ctx);

#endif /* AUDIO_INPUT_SPDIF_CONNECT_H_ */
