CC=gcc
CFLAGS= -Wall
INCLUDE=-I.

UTILITY_OBJS=utility/index.o utility/length.o utility/compare.o utility/case_compare.o utility/concatenate.o utility/copy.o utility/chunk_split.o utility/count_chars.o \
	     utility/crc32.o utility/substring_compare.o utility/substring_case_compare.o utility/substring.o utility/string_locate.o utility/access.o utility/join.o \
	     utility/split.o utility/trim.o utility/reverse.o utility/pad.o utility/locate_set.o utility/replace.o utility/index_split.o utility/token_split.o

TYPES_OBJS=types/s_strings_t.o
UNIVERSAL_OBJS=universal/allocate.o universal/error.o

OBJS=$(UTILITY_OBJS) $(TYPES_OBJS) $(UNIVERSAL_OBJS)
OUTP=testing

.c.o:
	$(CC) -c $(CFLAGS) $(INCLUDE) $*.c -o $*.o

testing: $(OBJS)
	$(CC) $(INCLUDE) -o $(OUTP) testing.c $(OBJS)

clean:
	rm $(OBJS) $(OUTP)
