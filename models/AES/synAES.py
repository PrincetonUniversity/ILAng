import ila
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
        self.addReg('aes_reserved_1', 0xff06, 10, readonly=True)
        self.addReg('aes_ctr', 0xff10, 0x10)
        self.addReg('aes_key0', 0xff20, 0x10)
        self.addReg('aes_key1', 0xff30, 0x10)

        self.aes_bytes_processed = 0
        self.aes_read_data = [0] * 16
        self.aes_enc_data  = [0] * 16

    def simulator():

def AES(s):
    cmd         = s['cmd']
    cmaddr      = s['cmdaddr']
    cmddata     = s['cmddata']

def createAESILA():
    m = ila.Abstraction()

    cmd         = m.inp('cmd', 2)
    cmdaddr     = m.inp('cmdaddr', 16)
    cmddata     = m.inp('cmddata', 8)

    state       = m.reg('state', 2)
    opaddr      = m.reg('addr', 16)
    oplen       = m.reg('len', 16)
    keysel      = m.reg('keysel', 1)
    ctr         = m.reg('ctr', 128)
    key0        = m.reg('key0', 128)
    key1        = m.reg('key1', 128)
    xram        = m.mem('XRAM', 16, 8)
    dataout     = m.reg('dataout', 8)

    m.fetch_expr   = ila.concat(cmd, ila.concat(cmdaddr, cmddata))
    m.fetch_valid  = (cmd == 1) | (cmd == 2)

    rdcmds = [(cmd == 1) & cmdaddr = addr for addr in xrange(0xff00, ff40)]
    wrcmds = [(cmd == 2) & cmdaddr = addr for addr in xrange(0xff00, ff40)]
    m.decode_exprs = rdcmds + wrcmds

    # store-block
    # load-block
    # write-byte
    # read-byte
