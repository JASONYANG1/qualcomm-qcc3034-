/****************************************************************************
Copyright (c) 2019 Qualcomm Technologies International, Ltd.
 
FILE NAME
    audio_input_spdif_broadcast.h
 
DESCRIPTION
    Handlers for broadcast specific tasks.
    
    When in the broadcast role, use the audio_plugin_forwarding framework 
    to redirect the input source(s) to audio_output_broadcast plugin.

    audio_output_broadcast handles broadcasting the audio stream as well
    as sending it to the local mixer/dac.
*/

#ifndef AUDIO_INPUT_SPDIF_BROADCAST_H_
#define AUDIO_INPUT_SPDIF_BROADCAST_H_

#include <audio_input_common.h>
#include <audio_plugin_forwarding.h>


void audioInputSpdifBroadcastCreate(Task input_task, Task output_task, audio_input_context_t *ctx);

void audioInputSpdifBroadcastStart(Task input_task, Message message, audio_input_context_t *ctx);

void audioInputSpdifBroadcastStartChain(Task input_task, Message message, audio_input_context_t* ctx);

void audioInputSpdifBroadcastStop(Task input_task, audio_input_context_t *ctx);

void audioInputSpdifBroadcastDestroy(Task input_task, Task output_task, audio_input_context_t *ctx);


#endif /* AUDIO_INPUT_SPDIF_BROADCAST_H_ */
