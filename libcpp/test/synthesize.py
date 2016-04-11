import ila

def foo(d):
    # print 'initial value: %s' % str(d)
    return d['r0'] + d['r1']

def bar(d):
    # print 'initial value: %s' % str(d)
    return d['r0'] - d['r1']

def baz(d):
    # print d
    a = d['a']
    b = d['b']
    return a ^ b
    
def shaz(d):
    # print d
    a = d['a']
    b = d['b']
    return not(a ^ b)

def fetch(d):
    print d
    addr = d['addr']
    data = d['data']
    wr = d['wr']
#    temp1 = ?? How to concat
#    return
    
def main():
    sys = ila.Abstraction()
    r0 = sys.reg('r0', 8)
    r1 = sys.reg('r1', 8)

    a = sys.bit('a')
    b = sys.bit('b')

    ex = ila.choice("function", r0+r1, r0-r1, r0+r1+1)
    print sys.synthesize(ex, foo)
    print sys.synthesize(ex, bar)

    a1 = ila.choice("a1", a, ~a, a&b, a|b)
    b1 = ila.choice("b1", [b, ~b, a&b, a|b, a^b])

    a2 = ila.choice("a2", a, ~a)
    b2 = ila.choice("b2", b, ~b)

    r1 = a1 & b1
    r2 = a2 & b2
    y  = r1 | r2
    print sys.synthesize(y, baz)
    print sys.synthesize(y, shaz)
    

if __name__ == '__main__':
    main()
