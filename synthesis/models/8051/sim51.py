import subprocess
import tempfile
from random import randint
from collections import defaultdict
import ila

def dumpState(fileobject, pc, xram_data_in, rom, regs):
    print >> fileobject, '%x' % (pc)
    print >> fileobject, '%x' % (xram_data_in)
    dumpMem(fileobject, rom)
    for i in xrange(0, 384, 32):
        for j in xrange(i, i+32):
                print >> fileobject, '%x' % (regs[j]),
        print >> fileobject

    fileobject.flush()

def dumpMem(fileobject, mem):
    l = len(mem.values)
    nums = [mem.default]
    for [a,v] in mem.values:
        nums.append(a)
        nums.append(v)
    assert len(nums) == 2*l + 1
    print >> fileobject, l, ' '.join('%x' % n for n in nums)

def evalState(pc, xram_data_in, rom, regs):
    "Create a temporary file with the input state, run 8051syn, collect the output and return."
    for i in regs:
        assert regs[i] >= 0 and regs[i] <= (1 << 8), regs[i]

    with tempfile.NamedTemporaryFile() as fileobject:
        dumpState(fileobject, pc, xram_data_in, rom, regs)

        # with open('data.out', 'wt') as fileobj:
        #     print >> fileobj, subprocess.check_output(['cat', fileobject.name])
        # print subprocess.check_output(['cat', fileobject.name])
        # print subprocess.check_output(['wc', fileobject.name])
        # print subprocess.check_output(['./8051syn', fileobject.name])
        state = subprocess.check_output(['./8051syn', fileobject.name])
        # print state
        words = state.split()
        pc = int(words[0], 16)
        xram_addr = int(words[1], 16)
        xram_data_out = int(words[2], 16)

        # there is no xram, but writing it out anyway.
        xram_def_size = int(words[3], 10)
        xram = []
        last = 4+2*xram_def_size
        for i in xrange(4, last, 2):
            xram.append([int(words[i], 16), int(words[i+1], 16)])
        xram.append(int(words[last], 16))
        regs = [int(x, 16) for x in words[last+1:]]
        assert len(regs) == 384
        return pc, xram_addr, xram_data_out, regs 
    
    raise IOError("Unable to execute command.")

def eval8051(inputs):
    # initialize input state.
    iram = inputs['IRAM']
    regs = ([iram.default]*256) + ([0]*128)
    for (addr,data) in iram.values:
        assert addr < 256
        assert data < 256
        regs[addr] = data

    regs[0x160] = inputs['ACC']
    regs[0x101] = inputs['SP']
    regs[0x150] = inputs['PSW']
    regs[0x102] = inputs['DPL']
    regs[0x103] = inputs['DPH']
    regs[0x80 + 0x80] = inputs['P0']
    regs[0x80 + 0x87] = inputs['PCON']
    regs[0x80 + 0x88] = inputs['TCON']
    regs[0x80 + 0x89] = inputs['TMOD']
    regs[0x80 + 0x8A] = inputs['TL0'] 
    regs[0x80 + 0x8C] = inputs['TH0'] 
    regs[0x80 + 0x8B] = inputs['TL1'] 
    regs[0x80 + 0x8D] = inputs['TH1'] 
    regs[0x80 + 0x90] = inputs['P1']  
    regs[0x80 + 0x98] = inputs['SCON']
    regs[0x80 + 0x99] = inputs['SBUF']
    regs[0x80 + 0xA0] = inputs['P2']  
    regs[0x80 + 0xA8] = inputs['IE']  
    regs[0x80 + 0xB0] = inputs['P3']  
    regs[0x80 + 0xB8] = inputs['IP']  
    regs[0x80 + 0xF0] = inputs['B']   

    rom = inputs['ROM']
    pc = inputs['PC']
    xram_data_in = inputs['XRAM_DATA_IN']

    # print inputs
    # simulate
    newPC, xram_addr, xram_data_out, newRegs = evalState(pc, xram_data_in, rom, regs)

    # read output state
    outputs = {}
    outputs['IRAM'] = extractIRAM(newRegs)
    outputs['XRAM_ADDR'] = xram_addr
    outputs['XRAM_DATA_OUT'] = xram_data_out

    outputs['PC'] = newPC
    outputs['ACC']  = newRegs[0x160]
    outputs['SP']   = newRegs[0x101]
    outputs['PSW']  = newRegs[0x150]
    outputs['DPL']  = newRegs[0x102]
    outputs['DPH']  = newRegs[0x103]
    outputs['P0']   = newRegs[0x80 + 0x80]
    outputs['PCON'] = newRegs[0x80 + 0x87]
    outputs['TCON'] = newRegs[0x80 + 0x88]
    outputs['TMOD'] = newRegs[0x80 + 0x89]
    outputs['TL0']  = newRegs[0x80 + 0x8A]
    outputs['TH0']  = newRegs[0x80 + 0x8C]
    outputs['TL1']  = newRegs[0x80 + 0x8B]
    outputs['TH1']  = newRegs[0x80 + 0x8D]
    outputs['P1']   = newRegs[0x80 + 0x90]
    outputs['SCON'] = newRegs[0x80 + 0x98]
    outputs['SBUF'] = newRegs[0x80 + 0x99]
    outputs['P2']   = newRegs[0x80 + 0xA0]
    outputs['IE']   = newRegs[0x80 + 0xA8]
    outputs['P3']   = newRegs[0x80 + 0xB0]
    outputs['IP']   = newRegs[0x80 + 0xB8]
    outputs['B']    = newRegs[0x80 + 0xF0]

    # print outputs
    return outputs

def extractIRAM(regs):
    numCounts = defaultdict(int)
    for i in xrange(0, 256):
        numCounts[regs[i]] += 1

    maxCnt = 0
    maxKey = 0
    for k,c in numCounts.iteritems():
        if c > maxCnt:
            maxCnt = c
            maxKey = k

    ram = ila.MemValues(8, 8, maxKey)
    for i in xrange(0, 256):
        if regs[i] != maxKey:
            ram[i] = regs[i]
    return ram

def main():
    rom = ila.MemValues(16, 8, 0)
    rom[0x800] = 0xA4
    rom[0x801] = 0x00
    inputs = {
        'ACC':0xC8,
        'B':0x97,
        'DPH':0x0,
        'DPL':0x0,
        'IE':0x0,
        'IP':0x0,
        'IRAM':ila.MemValues(8, 8, 0xff),
        'P0':0x0,
        'P1':0x0,
        'P2':0x0,
        'P3':0x0,
        'PC':0x800,
        'PCON':0x0,
        'PSW':0x0,
        'ROM':rom,
        'SBUF':0x0,
        'SCON':0x0,
        'SP':0x0,
        'TCON':0x0,
        'TH0':0x0,
        'TH1':0x0,
        'TL0':0x0,
        'TL1':0x0,
        'TMOD':0x0,
        'XRAM_DATA_IN':0xff
    }
    print inputs
    outputs = eval8051(inputs)
    print outputs


if __name__ == '__main__':
    main()
