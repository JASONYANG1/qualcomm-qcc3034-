/* Copyright (c) 2014 - 2016 Qualcomm Technologies International, Ltd. */
/* Part of 6.2 */

#include <sink.h>
#include <string.h>
#include <stream.h>
#include <gatt_ama_server.h>
#include "gatt_ama_server_private.h"
#include "gatt_ama_server_db.h"
#include "gatt_ama_server_access.h"
#include <gatt_ama_server.h>
#include "audio_plugin_if.h"
#include "audio_config.h"

extern GAMASS *AmaServer;

#define INVALID_SINK        (0xFFFF)
#define HANDLE_OFFSET       (2)

/****************************************************************************/
static gatt_ama_server_tx_status_t sendAttStreamData(uint16 cid, uint16 handle, const uint8_t *data, uint32_t length)
{
    Sink sink = StreamAttServerSink(cid);
    uint16 sink_size = length + HANDLE_OFFSET;

    if (sink == NULL)
        return gatt_ama_server_tx_status_invalid_sink;

    if (SinkSlack(sink) >= sink_size)
    {
        uint16 offset;
        uint8 *sink_data = NULL;

        offset = SinkClaim(sink, sink_size);

        if (offset == INVALID_SINK)
            return gatt_ama_server_tx_status_invalid_sink;

        sink_data = SinkMap(sink) + offset;
        sink_data[0] = handle & 0xFF;
        sink_data[1] = handle >> 8;
        memmove(&sink_data[HANDLE_OFFSET], data, length);

        if (SinkFlush(sink, sink_size))
            return gatt_ama_server_tx_status_success;
        else
            return gatt_ama_server_tx_status_invalid_sink;
    }
    else
    {
        if (!SinkIsValid(sink))
            return gatt_ama_server_tx_status_invalid_sink;
        return gatt_ama_server_tx_status_no_space_available;
    }
}

/****************************************************************************/
bool SendAmaNotification(uint8 *data, uint16 length)
{
#ifdef DEBUG_GATT_AMA_LE_TX
    uint16 count = 0;
#endif
    uint16 tx_mtu_size;
    GATT_AMA_SERVER_DEBUG_INFO(("AMA: SendAmaNotification for "));
    GATT_AMA_LE_TX(("AMA LE Tx len= %d\n", length));
    GATT_AMA_LE_TX(("AMA LE :"));

#ifdef DEBUG_GATT_AMA_LE_TX
    if(length < AMA_DEBUG_NOT_LE_SPEECH_DATA)
    {
        for(count = 0; count < length; count++)
        {
            GATT_AMA_LE_TX(("%x ",data[count]));
        }
        GATT_AMA_LE_TX(("\n"));
    }
#endif

    tx_mtu_size = GattGetMaxTxDataLength(AmaServer->cid);

    if(!(StreamAttServerSink(AmaServer->cid)==NULL))
    {
        return (sendAttStreamData(AmaServer->cid, AmaServer->stream_handle, data, length) == gatt_ama_server_tx_status_success);
    }
    else
    {
        /* The connection id must be invalid at this point */
        if (tx_mtu_size == 0)
        {
            GATT_AMA_SERVER_DEBUG_INFO(("AMA: Invalid MTU, drop notification\n"));
            return FALSE;
        }

        while(length)
        {
            uint16 bytesToSend = MIN(length, tx_mtu_size);

            /* Send notification to GATT Manager */
            GattManagerRemoteClientNotify((Task)&AmaServer->lib_task, AmaServer->cid, HANDLE_AMA_ALEXA_RX_CHAR, bytesToSend, data);

            data += bytesToSend;
            length -= bytesToSend;
        }
        return TRUE;
    }
}

