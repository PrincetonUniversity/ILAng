SYN_PATH = ./
SYNS = $(addprefix $(SYN_PATH)/, syn_instr.py syn_child.py sim.py)

CHC_PATH = ../horn
CHC_FILE = $(CHC_PATH)/ila.smt

all: $(CHC_FILE) 

$(CHC_FILE): $(SYNS)
	@echo Synthesize ILAs
	@python $(SYN_PATH)/syn_instr.py
	@python $(SYN_PATH)/syn_child.py
	@echo Converting ILAs to CHC
	@python $(SYN_PATH)/chc.py
