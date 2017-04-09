import sys

def byte2int(data, length):
    v, m = 0, 1
    for i in xrange(length):
        v = v + data[i] * m
        m = m << 8
    return v

def int2byte(num, length):
    v = num
    data = bytearray(length)
    for i in xrange(length):
        data[i] = v & 0xff
        v = v >> 8
    return data

def encrypt(n, e, m):
    M = byte2int(m, 256)
    E = byte2int(e, 256)
    N = byte2int(n, 256)
    C = pow(M, E, N)
    res = int2byte(C, 256)
    return res

class MODEXP(object):
    # addresses of registers
    EXP_ADDR_START = 0xfa00
    EXP_REG_M      = 0xfa00
    EXP_REG_EXP    = 0xfb00
    EXP_REG_N      = 0xfc00
    EXP_REG_START  = 0xfd00
    EXP_REG_STATE  = 0xfd01
    EXP_REG_ADDR   = 0xfd02
    EXP_ADDR_END   = 0xfd10

    # state of MODEXP module
    EXP_STATE_IDLE       = 0
    EXP_STATE_OPERATE    = 1
    EXP_STATE_WAIT       = 2
    EXP_STATE_WRITE_DATA = 3

    def __init__(self):

        # states
        self.exp_state  = self.EXP_STATE_IDLE
        self.exp_addr   = bytearray(2)
        self.exp_m      = bytearray(256)
        self.exp_n      = bytearray(256)
        self.exp_exp    = bytearray(256)
        self.data_buf   = bytearray(256)
        self.byte_cnt   = 0

        # next outputs
        self.ack_next            = 0
        self.in_addr_range_next  = 0
        self.data_out_next       = 0
        self.xram_addr_next      = 0
        self.xram_data_out_next  = 0
        self.xram_stb_next       = 0
        self.xram_wr_next        = 0
        self.exp_valid_next      = 0
        self.exp_step_next       = 0

        # next states
        self.exp_state_next = 0
        self.exp_addr_next  = bytearray(2)
        self.exp_m_next     = bytearray(256)
        self.exp_exp_next   = bytearray(256)
        self.exp_n_next     = bytearray(256)
        self.data_buf_next  = bytearray(256)
        self.byte_cnt_next  = 0

    # get input signals and current states
    def getState(self, exp_state, exp_addr, exp_m, exp_exp, exp_n):
        # module internal states
        self.exp_state      = exp_state
        self.exp_addr       = exp_addr
        self.exp_m          = exp_m
        self.exp_exp        = exp_exp
        self.exp_n          = exp_n

    # next state/output functions
    def update(self, wr, stb, addr, data_in, xram_data_in, xram_ack):
        # utility helper functions
        sel_reg_start = addr == self.EXP_REG_START
        sel_reg_state = addr == self.EXP_REG_STATE
        sel_reg_addr  = (addr >> 1) == (self.EXP_REG_ADDR >> 1)
        sel_reg_m     = (addr >> 8) == (self.EXP_REG_M >> 8)
        sel_reg_n     = (addr >> 8) == (self.EXP_REG_N >> 8)
        sel_reg_exp   = (addr >> 8) == (self.EXP_REG_EXP >> 8)
        
        in_range = addr >= self.EXP_ADDR_START and addr <= self.EXP_ADDR_END

        is_state_idle    = self.exp_state == self.EXP_STATE_IDLE
        is_state_operate = self.exp_state == self.EXP_STATE_OPERATE
        is_state_wait    = self.exp_state == self.EXP_STATE_WAIT
        is_state_write   = self.exp_state == self.EXP_STATE_WRITE_DATA

        wr_en = is_state_idle and wr == 1
        start_op = sel_reg_start and (data_in % 2 == 1) and wr_en
        last_byte_acked = self.byte_cnt == 255 and xram_ack

        #bigend_addr = 0xff - (addr & 0xff)
        bigend_addr = addr 
        exp_m_dataout = self.exp_m[(bigend_addr-self.EXP_REG_M) & 0xff]
        exp_n_dataout = self.exp_n[(bigend_addr-self.EXP_REG_N) & 0xff]
        exp_e_dataout = self.exp_exp[(bigend_addr-self.EXP_REG_EXP) & 0xff] 
        exp_a_dataout = self.exp_addr[addr%2]

        # How to model the non-blocking behavior here
        exp_valid = 0 if is_state_operate else 1
        """ 
        When "start", will transit to OPERATE state and set modexp to start.
        "valid" will be set to 0 in the next cycle. Here we assume the execution
        complete in one cycle, thus it is 1 in every state except OPERATE.
        """

        state_idle_next    = self.EXP_STATE_OPERATE if start_op \
                             else self.EXP_STATE_IDLE
        state_operate_next = self.EXP_STATE_WAIT
        state_wait_next    = self.EXP_STATE_WRITE_DATA if exp_valid \
                             else self.EXP_STATE_WAIT
        state_write_next   = self.EXP_STATE_IDLE if last_byte_acked \
                             else self.EXP_STATE_WRITE_DATA

        # next state/output function
        self.in_addr_range_next = 1 if in_range else 0
        self.ack_next = 1 if (in_range and stb == 1) else 0

        if sel_reg_state:
            self.data_out_next = self.exp_state & 0x03
        elif sel_reg_addr:
            self.data_out_next = exp_a_dataout
        elif sel_reg_m:
            self.data_out_next = exp_m_dataout
        elif sel_reg_n:
            self.data_out_next = exp_n_dataout
        elif sel_reg_exp:
            self.data_out_next = exp_e_dataout
        else:
            self.data_out_next = 0x00

        if is_state_idle:
            self.exp_state_next = state_idle_next
        elif is_state_operate:
            self.exp_state_next = state_operate_next
        elif is_state_wait:
            self.exp_state_next = state_wait_next
        elif is_state_write:
            self.exp_state_next = state_write_next
        else:
            self.exp_state_next = EXP_STATE_IDLE

        self.xram_stb_next = is_state_write
        self.xram_wr_next  = is_state_write
        self.exp_valid_next = exp_valid
        self.exp_step_next = self.exp_state != self.exp_state_next
        
        if start_op:
            self.byte_cnt_next = 0
        elif xram_ack:
            self.byte_cnt_next = self.byte_cnt + 1
        else:
            self.byte_cnt_next = self.byte_cnt

        addrInt = byte2int(self.exp_addr, 2)
        self.xram_addr_next = addrInt + (self.byte_cnt & 0x00ff)
        self.xram_data_out_next = self.data_buf[self.byte_cnt & 0x00ff]

        self.exp_addr_next = self.exp_addr
        if sel_reg_addr and wr_en:
            self.exp_addr_next[addr%2] = data_in & 0xff

        self.exp_m_next = self.exp_m
        if sel_reg_m and wr_en:
            self.exp_m_next[(bigend_addr-self.EXP_REG_M) & 0xff] = data_in & 0xff

        self.exp_n_next = self.exp_n
        if sel_reg_n and wr_en:
            self.exp_n_next[(bigend_addr-self.EXP_REG_N) & 0xff] = data_in & 0xff

        self.exp_exp_next = self.exp_exp
        if sel_reg_exp and wr_en:
            self.exp_exp_next[(bigend_addr-self.EXP_REG_EXP) & 0xff] = data_in & 0xff

        if start_op:
            self.data_buf_next = encrypt(self.exp_n, self.exp_exp, self.exp_m)

        # Update all the states with next values
        self.exp_state = self.exp_state_next
        self.exp_addr  = self.exp_addr_next
        self.exp_m     = self.exp_m_next
        self.exp_n     = self.exp_n_next
        self.exp_exp   = self.exp_exp_next
        self.byte_cnt  = self.byte_cnt_next
        self.data_buf  = self.data_buf_next

        res = (self.ack_next, self.in_addr_range_next, self.data_out_next, 
               self.xram_addr_next, self.xram_data_out_next, 
               self.xram_stb_next, self.xram_wr_next, 
               self.exp_valid_next, self.exp_step_next)
        return res

