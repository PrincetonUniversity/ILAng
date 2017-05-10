import ila

from gb_arch import GBArch

# Define next state functions for architectural states
def WRU0b (gb):
    m = gb.abst

    READY_T     = gb.READY_TRUE
    READY_F     = gb.READY_FALSE
    VALID_T     = gb.VALID_TRUE
    VALID_F     = gb.VALID_FALSE
    DATA_SIZE   = gb.DATA_SIZE

    decode = (gb.arg_1_TREADY == READY_F) & \
             (gb.arg_0_TREADY == READY_F) & \
             (gb.st_ready == READY_T) \

    decode = decode & (gb.RAM_x == gb.RAM_x_0) & (gb.RAM_y == gb.RAM_y_0)

    # next state functions for output ports
    arg_1_TREADY_nxt = READY_T
    gb.arg_1_TREADY_nxt = ila.ite (decode, arg_1_TREADY_nxt, gb.arg_1_TREADY_nxt)

    arg_0_TVALID_nxt = VALID_F
    gb.arg_0_TVALID_nxt = ila.ite (decode, arg_0_TVALID_nxt, gb.arg_0_TVALID_nxt)

    arg_0_TDATA_nxt = gb.arg_0_TDATA
    gb.arg_0_TDATA_nxt = ila.ite (decode, arg_0_TDATA_nxt, gb.arg_0_TDATA_nxt)

    # next state functions for internal arch-states
    # most recent pixel
    cur_pix_nxt = gb.cur_pix
    gb.cur_pix_nxt = ila.ite (decode, cur_pix_nxt, gb.cur_pix_nxt)

    # previous pixel (child-state)
    pre_pix_nxt = gb.cur_pix
    gb.pre_pix_nxt = ila.ite (decode, pre_pix_nxt, gb.pre_pix_nxt)

    gb.RAM_x_nxt = ila.ite (decode, gb.RAM_x_1, gb.RAM_x_nxt)
    gb.RAM_y_nxt = ila.ite (decode, gb.RAM_y, gb.RAM_y_nxt)
    gb.RAM_w_nxt = ila.ite (decode, gb.RAM_w, gb.RAM_w_nxt)
    for i in xrange (0, gb.RAM_size):
        gb.RAM_nxt[i] = ila.ite (decode, gb.RAM[i], gb.RAM_nxt[i])
    for i in xrange (0, gb.stencil_size):
        gb.stencil_nxt[i] = ila.ite (decode, gb.stencil[i], gb.stencil_nxt[i])
   
    # stencil ready (child-state)
    st_ready_nxt = READY_T 
    gb.st_ready_nxt = ila.ite (decode, st_ready_nxt, gb.st_ready_nxt)

    # 9x9 stencil (child-state)
    gb.proc_in_nxt = ila.ite (decode, gb.proc_in, gb.proc_in_nxt)

