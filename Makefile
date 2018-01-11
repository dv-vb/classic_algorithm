CC=${CROSS}-gcc
CFLAGS= -g -Wall -pthread
LD=${CROSS}-ld
LDFLAGS=
DEPENDFLAG=
INCLUDES=./
LIBS=
CFLAGS:=$(CFLAGS) -I$(INCLUDES)
LDFLAGS:=$(LDFLAGS) $(LIBS)
SRCDIRS=.

XML=*.xml
SHL=sh
BUILD_DIR=./build
SRCS := $(wildcard $(SRCDIRS)/*.c)
OBJS := $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRCS))
PROGRAMS := $(patsubst %.c, $(BUILD_DIR)/%.elf, $(SRCS))
.PHONY: all

all: env  $(PROGRAMS)
	
$(BUILD_DIR)/%.elf: $(BUILD_DIR)/%.o
	$(CC) $(CFLAGS) $< -o $@
	
$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

env:
	@$(shell if [ ! -d $(BUILD_DIR) ]; then mkdir $(BUILD_DIR); fi)
	
clean:
	rm $(DEPENDS) $(PROGRAMS)
	@rm -r $(BUILD_DIR)
