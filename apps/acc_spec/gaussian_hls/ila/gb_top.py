# ILA for Halide Gaussian blur accelerator, with both the read and write 
# instructions have child-instructions for data movement.
# Overall and export to RTL

import ila

from gb_arch import GBArch
from gb_wri import WRI
from gb_rdi import RDI
from gb_u1 import U1
from gb_u1b import U1b
from gb_u2 import U2
from gb_u2b import U2b
from gb_u3 import U3
from gb_u4 import U4

def createILA ():
    gb = GBArch ()
    U1 (gb)
    U1b (gb)
    U2 (gb)
    U2b (gb)
    U3 (gb)
    U4 (gb)
    WRI (gb)
    RDI (gb)

    gb.setNext ()
    verilogFile = 'gb_verilog.v'
    gb.exportVerilog (verilogFile)

if __name__ == '__main__':
    createILA ()
    
