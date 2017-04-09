import argparse
import ila
import time
import os

def readpyast(m, name):
    filename = os.path.join('aes-py-uinst/uasts', 'u'+name+'_en')
    if os.path.exists(filename):
        return m.importOne(filename)
    else:
        raise IOError, "File doesn't exist: " + filename
def readvast(m, name):
    filename = os.path.join('aes-rtl-uinst/asts', 'u_'+name+'_en')
    if os.path.exists(filename):
        return m.importOne(filename)
    else:
        raise IOError, "File doesn't exist: " + filename

def readPy():
    um = ila.Abstraction("aes1")

    # init the state var.
    # common state
    state           = um.reg('aes_state', 2)
    opaddr          = um.reg('aes_addr', 16)
    oplen           = um.reg('aes_len', 16)
    keysel          = um.reg('aes_keysel', 1)
    ctr             = um.reg('aes_ctr', 128)
    key0            = um.reg('aes_key0', 128)
    key1            = um.reg('aes_key1', 128)
    xram            = um.mem('XRAM', 16, 8)
    aes             = um.fun('aes', 128, [128, 128, 128])
    # uinst state
    rd_data         = um.reg('rd_data', 128)
    enc_data        = um.reg('enc_data', 128)
    byte_cnt        = um.reg('byte_cnt', 16)

    # state
    state_next = readpyast(um, 'aes_state')
    um.set_init('aes_state', um.const(1, 2))
    um.set_next('aes_state', state_next)
    # byte_cnt
    byte_cnt_next = readpyast(um, 'byte_cnt')
    um.set_next('byte_cnt', byte_cnt_next)
    um.set_init('byte_cnt', um.const(0, 16))
    # rd_data
    rd_data_nxt = readpyast(um, 'rd_data')
    um.set_next('rd_data', rd_data_nxt)
    # enc_data
    aes_key = ila.ite(keysel == 0, key0, key1)
    aes_enc_data = ila.appfun(aes, [ctr, aes_key, rd_data])
    enc_data_nxt = ila.ite(state == 2, aes_enc_data, enc_data)
    um.set_next('enc_data', enc_data_nxt)
    # xram
    uxram_nxt = readpyast(um, 'XRAM')
    um.set_next('XRAM', uxram_nxt)
    # the rest doesn't change.
    um.set_next('aes_addr', opaddr)
    um.set_next('aes_len', oplen)
    um.set_ipred('aes_len', (oplen != 0) & (oplen[3:0] == 0))
    um.set_next('aes_keysel', keysel)
    um.set_next('aes_ctr', ctr)
    um.set_next('aes_key0', key0)
    um.set_next('aes_key1', key1)


    return um

def readV():
    um = ila.Abstraction("aes2")

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
    byte_cnt     = um.reg('byte_cnt', 4)
    blk_cnt       = um.reg('blk_cnt', 16)
    oped_byte_cnt = um.reg('oped_byte_cnt', 16)

    # state
    state_next = readvast(um, 'aes_state')
    um.set_init('aes_state', um.const(1, 2))
    um.set_next('aes_state', state_next)

    # byte_cnt
    byte_cnt_next = readvast(um, 'byte_cnt')
    um.set_next('byte_cnt', byte_cnt_next)
    um.set_init('byte_cnt', um.const(0, 4))

    # blk_cnt
    blk_cnt_next = readvast(um, 'blk_cnt')
    um.set_next('blk_cnt', blk_cnt_next)
    um.set_init('blk_cnt', um.const(0, 16))

    # oped_byte_cnt
    oped_byte_cnt_next = readvast(um, 'oped_byte_cnt')
    um.set_next('oped_byte_cnt', oped_byte_cnt_next)
    um.set_init('oped_byte_cnt', um.const(0, 16))

    # rd_data
    rd_data_nxt = readvast(um, 'rd_data')
    um.set_next('rd_data', rd_data_nxt)

    # enc_data
    aes_key = ila.ite(keysel == 0, key0, key1)
    aes_enc_data = ila.appfun(aes, [ctr, aes_key, rd_data])
    enc_data_nxt = ila.ite(state == 2, aes_enc_data, enc_data)
    um.set_next('enc_data', enc_data_nxt)

    # xram
    uxram_nxt = readvast(um, 'XRAM')
    um.set_next('XRAM', uxram_nxt)

    # the rest doesn't change.
    um.set_next('aes_addr', opaddr)
    um.set_next('aes_len', oplen)
    um.set_ipred('aes_len', (oplen != 0) & (oplen[3:0] == 0))
    um.set_next('aes_keysel', keysel)
    um.set_next('aes_ctr', ctr)
    um.set_next('aes_key0', key0)
    um.set_next('aes_key1', key1)

    assert um.areEqualUnrolled(33, byte_cnt, um.const(0x0, 4))

    return um

if __name__ == '__main__':

    um1 = readPy()
    um2 = readV()

    xram1 = um1.getmem('XRAM')
    xram2 = um2.getmem('XRAM')

    st1 = um1.getreg('aes_state')
    st2 = um2.getreg('aes_state')

    rd_data1 = um1.getreg('rd_data')
    rd_data2 = um2.getreg('rd_data')

    byte_cnt1 = um1.getreg('byte_cnt')
    blk_cnt2 = um2.getreg('blk_cnt')

    print 'checking aes_state'
    st = time.clock()
    print ila.bmc(3, um1, st1, 33, um2, st2)
    dt = time.clock() - st
    print 'time: %.2f' % dt

    print 'checking rd_data'
    st = time.clock()
    print ila.bmc(1, um1, rd_data1, 16, um2, rd_data2)
    dt = time.clock() - st
    print 'time: %.2f' % dt

    print 'checking XRAM'
    st = time.clock()
    print ila.bmc(3, um1, xram1, 33, um2, xram2)
    dt = time.clock() - st
    print 'time: %.2f' % dt

    print 'checking byte_cnt'
    st = time.clock()
    print ila.bmc(3, um1, byte_cnt1, 33, um2, blk_cnt2)
    dt = time.clock() - st
    print 'time: %.2f' % dt
