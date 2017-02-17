# template for synthesizing RSA ILA
import ila
import os
import time
import multiprocessing as mp
from sim import RSA

def createRsaIla ():
    m = ila.Abstraction ('rsa')
    m.enable_parameterized_synthesis = 0

    # I/O interface
    cmd         = m.inp ('cmd', 2)
    cmdaddr     = m.inp ('cmdaddr', 16)
    cmddata     = m.inp ('cmddata', 8)
    # response
    dataout     = m.reg ('dataout', 8)

    # states
    state           = m.reg ('rsa_state', 2)
    addr            = m.reg ('rsa_addr', 16)
    rsa_M           = m.reg ('rsa_M', 2048)
    rsa_N           = m.reg ('rsa_N', 2048)
    rsa_E           = m.reg ('rsa_E', 2048)
    rsa_buff        = m.reg ('rsa_buff', 2048)
    byte_counter    = m.reg ('rsa_byte_counter', 8)
    xram            = m.mem ('XRAM', 16, 8)
    rsa             = m.fun ('rsa', 2048, [2048])

    # fetch
    m.fetch_expr    = ila.concat ([state, cmd, cmdaddr, cmddata])
    m.fetch_valid   = (cmd == 1) | (cmd == 2)

    statebyte   = ila.zero_extend (state, 8)
    wraddrbyte  = ila.readchunk ('rsa_addr', addr, 8)
    dataout_nxt = ila.choice ('dataout', [statebyte, wraddrbyte, m.const(0, 8)])
    m.set_next ('dataout', dataout_nxt)

    # rsa_addr
    addr_wr  = ila.writechunk ('wr_addr', addr, cmddata)
    addr_nxt = ila.choice ('nxt_addr', [addr_wr, addr])
    m.set_next ('rsa_addr', addr_nxt)

    # rsa_state
    state_choice = ila.choice ('state_choice', [m.const (0, 2),
                                                m.const (1, 2),
                                                m.const (2, 2),
                                                m.const (3, 2)])
    wr_nxt = ila.ite (byte_counter == 255, m.const (0, 2), m.const (3, 2))
    state_nxt = ila.choice ('rsa_state_nxt', [wr_nxt, state_choice, 
            ila.ite (cmddata == 1, m.const (1, 2), state), state])
    m.set_next ('rsa_state', state_nxt)

    # byte_counter
    byte_counter_inc = byte_counter + 1
    byte_counter_rst = ila.ite (cmddata == 1, m.const (0, 8), byte_counter)
    byte_counter_nxt = ila.choice ('byte_counter_nxt', [
            byte_counter_inc, byte_counter_rst, byte_counter])
    m.set_next ('rsa_byte_counter', byte_counter_nxt)

    # buff
    rsa_buff_op  = ila.appfun (rsa, [rsa_M])
    rsa_buff_nxt = ila.choice ('rsa_buff_nxt', rsa_buff_op, rsa_buff)
    m.set_next ('rsa_buff', rsa_buff_nxt)

    # rsa_M
    m.set_next ('rsa_M', rsa_M)

    # xram
    #xram_w_rsa_lit = ila.storeblk (xram, addr, rsa_buff)
    #xram_w_rsa_big = ila.storeblk_big (xram, addr, rsa_buff)
    byte_cnt_16 = ila.zero_extend (byte_counter, 16)
    sh = ila.zero_extend ((255-byte_counter) * 8, 2048)
    xram_w_rsa_data_1 = (rsa_buff >> sh) [7:0]
    #xram_w_rsa_data_2 = rsa_buff [255 - byte_cnt_16]
    xram_w_rsa_lit = ila.store (xram, addr + byte_cnt_16, xram_w_rsa_data_1)
    xram_nxt = ila.choice ('xram_nxt', [xram_w_rsa_lit, xram])
    m.set_next ('XRAM', xram_nxt)

    return m

def synthesize ():
    all_states = ['rsa_state']
    all_states = ['rsa_state', 'rsa_addr', 'XRAM', 'rsa_buff', 'rsa_byte_counter', 'rsa_M', 'dataout']
    all_instrs = [0xfd00, 0xfd01]
    all_childs = [1, 2, 3]

    directory = 'asts'
    if not os.path.exists (directory):
        os.makedirs (directory)

    def synToFile (m, filePath):
        if not os.path.exists (filePath):
            os.makedirs (filePath)

        sim = lambda s: RSA().simulate (s)
        for s in all_states:
            st = time.clock ()
            m.synthesize (s, sim)
            dt = time.clock () - st
            print s + ' synthesized: %.2f' % dt
            fileName = filePath + '/' + s
            nxt = m.get_next (s)
            si = ila.simplify (m.bool(True), nxt)
            m.exportOne (si, fileName)

    ######################### write instruction #######################
    def synInstr (addr):
        m       = createRsaIla ()
        cmd     = m.getinp ('cmd')
        cmdaddr = m.getinp ('cmdaddr')
        cmddata = m.getinp ('cmddata')
        state   = m.getreg ('rsa_state')

        name = 'instr_W_%x' % addr
        #m.decode_exprs = [(cmd == 2) & (cmdaddr == addr) & (state == 0)]
        m.decode_exprs = [(cmd == 2) & (cmdaddr == addr)]
        decode = m.decode_exprs[0]
        m.add_assumption (state == 0)

        subDir = directory + '/' + name
        synToFile (m, subDir)

        decodeFile = subDir + '/decode'
        m.exportOne (decode, decodeFile)

    ######################### read instruction #######################
    def synReadInstr (addr):
        m       = createRsaIla ()
        cmd     = m.getinp ('cmd')
        cmdaddr = m.getinp ('cmdaddr')
        cmddata = m.getinp ('cmddata')
        state   = m.getreg ('rsa_state')

        name = 'instr_R_%x' % addr
        m.decode_exprs = [(cmd == 1) & (cmdaddr == addr)]
        decode = m.decode_exprs[0]
        #m.add_assumption (state == 0)

        subDir = directory + '/' + name
        synToFile (m, subDir)

        decodeFile = subDir + '/decode'
        m.exportOne (decode, decodeFile)

    ################### chile instructions #######################
    def synChild (st):
        m = createRsaIla ()
        state = m.getreg ('rsa_state')

        name = 'child_%d' % st
        m.decode_exprs = [state == st]
        decode = m.decode_exprs[0]
        m.add_assumption (m.getinp ('cmd') == 2)
        
        subDir = directory + '/' + name
        if not os.path.exists (subDir):
            os.makedirs (subDir)

        decodeFile = subDir + '/decode'
        m.exportOne (decode, decodeFile)

        synToFile (m, subDir)

    processes =  [mp.Process (target=synInstr, args=(addr,)) 
        for addr in all_instrs]
    processes += [mp.Process (target=synReadInstr, args=(addr,))
        for addr in all_instrs]
    processes += [mp.Process (target=synChild, args=(st,)) 
        for st in all_childs]

    for p in processes:
        p.start ()

    for p in processes:
        p.join ()

if __name__ == '__main__':
    synthesize ()
