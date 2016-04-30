# A simple simulator for AES+XRAM

from mmio import mmiodev, NOP, RD, WR

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

        self.aes_bytes_processed = 0
        self.aes_read_data = [0] * 16
        self.aes_enc_data  = [0] * 16

    # create easy access properties.
    aes_state   = property(lambda s: s.getRegI('aes_state'), lambda s, v: s.setRegI('aes_state', v))
    aes_addr    = property(lambda s: s.getRegI('aes_addr'), lambda s, v: s.setRegI('aes_addr', v))
    aes_len     = property(lambda s: s.getRegI('aes_len'), lambda s, v: s.setRegI('aes_len', v))
    aes_keysel  = property(lambda s: s.getRegI('aes_keysel'), lambda s, v: s.setRegI('aes_keysel', v))
    aes_ctr     = property(lambda s: s.getRegI('aes_ctr'), lambda s, v: s.setRegI('aes_ctr', v))
    aes_key0    = property(lambda s: s.getRegI('aes_key0'), lambda s, v: s.setRegI('aes_key0', v))
    aes_key1    = property(lambda s: s.getRegI('aes_key1'), lambda s, v: s.setRegI('aes_key1', v))

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

        # default dataout.
        dataout = 0
        # execute command.
        if cmd == RD:
            found, data = self.read(cmdaddr)
            if found: 
                dataout = data
        elif cmd == WR and self.aes_state == 0:
            self.write(cmdaddr, cmddata)

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
            'aes_key1'      : self.aes_key1
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

