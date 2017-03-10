# ILA for Halide Gaussian blur accelerator, with both the read and write 
# instructions have child-instructions for data movement.
# Overall and export to RTL

import ila

from gb_arch import GBArch
from gb_wri import WRI

def createILA ():
    gb = GBArch ()
    WRI (gb)

    gb.setNext ()
    verilogFile = 'gb_rtl.v'
    gb.exportVerilog (verilogFile)

if __name__ == '__main__':
    createILA ()
    
