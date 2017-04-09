# A simple simulator for SHA+XRAM

from mmio import mmiodev, NOP, RD, WR
import sha as SHAFunc

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

class SHA(mmiodev):
    SHA_IDLE = 0
    SHA_RD   = 1
    SHA_OP1  = 2
    SHA_OP2  = 3
    SHA_WR   = 4

    def __init__(self):
        mmiodev.__init__(self)
        self.addReg('sha_start', 0xfe00, 1, readonly=True)
        self.addReg('sha_state', 0xfe01, 1, readonly=True)
        self.addReg('sha_rdaddr', 0xfe02, 2)
        self.addReg('sha_wraddr', 0xfe04, 2)
        self.addReg('sha_len', 0xfe06, 2)

        self.bytes_read = 0
        self.rd_data  = [0] * 64
        self.hs_data  = [0] * 20

        self.sha = SHAFunc.new()

        # Create easy access properties.
    sha_state  = property(lambda s: s.getRegI('sha_state'), lambda s, v: s.setRegI('sha_state', v))
    sha_rdaddr = property(lambda s: s.getRegI('sha_rdaddr'), lambda s, v: s.setRegI('sha_rdaddr', v))
    sha_wraddr = property(lambda s: s.getRegI('sha_wraddr'), lambda s, v: s.setRegI('sha_wraddr', v))
    sha_len    = property(lambda s: s.getRegI('sha_len'), lambda s, v: s.setRegI('sha_len', v))

    def simulate(self, s_in):
        cmd     = s_in['cmd']
        cmdaddr = s_in['cmdaddr']
        cmddata = s_in['cmddata']

        self.sha_state  = s_in['sha_state']
        self.sha_rdaddr = s_in['sha_rdaddr']
        self.sha_wraddr = s_in['sha_wraddr']
        self.sha_len    = s_in['sha_len']
        self.bytes_read = s_in['sha_bytes_read']
        self.rd_data    = s_in['sha_rd_data']
        self.hs_data    = s_in['sha_hs_data']
        self.xram       = s_in['XRAM']

        # default dataout.
        dataout = 0;
        # execute command.
        started = False
        if cmd == RD:
            found, data = self.read(cmdaddr)
            if found:
                dataout = data
        elif cmd == WR and self.sha_state == self.SHA_IDLE:
            if cmdaddr == 0xfe00:
                if cmddata == 1:
                    self.sha_state = self.SHA_RD
                    self.bytes_read = 0
                    started = True
            else:
                self.write(cmdaddr, cmddata)

        # do the operations.
        if not started and self.sha_state == self.SHA_RD:
            self.rd_data = 0
            for i in xrange(64):
                addr = (self.sha_rdaddr + self.bytes_read + 63 - i) & 0xffff
                byte = self.xram[addr]
                self.rd_data |= byte << (i*8)
            self.bytes_read = self.bytes_read + 64
            self.sha_state = self.SHA_OP1
        elif not started and self.sha_state == self.SHA_OP1:
            self.sha_state = self.SHA_OP2
        elif not started and self.sha_state == self.SHA_OP2:
            if self.bytes_read < self.sha_len: # Need more blk
                self.sha_state = self.SHA_RD
            else:
                self.sha_state = self.SHA_WR
            bytes_in = bytes(''.join(as_chars(self.rd_data, 64)))
            self.sha.update(bytes_in)
            res = self.sha.digest()
            self.hs_data = to_num(res, 20)
        elif not started and self.sha_state == self.SHA_WR:
            for i in xrange(20):
                addr = (self.sha_wraddr + 19 - i) & 0xffff
                byte = (self.hs_data >> (i*8)) & 0xff
                self.xram[addr] = byte
            self.sha_state = self.SHA_IDLE

        s_out = self.s_dict()
        s_out['dataout'] = dataout
        return s_out

    def s_dict(self):
        return {
            'sha_state'     : self.sha_state,
            'sha_rdaddr'    : self.sha_rdaddr,
            'sha_wraddr'    : self.sha_wraddr,
            'sha_len'       : self.sha_len,
            'sha_bytes_read': self.bytes_read,
            'sha_rd_data'   : self.rd_data,
            'sha_hs_data'   : self.hs_data,
            'XRAM'          : self.xram
        }

def testSHA():
    sha = SHA()
    sha.sha_state = 0
    assert sha.sha_state == 0

    s_in = sha.s_dict()
    s_in['cmd'] = WR
    s_in['cmdaddr'] = 0xfe06
    s_in['cmddata'] = 128
    s_out = sha.simulate(s_in)
    assert s_out['sha_len'] == 128

    s_in = sha.s_dict()
    s_in['cmd'] = RD
    s_in['cmdaddr'] = 0xfe06
    s_in['cmddata'] = 3
    s_out = sha.simulate(s_in)
    assert s_out['dataout'] == 128

if __name__ == '__main__':
    testSHA()

