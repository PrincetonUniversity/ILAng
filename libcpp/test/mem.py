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


if __name__ == '__main__':
    main()
