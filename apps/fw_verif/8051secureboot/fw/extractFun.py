# python scripts for commenting out MMIO function body in FW.

import os
import sys
import argparse
import util

def removeMMIO(inFile, outFile, funcs, filePath, suffix):
    metMMIO = 0
    res = []
    with open (inFile, 'r') as rFile:
        for line in rFile:
            if metMMIO == 0:
                for fun in funcs:
                    sub1 = '(rule (let ((a!1 (and (' + fun + '@_1'
                    sub2 = '(rule (let ((a!1 (and (' + fun + '@entry'
                    sub3 = '(rule (=> (and (' + fun + '@_1'
                    sub4 = '(rule (=> (and (' + fun + '@entry'
                    if (sub1 in line) or (sub2 in line) or (sub3 in line) or (sub4 in line):
                        metMMIO = 1
                        #print fun, 'removed'
                        newFileName = '%s/%s.%s' % (filePath, fun, suffix)
                        if not os.path.exists (filePath):
                            os.makedirs (filePath)
                        newFile = open (newFileName, 'w')
            elif metMMIO == 1:
                for fun in funcs:
                    sub1 = '(rule (=> (' + fun + '@.split'
                    sub2 = '(rule (=> (' + fun + '@entry.split'
                    if (sub1 in line) or (sub2 in line):
                        metMMIO = 0
                        newFile.close()
            else:
                print 'unknown case'

            if metMMIO == 0:
                res.append (line)
            else:
                newLine = ';' + line
                res.append (newLine)
                newFile.write (line)

    wFile = open (outFile, 'w')
    for line in res:
        wFile.write (line)

    wFile.close()
    rFile.close()

    return

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument ("input_file", type=str,
                         help="input file.")
    parser.add_argument ("output_file", type=str, 
                         help="output file.")
    parser.add_argument ("functions", type=str, nargs='+',
                         help="functions to be removed.")
    parser.add_argument ("--path", type=str, default='info',
                         help="extracted file path")
    parser.add_argument ("--suffix", type=str, default='smt2', 
                         help="file suffix")
    args = parser.parse_args()

    removeMMIO(args.input_file, args.output_file, args.functions, args.path, args.suffix)
