import ila
import filecmp

def foo(d):
    # print 'initial value: %s' % str(d)
    return { "sum": d['r0'] + d['r1'] }

def bar(d):
    # print 'initial value: %s' % str(d)
    return { "diff": d['r0'] - d['r1'] }

def baz(d):
    # print d
    a = d['a']
    b = d['b']
    return  { "baz": a ^ b }
    
def shaz(d):
    # print d
    a = d['a']
    b = d['b']
    return { "shaz": not(a ^ b) }

def daz(d):
    r0 = d['r0']
    r1 = d['r1']
    return { "daz": r0 + r1 + 0x44 }

def razmatazz(d):
    r0 = d['r0']
    r1 = d['r1']
    r0lo = r0 & 0xf
    r1hi = (r1 & 0xf0) >> 4
    res = r0lo + r1hi
    return { "razmatazz": res }

def jazz(d):
    r0 = d['r0']
    r1 = d['r1']
    r0lo = r0 & 0xf
    return { "jazz": (r0 & 0xf) | (r0lo << 4) }

def rota(d):
    r0 = d['r0']
    r1 = d['r1']
    r0sr1 = r0 << r1
    return { "rota": r0sr1 }

def shint(d):
    r0 = d['r0']
    erg = r0 << 2
    return { "shint": erg }

    
def main():
    expFile  = "tmp/test_ila_export.txt"

    sys = ila.Abstraction("test")

    r0 = sys.reg('r0', 8)
    r1 = sys.reg('r1', 8)

    a = sys.bit('a')
    b = sys.bit('b')

    ex = ila.choice("function", r0+r1, r0-r1, r0+r1+1)
    resfoo = sys.syn_elem("sum", ex, foo)
    assert sys.areEqual(resfoo, r0+r1)

    resbar = sys.syn_elem("diff", ex, bar)
    assert sys.areEqual(resbar, r0-r1)

    a1 = ila.choice("a1", a, ~a, a&b, a|b)
    b1 = ila.choice("b1", [b, ~b, a&b, a|b, a^b])

    a2 = ila.choice("a2", a, ~a)
    b2 = ila.choice("b2", b, ~b)

    t1 = a1 & b1
    t2 = a2 & b2
    y  = t1 | t2
    resbaz = sys.syn_elem("baz", y, baz)
    assert sys.areEqual(resbaz, a^b)

    resshaz= sys.syn_elem("shaz", y, shaz)
    assert sys.areEqual(resshaz, ~(a^b))
    
    c = ila.inrange("cnst", sys.const(0x00,8), sys.const(0xff,8))
    z = ila.choice("func_z", r0+r1+c, r0+r1-c)
    resdaz = sys.syn_elem("daz", z, daz)
    assert sys.areEqual(resdaz, r0 + r1 + 0x44)

    slc0 = ila.readslice("r0slice", r0, 4)
    slc1 = ila.readslice("r1slice", r1, 4)
    res = ila.choice('slice', slc0 + slc1, slc0 - slc1)
    resrmz = sys.syn_elem("razmatazz", res, razmatazz)
    assert sys.areEqual(resrmz, r0[3:0]+r1[7:4])

    sys.exportOne(resrmz, expFile)
    getback = sys.importOne(expFile)
    assert sys.areEqual(resrmz, getback)
    print getback
    #sys.exportFile(expFile);

    #sys.importFile(expFile);

    ila.setloglevel (3, "")
    ila.enablelog ("Export")
    sys.exportList([resrmz, resdaz], expFile)
    l = sys.importList (expFile)
    for ast in l:
        print ast

if __name__ == '__main__':
    main()
