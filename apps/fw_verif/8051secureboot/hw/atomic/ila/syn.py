# template for SHA ILA without child-instructions.
import ila
import os
from sim import SHA

def createIla():
    m = ila.Abstraction ('sha')
    m.enable_parameterized_synthesis = 0

    # input ports
    cmd     = m.inp ('cmd', 2)
    cmdaddr = m.inp ('cmdaddr', 16)
    cmddata = m.inp ('cmddata', 8)

    # arch states
    state   = m.reg ('sha_state', 3)
    rd_addr = m.reg ('sha_rdaddr', 16)
    wr_addr = m.reg ('sha_wraddr', 16)
    oplen   = m.reg ('sha_len', 16)
    rd_data = m.reg ('sha_rd_data', 512)
    hs_data = m.reg ('sha_hs_data', 160)
    xram    = m.mem ('XRAM', 16, 8)
    sha     = m.fun ('sha', 160, [512])

    # fetch is just looking at the input command.
    m.fetch_expr  = ila.concat ([state, cmd, cmdaddr, cmddata])
    m.fetch_valid = (cmd == 1) | (cmd == 2)

    # write commands.
    def mb_reg_wr (name, reg):
        # multibyte reg write.
        reg_wr  = ila.writechunk ('wr_' + name, reg, cmddata)
        reg_nxt = ila.choice ('nxt_' + name, [reg_wr, reg])
        m.set_next (name, reg_nxt)
    mb_reg_wr ('sha_rdaddr', rd_addr)
    mb_reg_wr ('sha_wraddr', wr_addr)
    mb_reg_wr ('sha_len', oplen)

    # state (atomic)
    state_nxt = ila.choice ('state_nxt', [
                    m.const (0, 3), m.const (1, 3), m.const (2, 3),
                    m.const (3, 3), m.const (4, 3), state])
    m.set_next ('sha_state', state_nxt)

    # xram
    xram_w_sha_little = ila.storeblk (xram, wr_addr, hs_data)
    xram_w_sha_big = ila.storeblk_big (xram, wr_addr, hs_data)
    xram_cho = ila.choice ('xram_nxt', xram, xram_w_sha_little, xram_w_sha_big)
    xram_nxt = ila.ite ((state == 0) & (cmddata == 1), xram_cho, xram)
    m.set_next ('XRAM', xram_nxt)

    return m

def checkOutPath (path):
    if not os.path.exists (path):
        os.makedirs (path)

def synthesize ():
    astPath = 'asts'
    checkOutPath (astPath)

    for addr in xrange (0xfe00, 0xfe10):
        instrPath = '%s/0x%x' % (astPath, addr)
        checkOutPath (instrPath)

        m = createIla()

        # decode functions
        decode = ((m.getinp ('cmd') == 2) & (m.getinp ('cmdaddr') == addr))
        m.decode_exprs = [decode]
        decodeFile = '%s/%s' % (instrPath, 'decode')
        m.exportOne (decode, decodeFile)

        all_states = ['sha_state', 'sha_len', 'sha_rdaddr', 'sha_wraddr', 'XRAM']
        sim = lambda s: SHA().simulate (s)
        for state in all_states:
            m.synthesize (state, sim)
            nxt = m.get_next (state)
            nxtFile = '%s/%s' % (instrPath, state)
            m.exportOne (nxt, nxtFile)

if __name__ == '__main__':
    synthesize()
