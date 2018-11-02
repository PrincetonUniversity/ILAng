SYN_PATH = ila

HORN_PATH = horn
ALL_CHC = $(addprefix $(HORN_PATH)/, $(shell ls $(HORN_PATH)))
MAP_CHC = $(addprefix $(HORN_PATH)/, $(shell ls $(HORN_PATH) | grep "test"))
MAP_CHC = $(addprefix $(HORN_PATH)/, $(shell ls $(HORN_PATH) | grep "map"))
COM_CHC = $(addprefix $(HORN_PATH)/, $(shell ls $(HORN_PATH) | grep "sum_shared"))
COM_CHC = $(addprefix $(HORN_PATH)/, $(shell ls $(HORN_PATH) | grep "common"))
ILA_CHC = $(addprefix $(HORN_PATH)/, $(shell ls $(HORN_PATH) | grep "ila"))
TAR_CHC = tmp.smt2

.PHONY: SYN

all: SYN
	@cat $(ILA_CHC) > $(TAR_CHC)
ifeq ($(ILA_WRAP), manual)
	@cat $(COM_CHC) >> $(TAR_CHC)
	@for chc in $(MAP_CHC); do \
		cat $$chc >> $(TAR_CHC); \
	done
endif

SYN:
	@$(MAKE) $(ILA_WRAP) -C $(SYN_PATH)

clean:
	@$(MAKE) clean -C $(SYN_PATH)
