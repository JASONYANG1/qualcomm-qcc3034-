/* Copyright (c) 2018 Qualcomm Technologies International, Ltd. */
/*    */
/****************************************************************************
FILE
    acl_if.h

CONTAINS
    Definitions used by acl handover traps.

*/

#ifndef __APP_ACL_IF_H__
#define __APP_ACL_IF_H__

/*! @brief Status of handover prepare state as returned by the AclHandoverPrepared()
    trap.
*/
typedef enum
{
    /*! Handover preparation in progress. */
    ACL_HANDOVER_PREPARE_IN_PROGRESS,

    /*! Handover preparation completed. */
    ACL_HANDOVER_PREPARE_COMPLETE,

    /*! Handover preparation failed. */
    ACL_HANDOVER_PREPARE_FAILED

} acl_handover_prepare_status;

/*! @brief Inbound data processed status as returned by the AclReceivedDataProcessed()
    trap.
*/
typedef enum
{
    /*! All received ACL data processed and consumed successfully. */
    ACL_RECEIVE_DATA_PROCESSED_COMPLETE,

    /*! All received ACL data not processed within the configured timeout. */
    ACL_RECEIVE_DATA_PROCESSED_TIMEOUT,

    /*! Received ACL data processing failed. */
    ACL_RECEIVE_DATA_PROCESSED_FAILED

} acl_rx_processed_status;

#endif /* __APP_ACL_IF_H__ */
