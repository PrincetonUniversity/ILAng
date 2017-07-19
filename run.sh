clang -I $HOME/workspace/smack/build/share/smack/include -DFAB_LOCK -DINT_LOCK -UMEM_CHECK -emit-llvm -S *.c
mv *.ll llvmir/
