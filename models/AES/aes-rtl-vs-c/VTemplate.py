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
    m.fetch_valid  = (cmd == 2)	# when write to some addresses

    # decode 
    wrcmds = [ (cmd == 2) & (cmdaddr == addr) for addr in xrange(0xff00, 0xff30) ] #
    m.decode_exprs =  wrcmds 

    um = m.add_microabstraction('aes_compute', state != 0)
    
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
    state_next = ila.choice('state_next', [state, ila.ite(cmddata == 1, m.const(1, 2), state)])
    m.set_next('aes_state', state_next)
    # xram
    m.set_next('XRAM', xram)

    ################################
    #           Micro-ILA                
    ################################


    # read data
    rd_data       = um.reg('rd_data', 128)
    enc_data      = um.reg('enc_data', 128)
    byte_cnt      = um.reg('byte_cnt', 4)
    oped_byte_cnt = um.reg('oped_byte_cnt', 16)
    blk_cnt       = um.reg('blk_cnt', 16)
    aes_time      = um.reg('aes_time',5)  
    uaes_ctr	  = um.reg('uaes_ctr',128) # change 1
    
    um.set_init('byte_cnt', um.const(0, 4))
    um.set_init('blk_cnt', um.const(0, 16))
    um.set_init('oped_byte_cnt', um.const(0, 16))
    um.set_init('aes_time',um.const(0,5)) 
    um.set_init('uaes_ctr',  m.getreg('aes_ctr') ) # change 2
    uxram = m.getmem('XRAM')

    byte_cnt_16b = ila.zero_extend(byte_cnt, 16)

    um.fetch_expr = state 
    um.decode_exprs = [(state == i) & (byte_cnt == j) 
                       for j in xrange(16) for i in [1, 2, 3]]  # Decode Expressionss
    # byte_cnt
    byte_cnt_inc = byte_cnt + 1
    byte_cnt_nxt = ila.choice('byte_cnt_nxt', 
            [m.const(0, 4), byte_cnt_inc, byte_cnt])        # 0, +1, NC
    um.set_next('byte_cnt', byte_cnt_nxt)

    # oped_byte_cnt
    oped_byte_cnt_inc = oped_byte_cnt + 16
    oped_byte_cnt_nxt = ila.choice('oped_byte_cnt_nxt', 
        [m.const(0, 16), oped_byte_cnt_inc, oped_byte_cnt]) # 0, +16, NC
    um.set_next('oped_byte_cnt', oped_byte_cnt_nxt) 

    # blk_cnt
    blk_cnt_inc = blk_cnt + 16
    more_blocks = (oped_byte_cnt_inc < oplen)
    blk_cnt_nxt = ila.choice('blk_cnt_nxt', 
        [m.const(0, 16), blk_cnt, blk_cnt_inc,
         ila.ite(more_blocks, blk_cnt_inc, blk_cnt)])
    um.set_next('blk_cnt', blk_cnt_nxt)

    aes_time_inc = aes_time + 1
    aes_time_ov = aes_time == m.const(31,5)
    aes_time_nxt_c = ila.ite(aes_time_ov,aes_time,aes_time_inc)
    aes_time_nxt = ila.choice("aes_timeC" , m.const(0,5) , aes_time_nxt_c, ila.ite(more_blocks,m.const(0,5),aes_time_nxt_c) )
    aes_time_enough = aes_time > m.const(10,5)
    um.set_next('aes_time',aes_time_nxt)
    
    # change 3
    um.set_next('uaes_ctr', 
    	ila.choice('uaes_ctr_nxt',
    			uaes_ctr, 
    			ila.ite(more_blocks,
    					uaes_ctr + ila.inrange('addvalue',um.const(1,128),um.const(128,128) ),
    					uaes_ctr), ctr) )

    # ustate
    ustate       = um.getreg('aes_state')
    ustate_nxt   = ila.choice('ustate_next', 
        [m.const(0, 2), m.const(1, 2), m.const(2, 2), m.const(3, 2), ustate,
         ila.ite(more_blocks, m.const(1, 2), m.const(0, 2)),
         ila.ite(aes_time_enough, m.const(3,2) , m.const(2,2))])  # change 4
    um.set_next('aes_state', ustate_nxt)

    # rd_data
    rdblock = ila.writechunk("rd_data_chunk", rd_data, ila.load(uxram, opaddr + blk_cnt + byte_cnt_16b))  #
    rd_data_nxt = ila.choice('rd_data_nxt', rdblock, rd_data)
    um.set_next('rd_data', rd_data_nxt)

    # enc_data
    aes_key = key0
    aes_ctr = ila.choice('ctr', uaes_ctr, ctr + ila.zero_extend( blk_cnt,128)  )    
    aes_enc_data = ila.appfun(aes, [aes_ctr, aes_key, rd_data])
    enc_data_nxt = ila.ite(state == 2, aes_enc_data, enc_data)
    um.set_next('enc_data', enc_data_nxt)
    #print um.get_next('enc_data')

    # xram write
    xram_w_data = ila.readchunk('enc_data_chunk', enc_data, 8)
    xram_w_addr = opaddr + blk_cnt + byte_cnt_16b
    xram_w_aes = ila.store(uxram, xram_w_addr, xram_w_data)
    xram_nxt = ila.choice('xram_nxt', uxram, xram_w_aes)
    um.set_next('XRAM', xram_nxt)
    
    return m,um
