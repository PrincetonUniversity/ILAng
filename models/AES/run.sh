#! /bin/bash
python synAES.py --en 0 ALL |& tee aes-dis.log
python synAES.py --en 1 ALL |& tee aes-en.log
python synAESuinst.py --en 1 |& tee aes-uinst-en.log
python synAESuinst.py --en 0 |& tee aes-uinst-dis.log
