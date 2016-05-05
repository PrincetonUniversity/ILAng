import ila

def foo(d):
    ram = d['iram']
    addr = d['addr']
    r = ram[addr]+1
    return { "foo": r}

def main():
    sys = ila.Abstraction("test")
    iram = sys.mem('iram', 8, 8)
    addr = sys.reg('addr', 8)
    print iram, iram.type
    data = iram[addr]

    addrp = sys.reg('addrp', 8)
    datap = iram[addrp]

    t = sys.bool(True)
    f = sys.bool(False)

    assert sys.areEqual((addr != addrp) | (data == datap), t)

    print data, data.type
    datap = data+1
    print datap, datap.type

    iramp = ila.store(iram, addr, data+1)
    print iramp, iramp.type

    assert sys.areEqual(iramp[addr], data+1)
    assert not sys.areEqual(data, data+1)

    m = ila.MemValues(8, 8, 0xff)
    print m

    for i in xrange(0x80, 0x90):
        m[i] = i-0x80
    print m

    for i in xrange(0x0, 0x100):
        if i >= 0x80 and i < 0x90:
            assert m[i] == i-0x80
        else:
            assert m[i] == 0xff

    print m
    m1 = sys.const(m)

    assert m.default == 0xff
    m.default = 0x0
    print m
    assert m[0] == 0
    print m.values

    m2 = sys.const(m)

    # assert not sys.areEqual(m1[addr], m2[addr])
    ante = ((addr >= 0x80) & (addr < 0x90))
    conseq = (m1[addr] == m2[addr])

    assert sys.areEqual(ila.implies(ante, conseq), t)
    assert not sys.areEqual(conseq, t)

    r1 = iram[addr]+1
    r2 = iram[addr]+iram[addr+1]
    r = ila.choice('r', r1, r2)
    print sys.syn_elem("foo", r, foo)

    def bar(d):
        print d
        ram = d['iram']
        ram_ = ila.MemValues(8, 8, ram.default)
        print ram
        print ram_
        for (ad, da) in ram.values:
            ram_[ad] = da
        addr = d['addr']
        print ram_, addr, ram[addr]
        if addr != 0:
            ram_[addr] = ram_[addr]+1
        print ram_
        return { "bar":  ram_ }

    r1 = ila.store(iram, addr, iram[addr]+1)
    r2 = ila.store(iram, addr, iram[addr]+2)
    r3 = ila.ite(addr != 0, r1, iram)
    rp = ila.choice('rp', r1, r2, r3)
    expr =  sys.syn_elem("bar", rp, bar)
    assert sys.areEqual(expr, r3)

    ila.setloglevel(3, "")

    data = sys.const(0xdeadbeef, 32)
    print data
    iramp = ila.storeblk(iram, addrp, data)
    d0 = iramp[addrp]
    d1 = iramp[addrp+1]
    d2 = iramp[addrp+2]
    d3 = iramp[addrp+3]
    datablk = ila.loadblk(iramp, addrp, 4)
    assert sys.areEqual(datablk, data)
    assert sys.areEqual(datablk, ila.concat([d3, d2, d1, d0]))
    assert sys.areEqual(ila.concat(d0, d1), sys.const(0xefbe, 16))
    assert sys.areEqual(ila.concat(d2, d3), sys.const(0xadde, 16))


if __name__ == '__main__':
    main()
