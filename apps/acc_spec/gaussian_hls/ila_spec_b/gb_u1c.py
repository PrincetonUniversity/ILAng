# ILA for Halide Gaussian blur accelerator, with both the read and write 
# instructions have child-instructions for data movement.
# child instruction 1

import ila
from gb_arch import GBArch

def U1c (gb):
    m = gb.abst

    READY_T = gb.READY_TRUE
    READY_F = gb.READY_FALSE
    FULL_T  = gb.FULL_TRUE
    FULL_F  = gb.FULL_FALSE
    EMPTY_T = gb.EMPTY_TRUE
    EMPTY_F = gb.EMPTY_FALSE

    ############################ decode ###################################
    decode = (gb.arg_1_TREADY == READY_T) & \
             (gb.in_stream_full == FULL_F) & \
             (gb.LB1D_it_1 == gb.it_T) & \
             (gb.LB1D_p_cnt == gb.LB1D_p_cnt_M)

    ############################ next state functions #####################
    # arg_1_TREADY
    arg_1_TREADY_nxt = READY_T 
    gb.arg_1_TREADY_nxt = ila.ite (decode, arg_1_TREADY_nxt, 
                                   gb.arg_1_TREADY_nxt)

    # LB1D_it_1
    LB1D_it_1_nxt = gb.it_F
    gb.LB1D_it_1_nxt = ila.ite (decode, LB1D_it_1_nxt, gb.LB1D_it_1_nxt)

    # 1-D buffer for input data
    LB1D_in_nxt = gb.LB1D_in
    gb.LB1D_in_nxt = ila.ite (decode, LB1D_in_nxt, gb.LB1D_in_nxt)

    LB1D_uIn_nxt = gb.LB1D_in
    gb.LB1D_uIn_nxt = ila.ite (decode, LB1D_uIn_nxt, gb.LB1D_uIn_nxt)

    LB1D_buff_nxt = gb.LB1D_uIn
    gb.LB1D_buff_nxt = ila.ite (decode, LB1D_buff_nxt, gb.LB1D_buff_nxt)

    # pixel position for input data
    LB1D_p_cnt_nxt = gb.LB1D_p_cnt_0
    gb.LB1D_p_cnt_nxt = ila.ite (decode, LB1D_p_cnt_nxt, gb.LB1D_p_cnt_nxt)

    # in stream full
    in_stream_full_nxt = ila.ite (gb.in_stream_empty == EMPTY_T, FULL_F, FULL_T)
    gb.in_stream_full_nxt = ila.ite (decode, in_stream_full_nxt, 
                                     gb.in_stream_full_nxt)

    # in stream empty
    in_stream_empty_nxt = EMPTY_F
    gb.in_stream_empty_nxt = ila.ite (decode, in_stream_empty_nxt, 
                                      gb.in_stream_empty_nxt)

    # in stream buffer
    in_stream_buff_0_nxt = gb.LB1D_buff
    in_stream_buff_0_nxt = gb.LB1D_uIn
    gb.in_stream_buff_nxt[0] = ila.ite (decode, in_stream_buff_0_nxt,
                                        gb.in_stream_buff_nxt[0])
    for i in xrange (1, gb.in_stream_size):
        in_stream_buff_i_nxt = gb.in_stream_buff[i-1]
        gb.in_stream_buff_nxt[i] = ila.ite (decode, in_stream_buff_i_nxt,
                                            gb.in_stream_buff_nxt[i])


    # others
    gb.arg_0_TDATA_nxt = ila.ite (decode, gb.arg_0_TDATA, gb.arg_0_TDATA_nxt)
    gb.arg_0_TVALID_nxt = ila.ite (decode, gb.arg_0_TVALID, gb.arg_0_TVALID_nxt)
    
 
