
# How to find out the numbers here
# in encoding.h 
# example:  MASK_LW = 0x707f    0b111000001111111
#           MATCH_LW = 0x2003   0b 10000000000011
#                                width      opcode

# PRIVILEDGED-LEVELS
# 00 user, 01 supervisor, 10: hypervisor, 11: machine


# TODO: 
# Please convert the content: encoding.h 214-623
import ila
import collections

legalMatch = [0x63, 0x1063, 0x4063, 0x5063, 0x6063, 0x7063, 0x67, 0x6f, 0x37, 0x17, 0x13, 0x1013, 0x2013, 0x3013, 0x4013, 0x5013, 0x40005013, 0x6013, 0x7013, 0x33, 0x40000033, 0x1033, 0x2033, 0x3033, 0x4033, 0x5033, 0x40005033, 0x6033, 0x7033, 0x1b, 0x101b, 0x501b, 0x4000501b, 0x3b, 0x4000003b, 0x103b, 0x503b, 0x4000503b, 0x3, 0x1003, 0x2003, 0x3003, 0x4003, 0x5003, 0x6003, 0x23, 0x1023, 0x2023, 0x3023, 0xf, 0x100f, 0x2000033, 0x2001033, 0x2002033, 0x2003033, 0x2004033, 0x2005033, 0x2006033, 0x2007033, 0x200003b, 0x200403b, 0x200503b, 0x200603b, 0x200703b, 0x202f, 0x2000202f, 0x4000202f, 0x6000202f, 0x8000202f, 0xa000202f, 0xc000202f, 0xe000202f, 0x800202f, 0x1000202f, 0x1800202f, 0x302f, 0x2000302f, 0x4000302f, 0x6000302f, 0x8000302f, 0xa000302f, 0xc000302f, 0xe000302f, 0x800302f, 0x1000302f, 0x1800302f, 0x73, 0x100073, 0x200073, 0x10200073, 0x20200073, 0x30200073, 0x7b200073, 0x10400073, 0x10500073, 0x1073, 0x2073, 0x3073, 0x5073, 0x6073, 0x7073, 0x53, 0x8000053, 0x10000053, 0x18000053, 0x20000053, 0x20001053, 0x20002053, 0x28000053, 0x28001053, 0x58000053, 0x2000053, 0xa000053, 0x12000053, 0x1a000053, 0x22000053, 0x22001053, 0x22002053, 0x2a000053, 0x2a001053, 0x40100053, 0x42000053, 0x5a000053, 0xa0000053, 0xa0001053, 0xa0002053, 0xa2000053, 0xa2001053, 0xa2002053, 0xc0000053, 0xc0100053, 0xc0200053, 0xc0300053, 0xe0000053, 0xe0001053, 0xc2000053, 0xc2100053, 0xc2200053, 0xc2300053, 0xe2000053, 0xe2001053, 0xd0000053, 0xd0100053, 0xd0200053, 0xd0300053, 0xf0000053, 0xd2000053, 0xd2100053, 0xd2200053, 0xd2300053, 0xf2000053, 0x2007, 0x3007, 0x2027, 0x3027, 0x43, 0x47, 0x4b, 0x4f, 0x2000043, 0x2000047, 0x200004b, 0x200004f, 0x1, 0x6101, 0x8002, 0x9002, 0x9002, 0x6000, 0xe000, 0x2001, 0x6002, 0xe002, 0x0, 0x2000, 0x4000, 0x6000, 0xa000, 0xc000, 0xe000, 0x1, 0x2001, 0x4001, 0x6001, 0x8001, 0x8401, 0x8801, 0x8c01, 0x8c21, 0x8c41, 0x8c61, 0x9c01, 0x9c21, 0xa001, 0xc001, 0xe001, 0x2, 0x2002, 0x4002, 0x6002, 0x8002, 0x9002, 0xa002, 0xc002, 0xe002]

