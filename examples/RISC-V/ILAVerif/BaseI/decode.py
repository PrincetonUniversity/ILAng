
inst = 0x01f82f33

instList = [    \
                (0x707f, 0x3, 'LB', ['rs1','rd','immI']), 
                (0x707f, 0x2003, 'LW', ['rs1','rd','immI']), 
                (0x707f, 0x1003, 'LH', ['rs1','rd','immI']), 
                (0x707f, 0x3003, 'LD', ['rs1','rd','immI']), 
                (0x707f, 0x4003, 'LBU', ['rs1','rd','immI']), 
                (0x707f, 0x5003, 'LHU', ['rs1','rd','immI']), 
                (0x707f, 0x6003, 'LWU', ['rs1','rd','immI']), 

                (0x707f, 0x0023, 'SB', ['rs1','rs2','immS']),
                (0x707f, 0x1023, 'SH', ['rs1','rs2','immS']),
                (0x707f, 0x2023, 'SW', ['rs1','rs2','immS']), 
                (0x707f, 0x3023, 'SD', ['rs1','rs2','immS']), 

                (0x707f, 0x0063, 'BEQ', ['rs1','rs2','immB']),
                (0x707f, 0x1063, 'BNE', ['rs1','rs2','immB']),
                (0x707f, 0x4063, 'BLT', ['rs1','rs2','immB']),
                (0x707f, 0x5063, 'BGE', ['rs1','rs2','immB']),
                (0x707f, 0x6063, 'BLTU', ['rs1','rs2','immB']),
                (0x707f, 0x7063, 'BGEU', ['rs1','rs2','immB']),

                (0x7f, 0x6f, 'JAL', ['immJ','rd']),
                (0x707f, 0x67, 'JALR', ['rs1','rd','immI']),

                (0x7f,0x37, 'LUI', ['immU','rd']),
                (0x7f,0x17, 'AUIPC', ['immU','rd']),

                (0x707f, 0x13, 'ADDI', ['rs1','rd','immI']),
                (0x707f, 0x2013, 'SLTI', ['rs1','rd','immI']),
                (0x707f, 0x3013, 'SLTIU', ['rs1','rd','immI']),
                (0x707f, 0x4013, 'XORI', ['rs1','rd','immI']),
                (0x707f, 0x6013, 'ORI', ['rs1','rd','immI']),
                (0x707f, 0x7013, 'ANDI', ['rs1','rd','immI']),
                (0xfe00707f, 0x00005013, 'SRLI', ['rs1','rd','shamt']),
                (0xfe00707f, 0x40005013, 'SRAI', ['rs1','rd','shamt']),
                (0xfe00707f, 0x00001013, 'SLLI', ['rs1','rd','shamt']),

                (0xfe00707f, 0x00000033, 'ADD', ['rs1','rs2','rd']),
                (0xfe00707f, 0x40000033, 'SUB', ['rs1','rs2','rd']),
                (0xfe00707f, 0x00001033, 'SLL', ['rs1','rs2','rd']),
                (0xfe00707f, 0x00002033, 'SLT', ['rs1','rs2','rd']),
                (0xfe00707f, 0x00003033, 'SLTU', ['rs1','rs2','rd']),
                (0xfe00707f, 0x00004033, 'XOR', ['rs1','rs2','rd']),
                (0xfe00707f, 0x00005033, 'SRL', ['rs1','rs2','rd']),
                (0xfe00707f, 0x40005033, 'SRA', ['rs1','rs2','rd']),
                (0xfe00707f, 0x00006033, 'OR', ['rs1','rs2','rd']),
                (0xfe00707f, 0x00007033, 'AND', ['rs1','rs2','rd']),

                (0x707f, 0x1073, 'CSRRW', ['CsrNo', 'rs1','rd']),
                (0x707f, 0x2073, 'CSRRS', ['CsrNo', 'rs1','rd']),
                (0x707f, 0x3073, 'CSRRC', ['CsrNo', 'rs1','rd']),
                (0x707f, 0x5073, 'CSRRWI', ['CsrNo', 'rs1','rd', 'zimm']),
                (0x707f, 0x6073, 'CSRRSI', ['CsrNo', 'rs1','rd', 'zimm']),
                (0x707f, 0x7073, 'CSRRCI', ['CsrNo', 'rs1','rd', 'zimm']),
                (0xffffffff, 0x73, 'ECALL', []),
                (0xffffffff, 0x100073, 'EBREAK', []),
                (0xffffffff, 0x10200073, 'SRET', []),
                (0xffffffff, 0x30200073, 'MRET', []),
                (0xfff07fff, 0x10400073, 'SFENCE.VM', []) ]


