/* Copyright (c) 2005 - 2019 Qualcomm Technologies International, Ltd. */
/*  */

#include <bdaddr.h>

bool BdaddrIsZero(const bdaddr *in)
{ 
    PanicConstNull(in);

    return !in->nap && !in->uap && !in->lap; 
}
