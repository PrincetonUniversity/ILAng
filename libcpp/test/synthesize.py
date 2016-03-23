import ila

def foo(d):
    print 'initial value:', d['arg']
    print d
    d['arg'] = d['arg'] + 1
    return d

def main():
    sys = ila.Abstraction()
    r0 = sys.addRegister('r0', 8)
    r1 = sys.addRegister('r1', 8)
    sys.synthesize(r0 + r1, foo)


if __name__ == '__main__':
    main()
