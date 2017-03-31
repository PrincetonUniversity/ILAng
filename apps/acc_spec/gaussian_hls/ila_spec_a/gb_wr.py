# ILA for Halide Gaussian Blur (GB) accelerator that abstracts buffering.
# write instruction.

import ila

from gb_arch import GBArch
from gb_nxt_wri import WRI
from gb_nxt_wr0 import WRU1

# Define child-states
def defUSts (gb):
    m = gb.abst

    gb.proc_in      = m.reg ('proc_in', gb.slice_size * gb.stencil_size)
    gb.proc_in_nxt  = gb.proc_in

    """
    COUNT_SIZE      = 19
    gb.proc_cnt     = m.reg ('proc_cnt', COUNT_SIZE)
    gb.proc_cnt_0   = m.const (0x0, COUNT_SIZE)
    gb.proc_cnt_1   = m.const (0x1, COUNT_SIZE)
    gb.proc_cnt_M   = m.const (0x4B000, COUNT_SIZE)
    gb.proc_cnt_nxt = gb.proc_cnt
    """

# Define next state function for each instruction/child-instruction
def defNext (gb):
    WRI (gb)
    WRU1 (gb)

# Connect next state function to the abstraction
def setNext (gb):
    gb.setNext ()
    
    m = gb.abst
    m.set_next ('proc_in', gb.proc_in_nxt)

if __name__ == '__main__':
    gb = GBArch ()

    defUSts (gb)
    defNext (gb)
    setNext (gb)

    verilogFile = 'gb_verilog_wri.v'
    gb.exportVerilog (verilogFile)
