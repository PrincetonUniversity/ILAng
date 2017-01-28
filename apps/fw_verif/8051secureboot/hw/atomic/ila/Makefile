SYN_PATH = ./
SYNS = $(addprefix $(SYN_PATH)/, syn.py sim.py)

CHC_PATH = ../horn
CHC_FILE = $(CHC_PATH)/ila.smt2

all: $(CHC_FILE)
	@echo Converting ILAs to CHC
	@python $(SYN_PATH)/chc.py

$(CHC_FILE): $(SYNS)
	@echo Synthesize ILAs
	@python $(SYN_PATH)/syn.py
