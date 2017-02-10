
tarCHC = map.smt2

all: $(test)
	@python integrate.py $(MAP_CONNECT_PATH) $(FW_FUN_PATH) $(HW_INSTR_PATH) $(tarCHC)
	@echo mapping clauses are generated in $(shell pwd)/$(tarCHC)

clean:
	@rm $(tarCHC)
