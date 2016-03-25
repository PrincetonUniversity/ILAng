import ila

def foo(d):
    print 'initial value:', d['arg']
    print d
    d['arg'] = d['arg'] + 1
    return d

def bar(d):
    print 'bar called.'
    return None

def main():
    sys = ila.Abstraction()
    r0 = sys.addReg('r0', 8)
    r1 = sys.addReg('r1', 8)
    sys.synthesize(r0 + r1, foo)
    sys.synthesize(r0 + r1, bar)


if __name__ == '__main__':
    main()
