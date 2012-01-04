CC=gcc
CFLAGS= -Wall
INCLUDE=-I.

UTILITY_OBJS=utility/index.o utility/length.o utility/compare.o utility/case_compare.o utility/concatenate.o utility/copy.o utility/chunk_split.o utility/count_chars.o \
	     utility/crc32.o utility/substring_compare.o
UNIVERSAL_OBJS=universal/allocate.o universal/error.o

OBJS=$(UTILITY_OBJS) $(UNIVERSAL_OBJS)
OUTP=testing

.c.o:
	$(CC) -c $(CFLAGS) $(INCLUDE) $*.c -o $*.o

testing: $(OBJS)
	$(CC) $(INCLUDE) -o $(OUTP) testing.c $(OBJS)

clean:
	rm $(OBJS) $(OUTP)
