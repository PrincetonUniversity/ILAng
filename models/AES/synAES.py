import ila

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

    state_start = m.const(1, 2)

    # store-block
    # load-block
    # write-byte
    # read-byte
