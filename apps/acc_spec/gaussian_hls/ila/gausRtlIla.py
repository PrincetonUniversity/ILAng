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
    m = ila.Abstraction ('gaussian')

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
    for i in xrange (0, 8):
        # each memory size is 488 bytes, address 9 bits, data DATA_SIZE bits
        buffName = 'buffer_%d_value_V_U' % i
        LB2D_buff.append (m.mem (buffName, COL_ADDR_SIZE, DATA_SIZE)) 

    # x-axis (column) indec in 2-D line buffer (col_reg_349)
    LB2D_x_idx = m.reg ('col_reg_349', COL_ADDR_SIZE)
    bv9_0      = m.const (0x0, COL_ADDR_SIZE)
    bv9_1      = m.const (0x1, COL_ADDR_SIZE)
    bv9_488    = m.const (IMG_X_SIZE, COL_ADDR_SIZE) # ap_const_lv9_1E8
    
    # y-axis (row) index in 2-D line buffer (row_reg_327)
    LB2D_y_idx = m.reg ('row_reg_327', ROW_ADDR_SIZE)
    bv10_0     = m.const (0x0, ROW_ADDR_SIZE)
    bv10_1     = m.const (0x1, ROW_ADDR_SIZE)
    bv10_688   = m.const (IMG_Y_SIZE, ROW_ADDR_SIZE) # ap_const_lv10_288

    # one 1x9 bytes slice in slice streamer
    slice_size = 1 * Y_EXTEND * DATA_SIZE
    slice_buff = m.reg ('slice_stream_V_value_V_U', slice_size)

    # eight 1x9 bytes slice in 1-D line buffer
    LB2D_shift = []
    for i in xrange (0, 8):
        # buffer_[i]_value_V_fu_[r]: r = 100, 104, 108, 112, 116, 120, 124, 96
        buffName = 'buffer_%d_value_V_fu_' % i
        LB2D_shift.append (m.reg (buffName, slice_size))

    # one 9x9 bytes stencil in stencil streamer
    stencil_size = X_EXTEND * Y_EXTEND * DATA_SIZE
    stencil_buff = m.reg ('p_p2_in_bounded_stencil_stream_s_U', stencil_size)

    ######################## fetch function ##################################
    m.fetch_valid = (arg_0_TREADY == True) & (arg_1_TVALID == True)
    m.fetch_expr  = ila.concat (arg_0_TREADY, arg_1_TVALID)

    ######################## instructions ####################################

    #### READ Instruction 
    READ_INSTR_decode = (arg_0_TREADY == True)

    # updating states: arg_0_TVALID, arg_0_TDATA, arg_1_TREADY


if __name__ == '__main__':
    gaussian ()
