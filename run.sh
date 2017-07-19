clang -I $HOME/workspace/smack/build/share/smack/include -DINT_LOCK -UMEM_CHECK -emit-llvm -S *.c
rm *.ll
