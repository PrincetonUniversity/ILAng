#!/bin/bash

FW_SRC=$(pwd)/fwsrc
LLVM_SRC=$(pwd)/llvmsrc
LLVM_TAR=$(pwd)/llvmtar
HW_MAP=$(pwd)/mb.mp
OBJ_BPL=$(pwd)/main.bpl
REP_BPL=$(pwd)/main.r.bpl
SMACK_LIB=$(pwd)/smack
SCRIPT_PATH=$HOME/workspace/ILA/apps/fw_verif/utils

clang -emit-llvm -S -std=c11 -I $SMACK_LIB $FW_SRC/*.c
mv *.ll $LLVM_SRC

CONTEXT_FLAG="--context-bound 4"
UNROLL_FLAG="--unroll 4"
LOOP_FLAG="--loop-limit 4"
STATIC_FLAG=""
TIMEOUT_FLAG="--time-limit 3600"
SMACK_FLAG="--pthread --bit-precise -v $CONTEXT_FLAG $UNROLL_FLAG $LOOP_FLAG $STATIC_FLAG $TIMEOUT_FLAG"

smack $SMACK_FLAG $LLVM_SRC/*.ll -t -bpl $OBJ_BPL
python $SCRIPT_PATH/bplReplacePthread.py $OBJ_BPL $REP_BPL
smack $SMACK_FLAG $REP_BPL
