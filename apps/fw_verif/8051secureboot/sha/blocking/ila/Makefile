SYN_PATH = $(shell pwd)
SYNS = $(addprefix $(SYN_PATH)/, syn.py sim.py simulate.py)
ILA_PATH = $(ROOT_PATH)/sha/interleave/ila

CHC_PATH = ../horn
CHC_FILE = $(CHC_PATH)/ila.smt2

all: auto

auto: $(CHC_FILE)
	@#$(MAKE) -C $(ILA_PATH)
	@#rm -rf asts
	@#cp -r $(ILA_PATH)/asts asts
	@python $(SYN_PATH)/chcAuto.py

manual: $(CHC_FILE)
	@python $(SYN_PATH)/chc.py

$(CHC_FILE): $(SYNS)
	@python $(SYN_PATH)/syn.py

clean:
	rm $(CHC_FILE)
