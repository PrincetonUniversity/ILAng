import os
import sys

def getLineFromFile (inFile):
    assert os.path.isfile (inFile), inFile + 'not found'
    res = []
    with open (inFile, 'r') as rFile:
        for line in rFile:
            try:
                #line = line.strip ('\n')
                res.append (line)
            except:
                print 'File', inFile, ' has wrong format when stripping endline'

    rFile.close ()
    return res

