/*****************************************************************************
Copyright (c) 2018 Qualcomm Technologies International, Ltd.

FILE NAME
    ama_speech_packetiser.c

DESCRIPTION
    Copies data from encoder output source into buffer and sends
*/

#include "ama.h"
#include "ama_speech_packetiser.h"
#include "ama_transport.h"
#include <stdlib.h>
#include <panic.h>
#include "ama_debug.h"
#include <string.h>
#include "ama_speech.h"

/* Parameters used by MSBC codec*/
#define AMA_MSBC_HEADER_LEN 4
#define MSBC_ENC_PKT_LEN 60
#define MSBC_FRAME_LEN 57
#define MSBC_FRAME_COUNT 5

/* Parameters used by OPus codec*/
#define AMA_OPUS_HEADER_LEN 3
#define OPUS_16KBPS_ENC_PKT_LEN 40
#define OPUS_32KBPS_ENC_PKT_LEN 80
#define OPUS_16KBPS_LE_FRAME_COUNT          4
#define OPUS_16KBPS_RFCOMM_FRAME_COUNT 5
#define OPUS_32KBPS_RFCOMM_FRAME_COUNT 3
#define OPUS_32KBPS_LE_FRAME_COUNT 2 

bool amaSendMsbcSpeechData(Source source)
{
    uint8 frames_to_send;
    uint16 payload_posn;
    uint16 lengthSourceThreshold;
    uint8 *buffer = NULL;
    uint8 no_of_transport_pkt = 0;
    uint8 initial_position = 0;

    bool sent_if_necessary = FALSE;

    frames_to_send = MSBC_FRAME_COUNT;
    initial_position = AMA_MSBC_HEADER_LEN;

    lengthSourceThreshold = MSBC_ENC_PKT_LEN * frames_to_send;

    AMA_DEBUG(("In = %d\n", SourceSize(source)));

    while ((SourceSize(source) >= (lengthSourceThreshold + 2)) && no_of_transport_pkt < 3)
    {
        const uint8 *source_ptr = SourceMap(source);
        uint32 copied = 0;
        uint32 frame;

        if(!buffer)
            buffer = PanicUnlessMalloc((MSBC_FRAME_LEN * frames_to_send) + AMA_MSBC_HEADER_LEN);

        payload_posn = initial_position;
        
        for (frame = 0; frame < frames_to_send; frame++)
        {
            memmove(&buffer[payload_posn], &source_ptr[(frame * MSBC_ENC_PKT_LEN) + 2], MSBC_FRAME_LEN);
            payload_posn += MSBC_FRAME_LEN;
            copied += MSBC_FRAME_LEN;
        }

        sent_if_necessary = amaTranportStreamData(buffer, copied);

        if(sent_if_necessary)
        {
            AMA_DEBUG(("S%d\n", copied));
            SourceDrop(source, lengthSourceThreshold);
        }
        else
        {
            AMA_DEBUG(("F\n"));
            break;
        }
        no_of_transport_pkt++;
    }

    if(buffer)
        free(buffer);

    AMA_DEBUG(("Remaining = %d\n", SourceSize(source)));

    return sent_if_necessary;
}

bool amaSendOpusSpeechData(Source source)
{

    uint16 payload_posn;
    uint16 lengthSourceThreshold;
    uint8 *buffer = NULL;
    bool sent_if_necessary = FALSE;
    uint8 no_of_transport_pkt = 0;
    ama_transport_t transport;
    uint16 opus_enc_pkt_len = OPUS_16KBPS_ENC_PKT_LEN; /* Make complier happy. */
    uint16 opus_frame_count = OPUS_16KBPS_RFCOMM_FRAME_COUNT;

    transport = AmaTransportGet();
    AMA_DEBUG(("amaSendOpusSourceSpeechData on %d transport\n", transport));

    switch(amaSpeechGetAudioFormat())
    {
        case AUDIO_FORMAT__OPUS_16KHZ_16KBPS_CBR_0_20MS :

            if(transport == ama_transport_rfcomm)
            {
                AMA_DEBUG(("16RF\n"));
                opus_enc_pkt_len = OPUS_16KBPS_ENC_PKT_LEN;
                opus_frame_count = OPUS_16KBPS_RFCOMM_FRAME_COUNT;
            }
            else
            {
                AMA_DEBUG(("16LE\n"));
                opus_enc_pkt_len = OPUS_16KBPS_ENC_PKT_LEN;
                opus_frame_count = OPUS_16KBPS_LE_FRAME_COUNT;
            }
            break;

        case AUDIO_FORMAT__OPUS_16KHZ_32KBPS_CBR_0_20MS :

            if(transport == ama_transport_rfcomm)
            {
                AMA_DEBUG(("32RF\n"));
                opus_enc_pkt_len = OPUS_32KBPS_ENC_PKT_LEN;
                opus_frame_count = OPUS_32KBPS_RFCOMM_FRAME_COUNT;
            }
            else
            {
                
                AMA_DEBUG(("32LE\n"));
                opus_enc_pkt_len = OPUS_32KBPS_ENC_PKT_LEN;
                opus_frame_count = OPUS_32KBPS_LE_FRAME_COUNT;
            }
            break;

        case AUDIO_FORMAT__PCM_L16_16KHZ_MONO :
        case AUDIO_FORMAT__MSBC:
            default :
                AMA_DEBUG(("Not Expected Codec on \n"));
                Panic();
                break;
    }

    lengthSourceThreshold = (opus_frame_count * opus_enc_pkt_len);
    AMA_DEBUG(("lengthSourceThreshold = %d\n", lengthSourceThreshold));

    AMA_DEBUG(("In = %d\n", SourceSize(source)));

    while (SourceSize(source) && (SourceSize(source) >= lengthSourceThreshold) && (no_of_transport_pkt < 3))
    {
        const uint8 *opus_ptr = SourceMap(source);
        uint16 frame;
        uint16 copied = 0;
        AMA_DEBUG(("N%d\n", no_of_transport_pkt));

        if(!buffer)
            buffer = PanicUnlessMalloc((lengthSourceThreshold) + 3);

        payload_posn = AMA_OPUS_HEADER_LEN;

        for (frame = 0; frame < opus_frame_count; frame++)
        {
            memmove(&buffer[payload_posn], &opus_ptr[(frame*opus_enc_pkt_len)], opus_enc_pkt_len);
            payload_posn += opus_enc_pkt_len;
            copied += opus_enc_pkt_len;
        }

        sent_if_necessary = amaTranportStreamData(buffer, copied);

        if(sent_if_necessary)
        {
            AMA_DEBUG(("S%d\n", copied));
            SourceDrop(source, lengthSourceThreshold);
        }
        else
        {
            AMA_DEBUG(("F\n"));
            break;
        }
        no_of_transport_pkt++;
    }

    if(buffer)
        free(buffer);

    AMA_DEBUG(("Remaining = %d\n", SourceSize(source)));

    return sent_if_necessary;
}
