# RTL simulator for AES+XRAM (uinst version)

import os
import subprocess
import ila

def to_hex(s, n):
    res = ""
    for i in xrange(n):
        num = s[n-1-i]
        res += hex(num)[2:]
    return res

def Hex(n):
    return hex(n)[2:]

class AES():
    def __init__(self):
        self.aes_state  = 0
        self.aes_addr   = 0
        self.aes_len    = 0
        self.aes_keysel = 0
        self.aes_ctr    = [0] * 16
        self.aes_key0   = [0] * 16
        self.aes_key1   = [0] * 16
        self.data_out   = 0

        self.byte_cnt   = 0
        self.rd_data    = [0] * 16
        self.enc_data   = [0] * 16

    def get(self, s, name, default):
        if name in s:
            return s[name]
        else:
            return default

    def extract(self, s_in):
        cmd     = s_in['cmd']
        cmdaddr = s_in['cmdaddr']
        cmddata = s_in['cmddata']

        self.aes_state  = s_in['aes_state']
        self.aes_addr   = s_in['aes_addr']
        self.aes_len    = s_in['aes_len']
        self.aes_keysel = s_in['aes_keysel']
        self.aes_ctr    = s_in['aes_ctr']
        self.aes_key0   = s_in['aes_key0']
        self.aes_key1   = s_in['aes_key1']
        self.data_out   = s_in['data_out']
        self.byte_cnt   = self.get(s_in,'byte_cnt', 0)
        self.rd_data    = self.get(s_in,'rd_data', 0)
        self.enc_data   = self.get(s_in,'enc_data', 0)
        self.xram       = self.get(s_in,'XRAM', ila.MemValues(16, 8, 0x0))

        return cmd, cmdaddr, cmddata

    def assign(self, s_in):
        cmd, cmdaddr, cmddata = self.extract(s_in)
        assignFile = 'assign.ip'
        f = open(assignFile, 'w')
        f.write(".AES_IP_START\n")
        
        f.write("cmd "          + Hex(cmd) + "\n")
        f.write("cmdaddr "      + Hex(cmdaddr) + "\n")
        f.write("cmddata "      + Hex(cmddata) + "\n")
        f.write("aes_state "    + Hex(self.aes_state) + "\n")
        f.write("aes_addr "     + Hex(self.aes_addr) + "\n")
        f.write("aes_len "      + Hex(self.aes_len) + "\n")
        f.write("aes_keysel "   + Hex(self.aes_keysel) + "\n")
        f.write("aes_ctr "      + to_hex(self.aes_ctr, 16) + "\n")
        f.write("aes_key0 "     + to_hex(self.aes_key0, 16) + "\n")
        f.write("aes_key1 "     + to_hex(self.aes_key1, 16) + "\n")
        f.write("data_out "     + Hex(self.data_out) + "\n")
        f.write("byte_cnt "     + Hex(self.byte_cnt) + "\n")
        f.write("rd_data "      + to_hex(self.rd_data, 16) + "\n")
        f.write("enc_data "     + to_hex(self.enc_data, 16) + "\n")
        # xram 

        f.write(".AES_IP_END\n")
        f.close()

    def getStates(self):
        resFile = "res.op"
        f = open(resFile, 'r')

        line = f.readline()
        assert(line == ".AES_OP_START\n")
        line = f.readline()
        while (line != ".AES_OP_END\n"):
            wordList = line.split()
            if (wordList[0] == "aes_state"):
                self.aes_state = int(wordList[1], 16)
            elif (wordList[0] == "aes_addr"):
                self.aes_addr = int(wordList[1], 16)
            elif (wordList[0] == "aes_len"):
                self.aes_len = int(wordList[1], 16)
            elif (wordList[0] == "aes_keysel"):
                self.aes_keysel = int(wordList[1], 16)
            elif (wordList[0] == "aes_ctr"):
                self.aes_ctr = int(wordList[1], 16)
            elif (wordList[0] == "aes_key0"):
                self.aes_key0 = int(wordList[1], 16)
            elif (wordList[0] == "aes_key1"):
                self.aes_key1 = int(wordList[1], 16)
            elif (wordList[0] == "data_out"):
                self.data_out = int(wordList[1], 16)
            elif (wordList[0] == "byte_cnt"):
                self.byte_cnt = int(wordList[1], 16)
            elif (wordList[0] == "rd_data"):
                self.rd_data = int(wordList[1], 16)
            elif (wordList[0] == "enc_data"):
                self.enc_data = int(wordList[1], 16)
            elif (wordList[0] == "xram"):
                # TODO
                print "xram not implemented"
            else: 
                assert(False)
            line = f.readline()

        f.close()
        
    def simMacro(self, s_in):

        s_out = self.s_dict()
        return s_out

    def simMicro(self, s_in):
        assign(s_in)
        subprocess.call(['./AESsim'])
        getStates()
        s_out = self.s_dict()
        return s_out

    def s_dict(self):
        return {
            'aes_state'     : self.aes_state,
            'aes_addr'      : self.aes_addr,
            'aes_len'       : self.aes_len,
            'aes_keysel'    : self.aes_keysel,
            'aes_ctr'       : self.aes_ctr,
            'aes_key0'      : self.aes_key0,
            'aes_key1'      : self.aes_key1,
            'data_out'      : self.data_out,
            'byte_cnt'      : self.byte_cnt,
            'rd_data'       : self.rd_data,
            'enc_data'      : self.enc_data,
            #'XRAM'          : self.xram
        }

def testAES():
    aes = AES()
    
    s_in = aes.s_dict()
    s_in['cmd'] =  1
    s_in['cmdaddr'] = 0xff04
    s_in['cmddata'] = 0x12
    s_in['aes_state'] = 0x00
    ctr = [0] * 16
    s_in['aes_ctr'] = [0, 0, 0, 0, 0, 0, 1, 2, 3, 15, 0, 0, 0, 0, 0, 0]

    aes.assign(s_in)

    subprocess.call(['./AESsim'])

    aes.getStates()

    s_out = aes.s_dict()

if __name__ == '__main__':
    testAES()


