CC=gcc
CFLAGS= -Wall
INCLUDE=-I.

ALLOCATE_OBJS=allocate.o
UTILITY_OBJS=utility/index.o utility/length.o utility/compare.o utility/case_compare.o
UNIVERSAL_OBJS=universal/error.o

OBJS=$(ALLOCATE_OBJS) $(UTILITY_OBJS) $(UNIVERSAL_OBJS)

.c.o:
	$(CC) -c $(CFLAGS) $(INCLUDE) $*.c -o $*.o

testing: $(OBJS)
	$(CC) $(INCLUDE) -o testing testing.c $(OBJS)

clean:
	rm $(OBJS)
