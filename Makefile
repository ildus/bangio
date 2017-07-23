CC = gcc
DEPS = linuxgpio.h bitbang.h
OBJ = linuxgpio.o bitbang.o
SRC = linuxgpio.c bitbang.c test.c
CFLAGS = -I. -std=gnu11 -g3 -Os -Wall -Werror -fpic

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

libbangio.so: $(OBJ)
	$(CC) -shared -o $@ $^

test: test.o
	$(CC) -o $@ $^ $(CFLAGS) -lbangio -L.

format: $(SRC) $(DEPS)
	astyle $^ --style=bsd --indent=tab

install: libbangio.so
	cp $^ /usr/lib/

clean:
	rm -f *.so *.o *~ *.c.orig *.orig ./test
