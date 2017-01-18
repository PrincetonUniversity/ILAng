import ila

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

