import argparse
import ila
import time
from microAESsim import AES as AESmicro
from macroAESsim import AES as AESmacro

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

    # read data
    rd_data       = um.reg('rd_data', 128)
    enc_data      = um.reg('enc_data', 128)
    byte_cnt      = um.reg('byte_cnt', 4)
    oped_byte_cnt = um.reg('oped_byte_cnt', 16)
    blk_cnt       = um.reg('blk_cnt', 16)
    um.set_init('byte_cnt', um.const(0, 4))
    um.set_init('blk_cnt', um.const(0, 16))
    um.set_init('oped_byte_cnt', um.const(0, 16))
    uxram = m.getmem('XRAM')

    byte_cnt_16b = ila.zero_extend(byte_cnt, 16)

    um.fetch_expr = state 
    um.decode_exprs = [(state == i) & (byte_cnt == j) 
                       for j in xrange(16) for i in [1, 2, 3]]

    usim = lambda s: AESmicro().simMicro(s)

    # byte_cnt
    byte_cnt_inc = byte_cnt + 1
    byte_cnt_buf = ila.choice('byte_cnt_buf', [byte_cnt_inc, byte_cnt])
    byte_cnt_nxt = ila.choice('byte_cnt_nxt', 
            [byte_cnt_inc, m.const(0, 4), byte_cnt])
    um.set_next('byte_cnt', byte_cnt_nxt)

    # oped_byte_cnt
    oped_byte_cnt_inc = oped_byte_cnt + 16
    oped_byte_cnt_nxt = ila.choice('oped_byte_cnt_nxt', 
        [m.const(0, 16), oped_byte_cnt, oped_byte_cnt_inc])
    um.set_next('oped_byte_cnt', oped_byte_cnt_nxt)

    # blk_cnt
    blk_cnt_inc = blk_cnt + 16
    more_blocks = (oped_byte_cnt_inc < oplen)
    blk_cnt_nxt = ila.choice('blk_cnt_nxt', 
        [m.const(0, 16), blk_cnt, blk_cnt_inc,
         ila.ite(more_blocks, blk_cnt_inc, blk_cnt)])
    um.set_next('blk_cnt', blk_cnt_nxt)

    # ustate
    ustate       = um.getreg('aes_state')
    ustate_nxt   = ila.choice('ustate_next', 
        [m.const(0, 2), m.const(1, 2), m.const(2, 2), m.const(3, 2), ustate,
         ila.ite(more_blocks, m.const(1, 2), m.const(0, 2))])
    um.set_next('aes_state', ustate_nxt)

    # rd_data
    rdblock = ila.writechunk("rd_data_chunk", rd_data, ila.load(uxram, opaddr + blk_cnt + byte_cnt_16b))
    rd_data_nxt = ila.choice('rd_data_nxt', rdblock, rd_data)
    um.set_next('rd_data', rd_data_nxt)

    # enc_data
    aes_key = ila.ite(keysel == 0, key0, key1)
    aes_enc_data = ila.appfun(aes, [ctr, aes_key, rd_data])
    enc_data_nxt = ila.ite(state == 2, aes_enc_data, enc_data)
    um.set_next('enc_data', enc_data_nxt)
    #print um.get_next('enc_data')

    # xram write
    xram_w_data = ila.readchunk('enc_data_chunk', enc_data, 8)
    xram_w_addr = opaddr + blk_cnt + byte_cnt_16b
    xram_w_aes = ila.store(uxram, xram_w_addr, xram_w_data)
    xram_nxt = ila.choice('xram_nxt', uxram, xram_w_aes)
    um.set_next('XRAM', xram_nxt)

    suffix = 'en' if enable_ps else 'dis'
    timefile = open('aes-times-%s.txt' % suffix, 'wt')

    t_elapsed = 0
    # micro-synthesis
    for s in ['XRAM', 'aes_state', 'byte_cnt', 'blk_cnt', 'oped_byte_cnt', 'rd_data']:
        t_elapsed = 0
        st = time.clock()
        um.synthesize(s, usim)
        dt = time.clock() - st
        t_elapsed += dt
        print >> timefile, '%s %.2f' % ('u_' + s, dt)
        print '%s: %s' % (s, str(um.get_next(s)))
        ast = um.get_next(s)
        m.exportOne(ast, 'asts/u_%s_%s' % (s, suffix))

    sim = lambda s: AESmacro().simMacro(s)
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
        print >> timefile, '%s %.2f' % (s, dt)

        ast = m.get_next(s)
        print '%s: %s' % (s, str(ast))
        m.exportOne(ast, 'asts/%s_%s' % (s, suffix))
    # connect to the uinst
    m.connect_microabstraction('aes_state', um)
    m.connect_microabstraction('XRAM', um)

    print 'total time: %.2f' % t_elapsed

    #print 'aes_state: %s' % str(m.get_next('aes_state'))
    #print 'XRAM: %s' % str(m.get_next('XRAM'))

    #m.generateSim('gen/aes_sim.hpp')
    m.generateSimToDir('sim')

if __name__ == '__main__':
    ila.setloglevel(1, "")
    parser = argparse.ArgumentParser()
    parser.add_argument("--en", type=int, default=1, 
                        help="enable parameterized synthesis.")
    #parser.add_argument("state", type=str, nargs='+',
    #                    help="the state to synthesize.")
    args = parser.parse_args()
    createAESILA(args.en)

