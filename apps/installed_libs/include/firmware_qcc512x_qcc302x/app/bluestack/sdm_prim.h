/*!

Copyright (c) 2019 Qualcomm Technologies International, Ltd.
  

\file   sdm_prim.h

\brief  Bluestack Shadow Manager 

        The functionalities exposed in this file are Qualcomm proprietary.

        Bluestack Shadow Manager provides application interface to perform shadowing functionalities.
        Currently the functionalities are only applicable for BR/EDR and 
        eSCO links.
*/
#ifndef _SDM_PRIM_H_
#define _SDM_PRIM_H_

#include "hci.h"
#include "dm_prim.h"
#include "l2cap_prim.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
    \name Response/result error and status codes

    \{
*/
/*! Operation was successful */
#define SDM_RESULT_SUCCESS                      0x0000
#define SDM_RESULT_INVALID_PARAM                0x0001
#define SDM_RESULT_INPROGRESS                   0x0002
#define SDM_RESULT_FAIL                         0x0003
#define SDM_RESULT_TIMEOUT                      0x0004


/*! \name Bluestack primitive segmentation and numbering

    \brief SDM primitives occupy the number space from
    SDM_PRIM_BASE to (SDM_PRIM_BASE | 0x00FF).

    \{ */
#define SDM_PRIM_DOWN           (SDM_PRIM_BASE)
#define SDM_PRIM_UP             (SDM_PRIM_BASE | 0x0080)
#define SDM_PRIM_MAX            (SDM_PRIM_BASE | 0x00FF)

typedef enum sdm_prim_tag
{
    /* downstream primitives */
    ENUM_SDM_REGISTER_REQ = SDM_PRIM_DOWN,
    ENUM_SDM_SET_BREDR_SLAVE_ADDRESS_REQ,
    ENUM_SDM_SHADOW_LINK_CREATE_REQ,
    ENUM_SDM_SHADOW_LINK_DISCONNECT_REQ,
    ENUM_SDM_SHADOW_L2CAP_CREATE_REQ,
    ENUM_SDM_SHADOW_L2CAP_CREATE_RSP,
    ENUM_SDM_SHADOW_L2CAP_DISCONNECT_REQ,
    ENUM_SDM_SHADOW_L2CAP_DISCONNECT_RSP,

    ENUM_SDM_DEBUG_TRAP_API_REQ = SDM_PRIM_UP - 1,

    /* upstream primitives */
    ENUM_SDM_REGISTER_CFM = SDM_PRIM_UP,
    ENUM_SDM_SET_BREDR_SLAVE_ADDRESS_CFM,
    ENUM_SDM_SET_BREDR_SLAVE_ADDRESS_IND,
    ENUM_SDM_SHADOW_ACL_LINK_CREATE_CFM,
    ENUM_SDM_SHADOW_ACL_LINK_CREATE_IND,
    ENUM_SDM_SHADOW_LINK_DISCONNECT_CFM,
    ENUM_SDM_SHADOW_LINK_DISCONNECT_IND,
    ENUM_SDM_SHADOW_ESCO_LINK_CREATE_CFM,
    ENUM_SDM_SHADOW_ESCO_LINK_CREATE_IND,
    ENUM_SDM_SHADOW_ESCO_RENEGOTIATED_IND,
    ENUM_SDM_SHADOW_L2CAP_CREATE_IND,
    ENUM_SDM_SHADOW_L2CAP_CREATE_CFM,
    ENUM_SDM_SHADOW_L2CAP_DISCONNECT_IND,
    ENUM_SDM_SHADOW_L2CAP_DISCONNECT_CFM,
    ENUM_SDM_SHADOW_L2CAP_DATA_SYNC_IND,

    ENUM_SDM_DEBUG_IND = SDM_PRIM_MAX - 2,
    ENUM_SDM_DEBUG_TRAP_API_CFM = SDM_PRIM_MAX - 1

} SDM_PRIM_T;

/**
 * Type definition used to specify shadow return and reason code.
 * The return and reason code corresponds to HCI and Qualcomm proprietary code.
 *
 * 0x0000 - 0x00FF  Defined by Bluetooth Core Specification, Volume 2, Part D.
 * 0x0100 - 0x01FF  Reserved for Future Qualcomm Use (RFQU).
 */
typedef uint16_t sdm_return_t;
typedef uint16_t sdm_reason_t;

/**
 * Type definition used to specify shadow link type.
 */
typedef uint8_t link_type_t;

#define LINK_TYPE_ACL       ((link_type_t)0x01)
#define LINK_TYPE_ESCO      ((link_type_t)0x02)

/**
 * Type definition used to specify shadow role type.
 */
typedef uint8_t shadow_role_t;
 
#define ROLE_TYPE_PRIMARY       ((shadow_role_t)0x00)
#define ROLE_TYPE_SECONDARY     ((shadow_role_t)0x01)

/* downstream primitives */
#define SDM_REGISTER_REQ                ((sdm_prim_t)ENUM_SDM_REGISTER_REQ)
#define SDM_SET_BREDR_SLAVE_ADDRESS_REQ ((sdm_prim_t)ENUM_SDM_SET_BREDR_SLAVE_ADDRESS_REQ)
#define SDM_SHADOW_LINK_CREATE_REQ      ((sdm_prim_t)ENUM_SDM_SHADOW_LINK_CREATE_REQ)
#define SDM_SHADOW_LINK_DISCONNECT_REQ  ((sdm_prim_t)ENUM_SDM_SHADOW_LINK_DISCONNECT_REQ)
#define SDM_SHADOW_L2CAP_CREATE_REQ     ((sdm_prim_t)ENUM_SDM_SHADOW_L2CAP_CREATE_REQ)
#define SDM_SHADOW_L2CAP_CREATE_RSP     ((sdm_prim_t)ENUM_SDM_SHADOW_L2CAP_CREATE_RSP)
#define SDM_SHADOW_L2CAP_DISCONNECT_REQ ((sdm_prim_t)ENUM_SDM_SHADOW_L2CAP_DISCONNECT_REQ)
#define SDM_SHADOW_L2CAP_DISCONNECT_RSP ((sdm_prim_t)ENUM_SDM_SHADOW_L2CAP_DISCONNECT_RSP)


/* upstream primitives */
#define SDM_REGISTER_CFM                ((sdm_prim_t)ENUM_SDM_REGISTER_CFM)
#define SDM_SET_BREDR_SLAVE_ADDRESS_CFM ((sdm_prim_t)ENUM_SDM_SET_BREDR_SLAVE_ADDRESS_CFM)
#define SDM_SET_BREDR_SLAVE_ADDRESS_IND ((sdm_prim_t)ENUM_SDM_SET_BREDR_SLAVE_ADDRESS_IND)
#define SDM_SHADOW_ACL_LINK_CREATE_CFM  ((sdm_prim_t)ENUM_SDM_SHADOW_ACL_LINK_CREATE_CFM)
#define SDM_SHADOW_ACL_LINK_CREATE_IND  ((sdm_prim_t)ENUM_SDM_SHADOW_ACL_LINK_CREATE_IND)
#define SDM_SHADOW_LINK_DISCONNECT_CFM  ((sdm_prim_t)ENUM_SDM_SHADOW_LINK_DISCONNECT_CFM)
#define SDM_SHADOW_LINK_DISCONNECT_IND  ((sdm_prim_t)ENUM_SDM_SHADOW_LINK_DISCONNECT_IND)
#define SDM_SHADOW_ESCO_LINK_CREATE_CFM ((sdm_prim_t)ENUM_SDM_SHADOW_ESCO_LINK_CREATE_CFM)
#define SDM_SHADOW_ESCO_LINK_CREATE_IND ((sdm_prim_t)ENUM_SDM_SHADOW_ESCO_LINK_CREATE_IND)
#define SDM_SHADOW_ESCO_RENEGOTIATED_IND ((sdm_prim_t)ENUM_SDM_SHADOW_ESCO_RENEGOTIATED_IND)
#define SDM_SHADOW_L2CAP_CREATE_IND     ((sdm_prim_t)ENUM_SDM_SHADOW_L2CAP_CREATE_IND)
#define SDM_SHADOW_L2CAP_CREATE_CFM     ((sdm_prim_t)ENUM_SDM_SHADOW_L2CAP_CREATE_CFM)
#define SDM_SHADOW_L2CAP_DISCONNECT_IND ((sdm_prim_t)ENUM_SDM_SHADOW_L2CAP_DISCONNECT_IND)
#define SDM_SHADOW_L2CAP_DISCONNECT_CFM ((sdm_prim_t)ENUM_SDM_SHADOW_L2CAP_DISCONNECT_CFM)
#define SDM_SHADOW_L2CAP_DATA_SYNC_IND ((sdm_prim_t)ENUM_SDM_SHADOW_L2CAP_DATA_SYNC_IND)

#define SDM_DEBUG_IND                     ((sdm_prim_t)ENUM_SDM_DEBUG_IND)
/*! \} */

/*! \brief Types for SDM */
typedef uint16_t                sdm_prim_t;
typedef uint16_t                sdm_result_t;

/*! \brief Register the SDM subsystem request

    Before any SDM operations can be performed the SDM subsystem shall
    be registered in order to allocate required resources and a 
    destination phandle for upstream application primitives shall also
    be registered.
*/
typedef struct
{
    sdm_prim_t          type;           /*!< Always SDM_REGISTER_REQ */
    phandle_t           phandle;        /*!< Destination phandle */
} SDM_REGISTER_REQ_T;


typedef struct
{
    sdm_prim_t          type;           /*!< Always SDM_REGISTER_CFM */
    phandle_t           phandle;        /*!< Destination phandle */
    sdm_result_t        result;         /*!< Result code - uses SDM_RESULT range */
} SDM_REGISTER_CFM_T;


/*! \brief Set slave address to a requested bluetooth address

    Change the address of slave device of a given link
    The initiating device will receive SDM_SET_BREDR_SLAVE_ADDRESS_CFM
    when the request is processed. The other device will receive
    SDM_SET_BREDR_SLAVE_ADDRESS_IND once the request is processed.

    If the status of the request is successful then 
    SDM_SET_BREDR_SLAVE_ADDRESS_CFM/SDM_SET_BREDR_SLAVE_ADDRESS_IND will
    contain old bluetooth address and new bluetooth address set on the 
    slave device.

    Flags field in the confirmation or indication message will identify
    if the slave device is local or remote.See Flag definition below.
*/
typedef struct
{
    sdm_prim_t          type;           /*!< Always SDM_SET_BREDR_SLAVE_ADDRESS_REQ */
    phandle_t           phandle;        /*!< Destination phandle */
    BD_ADDR_T           remote_bd_addr; /*!< Bluetooth address of remote device */
    BD_ADDR_T           new_bd_addr;    /*!< New Bluetooth address requested on slave device */
} SDM_SET_BREDR_SLAVE_ADDRESS_REQ_T;

/* Flags identifying local or remote device for
 * address change
 */
#define LOCAL_ADDRESS_CHANGED   0x00
#define REMOTE_ADDRESS_CHANGED  0x01

/*! \brief Confirmation of set BREDR slave address request

    This confirmation provides status of execution of
    SDM_SET_BREDR_SLAVE_ADDRESS_REQ. If status is success then confirmation
    also provides new address along with the old address of the slave device.
    Flags field identifies if the slave device is local or remote.
    See Flag definition above.

    Note:
    Flag definition can be ignored for failure status.
 */
typedef struct
{
    sdm_prim_t          type;           /*!< Always SDM_SET_BREDR_SLAVE_ADDRESS_CFM */
    phandle_t           phandle;        /*!< destination phandle */
    hci_return_t        status;         /*!< Anything other than HCI_SUCCESS is a failure */
    uint16_t            flags;          /*!< See flag definition above */
    BD_ADDR_T           old_bd_addr;    /*!< Old bluetooth address of slave device */
    BD_ADDR_T           new_bd_addr;    /*!< New bluetooth address of slave device
                                             if status is HCI_SUCCESS*/
} SDM_SET_BREDR_SLAVE_ADDRESS_CFM_T;

/*! \brief Indication of set BREDR slave address request on slave device

    This indication is sent when bluetooth address of slave device is
    changed asychronously, because of remote device initiated procedure.

    Note:
    Flag definition can be ignored for failure status.
 */
typedef struct
{
    sdm_prim_t          type;           /* Always  SDM_SET_BREDR_SLAVE_ADDRESS_IND */
    phandle_t           phandle;        /* destination phandle */
    uint16_t            flags;          /* See flag definition above */
    BD_ADDR_T           old_bd_addr;    /*!< Old bluetooth address of slave device */
    BD_ADDR_T           new_bd_addr;    /*!< New bluetooth address of slave device
                                             if status is HCI_SUCCESS*/
} SDM_SET_BREDR_SLAVE_ADDRESS_IND_T;

/*! \brief Setup a shadow ACL or eSCO link on a primary device

    Primary device uses this prim to establish a shadow ACL or eSCO link 
    between the secondary and the remote device based on "link_type" field.

    The shadow ACL allows the secondary device to synchronize to the link 
    between the primary and the remote device. It allows handing over of 
    primary role between primary and secondary device. 

    The shadow eSCO allows secondary device to sniff eSCO data sent from remote
    device to the primary device.

    Shadow ACL link creation is indicated using SDM_SHADOW_ACL_LINK_CREATE_CFM
    and shadow eSCO link creation is indicated using 
    SDM_SHADOW_ESCO_LINK_CREATE_CFM. When shadow link is disconnected 
    it will be indicated using SDM_SHADOW_LINK_DISCONNECT_CFM_T/IND_T.
   
    Note:
    a. The primary and secondary should be connected on an ACL link before the
    creation of shadow link.
    b. The shadow ACL link creation needs to be done before the creation of 
    shadow eSCO link.
*/
typedef struct
{
    sdm_prim_t          type;              /*!< Always SDM_SHADOW_LINK_CREATE_REQ */
    phandle_t           phandle;           /*!< Destination phandle */
    TP_BD_ADDR_T        shadow_bd_addr;    /*!< Bluetooth address of remote device which is being shadowed */
    TP_BD_ADDR_T        secondary_bd_addr; /*!< Bluetooth address of secondary device */
    link_type_t         link_type;         /*!< Type of shadow link, either ACL or eSCO */
} SDM_SHADOW_LINK_CREATE_REQ_T;

/*! \brief Confirmation of shadow ACL link creation

    This confirmation provides status for shadow ACL link creation request 
   (SDM_SHADOW_LINK_CREATE_REQ) on a primary device.

    The status value anything other than HCI_SUCCESS indicates failure of 
    shadow ACL link creation procedure. When the shadow ACL link creation is 
    successful, the secondary device will be shadowing the ACL link between the
    primary and remote device.

    The "connection_handle" uniquely identifies different shadowing links. Its 
    used as an identifier to subsequently perform other operations related to 
    shadowing.
*/
typedef struct
{
    sdm_prim_t              type;              /*!< Always SDM_SHADOW_ACL_LINK_CREATE_CFM */
    phandle_t               phandle;           /*!< Destination phandle */
    sdm_return_t            status;            /*!< Anything other than HCI_SUCCESS is a failure */
    hci_connection_handle_t connection_handle; /*!< Connection handle for the shadow ACL */
    TP_BD_ADDR_T            buddy_bd_addr;     /*!< Secondary device's address */
    TP_BD_ADDR_T            shadow_bd_addr;    /*!< Bluetooth address of Peer device which is being shadowed */
    shadow_role_t           role;              /*!< Role of the local device for the shadow link, primary. */
} SDM_SHADOW_ACL_LINK_CREATE_CFM_T;

/*! \brief Indication of shadow ACL link creation

    This event indicates shadow ACL link creation on secondary device.
    The shadow ACL link is created when primary device initiates the procedure.
    When the shadow ACL link creation is successful, the secondary device will 
    be shadowing the ACL link between the primary and remote device.

    The "connection_handle" uniquely identifies different shadowing links. It 
    is used as an identifier to subsequently perform other operations related 
    to shadowing.

    Note:
    No data is expected to be received on this shadow ACL link.
*/
typedef struct
{
    sdm_prim_t              type;              /*!< Always SDM_SHADOW_ACL_LINK_CREATE_IND */
    phandle_t               phandle;           /*!< Destination phandle */
    sdm_return_t            status;            /*!< Anything other than HCI_SUCCESS is a failure */
    hci_connection_handle_t connection_handle; /*!< Connection handle for the shadow ACL */
    TP_BD_ADDR_T            buddy_bd_addr;     /*!< Primary device's address */
    TP_BD_ADDR_T            shadow_bd_addr;    /*!< Bluetooth address of Peer device which is being shadowed */
    shadow_role_t           role;              /*!< Role of the local device for the shadow link, secondary */
} SDM_SHADOW_ACL_LINK_CREATE_IND_T;

/*! \brief Disconnect shadow ACL or eSCO link

    This prim is used to disconnect a shadow ACL or eSCO link between
    the secondary and remote device. Upon disconnection of shadow links 
    SDM_SHADOW_LINK_DISCONNECT_CFM is sent to the application.

    Note:
    The eSCO shadow link needs to be disconnected before disconnecting the
    ACL shadow link.
*/
typedef struct
{
    sdm_prim_t              type;        /*!< Always SDM_SHADOW_LINK_DISCONNECT_REQ */
    phandle_t               phandle;     /*!< Destination phandle */
    hci_connection_handle_t conn_handle; /*!< Connection handle of a eSCO/ACL shadow link */
    hci_reason_t            reason;      /*!< Reason to be reported in SDM_SHADOW_LINK_DISCONNECT_IND */
} SDM_SHADOW_LINK_DISCONNECT_REQ_T;

/*! \brief Confirmation of shadow ACL or eSCO link disconnection

    This confirmation provides status of shadow link disconnection request from
    the application. HCI_SUCCESS status indicates that disconnection of the 
    link is successful.
    
*/
typedef struct
{
    sdm_prim_t              type;        /*!< Always SDM_SHADOW_LINK_DISCONNECT_CFM */
    phandle_t               phandle;     /*!< Destination phandle */
    hci_connection_handle_t conn_handle; /*!< Connection handle of a eSCO/ACL shadow link */
    sdm_return_t            status;      /*!< Disconnection status, success or failure */
    link_type_t             link_type;   /*!< Type of shadow link, eSCO/ACL */
    shadow_role_t           role;        /*!< Role of the local device for the shadow link, Primary/Secondary */
} SDM_SHADOW_LINK_DISCONNECT_CFM_T;

/*! \brief Indication of shadow ACL or eSCO link disconnection

    This indication is sent to the application when a shadow ACL/eSCO 
    link is disconnected.

    The disconnect indication can be received if 
    a. Remote primary/secondary device has disconnected the shadow link.
    b. ACL or eSCO between the primary and the phone is disconnected.
    c. ACL between the primary and secondary is disconnected.
*/
typedef struct
{
    sdm_prim_t              type;        /*!< Always SDM_SHADOW_LINK_DISCONNECT_IND */
    phandle_t               phandle;     /*!< Destination phandle */
    hci_connection_handle_t conn_handle; /*!< Connection handle of a eSCO/ACL shadow link */
    sdm_reason_t            reason;      /*!< Disconnection reason received from the remote device */
    link_type_t             link_type;   /*!< Type of shadow link, eSCO/ACL */
    shadow_role_t           role;        /*!< Role of the local device for the shadow link, Primary/Secondary */
} SDM_SHADOW_LINK_DISCONNECT_IND_T;

/*! \brief Confirmation of shadow eSCO link creation

    This confirmation provides status for shadow eSCO link creation request
    (SDM_SHADOW_LINK_CREATE_REQ) on a primary device.

    The status value anything other than HCI_SUCCESS indicates failure of 
    shadow eSCO link creation procedure. When the shadow eSCO link creation is 
    successful, the secondary device will be shadowing the eSCO link between the
    primary and remote device.

    The "connection_handle" uniquely identifies different shadowing links. Its 
    used as an identifier to subsequently perform other operations related to 
    shadowing.

    Note:
    a. ESCO parameters for the shadow eSCO link are same as eSCO link with     
       remote device.
    b. When primary role is handed over to secondary device, 
       the original (bidirectional) eSCO link to the remote device becomes a 
       receive-only shadowed eSCO link. The connection_handle remains valid 
       throughout.    
*/
typedef struct
{
    sdm_prim_t              type;              /*!< Always SDM_SHADOW_ESCO_LINK_CREATE_CFM */
    phandle_t               phandle;           /*!< Destination phandle */
    sdm_return_t            status;            /*!< Anything other than HCI_SUCCESS is a failure */
    hci_connection_handle_t connection_handle; /*!< Connection handle for the shadow eSCO link */
    TP_BD_ADDR_T            buddy_bd_addr;     /*!< Secondary device's address */
    TP_BD_ADDR_T            shadow_bd_addr;    /*!< Bluetooth address of Peer device which is being shadowed */
    shadow_role_t           role;              /*!< Role of the local device for the shadow link, primary. */  
} SDM_SHADOW_ESCO_LINK_CREATE_CFM_T;

/* \brief Indication of shadow eSCO link creation

    This event indicates shadow eSCO link creation on secondary device. Shadow 
    eSCO link is created when primary device initiates the procedure.

    The shadow eSCO allows secondary device to sniff eSCO data sent from remote
    device to the primary device.

    The "connection_handle" uniquely identifies different shadowing links. Its 
    used as an identifier to subsequently perform other operations related to 
    shadowing.
    
    Note: 
    a. When secondary device becomes primary device after handover procedure,
       receive-only shadowed eSCO link becomes the bidirectional eSCO link to 
       the remote device. The connection_handle remains valid throughout.
*/
typedef struct
{
    sdm_prim_t              type;              /*!< Always SDM_SHADOW_ESCO_LINK_CREATE_IND */
    phandle_t               phandle;           /*!< Destination phandle */
    sdm_return_t            status;            /*!< Anything other than HCI_SUCCESS is a failure */
    hci_connection_handle_t connection_handle; /*!< Connection handle for the shadow eSCO link */
    TP_BD_ADDR_T            buddy_bd_addr;     /*!< Secondary device's address */
    TP_BD_ADDR_T            shadow_bd_addr;    /*!< Bluetooth address of remote device which is being shadowed */
    shadow_role_t           role;              /*!< Role of the local device for the shadow link, secondary. */     
    link_type_t             link_type;         /*!< Type of shadow link, eSCO */
    uint8_t                 tx_interval;       /*!< transmission interval in slots */
    uint8_t                 wesco;             /*!< retransmission window in slots */
    uint16_t                rx_packet_length;  /*!< Rx payload length in bytes */
    uint16_t                tx_packet_length;  /*!< Tx payload length in bytes */
    uint8_t                 air_mode;          /*!< Coding format of eSCO packets */
} SDM_SHADOW_ESCO_LINK_CREATE_IND_T;

/* \brief Indication of new parameters for shadow eSCO link

    This event indicates new negotiated parameters of the shadow eSCO link on 
    secondary device, this event is generated when primary and remote devices 
    successfully renegotiates new eSCO parameters for the link. 

    The "connection_handle" uniquely identifies different shadowing links. Its 
    used as an identifier to subsequently perform other operations related to 
    shadowing.
*/
typedef struct
{
    sdm_prim_t              type;              /*!< Always SDM_SHADOW_ESCO_RENEGOTIATED_IND */
    phandle_t               phandle;           /*!< Destination phandle */
    hci_connection_handle_t connection_handle; /*!< Connection handle for the shadow eSCO link */
    uint8_t                 tx_interval;       /*!< transmission interval in slots */
    uint8_t                 wesco;             /*!< retransmission window in slots */
    uint16_t                rx_packet_length;  /*!< Rx payload length in bytes */
    uint16_t                tx_packet_length;  /*!< Tx payload length in bytes */
} SDM_SHADOW_ESCO_RENEGOTIATED_IND_T;

/* Initiate shadowing of an L2CAP channel (Basic mode) on Primary device. 
 *
 * L2CAP shadowing creates L2CAP instance on Primary and Secondary device 
 * to shadow a particular L2CAP channel between Primary and Remote device.
 * Status of L2CAP shadowing is indicated using SDM_SHADOW_L2CAP_CREATE_CFM
 *  
 * When reliable ACL sniffing is enabled, the shadow L2CAP processes L2CAP
 * packets sent by the remote device to the primary device on the shadowed 
 * L2CAP channel. Processed L2CAP packets are sent to the associated shadow 
 * L2CAP stream. The application can access the shadowed L2CAP packets via
 * the shadow L2CAP stream.
 * 
 * L2CAP shadowing is completely driven by Primary device just like ACL and eSCO
 * shadowing. 
 *
 * Note: 
 *   1. L2CAP shadowing doesn't guarantee reliable L2CAP data sniffing, 
 *      Secondary device can miss one or more L2CAP packets sent by remote 
 *      device to Primary device.
 *   2. This primitive shall be used only for L2CAP basic mode, i.e mode shall 
 *      be set to L2CA_FLOW_MODE_BASIC. Streaming mode and ERTM are not 
 *      supported.
 */
typedef struct
{
    sdm_prim_t               type;              /*!< Always SDM_SHADOW_L2CAP_CREATE_REQ */
    phandle_t                phandle;           /*!< Destination phandle */ 
    hci_connection_handle_t  connection_handle; /*!< Connection handle of the shadow ACL */
    l2ca_cid_t               cid;               /*!< CID of L2CAP channel to be shadowed */
    uint16_t                 flags;             /*!< Reserved for future use, shall be set to 0 */
} SDM_SHADOW_L2CAP_CREATE_REQ_T;


/* Indication of request to create Shadow L2CAP channel on Secondary device.
 * 
 * This event indicates that Primary device has initiated Shadowing of an L2CAP 
 * channel between Primary and Remote device. Application shall respond to this
 * event with SDM_SHADOW_L2CAP_CREATE_RSP.
 * 
 */
typedef struct
{
    sdm_prim_t               type;              /*!< Always SDM_SHADOW_L2CAP_CREATE_IND */
    phandle_t                phandle;           /*!< Destination phandle */ 
    hci_connection_handle_t  connection_handle; /*!< Connection handle of the shadow ACL */
    l2ca_cid_t               cid;               /*!< CID of L2CAP channel to be shadowed */
    uint16_t                 flags;                  /*!< Reserved for future use, shall be set to 0 */
} SDM_SHADOW_L2CAP_CREATE_IND_T;


/* Response to create Shadow L2CAP channel on Secondary device. 
 * 
 * When L2CAP shadowing is accepted, L2CAP instance will be created on Secondary
 * device to shadow L2CAP channel between Primary and Remote device. Application
 * shall provide configuration of the shadow L2CAP channel using conftab, usage 
 * of conftab is same as documented in L2CAP auto (i.e L2CA_AUTO_TP_CONNECT_RSP/
 * L2CA_AUTO_CONNECT_RSP). For L2CAP basic mode only L2CA_AUTOPT_MTU_IN is the 
 * valid configuration. Result of Shadow L2CAP channel creation is indicated 
 * in SDM_SHADOW_L2CAP_CREATE_CFM.
 * 
 * Note: L2CAP shadowing is supported only for Basic L2CAP channels. 
 */
typedef struct
{
    sdm_prim_t               type;              /*!< Always SDM_SHADOW_L2CAP_CREATE_RSP */
    phandle_t                phandle;           /*!< Destination phandle */ 
    hci_connection_handle_t  connection_handle; /*!< Connection handle of the shadow ACL */
    l2ca_conn_result_t       response;          /*!< Result code - uses L2CA_CONNECT range */
    l2ca_cid_t               cid;               /*!< CID of L2CAP channel to be shadowed */
    uint16_t                 conftab_length;    /*!< Number of uint16_t's in the 'conftab' table */
    uint16_t                *conftab;           /*!< Configuration table (key,value pairs) */
} SDM_SHADOW_L2CAP_CREATE_RSP_T;


/* Confirmation for Shadow L2CAP Create Request.
 *
 * This event is sent on both Primary and Secondary device to confirm shadow
 * L2CAP connection creation status, on success a receive only L2CAP stream is 
 * created on Secondary device.
 */
typedef struct
{
    sdm_prim_t               type;              /*!< Always SDM_SHADOW_L2CAP_CREATE_CFM */
    phandle_t                phandle;           /*!< Destination phandle */
    hci_connection_handle_t  connection_handle; /*!< Connection handle of the shadow ACL */
    l2ca_cid_t               cid;               /*!< CID of L2CAP channel being shadowed */
    uint16_t                 flags;             /*!< Reserved for future use, shall be set to 0 */
    l2ca_conn_result_t       result;            /*!< Result code - uses L2CA_CONNECT range */
} SDM_SHADOW_L2CAP_CREATE_CFM_T;

/*
 * Disconnect Shadow L2CAP connection on Primary device. 
 * 
 * Shadowing of L2CAP channel on Primary and Secondary device is aborted when
 * shadow ACL of the L2CAP channel is disconnected.
 * Returns SDM_SHADOW_L2CAP_DISCONNECT_CFM when disconnection 
 * is complete. 
 */ 
typedef struct
{
    sdm_prim_t          type;              /*!< Always SDM_SHADOW_L2CAP_DISCONNECT_REQ */
    phandle_t           phandle;           /*!< Destination phandle */
    l2ca_cid_t          cid;               /*!< cid of L2CAP channel being shadowed */
} SDM_SHADOW_L2CAP_DISCONNECT_REQ_T;

/* 
 * Indication of Shadow L2CAP disconnection. 
 * 
 * Shadowing of L2CAP channel on Primary and Secondary device is aborted when 
 * shadow ACL of the L2CAP channel is disconnected. Application shall respond 
 * to disconnect indication with disconnection response. 
 *
 * L2CAP stream associated with this CID on Secondary is destroyed after the
 * application responds to disconnection. 
 */
typedef struct
{
    sdm_prim_t          type;              /*!< Always SDM_SHADOW_L2CAP_DISCONNECT_IND */
    phandle_t           phandle;           /*!< Destination phandle */
    l2ca_cid_t          cid;               /*!< cid of L2CAP channel being shadowed */
    l2ca_disc_result_t  reason;            /*!< Reason code - uses L2CA_DISCONNECT range */ 
} SDM_SHADOW_L2CAP_DISCONNECT_IND_T;

/*
 * Response to Shadow L2CAP disconnection indication event
 */
typedef struct
{
    sdm_prim_t          type;             /*!< Always SDM_SHADOW_L2CAP_DISCONNECT_RSP */
    l2ca_cid_t          cid;              /*!< Local channel ID */
} SDM_SHADOW_L2CAP_DISCONNECT_RSP_T;

/* 
 *  Confirmation of Shadow L2CAP disconnection request.
 *
 *  HCI_SUCCESS status indicates that disconnection of shadow L2CAP is 
 *  successful.
 *
 */
typedef struct
{
    sdm_prim_t          type;              /*!< Always SDM_SHADOW_L2CAP_DISCONNECT_CFM */
    phandle_t           phandle;           /*!< Destination phandle */
    l2ca_cid_t          cid;               /*!< cid of L2CAP channel being shadowed */
    sdm_return_t        status;            /*!< Success or failure to disconnect */
} SDM_SHADOW_L2CAP_DISCONNECT_CFM_T;

typedef struct
{
    sdm_prim_t          type;           /*!< Always SDM_DEBUG_IND */
    uint16_t            size_debug;
    uint8_t             *debug;
} SDM_DEBUG_IND_T;

/*! \brief Indication of data synchronisation on a shadow L2CAP link.

   This event indicates both primary and secondary devices have synchronised
   data receive on a shadow L2CAP link. This event is generated on both
   primary and secondary devices, and indicates the time of arrival of first
   shadowed data packet on an L2CAP CID at the primary device. The event will
   also be generated after each resync between primary and secondary devices.
*/
typedef struct
{
    sdm_prim_t          type;                   /*!< Always SDM_SHADOW_L2CAP_DATA_SYNC_IND_T */
    phandle_t           phandle;                /*!< Destination phandle */
    hci_connection_handle_t connection_handle;  /*!< Connection handle of the shadow ACL */
    l2ca_cid_t          cid;                    /*!< Cid of L2CAP channel being shadowed */
    uint32_t            clock;                  /*!< Clock synchronisation time instant */
} SDM_SHADOW_L2CAP_DATA_SYNC_IND_T;


/*! \brief Union of the primitives */
typedef union
{
    /* Shared */
    sdm_prim_t                        type;

    /* Downstream */
    SDM_REGISTER_REQ_T                sdm_register_req;
    SDM_SET_BREDR_SLAVE_ADDRESS_REQ_T sdm_set_bredr_slave_address_req;
    SDM_SHADOW_LINK_CREATE_REQ_T      sdm_shadow_link_create_req;
    SDM_SHADOW_LINK_DISCONNECT_REQ_T  sdm_shadow_link_disconnect_req;
    SDM_SHADOW_L2CAP_CREATE_REQ_T     sdm_shadow_l2cap_create_req;
    SDM_SHADOW_L2CAP_CREATE_RSP_T     sdm_shadow_l2cap_create_rsp;
    SDM_SHADOW_L2CAP_DISCONNECT_REQ_T sdm_shadow_l2cap_disconnect_req;
    SDM_SHADOW_L2CAP_DISCONNECT_RSP_T sdm_shadow_l2cap_disconnect_rsp;


    /* Upstream */
    SDM_REGISTER_CFM_T                sdm_register_cfm;
    SDM_SET_BREDR_SLAVE_ADDRESS_CFM_T sdm_set_bredr_slave_address_cfm;
    SDM_SET_BREDR_SLAVE_ADDRESS_IND_T sdm_set_bredr_slave_address_ind;
    SDM_SHADOW_ACL_LINK_CREATE_CFM_T  sdm_shadow_acl_link_create_cfm;
    SDM_SHADOW_ACL_LINK_CREATE_IND_T  sdm_shadow_acl_link_create_ind;
    SDM_SHADOW_LINK_DISCONNECT_CFM_T  sdm_shadow_link_disconnect_cfm;
    SDM_SHADOW_LINK_DISCONNECT_IND_T  sdm_shadow_link_disconnect_ind;
    SDM_SHADOW_ESCO_LINK_CREATE_CFM_T sdm_shadow_esco_link_create_cfm;
    SDM_SHADOW_ESCO_LINK_CREATE_IND_T sdm_shadow_esco_link_create_ind;
    SDM_SHADOW_ESCO_RENEGOTIATED_IND_T sdm_shadow_esco_renegotiated_ind;
    SDM_SHADOW_L2CAP_CREATE_IND_T     sdm_shadow_l2cap_create_ind;
    SDM_SHADOW_L2CAP_CREATE_CFM_T     sdm_shadow_l2cap_create_cfm;
    SDM_SHADOW_L2CAP_DISCONNECT_IND_T sdm_shadow_l2cap_disconnect_ind;
    SDM_SHADOW_L2CAP_DISCONNECT_CFM_T sdm_shadow_l2cap_disconnect_cfm;

    SDM_DEBUG_IND_T                   sdm_debug_ind;

} SDM_UPRIM_T;

#ifdef __cplusplus
}
#endif

#endif /* _SDM_PRIM_H_ */
