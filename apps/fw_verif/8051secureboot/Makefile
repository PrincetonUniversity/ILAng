.PHONY: hwCHC
.PHONY: fwCHC

hwDir=hw/
fwDir=fw/

all: hwCHC fwCHC
	@echo "Combining FW and HW CHC"
	@cat $(fwDir)/fw.smt2 > soc.smt2
	@cat $(hwDir)/hw.smt2 >> soc.smt2
	@grep "query" soc.smt2 >> soc.smt2

hwCHC: 
	@$(MAKE) -C $(hwDir)

fwCHC:
	@$(MAKE) -C $(fwDir)

clean:
	@rm soc.smt2
