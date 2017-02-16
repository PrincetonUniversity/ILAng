# ILA for SHA with child-instructions
import ila
import os
from simulate import SHA

def createShaIla():
    m = ila.Abstraction("sha")
    m.enable_parameterized_synthesis = 0

    # I/O interface
    cmd         = m.inp ('cmd', 2)
    cmdaddr     = m.inp ('cmdaddr', 16)
    cmddata     = m.inp ('cmddata', 8)
    # response
    dataout     = m.reg ('dataout', 8)

    # arch states
    state       = m.reg ('sha_state', 3)
    rdaddr      = m.reg ('sha_rdaddr', 16)
    wraddr      = m.reg ('sha_wraddr', 16)
    oplen       = m.reg ('sha_len', 16)
    xram        = m.mem ('XRAM', 16, 8)

    # child-ILA states
    bytes_read  = m.reg ('sha_bytes_read', 16)
    rd_data     = m.reg ('sha_rd_data', 512)
    hs_data     = m.reg ('sha_hs_data', 160)
    sha         = m.fun ('sha', 160, [512])

    # fetch
    m.fetch_expr    = ila.concat ([state, cmd, cmdaddr, cmddata])
    m.fetch_valid   = (cmd == 1) | (cmd == 2)

    # read commands.
    statebyte   = ila.zero_extend (state, 8)
    rdaddrbyte  = ila.readchunk ('rd_addr', rdaddr, 8)
    wraddrbyte  = ila.readchunk('wr_addr', wraddr, 8)
    oplenbyte   = ila.readchunk('op_len', oplen, 8)
    dataoutnext = ila.choice('dataout', [
                        statebyte, rdaddrbyte, wraddrbyte, 
                        oplenbyte, m.const(0, 8)])
    m.set_next('dataout', dataoutnext)

    # write commands.
    def mb_reg_wr (name, reg):
        reg_wr  = ila.writechunk ('wr_' + name, reg, cmddata)
        reg_nxt = ila.choice ('nxt_' + name, [reg_wr, reg])
        m.set_next (name, reg_nxt)
    mb_reg_wr ('sha_rdaddr', rdaddr)
    mb_reg_wr ('sha_wraddr', wraddr)
    mb_reg_wr ('sha_len', oplen)

    # state 
    state_choice = ila.choice ('state_choice', [m.const (0, 3), 
                                                m.const (1, 3),
                                                m.const (2, 3),
                                                m.const (3, 3),
                                                m.const (4, 3)])
    rd_nxt = ila.ite (bytes_read < oplen, m.const (1, 3), m.const (4, 3))
    state_nxt = ila.choice ('state_nxt', [rd_nxt, state_choice,
            ila.ite (cmddata == 1, m.const (1, 3), state), state])
    m.set_next ('sha_state', state_nxt)

    # bytes_read
    bytes_read_inc = bytes_read + 64
    bytes_read_rst = ila.ite (cmddata == 1, m.const (0, 16), bytes_read)
    bytes_read_nxt = ila.choice ('bytes_read_nxt', [
            m.const (0, 16), bytes_read_inc, bytes_read_rst, bytes_read])
    m.set_next ('sha_bytes_read', bytes_read_nxt)

    # rd_data
    rdblock_little = ila.loadblk (xram, rdaddr + bytes_read, 64)
    rdblock_big    = ila.loadblk_big (xram, rdaddr + bytes_read, 64)
    rd_data_nxt = ila.choice ('rd_data_nxt', [
            rdblock_big, rdblock_little, rd_data])
    m.set_next ('sha_rd_data', rd_data_nxt)

    # hs_data
    sha_hs_data = ila.appfun (sha, [rd_data])
    hs_data_nxt = ila.choice ('sh_data_nxt', sha_hs_data, hs_data)
    m.set_next ('sha_hs_data', hs_data_nxt)

    # xram
    xram_w_sha_little = ila.storeblk (xram, wraddr, hs_data)
    xram_w_sha_big    = ila.storeblk_big (xram, wraddr, hs_data)
    xram_nxt = ila.choice ('xram_nxt',[
            xram_w_sha_little, xram_w_sha_big, xram])
    m.set_next ('XRAM', xram_nxt)

    return m

def synthesize ():
    all_states = ['sha_state', 'sha_rdaddr', 'sha_wraddr', 'sha_len', 'XRAM', 'sha_bytes_read']
    all_states = ['sha_state', 'sha_rdaddr', 'sha_wraddr', 'sha_len', 'XRAM', 'sha_bytes_read', 'sha_rd_data', 'sha_hs_data', 'dataout']
    all_instrs = [0xfe00, 0xfe01]

    directory = 'asts'
    if not os.path.exists (directory):
        os.makedirs (directory)

    def synToFile (m, filePath) :
        if not os.path.exists (filePath):
            os.makedirs (filePath)

        sim = lambda s: SHA().simulate (s)
        for s in all_states:
            m.synthesize (s, sim)
            fileName = filePath + '/' + s
            nxt = m.get_next (s)
            m.exportOne (nxt, fileName)

    ######################### write instr ############################
    for addr in all_instrs:
        m       = createShaIla()
        cmd     = m.getinp ('cmd')
        cmdaddr = m.getinp ('cmdaddr')
        cmddata = m.getinp ('cmddata')
        state   = m.getreg ('sha_state')

        name = 'instr_W_%x' % addr
        print 'synthesize ' + name
        #m.decode_exprs = [(cmd == 2) & (cmdaddr == addr) & (state == 0)]
        m.decode_exprs = [(cmd == 2) & (cmdaddr == addr)]
        decode = m.decode_exprs[0]
        m.add_assumption (state == 0)

        subDir = directory + '/' + name
        synToFile (m, subDir)

        decodeFile = subDir + '/decode'
        m.exportOne (decode, decodeFile)

    ######################### read instr ############################
    for addr in all_instrs:
        m       = createShaIla()
        cmd     = m.getinp ('cmd')
        cmdaddr = m.getinp ('cmdaddr')
        cmddata = m.getinp ('cmddata')
        state   = m.getreg ('sha_state')

        name = 'instr_R_%x' % addr
        print 'synthesize ' + name
        m.decode_exprs = [(cmd == 1) & (cmdaddr == addr)]
        decode = m.decode_exprs[0]
        #m.add_assumption (state == 0)

        subDir = directory + '/' + name
        synToFile (m, subDir)

        decodeFile = subDir + '/decode'
        m.exportOne (decode, decodeFile)

    ######################### child instrs #######################
    child_decode = [state == s for s in [1, 2, 3, 4]]
    child_name = ['child_%d' % s for s in [1, 2, 3, 4]]

    # child-instruction
    for st in [1, 2, 3, 4]:
        m = createShaIla()
        state   = m.getreg ('sha_state')

        name = 'child_%d' % st
        m.decode_exprs = [state == st]
        decode = m.decode_exprs[0]
        m.add_assumption (m.getinp ('cmd') == 2)

        subDir = directory + '/' + name
        print 'synthesize ' + name
        if not os.path.exists (subDir):
            os.makedirs (subDir)

        decodeFile = subDir + '/decode'
        m.exportOne (decode, decodeFile)

        synToFile (m, subDir)

if __name__ == '__main__':
    synthesize()