legalMask  = [0x707f, 0x707f, 0x707f, 0x707f, 0x707f, 0x707f, 0x707f, 0x7f, 0x7f, 0x7f, 0x707f, 0xfc00707f, 0x707f, 0x707f, 0x707f, 0xfc00707f, 0xfc00707f, 0x707f, 0x707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0x707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0x707f, 0x707f, 0x707f, 0x707f, 0x707f, 0x707f, 0x707f, 0x707f, 0x707f, 0x707f, 0x707f, 0x707f, 0x707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xf800707f, 0xf800707f, 0xf800707f, 0xf800707f, 0xf800707f, 0xf800707f, 0xf800707f, 0xf800707f, 0xf800707f, 0xf9f0707f, 0xf800707f, 0xf800707f, 0xf800707f, 0xf800707f, 0xf800707f, 0xf800707f, 0xf800707f, 0xf800707f, 0xf800707f, 0xf800707f, 0xf9f0707f, 0xf800707f, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xfff07fff, 0xffffffff, 0x707f, 0x707f, 0x707f, 0x707f, 0x707f, 0x707f, 0xfe00007f, 0xfe00007f, 0xfe00007f, 0xfe00007f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfff0007f, 0xfe00007f, 0xfe00007f, 0xfe00007f, 0xfe00007f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfff0007f, 0xfff0007f, 0xfff0007f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfe00707f, 0xfff0007f, 0xfff0007f, 0xfff0007f, 0xfff0007f, 0xfff0707f, 0xfff0707f, 0xfff0007f, 0xfff0007f, 0xfff0007f, 0xfff0007f, 0xfff0707f, 0xfff0707f, 0xfff0007f, 0xfff0007f, 0xfff0007f, 0xfff0007f, 0xfff0707f, 0xfff0007f, 0xfff0007f, 0xfff0007f, 0xfff0007f, 0xfff0707f, 0x707f, 0x707f, 0x707f, 0x707f, 0x600007f, 0x600007f, 0x600007f, 0x600007f, 0x600007f, 0x600007f, 0x600007f, 0x600007f, 0xffff, 0xef83, 0xf07f, 0xf07f, 0xffff, 0xe003, 0xe003, 0xe003, 0xe003, 0xe003, 0xe003, 0xe003, 0xe003, 0xe003, 0xe003, 0xe003, 0xe003, 0xe003, 0xe003, 0xe003, 0xe003, 0xec03, 0xec03, 0xec03, 0xfc63, 0xfc63, 0xfc63, 0xfc63, 0xfc63, 0xfc63, 0xe003, 0xe003, 0xe003, 0xe003, 0xe003, 0xe003, 0xe003, 0xf003, 0xf003, 0xe003, 0xe003, 0xe003]

MACHINE = 3
HYPERVISOR = 2
SUPERVISOR = 1
USER = 0

# opcode
LOAD  = 0b0000011
STORE = 0b0100011
SYSTEM = 0b1110011

#funct3 
CSRRW = 0b001
CSRRS = 0b010
CSRRC = 0b011
CSRRWI = 0b101
CSRRSI = 0b110
CSRRCI = 0b111

# funct 12
ECALL = 0b0
EBREAK = 0b1

MRET = 0x302
SRET = 0x102
URET = 0x2

SFENCEVM = 0b00100000100

# width of load/store
BYTE = 0x0
HALF = 0x1
WORD = 0x2




# Supervisor CSR/User CSR

#Info Tuple: 
#   1. address
#   2. level
#   3. init (None for no init)
#   4. parent (None for no parent)
#   5. RO_range
#   6. S0_range (set to 0 when read, ignore when write) S0_range must in RO_range
#   7. const_range

# if parent has some info
# then init ignore, RO = parent + this, S0 = parent + this, const ignore
# will not be a true reg

# only instructions change dependant CSR
# HW does not

XLEN = 32

ISA = 0b01<<30| 1 << 8 | 1 << 20 | 1 << 18  # 32bits and RV32I and MSU 
powerOn_mstatus = 0
ALL = range(32)

CSRfield = collections.namedtuple('CSR','addr level init parent RORange ZeroRange ConstRange')

legalCSRAddr = [0x100, 0x104, 0x105, 0x140, 0x141, 0x142, 0x143, 0x144, 0x180, 0x300 , 0x301,0x302, 0x303,0x304, 0x305, 0x340, 0x341, 0x342, 0x343 , 0x344 ] 
CSRNotModeled = [(0x7a0, 0x7a4), (0x7b0, 0x7b3), (0xb00,0b01), (0xb02, 0xb20) , (0x320,0x340) , (0xf11,0xf15) , (0xc80,0xca0) , (0xb80, 0xba0) ]  

def ilegalCSRAddr(idxBits, false, true, const):
    expr = true
    for addr in legalCSRAddr:
        expr = ila.ite(idxBits == const(addr,12), false, expr )
    return expr

def NoProt(addr, level):
    return CSRfield(addr,level, None,None,[],[],[])

WLRLRange = { 'mstatus': (28,24, [0,8] )  }

