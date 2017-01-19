#!/usr/bin/python

import ila
import EqCheckLib

def loadILAs():
    vILA = ila.Abstraction('vaes')
    vILA.importAll('vILA/all')
    vuILA = vILA.get_microabstraction('aes_compute')
    vuILA.importAll('vILA/allu')
    
    cILA = ila.Abstraction('caes')
    cILA.importAll('cILA/all')
    cuILA = cILA.get_microabstraction('aes_compute')
    cuILA.importAll('cILA/allu')

    return (vILA,vuILA,cILA,cuILA)

def Checking():
    (vILA,vuILA,cILA,cuILA) = loadILAs()
    eq = EqCheckLib.EQCheck(vILA,vuILA,cILA,cuILA)

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
    eq.InductiveStep(34,4,
        inv1 = inductiveInvariant_Vlg,
        inv2 = inductiveInvariant_C,
        invCross = [('blk_cnt','blk_cnt'), ('uaes_ctr','uaes_ctr')]
        )
    
    print '##### EXIT STEP #####'
    eq.Exit(34,4,
        a1 = inductiveInvariant_Vlg,
        a2 = inductiveInvariant_C,
        c1 = [],
        c2 = [],
        CrossAssumpt = [('blk_cnt','blk_cnt'), ('uaes_ctr','uaes_ctr')],
        CrossConclusion = [ ('aes_state','aes_state') , ('enc_data','enc_data')]
        )


if __name__ == '__main__':
    #ila.enablelog("Unroller")
    Checking()
