ILAPATH = interleave
ILAPATH = blocking
ILAPATH = atomic

SRC_CHC = $(ILAPATH)/tmp.smt
DST_CHC = hw.smt

all: 
	@$(MAKE) -C $(ILAPATH)
	@cp $(SRC_CHC) $(DST_CHC)
	@echo "HW CHC Generated."

clean: 
	@rm $(DST_CHC)
