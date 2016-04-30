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
    opaddrbyte  = ila.readchunk('rd_addr', opaddr, 8)
    oplenbyte   = ila.readchunk('rd_len', oplen, 8)
    keyselbyte  = ila.zero_extend(keysel, 8)
    ctrbyte     = ila.readchunk('rd_ctr', ctr, 8)
    key0byte    = ila.readchunk('rd_key0', key0, 8)
    key1byte    = ila.readchunk('rd_key1', key1, 8)
    dataoutnext = ila.choice('dataout', [
                        statebyte, opaddrbyte, oplenbyte, 
                        keyselbyte, ctrbyte, key0byte, 
                        key1byte, m.const(0, 8)])
    m.set_next('dataout', dataoutnext)


    def mb_reg_wr(name, reg):
        "multibyte register write."
        reg_wr = ila.ite(state == 0, ila.writechunk('wr_' + name, reg, cmddata), reg)
        reg_nxt = ila.choice('nxt_'+name, [reg_wr, reg])
        m.set_next(name, reg_nxt)

    def bit_reg_wr(name, reg, sz):
        "multibyte register write."
        assert reg.type.bitwidth == sz
        reg_wr = ila.ite(state == 0, cmddata[sz-1:0], reg)
        reg_nxt = ila.choice('nxt_'+name, [reg_wr, reg])
        m.set_next(name, reg_nxt)

    mb_reg_wr('aes_addr', opaddr)
    mb_reg_wr('aes_len', oplen)
    mb_reg_wr('aes_ctr', ctr)
    mb_reg_wr('aes_key0', key0)
    mb_reg_wr('aes_key1', key1)
    bit_reg_wr('aes_keysel', keysel, 1)

    # synthesize.
    sim = lambda s: AES().simulate(s)
    m.synthesize('dataout', sim)
    m.synthesize('aes_addr', sim)
    m.synthesize('aes_len', sim)
    m.synthesize('aes_ctr', sim)
    m.synthesize('aes_key0', sim)
    m.synthesize('aes_key1', sim)
    m.synthesize('aes_keysel', sim)

if __name__ == '__main__':
    createAESILA()

