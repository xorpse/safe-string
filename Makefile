CC=gcc
CFLAGS=-c -Wall
INCLUDE=-I.

all: universal allocate.o utility testing.o
	$(CC) $(INCLUDE) universal/error.o allocate.o utility/compare.o utility/length.o utility/index.o testing.o -o testing

testing.o: testing.c
	$(CC) $(CFLAGS) $(INCLUDE) testing.c -o testing.o

allocate.o: allocate.c
	$(CC) $(CFLAGS) $(INCLUDE) allocate.c -o allocate.o

utility: utility/length.o utility/index.o utility/compare.o

utility/length.o: utility/length.c
	$(CC) $(CFLAGS) $(INCLUDE) utility/length.c -o utility/length.o

utility/index.o: utility/index.c
	$(CC) $(CFLAGS) $(INCLUDE) utility/index.c -o utility/index.o

utility/compare.o: utility/compare.c
	$(CC) $(CFLAGS) $(INCLUDE) utility/compare.c -o utility/compare.o

universal: universal/error.o

universal/error.o: universal/error.c
	$(CC) $(CFLAGS) $(INCLUDE) universal/error.c -o universal/error.o

clean:
	rm -Rf *.o
