# template for SHA ILA without child-instructions.

import ila
import os
from sim import SHA

def createIla():
    m = ila.Abstraction ('sha')
    return m

if __name__ == '__main__':
    createIla()
