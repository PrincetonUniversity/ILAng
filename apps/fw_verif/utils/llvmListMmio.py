# File: llvmListMmio.py
# Synopsis: List the set of MMIO READ/WRITE that uses interface variable.
# Usage: python listVarMmio.py [args] <type> <name> <llvm-ir>
# Arguments: 

import os
import sys
import argparse

def process () :
    return

if __name__ == '__main__':
    parser = argparse.ArgumentParser ()
    parser.add_argument ("input_file", type=str, default="main.llA",
            help="inpue file")
    parser.add_argument
