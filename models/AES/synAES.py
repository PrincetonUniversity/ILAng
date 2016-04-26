import ila

def createAESILA():
    m = ila.Abstraction()
    state       = m.reg('state', 2)
    opaddr      = m.reg('addr', 16)
    oplen       = m.reg('len', 16)
    ctr         = m.reg('ctr', 128)
    key0        = m.reg('key0', 128)
    key1        = m.reg('key1', 128)
    xram_in     = m.inp('xram_in', 8)
    xram_addr   = m.reg('xram_addr', 16)
    xram_out    = m.reg('xram_out', 16)



