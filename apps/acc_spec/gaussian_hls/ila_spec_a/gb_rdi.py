import ila

from gb_arch import GBArch

# Define next state functions for architectureal states
def defNext (gb):
    m = gb.abst

    READY_T     = gb.READY_TRUE
    READY_F     = gb.READY_FALSE
    VALID_T     = gb.VALID_TRUE
    VALID_F     = gb.VALID_FALSE
    DATA_SIZE   = gb.DATA_SIZE

    decode = (gb.arg_1_TVALID == VALID_F) & \
             (gb.arg_0_TVALID == VALID_T) & \
             (gb.arg_0_TREADY == READY_T)

    # next state functions for output ports
    arg_1_TREADY_nxt = gb.arg_1_TREADY
    gb.arg_1_TREADY_nxt = ila.ite (decode, arg_1_TREADY_nxt, gb.arg_1_TREADY_nxt)

    arg_0_TVALID_nxt = ila.ite ((gb.gbit == 0) | (gb.gbit == 7),
                                VALID_F, VALID_T)
    gb.arg_0_TVALID_nxt = ila.ite (decode, arg_0_TVALID_nxt, gb.arg_0_TVALID_nxt)

    arg_0_TDATA_nxt = gb.arg_0_TDATA
    gb.arg_0_TDATA_nxt = ila.ite (decode, arg_0_TDATA_nxt, gb.arg_0_TDATA_nxt)

    gbit_nxt = ila.ite ((gb.RAM_x == gb.RAM_x_M) & (gb.RAM_y == gb.RAM_y_M),
                        gb.gbit + 1, gb.gbit)
    gb.gbit_nxt = ila.ite (decode, gbit_nxt, gb.gbit_nxt)

    # other states are not affected
    gb.cur_pix_nxt = ila.ite (decode, gb.cur_pix, gb.cur_pix_nxt)
    gb.RAM_x_nxt = ila.ite (decode, gb.RAM_x, gb.RAM_x_nxt)
    gb.RAM_y_nxt = ila.ite (decode, gb.RAM_y, gb.RAM_y_nxt)
    gb.RAM_w_nxt = ila.ite (decode, gb.RAM_w, gb.RAM_w_nxt)
    for i in xrange (0, gb.RAM_size):
        gb.RAM_nxt[i] = ila.ite (decode, gb.RAM[i], gb.RAM_nxt[i])
    for i in xrange (0, gb.stencil_size):
        gb.stencil_nxt[i] = ila.ite (decode, gb.stencil[i], gb.stencil_nxt[i])


def setNext (gb):
    gb.setNext ()

if __name__ == '__main__':
    gb = GBArch ()

    defNext (gb)
    setNext (gb)

    verilogFile = 'gb_verilog_rdi.v'
    gb.exportVerilog (verilogFile)
