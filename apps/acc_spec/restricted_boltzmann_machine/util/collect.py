#!/usr/bin/python
import argparse
import os
from os import system

def shouldConvert(line, renameList, newList):
    kw = line.split()
    if 'from' in kw:
        idx = kw.index('from')
        moduleName = kw[idx+1]
    elif 'import' in kw:
        idx = kw.index('import')
        moduleName = kw[idx+1]
    else:
        return line,False

    if moduleName in renameList:
        newModuleName = newList[renameList.index(moduleName)]
        kw[idx+1] = newModuleName
        if len(kw) == 2 and kw[0] == 'import':
            kw.append('as')
            kw.append(moduleName)
        nl = ' '.join(kw) + '\n'
        return nl,True
    return line,False


def convertLine(line):
    kw = line.split()
    if kw == ['import','HiRTLSim']:
        return 'import dummyILA as HiRTLSim\n'
    if kw[0] == 'import' and kw[1] == 'RefRTLSim' and kw[2] == 'as' and len(kw) == 4:
        return 'import dummyILA as ' + kw[3] + '\n'
    if line == 'from CSim import CSim':
        return 'from dummyILA import CSim\n'
    if line == 'import CSim':
        return 'import dummyILA as CSim\n'
	if line == 'import SysCSim':
		return 'import dummyILA as SysCSim'
    if kw == ['import','ila']:
        return 'import dummyILA as ila\n'
    if kw[0] == 'import' and kw[1] == 'ila' and kw[2] == 'as' and len(kw) == 4:
        return 'import dummyILA as ' + kw[3] + '\n' 
    return line

def modify(renameList, newList):
    for idx in range(len(renameList)):
        oldName = renameList[idx]
        newName = newList[idx]
        oldfileName = oldName+".py"
        newfileName = os.path.join(os.path.split(os.path.abspath(oldName))[0],newName+'.py') 
        with open(oldfileName, 'rt' ) as inf:
            with open(newfileName, 'wt') as outf:
                for line in inf.xreadlines():
                    if 'import' in line:
                        nl, convert = shouldConvert(line, renameList, newList)
                        if convert:
                            outf.write(nl)
                            continue
                        outf.write(convertLine(line))
                        continue
                    outf.write(line)
                    continue

                if idx == 0: # this is the top module
                    outf.write('\nimport atexit\natexit.register(ila.exitHandler)\n')


                    
            

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument("modules", metavar='Module', type=str, nargs = '+', help="modules to parse (top module the first one)")
    parser.add_argument("-n","--no-clear",action='store_true', dest = 'no_clear', default = False, help = "don't clear temp file")
    args = parser.parse_args()
    
    # infile
    # temp
    # rename
    # run 
    if args.modules:
        oldList = [fname.split('.')[0] for fname in args.modules]
        newList = [fname.split('.')[0] + '__Temp__' for fname in args.modules]
        modify(oldList,newList)
        system('python '+newList[0] + '.py')

        flag = True
        for newModule in newList:
            newfileName = os.path.join(os.path.split(os.path.abspath(newModule+'.py'))[0],newModule+'.py') 
            #print newfileName
            if not args.no_clear:
                system('rm '+newfileName)
            if flag:
                flag = False
                continue
            newfileName = os.path.join(os.path.split(os.path.abspath(newModule+'.py'))[0],newModule+'.pyc') 
            if not args.no_clear:
                system('rm '+newfileName)

            
