import ila

def test():
    m = ila.Abstraction('t1')
    x = m.reg('x', 8)
    y = m.reg('y', 8)

    m.set_next('x', x)
    m.set_next('y', y+x)
    print m.areEqualUnrolled(3, y, y+x+x+x)


if __name__ == '__main__':
    test()