CSRInfo = { 'misa':     CSRfield( 0x301, MACHINE,  ISA,              None, ALL, [] , ALL),
            'mstatus':  CSRfield( 0x300, MACHINE, powerOn_mstatus,   None, range(29,32) + range(20,24) + [15,16,10,9,6,4,2,0], range(29,32) + range(20,24) + [15,16,10,9,6,4,2,0] , range(29,32) + range(20,24) + [15,16,10,9,6,4,2,0] ),
            'mtvec':    CSRfield( 0x305, MACHINE, 0,                 None, range(0,2), range(0,2), range(0,2) ),
            'medeleg':  CSRfield( 0x302, MACHINE, 0,                 None, range(12,32) + [10], range(12,32) + [10], range(12,32) + [10] ), # exclude HRET
            'mideleg':  CSRfield( 0x303, MACHINE, 0,                 None, range(12,32) + [11,7,3,10,6,2,8,4,0], range(12,32)+ [10,6,2,8,4,0], range(12,32)+ [10,6,2,8,4,0] ), # exclude HSU interupt
            'mip':      CSRfield( 0x344, MACHINE, 0,                 None, range(12,32) + [8,9,10,11] + [4,6,7] + [0,2,3] , range(12,32), range(12,32) ), 
            'mie':      CSRfield( 0x304, MACHINE, 0,                 None, range(12,32) + [11,10,8,6,4,2,0], range(12,32), range(12,32) ),
            'mscratch': NoProt(0x340, MACHINE),
            'mepc':     NoProt(0x341, MACHINE),
            'mcause':   NoProt(0x342, MACHINE),
            'mbadaddr': NoProt(0x343, MACHINE),
            # ----------------------------------
            # Supervisor level
            # ----------------------------------
            'sstatus':  CSRfield(0x100, SUPERVISOR, None, 'mstatus', range(24,29) + [19,17] + range(9,13) + [6,7,2,3] , range(24,29) + [19,17] + range(9,13) + [6,7,2,3]  , []),
            #'sedeleg':  CSRfield(0x102, SUPERVISOR, None, None     , range(12,32) + [10], range(12,32) + [10], range(12,32) + [10] ),
            #'sideleg':  CSRfield(0x103, SUPERVISOR, None, 'mideleg', [11,7,3], [11,7,3], []), # exclude machine deleg ability
            'sie':      CSRfield(0x104, SUPERVISOR, None, 'mie', [10,11,6,7,3,2,8,4,0], [10,11,6,7,3,2,8,4,0], [10,11,6,7,3,2,8,4,0] ), ### BIG CHANGE ###  
            'sip':      CSRfield(0x144, SUPERVISOR, None, 'mip', [11,7,3], [11,7,3], [11,7,3] ),  ### BIG CHANGE ###  
            'stvec':    CSRfield(0x105, SUPERVISOR, 0   , None , [0,1], [0,1] ,[0,1]), #***#
            'sscratch': NoProt(  0x140, SUPERVISOR ),
            'sepc':     NoProt(  0x141, SUPERVISOR ),
            'scause':   NoProt(  0x142, SUPERVISOR ),
            'sbadaddr': NoProt(  0x143, SUPERVISOR ),
            'sptbr':    CSRfield(0x180, SUPERVISOR, 0   , None , range(22,32), range(22,32), range(22,32)) # NoProt(0x180, SUPERVISOR)
            # ----------------------------------
            # User level
            # ----------------------------------
            #'ustatus':  CSRfield(0x000, USER, None, 'sstatus', [18,8,5,1] ,  [18,8,5,1] , []),
            #'uie':      CSRfield(0x004, USER, None, 'sie', [9,5,1], [9,5,1], [] ),
            #'utvec':    CSRfield(0x005, USER, 0,    None,  [1,0], [1,0], [1,0] ),
            #'uscratch': NoProt(0x040,USER),
            #'uepc':     NoProt(0x041,USER),
            #'ucause':   NoProt(0x042,USER),
            #'ubadaddr': NoProt(0x043,USER),
            #'uip':      CSRfield(0x044, USER, None, 'sie', [9,5,1], [9,5,1], [] )
            }

def PreProcess():
    before = CSRInfo.items()
    for name, CSR in before:
        if CSR.parent is None:
            continue
        # else
        RORange = CSR.RORange + CSRInfo[CSR.parent].RORange
        ZeroRange = CSR.ZeroRange + CSRInfo[CSR.parent].ZeroRange
        RORange   = list(set(RORange) )
        ZeroRange = list(set(ZeroRange) )
        # set the topmost one
        parent = CSR.parent
        while CSRInfo[parent].parent is not None:
            parent = CSRInfo[parent].parent

        CSRInfo[name] = CSRfield(CSR.addr , CSR.level, CSR.init, parent, RORange, ZeroRange, CSR.ConstRange )



