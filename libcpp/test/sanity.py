import ila

def main():
    c = ila.Abstraction()
    n = c.addReg("test", 16)
    print n.name
    print n.type
    print n.type.bitwidth
    n.doSomething()
    print n
    del n

    print 'creating new bitvecvar'
    m = c.addReg('mambo', 24)
    n = m
    del m
    print n.name
    p = ~n
    print n
    print p
    print -p
    del n
    print p.name
    print p.type
    print p.type.bitwidth
    del p

    n1 = c.addReg('n1', 16)
    n2 = c.addReg('n2', 16)
    n2p = ~n2
    n3 = n1 + n2p
    print n3
    print n3.type

    c1 = c.const(0x80L, 16)
    print ~c1

    c2 = c.const(0x80, 16)
    print ~(c1 + c2)
    
    x =  ~(c1 + c2) + 32
    print x
    print x.type

    y = 32 + ~(c1 + c2)
    print y
    print y.type
    
    x =  ~(c1 - c2) - 32
    print x
    print x.type

    y = 32 - ~(c1 - c2)
    print y
    print y.type

    p = c.addBoolReg('pix')
    q = c.addBoolReg('qix')
    pn = ~p
    qn = ~q
    r = (p & q) | (pn & qn)
    print r.type
    print r


if __name__ == '__main__':
    main()
