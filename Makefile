CC ?= gcc
PKGCONFIG = $(shell which pkg-config)
CFLAGS = $(shell $(PKGCONFIG) --cflags gtk+- 3.0)
LIBS = $(shell $(PKGCONFIG) --libs gtk+-3.0)

SRC = main.c
OBJ = $(SRC:.c=.o)

%.0 : %.c
	$(CC) -c -o $(@F) $(CFLAGS) $<

main: $(OBJS)
	$(CC) -o $(@F) $(LIBS) $(OBJS)

clean:
	rm -f $(OBJS)
	rm -f $(TARGET)