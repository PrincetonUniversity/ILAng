# template for synthesizing RSA ILA

import ila
import os
from sim import RSA

def createILA ():
    m = ila.Abstraction ('rsa')
    return m


if __name__ == '__main__':
    createILA ()
