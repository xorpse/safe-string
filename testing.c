#include <stdio.h>

#include "allocate.h"
#include "utility/length.h"
#include "utility/index.h"
#include "types/types.h"

int main(int argc, char **argv)
{
	int i = 0;
	s_string_t str = safe_string_new("Hello, world!");
	
	printf("buffer: %s\nlength: %lu\n", str->s_string, safe_string_length(str));

	for(i = 0; i < safe_string_length(str) + 10; i++) {
		printf("%c", safe_string_index(str, i));
	}

	safe_string_delete(str);

	str = safe_string_new(NULL);

	printf("buffer: %s", str->s_string);

	return(0);
}
