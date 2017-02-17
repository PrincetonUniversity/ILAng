dir	   = $(shell pwd)
fwSrc  = $(addprefix $(dir)/, secureboot.c rsa.c rsa.h)
source = $(addprefix $(dir)/, secureboot.c rsa.c)
target = $(dir)/fw.smt2

llvmBc = $(dir)/fw.bc
tmpChc = $(dir)/tmp.smt2

mmioFuncs = HW_REG_WRITE_chr HW_REG_READ_chr
infoPath  = $(FW_FUN_PATH)
fileSuff  = smt2

sea		= /u/byhuang/workspace/seaHornILA/seahorn/build/run/bin/sea
seahorn = /u/byhuang/workspace/seaHornILA/seahorn/build/run/bin/seahorn
sea     = /home/byhuang/workspace/packages/seahorn/build/run/bin/sea
seahorn = /home/byhuang/workspace/packages/seahorn/build/run/bin/seahorn

all: $(target)
	@python extractFun.py $(tmpChc) $(target) $(mmioFuncs) --suffix=$(fileSuff) --path=$(infoPath)
	@for mmio in $(mmioFuncs); do \
		python reasonFun.py $$mmio --path=$(infoPath) --suffix=$(fileSuff); \
	done
	@echo FW clauses generated at $(target)

$(target): $(fwSrc)
	@#$(sea) fe $(source) -o $(llvmBc)
	@$(sea) clang $(source) -o $(llvmBc)
	@$(seahorn) -keep-shadows=true -horn-inter-proc -horn-step=small -horn-sem-lvl=mem $(llvmBc) -o $(tmpChc)
	@rm $(llvmBc)

clean:
	@for file in $(fwSrc); do ]
		touch $$file; ]
	done
	rm $(target)
