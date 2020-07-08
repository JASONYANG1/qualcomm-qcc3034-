/* Copyright (c) 2011 - 2019 Qualcomm Technologies International, Ltd. */
/*  */

#include <bdaddr.h>

bool BdaddrTpIsSame(const tp_bdaddr *first, const tp_bdaddr *second)
{
    PanicConstNull(first);
    PanicConstNull(second);

    return  first->transport == second->transport && 
            BdaddrTypedIsSame(&first->taddr, &second->taddr);
}
