# ILA for Halide Gaussian blur accelerator, with both the read and write 
# instructions have child-instructions for data movement.
# Overall and export to RTL

import ila

from gb_arch import GBArch
from gb_wri import WRI
from gb_rdi import RDI
from gb_u1 import U1

def createILA ():
    gb = GBArch ()
    WRI (gb)
    RDI (gb)
    U1 (gb)

    gb.setNext ()
    verilogFile = 'gb_verilog.v'
    gb.exportVerilog (verilogFile)

if __name__ == '__main__':
    createILA ()
    
