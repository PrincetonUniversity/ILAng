import ila
from alusim import alu_sim

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

if __name__ == '__main__':
    sys = ila.Abstraction('alu')
    alu = alu_sim()
    rom = sys.mem('rom', alu.ROM_ADDR_WIDTH, alu.OPCODE_WIDTH)
    pc = sys.reg('pc', alu.ROM_ADDR_WIDTH)
    regs = [sys.reg('r' + str(i), alu.REG_SIZE) for i in xrange(alu.NUM_REGS)]
    gm_regs_next, pc_next = aluexpr(rom, pc, regs)
    for i in xrange(alu.NUM_REGS):
        sys.set_next('r' + str(i), gm_regs_next[i])
    sys.set_next('pc', pc_next)
    sys.set_next('rom', rom)
    prop = sys.bit('prop')
    opcode = rom[pc]
    prop_nxt = prop & (opcode == 0x0)
    sys.set_next('prop', prop_nxt)
    sys.set_init('prop', sys.bool(True))
    sys.set_init('pc', sys.const(0x0, alu.ROM_ADDR_WIDTH))
    rom_init = ila.MemValues(alu.ROM_ADDR_WIDTH, alu.OPCODE_WIDTH, 0x0)
    rom_init[0xa] = 0x1
    sys.set_init('rom', sys.const(rom_init))
    golden = ila.Abstraction('golden')
    g_prop = golden.bit('prop')
    golden.set_next('prop', golden.bool(True))
    golden.set_init('prop', golden.bool(True))

    print ila.bmc(11, sys, prop, 1, golden, g_prop)
