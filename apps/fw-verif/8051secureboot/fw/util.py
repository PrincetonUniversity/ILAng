import os
import sys

def getLineFromFile (inFile):
    res = []
    with open (inFile, 'r') as rFile:
        for line in rFile:
            try:
                #line = line.strip ('\n')
                res.append (line)
            except:
                print 'File', inFile, ' has wrong format when stripping endline'
    return res

