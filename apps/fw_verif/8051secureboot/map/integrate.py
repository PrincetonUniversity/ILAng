# scripts to compile the mapping.

import os
import sys
import argparse
#import util

def checkPath (path):
	if not os.path.exists (path):
		print 'Path', path, 'not exist.'
		return False
	return True

def createMap (mapConnectPath, fwFunPath, hwInstrPath, outFileName):
    outFile = open (outFileName, 'w')
    outFile.close()


if __name__ == '__main__':
	parser = argparse.ArgumentParser()
	parser.add_argument ("mapConnectPath", type = str,
						 help = "path for map connection")
	parser.add_argument ("fwFunPath", type = str,
						 help = "path for firmware function")
	parser.add_argument ("hwInstrPath", type = str,
						 help = "path for hardware instruction")
	parser.add_argument ("outFileName", type = str,
						 help = "output file for mapping clauses")
	args = parser.parse_args()

	createMap (args.mapConnectPath, args.fwFunPath, args.hwInstrPath, args.outFileName)
