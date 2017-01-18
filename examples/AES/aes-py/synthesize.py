import argparse
import ila
import time
from simulate import AES

def createAESILA(synstates, enable_ps):
    m = ila.Abstraction("aes")
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
    aes         = m.fun('aes', 128, [128, 128, 128])

    # fetch is just looking at the input command.
    m.fetch_expr   = ila.concat([state, cmd, cmdaddr, cmddata])
    m.fetch_valid  = (cmd == 1) | (cmd == 2)

    # decode 
    rdcmds = [(state == i) & (cmd == 1) & (cmdaddr == addr)
              for addr in xrange(0xff00, 0xff40) for i in [0,1,2,3]]
    wrcmds = [(state == 0) & (cmd == 2) & (cmdaddr == addr) 
              for addr in xrange(0xff00, 0xff40)]
    nopcmds = [(state == i) & (cmd != 1) & (cmdaddr == addr)
               for addr in xrange(0xff00, 0xff40) for i in [1,2,3]]
    m.decode_exprs = rdcmds + wrcmds + nopcmds

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
        reg_wr = ila.writechunk('wr_' + name, reg, cmddata)
        reg_nxt = ila.choice('nxt_'+name, [reg_wr, reg])
        m.set_next(name, reg_nxt)
    mb_reg_wr('aes_addr', opaddr)
    mb_reg_wr('aes_len', oplen)
    mb_reg_wr('aes_ctr', ctr)
    mb_reg_wr('aes_key0', key0)
    mb_reg_wr('aes_key1', key1)
    # bit-level registers
    def bit_reg_wr(name, reg, sz):
        # bitwise register write
        assert reg.type.bitwidth == sz
        reg_wr = cmddata[sz-1:0]
        reg_nxt = ila.choice('nxt_'+name, [reg_wr, reg])
        m.set_next(name, reg_nxt)
    bit_reg_wr('aes_keysel', keysel, 1)

    # state
    state_next = ila.choice('state_next', [
                        m.const(0, 2), m.const(1, 2), m.const(2, 2), m.const(3, 2),
                        ila.ite(cmddata == 1, m.const(1, 2), state),
                        ila.ite(byte_cnt+16 < oplen, m.const(1, 2), m.const(0, 2))])
    m.set_next('aes_state', state_next)

    # these are for the uinst
    # byte_cnt
    byte_cnt_inc = byte_cnt + 16
    byte_cnt_rst = ila.ite(cmddata == 1, m.const(0, 16), byte_cnt)
    byte_cnt_nxt = ila.choice('byte_cnt_nxt', [
        m.const(0, 16), byte_cnt_inc, byte_cnt_rst, byte_cnt])
    m.set_next('byte_cnt', byte_cnt_nxt)
    # rd_data
    rdblock = ila.loadblk(xram, opaddr + byte_cnt, 16)
    rd_data_nxt = ila.choice('rd_data_nxt', rdblock, rd_data)
    m.set_next('rd_data', rd_data_nxt)
    # enc_data
    aes_key = ila.ite(keysel == 0, key0, key1)
    aes_enc_data = ila.appfun(aes, [ctr, aes_key, rd_data])
    enc_data_nxt = ila.ite(state == 2, aes_enc_data, enc_data)
    m.set_next('enc_data', enc_data_nxt)
    # xram write
    xram_w_aes = ila.storeblk(xram, opaddr + byte_cnt, enc_data)
    xram_nxt = ila.choice('xram_nxt', xram, xram_w_aes)
    m.set_next('XRAM', xram_nxt)

    # synthesize.
    timefile = open('aes-times-%s.txt' % ('en' if enable_ps else 'dis'), 'wt')
    sim = lambda s: AES().simulate(s)
    for s in synstates:
        st = time.clock()
        m.synthesize(s, sim)
        t_elapsed = time.clock() - st
        print >> timefile, s
        print >> timefile, '%.2f' % (t_elapsed)

        ast = m.get_next(s)
        m.exportOne(ast, 'asts/%s_%s' % (s, 'en' if enable_ps else 'dis'))

    m.generateSimToDir('sim')

all_state = ['aes_state', 'aes_addr', 'aes_len', 'aes_keysel', 'aes_ctr', 'aes_key0', 'aes_key1', 'byte_cnt', 'rd_data', 'enc_data', 'XRAM', 'dataout']

if __name__ == '__main__':
    ila.setloglevel(1, "")
    parser = argparse.ArgumentParser()
    parser.add_argument("--en", type=int, default=1, 
                        help="enable parameterized synthesis.")
    parser.add_argument("state", type=str, nargs='+',
                        help="the state to synthesize.")
    args = parser.parse_args()
    if args.state == ['ALL']:
        state = all_state
    else:
        state = args.state
    createAESILA(state, args.en)

# done #















    #for r in ['dataout', 'aes_addr', 'aes_len', 'aes_ctr',
    #          'aes_key0', 'aes_key1', 'aes_keysel', 'aes_state']:
    #m.synthesize('byte_cnt', sim)
    #m.synthesize('aes_state', sim)
    #m.synthesize('rd_data', sim)
    #m.synthesize('enc_data', sim)
    #m.synthesize('XRAM', sim)


