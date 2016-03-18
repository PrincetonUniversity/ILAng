import ila

def main():
    n = ila.BitvectorVar("test", 16)
    print n.name
    print n.type
    print n.type.bitwidth
    n.doSomething()
    del n

    print 'creating new bitvecvar'
    m = ila.BitvectorVar('mambo', 24)
    n = m
    del m
    print n.name



if __name__ == '__main__':
    main()
