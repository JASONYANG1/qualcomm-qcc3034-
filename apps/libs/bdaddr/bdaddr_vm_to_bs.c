/* Copyright (c) 2011 - 2019 Qualcomm Technologies International, Ltd. */
/*  */

#include <bdaddr.h>

void BdaddrConvertVmToBluestack(BD_ADDR_T *out, const bdaddr *in)
{
    PanicNull(out);
    PanicConstNull(in);

    out->lap = (uint24_t)(in->lap);
    out->uap = (uint8_t)(in->uap);
    out->nap = (uint16_t)(in->nap);
}
