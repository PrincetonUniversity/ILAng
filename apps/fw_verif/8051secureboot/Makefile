.PHONY: SHA
.PHONY: RSA
.PHONY: FW
.PHONY: MAP
.PHONY: PRE
.PHONY: POST

MAKEFLAGS += --no-print-directory

encode = atomic
encode = blocking
encode = interleave
export ILA_ENCODE = $(encode)

wrap = manual
wrap = auto
export ILA_WRAP = $(wrap)

FW_DIR  = fw
SHA_DIR = sha
RSA_DIR = rsa
MAP_DIR = map
export ROOT_PATH 		= $(shell pwd)
export FW_FUN_PATH      = $(ROOT_PATH)/$(MAP_DIR)/fw_fun
export HW_INSTR_PATH    = $(ROOT_PATH)/$(MAP_DIR)/hw_instr
export MAP_CONNECT_PATH = $(ROOT_PATH)/$(MAP_DIR)/connect

tmpCHC = tmp.smt2
tarCHC = soc.smt2

fwCHC  = $(FW_DIR)/fw.smt2
shaCHC = $(SHA_DIR)/sha.smt2
rsaCHC = $(RSA_DIR)/rsa.smt2
mapCHC = $(MAP_DIR)/map.smt2
comCHC = $(MAP_CONNECT_PATH)/map_var.smt2

all: PRE FW SHA RSA MAP POST
	@echo "Integrate $(fwCHC) + $(shaCHC) + $(rsaCHC) --> $(tarCHC)"
	@cat $(fwCHC)  >  $(tmpCHC)
	@cat $(comCHC) >> $(tmpCHC)
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

PRE:
	@bash -c "mkdir -p $(FW_FUN_PATH)"
	@bash -c "mkdir -p $(HW_INSTR_PATH)"
	@bash -c "mkdir -p $(MAP_CONNECT_PATH)"

shareVars  = "XRAM" "XRAM_0" "XRAM_1" "cmd" cmdaddr "cmddata"
declareStr = "(declare-var "
shareLines = $(addprefix $(declareStr), $(shareVars))

POST:
	@for line in $(shareLines); do \
		grep "$$line" -v $(shaCHC) > $(tmpCHC); \
		mv $(tmpCHC) $(shaCHC); \
	done
	@for line in $(shareLines); do \
		grep "$$line" -v $(rsaCHC) > $(tmpCHC); \
		mv $(tmpCHC) $(rsaCHC); \
	done

clean:
	@rm soc.smt2
