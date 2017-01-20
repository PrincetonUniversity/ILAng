# scripts for converting ila to chc
import ila
import os

def createHorn ():
    all_addrs   = [addr for addr in xrange (0xfe00, 0xfe04)]
    all_child   = [1, 2, 3, 4]
    all_states  = ['acc_state', 'bytes_read']
    
    m = ila.Abstraction ('acc')

    chcPath = '../horn'
    if not os.path.exists (chcPath):
        os.makedirs (chcPath)

    for addr in all_addrs:
        decodePath = 'asts/0x%x/decode' % addr
        decode = m.importOne (decodePath)
        m.hornifyNode (decode, 'decode_%x' % addr, True)
        for s in all_states:
            nxtPath = 'asts/0x%x/%s' % (addr, s)
            nxt = m.importOne (nxtPath)
            m.hornifyNode (nxt, 'instr_%x_%s_nxt' % (addr, s), True)

    for st in all_child:
        decodePath = 'asts/st%d/decode' % st
        decode = m.importOne (decodePath)
        m.hornifyNode (decode, 'decode_st%d' % st, True)
        for s in all_states:
            nxtPath = 'asts/st%d/%s' % (st, s)
            nxt = m.importOne (nxtPath)
            m.hornifyNode (nxt, 'child_%d_%s_nxt' % (st, s), True)

    m.exportHornToFile ('%s/ila.smt' % chcPath)

if __name__ == '__main__':
    ila.setloglevel (3, "")
    #ila.enablelog ("Horn")

    createHorn()
