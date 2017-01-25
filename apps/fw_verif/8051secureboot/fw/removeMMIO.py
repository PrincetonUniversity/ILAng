# python scripts for commenting out MMIO function body in FW.

import os
import argparse

def removeMMIO(inFile, outFile, funcs):
    print inFile, outFile
    print funcs
    return

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument ("input_file", type=str,
                         help="input smt file.")
    parser.add_argument ("output_file", type=str, 
                         help="output smt file.")
    parser.add_argument ("functions", type=str, nargs='+',
                         help="functions to be removed.")
    args = parser.parse_args()

    removeMMIO(args.input_file, args.output_file, args.functions)
