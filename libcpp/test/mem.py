import ila

def main():
    sys = ila.Abstraction()
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
    assert m.default == 0xff
    m.default = 0x0
    print m
    assert m[0] == 0

if __name__ == '__main__':
    main()
