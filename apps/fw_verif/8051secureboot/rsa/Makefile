ILA_PATH = $(ILA_ENCODE)

SRC_CHC = $(ILA_PATH)/tmp.smt2
DST_CHC = hw.smt2

all: 
	@$(MAKE) -C $(ILA_PATH)
	@cp $(SRC_CHC) $(DST_CHC)
	@echo "rsa clauses ($(ILA_ENCODE)) are generated in $(shell pwd)/$(DST_CHC)"

clean: 
	@rm $(DST_CHC)
