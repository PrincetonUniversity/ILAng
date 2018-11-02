# simulator for synthesizing RSA ILA

from mmio import mmiodev, NOP, RD, WR

class RSA (mmiodev):
    IDLE    = 0
    OPERATE = 1
    WAIT    = 2
    WRITE   = 3

    def __init__ (self):
        mmiodev.__init__ (self)
        self.addReg ('rsa_start', 0xfe00, 1)
        self.addReg ('rsa_state', 0xfd01, 1, readonly = True)
        self.addReg ('rsa_addr', 0xfd02, 2)

        """
        self.addReg ('rsa_M', 0xfa00, 256)
        self.addReg ('rsa_E', 0xfb00, 256)
        self.addReg ('rsa_N', 0xfc00, 256)
        """
        self.rsa_M    = [0] * 256
        self.rsa_E    = [0] * 256
        self.rsa_N    = [0] * 256
        self.rsa_buff = [0] * 256
        self.byte_counter = 0

    rsa_state = property (lambda s: s.getRegI ('rsa_state'), lambda s, v: s.setRegI ('rsa_state', v))
    rsa_addr  = property (lambda s: s.getRegI ('rsa_addr'), lambda s, v: s.setRegI ('rsa_addr', v))

    def simulate (self, s_in):
        cmd     = s_in ['cmd']
        cmdaddr = s_in ['cmdaddr']
        cmddata = s_in ['cmddata']

        self.rsa_state      = s_in ['rsa_state']
        self.rsa_addr       = s_in ['rsa_addr']
        self.rsa_M          = s_in ['rsa_M']
        self.rsa_E          = s_in ['rsa_E']
        self.rsa_N          = s_in ['rsa_N']
        self.rsa_buff       = s_in ['rsa_buff']
        self.byte_counter   = s_in ['rsa_byte_counter']
        self.xram           = s_in ['XRAM']

        dataout = 0
        # execute command.
        if cmd == RD:
            found, data = self.read (cmdaddr)
            if found:
                dataout = data
            s_out = self.s_dict()
            s_out['dataout'] = dataout
            return s_out
        """
        if not cmd == WR:
            s_out = self.s_dict()
            return s_out
        """

        if self.rsa_state == self.IDLE and cmd == WR:
            if cmdaddr == 0xfd00 and cmddata == 1:
                state_nxt = self.OPERATE
                self.byte_counter = 0
            else:
                state_nxt = self.IDLE
                self.write (cmdaddr, cmddata)
        elif self.rsa_state == self.OPERATE:
            state_nxt = self.WAIT
        elif self.rsa_state == self.WAIT:
            state_nxt = self.WRITE  # assuming valid is immediately true.
            self.rsa_buff |= 1 << 8 # XXX representing RSA operation.
        elif self.rsa_state == self.WRITE:
            if self.byte_counter == 255:
                state_nxt = self.IDLE
            else:
                state_nxt = self.WRITE
                up = (255 - self.byte_counter) * 8
                self.xram [self.rsa_addr+self.byte_counter] =  \
                    (self.rsa_buff >> up) & 0xff
                self.byte_counter = self.byte_counter + 1
        else:
            print 'Unknown state'
            return s_in

        self.rsa_state = state_nxt

        s_out = self.s_dict()
        s_out ['dataout'] = dataout
        return s_out

    def s_dict (self):
        return {
            'rsa_state'         : self.rsa_state,
            'rsa_addr'          : self.rsa_addr,
            'rsa_M'             : self.rsa_M,
            'rsa_E'             : self.rsa_E,
            'rsa_N'             : self.rsa_N,
            'rsa_buff'          : self.rsa_buff,
            'rsa_byte_counter'  : self.byte_counter,
            'XRAM'              : self.xram
        }
