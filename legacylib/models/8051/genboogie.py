#! /usr/bin/python2.7

import sys
import argparse

import ila
from uc8051ast import uc8051

def readhex(filename):
    data_dict = {}
    data = []
    with open(filename, 'rt') as fileobject:
        for line in fileobject:
            line = line.strip()
            if len(line) == 0:
                continue
            if line[0] != ':':
                print filename, line
            assert line[0] == ':'
            line = line[1:]
            length_str = line[:2]
            addr_str = line[2:6]
            type_str = line[6:8]
            data_str = line[8:-2]

            data_length = int(length_str, 16)
            start_addr = int(addr_str, 16)
            record_type = int(type_str, 16)

            #print data_str
            #print 2*data_length, len(data_str)
            assert 2*data_length == len(data_str)
            data_bytes = [int(data_str[i:i+2], 16) for i in xrange(0,2*data_length,2)]
            #print data_bytes
            assert len(data_bytes) == data_length

            if record_type == 0:
                for i, addr in enumerate(xrange(start_addr, start_addr+data_length)):
                    data_dict[addr] = data_bytes[i]

        data = [-1] * (max(data_dict.keys())+1)
        for addr in data_dict:
            data_value = data_dict[addr]
            assert data[addr] == -1
            data[addr] = data_value
        for i in xrange(len(data)):
            if data[i] == -1:
                data[i] = 0

    return data

def genboogie(hexfile, enable_ps):
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
    regs = [
        'PC', 'ACC', 'B', 'PSW', 'SP', 
        'DPL', 'DPH', 
        'P0', 'P1', 'P2', 'P3', 
        'PCON', 'TCON', 'TMOD', 'TL0', 
        'TH0', 'TL1', 'TH1', 'SCON', 
        'SBUF', 'IE', 'IP', 'XRAM_DATA_OUT', 
        'XRAM_ADDR'
    ]
    states = regs + ['IRAM']


    for s in states:
        ast = model.importOne('asts/%s_%s' % (s, 'en' if enable_ps else 'dis'))
        model.set_next(s, ast)

    for r in regs:
        reg = model.getreg(r)
        zero = model.const(0, reg.type.bitwidth)
        model.set_init(r, zero)

    print 'Finished importing 8051 ASTs.'

    data = readhex(hexfile)
    romvalue = ila.MemValues(16, 8, 0xff)
    for a, d in enumerate(data):
        #print '0x%04x -> 0x%02x' % (a, d)
        romvalue[a] = d
    romconst = model.const(romvalue)
    model.set_init('ROM', romconst)
    model.set_next('ROM', rom)
    print 'Set ROM initial value.'
    model.toBoogie("test")

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("hexfile", type=str, help='hex file.')
    parser.add_argument("--en", type=int, default=1, 
                        help="enable parameterized synthesis.")

    args = parser.parse_args()
    genboogie(args.hexfile, args.en) 


if __name__ == '__main__':
    main()
