/****************************************************************************
 * Copyright (c) 2019 Qualcomm Technologies International, Ltd.
 ****************************************************************************/
/**
 * \file cbops_iir_resamplerv2_op_extra.c
 * \ingroup cbops
 *
 * This file contains extra functions for cbops iir resample v2
 */

/* Only for downloadable builds */
#ifdef CAPABILITY_DOWNLOAD_BUILD

/****************************************************************************
Include Files
*/
#include "pmalloc/pl_malloc.h"
#include "cbops_c.h"
#include "pl_assert.h"

/* define a function pointer to original create_iir_resamplerv2_op function */
typedef cbops_op * (*create_iir_resamplerv2_op_ptr)(
    unsigned nr_channels,
    unsigned* input_idx,
    unsigned* output_idx,
    unsigned in_rate,
    unsigned out_rate,
    unsigned inter_stage_size,
    unsigned *inter_stage,
    int shift,
    unsigned dbl_precision,
    unsigned low_mips);
#define create_iir_resamplerv2_op_rom ((create_iir_resamplerv2_op_ptr) 0x16fb3)

/*
 * Rewrite create_iir_resamplerv2_op function,
 * it will call the original rom function and then
 * will increase the headroom by 1 bit.
 */
cbops_op* create_iir_resamplerv2_op(
    unsigned nr_channels,
    unsigned* input_idx,
    unsigned* output_idx,
    unsigned in_rate,
    unsigned out_rate,
    unsigned inter_stage_size,
    unsigned *inter_stage,
    int shift,
    unsigned dbl_precision,
    unsigned low_mips)
{
    /* call original function */
    cbops_op *op_ptr = create_iir_resamplerv2_op_rom(
        nr_channels,
        input_idx,
        output_idx,
        in_rate,
        out_rate,
        inter_stage_size,
        inter_stage,
        shift,
        dbl_precision,
        low_mips);

    if(op_ptr != NULL)
    {
        /* increase the headroom by 1 bit (6dB) */
        cbops_param_hdr *params_hdr = (cbops_param_hdr*)CBOPS_OPERATOR_DATA_PTR(op_ptr);

        cbops_iir_resampler_op *params =
            (cbops_iir_resampler_op *) params_hdr->operator_data_ptr;

        /* Currently we expect IIR_RESAMPLEV2_IO_SCALE_FACTOR
         * to be 9 for best performance, in ROM it is 8, so this
         * will increase the headroom by 1 bit or 6dB.
         */
        COMPILE_TIME_ASSERT(IIR_RESAMPLEV2_IO_SCALE_FACTOR == 9,
                        IIR_RESAMPLEV2_IO_SCALE_FACTOR_Not_Accepted);

        if(shift >= 0)
        {
            params->common.input_scale =  shift - IIR_RESAMPLEV2_IO_SCALE_FACTOR;
            params->common.output_scale =  IIR_RESAMPLEV2_IO_SCALE_FACTOR;
        }
        else
        {
            params->common.input_scale = -IIR_RESAMPLEV2_IO_SCALE_FACTOR;
            params->common.output_scale =  IIR_RESAMPLEV2_IO_SCALE_FACTOR - shift;
        }
    }

    return op_ptr;
}
#endif
