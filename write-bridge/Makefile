C_SRC := write-bridge.cc
CFLAGS := -fstack-protector-all -O

ifeq ($(or $(COMSPEC),$(ComSpec)),)
RM := rm -rf
else
RM := cs-rm -rf
endif

ELF ?= $(basename $(firstword $(C_SRC)))
OBJ := $(patsubst %.cc,%.o,$(C_SRC))

.PHONY: all
all: $(OBJ)

.PHONY:
clean:
	$(RM) $(ELF) *.o

$(OBJ): $(C_SRC)
	$(CXX) $(CFLAGS) $< -o write-fpga

