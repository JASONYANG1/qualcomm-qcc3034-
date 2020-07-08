/* Copyright (c) 2005 - 2019 Qualcomm Technologies International, Ltd. */
/*  */

#include <bdaddr.h>

void BdaddrTpSetEmpty(tp_bdaddr *in)
{
    PanicNull(in);

    in->transport = TRANSPORT_NONE;
    BdaddrTypedSetEmpty(&in->taddr);
}

