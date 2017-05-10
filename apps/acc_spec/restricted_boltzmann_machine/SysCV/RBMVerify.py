import SysCVerifInstrument
import os

def test():
    CppOutName = 'predict_mod'
    SaveTarget = 'Predict.I4'

    sysCInst = SysCVerifInstrument.SysCInstrument(cFileName = 'inputExample.c')
    sysCInst.Annotate(which = 4,StartN = 0,CclassName = 'rbm', funlist = './Cmodel/%s/funlist.txt' % CppOutName)


    with open('make.inc','wt') as makefile:
        makefile.write('MODULE = %s\nCPTARGET = %s\n' % (CppOutName,SaveTarget))
    os.system('cp ./Cmodel/%s/funlist.txt ./' % CppOutName)

# unit test
if __name__ == '__main__':
    test()
