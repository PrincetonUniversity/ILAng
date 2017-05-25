import ila

from gb_arch import GBArch
from gb_nxt_wri import WRI
from gb_nxt_wr0 import WRU0
from gb_nxt_wr0b import WRU0b
from gb_nxt_wr1 import WRU1

# Define child-states
def defUSts (gb):
    m = gb.abst

    gb.pre_pix      = m.reg ('pre_pix', gb.DATA_SIZE)
    gb.pre_pix_nxt  = gb.pre_pix

    gb.st_ready     = m.reg ('st_ready', 1)
    gb.st_ready_nxt = gb.st_ready

    gb.proc_in      = m.reg ('proc_in', gb.slice_size * gb.stencil_size)
    gb.proc_in_nxt  = gb.proc_in
    
# Define next state function for each instruction/child-instruction
def defNext (gb):
    WRI (gb)
    WRU0 (gb)
    WRU0b (gb)
    WRU1 (gb)

# Connect next state function to the abstraction
def setNext (gb):
    gb.setNext ()
    
    m = gb.abst
    m.set_next ('proc_in', gb.proc_in_nxt)
    m.set_next ('pre_pix', gb.pre_pix_nxt)
    m.set_next ('st_ready', gb.st_ready_nxt)

if __name__ == '__main__':
    gb = GBArch ()

    defUSts (gb)
    defNext (gb)
    setNext (gb)

    verilogFile = 'gb_verilog_wri.v'
    gb.exportVerilog (verilogFile)
