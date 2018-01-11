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
BUILD_DIR?=./build
SRCS := $(wildcard $(SRCDIRS)/*.c)
OBJS := $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRCS))
PROGRAMS := $(patsubst %.c, $(BUILD_DIR)/%.elf, $(SRCS))
.PHONY: 

all: $(OBJS) $(PROGRAMS)
	
$(BUILD_DIR)/%.elf: %.o
	$(CC) $(CFLAGS) $(BUILD_DIR)/$< -o $@

$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJS) $(DEPENDS) $(PROGRAMS)
