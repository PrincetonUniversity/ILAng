#!/usr/bin/env python
import os

rootDir = '.'
allTaskInfo = {} # 'path -> result'
env = '/home/hongce/cosaEnv/bin/activate'
cosa = '/home/hongce/CoSA/CoSA.py'
solver = 'btor'

cmd = "env bash -c 'source %s ; %s --problem %s --solver=%s --vcd'"


# --------------------- HELPER --------------------- ##        
def ExecOnPath(p):
    if not os.path.exists(p):
        print 'Path:',p,'does not exist'
        return
    if not os.path.exists(os.path.join(p,'problem.txt')):
        # ignored
        return
    curDir = os.getcwd()
    os.chdir(p)
    print 'cd',p
    finalCmd = cmd % (env, cosa, 'problem.txt', solver)
    print 'exec:',finalCmd
    ret = os.system(finalCmd)     
    os.chdir(curDir)
    allTaskInfo[p] = ret
 
# --------------------- MAIN --------------------- ##     

for dirName, subdirList, fileList in os.walk(rootDir):
    for subDirName in subdirList:
        ExecOnPath(os.path.join(dirName, subDirName))

print
print '----------- PASSED ------------'
for t,r in allTaskInfo.items():
    if r == 0:
        print t
        
print
print '----------- FAILED ------------'
for t,r in allTaskInfo.items():
    if r != 0:
        print t
        
