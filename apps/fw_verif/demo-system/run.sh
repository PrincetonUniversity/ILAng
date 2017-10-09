#!/bin/bash

FW_SRC=$(pwd)/fwsrc
LLVM_SRC=$(pwd)/llvmsrc
LLVM_TAR=$(pwd)/llvmtar
HW_MAP=$(pwd)/mb.mp
OBJ_BPL=$(pwd)/main.bpl
REP_BPL=$(pwd)/main.r.bpl
SMACK_LIB=$(pwd)/smack/include
SCRIPT_PATH=$HOME/workspace/ILA/apps/fw_verif/utils

clang -emit-llvm -S -std=c11 -I $SMACK_LIB -UMEM_OP -UMUTEX -DFAB_LOCK -DCTX_LOCK -DPOR_OPT -UINT_LOCK $FW_SRC/*.c
mv *.ll $LLVM_SRC

for f in $LLVM_SRC/*.ll
do 
    fileName=$(basename "$f")
    #fileName="${fileName%.*}"
    python $SCRIPT_PATH/llvmReplaceMmio.py $LLVM_SRC/$fileName $HW_MAP $LLVM_TAR/$fileName
done

CTX_BND="--context-bound 4"
UNROLL="--unroll 4"
LOOP_LMT="--loop-limit 4"
TIME_LMT="--time-limit 0"
SMACK_FLAG="--pthread --bit-precise -v $CTX_BND $UNROLL $LOOP_LMT $TIME_LMT"

smack $SMACK_FLAG $LLVM_TAR/*.ll -t -bpl $OBJ_BPL
python $SCRIPT_PATH/bplReplacePthread.py $OBJ_BPL $REP_BPL
smack $SMACK_FLAG $REP_BPL 
