# RTL simulator for AES+XRAM (uinst version)

from mmio import mmiodev, NOP, RD, WR
import subprocess
import ila

def hex2arr(n, l):
    l = '%0' + str(l//4) + 'x'
    return l % n

class AES():
    def __init__(self):
        self.aes_state  = 0
        self.aes_addr   = 0
        self.aes_len    = 0
        self.aes_keysel = 0
        self.aes_ctr    = 0 
        self.aes_key0   = 0
        self.aes_key1   = 0
        self.data_out   = 0

        self.byte_cnt   = 0
        self.blk_cnt    = 0
        self.oped_byte_cnt = 0
        self.rd_data    = 0
        self.enc_data   = 0
        self.xram       = ila.MemValues(16, 8, 0x0)

        self.inFile     = 'assign.in'
        self.outFile    = 'result.out'

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
        self.byte_cnt   = self.get(s_in,'byte_cnt', 0)
        self.blk_cnt    = self.get(s_in,'blk_cnt', 0)
        self.oped_byte_cnt = self.get(s_in, 'oped_byte_cnt', 0)
        self.rd_data    = self.get(s_in,'rd_data', 0)
        self.enc_data   = self.get(s_in,'enc_data', 0)
        self.xram       = self.get(s_in,'XRAM', ila.MemValues(16, 8, 0x0))

        return cmd, cmdaddr, cmddata

    def assign(self, s_in):
        cmd, cmdaddr, cmddata = self.extract(s_in)
        f = open(self.inFile, 'w')
        f.write(".AES_IP_START\n")
        
        f.write("cmd "          + hex2arr(cmd, 8) + "\n")
        f.write("cmdaddr "      + hex2arr(cmdaddr, 16) + "\n")
        f.write("cmddata "      + hex2arr(cmddata, 8) + "\n")
        f.write("aes_state "    + hex2arr(self.aes_state, 8) + "\n")
        f.write("aes_addr "     + hex2arr(self.aes_addr, 16) + "\n")
        f.write("aes_len "      + hex2arr(self.aes_len, 16) + "\n")
        f.write("aes_keysel "   + hex2arr(self.aes_keysel, 8) + "\n")
        f.write("aes_ctr "      + hex2arr(self.aes_ctr, 128) + "\n")
        f.write("aes_key0 "     + hex2arr(self.aes_key0, 128) + "\n")
        f.write("aes_key1 "     + hex2arr(self.aes_key1, 128) + "\n")
        f.write("data_out "     + hex2arr(self.data_out, 8) + "\n")
        f.write("byte_cnt "     + hex2arr(self.byte_cnt, 16) + "\n")
        f.write("oped_byte_cnt "+ hex2arr(self.oped_byte_cnt, 16) + "\n")
        f.write("blk_cnt "      + hex2arr(self.blk_cnt, 16) + "\n")
        f.write("rd_data "      + hex2arr(self.rd_data, 128) + "\n")
        f.write("enc_data "     + hex2arr(self.enc_data, 128) + "\n")
        f.write("xram ")
        print >> f, self.xram
        f.write("\n")

        f.write(".AES_IP_END\n")
        f.close()

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
            elif (wordList[0] == "oped_byte_cnt"):
                self.oped_byte_cnt = int(wordList[1], 16)
            elif (wordList[0] == "blk_cnt"):
                self.blk_cnt = int(wordList[1], 16)
            elif (wordList[0] == "rd_data"):
                self.rd_data = int(wordList[1], 16)
            elif (wordList[0] == "enc_data"):
                self.enc_data = int(wordList[1], 16)
            elif (wordList[0] == "xram"):
                self.xram = ila.MemValues(16, 8, 0x0)
                line = f.readline()
                wordList = line.split()
                while (wordList[0] != "default:"):
                    addr = int(wordList[0], 16)
                    data = int(wordList[1], 16)
                    self.xram[addr] = data
                    line = f.readline()
                    wordList = line.split()
                defVal = int(wordList[1], 16)
                self.xram.default = defVal
            else: 
                assert(False)
            line = f.readline()

        f.close()
        
    def dump(self, prefix, s):
        byte_cnt = s['byte_cnt']
        blk_cnt = s['blk_cnt']
        aes_addr = s['aes_addr']
        print '%s: st:%d byte_cnt:%d blk_cnt:%x addr:%x wr_addr:%x enc_data:%x %s' % (
                    prefix, s['aes_state'], 
                    byte_cnt, blk_cnt, aes_addr, 
                    (byte_cnt + blk_cnt + aes_addr) & 0xffff,
                    s['enc_data'], str(s['XRAM']))

    def simMicro(self, s_in):
        self.assign(s_in)
        # self.dump('IN', s_in)
        subprocess.call(['./AESsim', 'micro', self.inFile, self.outFile])
        self.getStates()
        s_out = self.s_dict()
        # self.dump('OUT', s_in)
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
            'blk_cnt'       : self.blk_cnt,
            'oped_byte_cnt' : self.oped_byte_cnt,
            'rd_data'       : self.rd_data,
            'enc_data'      : self.enc_data,
            'XRAM'          : self.xram
        }

def testAES():
    aes = AES()
    
    s_in = aes.s_dict()
    s_in['cmd'] =  1
    s_in['cmdaddr'] = 0xff04
    s_in['cmddata'] = 0x12
    s_in['aes_state'] = 0x01
    s_in['aes_ctr'] = 0x123f000000

    s_out = aes.simMicro(s_in)

    s_in = aes.s_dict()
    s_in['cmd'] = 1
    s_in['cmdaddr'] = 0xff01
    s_in['cmddata'] = 2
    s_in['aes_state'] = 0x1
    s_in['aes_len'] = 0x10
    s_in['byte_cnt'] = 0xf

    s_out = aes.simMicro(s_in)


if __name__ == '__main__':
    testAES()