InstPart = {'opcode': [(6, 0)],
            'rd': [(11, 7)],
            'rs1': [(19,15)],
            'rs2': [(24,20)],
            'funct3': [(14,12)],
            'funct7': [(31,25)],
            'funct12': [(31,20)],
            'immI':[(31,20)],
            'CsrNo':[(31,20)],
            'zimm':[(19,15)],
            'shamt': [(24,20)],
            'immS':[(31,25), (11,7)],
            'immB':[(31,31),(7,7),(30,25),(11,8)],
            'immJ':[(31,31),(19,12),(20,20),(30,25),(24,21)],
            'immI':[(31,31),(30,25),(24,21),(20,20)],
            'immU':[(31,12)]}

    
def PartInst(inst, high,low):
    return ( inst & (1 << (high+1)) -1 ) >> low

def PartList(inst, l):
    retV = 0
    for (high,low) in l:
        retV = retV << (high-low+1) | PartInst(inst, high, low)
    return retV

def ImmList(inst, l, Tp):
    retV = 0
    First = True
    Sign = False
    for (high, low) in l:
        if First:
            First = False
            if high == low and PartInst(inst, high, high): 
                Sign = True; retV = 0xffffffff
            if high != low and PartInst(inst, high, high):
                Sign = True; retV = 0xffffffff
            retV = retV << (high-low+1) |  PartInst(inst, high, low)
        else:
            retV = retV << (high-low+1) |  PartInst(inst, high, low)
    if Tp in 'BJ':
        retV = retV << 1
    elif Tp in 'U':
        retV = retV << 12
    retV = retV & 0xffffffff
    if retV & 0x80000000:
        retV = retV - 0x80000000*2
    return retV
    
    

def check(name,rs,imm):
    if name == 'LW' or name == 'SW':
        print '>>>',(rs+imm)
        if (rs+imm)&0b11 != 0:
            print 'ERROR, misalign'
            exit(3)
    if name in ['LH','LHU', 'SH'] :
        print '>>>',(rs+imm)
        if (rs + imm) & 0b1 != 0:
            print 'ERROR, misalign'
            exit(3)

def DecodeInst(inst):
    print 'Instruction:%x' % inst
    #print 'pc:',hex(pcBefore),'(%s)'%(pcBefore/4),'->',hex(pcAfter)
    flag = False
    for mask, match, name, params in instList:
        if inst & mask == match:
            flag = True
            imm = 0; rs1 = 0
            print '  -> ', name
            for paramE in params:
                if paramE[0:3] == 'imm':
                    inst_partial = ImmList(inst, InstPart[paramE], paramE[3])
                else:
                    inst_partial = PartList(inst, InstPart[paramE])

                print '  P:', paramE,':', hex(inst_partial),
                #if paramE in ['rd','rs1','rs2']:
                #    print hex(GPRListBefore[inst_partial]),'->',hex(GPRListAfter[inst_partial])
                #else:
                #    print ""
                #if paramE == 'rs1':
                #    inst_partial = PartList(inst, InstPart[paramE])
                #    rs1 = GPRListBefore[inst_partial]
                if paramE[0:3] == 'imm':
                    imm = ImmList(inst, InstPart[paramE], paramE[3])
            #print GPRListBefore
            #check(name,rs1,imm)

    if not flag:
        print "Unrecognized instruction!"
        

inst = input("HEX:") or inst
DecodeInst(inst)
