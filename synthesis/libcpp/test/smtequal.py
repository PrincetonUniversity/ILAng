import ila

def main():
    ila.setloglevel(3, "")
    ila.enablelog("Z3ExprAdapter")
    c = ila.Abstraction("test")

    x = c.bit('x')
    y = c.bit('y')

    e1 = (x == y)
    e2 = ((x & y) | (~x & ~y))
    assert c.areEqual(e1, e2)

    e1p = ~e1
    e2p = ~e2
    assert c.areEqual(e1p, e2p)

    assert not c.areEqual(e1p, e2)
    assert not c.areEqual(e1, e2p)

    e1 = (x & y)
    e2 = ~(~x | ~y)

    assert c.areEqual(e1, e2)
    assert not c.areEqual(e1, e1p)

    a = c.reg('a', 8)
    e1 = -a
    e2 = ~a + 1
    e3 = ~a + 2
    e4 = ila.choice("dummy", e2, e1)
    assert c.areEqual(e1, e2)
    assert c.areEqual(e1, e4)
    assert c.areEqual(e2, e4)
    assert not c.areEqual(e1, e3)
    assert not c.areEqual(e4, e3)

    bv1 = c.reg('bv1', 8)
    bv2 = c.reg('bv2', 8)
    bv_add1 = bv1 + bv2
    bv_add2 = bv2 + bv1
    assert c.areEqual(bv_add1, bv_add2)

    #xram = c.mem('xram', 16, 8)
    #rom = c.mem('rom', 16, 8)
    #pc = c.reg('pc', 16)
    #opcode = concat(rom[pc], rom[pc+1])
    #c.set_opcode(opcode)

    #insts = []
    #for i in range(0, 256):
    #    inst_i = (opcode == i)
    #    insts.append(inst_i)
    #c.set_decode(insts)
    







if __name__ == '__main__':
    main()
