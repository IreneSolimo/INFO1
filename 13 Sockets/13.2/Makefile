ejecutables= cliente servidor 
CC=gcc
CFLAGS=-g -c -Wall
LDFLAGS=-g -Wall -L/usr/local/lib/ -lInfo1sock
#L may path, l min nombre
SOBJS=servidor.o
COBJS=cliente.o
SSOURCES=$(SOBJS:.o=.c)
CSOURCES=$(COBJS:.o=.c)
HEADERS=*.h

all: $(ejecutables)

cliente: $(COBJS)
	$(CC) $(COBJS) -o cliente $(LDFLAGS)
%.o: %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

servidor: $(SOBJS)
	$(CC) $(SOBJS) -o servidor $(LDFLAGS)
%.o: %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@	

clean:
	rm -f ./*.o
	rm -f $(ejecutables)

#rebuild
new: clean all

