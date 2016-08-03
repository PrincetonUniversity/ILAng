#! /usr/bin/python2.7

import sys
import argparse

import ila
from uc8051ast import uc8051

def genVerilog(state, enable_ps):
    model = ila.Abstraction("oc8051")
    # fetch and decode.
    uc = uc8051()
    model.fetch_expr = uc.op0 # s/hand for uc.rom[uc.pc]
    model.decode_exprs = [uc.op0 == i for i in xrange(0x0, 0x100)]
   
    # program counter
    pc = model.reg('PC', 16)
    # code memory
    rom = model.mem('ROM', 16, 8)
    # IRAM
    iram = model.mem('IRAM', 8, 8)
    # main SFRs
    acc = model.reg('ACC', 8)
    b = model.reg('B', 8)
    psw = model.reg('PSW', 8)
    sp = model.reg('SP', 8)
    dpl = model.reg('DPL', 8)
    dph = model.reg('DPH', 8)
    # ports
    p0 = model.reg('P0', 8)
    p1 = model.reg('P1', 8)
    p2 = model.reg('P2', 8)
    p3 = model.reg('P3', 8)
    # misc SFRs
    pcon = model.reg('PCON', 8)
    tcon = model.reg('TCON', 8)
    tmod = model.reg('TMOD', 8)
    tl0 = model.reg('TL0', 8)
    tl1 = model.reg('TH0', 8)
    tl1 = model.reg('TL1', 8)
    th1 = model.reg('TH1', 8)
    scon = model.reg('SCON', 8)
    sbuf = model.reg('SBUF', 8)
    ie = model.reg('IE', 8)
    ip = model.reg('IP', 8)

    # XRAM
    #xram_data_in = model.reg('XRAM_DATA_IN', 8)  FIXME
    #xram_data_in = model.inp('XRAM_DATA_IN', 8)
    xram_data_out = model.reg('XRAM_DATA_OUT', 8)
    xram_addr = model.reg('XRAM_ADDR', 16)

    # get synthesized states
    for s in state:
        print 'Import %s from file' %s
        ast = model.importOne('asts/%s_%s' % (s, 'en' if enable_ps else 'dis'))
        model.set_next(s, ast)

    ila.setloglevel(3, "")
    ila.enablelog("VerilogExport")
    model.generateVerilog('oc8051_golden_model.v')

def main():
    states = ['PC', 'IRAM', 'ACC', 'B', 'PSW', 'SP', 'DPL', 'DPH', 'P0', 'P1', 'P2', 'P3', 'PCON', 'TCON', 'TMOD', 'TL0', 'TH0', 'TL1', 'TH1', 'SCON', 'SBUF', 'IE', 'IP', 'XRAM_DATA_OUT', 'XRAM_ADDR']
    genVerilog(states, 1) 

if __name__ == '__main__':
    main()
