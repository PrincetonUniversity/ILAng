# simulator for synthesizing RSA ILA

from mmio import mmiodev, NOP, RD, WR

class RSA (mmiodev):
    def __init__ (self):
        self.addReg ('rsa_state', 0xff00, 1, readonly =True)

    def simulate (self, s_in):
        cmd     = s_in ['cmd']

        s_out = self.s_dict()
        return s_out

    def s_dict (self):
        return {
            'rsa_state'     : self.rsa_state
        }
