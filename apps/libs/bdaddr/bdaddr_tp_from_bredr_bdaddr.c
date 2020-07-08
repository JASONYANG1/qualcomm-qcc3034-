/* Copyright (c) 2019 Qualcomm Technologies International, Ltd. */

#include <bdaddr.h>

void BdaddrTpFromBredrBdaddr(tp_bdaddr* out, const bdaddr* in)
{
    PanicNull(out);
    PanicConstNull(in);

    out->transport = TRANSPORT_BREDR_ACL;
    out->taddr.type = TYPED_BDADDR_PUBLIC;
    out->taddr.addr = *in;
}
