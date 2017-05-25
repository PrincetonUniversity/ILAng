# This is the simulator
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

