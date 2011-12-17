CC=gcc
CFLAGS=-c -Wall

all: allocate.o

allocate.o: allocate.c
	$(CC) $(CFLAGS) allocate.c

clean:
	rm -Rf *.o
