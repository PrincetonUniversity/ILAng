import ila

def foo(d):
    print 'initial value: %s' % str(d)
    return d['r0'] + d['r1']

def bar(d):
    print 'bar called.'
    return None

def main():
    sys = ila.Abstraction()
    r0 = sys.reg('r0', 8)
    r1 = sys.reg('r1', 8)
    ex = sys.choice("function", r0+r1, r0-r1)
    sys.synthesize(ex, foo)


if __name__ == '__main__':
    main()
