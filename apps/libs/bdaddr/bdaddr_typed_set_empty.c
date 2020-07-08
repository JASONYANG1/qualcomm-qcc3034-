/* Copyright (c) 2005 - 2019 Qualcomm Technologies International, Ltd. */
/*  */

#include <bdaddr.h>

void BdaddrTypedSetEmpty(typed_bdaddr *in)
{
    PanicNull(in);

    in->type = TYPED_BDADDR_INVALID;
    BdaddrSetZero(&in->addr);
}
