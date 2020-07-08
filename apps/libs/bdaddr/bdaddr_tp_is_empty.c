/* Copyright (c) 2005 - 2019 Qualcomm Technologies International, Ltd. */
/*  */

#include <bdaddr.h>

bool BdaddrTpIsEmpty(const tp_bdaddr *in)
{
    PanicConstNull(in);

    return  in->transport == TRANSPORT_NONE &&
            BdaddrTypedIsEmpty(&in->taddr);
}
