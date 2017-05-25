import ila
from gb_arch import GBArch

def U3 (gb):
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
             (gb.LB2D_shift_x != gb.LB2D_shift_x_M) & \
             ((gb.stencil_stream_full == FULL_F) | \
              ((gb.LB2D_shift_x < gb.LB2D_shift_size) & \
               (gb.LB2D_shift_x > gb.LB2D_shift_x_0))) \

    ############################ next state functions #####################
    # arg_1_TREADY
    arg_1_TREADY_nxt = gb.arg_1_TREADY
    gb.arg_1_TREADY_nxt = ila.ite (decode, arg_1_TREADY_nxt, gb.arg_1_TREADY_nxt)

    # arg_0_TVALID
    arg_0_TVALID_nxt = gb.arg_0_TVALID
    gb.arg_0_TVALID_nxt = ila.ite (decode, arg_0_TVALID_nxt, gb.arg_0_TVALID_nxt)

    # arg_0_TDATA
    arg_0_TDATA_nxt = gb.arg_0_TDATA
    gb.arg_0_TDATA_nxt = ila.ite (decode, arg_0_TDATA_nxt, gb.arg_0_TDATA_nxt)

    # 1-D buffer for input data
    LB1D_in_nxt = gb.LB1D_in
    gb.LB1D_in_nxt = ila.ite (decode, LB1D_in_nxt, gb.LB1D_in_nxt)

    LB1D_uIn_nxt = gb.LB1D_uIn
    gb.LB1D_uIn_nxt = ila.ite (decode, LB1D_uIn_nxt, gb.LB1D_uIn_nxt)

    LB1D_buff_nxt = gb.LB1D_buff
    gb.LB1D_buff_nxt = ila.ite (decode, LB1D_buff_nxt, gb.LB1D_buff_nxt)

    # pixel position for input data
    LB1D_p_cnt_nxt = gb.LB1D_p_cnt
    gb.LB1D_p_cnt_nxt = ila.ite (decode, LB1D_p_cnt_nxt, gb.LB1D_p_cnt_nxt)

    # in stream full 
    in_stream_full_nxt = gb.in_stream_full
    gb.in_stream_full_nxt = ila.ite (decode, in_stream_full_nxt, 
                                     gb.in_stream_full_nxt)

    # in stream empty
    in_stream_empty_nxt = gb.in_stream_empty
    gb.in_stream_empty_nxt = ila.ite (decode, in_stream_empty_nxt, 
                                      gb.in_stream_empty_nxt)

    # in stream buffer
    for i in xrange (0, gb.in_stream_size):
        in_stream_buff_nxt = gb.in_stream_buff[i]
        gb.in_stream_buff_nxt[i] = ila.ite (decode, in_stream_buff_nxt,
                                            gb.in_stream_buff_nxt[i])

    # LB2D proc x idx
    LB2D_proc_x_nxt = gb.LB2D_proc_x
    gb.LB2D_proc_x_nxt = ila.ite (decode, LB2D_proc_x_nxt,
                                  gb.LB2D_proc_x_nxt)

    # LB2D proc y idx
    LB2D_proc_y_nxt = gb.LB2D_proc_y
    gb.LB2D_proc_y_nxt = ila.ite (decode, LB2D_proc_y_nxt,
                                  gb.LB2D_proc_y_nxt)

    # LB2D proc w idx
    LB2D_proc_w_nxt = gb.LB2D_proc_w
    gb.LB2D_proc_w_nxt = ila.ite (decode, LB2D_proc_w_nxt,
                                  gb.LB2D_proc_w_nxt)

    # LB2D proc buffer
    for i in xrange (0, gb.LB2D_proc_size):
        LB2D_proc_nxt = gb.LB2D_proc[i]
        gb.LB2D_proc_nxt[i] = ila.ite (decode, LB2D_proc_nxt,
                                       gb.LB2D_proc_nxt[i])

    # slice stream full
    slice_stream_full_nxt = FULL_F
    gb.slice_stream_full_nxt = ila.ite (decode, slice_stream_full_nxt,
                                        gb.slice_stream_full_nxt)

    # slice stream empty
    slice_stream_empty_nxt = ila.ite (gb.slice_stream_full == FULL_T,
                                      EMPTY_F, EMPTY_T)
    gb.slice_stream_empty_nxt = ila.ite (decode, slice_stream_empty_nxt,
                                         gb.slice_stream_empty_nxt)

    # slice stream buffer
    for i in xrange (0, gb.slice_stream_size):
        slice_stream_buff_nxt = gb.slice_stream_buff[i]
        gb.slice_stream_buff_nxt[i] = ila.ite (decode, slice_stream_buff_nxt,
                                               gb.slice_stream_buff_nxt[i])

    # LB2D shift x idx
    LB2D_shift_x_nxt = gb.LB2D_shift_x + gb.LB2D_shift_x_1
    gb.LB2D_shift_x_nxt = ila.ite (decode, LB2D_shift_x_nxt,
                                   gb.LB2D_shift_x_nxt)

    # LB2D shift y idx
    LB2D_shift_y_nxt = ila.ite (gb.LB2D_shift_y < gb.LB2D_shift_y_M,
                                ila.ite (gb.LB2D_shift_x < gb.LB2D_shift_x_M,
                                         gb.LB2D_shift_y,
                                         gb.LB2D_shift_y + gb.LB2D_shift_y_1),
                                gb.LB2D_shift_y_M)
    gb.LB2D_shift_y_nxt = ila.ite (decode, LB2D_shift_y_nxt,
                                   gb.LB2D_shift_y_nxt)

    # LB2D shift buffer
    in_slice = ila.ite (gb.slice_stream_full == FULL_T,
                        gb.slice_stream_buff[gb.slice_stream_size-1],
                        gb.slice_stream_buff[0])

    LB2D_shift_7_nxt = in_slice
    gb.LB2D_shift_nxt[gb.LB2D_shift_size-1] = ila.ite (decode, 
                                                       LB2D_shift_7_nxt,
                                                       gb.LB2D_shift_nxt[gb.LB2D_shift_size-1])
    for i in xrange (0, gb.LB2D_shift_size-1):
        LB2D_shift_i_nxt = gb.LB2D_shift[i+1]
        gb.LB2D_shift_nxt[i] = ila.ite (decode, LB2D_shift_i_nxt,
                                        gb.LB2D_shift_nxt[i])

    passToStencil = (gb.LB2D_shift_x >= gb.LB2D_shift_size) | \
                    (gb.LB2D_shift_x == gb.LB2D_shift_x_0)
    # stencil_stream_full
    stencil_stream_full_nxt = ila.ite (~passToStencil,
                                       gb.stencil_stream_full,
                              ila.ite (gb.stencil_stream_empty == EMPTY_T,
                                       FULL_F,
                                       FULL_T))
    gb.stencil_stream_full_nxt = ila.ite (decode, stencil_stream_full_nxt,
                                          gb.stencil_stream_full_nxt)

    # stencil_stream_empty
    stencil_stream_empty_nxt = ila.ite (~passToStencil,
                                        gb.stencil_stream_empty,
                                        EMPTY_F) 
    gb.stencil_stream_empty_nxt = ila.ite (decode, stencil_stream_empty_nxt,
                                           gb.stencil_stream_empty_nxt)

    # stencil_stream_buff
    def genRows (idx):
        l = gb.DATA_SIZE * idx
        h = l + gb.DATA_SIZE - 1
        res = ila.concat ([in_slice          [h:l],
                           gb.LB2D_shift [7] [h:l],
                           gb.LB2D_shift [6] [h:l],
                           gb.LB2D_shift [5] [h:l],
                           gb.LB2D_shift [4] [h:l],
                           gb.LB2D_shift [3] [h:l],
                           gb.LB2D_shift [2] [h:l],
                           gb.LB2D_shift [1] [h:l],
                           gb.LB2D_shift [0] [h:l]])
        return res

    stencil_rows = []
    stencil_rows.append (genRows (gb.LB2D_shift_size))
    for i in xrange (gb.LB2D_shift_size-1, -1, -1):
        stencil_rows.append (genRows (i))

    stencil_stream_buff_0_nxt = ila.ite (passToStencil,
                                         ila.concat (stencil_rows),
                                         gb.stencil_stream_buff[0])
    gb.stencil_stream_buff_nxt[0] = ila.ite (decode, stencil_stream_buff_0_nxt,
                                             gb.stencil_stream_buff_nxt[0])
    for i in xrange (1, gb.stencil_stream_size):
        stencil_stream_buff_i_nxt = gb.stencil_stream_buff[i-1]
        gb.stencil_stream_buff_nxt[i] = ila.ite (decode & passToStencil, 
                                                 stencil_stream_buff_i_nxt,
                                                 gb.stencil_stream_buff_nxt[i])

    # gb_p_cnt
    gb_p_cnt_nxt = gb.gb_p_cnt
    gb.gb_p_cnt_nxt = ila.ite (decode, gb_p_cnt_nxt, gb.gb_p_cnt_nxt)

    # gb_pp_it
    for i in xrange (0, gb.gb_pp_size):
        gb_pp_it_i_nxt = gb.gb_pp_it[i]
        gb.gb_pp_it_nxt[i] = ila.ite (decode, gb_pp_it_i_nxt,
                                      gb.gb_pp_it_nxt[i])

    # gb_exit_it
    for i in xrange (0, gb.gb_exit_size):
        gb_exit_it_i_nxt = gb.gb_exit_it[i]
        gb.gb_exit_it_nxt[i] = ila.ite (decode, gb_exit_it_i_nxt,
                                        gb.gb_exit_it_nxt[i])

