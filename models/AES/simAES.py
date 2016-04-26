# A simple simulator for the external memory, AES and SHA modules.
import sys
from Crypto.Cipher import AES
from Crypto.Hash import SHA
from collections import defaultdict


def array2int(data, length):
    m, v = 1, 0
    for i in xrange(length):
        v = v + m * data[i]
        m = m * 0x100
    return v

def int2array(datain, length):
    data = []
    for i in xrange(length):
        data.append(datain & 0xFF)
        datain = datain >> 8 
    return data

class XMM(object):
    STEP_NONE = 0
    STEP_AES  = 1
    STEP_SHA  = 2
    STEP_BOTH = 3
    RD        = 4
    WR        = 8

    AES_IDLE = 0
    AES_RD   = 1
    AES_OP   = 2
    AES_WR   = 3

    SHA_IDLE = 0
    SHA_RD   = 1
    SHA_OP   = 2
    SHA_WR   = 3

    def __init__(self):
        self.regmap = {}
        self.regidx = {}
        self.addReg('aes_start', 0xff00, 1, readonly=True)
        self.addReg('aes_state', 0xff01, 1, readonly=True)
        self.addReg('aes_addr', 0xff02, 2)
        self.addReg('aes_len', 0xff04, 2)
        self.addReg('aes_reserved_1', 0xff06, 10, readonly=True)
        self.addReg('aes_ctr', 0xff10, 0x10)
        self.addReg('aes_key0', 0xff20, 0x10)
        self.addReg('aes_key1', 0xff30, 0x10)

        self.aes_bytes_processed = 0
        self.aes_read_data = [0] * 16
        self.aes_enc_data  = [0] * 16

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
                return data[offset]
        
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

    def write(self, addr, datain):
        assert addr >= 0 and addr <= 65536
        assert datain >=0 and datain <= 256

        for (a0, a1) in self.regmap:
            if addr >= a0 and addr < a1:
                (name, length, readonly, data) = self.regmap[(a0, a1)]

                if readonly: 
                    if addr == 0xff00 and self.getRegI('aes_state') == XMM.AES_IDLE and (datain % 2) == 1:
                        self.setRegI('aes_state', XMM.AES_RD)
                        self.aes_bytes_processed = 0
                    elif addr == 0xfe00 and self.getRegI('sha_state') == XMM.SHA_IDLE and (datain % 2) == 1:
                        self.setRegI('sha_state', XMM.SHA_RD)
                        self.sha_bytes_processed = 0
                        self.sha_digest = [0]*20
                    return
                else:
                    # no writes when in operation.
                    if addr >= 0xff00 and addr < 0xff40 and self.getRegI('aes_state') != XMM.AES_IDLE:
                        return
                    if addr >= 0xfe00 and addr < 0xfe10 and self.getRegI('sha_state') != XMM.SHA_IDLE:
                        return

                    offset = addr-a0
                    data[offset] = datain
                    self.regmap[(a0, a1)] = (name, length, readonly, data)
                    return
        self.xram[addr] = datain

    def aes_step(self):
        aes_state = self.getRegI('aes_state')
        aes_addr = self.getRegI('aes_addr')
        if aes_state == XMM.AES_RD:
            self.aes_read_data = [self.xram[(i+aes_addr+self.aes_bytes_processed) & 0xFFFF] for i in xrange(16)]
            self.setRegI('aes_state', XMM.AES_OP)
        elif aes_state == XMM.AES_OP:
            aes_bytes_in = bytes(''.join([chr(ci) for ci in self.aes_read_data]))
            aes_ctr = lambda: bytes(''.join([chr(ci) for ci in self.getRegB('aes_ctr')]))
            aes_key = bytes(''.join([chr(ci) for ci in self.getRegB('aes_key0')]))
            aes = AES.new(key=aes_key, mode=AES.MODE_CTR, counter=aes_ctr)
            self.aes_enc_data = [ord(a) for a in aes.encrypt(aes_bytes_in)]
            self.setRegI('aes_state', XMM.AES_WR)

            assert len(self.aes_read_data) == 16
            assert len(aes_bytes_in) == 16
            assert len(aes_ctr()) == 16
            assert len(aes_key) == 16
            assert len(self.aes_enc_data) == 16

        elif aes_state == XMM.AES_WR:
            assert len(self.aes_read_data) == 16
            assert len(self.aes_enc_data) == 16

            for i in xrange(16):
                addr = (aes_addr + i + self.aes_bytes_processed) & 0xFFFF
                self.xram[addr] = self.aes_enc_data[i]
            self.aes_bytes_processed += 16
            self.aes_bytes_processed &= 0xFFFF
            if self.aes_bytes_processed < self.getRegI('aes_len'):
                self.setRegI('aes_state', XMM.AES_RD)
            else:
                self.setRegI('aes_state', XMM.AES_IDLE)
        else:
            assert aes_state == XMM.AES_IDLE


    def sha_step(self):
        sha_state = self.getRegI('sha_state')
        sha_rdaddr = self.getRegI('sha_rdaddr')
        sha_wraddr = self.getRegI('sha_wraddr')
        sha_len = self.getRegI('sha_len')

        if sha_state == XMM.SHA_RD:
            self.sha_read_data = [self.xram[(i+sha_rdaddr+self.sha_bytes_processed)&0xFFFF] for i in xrange(64)]
            self.setRegI('sha_state', XMM.SHA_OP)
        elif sha_state == XMM.SHA_OP:
            assert len(self.sha_digest) == 20

            sha_bytes_in = bytes(''.join([chr(c) for c in self.sha_digest + self.sha_read_data]))
            h = SHA.new()
            h.update(sha_bytes_in)
            self.sha_digest = [ord(a) for a in h.digest()]
            self.sha_bytes_processed += 64
            self.sha_bytes_processed &= 0xFFFF

            if self.sha_bytes_processed < sha_len:
                self.setRegI('sha_state', XMM.SHA_RD)
            else:
                self.setRegI('sha_state', XMM.SHA_WR)

            assert len(self.sha_read_data) == 64
            assert len(sha_bytes_in) == (64 + 20)
            assert len(self.sha_digest) == 20
        elif sha_state == XMM.SHA_WR:
            assert len(self.sha_digest) == 20
            for i in xrange(20):
                addr = (i + sha_wraddr) & 0xFFFF
                self.xram[addr] = self.sha_digest[i]
            self.setRegI('sha_state', XMM.SHA_IDLE)

        else:
            assert sha_state == XMM.SHA_IDLE
                        
    def operate(self, op, addr, datain):
        rv = 0
        if (op & 0xc) == XMM.RD:
            rv = self.read(addr)
        step = op & 0x3

        assert step == XMM.STEP_NONE or step == XMM.STEP_AES or step == XMM.STEP_SHA or step == XMM.STEP_BOTH
        if step == XMM.STEP_AES or step == XMM.STEP_BOTH:
            self.aes_step()
        if step == XMM.STEP_SHA or step == XMM.STEP_BOTH:
            self.sha_step()

        if (op & 0xc) == XMM.WR:
            assert rv == 0
            self.write(addr, datain)

        return rv
    def compressXRAM(self):
        numCounts = defaultdict(int)
        assert len(self.xram) == 65536

        for v in self.xram:
            numCounts[v] += 1

        maxCnt = 0
        maxKey = 0
        for k,c in numCounts.iteritems():
            if c > maxCnt:
                maxCnt = c
                maxKey = k

        ram = []
        for i, v in enumerate(self.xram):
            if v != maxKey:
                ram.append([i,v])
        ram.append(maxKey)
        return ram
        
    def decompressXRAM(self, ram):
        assert len(self.xram) == 65536
        for i in xrange(65536):
            self.xram[i] = ram[-1]

        for [a,v] in ram[:-1]:
            self.xram[a] = v

    regs = [
        'aes_state', 'aes_addr', 'aes_len', 
        'sha_state', 'sha_rdaddr', 'sha_wraddr', 'sha_len',
        'aes_ctr', 'aes_key0', 'aes_key1',
    ]

    def writeState(self, state_in):
        for r in XMM.regs:
            self.setRegI(r, state_in[r])

        self.aes_bytes_processed = state_in['aes_bytes_processed']
        self.aes_read_data = int2array(state_in['aes_read_data'], 16)
        self.aes_enc_data = int2array(state_in['aes_enc_data'], 16)
        self.sha_bytes_processed = state_in['sha_bytes_processed']
        self.sha_read_data = int2array(state_in['sha_read_data'], 64)
        self.sha_digest = int2array(state_in['sha_digest'], 20)
        self.decompressXRAM(state_in['xram'])

    def readState(self, state_out):
        for r in XMM.regs:
            state_out[r] = self.getRegI(r)

        state_out['aes_bytes_processed'] = self.aes_bytes_processed
        state_out['aes_read_data'] = array2int(self.aes_read_data, 16)
        state_out['aes_enc_data'] = array2int(self.aes_enc_data, 16)
        state_out['sha_bytes_processed'] = self.sha_bytes_processed
        state_out['sha_read_data'] = array2int(self.sha_read_data, 64)
        state_out['sha_digest'] = array2int(self.sha_digest, 20)
        state_out['xram'] = self.compressXRAM()

