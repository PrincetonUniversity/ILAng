ILATYPE = atomic
ILATYPE = concurrent
ILATYPE = blocking
ILAPATH = $(ILATYPE)
CHCPATH = $(ILATYPE)/horn

CHCS = $(addprefix $(CHCPATH)/, ila.smt map_chr.smt)

all: hw.smt

.PHONY: ILA

hw.smt: $(CHCS) ILA
	@echo "Generating HW CHC"
	@cat $(CHCPATH)/ila.smt > hw.smt
	@cat $(CHCPATH)/map_chr.smt >> hw.smt

ILA:
	@$(MAKE) -C $(ILAPATH)

clean: 
	@rm hw.smt
