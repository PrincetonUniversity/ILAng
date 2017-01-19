#!/usr/bin/python
import argparse
import ila
import CTemplate
import time
from CSim import CSim


    # micro-synthesis
def syn(m,um):
    usim = lambda s: CSim().simMicro(s)
    for s in [  'aes_state', 'uaes_ctr', 'blk_cnt',  'rd_data','XRAM']:
        print 'micro-syn: ', s
        um.synthesize(s, usim)
        print '%s: %s' % (s, str(um.get_next(s)))
        ast = um.get_next(s)
        m.exportOne(ast, 'cILA/u_%s' % (s))

    sim = lambda s: CSim().simMacro(s)
    for s in [ 'aes_state','aes_addr','aes_len', 'aes_ctr','aes_key0']: # 
        print 'macro-syn: ', s
        m.synthesize(s, sim)
        ast = m.get_next(s)
        print '%s: %s' % (s, str(ast))
        m.exportOne(ast, 'cILA/%s' % (s))
        
    m.exportAll('cILA/all')
    um.exportAll('cILA/allu')



import os

if __name__ == '__main__':
    if not os.access("cILA", os.R_OK):
        os.mkdir('cILA')
        
    ila.setloglevel(1, "")
    parser = argparse.ArgumentParser()
    parser.add_argument("--en", type=int, default=1, 
                        help="enable parameterized synthesis.")
    #parser.add_argument("state", type=str, nargs='+',
    #                    help="the state to synthesize.")
    args = parser.parse_args()
    m,um = CTemplate.createAESILA(args.en)
    syn(m,um)

