# template for synthesizing child instructions for acc_regs

import ila
import os
from sim import ACC

def createILA ():
    m = ila.Abstraction ('acc_regs')
    m.enable_parameterized_synthesis = 0

    # input ports
    cmd     = m.inp ('cmd', 2)
    cmdaddr = m.inp ('cmdaddr', 16)
    cmddata = m.inp ('cmddata', 8)

    # states
    state   = m.reg ('acc_state', 3)
    rd_addr = m.reg ('rd_addr', 16)
    wr_addr = m.reg ('wr_addr', 16)
    oplen   = m.reg ('acc_len', 16)
    xram    = m.mem ('XRAM', 16, 8)

    # child states
    bytes_read = m.reg ('bytes_read', 16)

    # fetch function and fetch valid function
    m.fetch_expr = state
    m.fetch_valid = (state == 1) | (state == 2) | (state == 3) | (state == 4)

    m.add_assumption (oplen > 0)

    # acc_state
    RD_nxt  = m.const (2, 3)
    OP1_nxt = m.const (3, 3)
    OP2_nxt = ila.ite (bytes_read < oplen, m.const (1, 3), m.const (4, 3))
    WR_nxt  = m.const (0, 3)
    state_nxt = ila.choice ('state_nxt', [RD_nxt, OP1_nxt, OP2_nxt, WR_nxt])
    m.set_next ('acc_state', state_nxt)

    # bytes_state
    bytes_read_inc = bytes_read + 1
    bytes_read_nxt = ila.choice ('bytes_read_nxt', bytes_read_inc, bytes_read)
    m.set_next ('bytes_read', bytes_read_nxt)

    return m

def checkOutPath (path):
    if not os.path.exists (path):
        os.makedirs (path)

def synthesize ():
    all_states = ['acc_state', 'bytes_read']

    astPath = 'asts'
    checkOutPath (astPath)

    for st in [1, 2, 3, 4]:
        instrPath = '%s/st%d' % (astPath, st)
        checkOutPath (instrPath)
        m = createILA()

        # decode functions
        decode = (m.getreg ('acc_state') == st)
        m.decode_exprs = [decode]
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
