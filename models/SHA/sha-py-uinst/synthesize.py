import argparse
import ila
import time
from simulate import SHA

def createSHAILA(enable_ps):
    m = ila.Abstraction("sha")
    m.enable_parameterized_synthesis = enable_ps

    # I/O interface: this is where the commands come from
    cmd         = m.inp('cmd', 2)
    cmdaddr     = m.inp('cmdaddr', 16)
    cmddata    = m.inp('cmddata', 8)
    # response
    dataout     = m.reg('dataout', 8)

    # internal arch state.
    state       = m.reg('sha_state', 3)
    rdaddr      = m.reg('sha_rdaddr', 16)
    wraddr      = m.reg('sha_wraddr', 16)
    oplen       = m.reg('sha_len', 16)

    # for the uinst.
    xram        = m.mem('XRAM', 16, 8)
    sha         = m.fun('sha', 160, [512])

    # fetch is just looking at the input command.
    m.fetch_expr    = ila.concat([state, cmd, cmdaddr, cmddata])
    m.fetch_valid   = (cmd == 1) | (cmd == 2)

    # decode
    rdcmds = [(state == i) & (cmd == 1) & (cmdaddr == addr)
              for addr in xrange(0xfe00, 0xfe10) for i in [0, 1, 2, 3, 4]]
    wrcmds = [(state == 0) & (cmd == 2) & (cmdaddr == addr)
              for addr in xrange(0xfe00, 0xfe10)]
    nopcmds = [((state != 0) & (cmd != 1)) | ((state == 0) & (cmd != 1) & (cmd != 2))]

    m.decode_exprs = rdcmds + wrcmds + nopcmds

    # read commands.
    statebyte   = ila.zero_extend(state, 8)
    rdaddrbyte  = ila.readchunk('rd_addr', rdaddr, 8)
    wraddrbyte  = ila.readchunk('wr_addr', wraddr, 8)
    oplenbyte   = ila.readchunk('op_len', oplen, 8)
    dataoutnext = ila.choice('dataout', [
                        statebyte, rdaddrbyte, wraddrbyte, 
                        oplenbyte, m.const(0, 8)])
    m.set_next('dataout', dataoutnext)

    # write commands.
    def mb_reg_wr(name, reg):
        # multibyte register write.
        reg_wr = ila.writechunk('wr_' + name, reg, cmddata)
        reg_nxt = ila.choice('nxt_' + name, [reg_wr, reg])
        m.set_next(name, reg_nxt)
    mb_reg_wr('sha_rdaddr', rdaddr)
    mb_reg_wr('sha_wraddr', wraddr)
    mb_reg_wr('sha_len', oplen)

    # these are for the uinst
    um = m.add_microabstraction('sha_compute', state != 0)
    um.fetch_expr = state
    um.decode_exprs = [state == i for i in [1, 2, 3, 4]]

    # read data
    rd_data     = um.reg('sha_rd_data', 512)
    hs_data     = um.reg('sha_hs_data', 160)
    bytes_read  = um.reg('sha_bytes_read', 16)
    um.set_init('sha_bytes_read', um.const(0, 16))
    uxram = m.getmem('XRAM')

    usim = lambda s: SHA().simMicro(s)

    # ustate
    ustate      = um.getreg('sha_state')
    ustate_nxt  = ila.choice('ustate_next', [
                    m.const(0, 3), m.const(1, 3), m.const(2, 3), 
                    m.const(3, 3), m.const(4, 3), 
                    ila.ite(bytes_read < oplen, m.const(1, 3), m.const(4, 3))])
    um.set_next('sha_state', ustate_nxt)

    # bytes_read 
    bytes_read_inc = bytes_read + 64
    bytes_read_nxt = ila.choice('bytes_read_nxt', [bytes_read_inc, 
                        bytes_read, m.const(0, 16)])
    um.set_next('sha_bytes_read', bytes_read_nxt)

    # rd_data
    rdblock_little = ila.loadblk(xram, rdaddr + bytes_read, 64)
    rdblock_big = ila.loadblk_big(xram, rdaddr + bytes_read, 64)
    rd_data_nxt = ila.choice('rd_data_nxt', rdblock_big, rdblock_little, rd_data)
    um.set_next('sha_rd_data', rd_data_nxt)

    # hs_data
    sha_hs_data = ila.appfun(sha, [rd_data])
    hs_data_nxt = ila.choice('hs_data_nxt', sha_hs_data, hs_data)
    um.set_next('sha_hs_data', hs_data_nxt)

    # xram write
    xram_w_sha_little = ila.storeblk(xram, wraddr, hs_data)
    xram_w_sha_big = ila.storeblk_big(xram, wraddr, hs_data)
    xram_nxt = ila.choice('xram_nxt', xram, xram_w_sha_little, xram_w_sha_big)
    um.set_next('XRAM', xram_nxt)

    # micro-synthesis
    suffix = 'en' if enable_ps else 'dis'
    timefile = open('sha-times-uinst-%s.txt' % suffix, 'wt')
    t_elapsed = 0
    for s in ['sha_state', 'sha_bytes_read', 'sha_rd_data', 'sha_hs_data', 'XRAM']:
        st = time.clock()
        um.synthesize(s, usim)
        dt = time.clock() - st
        t_elapsed += dt
        print >> timefile, 'u%s %.2f' % (s, dt)
        ast = um.get_next(s)
        print '%s: %s' % (s, str(ast))
        m.exportOne(ast, 'uasts/u%s_%s' % (s, suffix))

    sim = lambda s: SHA().simMacro(s)
    
    # state
    state_next = ila.choice('state_next', [state, ila.ite(cmddata == 1, m.const(1, 3), state)])
    m.set_next('sha_state', state_next)

    # xram
    m.set_next('XRAM', xram)

    # synthesize.
    for s in ['sha_state', 'sha_rdaddr', 'sha_wraddr', 'sha_len', 'dataout']:
        st = time.clock()
        m.synthesize(s, sim)
        dt = time.clock() - st
        t_elapsed += dt
        print >> timefile, '%s %.2f' % (s, dt)

        ast = m.get_next(s)
        print '%s: %s' % (s, str(ast))
        m.exportOne(ast, 'uasts/%s_%s' % (s, suffix))

    # connect to the uinst
    m.connect_microabstraction('sha_state', um)
    m.connect_microabstraction('XRAM', um)

    print 'time: %.2f' % (t_elapsed)
    #m.generateSim('utmp/shasim.hpp')
    m.generateSimToDir('sim')

if __name__ == '__main__':
    ila.setloglevel(1, "")
    parser = argparse.ArgumentParser()
    parser.add_argument("--en", type=int, default=1, 
                        help="enable parameterized synthesis.")
    #parser.add_argument("state", type=str, nargs='+',
    #                    help="the state to synthesize.")
    args = parser.parse_args()
    createSHAILA(args.en)

