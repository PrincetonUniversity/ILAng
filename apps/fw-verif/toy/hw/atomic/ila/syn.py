# python scripts for defining acc_regs ILA -- atomic

import ila
import os
from sim import ACC

def createILA():
    m = ila.Abstraction('acc_regs')

    # input ports
    cmd     = m.inp ('cmd', 2)
    cmdaddr = m.inp ('cmdaddr', 16)
    cmddata = m.inp ('cmddata', 8)

    # arch states
    state   = m.reg ('acc_state', 3)
    rd_addr = m.reg ('rd_addr', 16)
    wr_addr = m.reg ('wr_addr', 16)
    oplen   = m.reg ('acc_len', 16)
    xram    = m.mem ('XRAM', 16, 8)

    # micro-arch states
    bytes_read = m.reg ('bytes_read', 16)

    # fetch function and fetch valid function
    m.fetch_expr = ila.concat ([state, cmd, cmdaddr, cmddata])
    m.fetch_valid = (cmd == 1) | (cmd == 2)

    # state_nxt
    state_nxt = ila.choice ('state_nxt', [
                    m.const (0, 3), m.const (1, 3), m.const (2, 3),
                    m.const (3, 3), m.const (4, 3), state])
    m.set_next ('acc_state', state_nxt)

    # NOTE next state functions for rd_addr, wr_addr, oplen and xram is ignore.

    return m

def checkOutPath (path):
    if not os.path.exists (path):
        os.makedirs (path)

def synthesize():
    astPath = 'asts'
    checkOutPath (astPath)

    for addr in xrange (0xfe00, 0xfe04):
        instrPath = '%s/0x%x' % (astPath, addr)
        checkOutPath (instrPath)

        m = createILA()

        # decode functions
        decode = ((m.getinp ('cmd') == 2) & (m.getinp ('cmdaddr') == addr))
        m.decode_exprs = [decode]
        decodeFile = '%s/%s' % (instrPath, 'decode')
        m.exportOne (decode, decodeFile)

        all_states = ['acc_state']
        sim = lambda s: ACC().simulate (s)
        for state in all_states:
            m.synthesize (state, sim)
            nxt = m.get_next (state)
            nxtFile = '%s/%s' % (instrPath, state)
            m.exportOne (nxt, nxtFile)

if __name__ == '__main__':
    synthesize()
