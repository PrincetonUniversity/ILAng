SYN_PATH = ila

HORN_PATH = horn
ALL_CHC = $(addprefix $(HORN_PATH)/, $(shell ls $(HORN_PATH)))
MAP_CHC = $(addprefix $(HORN_PATH)/, $(shell ls $(HORN_PATH) | grep "map"))
MAP_CHC = $(addprefix $(HORN_PATH)/, map_0.smt2 map_1.smt2)
COM_CHC = $(addprefix $(HORN_PATH)/, $(shell ls $(HORN_PATH) | grep "common"))
ILA_CHC = $(addprefix $(HORN_PATH)/, $(shell ls $(HORN_PATH) | grep "ila"))
TAR_CHC = tmp.smt2

.PHONY: SYN

all: SYN
	@cat $(ILA_CHC) > $(TAR_CHC)
	@cat $(COM_CHC) >> $(TAR_CHC)
	@for chc in $(MAP_CHC); do \
		cat $$chc >> $(TAR_CHC); \
	done

SYN:
	@$(MAKE) -C $(SYN_PATH)

