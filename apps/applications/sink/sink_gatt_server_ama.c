/****************************************************************************
Copyright (c) 2014 - 2019 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_gatt_server_ama.c

DESCRIPTION
    Routines to handle messages sent from the GATT AMA Server Task.
*/
#include "stdlib.h"
#include "stdio.h"

#include "vm.h"
#include "sink_ble.h"
#include "sink_gatt.h"
#include "sink_gatt_db.h"
#include "sink_gatt_server_ama.h"
#include "sink_gatt_common.h"
#include "sink_debug.h"
#include "sink_development.h"
#include "sink_private_data.h"
#include "sink_gatt_server.h"


#include <csrtypes.h>
#include <message.h>

#ifdef GATT_AMA_SERVER
#include <gatt_ama_server.h>
#endif

#ifdef ENABLE_AMA
#include <ama.h>
#endif

#ifdef GATT_AMA_SERVER

#define AMA_INVALID_STREAM_HANDLE    (0xffff)

#ifdef DEBUG_GATT_AMA_SERVER
#define GATT_AMA_SERVER_INFO(x) DEBUG(x)
#define GATT_AMA_SERVER_ERROR(x) DEBUG(x) TOLERATED_ERROR(x)
#else
#define GATT_AMA_SERVER_INFO(x)
#define GATT_AMA_SERVER_ERROR(x)
#endif

#define AMA_TX_MTU_SIZE    (178)


/* Assigned numbers for GATT Bluetooth Namespace Descriptors */
#define NAMESPACE_BLUETOOTH_SIG             0x01        /* Bluetooth SIG Namespace */
#define DESCRIPTION_BATTERY_UNKNOWN         0x0000      /* Bluetooth SIG description "unknown" */
#define DESCRIPTION_BATTERY_LOCAL           0x010F      /* Bluetooth SIG description "internal" for local battery*/
#define DESCRIPTION_BATTERY_SECOND          0x0002      /* Bluetooth SIG description "Second" for remote battery*/
#define DESCRIPTION_BATTERY_THIRD           0x0003      /* Bluetooth SIG description "third" for peer battery */


GAMASS*  sink_gatt_ama_server_task;

static TaskData local_ama_task;

/*******************************************************************************/
uint16 sinkGattAmaServerCalculateSize(void)
{
    /* size of the AMA server data */
    uint16 size = sizeof(GAMASS);

    GATT_AMA_SERVER_INFO(("AMA[%d]\n", size));
    return size;
}

/*******************************************************************************/
bool sinkGattAmaServerInitialise(uint16 **ptr)
{
    sinkGattUpdateMinimumTxMtu(AMA_TX_MTU_SIZE);

    if (GattAmaServerInit(  (GAMASS *)*ptr, sinkGetBleTask(), HANDLE_AMA_ALEXA_SERVICE,
                            HANDLE_AMA_ALEXA_SERVICE_END))
    {
        GATT_AMA_SERVER_INFO(("GATT AMA Server initialised\n"));
        gattServerSetServicePtr(ptr, gatt_server_service_ama);

        sink_gatt_ama_server_task = (GAMASS *)*ptr;

        /* The size of AMA server tasks is calculated and memory is alocated.
         * So advance the ptr so that the next Server while initializing.
         * shall not over write the same memory */
        *ptr += ADJ_GATT_STRUCT_OFFSET(GAMASS);

        /* this is just because the MORE_SPACE and other messages cannot be processed becasue of the GATT MANAger */
        local_ama_task.handler = sinkGattAmaServerMsgHandler;
        return TRUE;
    }

    /* GATT AMA server library initialization failed */
    GATT_AMA_SERVER_INFO(("GATT AMA Server init failed \n"));
    return FALSE;
}

/******************************************************************************/
void sinkGattAmaServerMsgHandler(Task task, MessageId id, Message message)
{
    UNUSED(task);

    if(id == GATT_AMA_SERVER_WRITE_IND)
    {
        GATT_AMA_SERVER_INFO((" GATT_AMA_SERVER_WRITE_IND	\n",id ));
    }

    else if(id == GATT_AMA_SERVER_CLIENT_C_CFG)
    {
        uint16 client_config = ((GATT_AMA_SERVER_CLIENT_C_CFG_T*)message)->client_config;

        GATT_AMA_SERVER_INFO((" GATT_AMA_SERVER_CLIENT_C_CFG %d\n",client_config ));

        if(client_config)
        {
            /* Send the AMA Version */
               AmaTransportSendVersion(AMA_VERSION_MAJOR, AMA_VERSION_MINOR);

        }

        sinkAmaServerConnectionParameterUpdate(TRUE);
    }
}


/******************************************************************************/
void sinkAmaServerConnectEvent(GATT_MANAGER_REMOTE_CLIENT_CONNECT_CFM_T * cfm)
{
    GATT_AMA_SERVER_INFO(("BLE sinkAmaServerConnectEvent cid - %d   index - %d\n", cfm->cid, index));

    if (sink_gatt_ama_server_task->cid == 0)
    {
        sink_gatt_ama_server_task->cid = cfm->cid;
        sink_gatt_ama_server_task->stream_handle = HANDLE_AMA_ALEXA_RX_CHAR;
        sink_gatt_ama_server_task->taddr =  cfm->taddr;
    }
}

/******************************************************************************/
void sinkAmaServerDisconnectEvent(uint16 cid, uint16 reason)
{
    UNUSED(reason);
    GATT_AMA_SERVER_INFO(("BLE AMA Discon Ev cid  %04x res %04x  \n",cid, reason));

    if(sink_gatt_ama_server_task->cid == cid)
    {
        memset(&(sink_gatt_ama_server_task->taddr), 0, sizeof(typed_bdaddr));
        sink_gatt_ama_server_task->cid= 0;
        sink_gatt_ama_server_task->stream_handle = AMA_INVALID_STREAM_HANDLE;
        AmaLeDisconnected();
    }
}

/******************************************************************************/
void sinkAmaServerConnectionParameterUpdate(bool fast)
{
    GATT_AMA_SERVER_INFO(("BLE AMA cannction update fast = %04x  \n",fast ));

    if(fast == FALSE)
    {
        sinkBleSetSlaveConnectionParamsUpdate(&sink_gatt_ama_server_task->taddr);
    }
    else
    {

        GATT_AMA_SERVER_INFO(("Set BLE Updated FAST Slave Connection Params for AMA \n"));

        ConnectionDmBleConnectionParametersUpdateReq(
                    sinkGetBleTask(),
                    &sink_gatt_ama_server_task->taddr,
                    SINK_BLE_AMA_CONN_PARAM_SLAVE_CONN_INTERVAL_MIN,
                    SINK_BLE_AMA_CONN_PARAM_SLAVE_CONN_INTERVAL_MAX,
                    SINK_BLE_AMA_PARAM_SLAVE_CONN_LATENCY,
                    SINK_BLE_AMA_PARAM_SUPERVISION_TIMEOUT,
                    SINK_BLE_AMA_PARAM_CE_LENGTH_MIN,
                    SINK_BLE_AMA_PARAM_CE_LENGTH_MAX
                    );
    }
}

#endif /* GATT_AMA_SERVER */
