# ILA for Halide Gaussian Blur Accelerator.
# RTL (HLS verilog) version.

import ila

def gaussian ():
    m = ila.Abstraction ('gaussian')

    ######################## input ports #####################################
    arg_0_TREADY = m.inp ('arg_0_TREADY', 1)
    arg_1_TDATA  = m.inp ('arg_1_TDATA', 8)
    arg_1_TVALID = m.inp ('arg_1_TVALID', 1)

    ######################## output ports ####################################
    arg_0_TVALID = m.reg ('arg_0_TVALID', 1)
    arg_0_TDATA  = m.reg ('arg_0_TDATA', 8)
    arg_1_TREADY = m.reg ('arg_1_TREADY', 1)

    ######################## internal architectural states ###################
    # eight 488x1 bytes buffer in 2-D line buffer
    LB2D_buf = []
    for i in xrange(0, 8):
        # each memory size is 488 bytes, address 9 bits, data 8 bits
        buffName = 'buffer_%d_value_V_U' % i
        LB2D_buf.append (m.mem (buffName, 9, 8)) 

    # x-axis (column) indec in 2-D line buffer (col_reg_349)
    LB2D_x_idx = m.reg ('col_reg_349', 9)
    bv9_0      = m.const (0x0, 9)
    bv9_1      = m.const (0x1, 9)
    bv9_488    = m.const (0x1E8, 9) # ap_const_lv9_1E8
    
    # y-axis (row) index in 2-D line buffer (row_reg_327)
    LB2D_y_idx = m.reg ('row_reg_327', 10)
    bv10_0     = m.const (0, 10)
    bv10_1     = m.const (1, 10)
    bv10_688   = m.const (0x288, 10) # ap_const_lv10_288

    # one 1x9 bytes slice in 1-D line buffer
    


if __name__ == '__main__':
    gaussian ()