def evalXMM(op, addrin, datain, state_in, state_out):
    xmm = XMM()
    xmm.writeState(state_in)
    dataout = xmm.operate(op, addrin, datain)
    xmm.readState(state_out)
    return dataout

def test(argv):
    xmm = XMM()
    xmm.operate(XMM.WR, 0xfe03, 0x10)
    xmm.setRegB('aes_ctr', range(16))
    xmm.setRegI('sha_len', 0x100)
    assert xmm.getRegB('sha_rdaddr') == [0, 0x10]
    assert xmm.getRegI('sha_rdaddr') == 0x1000
    assert xmm.operate(XMM.RD, 0xfe03, 0) == 0x10
    assert xmm.getRegB('aes_ctr') == range(16)
    for i in xrange(16):
        assert xmm.operate(XMM.RD, 0xff10+i, 1) == i
    assert xmm.operate(XMM.RD, 0xfe06, 0) == 0
    assert xmm.operate(XMM.RD, 0xfe07, 0) == 1
    for i in xrange(16):
        xmm.operate(XMM.WR, 0xff20+i, i+1)
    xmm.operate(XMM.WR, 0xff02, 0x00)
    xmm.operate(XMM.WR, 0xff03, 0x10)
    xmm.operate(XMM.WR, 0xff04, 0x20)
    xmm.operate(XMM.WR, 0xff05, 0x00)

    for i in xrange(0x20):
        xmm.operate(XMM.WR, 0x1000+i, 65+i)

    xmm.operate(XMM.WR, 0xff00, 1)
    assert xmm.operate(XMM.RD, 0xff01, 1) == XMM.AES_RD

    xmm.operate(XMM.STEP_BOTH, 0, 0)
    assert xmm.operate(XMM.RD, 0xff01, 1) == XMM.AES_OP

    xmm.operate(XMM.STEP_BOTH, 0, 0)
    assert xmm.operate(XMM.RD, 0xff01, 1) == XMM.AES_WR

    xmm.operate(XMM.STEP_BOTH, 0, 0)
    assert xmm.operate(XMM.RD, 0xff01, 1) == XMM.AES_RD

    xmm.operate(XMM.STEP_BOTH, 0, 0)
    assert xmm.operate(XMM.RD, 0xff01, 1) == XMM.AES_OP

    xmm.operate(XMM.STEP_BOTH, 0, 0)
    assert xmm.operate(XMM.RD, 0xff01, 1) == XMM.AES_WR

    xmm.operate(XMM.STEP_BOTH, 0, 0)
    assert xmm.operate(XMM.RD, 0xff01, 1) == XMM.AES_IDLE

    data = []
    for i in xrange(0x20):
        data.append(xmm.operate(XMM.RD, 0x1000+i, 65+i))
    print data

    xmm.operate(XMM.WR, 0xff00, 1)
    while xmm.operate(XMM.RD, 0xff01, 0) != XMM.AES_IDLE:
        xmm.operate(XMM.STEP_BOTH, 0, 0)

    for i in xrange(0x20):
        assert xmm.operate(XMM.RD, 0x1000+i, 0) == 65+i

    assert xmm.getRegI('sha_state') == XMM.SHA_IDLE
    xmm.operate(XMM.WR, 0xfe02, 00)
    xmm.operate(XMM.WR, 0xfe03, 0x10)
    xmm.operate(XMM.WR, 0xfe04, 00)
    xmm.operate(XMM.WR, 0xfe05, 0x20)
    xmm.operate(XMM.WR, 0xfe06, 40)
    xmm.operate(XMM.WR, 0xfe07, 00)

    assert xmm.getRegI('sha_rdaddr') == 0x1000
    assert xmm.getRegI('sha_wraddr') == 0x2000

    for i in xrange(0x40):
        xmm.operate(XMM.WR, 0x1000+i, i)

    xmm.operate(XMM.WR, 0xfe00, 1)
    assert xmm.operate(XMM.RD, 0xfe01, 0) == XMM.SHA_RD

    while xmm.operate(XMM.RD, 0xfe01, 0) != XMM.SHA_IDLE:
        xmm.operate(XMM.STEP_BOTH, 0, 0)

    data = []
    for i in xrange(20):
        data.append(xmm.operate(XMM.RD, 0x2000+i, 0))

if __name__ == '__main__':
    test(sys.argv)

