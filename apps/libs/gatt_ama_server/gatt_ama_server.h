/* Copyright (c) 2014 - 2016 Qualcomm Technologies International, Ltd. */
/* Part of 6.2 */

/*!
@file    gatt_ama_server.h
@brief   Header file for the GATT ama server library.

        This file provides documentation for the GATT ama server library
        API (library name: gatt_ama_server).
*/

#ifndef GATT_AMA_SERVER_H_
#define GATT_AMA_SERVER_H_

#include <csrtypes.h>
#include <message.h>

#include <library.h>

#include "gatt_manager.h"

/*! @brief The ama server internal structure for the server role.

    This structure is visible to the application as it is responsible for managing resource to pass to the ama library.
    The elements of this structure are only modified by the ama library.
    The application SHOULD NOT modify the values at any time as it could lead to undefined behaviour.

 */
typedef struct __GAMASS
{
    TaskData lib_task;
    Task app_task;
    typed_bdaddr taddr;
    /*! Connection identifier of remote device. */
    uint16 cid;
    /*Handle stream data*/
    uint16 stream_handle;
}GAMASS ;


/*!
    @brief Status code returned from the GATT ama server library

    This status code indicates status of transmit  data 
*/

typedef enum {
    gatt_ama_server_tx_status_no_space_available,
    gatt_ama_server_tx_status_success,
    gatt_ama_server_tx_status_invalid_sink
} gatt_ama_server_tx_status_t;


typedef struct __GATT_AMA_SERVER_CLIENT_C_CFG
{
    const GAMASS *ama;    /*! Reference structure for the instance  */
    uint16 cid;                 /*! Connection ID */
    uint16 handle;
    uint16 client_config;        /*! Client Configuration value to be written */
}GATT_AMA_SERVER_CLIENT_C_CFG_T;

/*! @brief Enumeration of messages an application task can receive from the ama server library.
 */
typedef enum
{
    /* Server messages */
    GATT_AMA_SERVER_WRITE_IND = GATT_AMA_SERVER_MESSAGE_BASE,             /* 00 */
    GATT_AMA_SERVER_CLIENT_C_CFG,									  /* 01 */
    /* Library message limit */

    GATT_AMA_SERVER_TICK,

    GATT_AMA_SERVER_MESSAGE_TOP
} gatt_ama_server_message_id_t;

/*!
    @brief Initialises the Ama Service Library in the Server role.

    @param ama_server pointer to server role data
    @param app_task The Task that will receive the messages sent from this ama server library.
    @param init_params pointer to ama server initialization parameters
    @param start_handle start handle
    @param end_handle end handle

    @return TRUE if successful, FALSE otherwise

*/
bool GattAmaServerInit(GAMASS *ama_server,
                           Task app_task,
                           uint16 start_handle,
                           uint16 end_handle);
/*!
    @brief Send Ama Service notication 

    @param data pointer to server  data
    @param length length of ama server data

    @return TRUE if successful, FALSE otherwise

*/
bool SendAmaNotification(uint8 *data, uint16 length);

#endif
