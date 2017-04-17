import subprocess
import time


instList = [    \
                #(0x707f, 0x2003, 'LW', ['rs1','rd','immI']), 
                #(0x707f, 0x3, 'LB', ['rs1','rd','immI']), 
                #(0x707f, 0x1003, 'LH', ['rs1','rd','immI']), 
                #(0x707f, 0x3003, 'LD', ['rs1','rd','immI']), 
                #(0x707f, 0x4003, 'LBU', ['rs1','rd','immI']), 
                #(0x707f, 0x5003, 'LHU', ['rs1','rd','immI']), 
                #(0x707f, 0x6003, 'LWU', ['rs1','rd','immI']), 

                #(0x707f, 0x0023, 'SB', ['rs1','rs2','immS']),
                #(0x707f, 0x1023, 'SH', ['rs1','rs2','immS']),
                #(0x707f, 0x2023, 'SW', ['rs1','rs2','immS']), \
                #(0x707f, 0x3023, 'SD', ['rs1','rs2','immS']), 

                #(0x707f, 0x0063, 'BEQ', ['rs1','rs2','immB']),
                #(0x707f, 0x1063, 'BNE', ['rs1','rs2','immB']),
                #(0x707f, 0x4063, 'BLT', ['rs1','rs2','immB']),
                #(0x707f, 0x5063, 'BGE', ['rs1','rs2','immB']),
                #(0x707f, 0x6063, 'BLTU', ['rs1','rs2','immB']),
                #(0x707f, 0x7063, 'BGEU', ['rs1','rs2','immB']),

                #(0x7f, 0x6f, 'JAL', ['immJ','rd']),
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
                #(0xfe00707f, 0x00007033, 'AND', ['rs1','rs2','rd'])
                ]

with open('RocketFV.v.in') as fin:
    text = fin.read()
with open('bmcprove.tcl.in') as fin:
    script = fin.read()

logf = open('prove.log','wt')

with open ('result.log','wt') as rt:
    for m,h,instname,l in instList:
        outtext = text.replace('%%%INST%%%', instname)
        scr = script.replace('%%%INST%%%', instname)
        with open('RocketFV.v','wt') as fout:
            fout.write(outtext)
        with open('bmcprove.tcl','wt') as fout:
            fout.write(scr)
        #let's do the work
        subprocess.call(['mkdir','db/'+instname])
        
        logf.flush()
        logf.write( 'proving %s\n' % instname )
        starttime = time.time()
        logf.write( 'Time: %f\n' % starttime )
        logf.flush()
        
        #exit(1);
        subprocess.call(['jg','-no_gui','-fpv','bmcprove.tcl'], stdout=rt)
        
        endtime = time.time()
        logf.write( 'End: %f\n Elapsed: %f\n' % (starttime, endtime-starttime ) )
        logf.flush()
    
    




