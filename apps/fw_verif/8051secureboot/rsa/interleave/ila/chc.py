# python scripts from translating ILA into CHC.
import ila
import os

def translate ():
    all_instrs = [addr for addr in xrange (0xfd00, 0xfe10)]
    all_instrs = [0xfd00, 0xfd01]
    all_childs = [1, 2, 3]
    all_states = ['rsa_state', 'rsa_addr', 'XRAM', 'rsa_byte_counter', 'rsa_buff', 'rsa_M', 'dataout']

    m = ila.Abstraction ('rsa')
    m.hornifyIteAsNode (True)
    m.hornifyBvAsInt (True)

    dstDir = '../horn'
    if not os.path.exists(dstDir):
        os.makedirs (dstDir)

    root = 'asts'

    for addr in all_instrs:
        Dpath = root + '/instr_W_%x/decode' % addr
        Dast  = m.importOne (Dpath)
        instrName = 'rsa_w_%x' % addr
        #m.hornifyNode (Dast, 'D_%x' % addr)
        m.addHornInstr (instrName, Dast)

        for s in all_states:
            Npath = root + '/instr_W_%x/%s' % (addr, s)
            Nast  = m.importOne (Npath)
            #m.hornifyNode (Nast, 'N_%x_%s' % (addr, s))
            m.addHornNext (instrName, s, Nast)

    for addr in all_instrs:
        Dpath = root + '/instr_R_%x/decode' % addr
        Dast  = m.importOne (Dpath)
        instrName = 'rsa_r_%x' % addr
        m.addHornInstr (instrName, Dast)

        for s in all_states:
            Npath = root + '/instr_R_%x/%s' % (addr, s)
            Nast  = m.importOne (Npath)
            m.addHornNext (instrName, s, Nast)

    for st in all_childs:
        Dpath = root + '/child_%d/decode' % st
        Dast  = m.importOne (Dpath)
        childName = 'rsa_u_%x' % st
        #m.hornifyNode (Dast, 'D_%x' % st)
        m.addHornChild (childName, 'rsa_w_fd00', Dast)

        for s in all_states:
            Npath = root + '/child_%d/%s' % (st, s)
            Nast = m.importOne (Npath)
            #m.hornifyNode (Nast, 'N_%d_%s' % (st, s))
            m.addHornNext (childName, s, Nast)

    m.generateHornMapping ('Interleave')
    ilaFile = dstDir + '/ila.smt2'
    m.exportHornToFile (ilaFile)

if __name__ == '__main__':
    ila.setloglevel (3, "")
    #ila.enablelog ("Horn")
    ila.enablelog ("Horn-Warning")
    ila.enablelog ("Horn-Error")
    translate ()
