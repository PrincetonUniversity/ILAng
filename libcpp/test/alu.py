# This is a test which tries to synthesize a simple ALU.
import ila

NUM_REGS = 8

def alu(opcode, regs):
    ADD = 0
    SUB = 1
    AND = 2
    OR  = 3
    MASK = 0xff

    assert len(regs) == NUM_REGS

    reg0_index = opcode & 0b111
    reg1_index = (opcode & 0b111000) >> 3
    r0 = regs[reg0_index]
    r1 = regs[reg1_index]
    opcode = (opcode & 0b11000000) >> 6

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
    elif opcode == OR and reg0_index == reg1_index:
        res = -r0
    else:
        assert False

    regs[reg0_index] = res
    return regs

def alusim(state):
    #print state
    opcode = state['opcode']
    regs = [state['r%d' % i] for i in xrange(NUM_REGS)]
    regs = alu(opcode, regs)
    for i in xrange(NUM_REGS):
        state['r%d' % i] = regs[i]
    #print state
    return state

def model():
    sys = ila.Abstraction()
    # state elements.
    regs = [sys.reg('r%d' % i, 8) for i in xrange(NUM_REGS)]
    opcode = sys.inp('opcode', 8)

    # get the two sources.
    r0 = ila.choice('r0', regs)
    r1 = ila.choice('r1', regs)
    r0_index = ila.readslice('r0bits', opcode, 3)
    e = ila.choice('res', [r0+r1, r0-r1, r0&r1, r0|r1, ~r0, -r0, ~r1, -r1])

    # set next.
    regs_next = []
    for i in xrange(NUM_REGS):
        ri_next = ila.ite(r0_index == i, e, regs[i])
        sys.set_next('r%d' % i, ri_next)

    # set the fetch expressions.
    sys.fetch_expr = opcode
    # now set the decode expressions.
    sys.decode_exprs = [opcode == i for i in xrange(256)]
    # now synthesize.
    sys.synthesize(alusim)

if __name__ == '__main__':
    model()

    

