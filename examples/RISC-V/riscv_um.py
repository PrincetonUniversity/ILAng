import ila

XLEN = 32

class Encoding:
    OPIMM = 0x13
    LUI   = 0x37
    AUIPC = 0x17
    OP    = 0x33
    BRANCH = 0x63
    JAL = 0x6f; JALR = 0x67
    LOAD = 0x03;
    STORE = 0x23;

    #funct3 for OPIMM
    ADDI  = 0x0
    SLTI  = 0x2
    SLTIU = 0x3
    ANDI  = 0x7
    ORI   = 0x6
    XORI  = 0x4
    SLLI  = 0x1
    SLLIfunct7 = 0x00
    SRLI  = 0x5
    SRLIfunct7 = 0x00
    SRAI  = 0x5
    SRAIfunct7 = 0x20
    #funct3 for OP
    ADD = 0x0; SLT = 0x2; SLTU = 0x3;
    AND = 0x7; OR  = 0x6; XOR  = 0x4;
    SLL = 0x1; SRL = 0x5;
    funct7_NM = 0x0;
    SUB  = 0x0; SRA = 0x5;
    funct7_PM = 0x20
    # funct3 for BRANCH
    BEQ = 0x0; BNE = 0x1; 
    BLT = 0x4; BLTU = 0x6; BGE = 0x5; BGEU = 0x7;
    # funct3 for L/S
    Byte = 0x0; Half = 0x1; Word = 0x2; Double = 0x3;
    BU = 0x4; HU = 0x5; WU = 0x6; 


class riscvModel:
    def __init__(self):
        self.model = ila.Abstraction('riscv')
        self.createStates()
        self.uID = -1

    def createStates(self):
        self.pc    = self.model.reg('pc', XLEN)
        self.mem   = self.model.mem('mem', 32, 32)
        self.generalRegDict    = {}
        self.generalRegList    = []
        for idx in range(32):
            treg = self.model.reg('x%d' % idx, XLEN)
            self.generalRegDict['x%d' % idx] = treg
            self.generalRegList.append( treg )
        self.InstFetch()
        self.createPrivilegeStates()
        self.stateList = ['pc','mem'] + ['x%d' % idx for idx in range(32)]

    def InstFetch(self):
        #self.inst = self.model.inp('inst',32)
        #self.fetch_expr = self.inst
        inst = ila.load(self.mem, ila.zero_extend(self.pc[31:2], 32)) #ila.zero_extend(self.pc[31:2], 32))
        self.inst = inst
        self.fetch_expr = self.inst
        self.opcode = self.inst[6:0]
        self.rd     = self.inst[11:7]
        self.rs1    = self.inst[19:15]
        self.rs2    = self.inst[24:20]
        self.funct3 = self.inst[14:12]
        self.funct7 = self.inst[31:25]
        self.funct12= self.inst[31:20]   
        self.immI   = ila.sign_extend( inst[31:20], XLEN)
        self.immS   = ila.sign_extend( ila.concat( [inst[31:25], inst[11:7]] ), XLEN )
        self.immB   = ila.sign_extend( ila.concat( [inst[31],inst[7], inst[30:25], inst[11:8], ila.const(0,1) ] ) , XLEN ) 
        self.immU   = ila.concat( [inst[31:12],ila.const(0,12)] )
        self.immJ   = ila.sign_extend( ila.concat( [inst[31], inst[19:12], inst[20], inst[30:21], ila.const(0,1) ] ) , XLEN)


    def InstDecode(self, decodeList):
        self.model.decode_exprs = decodeList

    def createPrivilegeStates(self):
        pass

    #---------------------------
    #   Auxiliary Functions     
    #---------------------------

    def indexIntoGPR(self,idxBits):
        expr = self.generalRegList[0] # r0
        for idx in range(1,32):
            expr = ila.ite(idxBits == idx, self.generalRegList[idx], expr)
        return expr

    def GPRwriteList(self,idxBits, writeExpr ):
        exprList = []
        for idx in range(32):
            exprList.append( ila.ite( (idxBits == idx) , writeExpr, self.generalRegList[idx]) )
        return exprList

    def GPRwriteListCond(self,dxBits, writeExpr, cond ):
        exprList = []
        for idx in range(32):
            exprList.append( ila.ite( (idxBits == idx) & (cond), writeExpr, self.generalRegList[idx]) )
        return exprList

    def choiceGPRList(self,*arg): # l1[0,1,...,31], l2[0,1,...,31], ... => [0:choice(l1[0],l2[0],...), ... 31:...]
        # check length
        for listIter in arg:
            assert( len(listIter) == 32 )
        exprList = []
        for idx in range(32):
            choiceList = []
            for listIter in arg:
                choiceList.append(listIter[idx])
            exprList.append( ila.choice('gpr_final_choice_%d'%idx, choiceList) )
        return exprList

    def newID(self):
        self.uID += 1
        return 'uid_%d' % self.uID
    def zext(self,v):
        return ila.zero_extend(v,XLEN)
    def sext(self,v):
        return ila.sign_extend(v,XLEN)
    def ext(self,v):
        return ila.choice(self.newID(), self.zext(v), self.sext(v) )
    def bv(self,v,w=XLEN):
        return self.model.const(v,w)

    def loadNxtFromDir(self,dirName):
        for name in self.stateList:
            ast = self.model.importOne(dirName + '/' + name)
            self.model.set_next(name, ast )
