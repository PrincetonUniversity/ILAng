import ila

class uc8051(object):
    def __init__(self):
        self.model = ila.Abstraction()
        self.createInputs()
        
        self.op0 = self.rom[self.pc]
        self.op1 = self.rom[self.pc+1]
        self.op2 = self.rom[self.pc+2]
        self.opcode = ila.concat(
                        self.op2, 
                            ila.concat(
                                self.op1, 
                                    self.op0))

        self.cy = self.psw[7:7]
        self.ac = self.psw[6:6]
        self.ov = self.psw[2:2]
        self._Rbank = self.psw[4:3]
        self.RxAddr = [
            ila.concat(self.model.const(0, 3), 
                ila.concat(self._Rbank, 
                    self.model.const(i, 3))) 
                        for i in xrange(8)]
        self.Rx = [self.iram[RxAddr_i] for RxAddr_i in self.RxAddr]

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

    def readDirect(self, addr):
        msb0 = addr[7:7] == 0 
        expr = ila.ite(msb0, self.IRAM[addr],
            ila.ite(addr == 0x80, self.P0,
            ila.ite(addr == 0x81, self.SP,
            ila.ite(addr == 0x82, self.DPL,
            ila.ite(addr == 0x83, self.DPH,
            ila.ite(addr == 0x87, self.PCON,
            ila.ite(addr == 0x88, self.TCON,
            ila.ite(addr == 0x89, self.TMOD,
            ila.ite(addr == 0x8A, self.TL0,
            ila.ite(addr == 0x8C, self.TH0,
            ila.ite(addr == 0x8B, self.TL1,
            ila.ite(addr == 0x8D, self.TH1,
            ila.ite(addr == 0x90, self.P1,
            ila.ite(addr == 0x98, self.SCON,
            ila.ite(addr == 0x99, self.SBUF,
            ila.ite(addr == 0xA0, self.P2,
            ila.ite(addr == 0xA8, self.IE,
            ila.ite(addr == 0xB0, self.P3,
            ila.ite(addr == 0xB8, self.IP,
            ila.ite(addr == 0xD0, self.PSW,
            ila.ite(addr == 0xE0, self.ACC,
            ila.ite(addr == 0xF0, self.B,
            self.model.const(0, 8)))))))))))))))))))))))
        return expr

    def readBit(self, bitaddr):
        msb1 = bitaddr[7:7] == 1
        byteaddr = ila.ite(msb1, 
            ila.concat(bitaddr[7:3], self.model.const(0, 3)), 
            ila.zero_extend(bitaddr, 8) + 32)
        bitindex = bitaddr[2:0]
        byte = self.readDirect(byteaddr)
        bit = byte[bitindex]
        return bit

    def writeBit(self, bitaddr, bitval):
        # FIXME
        msb1 = Equal(Extract(7, 7, bitaddr), BitVecVal(1, 1))
        byteaddr = If(msb1, 
            Concat(Extract(7, 3, bitaddr), BitVecVal(0, 3)), 
            Add(ZeroExt(Extract(7, 3, bitaddr), 3), BitVecVal(32, 8)))
        byte = self.readDirect(byteaddr)
        bitindex = ZeroExt(Extract(2, 0, bitaddr), 5)
        # put a 0 in the right position with 1s elsewhere.
        mask1 = Complement(LShift(BitVecVal(1, 8), bitindex))
        # put the bit value in the correct position with 0s elsewhere
        mask2 = LShift(ZeroExt(bitval, 7), bitindex)
        byte_p = BVOr(BVAnd(mask1, byte), mask2)
        return self.writeDirect(byteaddr, byte_p)

    def writeDirect(self, addr, data):
        # FIXME
        ctxp = self.clone()
        ctxp.IRAM = If(Equal(Extract(7, 7, addr), BitVecVal(0, 1)), 
            WriteMem(self.IRAM, addr, data), self.IRAM)
        ctxp.P0   = If(Equal(addr, BitVecVal(0x80, 8)), data, self.P0)
        ctxp.SP   = If(Equal(addr, BitVecVal(0x81, 8)), data, self.SP)
        ctxp.DPL  = If(Equal(addr, BitVecVal(0x82, 8)), data, self.DPL)
        ctxp.DPH  = If(Equal(addr, BitVecVal(0x83, 8)), data, self.DPH)
        ctxp.PCON = If(Equal(addr, BitVecVal(0x87, 8)), data, self.PCON)
        ctxp.TCON = If(Equal(addr, BitVecVal(0x88, 8)), data, self.TCON)
        ctxp.TMOD = If(Equal(addr, BitVecVal(0x89, 8)), data, self.TMOD)
        ctxp.TL0  = If(Equal(addr, BitVecVal(0x8A, 8)), data, self.TL0)
        ctxp.TH0  = If(Equal(addr, BitVecVal(0x8C, 8)), data, self.TH0)
        ctxp.TL1  = If(Equal(addr, BitVecVal(0x8B, 8)), data, self.TL1)
        ctxp.TH1  = If(Equal(addr, BitVecVal(0x8D, 8)), data, self.TH1)
        ctxp.P1   = If(Equal(addr, BitVecVal(0x90, 8)), data, self.P1)
        ctxp.SCON = If(Equal(addr, BitVecVal(0x98, 8)), data, self.SCON)
        ctxp.SBUF = If(Equal(addr, BitVecVal(0x99, 8)), data, self.SBUF)
        ctxp.P2   = If(Equal(addr, BitVecVal(0xA0, 8)), data, self.P2)
        ctxp.IE   = If(Equal(addr, BitVecVal(0xA8, 8)), data, self.IE)
        ctxp.P3   = If(Equal(addr, BitVecVal(0xB0, 8)), data, self.P3)
        ctxp.IP   = If(Equal(addr, BitVecVal(0xB8, 8)), data, self.IP)
        ctxp.PSW  = If(Equal(addr, BitVecVal(0xD0, 8)), data, self.PSW)
        ctxp.ACC  = If(Equal(addr, BitVecVal(0xE0, 8)), data, self.ACC)
        ctxp.B    = If(Equal(addr, BitVecVal(0xF0, 8)), data, self.B)
        return ctxp

    
