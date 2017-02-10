ILA_PATH = $(ILA_ENCODE)

SRC_CHC = $(ILA_PATH)/tmp.smt2
DST_CHC = rsa.smt2

all: 
	@$(MAKE) -C $(ILA_PATH)
	@cp $(SRC_CHC) $(DST_CHC)
	@grep " (rsa_fd00 " $(DST_CHC) > $(HW_INSTR_PATH)/rsa_fd00.smt2
	@grep " (rsa_fd01 " $(DST_CHC) > $(HW_INSTR_PATH)/rsa_fd01.smt2
	@echo "rsa clauses ($(ILA_ENCODE)) are generated in $(shell pwd)/$(DST_CHC)"

clean: 
	@$(MAKE) clean -C $(ILA_PATH)
	@rm $(DST_CHC)
