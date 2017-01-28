ILAPATH = interleave
ILAPATH = blocking
ILAPATH = atomic

SRC_CHC = $(ILAPATH)/tmp.smt2
DST_CHC = hw.smt2

all: 
	@$(MAKE) -C $(ILAPATH)
	@cp $(SRC_CHC) $(DST_CHC)
	@echo "HW CHC Generated."

clean: 
	@rm $(DST_CHC)
