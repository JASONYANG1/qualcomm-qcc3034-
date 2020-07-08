/* Copyright (c) 2005 - 2019 Qualcomm Technologies International, Ltd. */
/*  */

#include <bdaddr.h>

bool BdaddrTypedIsEmpty(const typed_bdaddr *in)
{
    PanicConstNull(in);

    return  in->type == TYPED_BDADDR_INVALID &&
            BdaddrIsZero(&in->addr);
}
