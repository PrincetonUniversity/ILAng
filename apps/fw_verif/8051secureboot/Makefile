.PHONY: SHA
.PHONY: RSA
.PHONY: FW
.PHONY: MAP

MAKEFLAGS += --no-print-directory

encode = atomic
encode = blocking
encode = interleave
export ILA_ENCODE = $(encode)

wrap = manual
wrap = auto
export ILA_WRAP = $(wrap)

export ROOT_PATH = $(shell pwd)
export FW_DIR  = fw
export SHA_DIR = sha
export RSA_DIR = rsa
export MAP_DIR = map

tmpCHC = tmp.smt2
tarCHC = soc.smt2

fwCHC  = $(FW_DIR)/fw.smt2
shaCHC = $(SHA_DIR)/sha.smt2
rsaCHC = $(RSA_DIR)/rsa.smt2
mapCHC = $(MAP_DIR)/map.smt2

all: FW SHA RSA MAP
	@echo "Integrate $(fwCHC) + $(shaCHC) + $(rsaCHC) --> $(tarCHC)"
	@cat $(fwCHC) >  $(tmpCHC)
	@cat $(shaCHC) >> $(tmpCHC)
	@cat $(rsaCHC) >> $(tmpCHC)
	@cat $(mapCHC) >> $(tmpCHC)
	@grep "query" -v $(tmpCHC) > $(tarCHC)
	@grep "query" $(tmpCHC) >> $(tarCHC)
	@rm $(tmpCHC)

MAP:
	@$(MAKE) -C $(MAP_DIR)

SHA: 
	@$(MAKE) -C $(SHA_DIR)

RSA:
	@$(MAKE) -C $(RSA_DIR)

FW:
	@$(MAKE) -C $(FW_DIR)

clean:
	@rm soc.smt2
