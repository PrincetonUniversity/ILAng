.PHONY: hwCHC

hwDir=hw/
fwDir=fw/

all: hwCHC 
	@echo "Combining FW and HW CHC"
	@cat $(fwDir)/fw.smt > soc.smt
	@cat $(hwDir)/hw.smt >> soc.smt
	@grep "query" soc.smt >> soc.smt

hwCHC: 
	@$(MAKE) -C $(hwDir)

clean:
	@rm soc.smt
