.PHONY: hwCHC
.PHONY: fwCHC

hwDir=hw/
fwDir=fw/

tmpSmt2=tmp.smt2
tarSmt2=soc.smt2
fwSmt2=$(fwDir)/fw.smt2
hwSmt2=$(hwDir)/hw.smt2

all: hwCHC fwCHC
	@echo "Combining FW and HW CHC"
	@cat $(fwSmt2) >  $(tmpSmt2)
	@cat $(hwSmt2) >> $(tmpSmt2)
	@cat $(tmpSmt2) > $(tarSmt2)
	@grep "query" $(tmpSmt2) >> $(tarSmt2)
	@rm $(tmpSmt2)

hwCHC: 
	@$(MAKE) -C $(hwDir)

fwCHC:
	@$(MAKE) -C $(fwDir)

clean:
	@rm soc.smt2
