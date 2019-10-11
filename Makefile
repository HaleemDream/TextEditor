CC ?= gcc
PKGCONFIG = $(shell which pkg-config)
CFLAGS = $(shell $(PKGCONFIG) --cflags gtk+-3.0)
LIBS = $(shell $(PKGCONFIG) --libs gtk+-3.0)

SUBDIR_ROOTS := . buffer files menu
DIRS := . $(shell find $(SUBDIR_ROOTS) -type d)
GARBAGE_PATTERNS := *.o
GARBAGE := $(foreach DIR,$(DIRS),$(addprefix $(DIR)/,$(GARBAGE_PATTERNS)))

SRC = main.c menu/main_menu.c buffer/read.c
OBJS = $(SRC:.c=.o)

all: main clean

%.o: %.c
	$(CC) -c -o $(@F) $(CFLAGS) $< -o $@

main: $(OBJS)
	$(CC) -o $(@F) $(OBJS) $(LIBS)

clean:
	rm -rf $(GARBAGE)