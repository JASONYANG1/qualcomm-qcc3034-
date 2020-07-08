
/****************************************************************************
Copyright (c) 2020 Qualcomm Technologies International, Ltd.

FILE NAME
    sink_private_data_config_def.h

DESCRIPTION 
    This file contains the module specific configuration structure(s) and
    configuration block id(s) to be used with the config_store library.

*/

/*********************************/
/* GENERATED FILE - DO NOT EDIT! */
/*********************************/

#ifndef _SINK_PRIVATE_DATA_CONFIG_DEF_H_
#define _SINK_PRIVATE_DATA_CONFIG_DEF_H_

#include "config_definition.h"

typedef struct {
    unsigned short AutoSwitchOffTime_s;
    unsigned short DisablePowerOffAfterPOnTime_s;
    unsigned short PairModeTimeout_s;
    unsigned short ConnectableTimeout_s;
    unsigned short PairModeTimeoutIfPDL_s;
    unsigned short PairingModeReminderInterval_s;
    unsigned short EncryptionRefreshTimeout_m;
    unsigned short SecondAGConnectDelayTime_s;
    unsigned short DefragCheckTimer_s;
    unsigned short AudioAmpPDownTimeInLimbo_s;
    unsigned short LimboTimeout_s;
} sinkdata_timer_t;

typedef struct {
    unsigned short key_minimum:8;
    unsigned short key_size:8;
} defrag_config_t;

typedef struct {
    unsigned short max_remote_ssr_latency;
    unsigned short min_remote_ssr_timeout;
    unsigned short min_local_ssr_timeout;
} ssr_params_t;

typedef struct {
    ssr_params_t sco_params;
    ssr_params_t slc_params;
} subrate_t;

#define SINKDATA_READONLY_CONFIG_BLK_ID 132

typedef struct {
    sinkdata_timer_t private_data_timers;
    defrag_config_t defrag;
    subrate_t ssr_data;
    unsigned short ReconnectionAttempts;
    unsigned short pdl_size;
    unsigned short ReconnectOnPanic:1;
    unsigned short ReconnectLastAttempts:3;
    unsigned short DiscoIfPDLLessThan:4;
    unsigned short partitions_free:8;
    unsigned short EnterPairingModeOnFailureToConn:1;
    unsigned short AutoReconnectPowerOn:1;
    unsigned short pair_mode_en:1;
    unsigned short AllowAutomaticPowerOffWhenCharging:1;
    unsigned short PowerOffOnlyIfVRegEnLow:1;
    unsigned short DisablePowerOffAfterPowerOn:1;
    unsigned short RemainDiscoverableAtAllTimes:1;
    unsigned short PowerOffAfterPDLReset:1;
    unsigned short ActionOnPanicReset:2;
    unsigned short PairIfPDLLessThan:2;
    unsigned short ActionOnPowerOn:2;
    unsigned short PowerDownOnDiscoTimeout:2;
    unsigned short padding:6;
    unsigned short EncryptOnSLCEstablishment:1;
    unsigned short DisableCompletePowerOff:1;
    unsigned short GoConnectableDuringLinkLoss:1;
    unsigned short DisableRoleSwitching:1;
    unsigned short AutoPowerOnAfterInitialisation:1;
    unsigned short ResetAfterPowerOffComplete:1;
    unsigned short SecurePairing:1;
    unsigned short UseDiffConnectedEventAtPowerOn:1;
    unsigned short ManInTheMiddle:1;
    unsigned short DoNotDiscoDuringLinkLoss:1;
} sinkdata_readonly_config_def_t;

#define SINKDATA_WRITEABLE_CONFIG_BLK_ID 159

typedef struct {
    unsigned short padding:15;
    unsigned short multipoint_enable:1;
} sinkdata_writeable_config_def_t;

#endif /* _SINK_PRIVATE_DATA_CONFIG_DEF_H_ */
