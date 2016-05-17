#! /bin/bash

regs="PC ACC IRAM PSW SP DPL DPH B XRAM_ADDR XRAM_DATA_OUT P0 P1 P2 P3 PCON TCON TMOD TL0 TH0 TL1 TH1 SCON SBUF IE IP "
for r in $regs;
do
    python uc8051syn.py $r >& $r-en.out
    python uc8051syn.py --en 0 $r >& $r-en.out
done
