# This is a test which tries to synthesize a simple ALU.
import ila
import argparse
import math

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

    def alu(self, opcode, regs):
        ADD = 0
        SUB = 1
        AND = 2
        OR  = 3

        assert len(regs) == self.NUM_REGS

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
        opcode = state['opcode']
        regs = [state['r%d' % i] for i in xrange(self.NUM_REGS)]
        regs = self.alu(opcode, regs)
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

def aluexpr(opcode, regs):
    reg_field_width = int(math.log(num_regs, 2))
    rs = opcode[reg_field_width-1:0]
    rt = opcode[2*reg_field_width-1:reg_field_width]
    r0 = select(regs, rs)
    r1 = select(regs, rt)
    op = opcode[2*reg_field_width+1:2*reg_field_width]

    res = ila.ite(op == 0, r0+r1, 
            ila.ite(op == 1, r0-r1,
                ila.ite(op == 2, ila.ite(rs == rt, ~rs, rs & rt),
                    ila.ite(op == 3, ila.ite(rs == rt, -rs, rs | rt)))))

    regs_next = []
    for i, r in enumerate(regs):
        regs_next.append(ila.ite(rs == i, res, r))

def model(num_regs, reg_size, paramsyn):
    reg_field_width = int(math.log(num_regs, 2))
    assert (1 << reg_field_width) == num_regs

    # create the alu.
    alu = alu_sim(reg_field_width, reg_size)

    sys = ila.Abstraction()
    sys.enable_parameterized_synthesis = paramsyn
    print sys.enable_parameterized_synthesis;

    # state elements.
    regs = [sys.reg('r%d' % i, alu.REG_SIZE) for i in xrange(alu.NUM_REGS)]
    opcode = sys.inp('opcode', alu.OPCODE_WIDTH)

    # get the two sources.
    rs = ila.choice('rs', regs)
    rt = ila.choice('rt', regs)
    rs = [rs+rt, rs-rt, rs&rt, rs|rt, ~rs, -rs, ~rt, -rt]
    # rs = [rs+rt, rs-rt] #

    # set next.
    regs_next = []
    for i in xrange(alu.NUM_REGS):
        ri_next = ila.choice('result%d' % i, rs+[regs[i]])
        sys.set_next('r%d' % i, ri_next)

    # set the fetch expressions.
    sys.fetch_expr = opcode
    # now set the decode expressions.
    sys.decode_exprs = [opcode == i for i in xrange(alu.NUM_OPCODES)]
    # now synthesize.
    sys.synthesize(lambda s: alu.alusim(s))
    #sys.add_assumption(opcode == 0x80)
    #print sys.syn_elem("r0", sys.get_next('r0'), alusim)

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

    

