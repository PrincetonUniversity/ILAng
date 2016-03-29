import ila

def main():
    c = ila.Abstraction()

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
    e4 = c.choice("dummy", e2, e1)
    assert c.areEqual(e1, e2)
    assert c.areEqual(e1, e4)
    assert c.areEqual(e2, e4)
    assert not c.areEqual(e1, e3)
    assert not c.areEqual(e4, e3)



if __name__ == '__main__':
    main()
