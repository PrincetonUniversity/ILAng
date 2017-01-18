import argparse
import ila
import time
from simulate import AES

def createAESILA(enable_ps):
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
    nopcmds = [((state != 0) & (cmd != 1)) | ((state == 0) & (cmd != 1) & (cmd != 2))]

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

    # these are for the uinst
    um = m.add_microabstraction('aes_compute', state != 0)
    um.fetch_expr = state 
    um.decode_exprs = [state == i for i in [1, 2, 3]]

    # read data
    rd_data      = um.reg('rd_data', 128)
    enc_data     = um.reg('enc_data', 128)
    byte_cnt     = um.reg('byte_cnt', 16)
    um.set_init('byte_cnt', um.const(0, 16))
    uxram = m.getmem('XRAM')

    usim = lambda s: AES().simMicro(s)

    # ustate
    ustate       = um.getreg('aes_state')
    ustate_nxt   = ila.choice('ustate_next', 
                        [m.const(0, 2), m.const(1, 2), m.const(2, 2), m.const(3, 2),
                        ila.ite(byte_cnt+16 < oplen, m.const(1, 2), m.const(0, 2))])
    um.set_next('aes_state', ustate_nxt)

    # byte_cnt
    byte_cnt_inc = ila.ite(byte_cnt + 16 < oplen, byte_cnt + 16, byte_cnt)
    byte_cnt_nxt = ila.choice('byte_cnt_nxt', [byte_cnt_inc, byte_cnt])
    um.set_next('byte_cnt', byte_cnt_nxt)

    # rd_data
    rdblock = ila.loadblk(uxram, opaddr + byte_cnt, 16)
    rd_data_nxt = ila.choice('rd_data_nxt', rdblock, rd_data)
    um.set_next('rd_data', rd_data_nxt)

    # enc_data
    aes_key = ila.ite(keysel == 0, key0, key1)
    aes_enc_data = ila.appfun(aes, [ctr, aes_key, rd_data])
    enc_data_nxt = ila.ite(state == 2, aes_enc_data, enc_data)
    um.set_next('enc_data', enc_data_nxt)
    print um.get_next('enc_data')

    # xram write
    xram_w_aes = ila.storeblk(uxram, opaddr + byte_cnt, enc_data)
    xram_nxt = ila.choice('xram_nxt', uxram, xram_w_aes)
    um.set_next('XRAM', xram_nxt)

    suffix = ('en' if enable_ps else 'dis')
    timefile = open('aes-times-uinst-%s.txt' % suffix, 'wt')
    # micro-synthesis
    t_elapsed = 0
    for s in ['aes_state', 'byte_cnt', 'rd_data', 'XRAM']:
        st = time.clock()
        um.synthesize(s, usim)
        dt = time.clock() - st
        t_elapsed += dt
        ast = um.get_next(s)
        print '%s: %s' % (s, str(ast))
        m.exportOne(ast, 'uasts/u%s_%s' % (s, suffix))
        print >> timefile, 'u_%s' % s
        print >> timefile, '%.2f' % dt
    sim = lambda s: AES().simMacro(s)

    # state
    state_next = ila.choice('state_next', [
                        state, ila.ite(cmddata == 1, m.const(1, 2), state)])
    m.set_next('aes_state', state_next)

    # xram
    m.set_next('XRAM', xram)

    # synthesize.
    for s in [ 'aes_state','aes_addr','aes_len','aes_keysel','aes_ctr','aes_key0','aes_key1', 'dataout']:
        st = time.clock()
        m.synthesize(s, sim)
        dt = time.clock() - st
        t_elapsed += dt

        ast = m.get_next(s)
        print '%s: %s' % (s, str(ast))
        m.exportOne(ast, 'uasts/%s_%s' % (s, suffix))
        print >> timefile, '%s' % s
        print >> timefile, '%.2f' % dt

    # connect to the uinst
    m.connect_microabstraction('aes_state', um)
    m.connect_microabstraction('XRAM', um)

    print 'aes_state: %s' % str(m.get_next('aes_state'))
    print 'XRAM: %s' % str(m.get_next('XRAM'))

    print 'time: %.2f' % (t_elapsed)
    m.generateSimToDir('sim_aes_u')

if __name__ == '__main__':
    ila.setloglevel(1, "")
    parser = argparse.ArgumentParser()
    parser.add_argument("--en", type=int, default=1, 
                        help="enable parameterized synthesis.")
    #parser.add_argument("state", type=str, nargs='+',
    #                    help="the state to synthesize.")
    args = parser.parse_args()
    createAESILA(args.en)

