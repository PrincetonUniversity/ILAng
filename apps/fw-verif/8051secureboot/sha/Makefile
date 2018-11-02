ILA_PATH = $(ILA_ENCODE)

SRC_CHC = $(ILA_PATH)/tmp.smt2
DST_CHC = sha.smt2

INSTRs = sha_w_fe00 sha_w_fe01 sha_r_fe00 sha_r_fe01

.PHONY: auto

all: 
	@$(MAKE) -C $(ILA_PATH)
	@cp $(SRC_CHC) $(DST_CHC)
	@for instr in $(INSTRs); do \
		grep " ($$instr " $(DST_CHC) > $(HW_INSTR_PATH)/$$instr.smt2; \
	done
	@#grep " (sha_w_fe00 " $(DST_CHC) > $(HW_INSTR_PATH)/sha_fe00.smt2
	@#grep " (sha_w_fe01 " $(DST_CHC) > $(HW_INSTR_PATH)/sha_fe01.smt2
	@echo "sha clauses ($(ILA_ENCODE)) are generated in $(shell pwd)/$(DST_CHC)"

clean: 
	@$(MAKE) clean -C $(ILA_PATH)
	@rm $(DST_CHC)
