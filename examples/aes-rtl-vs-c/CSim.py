# RTL simulator for AES+XRAM (uinst version)

import os
import subprocess
import ila
import CInstrument

NOP = 0
RD  = 1
WR  = 2

def hex2arr(n, l):
    l = '%0' + str(l//4) + 'x'
    return l % n

class CSim():
    def __init__(self):
        self.aes_state  = 0
        self.aes_addr   = 0
        self.aes_len    = 0
        self.aes_ctr    = 0 
        self.aes_key0   = 0
        self.data_out   = 0

        self.byte_cnt   = 0
        self.aes_time   = 0
        self.blk_cnt    = 0
        self.oped_byte_cnt = 0
        self.rd_data    = 0
        self.enc_data   = 0
        self.xram       = ila.MemValues(16, 8, 0x0)

        self.CAnno      = 'C/Cinst.c'
        self.Cinst      = CInstrument.CInstrument('C/AES_CTR_TOP.c',self.CAnno)
        self.outFile    = 'Cresult.out'

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
        self.aes_ctr    = s_in['aes_ctr']
        self.aes_key0   = s_in['aes_key0']
        self.uaes_ctr   = self.get(s_in,'uaes_ctr',0)
        self.blk_cnt    = self.get(s_in,'blk_cnt', 0)
        self.rd_data    = self.get(s_in,'rd_data', 0)
        self.enc_data   = self.get(s_in,'enc_data', 0)
        self.xram       = self.get(s_in,'XRAM', ila.MemValues(16, 8, 0x0))

        return cmd, cmdaddr, cmddata

    def assignMacro(self, s_in):
        cmd, cmdaddr, cmddata = self.extract(s_in)
        self.Cinst.genCcode(s_in,'aes')
    def assignMicro(self,s_in):
        cmd, cmdaddr, cmddata = self.extract(s_in)
        s_in['cmd'] = 2
        s_in['cmdaddr'] = 0xff00
        s_in['cmddata'] = 1
        #if s_in['aes_len'] == 0:
        #    s_in['aes_len'] = 1
        self.Cinst.genCcode(s_in,'aes_compute')


    def getStates(self):
        f = open(self.outFile, 'r')

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
            elif (wordList[0] == "aes_ctr"):
                self.aes_ctr = int(wordList[1], 16)
            elif (wordList[0] == "aes_key0"):
                self.aes_key0 = int(wordList[1], 16)
            elif (wordList[0] == "blk_cnt"):
                self.blk_cnt = int(wordList[1], 16)
            elif (wordList[0] == "rd_data"):
                self.rd_data = int(wordList[1], 16)
            elif (wordList[0] == "uaes_ctr"):
                self.uaes_ctr = int(wordList[1], 16)
            elif (wordList[0] == "enc_data"):
                self.enc_data = int(wordList[1], 16)
            elif (wordList[0] == "XRAM"): # need some changes
                self.xram = ila.MemValues(16, 8, 0x0)
                nopair = int(wordList[1],10)
                defVal = int(wordList[2],16)
                self.xram.default = defVal
                for idx in range(nopair):
                    line = f.readline()
                    wordList = line.split()
                    addr = int(wordList[0],16)
                    data = int(wordList[1],16)
                    self.xram[addr] = data
            elif wordList[0] in ['cmd','cmdaddr','cmddata']: 
                pass
            else:
                print wordList[0]
                assert(False)
            line = f.readline()

        f.close()
        
    def dump(self, prefix, s):
        blk_cnt = s['blk_cnt']
        aes_addr = s['aes_addr']
        print '%s: st:%d  blk_cnt:%x addr:%x enc_data:%x %s, aes_len:%x' % (
                    prefix, s['aes_state'], 
                    blk_cnt, aes_addr, 
                    s['enc_data'], str(s['XRAM']),s["aes_len"])
    def _dump(self,s_in):
        print s_in

    def simMicro(self, s_in):
        self.assignMicro(s_in)
        self.dump('IN', s_in)
        subprocess.call(['rm', self.outFile])
        subprocess.call(['gcc',self.CAnno,'-o','test','-w'])
        subprocess.call(['./test'])
        self.getStates()
        print 'state!=',self.aes_state,'blk_count\'=%x' % self.blk_cnt
        s_out = self.s_dict()
        # self.dump('OUT', s_in)
        return s_out

    def simMacro(self, s_in):
        self.assignMacro(s_in)
        #self._dump( s_in)
        subprocess.call(['rm', self.outFile])
        subprocess.call(['gcc',self.CAnno,'-g','-o','C/test'])
        subprocess.call(['./C/test'])
        self.getStates()
        s_out = self.s_dict()
        
        return s_out
        
        
    def s_dict(self):
        return {
            'aes_state'     : self.aes_state,
            'aes_addr'      : self.aes_addr,
            'aes_len'       : self.aes_len,
            'aes_ctr'       : self.aes_ctr,
            'aes_key0'      : self.aes_key0,
            'blk_cnt'       : self.blk_cnt,
            'rd_data'       : self.rd_data,
            'enc_data'      : self.enc_data,
            'uaes_ctr'      : self.uaes_ctr,
            'XRAM'          : self.xram
        }
        

