
# This is a test which tries to synthesize a simple ALU.
import ila
import argparse
import math
import time
import os

class alu_sim(object):
    def __init__(self, reg_field_width, reg_size):
        self.REG_FIELD_WIDTH = reg_field_width
        self.REG_FIELD_MASK1 = (1 << self.REG_FIELD_WIDTH) - 1
        self.REG_FIELD_MASK2 = ((1 << self.REG_FIELD_WIDTH) - 1) << self.REG_FIELD_WIDTH
        self.NUM_REGS = 1 << self.REG_FIELD_WIDTH
        self.REG_SIZE = reg_size
        self.OPCODE_WIDTH = 2 + 2*self.REG_FIELD_WIDTH
        self.NUM_OPCODES = 1 << self.OPCODE_WIDTH
        self.OPCODE_MASK = 0b11 << (2*self.REG_FIELD_WIDTH)
        self.MASK = (1 << reg_size) - 1
        self.ROM_SIZE = 16
        self.ROM_ADDR_WIDTH = int(math.log(self.ROM_SIZE, 2))
        self.PC_MASK = (self.ROM_SIZE-1)

    def alu(self, rom, pc, regs):
        ADD = 0
        SUB = 1
        AND = 2
        OR  = 3

        assert len(regs) == self.NUM_REGS

        opcode = rom[pc]
        reg0_index = opcode & self.REG_FIELD_MASK1
        reg1_index = (opcode & self.REG_FIELD_MASK2) >> self.REG_FIELD_WIDTH
        r0 = regs[reg0_index]
        r1 = regs[reg1_index]
        opcode = (opcode & self.OPCODE_MASK) >> (2*self.REG_FIELD_WIDTH)

        #print 'ARGS:', opcode, r0, r1

        if opcode == ADD:
            res = (r0 + r1) & self.MASK
        elif opcode == SUB:
            res = (r0 - r1) & self.MASK
        elif opcode == AND and reg0_index == reg1_index:
            res = (~r0 & self.MASK)
        elif opcode == OR and reg0_index == reg1_index:
            res = (-r0 & self.MASK)
        elif opcode == AND:
            res = (r0 & r1)
        elif opcode == OR:
            res = (r0 | r1)
        else:
            assert False

        # print 'OP:%x r%d:%x r%d:%x res:%x' % (opcode, reg0_index, r0, reg1_index, r1, res)
        regs[reg0_index] = res
        return regs

    def alusim(self, state):
        #print 'IN:', state
        rom = state['rom']
        pc = state['pc']
        regs = [state['r%d' % i] for i in xrange(self.NUM_REGS)]
        regs = self.alu(rom, pc, regs)
        for i in xrange(self.NUM_REGS):
            state['r%d' % i] = regs[i]
        state['pc'] = (pc + 1) & self.PC_MASK
        #print 'OUT:', state
        return state

def select(regs, regindex):
    def r(i):
        if i == 0: return regs[0]
        else: return ila.ite(regindex == i, regs[i], r(i-1))
    n = len(regs)
    return r(n-1)

def aluexpr(rom, pc, regs):
    reg_field_width = int(math.log(len(regs), 2))
    opcode = rom[pc]
    rs = opcode[reg_field_width-1:0]
    rt = opcode[2*reg_field_width-1:reg_field_width]
    r0 = select(regs, rs)
    r1 = select(regs, rt)
    op = opcode[2*reg_field_width+1:2*reg_field_width]

    res = ila.ite(op == 0, r0+r1, 
            ila.ite(op == 1, r0-r1,
                ila.ite(op == 2, ila.ite(rs == rt, ~r0, r0 & r1),
                    ila.ite(rs == rt, -r0, r0 | r1))))

    regs_next = []
    for i, r in enumerate(regs):
        regs_next.append(ila.ite(rs == i, res, r))

    return regs_next

