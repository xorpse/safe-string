CC=gcc
CFLAGS=-c -Wall
INCLUDE=-I.

all: allocate.o utility testing.o
	$(CC) $(INCLUDE) allocate.o utility/length.o utility/index.o testing.o -o testing

testing.o: testing.c
	$(CC) $(CFLAGS) $(INCLUDE) testing.c -o testing.o

allocate.o: allocate.c
	$(CC) $(CFLAGS) $(INCLUDE) allocate.c -o allocate.o

utility: utility/length.o utility/index.o

utility/length.o: utility/length.c
	$(CC) $(CFLAGS) $(INCLUDE) utility/length.c -o utility/length.o

utility/index.o: utility/index.c
	$(CC) $(CFLAGS) $(INCLUDE) utility/index.c -o utility/index.o
clean:
	rm -Rf *.o
