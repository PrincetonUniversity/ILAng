# File: llvmReplaceMmio.py
# Synopsis: Replace the set of MMIO READ/WRITE that uses interface variable.

import os
import sys
import argparse
import common

class mapStructType ():
    def __init__ (self):
        self.mapping = {}
        self.declare = {}
        self.tagType = ''
        self.tagName = ''

    def get (self, inStr):
        return self.mapping[inStr]

    def add (self, key, func):
        self.mapping[key] = func

    def addDeclare (self, key, dcl):
        self.declare[key] = dcl

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
            key = 'wr/{}/{}'.format (words[2], words[3])
            hwMap.add (key, words[1])
        elif tag == '_MapRd':
            key = 'rd/{}/{}'.format (words[2], words[3])
            hwMap.add (key, words[1])
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

        key = '{}/{}/{}'.format (op, reg, off)
        func = hwMap.get (key)

        if op == 'wr':
            dcl = 'declare void @{}(i32)\n'.format (func)
            cmd = '  call void @{}({})\n'.format (func, var)
        else:
            dcl = 'declare i32 @{}(...)\n'.format (func)
            cmd = '  {} = call i32 bitcast (i32 (...)* @{} to i32 ()*)()\n'.format (var, func)

        hwMap.addDeclare (key, dcl)
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
                    found = True
            relayCmd (line)
        elif state == FSM.FOUND:
            assert 'getelementptr inbounds' in line, 'Unexpected llvm pattern'
            state = FSM.REGNAME
        elif state == FSM.REGNAME:
            assert 'getelementptr inbounds' in line, 'Unexpected llvm pattern'
            if words[-2] == '!dbg':
                if words[-3] == '0,':
                    state = FSM.OPERATE
                else:
                    state = FSM.OFFSET
            else:
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
            # XXX starting from 0
            if words[-2] == '!dbg':
                off = words[-3].split (',')[0]
            else:
                off = words[-1] 
        elif state == FSM.OPERATE:
            if words[2] == 'load':
                var = words[0]
                registerCmd ('rd', reg, off, var)
            elif words[0] == 'store':
                var = '{} {}'.format (words[1], words[2].split(',')[0])
                registerCmd ('wr', reg, off, var)
            else:
                assert 0, 'Unexpected llvm pattern'
            state = FSM.IDLE
        else:
            assert 0, 'Unexpected state'

    declareList = hwMap.declare
    for key in declareList:
        relayCmd (declareList[key])

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
