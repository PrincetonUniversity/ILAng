# A simple simulator for AES+XRAM

from mmio import mmiodev, NOP, RD, WR
from Crypto.Cipher import AES as AESFactory
import ila

def as_chars(s, n):
    b = []
    for i in xrange(n):
        byte = s & 0xff
        s >>= 8
        b.append(byte)
    return [chr(i) for i in b]
def to_num(s, n):
    num = 0
    for i in xrange(n):
        num |= (ord(s[i]) << (i * 8))
    return num

class AES(mmiodev):
    AES_IDLE = 0
    AES_RD   = 1
    AES_OP   = 2
    AES_WR   = 3

    def __init__(self):
        mmiodev.__init__(self)
        self.addReg('aes_start', 0xff00, 1, readonly=True)
        self.addReg('aes_state', 0xff01, 1, readonly=True)
        self.addReg('aes_addr', 0xff02, 2)
        self.addReg('aes_len', 0xff04, 2)
        self.addReg('aes_keysel', 0xff06, 1)
        self.addReg('aes_ctr', 0xff10, 0x10)
        self.addReg('aes_key0', 0xff20, 0x10)
        self.addReg('aes_key1', 0xff30, 0x10)

        self.byte_cnt = 0
        self.rd_data = [0] * 16
        self.enc_data  = [0] * 16

    # create easy access properties.
    aes_state   = property(lambda s: s.getRegI('aes_state'), lambda s, v: s.setRegI('aes_state', v))
    aes_addr    = property(lambda s: s.getRegI('aes_addr'), lambda s, v: s.setRegI('aes_addr', v))
    aes_len     = property(lambda s: s.getRegI('aes_len'), lambda s, v: s.setRegI('aes_len', v))
    aes_keysel  = property(lambda s: s.getRegI('aes_keysel'), lambda s, v: s.setRegI('aes_keysel', v))
    aes_ctr     = property(lambda s: s.getRegI('aes_ctr'), lambda s, v: s.setRegI('aes_ctr', v))
    aes_key0    = property(lambda s: s.getRegI('aes_key0'), lambda s, v: s.setRegI('aes_key0', v))
    aes_key1    = property(lambda s: s.getRegI('aes_key1'), lambda s, v: s.setRegI('aes_key1', v))

    def get(self, s, name, default):
        if name in s:
            return s[name]
        else:
            return default

    def simulate(self, s_in):
        cmd     = s_in['cmd']
        cmdaddr = s_in['cmdaddr']
        cmddata = s_in['cmddata']

        self.aes_state  = s_in['aes_state']
        self.aes_addr   = s_in['aes_addr']
        self.aes_len    = s_in['aes_len']
        self.aes_keysel = s_in['aes_keysel']
        self.aes_ctr    = s_in['aes_ctr']
        self.aes_key0   = s_in['aes_key0']
        self.aes_key1   = s_in['aes_key1']
        self.byte_cnt   = s_in['byte_cnt']
        self.rd_data    = self.get(s_in,'rd_data', 0)
        self.enc_data   = self.get(s_in,'enc_data', 0)
        self.xram       = self.get(s_in,'XRAM', ila.MemValues(16, 8, 0x0))

        # default dataout.
        dataout = 0
        # execute command.
        started = False
        if cmd == RD:
            found, data = self.read(cmdaddr)
            if found: 
                dataout = data
        elif cmd == WR and self.aes_state == 0:
            if cmdaddr == 0xff00:
                if cmddata == 1:
                    self.aes_state = 1
                    self.byte_cnt  = 0
                    started = True
            else:
                self.write(cmdaddr, cmddata)

        # do the operations.
        if not started and self.aes_state == 1:
            self.rd_data = 0
            for i in xrange(16):
                addr = (self.aes_addr + i + self.byte_cnt) & 0xffff
                byte = self.xram[addr]
                self.rd_data |= byte << (i*8)
            self.aes_state = 2
        elif not started and self.aes_state == 2:
            aes_key = self.aes_key0 if self.aes_keysel == 0 else self.aes_key1
            aes_bytes_in = bytes(''.join(as_chars(self.rd_data, 16)))
            aes_ctr = lambda: bytes(''.join(as_chars(self.aes_ctr, 16)))
            aes_key = bytes(''.join(as_chars(aes_key, 16)))
            aes = AESFactory.new(key=aes_key, mode=AESFactory.MODE_CTR, counter=aes_ctr)
            self.enc_data = to_num(aes.encrypt(aes_bytes_in), 16)
            self.aes_state = 3
            pass
        elif not started and self.aes_state == 3:
            for i in xrange(16):
                addr = (self.aes_addr + i + self.byte_cnt) & 0xffff
                byte = (self.enc_data >> (i*8)) & 0xff
                self.xram[addr] = byte

            self.byte_cnt = (self.byte_cnt + 16) & 0xffff
            if self.byte_cnt < self.aes_len:
                self.aes_state = 1
            else:
                self.aes_state = 0
        s_out = self.s_dict()
        s_out['dataout'] = dataout
        return s_out

    def s_dict(self):
        return {
            'aes_state'     : self.aes_state,
            'aes_addr'      : self.aes_addr,
            'aes_len'       : self.aes_len,
            'aes_keysel'    : self.aes_keysel,
            'aes_ctr'       : self.aes_ctr,
            'aes_key0'      : self.aes_key0,
            'aes_key1'      : self.aes_key1,
            'byte_cnt'      : self.byte_cnt,
            'rd_data'       : self.rd_data,
            'enc_data'      : self.enc_data,
            'XRAM'          : self.xram
        }

def testAES():
    aes = AES()
    aes.aes_state = 2
    assert 2 == aes.aes_state

    s_in = aes.s_dict()
    s_in['cmd'] =  RD
    s_in['cmdaddr'] = 0xff01
    s_in['cmddata'] = 0x0
    s_out = aes.simulate(s_in)
    assert s_out['dataout'] == 2

    aes.aes_state = 0
    s_in = aes.s_dict()
    s_in['cmd'] = WR
    s_in['cmdaddr'] = 0xff10
    s_in['cmddata'] = 0xff
    s_out = aes.simulate(s_in)
    assert s_out['aes_ctr'] == 0xff

if __name__ == '__main__':
    testAES()

