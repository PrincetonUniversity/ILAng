dir	   = .
fwSrc  = $(addprefix $(dir)/, secureboot.c rsa.c rsa.h)
source = $(addprefix $(dir)/, secureboot.c rsa.c)
target = fw.smt2

llvmBc = fw.bc
tmpChc = tmp.smt2

sea     = /home/byhuang/workspace/packages/seahorn/build/run/bin/sea
seahorn = /home/byhuang/workspace/packages/seahorn/build/run/bin/seahorn

all: $(target)
	@python blockMMIO.py $(tmpChc) $(target) HW_REG_WRITE_chr
	@echo FW clauses generated at $(shell pwd)/$(target)

$(target): $(fwSrc)
	@$(sea) fe $(source) -o $(llvmBc)
	@$(seahorn) -keep-shadows=true -horn-inter-proc -horn-step=small -horn-sem-lvl=mem $(llvmBc) -o $(tmpChc)
	@rm $(llvmBc)
