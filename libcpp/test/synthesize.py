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

def daz(d):
    r0 = d['r0']
    r1 = d['r1']
    return r0 + r1 + 0x44

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
    resfoo = sys.synthesize(ex, foo)
    assert sys.areEqual(resfoo, r0+r1)

    resbar = sys.synthesize(ex, bar)
    assert sys.areEqual(resbar, r0-r1)

    a1 = ila.choice("a1", a, ~a, a&b, a|b)
    b1 = ila.choice("b1", [b, ~b, a&b, a|b, a^b])

    a2 = ila.choice("a2", a, ~a)
    b2 = ila.choice("b2", b, ~b)

    t1 = a1 & b1
    t2 = a2 & b2
    y  = t1 | t2
    resbaz = sys.synthesize(y, baz)
    assert sys.areEqual(resbaz, a^b)

    resshaz= sys.synthesize(y, shaz)
    assert sys.areEqual(resshaz, ~(a^b))
    
    c = ila.inrange("cnst", sys.const(0x00,8), sys.const(0xff,8))
    print c, c.type
    z = ila.choice("func_z", r0+r1+c, r0+r1-c)
    resdaz = sys.synthesize(z, daz)
    print resdaz

if __name__ == '__main__':
    main()
