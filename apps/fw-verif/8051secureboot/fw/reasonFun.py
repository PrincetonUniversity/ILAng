# python scripts for reasoning mmio function body.

import os
import sys
import argparse
import util

def reasonFun (funName, filePath, fileSuff):
    fileName = '%s/%s.%s' % (filePath, funName, fileSuff)
    if not os.path.isfile (fileName):
        print 'File ', fileName, ' not exist.'
        return

    lines = util.getLineFromFile (fileName)

    entryFileName = '%s/%s_entry.%s' % (filePath, funName, fileSuff)
    entryFile = open (entryFileName, 'w')
    exitFileName  = '%s/%s_exit.%s' % (filePath, funName, fileSuff)
    exitFile  = open (exitFileName, 'w')

    isRead = False
    # find out entry memory,
    firstSelect = ''
    selectPattern = '(select '
    for line in lines:
        if selectPattern in line:
            firstSelect = line
            break

    elements = firstSelect.split()
    entryMem = elements[1]

    # copy the entry part into the new file, also find addr and data
    cmd_addr = ''
    cmd_data = ''
    for line in lines:
        entryFile.write (line)
        if '@%addr' in line:
            cmd_addr = line
        if '@%data' in line:
            cmd_data = line
        if 'true' in line:
            break

    entryFile.write ('\t\t(= %s entryMem)\n' % entryMem)

    if not (cmd_addr == ''):
        entryFile.write ('\t\t(= %s mmio_input_addr)\n' % cmd_addr.strip().strip(')'))
    else: 
        print '[Horn-Warning]', funName, 'does not have mmio_input_addr'

    if not (cmd_data == ''):
        entryFile.write ('\t\t(= %s mmio_input_data)\n' % cmd_data.strip().strip(')'))
    else: 
        isRead = True

    entryFile.close()
            
    # find out exit memory
    lastStore = ''
    prevLine  = ''
    prevStore = ''
    storePattern = '(store '
    for line in lines:
        if storePattern in line:
            lastStore = line
            prevStore = prevLine
        else:
            prevLine = line

    elements = prevStore.split()
    exitMem = elements[1]
    
    # copy the exit part (and return value) into the new file
    prevLine = ''
    returnLine = ''
    reach = 0
    for line in lines:
        if lastStore in line:
            reach = 1
        if (reach == 1) and ('a!1' in line):
            reach = 2
        if reach == 2:
            returnLine = prevLine
            reach = 3
        prevLine = line

    if isRead:
        returnValElem = returnLine.split()
        returnVal = returnValElem[1]
        exitFile.write ('\t\t(= %s returnVal)\n' % returnVal)

    exitFile.write ('\t\t(= %s exitMem)\n' % exitMem)
    exitFile.write ('\t\t)))\n')
    reach = 0
    for line in lines:
        if lastStore in line:
            reach = 1
        if reach == 1 and 'a!1' in line:
            reach = 2
        if reach == 2:
            exitFile.write (line)

    exitFile.close()

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument ("funName", type=str,
                         help="funxtion name")
    parser.add_argument ("--path", type=str, default='info',
                         help="file path")
    parser.add_argument ("--suffix", type=str, default='smt2', 
                         help="file suffix")
    args = parser.parse_args()

    reasonFun (args.funName, args.path, args.suffix)
