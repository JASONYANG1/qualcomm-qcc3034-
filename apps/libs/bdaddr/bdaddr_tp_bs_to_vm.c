/* Copyright (c) 2011 - 2019 Qualcomm Technologies International, Ltd. */
/*  */

#include <bdaddr.h>

void BdaddrConvertTpBluestackToVm(
        tp_bdaddr            *out, 
        const TP_BD_ADDR_T   *in
        )
{
    PanicNull(out);
    PanicConstNull(in);

    switch (in->tp_type)
    {
        case BREDR_ACL:
            out->transport = TRANSPORT_BREDR_ACL;
            break;
        case LE_ACL:
            out->transport = TRANSPORT_BLE_ACL;
            break;
        default:
            out->transport = TRANSPORT_NONE;
            break;
    }
    BdaddrConvertTypedBluestackToVm(&out->taddr, &in->addrt);
}
