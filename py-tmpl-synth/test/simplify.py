# This is a test which tries to synthesize a simple ALU.
import ila
import argparse
import math
import time
import os

def alusim(s_in):
    opcode = s_in['opcode']
    rs_index = opcode & 0x3
    rt_index = (opcode >> 2) & 0x3
    rd_index = (opcode >> 4) & 0x3
    op = (opcode >> 6) & 0x1

    regs = [s_in['r%d' % i] for i in xrange(4)]
    rs = regs[rs_index]
    rt = regs[rt_index]


    if op == 0:
        res = (rs + rt) & 0xff
    else:
        res = (rs - rt) & 0xff

    regs[rd_index] = res

    s_out = {'r%d' % i: regs[i] for i in xrange(len(regs))}
    return s_out


def createmodel():
    m = ila.Abstraction('alu')
    m.enable_parameterized_synthesis = 1

    regs = [m.reg('r%d' % i, 8) for i in xrange(4)]
    opcode = m.inp('opcode', 7)

    rs_index = opcode[1:0]
    rt_index = opcode[3:2]
    rd_index = opcode[5:4]
    op       = opcode[6:6]

    def sel(regs, idx):
        return ila.ite(idx == 0, regs[0],
                ila.ite(idx == 1, regs[1],
                 ila.ite(idx == 2, regs[2], regs[3])))

    rs = sel(regs, rs_index)
    rt = sel(regs, rt_index)
    res = ila.choice('op', rs + rt, rs - rt)
    for i in xrange(4):
        ri_next = ila.ite(rd_index == i, res, regs[i])
        m.set_next('r%d' % i, ri_next)

    m.fetch_expr = opcode
    m.decode_exprs = [opcode == i for i in xrange(0, 128)]
    m.synthesize(alusim)
    for i, di in enumerate(m.decode_exprs):
        for reg in xrange(4):
            exp_i = m.get_next('r%d' % reg, i)
            si =  ila.simplify(di, exp_i)
            if not m.areEqual(di, exp_i, si):
                print 'decode:', di
                print 'exp:', exp_i

def main():
    createmodel()

if __name__ == '__main__':
    main()

    


