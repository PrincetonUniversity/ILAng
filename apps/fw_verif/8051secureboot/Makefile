.PHONY: hwCHC
.PHONY: fwCHC

hwDir=hw/
fwDir=fw/

all: hwCHC fwCHC
	@echo "Combining FW and HW CHC"
	@cat $(fwDir)/fw.smt > soc.smt
	@cat $(hwDir)/hw.smt >> soc.smt
	@grep "query" soc.smt >> soc.smt

hwCHC: 
	@$(MAKE) -C $(hwDir)

fwCHC:
	@$(MAKE) -C $(fwDir)

clean:
	@rm soc.smt
