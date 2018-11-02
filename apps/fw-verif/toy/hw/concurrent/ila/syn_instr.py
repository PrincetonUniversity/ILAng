# template for synthesizing instructions for acc_regs

import ila
import os
from sim import ACC

def createILA():
    m = ila.Abstraction ('acc_regs')
    m.enable_parameterized_synthesis = 0

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

    bytes_read = m.reg ('bytes_read', 16)

    # fetch function and fetch valid fuction
    m.fetch_expr = ila.concat ([state, cmd, cmdaddr,cmddata])
    m.fetch_valid = (cmd == 1) | (cmd == 2)

    m.add_assumption (oplen > 0)

    # acc_state
    id_nxt = ila.ite (cmddata == 1, m.const (1, 3), m.const (0, 3))
    state_nxt = ila.choice ('state_nxt', id_nxt, state)
    m.set_next ('acc_state', state_nxt)

    # bytes_read
    bytes_read_inc = bytes_read + 1
    bytes_read_rst = ila.ite (cmddata == 1, m.const (0, 16), bytes_read)
    bytes_read_nxt = ila.choice ('bytes_read_nxt', [
            m.const (0, 16), bytes_read_inc, bytes_read_rst, bytes_read])
    m.set_next ('bytes_read', bytes_read_nxt)

    return m

def checkOutPath (path):
    if not os.path.exists (path):
        os.makedirs (path)

def synthesize():
    all_states = ['acc_state', 'bytes_read']

    astPath = 'asts'
    checkOutPath (astPath)

    for addr in xrange (0xfe00, 0xfe04):
        instrPath = '%s/0x%x' % (astPath, addr)
        checkOutPath (instrPath)

        m = createILA()

        # decode functions
        decode = ((m.getinp ('cmd') == 2) & (m.getinp ('cmdaddr') == addr))
        m.decode_exprs = [decode & (m.getreg ('acc_state') == 0)]
        decodeFile = '%s/%s' % (instrPath, 'decode')
        m.exportOne (decode, decodeFile)

        sim = lambda s: ACC().simulate (s)
        for s in all_states:
            m.synthesize (s, sim)
            fileName = instrPath + '/' + s
            nxt = m.get_next (s)
            m.exportOne (nxt, fileName)

if __name__ == '__main__':
    synthesize()

