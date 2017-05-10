import ila
from gb_arch import GBArch

def U2 (gb):
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
    decode = (gb.in_stream_empty == EMPTY_F) & \
             ((gb.slice_stream_full == FULL_F) | \
              (gb.LB2D_proc_y < gb.LB2D_proc_size))

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
    in_stream_full_nxt = FULL_F
    gb.in_stream_full_nxt = ila.ite (decode, in_stream_full_nxt,
                                     gb.in_stream_full_nxt)

    # in stream empty
    in_stream_empty_nxt = ila.ite (gb.in_stream_full == FULL_T, EMPTY_F, EMPTY_T)
    gb.in_stream_empty_nxt = ila.ite (decode, in_stream_empty_nxt,
                                      gb.in_stream_empty_nxt)

    # in stream buffer
    for i in xrange (0, gb.in_stream_size):
        in_stream_buff_nxt = gb.in_stream_buff[i]
        gb.in_stream_buff_nxt[i] = ila.ite (decode, in_stream_buff_nxt,
                                            gb.in_stream_buff_nxt[i])

    # LB2D proc x idx
    LB2D_proc_x_nxt = ila.ite (gb.LB2D_proc_x == gb.LB2D_proc_x_M,
                               gb.LB2D_proc_x_1,
                               gb.LB2D_proc_x + gb.LB2D_proc_x_1)
    gb.LB2D_proc_x_nxt = ila.ite (decode, LB2D_proc_x_nxt, gb.LB2D_proc_x_nxt)

    # LB2D proc y idx
    LB2D_proc_y_nxt = ila.ite (gb.LB2D_proc_x == gb.LB2D_proc_x_M,
                      ila.ite (gb.LB2D_proc_y == gb.LB2D_proc_y_M,
                               gb.LB2D_proc_y_0,
                               gb.LB2D_proc_y + gb.LB2D_proc_y_1),
                               gb.LB2D_proc_y)
    gb.LB2D_proc_y_nxt = ila.ite (decode, LB2D_proc_y_nxt, gb.LB2D_proc_y_nxt)
                               
    # LB2D proc w idx
    LB2D_proc_w_nxt = ila.ite (gb.LB2D_proc_x == gb.LB2D_proc_x_M,
                      ila.ite (gb.LB2D_proc_w == gb.LB2D_proc_w_M,
                               gb.LB2D_proc_w_0,
                               gb.LB2D_proc_w + gb.LB2D_proc_w_1),
                               gb.LB2D_proc_w)
    gb.LB2D_proc_w_nxt = ila.ite (decode, LB2D_proc_w_nxt, gb.LB2D_proc_w_nxt)

    # LB2D proc buffer
    in_byte = ila.ite (gb.in_stream_full == FULL_T, 
                       gb.in_stream_buff[gb.in_stream_size-1],
                       gb.in_stream_buff[0])
    for i in xrange (0, gb.LB2D_proc_size):
        LB2D_proc_nxt = ila.ite (gb.LB2D_proc_w == i,
                                 ila.store (gb.LB2D_proc[i], 
                                            gb.LB2D_proc_x - gb.LB2D_proc_x_1, 
                                            in_byte),
                                 gb.LB2D_proc[i])
        gb.LB2D_proc_nxt[i] = ila.ite (decode, LB2D_proc_nxt, gb.LB2D_proc_nxt[i])

    # slice stream full
    slice_stream_full_nxt = ila.ite (gb.LB2D_proc_y < gb.LB2D_proc_size,
                                     FULL_F, 
                            ila.ite (gb.slice_stream_empty == EMPTY_T,
                                     FULL_F, 
                                     FULL_T))
    gb.slice_stream_full_nxt = ila.ite (decode, slice_stream_full_nxt,
                                        gb.slice_stream_full_nxt)

    # slice stream empty
    slice_stream_empty_nxt = ila.ite (gb.LB2D_proc_y < gb.LB2D_proc_size,
                                      EMPTY_T, EMPTY_F) 
    gb.slice_stream_empty_nxt = ila.ite (decode, slice_stream_empty_nxt,
                                         gb.slice_stream_empty_nxt)

    # slice stream buffer
    def sliceSelect (start, seqs):
        assert (len (seqs) == gb.LB2D_proc_size)

        def sliceSelectOne (modCase):
            idx = seqs[modCase]
            if modCase == gb.LB2D_proc_size - 1:
                return ila.load (gb.LB2D_proc[idx], gb.LB2D_proc_x - gb.LB2D_proc_x_1) 
            else:
                return ila.ite (start == modCase, 
                                ila.load (gb.LB2D_proc[idx], gb.LB2D_proc_x - gb.LB2D_proc_x_1), 
                                sliceSelectOne (modCase + 1))
        return sliceSelectOne (0)

    def genSliceSeqs (start):
        assert (start <= gb.LB2D_proc_size)
        res = []
        for i in xrange (0, gb.LB2D_proc_size):
            res.append ((start + i) % gb.LB2D_proc_size)
        return res

    slice_seqs = []
    for i in xrange (0, gb.LB2D_proc_size):
        slice_seqs.append (genSliceSeqs (i))

    """
    slice_seq_7 = [7, 0, 1, 2, 3, 4, 5, 6]
    slice_seq_6 = [6, 7, 0, 1, 2, 3, 4, 5]
    slice_seq_5 = [5, 6, 7, 0, 1, 2, 3, 4]
    slice_seq_4 = [4, 5, 6, 7, 0, 1, 2, 3]
    slice_seq_3 = [3, 4, 5, 6, 7, 0, 1, 2]
    slice_seq_2 = [2, 3, 4, 5, 6, 7, 0, 1]
    slice_seq_1 = [1, 2, 3, 4, 5, 6, 7, 0]
    slice_seq_0 = [0, 1, 2, 3, 4, 5, 6, 7]
    """

    slice_chunks = [in_byte]
    for i in xrange (7, -1, -1):
        slice_chunks.append (
                sliceSelect (gb.LB2D_proc_w, slice_seqs[i]))
    # slice_stream_buff
    slice_stream_buff_0_nxt = ila.ite (gb.LB2D_proc_y < gb.LB2D_proc_size,
                                       gb.slice_stream_buff[0],
                                       ila.concat (slice_chunks))
    gb.slice_stream_buff_nxt[0] = ila.ite (decode, slice_stream_buff_0_nxt,
                                           gb.slice_stream_buff_nxt[0])
    for i in xrange (1, gb.slice_stream_size):
        slice_stream_buff_i_nxt = ila.ite (gb.LB2D_proc_y < gb.LB2D_proc_size,
                                           gb.slice_stream_buff[i],
                                           gb.slice_stream_buff[i-1])
        gb.slice_stream_buff_nxt[i] = ila.ite (decode, slice_stream_buff_i_nxt,
                                               gb.slice_stream_buff_nxt[i])

    # LB2D shift x idx
    LB2D_shift_x_nxt = gb.LB2D_shift_x
    gb.LB2D_shift_x_nxt = ila.ite (decode, LB2D_shift_x_nxt,
                                   gb.LB2D_shift_x_nxt)

    # LB2D shift y idx
    LB2D_shift_y_nxt = gb.LB2D_shift_y
    gb.LB2D_shift_y_nxt = ila.ite (decode, LB2D_shift_y_nxt,
                                   gb.LB2D_shift_y_nxt)

    # LB2D shift buffer
    for i in xrange (0, gb.LB2D_shift_size):
        LB2D_shift_nxt = gb.LB2D_shift[i]
        gb.LB2D_shift_nxt[i] = ila.ite (decode, LB2D_shift_nxt,
                                        gb.LB2D_shift_nxt[i])

    # stencil_stream_full
    stencil_stream_full_nxt = gb.stencil_stream_full
    gb.stencil_stream_full_nxt = ila.ite (decode, stencil_stream_full_nxt,
                                          gb.stencil_stream_full_nxt)

    # stencil_stream_empty
    stencil_stream_empty_nxt = gb.stencil_stream_empty
    gb.stencil_stream_empty_nxt = ila.ite (decode, stencil_stream_empty_nxt,
                                           gb.stencil_stream_empty_nxt)

    # stencil_stream_buff
    for i in xrange (0, gb.stencil_stream_size):
        stencil_stream_buff_nxt = gb.stencil_stream_buff[i]
        gb.stencil_stream_buff_nxt[i] = ila.ite (decode, stencil_stream_buff_nxt,
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

