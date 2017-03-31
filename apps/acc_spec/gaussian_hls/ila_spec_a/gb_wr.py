# ILA for Halide Gaussian Blur (GB) accelerator that abstracts buffering.
# write instruction.

import ila

from gb_arch import GBArch
from gb_wr_i import WRI
from gb_wr_1 import WRU1

# Define child-states
def defUSts (gb):
    m = gb.abst

    # TODO

# Define next state function for each instruction/child-instruction
def defNext (gb):
    WRI (gb)
    WRU1 (gb)

# Connect next state function to the abstraction
def setNext (gb):
    gb.setNext ()
    # TODO
    # set u-state nxt

if __name__ == '__main__':
    gb = GBArch ()

    defUSts (gb)
    defNext (gb)
    setNext (gb)

    verilogFile = 'gb_verilog_wri.v'
    gb.exportVerilog (verilogFile)
