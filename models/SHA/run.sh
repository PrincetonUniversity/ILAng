#! /bin/bash
python synSHA.py --en 0 ALL >& sha-dis.log
python synSHA.py --en 1 ALL >& sha-en.log
python synSHAuinst.py --en 1 >& sha-uinst-en.log
python synSHAuinst.py --en 0 >& sha-uinst-dis.log
