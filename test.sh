clang -I $HOME/workspace/smack/build/share/smack/include -emit-llvm -S *.c
rm *.ll
