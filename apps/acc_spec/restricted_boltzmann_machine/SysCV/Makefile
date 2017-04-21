COLLECT=~/ila/util/collect.py
STABLECBMC = ~/cbmc/cbmc

CC=g++
UNWIND=3
include ./make.inc
include ./funlist.txt
mSRCS = $(addprefix ./Cmodel/$(MODULE)/,$(SRCS))

CLANG = ~/clang+llvm-2.9-x86_64-linux.tar/bin/clang
LLC   = ~/clang+llvm-2.9-x86_64-linux.tar/bin/llc
ALLSRC = $(SRCS) vWrapper.cpp

GENSRC = \
	Compute.I0 \
	Compute.I1 \
	Compute.I2 \
	Compute.I3 \
	DMAload.Load \
	Predict.I0 \
	Predict.I1 \
	Predict.I2 \
	Predict.I3 \
	Predict.I4 \
	RBM.ConfInst \
	RBM.readGrant \
	RBM.writeGrant \
	Store.Store \
	Train.I0 \
	Train.I1 \
	Train.I2 \
	Train.I3 \
	Train.I4 \
	Train.I5 
	

template_parse_result: rbm_template.py fixpoint.py
	$(COLLECT) rbm_template.py fixpoint.py

vWrapper.cpp: inputExample.c 
	python RBMVerify.py


vWrapper.li: $(mSRCS) vWrapper.cpp Cmodel/$(MODULE)/common.hpp verifyExample.cpp sysC.h VerC/rbm.hpp VerC/rbm.cpp VerC/data.hpp
	$(CLANG) -S -emit-llvm -I./Cmodel/$(MODULE) -I./VerC -I. vWrapper.cpp
	mv vWrapper.s vWrapper.li

vWrapper.ci: vWrapper.li
	$(LLC) -march=c -o vWrapper.ci vWrapper.li
	
cvv:vWrapper.ci
	mv vWrapper.ci vWrapper.c
	python sanitize.py
	$(STABLECBMC) --unwind $(UNWIND) --unwinding-assertions --slice-formula vWrapper.c

cvvonly:
	$(CLANG) -S -emit-llvm -I./Cmodel/$(MODULE) -I./VerC -I. vWrapper.cpp
	mv vWrapper.s vWrapper.li
	$(LLC) -march=c -o vWrapper.ci vWrapper.li
	mv vWrapper.ci vWrapper.c
	python sanitize.py
	$(STABLECBMC) --unwind $(UNWIND) --unwinding-assertions --slice-formula vWrapper.c


.PHONY: verify

verify:
	$(foreach dirn,$(GENSRC), $(STABLECBMC) --unwind $(UNWIND) --unwinding-assertions --slice-formula InstVerify/$(dirn)/vWrapper.c;)

	
	
	
	
