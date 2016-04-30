import argparse
import ila
import time
from simAES import AES

def createAESILA(enable_ps):
    ila.setloglevel(0, "")
    m = ila.Abstraction()
    m.enable_parameterized_synthesis = enable_ps

    # I/O interface: this is where the commands come from.
    cmd         = m.inp('cmd', 2)
    cmdaddr     = m.inp('cmdaddr', 16)
    cmddata     = m.inp('cmddata', 8)
    # response.
    dataout     = m.reg('dataout', 8)

    # internal arch state.
    state       = m.reg('aes_state', 2)
    opaddr      = m.reg('aes_addr', 16)
    oplen       = m.reg('aes_len', 16)
    keysel      = m.reg('aes_keysel', 1)
    ctr         = m.reg('aes_ctr', 128)
    key0        = m.reg('aes_key0', 128)
    key1        = m.reg('aes_key1', 128)

    # for the uinst.
    byte_cnt    = m.reg('byte_cnt', 16)
    rd_data     = m.reg('rd_data', 128)
    enc_data    = m.reg('enc_data', 128)
    xram        = m.mem('XRAM', 16, 8)

    # fetch is just looking at the input command.
    m.fetch_expr   = ila.concat([cmd, cmdaddr, cmddata])
    m.fetch_valid  = (cmd == 1) | (cmd == 2)

    # decode 
    rdcmds = [(cmd == 1) & (cmdaddr == addr) for addr in xrange(0xff00, 0xff40)]
    wrcmds = [(cmd == 2) & (cmdaddr == addr) for addr in xrange(0xff00, 0xff40)]
    m.decode_exprs = rdcmds + wrcmds

    # read commands
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

    # write commands.
    def mb_reg_wr(name, reg):
        # multibyte register write.
        reg_wr = ila.ite(state == 0, ila.writechunk('wr_' + name, reg, cmddata), reg)
        reg_nxt = ila.choice('nxt_'+name, [reg_wr, reg])
        m.set_next(name, reg_nxt)
    def bit_reg_wr(name, reg, sz):
        # bitwise register write
        assert reg.type.bitwidth == sz
        reg_wr = ila.ite(state == 0, cmddata[sz-1:0], reg)
        reg_nxt = ila.choice('nxt_'+name, [reg_wr, reg])
        m.set_next(name, reg_nxt)
    # setup the update functions.
    mb_reg_wr('aes_addr', opaddr)
    mb_reg_wr('aes_len', oplen)
    mb_reg_wr('aes_ctr', ctr)
    mb_reg_wr('aes_key0', key0)
    mb_reg_wr('aes_key1', key1)
    bit_reg_wr('aes_keysel', keysel, 1)

    # lets deal with the uinst now
    enc_inst = m.add_uinst(
                    'aes_encrypt',                      # name
                    state != 0,                         # "valid" flag for uinst
                    state,                              # fetch expression
                    [state == i for i in [1, 2, 3]])    # decode expressions
    print enc_inst.name
    print enc_inst.valid
    print enc_inst.fetch_expr
    print [str(s) for s in enc_inst.decode_exprs]
    return

    # synthesize.
    sim = lambda s: AES().simulate(s)
    st = time.clock()
    for r in ['dataout', 'aes_addr', 'aes_len', 'aes_ctr',
              'aes_key0', 'aes_key1', 'aes_keysel']:
        m.synthesize(r, sim)
    t_elapsed = time.clock() - st
    print '%.2f' % (t_elapsed)

if __name__ == '__main__':
    ila.setloglevel(0, "")
    parser = argparse.ArgumentParser()
    parser.add_argument("--en", type=int, default=1, 
                        help="enable parameterized synthesis.")
    args = parser.parse_args()
    createAESILA(args.en)

