import ila

from gb_arch import GBArch
from gb_wri import WRI
from gb_u1 import U1
from gb_u2 import U2
from gb_u3 import U3
from gb_u4 import U4

def createILA ():
    gb = GBArch ()
    U1 (gb)
    U2 (gb)
    U3 (gb)
    U4 (gb)
    WRI (gb)

    gb.setNext ()
    verilogFile = 'gb_verilog_wri.v'
    gb.exportVerilog (verilogFile)

if __name__ == '__main__':
    createILA ()
    
