# ILA for Halide Gaussian Blur (GB) accelerator that abstracts buffering.
# write instruction - child-instruction 1

import ila

from gb_arch import GBArch

# Define next state functions for child-instruction 1
def WRU1 (gb):
    m = gb.abst

    READY_T = gb.READY_TRUE
    READY_F = gb.READY_FALSE
    VALID_T = gb.VALID_TRUE
    VALID_F = gb.VALID_FALSE
    DATA_SIZE = gb.DATA_SIZE

    # TODO
    # decode
    decode = (gb.arg_1_TREADY == READY_T)

    # nxt
    arg_1_TREADY_nxt = gb.arg_1_TREADY
    gb.arg_1_TREADY_nxt = ila.ite (decode, arg_1_TREADY_nxt, gb.arg_1_TREADY_nxt)
