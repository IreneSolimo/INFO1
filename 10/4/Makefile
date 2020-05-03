all: executable

CC=gcc
CFLAGS=-c -g
LDFLAGS=
OBJS=main.o funciones.h funciones.c

executable: $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

%.o: %.c Makefile
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f ./*.o
	rm -f executable