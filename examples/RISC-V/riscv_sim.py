import os
import subprocess
import ila

def getBit(v,pos):
    return ( v & (1<<pos)) >> pos
def hex2arr(n, l):
    l = '%0' + str(l//4) + 'x'
    return l % n

GPRList = ['x%d' % idx for idx in range(32)] + ['pc']
CSRList = [ 'misa', 'mstatus', 'mtvec','medeleg', 'mideleg', 'mip', 'mie', 
            'mscratch','mepc', 'mcause','mbadaddr','stvec', 'sscratch','sepc','scause','sbadaddr',
            'sptbr','Priv']

inFile = 'assign.in'
outFile = 'result.out'

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

                (0x7f, 0x6f, 'JAL', ['immJ']),
                (0x707f, 0x67, 'JALR', ['rs1','immI']),

                (0x7f,0x37, 'LUI', ['immU','rd']),
                (0x7f,0x17, 'AUIPC', ['immU','rd']),

                (0x707f, 0x13, 'ADDI', ['rs1','rd','immI']),
                (0x707f, 0x2013, 'SLTI', ['rs1','rd','immI']),
                (0x707f, 0x3013, 'SLTIU', ['rs1','rd','immI']),
                (0x707f, 0x4013, 'XORI', ['rs1','rd','immI']),
                (0x707f, 0x6013, 'ORI', ['rs1','rd','immI']),
                (0x707f, 0x7013, 'ANDI', ['rs1','rd','immI']),
                (0xfc00707f, 0x00005013, 'SRLI', ['rs1','rd','shamt']),
                (0xfc00707f, 0x40005013, 'SRAI', ['rs1','rd','shamt']),
                (0xfc00707f, 0x00001013, 'SLLI', ['rs1','rd','shamt']),

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

def DecodeInst(inst, GPRListBefore, GPRListAfter, pcBefore, pcAfter):
    print 'Instruction:%x' % inst
    print 'pc:',hex(pcBefore),'(%s)'%(pcBefore/4),'->',hex(pcAfter)
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
                if paramE in ['rd','rs1','rs2']:
                    print hex(GPRListBefore[inst_partial]),'->',hex(GPRListAfter[inst_partial])
                else:
                    print ""
                if paramE == 'rs1':
                    inst_partial = PartList(inst, InstPart[paramE])
                    rs1 = GPRListBefore[inst_partial]
                if paramE[0:3] == 'imm':
                    imm = ImmList(inst, InstPart[paramE], paramE[3])
            print GPRListBefore
            check(name,rs1,imm)

    if not flag:
        print "Unrecognized instruction!"
        assert(0)

def _extractGPR(S):
    l = []
    for idx in range(32):
        name = 'x' + str(idx)
        l.append( S[name] )
    return l

def InterruptDump(mip,mie,mstatus, mideleg, Priv):
    print 'Priv:',Priv
    SIE = getBit(mstatus, 1)
    MIE = getBit(mstatus, 3)
    ipe = mip & mie
    trapFromS = ( Priv == 1 and SIE == 1 ) or Priv < 1
    trapFromM = ( Priv == 3 and MIE == 1 ) or Priv < 3
    print 'TrapTo:', 'S' if trapFromS else '', 'M' if trapFromM else ''
    for idx in range(12):
        if getBit(ipe,idx) == 1:
            print 'Int idx:',idx, 'X' if getBit(mideleg, idx) else ''

def saveIO(s,n):
    subprocess.call(['cp','assign.in','test_out/%s_%d.in'%(s,n)])
    subprocess.call(['cp','result.out','test_out/%s_%d.out'%(s,n)])

class RiscVSim():
    def __init__(self):
        pass
    def Sim(self, Sin):
        print '!!!'
        self._assign_state(Sin)
        proc = subprocess.Popen(['./spike_sim_inst'], stdout = subprocess.PIPE)
        for line in proc.stdout:
            print line
        proc.wait()
        Sout = self._load_state(Sin)
        self.iterCount += 1
        self._dump(Sin,Sout)
        return Sout
    def SetSynState(self,name):
        self.iterCount = 0
        self.syn_state = name

    def _dump(self, Sin, Sout):
        print 'Syn state: ', self.syn_state, 'iter#',self.iterCount
        inst = Sin['mem'][Sin['pc']/4] #inst = Sin['inst']
        print 'mem:',Sin['mem'],'->',Sout['mem']
        DecodeInst(inst,_extractGPR(Sin),_extractGPR(Sout),Sin['pc'],Sout['pc'])
        #InterruptDump(Sin['mip'],Sin['mie'],Sin['mstatus'], Sin['mideleg'], Sin['Priv'])
        saveIO(self.syn_state, self.iterCount)
        #pa = raw_input("Press Enter to Continue.")

    def _assign_state(self,Sin):
        with open(inFile,'w') as inf:
            # Instruction (Hex)
            inst = Sin['mem'][Sin['pc']/4]
            print >> inf, hex2arr(inst, 32)
            # GPR
            for name in GPRList:
                assert (name in Sin)
                print >> inf, name, hex2arr(Sin[name],32)

            print >> inf,'.CSR_BEGIN'
            # dump CSR register
            #for name in CSRList:
            #    assert (name in Sin)
            #    print >> inf, name, hex2arr(Sin[name],32)
            print >> inf,'.CSR_END'
            # dump memory
            mem = Sin['mem']
            default = mem.default
            values  = mem.values
            size = len(values)
            print mem
            print >> inf, size*4, hex2arr(default, 32)
            for (addr,value) in values:
                print >> inf, hex2arr(addr*4 + 0, 32) , hex2arr( (value            )%256 ,8) # little endian
                print >> inf, hex2arr(addr*4 + 1, 32) , hex2arr( (value/256        )%256 ,8)
                print >> inf, hex2arr(addr*4 + 2, 32) , hex2arr( (value/256/256    )%256 ,8) 
                print >> inf, hex2arr(addr*4 + 3, 32) , hex2arr( (value/256/256/256)%256 ,8)

            # what about interrupt
    def _load_state(self,Sin): #return Sout
        # fake the effect of interrupt ! 
        masks = [0xffffff00, 0xffff00ff, 0xff00ffff, 0x00ffffff]
        Sout = {}
        with open(outFile) as outf:
            # load x0-x31
            for idx in range(33):
                line = outf.readline().split()
                assert(line[0] in GPRList)
                Sout[line[0]] = int(line[1],16)
            assert(outf.readline().startswith('.CSR_BEGIN') )
            line = outf.readline()
            while not line.startswith('.CSR_END'):
                #CSRname = line.split()[0]
                #CSRval  = line.split()[1]
                line = outf.readline()
                #if CSRname not in CSRList:
                #    continue
                #Sout[CSRname] = int(CSRval, 16)
            # check all have been assigned
            #for name in CSRList:
            #    assert(name in Sout)
            # now load memory
            line = outf.readline().split()
            byteSize = int(line[0])
            default = int(line[1], 16)
            outMem = ila.MemValues(32,32,default)

            for idx in range(byteSize):
                line = outf.readline().split()
                byteAddr = int(line[0],16)
                wordAddr = byteAddr/4
                byteData = int(line[1],16)

                originalVal = outMem[wordAddr]
                pos = (byteAddr - wordAddr*4) * 8
                mask = masks[byteAddr - wordAddr*4]
                updateData = (originalVal &  mask ) | ( ( byteData & 0xff )  << pos )
                outMem[wordAddr] = updateData

            Sout['mem'] = outMem
            return Sout

            # fake the effect of interrupt
            """
            value = Sin['meInt'] << 11 | Sin['seInt'] << 9 | Sin['mtInt'] << 7 | Sin['stInt'] << 5 | Sin['msInt'] << 3 | Sin['ssInt'] << 1
            if value != 0:
                print 'Interrupt:', bin(value)
                print 'mip:', bin(Sout['mip'])

            Sout['mip'] = Sout['mip'] | value # only used to set, not reset


            # clean mstatus SD bits
            mstatus = Sout['mstatus']
            mstatus = mstatus & 0x7ffe7fff
            Sout['mstatus'] = mstatus
            """





