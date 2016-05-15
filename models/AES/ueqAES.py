import argparse
import ila
import time
import os

def readpyast(m, name):
    filename = os.path.join('asts', 'u'+name+'_en')
    if os.path.exists(filename):
        return m.importOne(filename)
    else:
        raise IOError, "File doesn't exist: " + filename

def check():
    um = ila.Abstraction("aes")

    # init the state var.
    # common state
    state       = um.reg('aes_state', 2)
    opaddr      = um.reg('aes_addr', 16)
    oplen       = um.reg('aes_len', 16)
    keysel      = um.reg('aes_keysel', 1)
    ctr         = um.reg('aes_ctr', 128)
    key0        = um.reg('aes_key0', 128)
    key1        = um.reg('aes_key1', 128)
    xram        = um.mem('XRAM', 16, 8)
    aes         = um.fun('aes', 128, [128, 128, 128])
    # uinst state
    rd_data      = um.reg('rd_data', 128)
    enc_data     = um.reg('enc_data', 128)
    byte_cnt     = um.reg('byte_cnt', 16)

    # fetch and decode.
    um.fetch_expr = state
    um.decode_exprs = [state == i for i in [1, 2, 3]]

    # now read in the uarch state.
    rd_data_nxt = readpyast(um, 'rd_data')
    # this is fixed.
    aes_key = ila.ite(keysel == 0, key0, key1)
    aes_enc_data = ila.appfun(aes, [ctr, aes_key, rd_data])
    enc_data_nxt = ila.ite(state == 2, aes_enc_data, enc_data)
    # xram
    uxram_nxt = readpyast(um, 'XRAM')

if __name__ == '__main__':
    check()

