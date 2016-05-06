import ila
from collections import namedtuple

class uc8051(object):
    def __init__(self):
        self.model = ila.Abstraction("oc8051")
        self.createInputs()
        
        self.op0 = self.rom[self.pc]
        self.op1 = self.rom[self.pc+1]
        self.op2 = self.rom[self.pc+2]
        self.opcode = ila.concat(
                        self.op2, 
                            ila.concat(
                                self.op1, 
                                    self.op0))

        self.dptr = ila.concat(self.dph, self.dpl)
        self.cy = self.psw[7:7]
        self.ac = self.psw[6:6]
        self.ov = self.psw[2:2]
        self._Rbank = self.psw[4:3]
        self.rxaddr = [
            ila.concat(self.model.const(0, 3), 
                ila.concat(self._Rbank, 
                    self.model.const(i, 3))) 
                        for i in xrange(8)]
        self.rx = [self.iram[RxAddr_i] for RxAddr_i in self.rxaddr]

    def createInputs(self):
        self.pc = self.model.reg('PC', 16)
        # code memory.
        self.rom = self.model.mem('ROM', 16, 8)
        # IRAM
        self.iram = self.model.mem('IRAM', 8, 8)
        # main SFRs
        self.acc = self.model.reg('ACC', 8)
        self.b = self.model.reg('B', 8)
        self.psw = self.model.reg('PSW', 8)
        self.sp = self.model.reg('SP', 8)
        self.dpl = self.model.reg('DPL', 8)
        self.dph = self.model.reg('DPH', 8)
        # ports
        self.p0 = self.model.reg('P0', 8)
        self.p1 = self.model.reg('P1', 8)
        self.p2 = self.model.reg('P2', 8)
        self.p3 = self.model.reg('P3', 8)
        # misc SFRs.
        self.pcon = self.model.reg('PCON', 8)
        self.tcon = self.model.reg('TCON', 8)
        self.tmod = self.model.reg('TMOD', 8)
        self.tl0 = self.model.reg('TL0', 8)
        self.th0 = self.model.reg('TH0', 8)
        self.tl1 = self.model.reg('TL1', 8)
        self.th1 = self.model.reg('TH1', 8)
        self.scon = self.model.reg('SCON', 8)
        self.sbuf = self.model.reg('SBUF', 8)
        self.ie = self.model.reg('IE', 8)
        self.ip = self.model.reg('IP', 8)
        # XRAM
        self.xram_data_in = self.model.reg('XRAM_DATA_IN', 8)
        self.xram_data_out = self.model.reg('XRAM_DATA_OUT', 8)
        self.xram_addr = self.model.reg('XRAM_ADDR', 16)

    def readDirect(self, addr):
        msb0 = addr[7:7] == 0 
        expr = ila.ite(msb0, self.iram[addr],
            ila.ite(addr == 0x80, self.p0,
            ila.ite(addr == 0x81, self.sp,
            ila.ite(addr == 0x82, self.dpl,
            ila.ite(addr == 0x83, self.dph,
            ila.ite(addr == 0x87, self.pcon,
            ila.ite(addr == 0x88, self.tcon,
            ila.ite(addr == 0x89, self.tmod,
            ila.ite(addr == 0x8a, self.tl0,
            ila.ite(addr == 0x8c, self.th0,
            ila.ite(addr == 0x8b, self.tl1,
            ila.ite(addr == 0x8d, self.th1,
            ila.ite(addr == 0x90, self.p1,
            ila.ite(addr == 0x98, self.scon,
            ila.ite(addr == 0x99, self.sbuf,
            ila.ite(addr == 0xa0, self.p2,
            ila.ite(addr == 0xa8, self.ie,
            ila.ite(addr == 0xb0, self.p3,
            ila.ite(addr == 0xb8, self.ip,
            ila.ite(addr == 0xd0, self.psw,
            ila.ite(addr == 0xe0, self.acc,
            ila.ite(addr == 0xf0, self.b,
            self.model.const(0, 8)))))))))))))))))))))))
        return expr

    def readBit(self, bitaddr):
        msb1 = bitaddr[7:7] == 1
        byteaddr = ila.ite(msb1, 
            ila.concat(bitaddr[7:3], self.model.const(0, 3)), 
            ila.zero_extend(bitaddr[7:3], 8) + 32)
        bitindex = bitaddr[2:0]
        byte = self.readDirect(byteaddr)
        bit = byte[bitindex]
        return bit

    def writeBit(self, bitaddr, bitval):
        # FIXME
        msb1 = bitaddr[7:7] == 1
        byteaddr = ila.ite(msb1, 
            ila.concat(bitaddr[7:3], self.model.const(0, 3)), 
            ila.zero_extend(bitaddr[7:3], 8) + 32)
        byte = self.readDirect(byteaddr)
        bitindex = ila.zero_extend(bitaddr[2:0], 8)
        mask1 = ~(self.model.const(1, 8) << bitindex)
        mask2 = ila.zero_extend(bitval, 8) << bitindex
        byte_p = (mask1 & byte) | mask2
        return self.writeDirect(byteaddr, byte_p)

    def writeDirect(self, addr, data):
        # FIXME
        fields = [ 
            'iram', 'p0', 'sp', 'dpl', 'dph', 'pcon'
            'tcon', 'tmod', 'tl0', 'th0', 'tl1', 'th1', 
            'p1', 'scon', 'sbuf', 'p2', 'ie', 
            'p3', 'ip', 'psw', 'acc', 'b'
        ]
        r = namedtuple('MemMapState', fields)
        r.iram = ila.ite(addr[7:7] == 0, ila.store(self.iram, addr, data), self.iram)
        r.p0   = ila.ite(addr == 0x80, data, self.p0)
        r.sp   = ila.ite(addr == 0x81, data, self.sp)
        r.dpl  = ila.ite(addr == 0x82, data, self.dpl)
        r.dph  = ila.ite(addr == 0x83, data, self.dph)
        r.pcon = ila.ite(addr == 0x87, data, self.pcon)
        r.tcon = ila.ite(addr == 0x88, data, self.tcon)
        r.tmod = ila.ite(addr == 0x89, data, self.tmod)
        r.tl0  = ila.ite(addr == 0x8a, data, self.tl0)
        r.th0  = ila.ite(addr == 0x8c, data, self.th0)
        r.tl1  = ila.ite(addr == 0x8b, data, self.tl1)
        r.th1  = ila.ite(addr == 0x8d, data, self.th1)
        r.p1   = ila.ite(addr == 0x90, data, self.p1)
        r.scon = ila.ite(addr == 0x98, data, self.scon)
        r.sbuf = ila.ite(addr == 0x99, data, self.sbuf)
        r.p2   = ila.ite(addr == 0xa0, data, self.p2)
        r.ie   = ila.ite(addr == 0xa8, data, self.ie)
        r.p3   = ila.ite(addr == 0xb0, data, self.p3)
        r.ip   = ila.ite(addr == 0xb8, data, self.ip)
        r.psw  = ila.ite(addr == 0xd0, data, self.psw)
        r.acc  = ila.ite(addr == 0xe0, data, self.acc)
        r.b    = ila.ite(addr == 0xf0, data, self.b)
        return r

    
