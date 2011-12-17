CC=gcc
CFLAGS=-c -Wall
INCLUDE=-I.

all: allocate.o utility testing.o
	$(CC) $(INCLUDE) allocate.o utility/length.o testing.o -o testing

testing.o: testing.c
	$(CC) $(CFLAGS) $(INCLUDE) testing.c -o testing.o

allocate.o: allocate.c
	$(CC) $(CFLAGS) $(INCLUDE) allocate.c -o allocate.o

utility: utility/length.o

utility/length.o: utility/length.c
	$(CC) $(CFLAGS) $(INCLUDE) utility/length.c -o utility/length.o

clean:
	rm -Rf *.o
