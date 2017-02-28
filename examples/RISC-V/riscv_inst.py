import ila
from riscv_um import Encoding


def addInstructions(rm):
    BranchInstrctions = [
            (rm.opcode == Encoding.BRANCH ) & (rm.funct3 == Encoding.BEQ )   , #
            (rm.opcode == Encoding.BRANCH ) & (rm.funct3 == Encoding.BNE )   , #
            (rm.opcode == Encoding.BRANCH ) & (rm.funct3 == Encoding.BLT )   , #
            (rm.opcode == Encoding.BRANCH ) & (rm.funct3 == Encoding.BLTU )   , #
            (rm.opcode == Encoding.BRANCH ) & (rm.funct3 == Encoding.BGE )   , #
            (rm.opcode == Encoding.BRANCH ) & (rm.funct3 == Encoding.BGEU )   ]  #
    JumpInstructions = [ #
            (rm.opcode == Encoding.JAL ) , #
            (rm.opcode == Encoding.JALR ) & (rm.funct3 == 0) ]
    LoadInstructions = [
            (rm.opcode == Encoding.LOAD ) & (rm.funct3 == Encoding.Word )   , 
            (rm.opcode == Encoding.LOAD ) & (rm.funct3 == Encoding.Half )   , #
            (rm.opcode == Encoding.LOAD ) & (rm.funct3 == Encoding.Byte )   , #
            (rm.opcode == Encoding.LOAD ) & (rm.funct3 == Encoding.BU )   , #
            (rm.opcode == Encoding.LOAD ) & (rm.funct3 == Encoding.HU )   
            ] 
    StoreInstructions = [
            (rm.opcode == Encoding.STORE ) & (rm.funct3 == Encoding.Byte )   , #
            (rm.opcode == Encoding.STORE ) & (rm.funct3 == Encoding.Half )   , #
            (rm.opcode == Encoding.STORE ) & (rm.funct3 == Encoding.Word )  
            ]
    ALUInstructions = [
            (rm.opcode == Encoding.OPIMM ) & (rm.funct3 == Encoding.ADDI )   , #ADDI
            (rm.opcode == Encoding.OPIMM ) & (rm.funct3 == Encoding.SLTI )   , #
            (rm.opcode == Encoding.OPIMM ) & (rm.funct3 == Encoding.SLTIU)   , #
            (rm.opcode == Encoding.OPIMM ) & (rm.funct3 == Encoding.ANDI )   , #
            (rm.opcode == Encoding.OPIMM ) & (rm.funct3 == Encoding.ORI  )   , #
            (rm.opcode == Encoding.OPIMM ) & (rm.funct3 == Encoding.XORI )   , #
            (rm.opcode == Encoding.OPIMM ) & (rm.funct3 == Encoding.SLLI ) & (rm.funct7 == Encoding.SLLIfunct7)   , #
            (rm.opcode == Encoding.OPIMM ) & (rm.funct3 == Encoding.SRLI ) & (rm.funct7 == Encoding.SRLIfunct7)   , #
            (rm.opcode == Encoding.OPIMM ) & (rm.funct3 == Encoding.SRAI ) & (rm.funct7 == Encoding.SRAIfunct7)     #
            ]
    ALUImmedInstructions = [
            (rm.opcode == Encoding.OP) & (rm.funct3 == Encoding.ADD) & (rm.funct7 == Encoding.funct7_NM) , #
            (rm.opcode == Encoding.OP) & (rm.funct3 == Encoding.SLT) & (rm.funct7 == Encoding.funct7_NM) , #
            (rm.opcode == Encoding.OP) & (rm.funct3 == Encoding.SLTU)& (rm.funct7 == Encoding.funct7_NM) , #
            (rm.opcode == Encoding.OP) & (rm.funct3 == Encoding.AND) & (rm.funct7 == Encoding.funct7_NM) , #
            (rm.opcode == Encoding.OP) & (rm.funct3 == Encoding.OR)  & (rm.funct7 == Encoding.funct7_NM) , #
            (rm.opcode == Encoding.OP) & (rm.funct3 == Encoding.XOR) & (rm.funct7 == Encoding.funct7_NM) , #
            (rm.opcode == Encoding.OP) & (rm.funct3 == Encoding.SLL) & (rm.funct7 == Encoding.funct7_NM) , #
            (rm.opcode == Encoding.OP) & (rm.funct3 == Encoding.SRL) & (rm.funct7 == Encoding.funct7_NM) , #
            (rm.opcode == Encoding.OP) & (rm.funct3 == Encoding.SUB) & (rm.funct7 == Encoding.funct7_PM) , #
            (rm.opcode == Encoding.OP) & (rm.funct3 == Encoding.SRA) & (rm.funct7 == Encoding.funct7_PM) , #
            ]
    ImmedInstructions =  [   
            (rm.opcode == Encoding.LUI ) , #
            (rm.opcode == Encoding.AUIPC )  #
            ] 
    InstructionSet = LoadInstructions + StoreInstructions + ImmedInstructions \
        + BranchInstrctions + JumpInstructions  \
        + ALUInstructions + ALUImmedInstructions

    rm.InstDecode(InstructionSet)
    return (BranchInstrctions, JumpInstructions, LoadInstructions, StoreInstructions, ALUInstructions, ALUImmedInstructions, ImmedInstructions)

