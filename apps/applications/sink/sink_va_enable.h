/****************************************************************************
Copyright (c) 2019 Qualcomm Technologies International, Ltd.


FILE NAME
    sink_va_enable.h

DESCRIPTION
    This file should be updated with all the voice assistants supported for the Sink application. It maps any of the supported voice assistant with
    ENABLE_VOICE_ASSISTANT for sink_va_audio_tuning and sink_va_if file

*/

/*!
@file   sink_va_enable.h
@brief  This file should be updated with all the voice assistants supported for the Sink application. It maps any of the supported voice assistant with
        ENABLE_VOICE_ASSISTANT for sink_va_audio_tuning and sink_va_if files
*/

#ifndef SINK_VA_ENABLE_H_
#define SINK_VA_ENABLE_H_
#if (defined(ENABLE_AMA) || defined(ENABLE_GAA))
#ifndef ENABLE_VOICE_ASSISTANT
  #define ENABLE_VOICE_ASSISTANT
#endif/* ENABLE_VOICE_ASSISTANT */
#ifndef ENABLE_VA_AUDIO_TUNING
  #define ENABLE_VA_AUDIO_TUNING
#endif/* ENABLE_VA_AUDIO_TUNING */
#endif 
#endif /* SINK_VA_ENABLE_H_ */
