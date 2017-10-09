# File: bplReplacePthread.py
# Synopsis: Replace pthread int type for bit precise check

import os
import sys
import argparse
import common

class int2bvFilter ():
    def __init__ (self):
        self.mapping = {}
        self.add ('procedure  corral_getThreadID() returns (x:int);\n',
                  'procedure  corral_getThreadID() returns (x:bv32);\n')
        self.add ('procedure  corral_getChildThreadID() returns (x:int);\n',
                  'procedure  corral_getChildThreadID() returns (x:bv32);\n')
        self.add ('  assume (forall i:int :: $pthreadStatus[i][0] == $pthread_uninitialized);\n',
                  '  assume (forall i:bv32 :: $pthreadStatus[i][0] == $pthread_uninitialized);\n')
        self.add ('var $pthreadStatus: [int][int]int;\n',
                  'var $pthreadStatus: [bv32][int]int;\n')
        """
        self.add ('var $pthreadStatus: [int][int]int;\n',
                  'var $pthreadStatus: [bv32][int]bv32;\n')
        self.add ('const unique $pthread_uninitialized: int;\n',
                  'const unique $pthread_uninitialized: bv32;\n')
        self.add ('const unique $pthread_initialized: int;\n',
                  'const unique $pthread_initialized: bv32;\n')
        self.add ('const unique $pthread_waiting: int;\n',
                  'const unique $pthread_waiting: bv32;\n')
        self.add ('const unique $pthread_running: int;\n',
                  'const unique $pthread_running: bv32;\n')
        self.add ('const unique $pthread_stopped: int;\n',
                  'const unique $pthread_stopped: bv32;\n')
        """

    def add (self, key, val):
        self.mapping[key] = val 

    def filt (self, inLine):
        if inLine in self.mapping:
            return self.mapping[inLine]
        else:
            return inLine

def process (inFile, outFile):
    srcLines = common.getLineFromFile (inFile)

    bvFilter = int2bvFilter ()

    wFile = open (outFile, 'w')
    for line in srcLines:
        wFile.write (bvFilter.filt (line))

    wFile.close ()
    return

if __name__ == '__main__':
    parser = argparse.ArgumentParser ()
    parser.add_argument ("bpl_src", type=str, help="input bpl file")
    parser.add_argument ("bpl_tar", type=str, help="output bpl file")

    args = parser.parse_args ()

    process (args.bpl_src, args.bpl_tar)
