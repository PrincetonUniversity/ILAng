SYN_PATH = $(shell pwd)
SYNS = $(addprefix $(SYN_PATH)/, syn.py sim.py)

CHC_PATH = ../horn
CHC_FILE = $(CHC_PATH)/ila.smt2

all: $(CHC_FILE)
	@python $(SYN_PATH)/chc.py

$(CHC_FILE): $(SYNS)
	@python $(SYN_PATH)/syn.py

clean:
	rm $(CHC_FILE)
