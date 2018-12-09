import ila
import CVerifInstrument
import os

def LoadIla():
    cILA = ila.Abstraction('caes')
    cILA.importAll('cILA/all')
    cuILA = cILA.get_microabstraction('aes_compute')
    cuILA.importAll('cILA/allu')
    return cILA, cuILA

def test():
    cILA, cuILA = LoadIla()
    os.system('mkdir -p CVerify/aes')
    os.system('mkdir -p CVerify/aes_compute')
    cILA.generateCbmcCtoDir('CVerify/aes')
    cuILA.generateCbmcCtoDir('CVerify/aes_compute')

# unit test
if __name__ == '__main__':
    test()
     
    
