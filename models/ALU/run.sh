#! /bin/bash

for regs in 4 8 16 32;
do
  for w in 4 8 16 32;
  do
    echo alu_${regs}_${w}
    python alu.py --numregs $regs --regwidth $w
  done
done

for regs in 4 8 16 32;
do
  for w in 4 8 16 32;
  do
    echo alu_${regs}_${w}
    python alu.py --enable-param-syn 0 --numregs $regs --regwidth $w
  done
done
