
NOP = 0
RD  = 1
WR  = 2

class mmiodev(object):
    def __init__(self):
        self.regmap = {}
        self.regidx = {}

    def addReg(self, name, addr, length, readonly=0, default=0):
        # make sure it doesn't overlap with anything.
        for (a0,a1) in self.regmap:
            assert addr < a0 or addr >= a1
        assert name not in self.regidx

        self.regmap[(addr, addr+length)] = (name, length, readonly, [default]*length)
        self.regidx[name] = (addr, addr+length)

    def read(self, addr):
        assert addr >= 0 and addr <= 65536
        for (a0, a1) in self.regmap:
            if addr >= a0 and addr < a1:
                (name, length, readonly, data) = self.regmap[(a0, a1)]
                offset = addr-a0
                return True, data[offset]
        return False, 0

    def write(self, addr, byte):
        assert addr >= 0 and addr <= 65536
        for (a0, a1) in self.regmap:
            if addr >= a0 and addr < a1:
                (name, length, readonly, data) = self.regmap[(a0, a1)]
                if not readonly:
                    offset = addr-a0
                    data[offset] = byte

    def getRegB(self, name):
        (a0, a1) = self.regidx[name]
        (name, length, readonly, data) = self.regmap[(a0, a1)]
        return data

    def getRegI(self, name):
        (a0, a1) = self.regidx[name]
        (name, length, readonly, data) = self.regmap[(a0, a1)]
        m, v = 1, 0
        for i in xrange(length):
            v = v + m * data[i]
            m = m * 0x100
        return v

    def setRegI(self, name, datain):
        (a0, a1) = self.regidx[name]
        (name, length, readonly, data) = self.regmap[(a0, a1)]
        data = []
        for i in xrange(length):
            data.append(datain & 0xFF)
            datain = datain >> 8 
        self.regmap[(a0, a1)] = (name, length, readonly, data)

    def setRegB(self, name, datain):
        (a0, a1) = self.regidx[name]
        (name, length, readonly, data) = self.regmap[(a0, a1)]
        assert len(datain) == length
        self.regmap[(a0, a1)] = (name, length, readonly, datain)

