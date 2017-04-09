#! /bin/bash

for w in 4 8 16 32;
do
  for regs in 4 8 16 32;
  do
    echo alu_${regs}_${w}
    timeout 1800s python alu.py --numregs $regs --regwidth $w
  done
done

for w in 4 8 16 32;
do
  for regs in 4 8 16 32;
  do
    echo alu_${regs}_${w}
    timeout 1800s python alu.py --enable-param-syn 0 --numregs $regs --regwidth $w
  done
done
