# simulator for atomic acc_regs

class ACC ():
    IDLE = 0
    RD   = 1
    OP1  = 2
    OP2  = 3
    WR   = 4

    def __init__ (self):
        self.state  = self.IDLE
        self.rdaddr = 0
        self.wraddr = 0
        self.oplen  = 0

    def simulate (self, s_in):
        cmd     = s_in ['cmd']
        cmdaddr = s_in ['cmdaddr']
        cmddata = s_in ['cmddata']

        self.state  = s_in ['acc_state']
        self.rdaddr = s_in ['rd_addr']
        self.wraddr = s_in ['wr_addr']
        self.oplen  = s_in ['acc_len']
        self.xram   = s_in ['XRAM']

        done = False
        if cmd == 2:
            if cmdaddr == 0xfe00:
                if cmddata == 1:
                    self.state = self.IDLE
                    done = True
        if done == False:
            self.state = self.IDLE

        s_out = self.s_dict ()
        return s_out

    def s_dict (self):
        return {
            'acc_state' : self.state,
            'rd_addr'   : self.rdaddr,
            'wr_addr'   : self.wraddr,
            'acc_len'   : self.oplen,
            'XRAM'      : self.xram
        }
