# Integrating the models
# currently the top most level  for modeling
#
#

import collections
import ila
import riscv_um


#-------------------------
#   Priv Inst  DEOCDE
#-------------------------

# width 0:b 1:h 2:w 3:d



# ---------------
# AUX Func
# ---------------

# set short name to this

RVEncoding = riscv_um.Encoding
XLEN = riscv_um.XLEN
const = riscv_um.const

b0      = const(0,1)
b1      = const(1,1)

def false():
    return ila.bool(0)

def getOnePos(to, input, default = const(0,XLEN), fr=0):
    expr = default
    for idx in range(fr,to):
        expr = ila.ite( input[idx] == 1, const(idx,XLEN), expr)
    return expr


class RVPrivModel:
    def __init__(self, unpriv_asts = 'unpriv_asts'): # riscv : riscvModel (in rv_um)
        self.riscv = riscv_um.riscvModel()
        self.riscv.loadUnprivNxtFromDir(unpriv_asts)

    def PrivDecode(self):
        riscv = self.riscv
        csrRWExpr = [   (riscv.opcode == RVEncoding.SYSTEM) & (riscv.funct3 == RVEncoding.CSRRW)  ]
        csrRSExpr = [   (riscv.opcode == RVEncoding.SYSTEM) & (riscv.funct3 == RVEncoding.CSRRS)  ]
        csrRCExpr = [   (riscv.opcode == RVEncoding.SYSTEM) & (riscv.funct3 == RVEncoding.CSRRC)  ]
        csrIExpr  = [   (riscv.opcode == RVEncoding.SYSTEM) & (riscv.funct3 == RVEncoding.CSRRWI) ,
                        (riscv.opcode == RVEncoding.SYSTEM) & (riscv.funct3 == RVEncoding.CSRRSI) ,
                        (riscv.opcode == RVEncoding.SYSTEM) & (riscv.funct3 == RVEncoding.CSRRCI) ] 
        EcallExpr = [   riscv.inst == 0x73     ]
        EbrkExpr  = [   riscv.inst == 0x100073 ]
        TrapRetExp= [   riscv.inst == 0x10200073 ,
                        riscv.inst == 0x30200073 ] 
        SfenceVMExpr = [ (riscv.opcode == RVEncoding.SYSTEM) & ( riscv.funct12 == RVEncoding.SFENCEVM) & (riscv.rd == 0) & (riscv.funct3 == 0) ]

        return (csrRWExpr,csrRSExpr,csrRCExpr,csrIExpr,EcallExpr,EbrkExpr,TrapRetExp,SfenceVMExpr)

    def buildATModel(self): # address translation model
        self.mem_v_addr = const(0,32) # self.riscv. ###OPT-OUT###

    def buildExpModel(self):

        riscv   = self.riscv
        CSRRegs = riscv.CSRRegs
        Priv    = riscv.Priv

        csr_index = riscv.csr_index
        #--------------------
        #   CSR decomposition
        #--------------------

        status_SD   = CSRRegs['mstatus'][XLEN-1]
        status_VM   = CSRRegs['mstatus'][28:24]
        status_MXR  = CSRRegs['mstatus'][19]
        status_PUM  = CSRRegs['mstatus'][18]
        status_MPRV = CSRRegs['mstatus'][17]
        status_MPP  = CSRRegs['mstatus'][12:11]
        status_HPP  = CSRRegs['mstatus'][10: 9]
        status_SPP  = CSRRegs['mstatus'][    8]
        status_MPIE = CSRRegs['mstatus'][    7]
        status_HPIE = CSRRegs['mstatus'][    6]
        status_SPIE = CSRRegs['mstatus'][    5]
        status_UPIE = CSRRegs['mstatus'][    4]
        status_MIE  = CSRRegs['mstatus'][    3]
        status_HIE  = CSRRegs['mstatus'][    2]
        status_SIE  = CSRRegs['mstatus'][    1]
        status_UIE  = CSRRegs['mstatus'][    0]

        #--------------------
        #   Choose interrupt
        #--------------------
        # NOTE!!!
        # all set_next_signal should be like
        # ite(take_int_or_expt, ??? , ??? )

        ipe = CSRRegs['mip'] & CSRRegs['mie']
        ideleg = CSRRegs['mideleg']

        illegalInst_subpart1 = ila.ite( (Priv<RVEncoding.MACHINE) & ( riscv.isAccessCSR_Level(csr_index, RVEncoding.MACHINE) ), ~false() , 
                                    ila.ite( (Priv<RVEncoding.SUPERVISOR) & ( ( riscv.isAccessCSR_Level(csr_index, RVEncoding.SUPERVISOR) ) | ( riscv.isAccessCSR_Level(csr_index, RVEncoding.MACHINE) ) ) , ~false() , false() ) )

        illegalInst_subpart2 = riscv_um.CSR.ilegalCSRAddr(csr_index, false(), ~false(), const)
        illegalInst_subpart3 = ila.choice('illegal_inst_lvl_wrong', ila.ite(Priv < RVEncoding.SUPERVISOR, ~false(), false() ), ila.ite(Priv<RVEncoding.MACHINE, ~false(), false() ) , false() )

        illegalInst_p1 = false() # ila.choice('illegal_inst1', false() , illegalInst_subpart1 | illegalInst_subpart2 ) # choose which instructions (only CSRs)

        def retInvSig(legalMask, legalMatch ):
            expr = const(1,1)
            assert( len(legalMask) == len(legalMatch) )
            for idx in range(len(legalMask)):
                #print idx
                expr = ila.ite( const(legalMatch[idx], XLEN) == ( const(legalMask[idx], XLEN) & riscv.inst ) , const(0,1), expr  )
            return expr

        illegalInst_p2 = retInvSig( riscv_um.CSR.legalMask , riscv_um.CSR.legalMatch )

        ret_signal     = self.isTrapReturn #ila.choice('ret_sig',const(0,1), const(1,1)) # some instructions will set this to 1
        illegalInst_p3 = ( ret_signal  ) & ( ( self.isMRET & (Priv < RVEncoding.MACHINE) ) | ( self.isSRET & (Priv < RVEncoding.SUPERVISOR) ) )

        
        ret_misalignment = self.isTrapReturn & ( (( self.isMRET ) & ( CSRRegs['mepc'][1:0]  != const(0,2))) |  (( self.isSRET ) & ( CSRRegs['sepc'][1:0]  != const(0,2))) )

        cause_inst_misalign  = (riscv.pc[1:0] != const(0,2)) | (ret_misalignment)
        cause_inst_acc_fault = false() ###OPT-OUT### #fetch_acc_fault
        cause_inst_illegal   = (illegalInst_p1) | ( illegalInst_p2 == 1) | (illegalInst_p3) ###OPT-OUT### #| (exception_others)
        cause_break_point    = false() ###OPT-OUT### #self.isEBreak 
        cause_load_misalign  = false() ###OPT-OUT### #ila.ite(isLoadInst() , mem_v_addr[1:0] != const(0,2), false() ) #ila.choice('load_except_choice', mem_v_addr[1:0] != const(0,2), false() ) # the computation of load address can be found in user-level spec
        cause_load_acc_fault = false() ###OPT-OUT### #isLoadInst() & load_store_acc_fault
        cause_store_misalign = false() ###OPT-OUT### #isStoreInst() & ( mem_v_addr[1:0] != const(0,2) ) #ila.choice('store_except_choice', mem_v_addr[1:0] != const(0,2), false() )
        cause_store_acc_fault = false() ###OPT-OUT### #isStoreInst() & load_store_acc_fault
        cause_ecall_from_U = false() ###OPT-OUT### #ila.choice('ecall_U_choice', const(0,1),  ila.ite( Priv == RISCV.USER ,const(1,1), const(0,1) ) ) ==  1
        cause_ecall_from_S = false() ###OPT-OUT### #ila.choice('ecall_S_choice', const(0,1),  ila.ite( Priv == RISCV.SUPERVISOR ,const(1,1), const(0,1) ) ) == 1
        cause_ecall_from_H = false() ###OPT-OUT### #const(0,1) ==1
        cause_ecall_from_M = false() ###OPT-OUT### #ila.choice('ecall_M_choice', const(0,1),  ila.ite( Priv == RISCV.MACHINE ,const(1,1), const(0,1) ) ) ==1
    
        self.exception_signal =  ( cause_inst_misalign  ) | \
                                 ( cause_inst_acc_fault ) | \
                                 ( cause_inst_illegal )   | \
                                 ( cause_break_point )    | \
                                 ( cause_load_misalign )  | \
                                 ( cause_load_acc_fault ) | \
                                 ( cause_store_misalign ) | \
                                 ( cause_store_acc_fault ) |\
                                 ( cause_ecall_from_U )  | \
                                 ( cause_ecall_from_S )  | \
                                 ( cause_ecall_from_H )  | \
                                 ( cause_ecall_from_M )  

                            
        self.exception_code = ila.ite( cause_inst_misalign  , const(0,XLEN),  # inst address misaligned
                              ila.ite( cause_inst_acc_fault , const(1,XLEN),  # instruction access fault
                              ila.ite( cause_inst_illegal   , const(2,XLEN),  # ...
                              ila.ite( cause_break_point    , const(3,XLEN),  # ...
                              ila.ite( cause_load_misalign  , const(4,XLEN),  # ...
                              ila.ite( cause_load_acc_fault , const(5,XLEN),  # ...
                              ila.ite( cause_store_misalign , const(6,XLEN),  # ...
                              ila.ite( cause_store_acc_fault, const(7,XLEN),  # ...
                              ila.ite( cause_ecall_from_U   , const(8,XLEN),  # ...
                              ila.ite( cause_ecall_from_S   , const(9,XLEN),  # ...
                              ila.ite( cause_ecall_from_H   , const(10,XLEN),  # ...
                              ila.ite( cause_ecall_from_M   , const(11,XLEN),  # ...
                              const(12,XLEN)  # undetermine
                              ))))))))))))
        
        self.choose_except = ila.ite( cause_inst_misalign  , const(0b1,XLEN),  # inst address misaligned
                             ila.ite( cause_inst_acc_fault , const(0b10,XLEN),  # instruction access fault
                             ila.ite( cause_inst_illegal   , const(0b100,XLEN),  # ...
                             ila.ite( cause_break_point    , const(0b1000,XLEN),  # ...
                             ila.ite( cause_load_misalign  , const(0b10000,XLEN),  # ...
                             ila.ite( cause_load_acc_fault , const(0b100000,XLEN),  # ...
                             ila.ite( cause_store_misalign , const(0b1000000,XLEN),  # ...
                             ila.ite( cause_store_acc_fault, const(0b10000000,XLEN),  # ...
                             ila.ite( cause_ecall_from_U   , const(0b100000000,XLEN),  # ...
                             ila.ite( cause_ecall_from_S   , const(0b1000000000,XLEN),  # ...
                             ila.ite( cause_ecall_from_H   , const(0b10000000000,XLEN),  # ...
                             ila.ite( cause_ecall_from_M   , const(0b100000000000,XLEN),  # ...
                             const(0,XLEN)
                             ))))))))))))

        self.exception_code.setRefName("exception_code")
        self.choose_except .setRefName("choose_except") # for better tracking in the export


        # Set some signals to be used in the buildIntModel
        # (signal exception conditions)
    def buildPrivInst(self): # Should handle x0-x31 update, should not touch pc/csrs

        riscv   = self.riscv
        inst    = riscv.inst
        opcode  = riscv.opcode
        funct12 = riscv.funct12
        CSRRegs = riscv.CSRRegs

        #--------------------
        #   CSR decomposition
        #--------------------

        status_SD   = CSRRegs['mstatus'][XLEN-1]
        status_VM   = CSRRegs['mstatus'][28:24]
        status_MXR  = CSRRegs['mstatus'][19]
        status_PUM  = CSRRegs['mstatus'][18]
        status_MPRV = CSRRegs['mstatus'][17]
        status_MPP  = CSRRegs['mstatus'][12:11]
        status_HPP  = CSRRegs['mstatus'][10: 9]
        status_SPP  = CSRRegs['mstatus'][    8]
        status_MPIE = CSRRegs['mstatus'][    7]
        status_HPIE = CSRRegs['mstatus'][    6]
        status_SPIE = CSRRegs['mstatus'][    5]
        status_UPIE = CSRRegs['mstatus'][    4]
        status_MIE  = CSRRegs['mstatus'][    3]
        status_HIE  = CSRRegs['mstatus'][    2]
        status_SIE  = CSRRegs['mstatus'][    1]
        status_UIE  = CSRRegs['mstatus'][    0]

        (csrRWExpr,csrRSExpr,csrRCExpr,csrIExpr,EcallExpr,EbrkExpr,TrapRetExp,SfenceVMExpr) \
            = self.PrivDecode()

        self.isTrapReturn = (inst == 0x10200073)  | (inst == 0x30200073)
        self.isMRET = inst == 0x30200073
        self.isSRET = inst == 0x10200073
        self.isEBreak = (opcode == RVEncoding.SYSTEM) & (funct12 == RVEncoding.EBREAK)

        self.trapRetPC   = ila.ite( self.isMRET , CSRRegs['mepc'], CSRRegs['sepc'] ) 
        self.trapRetPriv = ila.ite( self.isMRET , ila.ite(status_MPP == RVEncoding.HYPERVISOR, const(RVEncoding.SUPERVISOR,2), status_MPP) , ila.concat([b0, status_SPP]) )


        # gen CSR Inst Update List, add interrupt choice to the merge ones
        csr_W_inst_update = {} # Indep CSRNAME-> update function
        for csrName, CSRinf in riscv.CSRInfo.items():
            ### OPT-OUT ###
            if CSRinf.parent is not None:
                continue
            old = CSRRegs[csrName] 
            csr_W_inst_update[csrName] = old

        self.csr_W_inst_update = csr_W_inst_update

        """
            addr = CSRinf.addr
            # first are those without parent
            if CSRinf.parent is None:
                #print csrName
                old = CSRRegs[csrName] 
                update_expr = ila.choice('csr_W_expr', csr_w_reg , old | csr_w_set, old & ~csr_w_set )

                if csrName in RISCV.WLRLRange:
                    rangeH,rangeL, validVal = RISCV.WLRLRange[csrName]
                    Width = rangeH - rangeL + 1
                    defVal = const(validVal[0], Width)

                    condexpr = ~false() # true
                    for val in validVal:
                        condexpr = condexpr & ( update_expr[rangeH:rangeL] != val )
                    slot = ila.ite( condexpr, defVal, update_expr[rangeH:rangeL] )

                    update_expr = ila.concat([update_expr[XLEN-1:rangeH+1], slot , update_expr[rangeL-1:0] ])

                expr = ila.choice('csr_W_i_nxt_' + csrName, old,  
                    ila.ite( csr_index == addr, ROUpdate( update_expr , CSRinf.RORange, old), old)
                    )
                csr_W_inst_update[csrName] = expr
            else:
                #print csrName, CSRinf.parent
                assert(CSRinf.parent in csr_W_inst_update) # must have processed already
                old = CSRRegs[CSRinf.parent]
                partUpdate = csr_W_inst_update[CSRinf.parent]
                if csrName == 'sip' or csrName == 'sie':
                    expr = ila.choice('csr_W_i_nxt_' + csrName, partUpdate, 
                        ila.ite( csr_index == addr, ROUpdateExtraRange(csr_w_reg, CSRinf.RORange, old, CSRRegs['mideleg']), old), 
                        ila.ite( csr_index == addr, ROUpdateExtraRange(old | csr_w_set ,   CSRinf.RORange, old, CSRRegs['mideleg']), old),   # r
                        ila.ite( csr_index == addr, ROUpdateExtraRange(old & ~csr_w_set ,   CSRinf.RORange, old, CSRRegs['mideleg']), old), 
                        )
                else:
                    expr = ila.choice('csr_W_i_nxt_' + csrName, partUpdate, 
                        ila.ite( csr_index == addr, ROUpdate(csr_w_reg, CSRinf.RORange, old), old), 
                        ila.ite( csr_index == addr, ROUpdate(old | csr_w_set ,   CSRinf.RORange, old), old),   # r
                        ila.ite( csr_index == addr, ROUpdate(old & ~csr_w_set ,   CSRinf.RORange, old), old), 
                        )
                csr_W_inst_update[CSRinf.parent] = expr
        """


    def buildIntModel(self):

        riscv     = self.riscv
        CSRRegs   = riscv.CSRRegs
        Priv      = riscv.Priv
        pc        = riscv.pc
        processor = riscv.model
        #--------------------
        #   CSR decomposition
        #--------------------

        status_SD   = CSRRegs['mstatus'][XLEN-1]
        status_VM   = CSRRegs['mstatus'][28:24]
        status_MXR  = CSRRegs['mstatus'][19]
        status_PUM  = CSRRegs['mstatus'][18]
        status_MPRV = CSRRegs['mstatus'][17]
        status_MPP  = CSRRegs['mstatus'][12:11]
        status_HPP  = CSRRegs['mstatus'][10: 9]
        status_SPP  = CSRRegs['mstatus'][    8]
        status_MPIE = CSRRegs['mstatus'][    7]
        status_HPIE = CSRRegs['mstatus'][    6]
        status_SPIE = CSRRegs['mstatus'][    5]
        status_UPIE = CSRRegs['mstatus'][    4]
        status_MIE  = CSRRegs['mstatus'][    3]
        status_HIE  = CSRRegs['mstatus'][    2]
        status_SIE  = CSRRegs['mstatus'][    1]
        status_UIE  = CSRRegs['mstatus'][    0]

        #--------------------
        #   Choose interrupt
        #--------------------
        # NOTE!!!
        # all set_next_signal should be like
        # ite(take_int_or_expt, ??? , ??? )

        # 
        meip_next = riscv.meInt #& ~ (  CSRRegs['mideleg'] [11] )  # if external interrupt is there and it is not delegated
        heip_next = b0 # don't model hypervisor
        seip_next = riscv.seInt #& ~ ( CSRRegs['mideleg'] [ 9] )  
        ueip_next = b0
        
        msip_next = riscv.msInt #& ~ ( CSRRegs['mideleg'][3] ) # similar to the privious one
        hsip_next = b0 # we don't model hypervisor!
        ssip_next = riscv.ssInt #& ~ ( CSRRegs['mideleg'][1] ) 
        usip_next = b0
        
        mtip_next = riscv.mtInt #& ~ ( CSRRegs['mideleg'][7] )    # for timer interrupt
        htip_next = b0
        stip_next = riscv.stInt #& ~ ( CSRRegs['mideleg'][5] )
        utip_next = b0

        mip_next = ila.zero_extend( ila.concat( [ meip_next, heip_next, seip_next, ueip_next,
                                                  mtip_next, htip_next, stip_next, utip_next,
                                                  msip_next, hsip_next, ssip_next, usip_next ] ), 32 ) 

        ipe = mip_next & CSRRegs['mie']  #ipe = CSRRegs['mip'] & CSRRegs['mie'] # Question: How ipe is deduced?
        ideleg = CSRRegs['mideleg']

        trapFromS = ((( Priv == RVEncoding.SUPERVISOR ) & ( status_SIE == 1 )) | ( Priv < RVEncoding.SUPERVISOR ) )
        trapFromM = ((( Priv == RVEncoding.MACHINE    ) & ( status_MIE == 1 )) | ( Priv < RVEncoding.MACHINE    ) )

        # int_trap_select : Order of Spike
        
        int_trap_select =   ila.ite( trapFromS & ( (ipe[ 1] &  ideleg[ 1] ) == 1 ) , const(0b1, XLEN) << 1,   # select it and trap to S
                            ila.ite( trapFromM & ( (ipe[ 1] & ~ideleg[ 1] ) == 1 ) , const(0b1, XLEN) << 1,   # select it and trap to M
                            ila.ite( trapFromM & ( (ipe[ 3] & ~ideleg[ 3] ) == 1 ) , const(0b1, XLEN) << 3,
                            ila.ite( trapFromS & ( (ipe[ 5] &  ideleg[ 5] ) == 1 ) , const(0b1, XLEN) << 5, 
                            ila.ite( trapFromM & ( (ipe[ 5] & ~ideleg[ 5] ) == 1 ) , const(0b1, XLEN) << 5, 
                            ila.ite( trapFromM & ( (ipe[ 7] & ~ideleg[ 7] ) == 1 ) , const(0b1, XLEN) << 7,
                            ila.ite( trapFromS & ( (ipe[ 9] &  ideleg[ 9] ) == 1 ) , const(0b1, XLEN) << 9, 
                            ila.ite( trapFromM & ( (ipe[ 9] & ~ideleg[ 9] ) == 1 ) , const(0b1, XLEN) << 9, 
                            ila.ite( trapFromM & ( (ipe[11] & ~ideleg[11] ) == 1 ) , const(0b1, XLEN) << 11,
                            const(0,XLEN)
                            )))))))))
        """
        int_trap_select =   ila.ite( trapFromM & ( (ipe[11] & ~ideleg[11] ) == 1 ) , const(0b1, XLEN) << 11,
                            ila.ite( trapFromM & ( (ipe[ 9] & ~ideleg[ 9] ) == 1 ) , const(0b1, XLEN) << 9, 
                            ila.ite( trapFromS & ( (ipe[ 9] &  ideleg[ 9] ) == 1 ) , const(0b1, XLEN) << 9, 
                            ila.ite( trapFromM & ( (ipe[ 7] & ~ideleg[ 7] ) == 1 ) , const(0b1, XLEN) << 7,
                            ila.ite( trapFromM & ( (ipe[ 5] & ~ideleg[ 5] ) == 1 ) , const(0b1, XLEN) << 5, 
                            ila.ite( trapFromS & ( (ipe[ 5] &  ideleg[ 5] ) == 1 ) , const(0b1, XLEN) << 5, 
                            ila.ite( trapFromM & ( (ipe[ 3] & ~ideleg[ 3] ) == 1 ) , const(0b1, XLEN) << 3,
                            ila.ite( trapFromM & ( (ipe[ 1] & ~ideleg[ 1] ) == 1 ) , const(0b1, XLEN) << 1,   # select it and trap to M
                            ila.ite( trapFromS & ( (ipe[ 1] &  ideleg[ 1] ) == 1 ) , const(0b1, XLEN) << 1,   # select it and trap to S                            
                            const(0,XLEN)
                            )))))))))"""

        int_trap_select.setRefName('int_trap_select')

        int_trap_to_s = ((int_trap_select[ 1] & ideleg[ 1]) | (int_trap_select[ 5] & ideleg[ 5]) | (int_trap_select[ 9] & ideleg[ 9]) ) == 1
        int_trap_to_m = ((int_trap_select[3] | int_trap_select[7] | int_trap_select[11] ) | ((int_trap_select[ 1] & ~ideleg[ 1]) | (int_trap_select[ 5] & ~ideleg[ 5]) | (int_trap_select[ 9] & ~ideleg[ 9]) ) ) == 1

        take_int_sig = int_trap_to_s | int_trap_to_m
        take_int_sig.setRefName('take_int_sig')

        #  output by exception part
        trap_to_s = ( (self.choose_except &   CSRRegs['medeleg']) != 0 ) & (Priv <= RVEncoding.SUPERVISOR) 
        trap_to_m = ( ( (self.choose_except & ~ CSRRegs['medeleg']) != 0 ) | (( (self.choose_except &   CSRRegs['medeleg']) != 0 ) & (Priv > RVEncoding.SUPERVISOR)) )& (~ trap_to_s)
       
        take_int_or_expt = self.exception_signal | take_int_sig 

        take_int_or_expt.setRefName('take_int_or_expt')
        # OTHER CSR_UPDATES in interrupt/ ret updates
        csr_W_hw_update = {}

        next_m = ila.ite(take_int_sig,  int_trap_to_m, trap_to_m)
        next_s = ila.ite(take_int_sig,  int_trap_to_s, trap_to_s)

        HW_CSR_Update = collections.namedtuple('updateFunc', 'cond value mask')

        #------------------------
        # Pure Interrupt Updates
        #------------------------
        # (1) PC
        normalPC = processor.get_next('pc') # non_prev pc change

        next_pc = ila.ite( next_m , CSRRegs['mtvec'],
                        ila.ite( next_s , CSRRegs['stvec'],
                        ila.ite( self.isTrapReturn , self.trapRetPC,
                        normalPC ) ) )
        processor.set_next('pc', next_pc)    

        # (2) Priv
        next_priv = ila.ite( next_m, const(RVEncoding.MACHINE,2),
                    ila.ite( next_s, const(RVEncoding.SUPERVISOR,2),
                    ila.ite( self.isTrapReturn , self.trapRetPriv , 
                    Priv) ) )
        processor.set_next('Priv', next_priv)

        # (3) xIE & also ret
        mie_next =  ila.ite( next_m, b0, 
                    ila.ite( next_s, status_MIE,
                    ila.ite( self.isTrapReturn & self.isMRET & (status_MPP == RVEncoding.MACHINE), status_MPIE ,status_MIE ) ) )

        sie_next =  ila.ite( next_s, b0, 
                    ila.ite( next_m, status_SIE,
                    ila.ite( self.isTrapReturn , 
                    ila.ite( self.isSRET & (status_SPP == 1), status_SPIE , 
                    ila.ite( self.isMRET & ( (status_MPP == RVEncoding.SUPERVISOR) | (status_MPP == RVEncoding.HYPERVISOR) ), status_MPIE, status_SIE ) ) ,
                    status_SIE   ) ) )
        # (4) xPIE & also ret
        int_en =    ila.ite( Priv == RVEncoding.MACHINE, status_MIE, 
                    ila.ite( Priv == RVEncoding.SUPERVISOR, status_SIE, 
                    ila.ite( Priv == RVEncoding.USER, status_UIE, 
                    b0 )))
        mpie_next = ila.ite( next_m, int_en, ila.ite( (~next_s) & self.isTrapReturn & self.isMRET , b1 , status_MPIE) )
        spie_next = ila.ite( next_s, int_en, ila.ite( (~next_m) & self.isTrapReturn & self.isSRET , b1 , status_SPIE) )

        # (5) xPP & also ret
        spp_next = ila.ite( next_s, Priv[0], ila.ite( ( ~next_m ) & self.isSRET , const(0,1), status_SPP) )
        mpp_next = ila.ite( next_m, Priv,    ila.ite( ( ~next_s ) & self.isMRET , const(0,2), status_MPP) )

        # (*) Merge to Mstatus
        mstatus_update_value = ila.zero_extend(
            ila.concat([ mpp_next, const(0,2), spp_next, mpie_next, const(0,1), spie_next, const(0,1), mie_next, const(0,1) ,sie_next, const(0,1)]), 
            XLEN)
        mstatus_update_mask = const(0b1100110101010,XLEN)
        status_mie_update_cond = take_int_or_expt | self.isTrapReturn

        csr_W_hw_update['mstatus'] = HW_CSR_Update( cond = status_mie_update_cond, value = mstatus_update_value, mask = mstatus_update_mask )

        # (5) xCAUSE

        int_sel =const(1<<(XLEN-1),XLEN)

        epcv_t_m = ila.ite( self.exception_signal, self.exception_code, CSRRegs['mcause'] )
        epcv_ti_m= ila.ite( take_int_sig, getOnePos(to=12, input=int_trap_select ) | int_sel,  epcv_t_m )

        epcv_t_s = ila.ite( self.exception_signal, self.exception_code, CSRRegs['scause'] )
        epcv_ti_s= ila.ite( take_int_sig, getOnePos(to=12, input=int_trap_select ) | int_sel,  epcv_t_s )

        csr_W_hw_update['mcause'] = HW_CSR_Update( cond = ( next_m ) & ( take_int_or_expt ), value = epcv_ti_m, mask = None )
        csr_W_hw_update['scause'] = HW_CSR_Update( cond = ( next_s ) & ( take_int_or_expt ), value = epcv_ti_s, mask = None )

        # (6) xBADADDR 

        #m_recv_trap = choose_except & ~ CSRRegs['medeleg']
        #s_recv_trap = choose_except &   CSRRegs['medeleg']

        ld_st_fetch_trap_to_m = (~take_int_sig) & ( ( self.choose_except[0] | self.choose_except[1] | self.choose_except[4] | self.choose_except[5] | self.choose_except[6] | self.choose_except[7] ) == 1) & trap_to_m
        ld_st_fetch_trap_to_s = (~take_int_sig) & ( ( self.choose_except[0] | self.choose_except[1] | self.choose_except[4] | self.choose_except[5] | self.choose_except[6] | self.choose_except[7] ) == 1) & trap_to_s
        badaddr_update_value = ila.ite( ( self.choose_except[0] | self.choose_except[1] ) == 1 , pc, self.mem_v_addr)

        csr_W_hw_update['sbadaddr'] = HW_CSR_Update( cond = ld_st_fetch_trap_to_s , value = badaddr_update_value, mask = None)
        csr_W_hw_update['mbadaddr'] = HW_CSR_Update( cond = ld_st_fetch_trap_to_m , value = badaddr_update_value, mask = None )


        # (7) xEPC
        csr_W_hw_update['mepc'] = HW_CSR_Update( cond = ( next_m ) & ( take_int_or_expt ), value = pc & const(2**32-1-3, XLEN) , mask = None)
        csr_W_hw_update['sepc'] = HW_CSR_Update( cond = ( next_s ) & ( take_int_or_expt ), value = pc & const(2**32-1-3, XLEN) , mask = None)

        #==========================
        #  CSR Merge Updates
        #==========================

        # mip update
        has_interrupt = ( riscv.meInt | riscv.mtInt | riscv.meInt | riscv.stInt | riscv.seInt | riscv.ssInt )  == 1 
        #mip_update_func = ila.ite(has_interrupt , mip_csr_inst_write_next | mip_next, mip_csr_inst_write_next)
        #processor.set_next('mip', mip_update_func ) 

        # merge the updates
        for csrName, csrInfo in riscv.CSRInfo.items():
            if csrInfo.parent is not None:
                continue
            assert(csrName in self.csr_W_inst_update)

            expr = self.csr_W_inst_update[csrName]
            expr = ila.ite( ~take_int_or_expt, expr, CSRRegs[csrName] )

            if csrName in csr_W_hw_update: # if it is updated by hardware ( in addition to instructions )
                # if it is partially modified with a mask
                if csr_W_hw_update[csrName].mask is None:
                    expr = ila.ite( csr_W_hw_update[csrName].cond, csr_W_hw_update[csrName].value, expr )
                else:
                    expr = ila.ite( csr_W_hw_update[csrName].cond, 
                        (csr_W_hw_update[csrName].value & csr_W_hw_update[csrName].mask)
                        |
                        (expr & ~ csr_W_hw_update[csrName].mask ),
                        expr )
            #else: # it only has inst update, then it must be ignore if it raised trap/interrupt
                
            if csrName == 'mip':
                expr = mip_next # ila.ite(has_interrupt, expr | mip_next, expr )
            # if not using MIP

            processor.set_next(csrName, expr)

        self.take_int_or_expt = take_int_or_expt


    def buildAssumptions(self):

        def imply(p,q):
            return (~p) | q

        riscv     = self.riscv
        CSRRegs   = riscv.CSRRegs
        Priv      = riscv.Priv
        pc        = riscv.pc
        processor = riscv.model
        csr_index = riscv.csr_index
        #--------------------
        #   CSR decomposition
        #--------------------

        status_SD   = CSRRegs['mstatus'][XLEN-1]
        status_VM   = CSRRegs['mstatus'][28:24]
        status_MXR  = CSRRegs['mstatus'][19]
        status_PUM  = CSRRegs['mstatus'][18]
        status_MPRV = CSRRegs['mstatus'][17]
        status_MPP  = CSRRegs['mstatus'][12:11]
        status_HPP  = CSRRegs['mstatus'][10: 9]
        status_SPP  = CSRRegs['mstatus'][    8]
        status_MPIE = CSRRegs['mstatus'][    7]
        status_HPIE = CSRRegs['mstatus'][    6]
        status_SPIE = CSRRegs['mstatus'][    5]
        status_UPIE = CSRRegs['mstatus'][    4]
        status_MIE  = CSRRegs['mstatus'][    3]
        status_HIE  = CSRRegs['mstatus'][    2]
        status_SIE  = CSRRegs['mstatus'][    1]
        status_UIE  = CSRRegs['mstatus'][    0]

        # assume tlb's trans is disabled first
        # then do something else

        processor.add_assumption( status_VM == 0 ) # bare mode, no translation
        processor.add_assumption( riscv.generalRegDict['x0'] == 0)
        processor.add_assumption( (Priv == RVEncoding.MACHINE) | (Priv == RVEncoding.SUPERVISOR) | (Priv == RVEncoding.USER) )
        processor.set_init('x0', const(0,XLEN) )

        # NO hypervisor interrupts
        processor.add_assumption( status_HIE == 0 )
        processor.add_assumption( CSRRegs['mie'][10] == 0 )
        processor.add_assumption( CSRRegs['mie'][ 6] == 0 )
        processor.add_assumption( CSRRegs['mie'][ 2] == 0 )

        # Non-delegatable interrupts (M)
        processor.add_assumption( (CSRRegs['mideleg'][11] == 0) )
        processor.add_assumption( (CSRRegs['mideleg'][ 7] == 0) )
        processor.add_assumption( (CSRRegs['mideleg'][ 3] == 0) )
        # Non-existing delegation (H)
        processor.add_assumption( (CSRRegs['mideleg'][10] == 0) )
        processor.add_assumption( (CSRRegs['mideleg'][ 6] == 0) )
        processor.add_assumption( (CSRRegs['mideleg'][ 2] == 0) )

        # rule out CSR not modeled
        (csrRWExpr,csrRSExpr,csrRCExpr,csrIExpr,EcallExpr,EbrkExpr,TrapRetExp,SfenceVMExpr) \
            = self.PrivDecode()

        for csrL,csrH in RVEncoding.CSRNotModeled:
            for InstDecode in csrRWExpr + csrRSExpr + csrRCExpr + csrIExpr:
                processor.add_assumption( ~( (InstDecode) & (csr_index >= csrL) & (csr_index < csrH) ) )

        processor.add_assumption( imply(Priv == RVEncoding.USER, (status_SPIE == 1) & (status_SPP == 0) )  )
        processor.add_assumption( imply(Priv == RVEncoding.USER, (status_MPIE == 1) & (status_MPP == 0) )  )
        processor.add_assumption( imply(Priv == RVEncoding.SUPERVISOR , (status_MPIE == 1) & (status_MPP == 0) )  )

        # interrupt controls : no these things
        processor.add_assumption( riscv.seInt == 0 )
        processor.add_assumption( riscv.stInt == 0 )
        processor.add_assumption( riscv.ssInt == 0 )

        # no delegate
        processor.add_assumption( CSRRegs['mideleg'] == 0 )
        processor.add_assumption( CSRRegs['medeleg'] == 0 )

    def set_updates_GPR_MEM(self):
        riscv = self.riscv
        processor = riscv.model
        processor.set_next('x0', const(0,XLEN) )
        for idx in range(1,32):
            #print gpr_update_list[idx]
            oldexpr = processor.get_next('x%d' % idx)
            nochang = self.riscv.generalRegDict['x%d' % idx]
            processor.set_next('x%d' % idx,  ila.ite(~self.take_int_or_expt , oldexpr, nochang) )

        oldexpr_mem = processor.get_next('mem')
        processor.set_next('mem', ila.ite(~self.take_int_or_expt, oldexpr_mem, riscv.mem ) )



def buildModel():
    rvPriv = RVPrivModel()
    rvPriv.buildPrivInst()
    rvPriv.buildATModel()
    rvPriv.buildExpModel()
    rvPriv.buildIntModel()
    rvPriv.buildAssumptions()
    rvPriv.set_updates_GPR_MEM()

    return rvPriv

if __name__ == '__main__':
    rvPriv = buildModel()
    rvPriv.riscv.model.verilogExpConfig(externalMemory = True, funcAsModule = False)
    rvPriv.riscv.model.generateVerilog('RISC-V-VLG.v')


#