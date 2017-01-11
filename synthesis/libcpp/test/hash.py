import ila

def main():
    m = ila.Abstraction('test')
    x = m.reg('x', 8)
    y = m.reg('y', 8)

    ex1 = (x + y) | x
    h1 = ex1.__hash__()

    ex2 = (x + y) | x
    h2 = ex2.__hash__()

    x3 = m.getreg('x')
    y3 = m.getreg('y')
    ex3 = (x3 + y3) | x
    h3 = ex3.__hash__()

    assert h1 == h2
    assert h2 == h3
    assert h3 == h1

    ex4 = (y + x) | x
    h4 = ex4.__hash__()

    assert h4 != h1
    assert h4 != h2
    assert h4 != h3


if __name__ == '__main__':
    main()

    
