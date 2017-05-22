import ila
from gb_arch import GBArch

def U2b (gb):
    m = gb.abst

    FULL_T  = gb.FULL_TRUE
    FULL_F  = gb.FULL_FALSE
    EMPTY_T = gb.EMPTY_TRUE
    EMPTY_F = gb.EMPTY_FALSE

    ############################ decode ###################################
    decode = (gb.in_stream_empty == EMPTY_F) & \
             (gb.LB2D_proc_x == gb.LB2D_proc_x_M) & \
             ((gb.slice_stream_full == FULL_F) | \
              (gb.LB2D_proc_y < gb.LB2D_proc_size))

    ############################ next state functions #####################
    # LB2D_proc_x
    LB2D_proc_x_nxt = gb.LB2D_proc_x_1
    gb.LB2D_proc_x_nxt = ila.ite (decode, LB2D_proc_x_nxt, gb.LB2D_proc_x_nxt)

    # LB2D_proc_y
    LB2D_proc_y_nxt = ila.ite (gb.LB2D_proc_y == gb.LB2D_proc_y_M,
                               gb.LB2D_proc_y_0,
                               gb.LB2D_proc_y + gb.LB2D_proc_y_1)
    gb.LB2D_proc_y_nxt = ila.ite (decode, LB2D_proc_y_nxt, gb.LB2D_proc_y_nxt)

    # LB2D_proc_w
    LB2D_proc_w_nxt = ila.ite (gb.LB2D_proc_w == gb.LB2D_proc_w_M,
                               gb.LB2D_proc_w_0,
                               gb.LB2D_proc_w + gb.LB2D_proc_w_1)
    gb.LB2D_proc_w_nxt = ila.ite (decode, LB2D_proc_w_nxt, gb.LB2D_proc_w_nxt)
