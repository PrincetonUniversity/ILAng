ILATYPE=concurrent
ILATYPE=atomic
CHCPATH=$(ILATYPE)/horn

all: hw.smt

hw.smt: $(CHCPATH)/ila.smt $(CHCPATH)/map_chr.smt
	@echo "Generating HW CHC"
	@cat $(CHCPATH)/ila.smt > hw.smt
	@cat $(CHCPATH)/map_chr.smt >> hw.smt

clean: 
	@rm hw.smt
