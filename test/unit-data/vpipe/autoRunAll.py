#!/usr/bin/env python
import os

rootDir = '.'
allTaskInfo = {} # 'path -> result'

ignored_subdir = set()

cmd = "bash run.sh"


# --------------------- HELPER --------------------- ##        
def ExecOnPath(p):
    if not os.path.exists(p):
        print 'Path:',p,'does not exist'
        return
    if not os.path.exists(os.path.join(p,'run.sh')):
        # ignored
        ignored_subdir.add(p)
        return
    if not os.path.exists(os.path.join(p,'gen_btor.ys')):
        # ignored
        allTaskInfo[p] = "skip"
        return
        
    curDir = os.getcwd()
    os.chdir(p)
    print 'cd',p
    finalCmd = cmd
    print 'exec:',finalCmd
    
    os.system("rm -f *.btor *.btor2") 
    ret = os.system(finalCmd)
    if ret == 256:
        ret = 1   
    elif ret == 65280:
        ret = 255
    elif ret == 512:
        ret = 2
        
    os.chdir(curDir)
    allTaskInfo[p] = ret
 
# --------------------- MAIN --------------------- ##     

for dirName, subdirList, fileList in os.walk(rootDir):
    for subDirName in subdirList:
        ExecOnPath(os.path.join(dirName, subDirName))

print
print '----------- PASSED ------------'
for t,r in allTaskInfo.items():
    if r == 1:
        print t

print
print '----------- UNKNOWN ------------'
for t,r in allTaskInfo.items():
    if r == 255:
        print t        
        
print
print '----------- FAILED ------------'
for t,r in allTaskInfo.items():
    if r == 0:
        print t

print
print '----------- SKIPPED ------------'
for t,r in allTaskInfo.items():
    if r == "skip":
        print t    
 
print
print '----------- No Valid run.sh ------------'
print ignored_subdir    

print
print '----------- STATUS-ERR ------------'
for t,r in allTaskInfo.items():
    if r not in [0,1,255,"skip"]:
        print r,':',t
        
