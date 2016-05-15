import ila

def test():
    m1 = ila.Abstraction('t1')
    x1 = m1.reg('x', 8)
    y1 = m1.reg('y', 8)

    m1.set_next('x', x1)
    m1.set_init('x', m1.const(1, 8))
    m1.set_next('y', y1+x1)
    assert m1.areEqualUnrolled(3, y1, y1+3)

    m2 = ila.Abstraction('t2')
    y2 = m2.reg('y', 8)
    m2.set_next('y', y2+3)
    assert m2.areEqualUnrolled(3, y2, y2+9)

    assert ila.bmc(3, m2, y2, 9, m1, y1)
    assert not ila.bmc(4, m2, y2, 9, m1, y1)


if __name__ == '__main__':
    test()
