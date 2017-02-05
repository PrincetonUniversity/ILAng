.PHONY: shaCHC
.PHONY: rsaCHC
.PHONY: fwCHC

MAKEFLAGS += --no-print-directory

encode = atomic
encode = blocking
encode = interleave
export ILA_ENCODE = $(encode)

fwDir  = fw
shaDir = sha
rsaDir = rsa

tmpSmt2 = tmp.smt2
tarSmt2 = soc.smt2

fwSmt2  = $(fwDir)/fw.smt2
shaSmt2 = $(shaDir)/hw.smt2
rsaSmt2 = $(rsaDir)/hw.smt2

all: fwCHC shaCHC rsaCHC 
	@echo Concat $(fwSmt2), $(shaSmt2), and $(rsaSmt2) to $(tarSmt2)
	@cat $(fwSmt2) >  $(tmpSmt2)
	@cat $(shaSmt2) >> $(tmpSmt2)
	@cat $(rsaSmt2) >> $(tmpSmt2)
	@grep "query" -v $(tmpSmt2) > $(tarSmt2)
	@grep "query" $(tmpSmt2) >> $(tarSmt2)
	@rm $(tmpSmt2)

shaCHC: 
	@$(MAKE) -C $(shaDir)

rsaCHC:
	@$(MAKE) -C $(rsaDir)

fwCHC:
	@$(MAKE) -C $(fwDir)

clean:
	@rm soc.smt2
