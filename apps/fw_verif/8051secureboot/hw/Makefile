ILATYPE = interleave
ILATYPE = blocking
ILATYPE = atomic
ILAPATH = $(ILATYPE)
CHCPATH = $(ILATYPE)/horn

CHCS = $(addprefix $(CHCPATH)/, ila.smt map_chr.smt map_int.smt map_ptr.smt common.smt)

all: hw.smt

.PHONY: ILA

hw.smt: $(CHCS) ILA
	@echo "Generating HW CHC"
	@cat $(CHCPATH)/ila.smt > hw.smt
	@cat $(CHCPATH)/common.smt >> hw.smt
	@cat $(CHCPATH)/map_chr.smt >> hw.smt
	@cat $(CHCPATH)/map_int.smt >> hw.smt
	@cat $(CHCPATH)/map_ptr.smt >> hw.smt

ILA:
	@$(MAKE) -C $(ILAPATH)

clean: 
	@rm hw.smt
