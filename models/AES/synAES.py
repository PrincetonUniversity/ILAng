import ila
from simAES import AES

def createAESILA():
    m = ila.Abstraction()

    # I/O interface.
    cmd         = m.inp('cmd', 2)
    cmdaddr     = m.inp('cmdaddr', 16)
    cmddata     = m.inp('cmddata', 8)
    dataout     = m.reg('dataout', 8)

    # internal state.
    state       = m.reg('aes_state', 2)
    opaddr      = m.reg('aes_addr', 16)
    oplen       = m.reg('aes_len', 16)
    keysel      = m.reg('aes_keysel', 1)
    ctr         = m.reg('aes_ctr', 128)
    key0        = m.reg('aes_key0', 128)
    key1        = m.reg('aes_key1', 128)
    xram        = m.mem('XRAM', 16, 8)

    m.fetch_expr   = ila.concat([cmd, cmdaddr, cmddata])
    m.fetch_valid  = (cmd == 1) | (cmd == 2)

    rdcmds = [(cmd == 1) & (cmdaddr == addr) for addr in xrange(0xff00, 0xff40)]
    wrcmds = [(cmd == 2) & (cmdaddr == addr) for addr in xrange(0xff00, 0xff40)]
    m.decode_exprs = rdcmds + wrcmds

    statebyte   = ila.zero_extend(state, 8)
    opaddrbyte  = ila.readchunk('rd-addr', opaddr, 8)
    oplenbyte   = ila.readchunk('rd-len', oplen, 8)
    keyselbyte  = ila.zero_extend(keysel, 8)
    ctrbyte     = ila.readchunk('rd-ctr', ctr, 8)
    key0byte    = ila.readchunk('rd-key0', key0, 8)
    key1byte    = ila.readchunk('rd-key1', key1, 8)
    dataoutnext = ila.choice('dataout', [
                        statebyte, opaddrbyte, oplenbyte, 
                        keyselbyte, ctrbyte, key0byte, 
                        key1byte, m.const(0, 8)])
    m.set_next('dataout', dataoutnext)


    opaddr_wr = ila.ite(state == 0, ila.writechunk('wr-addr', opaddr, cmddata), opaddr)
    opaddr_next = ila.choice('addr-next', [opaddr_wr, opaddr])
    m.set_next('aes_addr', opaddr_next)
    
    print m.synthesize('dataout', lambda s: AES().simulate(s))
    print m.synthesize('aes_addr', lambda s: AES().simulate(s))

if __name__ == '__main__':
    createAESILA()

