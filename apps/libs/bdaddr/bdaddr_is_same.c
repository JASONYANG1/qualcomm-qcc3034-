/* Copyright (c) 2005 - 2019 Qualcomm Technologies International, Ltd. */
/*  */

#include <bdaddr.h>

bool BdaddrIsSame(const bdaddr *first, const bdaddr *second)
{ 
    PanicConstNull(first);
    PanicConstNull(second);

    return  first->nap == second->nap && 
            first->uap == second->uap && 
            first->lap == second->lap; 
}
