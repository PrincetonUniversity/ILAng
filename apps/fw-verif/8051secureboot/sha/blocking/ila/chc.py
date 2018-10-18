# Convert ILA to Horn Clause for concurrent instructions.
import ila
import os

def createHorn():
    all_instr  = [addr for addr in xrange(0xfe00, 0xfe10)]
    all_instr  = [0xfe00, 0xfe01]
    all_child  = [1, 2, 3, 4]
    all_states = ['sha_state', 'sha_rdaddr', 'sha_wraddr', 'sha_len', 'XRAM', 'sha_bytes_read', 'sha_rd_data', 'sha_hs_data']

    m = ila.Abstraction("sha")
    m.hornifyIteAsNode (True)
    m.hornifyBvAsInt (True)

    destDir = '../horn'
    if not os.path.exists(destDir):
        os.makedirs(destDir)

    root = 'asts/'

    for addr in all_instr:
        Dpath = root + '/instr_%x/decode' % addr
        Dast = m.importOne (Dpath)
        m.hornifyNode (Dast, 'delta_%x' % addr)

        for s in all_states:
            Npath = root + '/instr_%x/%s' % (addr, s)
            Nast = m.importOne (Npath)
            m.hornifyNode (Nast, 'N_%x_%s_nxt' % (addr, s))

    for st in all_child:
        Dpath = root + '/child_%d/decode' % st
        Dast = m.importOne (Dpath)
        m.hornifyNode (Dast, 'delta_%d' % st)

        for s in all_states:
            Npath = root + '/child_%d/%s' % (st, s)
            Nast = m.importOne (Npath)
            m.hornifyNode (Nast, 'N_%d_%s_nxt' % (st, s))

    ilaFile = destDir + '/ila.smt2'
    m.exportHornToFile (ilaFile)

if __name__ == '__main__':
    ila.setloglevel(3, "")
    #ila.enablelog("Horn")
    createHorn()
