import ila


def createAESILA(enable_ps):
    m = ila.Abstraction("aes")
    m.enable_parameterized_synthesis = enable_ps

    # I/O interface: this is where the commands come from.
    cmd         = m.inp('cmd', 2)
    cmdaddr     = m.inp('cmdaddr', 16)
    cmddata     = m.inp('cmddata', 8)

    # internal arch state.
    state       = m.reg('aes_state', 2)
    opaddr      = m.reg('aes_addr', 16)
    oplen       = m.reg('aes_len', 16)
    ctr         = m.reg('aes_ctr', 128)
    key0        = m.reg('aes_key0', 128)

    # for the uinst.
    xram        = m.mem('XRAM', 16, 8)
    aes         = m.fun('aes', 128, [128, 128, 128])

    # fetch is just looking at the input command.
    m.fetch_expr   = ila.concat([ cmd, cmdaddr, cmddata])  # actually, the equivelant instruction
    m.fetch_valid  = (cmd == 2) # when write to some addresses

    # decode 
    wrcmds = [ (cmd == 2) & (cmdaddr == addr) for addr in xrange(0xff00, 0xff40) ]
    m.decode_exprs =  wrcmds 
    
    m.add_assumption( (state==0) | (oplen>1) )
    um = m.add_microabstraction('aes_compute', (state != 0)  )

    # write commands.
    def mb_reg_wr(name, reg):
        # multibyte register write.
        reg_wr = ila.writechunk('wr_' + name, reg, cmddata)
        reg_nxt = ila.choice('nxt_'+name, [reg_wr, reg])
        m.set_next(name, reg_nxt)
    mb_reg_wr('aes_addr', opaddr)
    mb_reg_wr('aes_len', oplen)
    mb_reg_wr('aes_ctr', ctr)
    mb_reg_wr('aes_key0', key0)
    # state
    state_next = ila.choice('state_next', [state, m.const(0,2), ila.ite( (cmddata == 1)  , m.const(1, 2), state)])
    m.set_next('aes_state', state_next)
    # xram
    m.set_next('XRAM', xram)

    ################################
    #           Micro-ILA                
    ################################


    # read data
    rd_data       = um.reg('rd_data', 128)
    enc_data      = um.reg('enc_data', 128)
    blk_cnt       = um.reg('blk_cnt', 16)
    uaes_ctr       = um.reg('uaes_ctr', 128)
    
    um.set_init('blk_cnt', um.const(0, 16))
    um.set_init('uaes_ctr', um.getreg('aes_ctr') )
    uxram = m.getmem('XRAM')

    um.fetch_expr = state 
    um.decode_exprs = [(state == i) for i in [1, 2, 3]]  # READ/OPERATE/WRITE
   
    # blk_cnt
    blk_cnt_inc = blk_cnt + ila.inrange('blkcntrange',um.const(1,16),um.const(32,16))
    more_blocks = ila.choice('cond1' , (blk_cnt_inc != oplen) , (oplen >= blk_cnt_inc), (oplen > blk_cnt_inc ) )
    blk_cnt_nxt = ila.choice('blk_cnt_nxt', 
        [m.const(0, 16), blk_cnt, blk_cnt_inc,
         ila.ite(more_blocks, blk_cnt_inc, blk_cnt)])
    um.set_next('blk_cnt', blk_cnt_nxt)

    # ustate
    ustate       = um.getreg('aes_state')
    ustate_nxt   = ila.choice('ustate_next', 
        [m.const(0, 2), m.const(1, 2), m.const(2, 2), m.const(3, 2), ustate,
         ila.ite(more_blocks, m.const(1, 2), m.const(0, 2)) ])  # change 4
    um.set_next('aes_state', ustate_nxt)

    # rd_data
    rdblock = ila.loadblk(uxram, opaddr + blk_cnt, 16)
    rd_data_nxt = ila.choice('rd_data_nxt', rdblock, rd_data)
    um.set_next('rd_data', rd_data_nxt)

    # enc_data
    aes_key = key0
    aes_enc_data = ila.appfun(aes, [uaes_ctr, aes_key, rd_data])
    enc_data_nxt = ila.ite(state == 2, aes_enc_data, enc_data)
    um.set_next('enc_data', enc_data_nxt)
    #print um.get_next('enc_data')
    
    uaes_ctr_nxt = ila.choice('uaes_ctr_nxt', 
        uaes_ctr, uaes_ctr + ila.inrange('uaes_ctr_nxt_range',m.const(1,128), m.const(128,128) ) )
    um.set_next('uaes_ctr',uaes_ctr_nxt)
	
    # xram write
    xram_w_addr = opaddr + blk_cnt
    xram_w_aes = ila.storeblk(uxram, xram_w_addr, enc_data)
    xram_nxt = ila.choice('xram_nxt', uxram, xram_w_aes)
    um.set_next('XRAM', xram_nxt)

    return m,um
