import ila

from gb_arch import GBArch
from gb_wri import WRI
from gb_rdi import RDI
from gb_u1 import U1
from gb_u1b import U1b
from gb_u1c import U1c
from gb_u2 import U2
from gb_u3 import U3
from gb_u3b import U3b
from gb_u4 import U4

def createILA ():
    gb = GBArch ()
    U1 (gb)
    U1b (gb)
    U2 (gb)
    U3 (gb)
    U3b (gb)
    U4 (gb)
    WRI (gb)
    RDI (gb)
    U1c (gb)

    gb.setNext ()
    verilogFile = 'gb_verilog_all.v'
    gb.exportVerilog (verilogFile)

if __name__ == '__main__':
    createILA ()
    
