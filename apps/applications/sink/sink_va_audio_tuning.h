/****************************************************************************
Copyright (c) 2019 Qualcomm Technologies International, Ltd.


FILE NAME
    sink_va_audio_tuning.h

DESCRIPTION
    Header file for the interface to the sink VA audio tuning functionality

*/

/*!
@file   sink_va_audio_tuning.h
@brief  Interface to the voice assistant functionality in the sink app

*/
#ifndef _SINK_VA_AUDIO_TUNING_H_
#define _SINK_VA_AUDIO_TUNING_H_
#include "sink_va_enable.h"
#ifdef ENABLE_VA_AUDIO_TUNING

/******************************************************************************
    @brief This function checks if VaAudioTuning mode is enabled in sink application. 

    @param None

    @return TRUE if VaAudioTuning mode is enabled, else FALSE
*/
bool SinkVaAudioTuningIsModeEnabled(void);
/******************************************************************************
    @brief This function makes VA chain up and running.

    @param none

    @return None
*/
void SinkVaAudioTuningEnterMode(void);
/******************************************************************************
    @brief This function destroys the VA chain.

    @param none

    @return None
*/
void SinkVaAudioTuningExitMode(void);
#else
#define SinkVaAudioTuningIsModeEnabled() (FALSE)
/******************************************************************************/
#define SinkVaAudioTuningEnterMode() ((void)(0))
/******************************************************************************/
#define SinkVaAudioTuningExitMode() ((void)(0))
#endif/* ENABLE_VA_AUDIO_TUNING*/
#endif
