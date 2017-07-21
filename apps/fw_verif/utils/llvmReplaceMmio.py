# File: llvmReplaceMmio.py
# Synopsis: Replace the set of MMIO READ/WRITE that uses interface variable.

import os
import sys
import argparse
import common

class mapStructType ():
    def __init__ (self):
        self.mapping = {}
        self.declare = []
        self.tagType = ''
        self.tagName = ''

    def get (self, inStr):
        return self.mapping[inStr]

    def add (self, inStr, outStr):
        self.mapping[inStr] = outStr

    def addDeclare (self, dcl):
        self.declare.append (dcl)

def buildMapping (mapFile):
    """ Mapping Format:
        _Type [mmio container type]
        _Name [mmio container pointer variable]
        _MapWr [function to call] [reg name] [offset] ...
        _MapRd [function to call] [reg name] [offset] ...
    """

    mapLines = common.getLineFromFile (mapFile)

    hwMap = mapStructType ()

    for line in mapLines:
        words = line.split ()
        if not words: continue

        tag = words[0]
        if tag[:2] == '//': 
            continue
        elif tag == '_Type':
            hwMap.tagType = words[1]
        elif tag == '_Name':
            hwMap.tagName = words[1]
        elif tag == '_MapWr':
            key = 'wr/' + words[2] + '/' + words[3]
            hwMap.add (key, words[1])
            dcl = 'declare void @' + words[1] + '(i32) #1\n'
            hwMap.addDeclare (dcl)
        elif tag == '_MapRd':
            key = 'rd/' + words[2] + '/' + words[3]
            hwMap.add (key, words[1])
            dcl = 'declare i32 @' + words[1] + '(...) #1\n'
            hwMap.addDeclare (dcl)
        else:
            assert 0, 'Unknown tag ' + tag

    return hwMap

def process (srcFile, hwMap, outFile) :
    llvmSrc = common.getLineFromFile (srcFile)

    wFile = open (outFile, 'w')

    def relayCmd (cmd):
        wFile.write (cmd)

    def registerCmd (op, reg, off, var):
        cmd = ''

        key = op + '/' + reg + '/' + off
        func = hwMap.get (key)

        if op == 'wr':
            cmd = '  call void @' + func + '(' + var + ')\n'
        else:
            cmd = '  ' + var + ' = call i32 bitcast (i32 (...)* @' + \
                    func + ' to i32 ()*)()\n'

        wFile.write (cmd)

    class FSM:
        IDLE    = 1
        FOUND   = 2
        REGNAME = 3
        OFFSET  = 4
        OPERATE = 5

    state = FSM.IDLE
    reg   = ''
    off   = 0

    for line in llvmSrc:
        words = line.split ()
        if state == FSM.IDLE:
            if (hwMap.tagType in line) and (hwMap.tagName in line):
                if 'load' in line:
                    state = FSM.FOUND
            relayCmd (line)
        elif state == FSM.FOUND:
            assert 'getelementptr inbounds' in line, 'Unexpected llvm pattern'
            state = FSM.REGNAME
        elif state == FSM.REGNAME:
            assert 'getelementptr inbounds' in line, 'Unexpected llvm pattern'
            if words[-1] == '0':
                state = FSM.OPERATE
            else:
                state = FSM.OFFSET
            reg = words[4]
            reg = reg.split (',')[0]
            reg = reg.split('%')[1]
            reg = reg.split('.')[1]
            off = '-1'
        elif state == FSM.OFFSET:
            assert 'getelementptr inbounds' in line, 'Unexpected llvm pattern'
            state = FSM.OPERATE
            off = words[-1] # FIXME 
        elif state == FSM.OPERATE:
            if words[2] == 'load':
                var = words[0]
                registerCmd ('rd', reg, off, var)
            elif words[0] == 'store':
                var = words[1] + ' ' + words[2].split(',')[0]
                registerCmd ('wr', reg, off, var)
            else:
                assert 0, 'Unexpected llvm pattern'
            state = FSM.IDLE
        else:
            assert 0, 'Unexpected state'

    declareList = hwMap.declare
    for dcl in declareList:
        relayCmd (dcl)

    wFile.close ()
    return

if __name__ == '__main__':
    parser = argparse.ArgumentParser ()
    parser.add_argument ("llvm_src", type=str, help="input LLVM IR")
    parser.add_argument ("mapping", type=str, help="MMIO mapping")
    parser.add_argument ("llvm_out", type=str, default="a.ll", help="output file")
    args = parser.parse_args ()

    mmioMap = buildMapping (args.mapping)
    assert (mmioMap is not None), 'Error getting map'
    process (args.llvm_src, mmioMap, args.llvm_out)
