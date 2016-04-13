# This is a test which tries to synthesize a simple ALU.
import ila

def alu(opcode, regs, immediate):
    ADD = 0
    SUB = 1
    AND = 2
    OR  = 3
    MASK = 0xffff

    assert len(regs) == 8

    reg0_index = opcode & 0b111
    reg1_index = (opcode & 0b111000) >> 3
    r0 = regs[reg0_index]
    r1 = regs[reg1_index]
    opcode = (opcode & 0b11000000)

    if opcode == ADD:
        res = (r0 + r1) & MASK
    elif opcode == SUB:
        res = (r0 - r1) & MASK
    elif opcode == AND:
        res = (r0 & r1)
    elif opcode == OR:
        res = (r0 | r1)
    elif opcode == AND and reg0_index == reg1_index:
        res = ~r0
    elif opcode == NEG and reg0_index == reg1_index:
        res = -r0
    return res

def model():
    sys = ila.Abstraction()

    regs = []
    for i in xrange(8):
        reg = 'r%d' % i
        regs.append(sys.reg(reg, 16))

    opcode = sys.reg('opcode', 8)
    r0 = ila.choice('r0', regs)
    r1 = ila.choice('r1', regs)
    res = ila.choice('res', [r0+r1, r0-r1, r0&r1, r0|r1, ~r0, -r0, ~r1, -r1])

    print res

    # set the fetch expressions.
    sys.fetch_expr = opcode
    # now set the decode expressions.
    sys.decode_exprs = [opcode == i for i in xrange(256)]

if __name__ == '__main__':
    model()

    

