/* Copyright (c) 2011 - 2019 Qualcomm Technologies International, Ltd. */
/*  */

#include <bdaddr.h>

bool BdaddrTypedIsSame(const typed_bdaddr *first, const typed_bdaddr *second)
{
    PanicConstNull(first);
    PanicConstNull(second);

    return  first->type == second->type && 
            BdaddrIsSame(&first->addr, &second->addr);
}
