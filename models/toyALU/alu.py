# This is a test which tries to synthesize a simple ALU.
import ila
import argparse
import math
import time
import os

class alu_sim(object):
    def __init__(self):
        self.NUM_REGS = 4
        self.REG_SIZE = 8
        self.REG_FIELD_MASK1 = 0b11
        self.REG_FIELD_MASK2 = 0b1100
        self.REG_FIELD_WIDTH = 2
        self.OPCODE_MASK = 0x3f
        self.MASK = 0xff

        self.ROM_ADDR_WIDTH = 8
        self.OPCODE_WIDTH = 8
        self.PC_MASK = 0xff
        self.NUM_OPCODES = 0x100
        self.NUM_CARE_OPCODES = (1 << 6)

    def alu(self, rom, pc, regs):
        ADD = 0
        SUB = 1
        ADDI = 2
        SUBI = 3

        assert len(regs) == self.NUM_REGS

        opcode = rom[pc]
        imm = rom[(pc + 1) & 0xFF]
        reg0_index = opcode & self.REG_FIELD_MASK1
        reg1_index = (opcode & self.REG_FIELD_MASK2) >> self.REG_FIELD_WIDTH
        r0 = regs[reg0_index]
        r1 = regs[reg1_index]
        opcode = (opcode & self.OPCODE_MASK) >> (2*self.REG_FIELD_WIDTH)

        #print 'ARGS:', opcode, r0, r1

        if opcode == ADD:
            res = (r0 + r1) & self.MASK
            pc += 1
        elif opcode == SUB:
            res = (r0 - r1) & self.MASK
            pc += 1
        elif opcode == ADDI:
            res = (r0 + imm) & self.MASK
            pc += 2
        elif opcode == SUBI:
            res = (r0 - imm) & self.MASK
            pc += 2
        else:
            assert False

        # print 'OP:%x r%d:%x r%d:%x res:%x' % (opcode, reg0_index, r0, reg1_index, r1, res)
        regs[reg0_index] = res
        return regs, (pc & self.PC_MASK)

    def alusim(self, state):
        #print 'IN:', state
        regs = [state['r%d' % i] for i in xrange(self.NUM_REGS)]
        regs, state['pc'] = self.alu(state['rom'], state['pc'], regs)
        for i in xrange(self.NUM_REGS):
            state['r%d' % i] = regs[i]
        #print 'OUT:', state
        return state

def select(regs, regindex):
    def r(i):
        if i == 0: return regs[0]
        else: return ila.ite(regindex == i, regs[i], r(i-1))
    n = len(regs)
    return r(n-1)

def aluexpr(rom, pc, regs):
    assert len(regs) == 4
    opcode = rom[pc]
    rs = opcode[1:0]
    rt = opcode[3:2]
    r0 = select(regs, rs)
    r1 = select(regs, rt)
    imm = rom[pc+1]
    op = opcode[5:4]

    res = ila.ite(op == 0, r0+r1, 
            ila.ite(op == 1, r0-r1,
                ila.ite(op == 2, r0+imm,
                    r0-imm)))

    regs_next = []
    for i, r in enumerate(regs):
        regs_next.append(ila.ite(rs == i, res, r))

    pc_next = ila.ite((op == 0) | (op == 1), pc+1, pc+2)
    return regs_next, pc_next

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

def main():
    ila.setloglevel(2, "")
    parser = argparse.ArgumentParser()
    parser.add_argument("--enable-param-syn", type=int, 
                        default=1, help="enable parameterized synthesis")
    args = parser.parse_args()
    model(args.enable_param_syn)

if __name__ == '__main__':
    main()

    

