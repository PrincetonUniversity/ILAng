# ILA for Halide Gaussian Blur Accelerator.
# RTL (HLS verilog) version.

import ila

DATA_SIZE       = 8
X_EXTEND        = 9
Y_EXTEND        = 9
IMG_X_SIZE      = 488
IMG_Y_SIZE      = 688
COL_ADDR_SIZE   = 9
ROW_ADDR_SIZE   = 10

def gaussian ():
    m = ila.Abstraction ('gaussianRTL')

    BV_TRUE     = m.const (0x1, 1)
    BV_FALSE    = m.const (0x0, 1)
    READY_TRUE  = BV_TRUE
    READY_FALSE = BV_FALSE
    VALID_TRUE  = BV_TRUE
    VALID_FALSE = BV_FALSE

    ######################## input ports #####################################
    arg_1_TDATA  = m.inp ('arg_1_TDATA', DATA_SIZE)
    arg_1_TVALID = m.inp ('arg_1_TVALID', 1)
    arg_0_TREADY = m.inp ('arg_0_TREADY', 1)

    ######################## output ports ####################################
    arg_0_TDATA  = m.reg ('arg_0_TDATA', DATA_SIZE)
    arg_0_TVALID = m.reg ('arg_0_TVALID', 1)
    arg_1_TREADY = m.reg ('arg_1_TREADY', 1)

    ######################## internal architectural states ###################
    # eight 488x1 bytes buffer in 2-D line buffer
    LB2D_buff = []
    LB2D_buff_size = Y_EXTEND - 1
    for i in xrange (0, LB2D_buff_size):
        # each memory size is 488 bytes, address 9 bits, data DATA_SIZE bits
        buffName = 'buffer_%d_value_V_U' % i
        LB2D_buff.append (m.mem (buffName, COL_ADDR_SIZE, DATA_SIZE)) 

    # x-axis (column) indec in 2-D line buffer (col_reg_349)
    LB2D_x_idx = m.reg ('col_reg_349', COL_ADDR_SIZE)
    x_idx_0    = m.const (0x0, COL_ADDR_SIZE)
    x_idx_1    = m.const (0x1, COL_ADDR_SIZE)
    x_idx_M    = m.const (IMG_X_SIZE, COL_ADDR_SIZE) # ap_const_lv9_1E8
    
    # y-axis (row) index in 2-D line buffer (row_reg_327)
    LB2D_y_idx = m.reg ('row_reg_327', ROW_ADDR_SIZE)
    y_idx_0    = m.const (0x0, ROW_ADDR_SIZE)
    y_idx_1    = m.const (0x1, ROW_ADDR_SIZE)
    y_idx_M    = m.const (IMG_Y_SIZE, ROW_ADDR_SIZE) # ap_const_lv10_288

    # one 1x9 bytes slice in slice streamer
    slice_size = 1 * Y_EXTEND * DATA_SIZE
    slice_buff = m.reg ('slice_stream_V_value_V_U', slice_size)

    # eight 1x9 bytes slice in 1-D line buffer
    LB2D_shift = []
    LB2D_shift_size = X_EXTEND - 1
    for i in xrange (0, LB2D_shift_size):
        # buffer_[i]_value_V_fu_[r]: r = 100, 104, 108, 112, 116, 120, 124, 96
        buffName = 'buffer_%d_value_V_fu_' % i
        LB2D_shift.append (m.reg (buffName, slice_size))

    # one 9x9 bytes stencil in stencil streamer
    stencil_size = X_EXTEND * Y_EXTEND * DATA_SIZE
    stencil_buff = m.reg ('p_p2_in_bounded_stencil_stream_s_U', stencil_size)
    stencil_full = m.reg ('p_p2_in_bounded_stencil_stream_full', 1)
    stencil_full_FULL  = m.const (0x1, 1)
    stencil_full_EMPTY = m.const (0x0, 1)

    # uninterpreted function for gaussian blur on a stencil
    gaussianFun  = m.fun ('gaussianBlurStencil', DATA_SIZE, [stencil_size])

    ######################## fetch function ##################################
    m.fetch_valid = (arg_0_TREADY == BV_TRUE) & (arg_1_TVALID == BV_TRUE)
    m.fetch_expr  = ila.concat (arg_0_TREADY, arg_1_TVALID)

    ######################## instructions ####################################

    # XXX READ Instruction XXX
    # perform gaussian operation on the stencil, if any, and output to the port
    READ_I_decode = (arg_0_TREADY == READY_TRUE)

    # updating states: 
    READ_I_stencil_has_data = (stencil_full == stencil_full_FULL)
    READ_I_arg_0_TVALID_nxt = READ_I_stencil_has_data
    READ_I_arg_0_TDATA_nxt  = ila.ite (READ_I_stencil_has_data,
                                       ila.appfun (gaussianFun, stencil_buff),
                                       arg_0_TDATA)
    READ_I_arg_1_TREADY_nxt = READY_TRUE

    READ_I_LB2D_buff_nxt = []
    for i in xrange (0, LB2D_buff_size):
        READ_I_LB2D_buff_nxt.append (LB2D_buff[i])

    READ_I_LB2D_x_idx_nxt = LB2D_x_idx
    READ_I_LB2D_y_idx_nxt = LB2D_y_idx
    READ_I_slice_buff_nxt = slice_buff

    READ_I_LB2D_shift_nxt = []
    for i in xrange (0, LB2D_shift_size):
        READ_I_LB2D_shift_nxt.append (LB2D_shift[i])

    READ_I_stencil_buff_nxt = stencil_buff # abstracted version
    READ_I_stencil_full_nxt = stencil_full_EMPTY


    # XXX WRITE Instruction XXX
    # store the streamed-in pixel into the 2-D buffer and output slice, if so
    WRITE_I_decode = (arg_1_TVALID == VALID_TRUE)

    # updating states: 
    WRITE_I_arg_0_TVALID_nxt = VALID_FALSE # abstracted version
    WRITE_I_arg_0_TDATA_nxt  = arg_0_TDATA # abstracted version
    WRITE_I_arg_1_TREADY_nxt = READY_FALSE # ordering, only after child-instr
                                           # complete may the next come in.
                                           # FIXME check RTL implementation
    WRITE_I_LB2D_buff_nxt = []
    for i in xrange (0, LB2D_buff_size):
        buff_idx = (LB2D_y_idx % LB2D_buff_size)
        buff_i_nxt = ila.ite (buff_idx == i,
                              ila.store (LB2D_buff[i], LB2D_x_idx, arg_1_TDATA), 
                              LB2D_buff[i])
        WRITE_I_LB2D_buff_nxt.append (buff_i_nxt)

    WRITE_I_LB2D_x_idx_nxt = ila.ite (LB2D_x_idx == x_idx_M - 1, # abstracted 
                                      LB2D_x_idx + 1, x_idx_0)
    WRITE_I_LB2D_y_idx_nxt = LB2D_y_idx + 1 # abstract reset signal

    def sliceSelect (start, seqs):
        assert (len (seqs) == LB2D_buff_size)

        def sliceSelectOne (modCase):
            idx = seqs[modCase]
            if modCase == LB2D_buff_size-1:
                return ila.load (LB2D_buff[idx], LB2D_x_idx)
            else:
                return ila.ite (start == modCase,
                                ila.load (LB2D_buff[idx], LB2D_x_idx),
                                sliceSelectOne (modCase+1))
        
        return sliceSelectOne (0)


    WRITE_I_LB2D_buff_valid = (LB2D_y_idx >= LB2D_buff_size)
    WRITE_I_LB2D_buff_start = (LB2D_y_idx % LB2D_buff_size)
    WRITE_I_seqs_7 = [7, 0, 1, 2, 3, 4, 5, 6]
    WRITE_I_seqs_6 = [6, 7, 0, 1, 2, 3, 4, 5]
    WRITE_I_seqs_5 = [5, 6, 7, 0, 1, 2, 3, 4]
    WRITE_I_seqs_4 = [4, 5, 6, 7, 0, 1, 2, 3]
    WRITE_I_seqs_3 = [3, 4, 5, 6, 7, 0, 1, 2]
    WRITE_I_seqs_2 = [2, 3, 4, 5, 6, 7, 0, 1]
    WRITE_I_seqs_1 = [1, 2, 3, 4, 5, 6, 7, 0]
    WRITE_I_seqs_0 = [0, 1, 2, 3, 4, 5, 6, 7]
    WRITE_I_slice_8 = arg_1_TDATA
    WRITE_I_slice_7 = sliceSelect (WRITE_I_LB2D_buff_start, WRITE_I_seqs_7)
    WRITE_I_slice_6 = sliceSelect (WRITE_I_LB2D_buff_start, WRITE_I_seqs_6)
    WRITE_I_slice_5 = sliceSelect (WRITE_I_LB2D_buff_start, WRITE_I_seqs_5)
    WRITE_I_slice_4 = sliceSelect (WRITE_I_LB2D_buff_start, WRITE_I_seqs_4)
    WRITE_I_slice_3 = sliceSelect (WRITE_I_LB2D_buff_start, WRITE_I_seqs_3)
    WRITE_I_slice_2 = sliceSelect (WRITE_I_LB2D_buff_start, WRITE_I_seqs_2)
    WRITE_I_slice_1 = sliceSelect (WRITE_I_LB2D_buff_start, WRITE_I_seqs_1)
    WRITE_I_slice_0 = sliceSelect (WRITE_I_LB2D_buff_start, WRITE_I_seqs_0)
    WRITE_I_slice_list = [WRITE_I_slice_8,
                                         WRITE_I_slice_7,
                                         WRITE_I_slice_6,
                                         WRITE_I_slice_5,
                                         WRITE_I_slice_4,
                                         WRITE_I_slice_3,
                                         WRITE_I_slice_2,
                                         WRITE_I_slice_1,
                                         WRITE_I_slice_0]

    WRITE_I_slice_buff_nxt = ila.concat (WRITE_I_slice_list)


if __name__ == '__main__':
    gaussian ()
