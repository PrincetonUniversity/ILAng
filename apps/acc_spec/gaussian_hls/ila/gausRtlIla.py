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
    x_idx_M    = m.const (IMG_X_SIZE-1, COL_ADDR_SIZE) # ap_const_lv9_1E8 (abs)
    
    # y-axis (row) index in 2-D line buffer (row_reg_327)
    LB2D_y_idx = m.reg ('row_reg_327', ROW_ADDR_SIZE)
    y_idx_0    = m.const (0x0, ROW_ADDR_SIZE)
    y_idx_1    = m.const (0x1, ROW_ADDR_SIZE)
    y_idx_M    = m.const (IMG_Y_SIZE-1, ROW_ADDR_SIZE) # ap_const_lv10_288 (abs)

    # write index in 2-D line buffer (p_write_idx_1_1_reg_723)
    LB2D_w_idx = m.reg ('p_write_idx_1_1_reg_723', 64)
    w_idx_0    = m.const (0x0, 64)
    w_idx_1    = m.const (0x1, 64)
    w_idx_M    = m.const (LB2D_buff_size-1, 64) # abstracted
                                                # ap_const_lv64_FFFFFFFFFFFFFFF8

    # one 1x9 bytes slice in slice streamer
    slice_size = 1 * Y_EXTEND * DATA_SIZE
    slice_buff = m.reg ('slice_stream_V_value_V_U', slice_size)
    slice_full = m.reg ('slice_stream_V_value_V_U_internal_full_n', 1)
    slice_full_FULL  = m.const (0x1, 1)
    slice_full_EMPTY = m.const (0x0, 1)

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
    m.fetch_expr  = ila.concat ([arg_0_TREADY, arg_1_TVALID, 
                                 slice_full, stencil_full])

    ######################## instructions ####################################

    # XXX READ Instruction XXX
    # perform gaussian operation on the stencil, if any, and output to the port
    READ_I_decode = (arg_0_TREADY == READY_TRUE) & \
                    (stencil_full == stencil_full_FULL)

    # updating states: 
    READ_I_stencil_has_data = (stencil_full == stencil_full_FULL)
    READ_I_arg_0_TVALID_nxt = ila.ite (READ_I_stencil_has_data, 
                                       VALID_TRUE,
                                       VALID_FALSE)
    READ_I_arg_0_TDATA_nxt  = ila.ite (READ_I_stencil_has_data,
                                       ila.appfun (gaussianFun, stencil_buff),
                                       arg_0_TDATA)
    READ_I_arg_1_TREADY_nxt = READY_TRUE

    READ_I_LB2D_buff_nxt = []
    for i in xrange (0, LB2D_buff_size):
        READ_I_LB2D_buff_nxt.append (LB2D_buff[i])

    READ_I_LB2D_x_idx_nxt = LB2D_x_idx
    READ_I_LB2D_y_idx_nxt = LB2D_y_idx
    READ_I_LB2D_w_idx_nxt = LB2D_w_idx
    READ_I_slice_buff_nxt = slice_buff
    READ_I_slice_full_nxt = slice_full

    READ_I_LB2D_shift_nxt = []
    for i in xrange (0, LB2D_shift_size):
        READ_I_LB2D_shift_nxt.append (LB2D_shift[i])

    READ_I_stencil_buff_nxt = stencil_buff # abstracted version
    READ_I_stencil_full_nxt = stencil_full_EMPTY


    # XXX WRITE Instruction XXX
    # store the streamed-in pixel into the 2-D buffer and output slice, if so
    WRITE_I_decode = (arg_1_TVALID == VALID_TRUE) & \
                     (slice_full == slice_full_EMPTY)

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

    WRITE_I_LB2D_x_idx_nxt = ila.ite (LB2D_x_idx != x_idx_M, # abstracted 
                                      LB2D_x_idx + 1, x_idx_0)
    WRITE_I_LB2D_y_idx_nxt = ila.ite (LB2D_x_idx == x_idx_M, # abstracted
                             ila.ite (LB2D_y_idx != y_idx_M,
                                      LB2D_y_idx + 1, LB2D_y_idx),
                                      LB2D_y_idx)
    WRITE_I_LB2D_w_idx_nxt = ila.ite (LB2D_x_idx == x_idx_M, # abstracted
                             ila.ite (LB2D_w_idx != w_idx_M, 
                                      LB2D_w_idx + 1, w_idx_0),
                                      LB2D_w_idx)
                                      #LB2D_w_idx + 1, w_idx_0),
                                      #LB2D_w_idx)

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

    def WRITE_I_gen_seqs (start):
        assert (start <= LB2D_buff_size)
        res = []
        for i in xrange (0, LB2D_buff_size):
            res.append ((start + i) % LB2D_buff_size)
        return res

    WRITE_I_LB2D_buff_valid = (LB2D_y_idx >= LB2D_buff_size)
    WRITE_I_LB2D_buff_start = (LB2D_y_idx % LB2D_buff_size)
    WRITE_I_seqs = []
    for i in xrange (0, LB2D_buff_size):
        WRITE_I_seqs.append (WRITE_I_gen_seqs (i))
    """
    WRITE_I_seqs_7 = [7, 0, 1, 2, 3, 4, 5, 6]
    WRITE_I_seqs_6 = [6, 7, 0, 1, 2, 3, 4, 5]
    WRITE_I_seqs_5 = [5, 6, 7, 0, 1, 2, 3, 4]
    WRITE_I_seqs_4 = [4, 5, 6, 7, 0, 1, 2, 3]
    WRITE_I_seqs_3 = [3, 4, 5, 6, 7, 0, 1, 2]
    WRITE_I_seqs_2 = [2, 3, 4, 5, 6, 7, 0, 1]
    WRITE_I_seqs_1 = [1, 2, 3, 4, 5, 6, 7, 0]
    WRITE_I_seqs_0 = [0, 1, 2, 3, 4, 5, 6, 7]
    """
    WRITE_I_slice_chunks = [arg_1_TDATA]
    for i in xrange (7, -1, -1):
        WRITE_I_slice_chunks.append (
                sliceSelect (WRITE_I_LB2D_buff_start, WRITE_I_seqs[i]))
    WRITE_I_slice_buff_val = ila.concat (WRITE_I_slice_chunks)
    WRITE_I_slice_buff_nxt = ila.ite (WRITE_I_LB2D_buff_valid, 
                                      WRITE_I_slice_buff_val,
                                      slice_buff)

    WRITE_I_slice_full_nxt = slice_full_FULL

    WRITE_I_LB2D_shift_nxt = []
    for i in xrange (0, LB2D_shift_size):
        WRITE_I_LB2D_shift_nxt_i =  LB2D_shift [i]
        WRITE_I_LB2D_shift_nxt.append (WRITE_I_LB2D_shift_nxt_i)

    WRITE_I_stencil_buff_nxt = stencil_buff
    WRITE_I_stencil_full_nxt = stencil_full

    # XXX Write micro-instruction 1 XXX
    WRITE_U1_decode = (slice_full == slice_full_FULL) & \
                      (stencil_full == stencil_full_EMPTY)

    # updating states:
    WRITE_U1_arg_0_TVALID_nxt = VALID_FALSE # abstracted version
    WRITE_U1_arg_0_TDATA_nxt  = arg_0_TDATA # abstracted version
    WRITE_U1_arg_1_TREADY_nxt = READY_TRUE  # if slice is full and stencil is
                                            # empty, then create new stencil and
                                            # output ready signal.
    WRITE_U1_LB2D_buff_nxt = []
    for i in xrange (0, LB2D_buff_size):
        WRITE_U1_LB2D_buff_nxt.append (LB2D_buff[i])
        
    WRITE_U1_LB2D_x_idx_nxt = LB2D_x_idx
    WRITE_U1_LB2D_y_idx_nxt = LB2D_y_idx
    WRITE_U1_LB2D_w_idx_nxt = LB2D_w_idx
    WRITE_U1_slice_buff_nxt = slice_buff
    WRITE_U1_slice_full_nxt = slice_full_EMPTY # abstracted version

    WRITE_U1_LB2D_shift_nxt = []
    WRITE_U1_LB2D_shift_nxt.append (slice_buff)
    for i in xrange (1, LB2D_shift_size):
        WRITE_U1_LB2D_shift_nxt.append (LB2D_shift[i-1])

    def WRITE_U1_gen_row (idx):
        l = DATA_SIZE * idx
        h = l + DATA_SIZE - 1
        res = ila.concat ([slice_buff     [h:l],
                           LB2D_shift [0] [h:l],
                           LB2D_shift [1] [h:l],
                           LB2D_shift [2] [h:l],
                           LB2D_shift [3] [h:l],
                           LB2D_shift [4] [h:l],
                           LB2D_shift [5] [h:l],
                           LB2D_shift [6] [h:l],
                           LB2D_shift [7] [h:l]])
        return res

    WRITE_U1_stencil_rows = []
    WRITE_U1_stencil_rows.append (WRITE_U1_gen_row (LB2D_shift_size))
    for i in xrange (LB2D_shift_size-1, -1, -1):
        WRITE_U1_stencil_rows.append (WRITE_U1_gen_row (i))
    WRITE_U1_stencil_buff_nxt = ila.concat (WRITE_U1_stencil_rows)
    WRITE_U1_stencil_full_nxt = stencil_full_EMPTY

    """
    Modified decode for read instruction (arg_1_TVALID == 0) for getting 
    one-hot encoding and reuse the verilog export function.
    """
    read_i_decode  = READ_I_decode & (arg_1_TVALID == VALID_FALSE)
    write_i_decode = WRITE_I_decode
    write_u_decode = WRITE_U1_decode
    m.decode_exprs = [read_i_decode, write_i_decode, write_u_decode]

    def decodeWrap (st, ri, wi, wu):
        return ila.ite (write_i_decode, wi,
               ila.ite (write_u_decode, wu,
               ila.ite (read_i_decode, ri, st)))

    arg_0_TVALID_nxt = decodeWrap (arg_0_TVALID,
                                   READ_I_arg_0_TVALID_nxt,
                                   WRITE_I_arg_0_TVALID_nxt,
                                   WRITE_U1_arg_0_TVALID_nxt)
    m.set_next ('arg_0_TVALID', arg_0_TVALID_nxt)

    arg_0_TDATA_nxt  = decodeWrap (arg_0_TDATA,
                                   READ_I_arg_0_TDATA_nxt,
                                   WRITE_I_arg_0_TDATA_nxt,
                                   WRITE_U1_arg_0_TDATA_nxt)
    m.set_next ('arg_0_TDATA', arg_0_TDATA_nxt)

    arg_1_TREADY_nxt = decodeWrap (arg_1_TREADY,
                                   READ_I_arg_1_TREADY_nxt,
                                   WRITE_I_arg_1_TREADY_nxt,
                                   WRITE_U1_arg_1_TREADY_nxt)
    m.set_next ('arg_1_TREADY', arg_1_TREADY_nxt)

    for i in xrange (0, LB2D_buff_size):
        buffName = 'buffer_%d_value_V_U' % i
        LB2D_buff_nxt_i = (decodeWrap (LB2D_buff[i],
                                       READ_I_LB2D_buff_nxt[i],
                                       WRITE_I_LB2D_buff_nxt[i],
                                       WRITE_U1_LB2D_buff_nxt[i]))
        m.set_next (buffName, LB2D_buff_nxt_i)

    LB2D_x_idx_nxt = decodeWrap (LB2D_x_idx,
                                 READ_I_LB2D_x_idx_nxt,
                                 WRITE_I_LB2D_x_idx_nxt,
                                 WRITE_U1_LB2D_x_idx_nxt)
    m.set_next ('col_reg_349', LB2D_x_idx_nxt)

    LB2D_y_idx_nxt = decodeWrap (LB2D_y_idx,
                                 READ_I_LB2D_y_idx_nxt,
                                 WRITE_I_LB2D_y_idx_nxt,
                                 WRITE_U1_LB2D_y_idx_nxt)
    m.set_next ('row_reg_327', LB2D_y_idx_nxt)

    LB2D_w_idx_nxt = decodeWrap (LB2D_w_idx,
                                 LB2D_w_idx, #READ_I_LB2D_w_idx_nxt,
                                 WRITE_I_LB2D_w_idx_nxt,
                                 LB2D_w_idx) #WRITE_U1_LB2D_w_idx_nxt)
    m.set_next ('p_write_idx_1_1_reg_723', LB2D_w_idx_nxt)

    slice_buff_nxt = decodeWrap (slice_buff,
                                 READ_I_slice_buff_nxt,
                                 WRITE_I_slice_buff_nxt,
                                 WRITE_U1_slice_buff_nxt)
    m.set_next ('slice_stream_V_value_V_U', slice_buff_nxt)

    slice_full_nxt = decodeWrap (slice_full,
                                 READ_I_slice_full_nxt,
                                 WRITE_I_slice_full_nxt,
                                 WRITE_U1_slice_full_nxt)
    m.set_next ('slice_stream_V_value_V_U_internal_full_n', slice_full_nxt)

    LB2D_shift_nxt = []
    for i in xrange (0, LB2D_shift_size):
        buffName = 'buffer_%d_value_V_fu_' % i
        LB2D_shift_nxt_i = decodeWrap (LB2D_shift[i],
                                       READ_I_LB2D_shift_nxt[i],
                                       WRITE_I_LB2D_shift_nxt[i],
                                       WRITE_U1_LB2D_shift_nxt[i])
        m.set_next (buffName, LB2D_shift_nxt_i)

    stencil_buff_nxt = decodeWrap (stencil_buff,
                                   READ_I_stencil_buff_nxt,
                                   WRITE_I_stencil_buff_nxt,
                                   WRITE_U1_stencil_buff_nxt)
    m.set_next ('p_p2_in_bounded_stencil_stream_s_U', stencil_buff_nxt)

    stencil_full_nxt = decodeWrap (stencil_full,
                                   READ_I_stencil_full_nxt,
                                   WRITE_I_stencil_full_nxt,
                                   WRITE_U1_stencil_full_nxt)
    m.set_next ('p_p2_in_bounded_stencil_stream_full', stencil_full_nxt)

    # export ILA
    ilaFileName = 'rtl.ila'
    m.exportAll (ilaFileName)

    # export verilog 
    verilogFileName = 'rtl.v'
    m.generateVerilog (verilogFileName)


if __name__ == '__main__':
    #ila.setloglevel (3, "")
    #ila.enablelog ("ExportVerilog")
    gaussian ()