def test(argv):
    init_state = MODEXP.EXP_STATE_IDLE
    init_addr  = bytearray(2)
    message = bytearray('This is the testing message')
    pKey = 65537
    modulN = 0x98a918a2a7a893f779e0c1b7e6208904e973b45db2a3d34794ee237e01c1f2d74b93764bc82ff8a90c356fc363eb34aa48dadfe815222f87a9c04c6ece584fc9ab3db560fd36d1bea51bf63a00c13f41cfbd60bd59ccbdf0fbefcd24267c16205c2b6249c39d58482267abd60ead9e09b5f9ee89d8e8ba5d2818c0ff52f165ee4f352338545db40a368f1962303bf9899cece30af26c7e6bf90a4baaf3eced8e29da8f744ac840d0aaf97c400b1d856383f60ec9e6abb62ed5e7e97b3b4aae55519e4f3cae5d3a979279fe2ad1a0bdbe559b307bd948c659967eddeae518080065c985a6b058f297835d1d8fdf81573b446a7a9c1ac4b05527d5327b247e18a9
    init_m = bytearray(256)
    for i in xrange(len(message)):
        init_m[i] = message[i]
    init_exp = int2byte(pKey, 256) 
    init_n = int2byte(modulN, 256)
    
    mod = MODEXP()
    #mod.getState(init_state, init_addr, init_m, init_exp, init_n)

    # input: wr, stb, addr, data_in, xram_data_in, xram_ack
    # output: ack, in_addr_range, data_out, xram_addr, xram_data_out, xram_stb, xram_wr, valid, step
    # write addr
    for i in xrange(2):
        mod.update(1, 1, mod.EXP_REG_ADDR+i, init_addr[i], 0, 0)
    assert mod.exp_addr == init_addr
    # write message
    for i in xrange(256):
        mod.update(1, 1, mod.EXP_REG_M+i, init_m[i], 0, 0)
    assert mod.exp_m == init_m
    # write modulo
    for i in xrange(256):
        mod.update(1, 1, mod.EXP_REG_N+i, init_n[i], 0, 0)
    assert mod.exp_n == init_n
    # write exponent
    for i in xrange(256):
        mod.update(1, 1, mod.EXP_REG_EXP+i, init_exp[i], 0, 0)
    assert mod.exp_exp == init_exp;
    # read addr
    a_set = bytearray(2)
    for i in xrange(2):
        res = mod.update(0, 1, mod.EXP_REG_ADDR+i, 0, 0, 0)
        a_set[i] = res[2]
    assert a_set == init_addr
    # read message
    a_set = bytearray(2)
    m_set = bytearray(256)
    for i in xrange(256):
        res = mod.update(0, 1, mod.EXP_REG_M+i, 0, 0, 0)
        m_set[i] = res[2]
    assert m_set == init_m
    # read modulo 
    n_set = bytearray(256)
    for i in xrange(256):
        res = mod.update(0, 1, mod.EXP_REG_N+i, 0, 0, 0)
        n_set[i] = res[2]
    assert n_set == init_n
    # read exponent
    e_set = bytearray(256)
    for i in xrange(256):
        res = mod.update(0, 1, mod.EXP_REG_EXP+i, 0, 0, 0)
        e_set[i] = res[2]
    assert e_set == init_exp
    # read state 
    res = mod.update(0, 1, mod.EXP_REG_STATE, 0, 0, 0)
    assert res[2] == mod.EXP_STATE_IDLE
    # Start operation
    res = mod.update(1, 1, mod.EXP_REG_START, 1, 0, 0)
    assert mod.exp_state == mod.EXP_STATE_OPERATE
    # cache the xram --> encryted results
    xram = bytearray(256)
    xram_ack = 0
    for i in xrange(265) :
        res = mod.update(0, 1, mod.EXP_REG_STATE, 0, 0, xram_ack)
        xram_addr, xram_data_out = res[3], res[4]
        if res[5] & res[6]:
            xram[ xram_addr ] = xram_data_out
        xram_ack = 1 if (res[5] & res[6]) else 0
    enc_text = byte2int(xram, 256)
    assert enc_text == byte2int( encrypt(init_n, init_exp, init_m), 256 )
    assert mod.exp_state == mod.EXP_STATE_IDLE

    print "Pass"

if __name__ == '__main__':
    test(sys.argv)
