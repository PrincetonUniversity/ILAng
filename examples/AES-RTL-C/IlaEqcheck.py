#!/usr/bin/python
import os
import argparse
import ila
import EqCheckLib

def checkPath(pathname):
    if not os.path.exists(pathname):
        print pathname,'does not exists!'
        return False
    if not os.path.isdir(pathname):
        print pathname,'is not a directory'
        return False
    if not os.path.exists(os.path.join(pathname, 'all')):
        print pathname,'does not contain an ILA-IR'
        return False
    if not os.path.exists(os.path.join(pathname, 'allu')):
        print pathname,'does not a complete ILA-IR'
        return False
    return True
    

def loadILAs(vname,cname):
    vILA = ila.Abstraction('vaes')
    vILA.importAll(os.path.join(vname, 'all') )
    vuILA = vILA.get_microabstraction('aes_compute')
    vuILA.importAll(os.path.join(vname, 'allu'))
    
    cILA = ila.Abstraction('caes')
    cILA.importAll(os.path.join(cname, 'all') )
    cuILA = cILA.get_microabstraction('aes_compute')
    cuILA.importAll(os.path.join(cname, 'allu') )

    return (vILA,vuILA,cILA,cuILA)

def Checking(vname,cname):
    (vILA,vuILA,cILA,cuILA) = loadILAs(vname, cname)
    eq = EqCheckLib.EQCheck(vILA,vuILA,cILA,cuILA)
    
    try:
        cmd_Vlg           = vuILA.getinp('cmd')
        cmdaddr_Vlg       = vuILA.getinp('cmdaddr')
        cmddata_Vlg       = vuILA.getinp('cmddata')
        aes_state_Vlg     = vuILA.getreg('aes_state')
        byte_cnt_Vlg      = vuILA.getreg('byte_cnt') 
        blk_cnt_Vlg       = vuILA.getreg('blk_cnt') 
        oped_byte_cnt_Vlg = vuILA.getreg('oped_byte_cnt')
        uaes_ctr_Vlg      = vuILA.getreg('uaes_ctr')
        aes_len_Vlg       = vuILA.getreg('aes_len')
        

        cmd_C             = cuILA.getinp('cmd')
        cmdaddr_C         = cuILA.getinp('cmdaddr')
        cmddata_C         = cuILA.getinp('cmddata')
        aes_state_C       = cuILA.getreg('aes_state')
        aes_ctr_C         = cuILA.getreg('aes_ctr')
        uaes_ctr_C        = cuILA.getreg('uaes_ctr')
        blk_cnt_C         = cuILA.getreg('blk_cnt') 
        aes_len_C         = cuILA.getreg('aes_len')
    except IndexError:
        print 'Error: ILA does not match refinement relations'
        exit(1)
        
    
    try:
        cuILA.getreg('oped_byte_cnt')
        print 'Error: ILA does not match refinement relations'
        exit(1)
    except IndexError:
        pass

    inductiveInvariant_Vlg = [  vuILA.fetch_valid , 
                                ( aes_state_Vlg == 1 ) & ( byte_cnt_Vlg == 0) , 
                                blk_cnt_Vlg == oped_byte_cnt_Vlg ,
                                blk_cnt_Vlg <= aes_len_Vlg 
                            ]

    inductiveInvariant_C   = [  cuILA.fetch_valid, 
                                aes_state_C == 1,  
                                blk_cnt_C <= aes_len_C 
                            ]
    
    print '##### BASE STEP #####'
    eq.BaseCase(1,1, 
        (cmd_Vlg==2) & ( cmdaddr_Vlg == 0xff00 ) & ( cmddata_Vlg == 1) ,
        (cmd_C  ==2) & ( cmdaddr_C   == 0xff00 ) & ( cmddata_C   == 1) ,
        conclusion1 = inductiveInvariant_Vlg,
        conclusion2 = inductiveInvariant_C,
        CrossConclusion = [('blk_cnt','blk_cnt'), ('uaes_ctr','uaes_ctr')]
        )

    print '##### INDUCTIVE STEP #####'
    r = \
        eq.InductiveStep(34,4,
        inv1 = inductiveInvariant_Vlg,
        inv2 = inductiveInvariant_C,
        invCross = [('blk_cnt','blk_cnt'), ('uaes_ctr','uaes_ctr')]
        )
    
    print '##### EXIT STEP #####'
    r = r and \
        eq.Exit(34,4,
        a1 = inductiveInvariant_Vlg,
        a2 = inductiveInvariant_C,
        c1 = [],
        c2 = [],
        CrossAssumpt = [('blk_cnt','blk_cnt'), ('uaes_ctr','uaes_ctr')],
        CrossConclusion = [ ('aes_state','aes_state') , ('enc_data','enc_data')]
        )

    if r:
        print 'Equivalence between "' + vILA.name + '" and "' + cILA.name + '" holds.' 
    else:
        print  vILA.name, 'and' , cILA.name, 'are not equivalent.' 


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='ILA Equivalence Checking Helper')
    parser.add_argument('-v', type = str, help = 'ILA AST from Verilog', default="vILA")
    parser.add_argument('-c', type = str, help = 'ILA AST from C', default='cILA')
    args = parser.parse_args()
    if not args.v or not checkPath(args.v):
        print 'Incorrect path', args.v,' for ILA AST from Verilog'
        exit(1)
    
    if not args.c or not checkPath(args.c):
        print 'Incorrect path', args.c,' for ILA AST from C'
        exit(1)
        
    Checking(args.v, args.c)
