SYN_PATH = $(shell pwd)
SYNS = $(addprefix $(SYN_PATH)/, syn.py sim.py)
ILA_PATH = $(ROOT_PATH)/rsa/interleave/ila

CHC_PATH = ../horn
CHC_FILE = $(CHC_PATH)/ila.smt2

all: 
	@$(MAKE) -C $(ILA_PATH)
	@rm -rf asts
	@cp -r $(ILA_PATH)/asts asts
	@python $(SYN_PATH)/chc.py

$(CHC_FILE): 
	@$(MAKE) -C $(ILA_PATH)
	@#python $(SYN_PATH)/syn.py

clean:
	rm $(CHC_FILE)
