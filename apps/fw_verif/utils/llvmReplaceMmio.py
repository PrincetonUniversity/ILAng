# File: llvmReplaceMmio.py
# Synopsis: Replace the set of MMIO READ/WRITE that uses interface variable.

import os
import sys
import argparse

def buildMapping (mapFile):
    """ Mapping Format:
        _Type [mmio container type]
        _Name [mmio container pointer variable]
        _MapWrite [function to call] [struct tier 0] [struct tier 1] ...
        _MapRead [function to call] [struct tier 0] [struct tier 1] ...
    """
    return None

def process (srcFile, mmioMap, outFile) :
    return

if __name__ == '__main__':
    parser = argparse.ArgumentParser ()
    parser.add_argument ("llvm_src", type=str, help="input LLVM IR")
    parser.add_argument ("mapping", type=str, help="MMIO mapping")
    parser.add_argument ("--out", type=str, default="a.ll", help="output file")
    args = parser.parse_args ()

    mmioMap = buildMapping (args.mapping)
    process (args.llvm_src, mmioMap, args.out)
