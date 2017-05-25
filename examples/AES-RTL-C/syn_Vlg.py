#!/usr/bin/python
import argparse
import ila
import VTemplate
import time
from VSim import AES as AESsim


    # micro-synthesis
def syn(m,um):
    usim = lambda s: AESsim().simMicro(s)
    
    sim = lambda s: AESsim().simMacro(s)
    for s in [ 'aes_len','aes_state','aes_addr','aes_ctr','aes_key0']: #
        m.synthesize(s, sim)
        ast = m.get_next(s)
        print '%s: %s' % (s, str(ast))
        m.exportOne(ast, 'vILA/%s' % (s))
        
    for s in [ 'enc_data', 'uaes_ctr', 'aes_time','aes_state', 'byte_cnt', 'blk_cnt', 'oped_byte_cnt', 'rd_data','XRAM']:
        print 'micro-syn: ', s
        um.synthesize(s, usim)
        print '%s: %s' % (s, str(um.get_next(s)))
        ast = um.get_next(s)
        m.exportOne(ast, 'vILA/u_%s' % (s))
    
    
    
    # export ALL
    m.exportAll('vILA/all')
    um.exportAll('vILA/allu')

	


import os

if __name__ == '__main__':
    if not os.access("vILA", os.R_OK):
        os.mkdir('vILA')
        
    ila.setloglevel(1, "")
    parser = argparse.ArgumentParser()
    parser.add_argument("--en", type=int, default=1, 
                        help="enable parameterized synthesis.")
    #parser.add_argument("state", type=str, nargs='+',
    #                    help="the state to synthesize.")
    args = parser.parse_args()
    m,um = VTemplate.createAESILA(args.en)
    syn(m,um)

