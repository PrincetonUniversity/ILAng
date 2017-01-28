# scripts for translating SHA ILA (without child-instructions) into CHC.
import ila
import os

def createHorn ():
    all_addrs   = [addr for addr in xrange (0xfe00, 0xfe10)]
    all_states  = ['sha_state', 'sha_len', 'sha_rdaddr', 'sha_wraddr', 'XRAM']
    
    m = ila.Abstraction ('sha')
    m.hornifyIteAsNode (True)
    m.hornifyBvAsInt (True)

    chcPath = '../horn'
    if not os.path.exists (chcPath):
        os.makedirs (chcPath)

    for addr in all_addrs:
        decodePath = 'asts/0x%x/decode' % addr
        decode = m.importOne (decodePath)
        m.hornifyNode (decode, 'decode_%x' % addr)
        for s in all_states:
            nxtPath = 'asts/0x%x/%s' % (addr, s)
            nxt = m.importOne (nxtPath)
            m.hornifyNode (nxt, 'instr_%x_%s_nxt' % (addr, s))

    m.exportHornToFile ('%s/ila.smt2' % chcPath)

if __name__ == '__main__':
    ila.setloglevel (3, "")
    #ila.enablelog ("Horn")

    createHorn()
