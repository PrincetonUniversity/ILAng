import ila
from gb_arch import GBArch

def U1b (gb):
    m = gb.abst

    READY_T = gb.READY_TRUE
    READY_F = gb.READY_FALSE
    FULL_T  = gb.FULL_TRUE
    FULL_F  = gb.FULL_FALSE

    ############################ decode ###################################
    decode = (gb.arg_1_TREADY == READY_F) & \
             (gb.in_stream_full == FULL_F) & \
             (gb.LB1D_it_1 == gb.it_F)

    ############################ next state functions #####################
    # arg_1_TREADY
    arg_1_TREADY_nxt = READY_T 
    gb.arg_1_TREADY_nxt = ila.ite (decode, arg_1_TREADY_nxt, 
                                   gb.arg_1_TREADY_nxt)
    # LB1D_it_1
    LB1D_it_1_nxt = gb.it_T
    gb.LB1D_it_1_nxt = ila.ite (decode, LB1D_it_1_nxt, gb.LB1D_it_1_nxt)

    # 1-D buffer for input data
    LB1D_in_nxt = gb.LB1D_in
    gb.LB1D_in_nxt = ila.ite (decode, LB1D_in_nxt, gb.LB1D_in_nxt)

    LB1D_uIn_nxt = gb.LB1D_in
    gb.LB1D_uIn_nxt = ila.ite (decode, LB1D_uIn_nxt, gb.LB1D_uIn_nxt)

    LB1D_buff_nxt = gb.LB1D_uIn
    gb.LB1D_buff_nxt = ila.ite (decode, LB1D_buff_nxt, gb.LB1D_buff_nxt)

    # pixel position for input data
    LB1D_p_cnt_nxt = gb.LB1D_p_cnt + gb.LB1D_p_cnt_1
    gb.LB1D_p_cnt_nxt = ila.ite (decode, LB1D_p_cnt_nxt, gb.LB1D_p_cnt_nxt)

