import ila
import argparse
import math
import time
import os

from alusim import alu_sim
from alumodel import aluexpr

def model(paramsyn):
    # create the alu.
    alu = alu_sim()

    sys = ila.Abstraction("alu")
    sys.enable_parameterized_synthesis = paramsyn

    # state elements.
    rom = sys.mem('rom', alu.ROM_ADDR_WIDTH, alu.OPCODE_WIDTH)
    pc = sys.reg('pc', alu.ROM_ADDR_WIDTH)
    opcode = rom[pc]
    regs = [sys.reg('r%d' % i, alu.REG_SIZE) for i in xrange(alu.NUM_REGS)]

    # get the two sources.
    imm = rom[pc+1]
    rs = ila.choice('rs', regs)
    rt = ila.choice('rt', regs+[imm])
    results = [rs+rt, rs-rt]

    # golden model
    gm_regs_next, pc_next = aluexpr(rom, pc, regs)
    # set next for PC.
    sys.set_next('pc', pc_next)
    # rom never changes.
    sys.set_next('rom', rom)

    regs_next = []
    for i in xrange(alu.NUM_REGS):
        ri_next = ila.choice('result%d' % i, results+[regs[i]])
        sys.set_next('r%d' % i, ri_next)
    # set the fetch expressions.
    sys.fetch_expr = opcode
    # now set the decode expressions.
    sys.decode_exprs = [opcode[5:0] == i for i in xrange(alu.NUM_CARE_OPCODES)]

    # now synthesize.
    st = time.clock()
    #sys.synthesize(lambda s: alu.alusim(s))
    sys.synthesize(lambda s: alu.alusim(s))
    et = time.clock()
    print '%.3f' % (et-st)

    for i in xrange(alu.NUM_REGS):
        rn1 = sys.get_next('r%d' % i)
        rn2 = gm_regs_next[i]
        if not sys.areEqual(rn1, rn2):
            print rn1
            print rn2
            assert False
        print rn1
    sys.generateVerilog("syn.v")

def main():
    ila.setloglevel(2, "")
    parser = argparse.ArgumentParser()
    parser.add_argument("--enable-param-syn", type=int, 
                        default=1, help="enable parameterized synthesis")
    args = parser.parse_args()
    model(args.enable_param_syn)

if __name__ == '__main__':
    main()

    

