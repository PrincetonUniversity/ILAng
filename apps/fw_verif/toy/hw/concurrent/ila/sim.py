# simulator for concurrent acc_regs

class ACC():
    IDLE = 0
    RD   = 1
    OP1  = 2
    OP2  = 3
    WR   = 4

    def __init__ (self):
        self.state      = self.IDLE
        self.rdaddr     = 0
        self.wraddr     = 0
        self.oplen      = 0
        self.bytes_read = 0

    def simulate (self, s_in):
        cmd     = s_in ['cmd']
        cmdaddr = s_in ['cmdaddr']
        cmddata = s_in ['cmddata']

        self.state      = s_in ['acc_state']
        self.rdaddr     = s_in ['rd_addr']
        self.wraddr     = s_in ['wr_addr']
        self.oplen      = s_in ['acc_len']
        self.xram       = s_in ['XRAM']
        self.bytes_read = s_in ['bytes_read']

        # Execute the command
        state_nxt = self.state
        num_nxt = self.bytes_read
        if self.state == self.IDLE:
            if cmd == 2 and cmdaddr == 0xfe00 and cmddata == 1:
                state_nxt = self.RD
                num_nxt = 0
            else:
                state_nxt = self.state
                num_nxt = self.bytes_read
        elif self.state == self.RD:
            state_nxt = self.OP1
            num_nxt = self.bytes_read + 1
        elif self.state == self.OP1:
            state_nxt = self.OP2
            num_nxt = self.bytes_read
        elif self.state == self.OP2:
            if (self.bytes_read & 0xffff) < (self.oplen & 0xffff):
                state_nxt = self.RD
                num_nxt = self.bytes_read
            else:
                state_nxt = self.WR
                num_nxt = self.bytes_read
        elif self.state == self.WR:
            state_nxt = self.IDLE
            num_nxt = self.bytes_read

        self.state = state_nxt
        self.bytes_read = num_nxt

        s_out = self.s_dict()
        return s_out

    def s_dict (self):
        return {
            'acc_state'     : self.state,
            'rd_addr'       : self.rdaddr,
            'wr_addr'       : self.wraddr,
            'acc_len'       : self.oplen,
            'XRAM'          : self.xram,
            'bytes_read'    : self.bytes_read
        }
