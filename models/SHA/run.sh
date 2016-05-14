#! /bin/bash
python synSHA.py --en 0 ALL |& tee sha-dis.log
python synSHA.py --en 1 ALL |& tee sha-en.log
python synSHAuinst.py --en 1 |& tee sha-uinst-en.log
python synSHAuinst.py --en 0 |& tee sha-uinst-dis.log
