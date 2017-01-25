dir = ./
source = $(addprefix $(dir)/, secureboot.c rsa.c rsa.h)
target = $(dir)/fw.smt

all: $(target)
	@echo "FW CHC Generated."

$(target): $(source)
	@bash -c "source compile.sh"