def SetUpCSRReg(proc):
    def getBit(v,pos):
        return ( v & (1<<pos)) >> pos
    CSRRegs = {}
    for name,CSR in CSRInfo.items():
        if CSR.parent is not None:
            continue # not physically exist
        reg = proc.reg(name, XLEN)
        if CSR.init is not None:
            proc.set_init(name, proc.const( CSR.init , XLEN) )
        for const_bit in CSR.ConstRange:
            proc.add_assumption( reg[const_bit] == getBit(CSR.init, const_bit) )
        CSRRegs[name] = reg 
    return CSRRegs

# ------------------------------------
# Virtual Memory Related
# ------------------------------------

TLB_IDX_LEN = 8
TLB_SIZE = 2 ** TLB_IDX_LEN

def PTEcheck(inst, mstatus, Priv, pte ,takeInt):
    opcode = inst[6:0]

    MXR = mstatus[19]
    PUM = mstatus[18]
    MPRV= mstatus[17]
    MPP = mstatus[12:11]

    effectPriv = ila.ite( ( Priv == MACHINE ) & ( MPRV == 1 ) , MPP, Priv )
    disallowUser = (effectPriv != USER) &  (PUM == 1)
    allowXasR = (effectPriv == MACHINE) & (MXR == 1)

    pte_V = pte[0]
    pte_R = pte[1]
    pte_W = pte[2]
    pte_X = pte[3]
    pte_U = pte[4]
    pte_G = pte[5]
    pte_A = pte[6]
    pte_D = pte[7]
    nonleaf_pte = pte_V & (~ pte_R ) & (~ pte_X )

    fault_condition =   (~takeInt) & (
                        (pte_V == 0) | 
                        ( (pte_R == 0) & (pte_W == 1) ) |
                        ( (opcode == STORE ) & (pte_W == 0) ) |
                        ( (opcode == LOAD) & ( ila.ite(allowXasR, pte_X|pte_R, pte_R ) == 0 ) )  |
                        ( (pte_U == 1) & disallowUser ) |
                        ( (pte_U == 0) & (effectPriv != USER) ) )
    return fault_condition


def IFetchPTE(inst, mstatus, Priv, pte ,takeInt):
    opcode = inst[6:0]

    MXR = mstatus[19]
    PUM = mstatus[18]
    MPRV= mstatus[17]
    MPP = mstatus[12:11]

    effectPriv = ila.ite( ( Priv == MACHINE ) & ( MPRV == 1 ) , MPP, Priv )
    disallowUser = (effectPriv != USER) &  (PUM == 1)

    pte_V = pte[0]
    pte_R = pte[1]
    pte_W = pte[2]
    pte_X = pte[3]
    pte_U = pte[4]
    pte_G = pte[5]
    pte_A = pte[6]
    pte_D = pte[7]
    nonleaf_pte = pte_V & (~ pte_R ) & (~ pte_X )

    fault_condition =   (~takeInt) & (
                        (pte_V == 0) | 
                        ( (pte_R == 0) & (pte_W == 1) ) |
                        ( pte_X == 0 ) |
                        ( (pte_U == 1) & disallowUser ) |
                        ( (pte_U == 0) & (effectPriv != USER) ) )
    return fault_condition

def ExtractPAddr(pte, bigpage, vaddr ):
    pte_ppn1 = pte[31:20]
    pte_ppn  = pte[31:10]
    bigTrans = ila.concat([pte_ppn1, vaddr[21:12], vaddr[11:0] ]) # byte address
    smlTrans = ila.concat([     pte_ppn,           vaddr[11:0] ]) # byte address
    fullAddr = ila.ite(bigpage, bigTrans , smlTrans )
    return fullAddr[31:0]

def GenTLBFlush(tlb_pte_buf,  proc):
    expr = tlb_pte_buf
    default = proc.const(0,32)
    for idx in range(TLB_SIZE):
        expr = ila.store(expr, proc.const(idx,TLB_IDX_LEN ) , default )
    return expr



PreProcess()
CSRInfo = collections.OrderedDict(sorted(CSRInfo.items(), key = lambda t: 0 if t[1].parent is None else 1))

# import 
# CSRRegs = SetUpCSRReg()
# 