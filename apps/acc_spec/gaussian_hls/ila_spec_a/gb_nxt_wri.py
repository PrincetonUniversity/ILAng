import ila

from gb_arch import GBArch

# Define next state functions for architectural states
def WRI (gb):
    m = gb.abst

    READY_T     = gb.READY_TRUE
    READY_F     = gb.READY_FALSE
    VALID_T     = gb.VALID_TRUE
    VALID_F     = gb.VALID_FALSE
    DATA_SIZE   = gb.DATA_SIZE

    decode = (gb.arg_1_TVALID == VALID_T) & \
             (gb.arg_1_TREADY == READY_T) & \
             (gb.arg_0_TVALID == VALID_F) & \
             (gb.arg_0_TREADY == READY_F)

    # next state functions for output ports
    arg_1_TREADY_nxt = READY_F
    gb.arg_1_TREADY_nxt = ila.ite (decode, arg_1_TREADY_nxt, gb.arg_1_TREADY_nxt)

    arg_0_TVALID_nxt = VALID_F
    gb.arg_0_TVALID_nxt = ila.ite (decode, arg_0_TVALID_nxt, gb.arg_0_TVALID_nxt)

    arg_0_TDATA_nxt = gb.arg_0_TDATA
    gb.arg_0_TDATA_nxt = ila.ite (decode, arg_0_TDATA_nxt, gb.arg_0_TDATA_nxt)

    # next state functions for internal arch-states
    cur_pix_nxt = gb.arg_1_TDATA
    gb.cur_pix_nxt = ila.ite (decode, cur_pix_nxt, gb.cur_pix_nxt)

    # x index (column) in the 2-D RAM
    RAM_x_nxt = gb.RAM_x
    gb.RAM_x_nxt = ila.ite (decode, RAM_x_nxt, gb.RAM_x_nxt)

    # y index (row) in the 2-D RAM
    RAM_y_nxt = gb.RAM_y
    gb.RAM_y_nxt = ila.ite (decode, RAM_y_nxt, gb.RAM_y_nxt)

    # w index (write) in the 2-D RAM
    RAM_w_nxt = gb.RAM_w
    gb.RAM_w_nxt = ila.ite (decode, RAM_w_nxt, gb.RAM_w_nxt)

    # 8 488x1 bytes buffer in the 20D RAM
    for i in xrange (0, gb.RAM_size):
        RAM_i_nxt = gb.RAM[i]
        gb.RAM_nxt[i] = ila.ite (decode, RAM_i_nxt, gb.RAM_nxt[i])

    # 8 1x9 bytes slice in the stencil
    for i in xrange (0, gb.stencil_size):
        stencil_i_nxt = gb.stencil[i]
        gb.stencil_nxt[i] = ila.ite (decode, stencil_i_nxt, gb.stencil_nxt[i])

