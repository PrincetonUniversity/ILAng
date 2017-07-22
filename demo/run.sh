#!/bin/bash

FW_SRC=$(pwd)/fwsrc
LLVM_SRC=$(pwd)/llvmsrc
LLVM_TAR=$(pwd)/llvmtar
HW_MAP=$(pwd)/mb.mp
SCRIPT_PATH=$HOME/workspace/ILA/apps/fw_verif/utils

clang -emit-llvm -S -std=c11 -I $HOME/workspace/smack/build/share/smack/include -DFAB_LOCK -DINT_LOCK -UMEM_CHECK $FW_SRC/*.c
mv *.ll $LLVM_SRC

for f in $LLVM_SRC/*.ll
do 
    fileName=$(basename "$f")
    #fileName="${fileName%.*}"
    python $SCRIPT_PATH/llvmReplaceMmio.py $LLVM_SRC/$fileName $HW_MAP $LLVM_TAR/$fileName
done

smack --pthread --context-bound 3 -v $LLVM_TAR/*.ll -w err.log