def model(num_regs, reg_size, paramsyn):
    reg_field_width = int(math.log(num_regs, 2))
    assert (1 << reg_field_width) == num_regs

    # create the alu.
    alu = alu_sim(reg_field_width, reg_size)

    sys = ila.Abstraction("alu")
    sys.enable_parameterized_synthesis = paramsyn

    # state elements.
    rom = sys.mem('rom', alu.ROM_ADDR_WIDTH, alu.OPCODE_WIDTH)
    pc = sys.reg('pc', alu.ROM_ADDR_WIDTH)
    opcode = rom[pc]
    regs = [sys.reg('r%d' % i, alu.REG_SIZE) for i in xrange(alu.NUM_REGS)]
    # get the two sources.
    rs = ila.choice('rs', regs)
    rt = ila.choice('rt', regs)
    rs = [rs+rt, rs-rt, rs&rt, rs|rt, ~rs, -rs, ~rt, -rt]
    # set next.
    sys.set_next('pc', ila.choice('pc', pc+1, pc+2))

    # set rom next.
    sys.set_next('rom', rom)

    regs_next = []
    for i in xrange(alu.NUM_REGS):
        ri_next = ila.choice('result%d' % i, rs+[regs[i]])
        sys.set_next('r%d' % i, ri_next)
    # set the fetch expressions.
    sys.fetch_expr = opcode
    # now set the decode expressions.
    sys.decode_exprs = [opcode == i for i in xrange(alu.NUM_OPCODES)]

    # synthesize pc first.
    sys.synthesize('pc', lambda s: alu.alusim(s))
    pc_next = sys.get_next('pc')
    assert sys.areEqual(pc_next, pc+1)

    # now synthesize.
    st = time.clock()
    sys.synthesize(lambda s: alu.alusim(s))
    et = time.clock()
    print 'time for synthesis: %.3f' % (et-st)

    regs_next = aluexpr(rom, pc, regs)
    for i in xrange(alu.NUM_REGS):
        rn1 = sys.get_next('r%d' % i)
        rn2 = regs_next[i]
        assert sys.areEqual(rn1, rn2)
    # addr 16 bit, data 8 bit
    xram = sys.mem('xram', 8, 8)
    wrrd = sys.reg('wrrd', 8)
    data = sys.const(0xfe, 8)
    addr = sys.const(0x04, 8)
    xram = ila.store(xram, addr, data)
    wrrd_next = xram[addr]
    sys.set_next('wrrd', wrrd_next)
    
    wrrdblx = sys.reg('wrrdblx', 24)
    datablx = sys.const(0x0f00fe, 24)
    xram = ila.storeblk(xram, addr, datablx)
    wrrdblx_next = ila.loadblk(xram, addr, 3)
    sys.set_next('wrrdblx', wrrdblx_next)
    
    #sys.add_assumption(opcode == 0x80)
    #print sys.syn_elem("r0", sys.get_next('r0'), alusim)

    expFile  = "tmp/test_ila_export.txt"
    sys.exportAll(expFile);

    # now import into a new abstraction and check.
    sysp = ila.Abstraction("alu")
    sysp.importAll(expFile);
    romp = sysp.getmem('rom')
    pcp = sysp.getreg('pc')
    regsp = [sysp.getreg('r%d' % i) for i in xrange(alu.NUM_REGS)]
    regs_next = aluexpr(romp, pcp, regsp)
    for i in xrange(alu.NUM_REGS):
        rn1 = sysp.get_next('r%d' % i)
        rn2 = regs_next[i]
        assert sysp.areEqual(rn1, rn2)

    #os.unlink(expFile)

    #simFile = "tmp/test_ila_sim.hpp"
    #sys.generateSim(simFile)
    path = 'tmp/dir'
    if not os.path.exists (path):
        os.makedirs (path)
    sys.generateSimToDir(path)
    #os.system('g++ ' + simFile + 'tmp/test_ila_sim')
    #os.unlink(simFile)

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--numregs", type=int, default=2, help="# of registers")
    parser.add_argument("--regwidth", type=int, default=4, help="register width")
    parser.add_argument("--enable-param-syn", type=int, 
                        default=1, help="enable parameterized synthesis")
    args = parser.parse_args()

    numregs = args.numregs
    if (numregs & (numregs - 1)) != 0:
        print 'Error: number of registers must be power of two.'
        return

    model(numregs, args.regwidth, args.enable_param_syn)

if __name__ == '__main__':
    main()

    

