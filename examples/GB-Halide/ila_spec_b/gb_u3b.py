import ila
from gb_arch import GBArch

def U3b (gb):
    m = gb.abst

    READY_T = gb.READY_TRUE
    READY_F = gb.READY_FALSE
    VALID_T = gb.VALID_TRUE
    VALID_F = gb.VALID_FALSE
    FULL_T  = gb.FULL_TRUE
    FULL_F  = gb.FULL_FALSE
    EMPTY_T = gb.EMPTY_TRUE
    EMPTY_F = gb.EMPTY_FALSE

    ############################ decode ###################################
    decode = (gb.slice_stream_empty == EMPTY_F) & \
             (gb.LB2D_shift_x == gb.LB2D_shift_x_M) & \
             ((gb.stencil_stream_full == FULL_F) | \
              (gb.LB2D_shift_x < gb.LB2D_shift_size))

    ############################ next state functions #####################
    # LB2D shift x idx
    LB2D_shift_x_nxt = gb.LB2D_shift_x_0
    gb.LB2D_shift_x_nxt = ila.ite (decode, LB2D_shift_x_nxt,
                                   gb.LB2D_shift_x_nxt)

