#!/usr/bin/python
from R2 import *


if __name__ == '__main__':
    ila.setloglevel(3,"")
    ila.enablelog("BMCResult")
    
    aesR = buildTwoModels()
    print 'built Complete.'
    checkEQ(aesR)
    print 'prove Complete.'