# add assumptions
# 1. read alignment
# 2. jump/branch alignment
# 3. X0

def AddInst(rm):
    (BranchInstrctions, JumpInstructions, LoadInstructions, 
        StoreInstructions, ALUInstructions, ALUImmedInstructions, 
        ImmedInstructions) = addInstructions(rm)

    bv = rm.bv
    ext = rm.ext
    zext = rm.zext
    sext = rm.sext

    def getSlice(v,lowBits):
        expr = \
        ila.ite( lowBits == 0, ila.choice('lowbits_0',ext(v[7:0]), ext(v[15:0]), ext(v[23:0] ), v[31:0]       ),
        ila.ite( lowBits == 1, ila.choice('lowbits_1'            , ext(v[15:8]), ext(v[23:8] ), ext(v[31:8] ) ),
        ila.ite( lowBits == 2, ila.choice('lowbits_2'                          , ext(v[23:16]), ext(v[31:16]) ),
        ila.ite( lowBits == 3, ext(v[31:24]) ,
            v[31:0]
            ))))
        return expr

    def get_reg_choices(reg):
        rs1_val = rm.indexIntoGPR(rm.rs1)
        rs2_val = rm.indexIntoGPR(rm.rs2)
        rd_val  = rm.indexIntoGPR(rm.rd )
        rs_val  = ila.choice('rs_sel',rs1_val, rs2_val)
        shamt   = ila.choice('shift_amout', rs2_val[4:0], rm.inst[24:20])
        rs2_comb = ila.choice('rs2_or_immed', rs2_val, ila.zero_extend(rm.immI, 32), ila.sign_extend(rm.immI, 32) )

        addr = rs1_val + rm.immI
        lw_val    = ila.load(rm.mem, zext(addr[31:2]) )
        load_val  = getSlice(lw_val, addr[1:0] )
        #load_dw   = ila.loadblk(rm.mem, zext(addr[31:2]), 2 )

        return ila.choice("x%d_next" % reg,
                      [rm.generalRegList[reg],                      # Remain the Same regardless of RD (i.e. S/SB instructions)
                       ila.ite(rm.rd == reg,                                            # Is this the destination register?
                               ila.choice("x%d" % reg,
                                          [rs1_val + rs2_comb,                        # RS1 + RS2
                                           rs1_val - rs2_comb,                        # RS1 - RS2
                                           rs1_val & rs2_comb,                        # AND
                                           rs1_val | rs2_comb,                        # OR
                                           rs1_val ^ rs2_comb,                        # XOR
                                           ila.ite(ila.slt(rs1_val,rs2_comb),         # SLT
                                                   bv(1), bv(0)),
                                           ila.ite(ila.slt(rs1_val, rs2_comb),
                                                   bv(0), bv(1)),
                                           ila.ite(rs1_val<rs2_comb,
                                                   bv(1), bv(0)),
                                           rs1_val << zext(shamt),    # sll
                                           rs1_val >> zext(shamt),    # srl
                                           ila.ashr(rs1_val ,zext(shamt) ), # sra
                                           rm.immU,                # LUI
                                           rm.immU + rm.pc,        # AUIPC
                                           rm.pc + bv(4),                               # JAL/JALR
                                           load_val
                                           #load_dw
                                          ]),
                               rm.generalRegList[reg])    # Remain the same
                      ])


    def get_pc_choices():
        rs1_val = rm.indexIntoGPR(rm.rs1)
        rs2_val = rm.indexIntoGPR(rm.rs2)
        NC = rm.pc + bv(4)
        BTarget = rm.pc + rm.immB
        return ila.choice("pc_nxt", [   NC,                            # Next Instruction Address
                                        ila.ite(rs1_val == rs2_val, BTarget, NC),
                                        ila.ite(rs1_val != rs2_val, BTarget, NC),
                                        ila.ite(rs1_val  < rs2_val, BTarget, NC),
                                        ila.ite(ila.slt(rs1_val, rs2_val), BTarget, NC),
                                        ila.ite(rs1_val >= rs2_val, BTarget, NC),
                                        ila.ite(ila.sge(rs1_val, rs2_val), BTarget, NC),
                                        rm.pc + rm.immJ,               # JAL
                                        (rs1_val + rm.immI) & bv(0xFFFFFFFE)    #JALR
                                    ])
    def get_mem_choices():

        rs1_val = rm.indexIntoGPR(rm.rs1)
        rs2_val = rm.indexIntoGPR(rm.rs2)

        mask = ila.choice('store_mask', [bv(0xff), bv(0xffff), bv(0xffffffff)] )
        addr = rs1_val + rm.immS
        word_addr = zext(addr[31:2])
        store_value = ( rs2_val & mask )<< ( 8*zext(addr[1:0]) ) | ( (~(mask<< (8* zext(addr[1:0])) )) & rm.mem[word_addr] )

        return ila.choice("mem_nxt", [  rm.mem,       # NC
                                        ila.store(rm.mem, word_addr, store_value)
                                        ])

    def add_assumptions():
        def imply(p,q):
            return (~p) | q
        rs1_val = rm.indexIntoGPR(rm.rs1)
        BTarget = rm.pc + rm.immB
        LoadAddr = rs1_val[1:0] + rm.immI[1:0]
        StoreAddr = rs1_val[1:0] + rm.immS[1:0]

        isJump = JumpInstructions[0] | JumpInstructions[1]
        isBranch = BranchInstrctions[0] | BranchInstrctions[1] | BranchInstrctions[2] | BranchInstrctions[3] | BranchInstrctions[4] #reduce( lambda x,y: x|y , BranchInstrctions)
        isLoad   = LoadInstructions[0] | LoadInstructions[1] | LoadInstructions[2] | LoadInstructions[3] | LoadInstructions[4] #reduce( lambda x,y: x|y , LoadInstructions )
        isStore  = StoreInstructions[0] | StoreInstructions[1] | StoreInstructions[2] #reduce( lambda x,y: x|y , StoreInstructions)
        a1 = imply(JumpInstructions[0], (rm.pc + rm.immJ)[1:0] == 0 ) # JAL
        a2 = imply(JumpInstructions[1], (rs1_val + rm.immI)[1] == 0 ) # JALR
        a3 = imply(isBranch, BTarget[1:0] == 0)
        a4 = imply(isLoad & (rm.funct3 == Encoding.Half) , LoadAddr[0] == 0)
        a5 = imply(isLoad & (rm.funct3 == Encoding.Word) , LoadAddr[1:0] == 0)
        a6 = imply(isLoad & (rm.funct3 == Encoding.HU) , LoadAddr[0] == 0)

        a7 = imply(isStore & (rm.funct3 == Encoding.Word) , StoreAddr[1:0] == 0)
        a8 = imply(isStore & (rm.funct3 == Encoding.Half) , StoreAddr[0] == 0)

        a9 = rm.generalRegList[0] == 0
        a10 = rm.pc[1:0] == 0
        rm.model.add_assumption(a1)
        rm.model.add_assumption(a2)
        rm.model.add_assumption(a3)
        rm.model.add_assumption(a4)
        rm.model.add_assumption(a5)
        rm.model.add_assumption(a6)
        rm.model.add_assumption(a7)
        rm.model.add_assumption(a8)
        rm.model.add_assumption(a9)
        rm.model.add_assumption(a10)
        #rm.model.add_assumption(a52);rm.model.add_assumption(a5);

        rm.model.set_next('x0', bv(0))

    rm.model.set_next('pc', get_pc_choices() )
    rm.model.set_next('mem', get_mem_choices() )
    for regNo in range(1,32):
        rm.model.set_next('x%d' % regNo, get_reg_choices(regNo))
    add_assumptions()

    #ila.setloglevel(3,'')
    #ila.enablelog('Synthesizer.useAssump')

    rsvalue = rm.indexIntoGPR(rm.inst[19:15])
    #rwvalue = rm.indexIntoGPR(ila.const(2,5))
    #ass = ( rsvalue[0] +  rm.inst[25] ) [0] == 0 
    #ass2 = ( rsvalue[1:0] +  rm.inst[26:25] ) [1] == 0 

    #rm.model.add_assumption( ass2 & ~ass )

    #rm.model.add_assumption( ~( ( ( (rm.inst & 0x707f) == 0x2003) ) & (~ass) ) ) # LoadInstructions[2] &    
    #rm.model.add_assumption( ~( ( ( (rm.inst & 0x707f) == 0x2003) ) & (~ass2) ) ) # LoadInstructions[2] &   ( (rm.inst & 0x707f) == 0x2003) & 
    
    #rm.model.add_assumption( ~( ( ( (rm.inst & 0x707f) == 0x2003) ) & (rm.immI == 0x21) ) ) 
    #print rm.generalRegList[2] rm.generalRegList[2]
    #a1 = ( ( rm.inst & bv(0x707f) ) != bv(0x2003) )   | ( ( rsvalue + rm.immI )[1:0] == 0) 
    #a2 = ( ( rm.inst & bv(0x707f) ) != bv(0x1003) )   | ( ( rsvalue + rm.immI )[0] == 0) 
    #rm.model.add_assumption( a1  )
    #rm.model.add_assumption( a2  )
    rm.model.enable_parameterized_synthesis = 0
    #rm.model.add_assumption( a1 & a2 )

    #rm.model.add_assumption( ~( ( ( ( (rm.inst & bv(0x707f)) == bv(0x2003)) ) ) & ( rm.model.getreg('x2') != 0x303033) ) ) # LoadInstructions[2] &   ( (rm.inst & 0x707f) == 0x2003) & 



"""

    rm.model.add_assumption(  rm.inst[25] == 1 )

    ass = ~ ((rm.opcode == Encoding.STORE ) & (rm.funct3 == Encoding.Half ) & ( ( rm.indexIntoGPR(rm.inst[19:15])[0] +  rm.inst[7] ) != 0 ) )
    
    #ass1 =  ( rm.indexIntoGPR(rm.inst[19:15])[0] +  rm.inst[7] ) == 0 
    #ass10 = rm.inst[7] == 0
    #ass2 =  ( (rm.indexIntoGPR(rm.inst[19:15]))[1:0] +  rm.inst[8:7] ) [0] == 0
    ass3 =  ( (rm.indexIntoGPR(rm.inst[19:15]))[1:0] +  rm.inst[8:7] ) [1] == 0

    #rm.model.add_assumption( ass2 & (~ass1) )

    #ass3 = rm.indexIntoGPR(rm.inst[19:15])[0] == 0
    #print ass2
    #rm.model.add_assumption( ass1 )
    #rm.model.add_assumption( ass10 )
    #rm.model.add_assumption( ass2 )
    rm.model.add_assumption( ass3 )
    #exit(1)
"""
