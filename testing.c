#include <stdio.h>

#include "universal.h"
#include "utility.h"
#include "types/types.h"

int main(int argc, char **argv)
{
	int i = 0;
	s_string_t str = safe_string_new("Hello, world!");
	s_string_t str2;

	str2 = safe_string_new("Hello, woRld!");

	printf("str1 == str2 ? %s\n", !safe_string_case_compare_limit(str, str2, -100) ? "true" : "false");

	safe_string_index_set(str2, 9, 'r');

	printf("str1 == str2 ? %s\n", !safe_string_compare(str, str2) ? "true" : "false");

	safe_string_concatenate_limit(str, str2, 200);

	printf("buffer: %s\nlength: %lu\n", str->s_string, safe_string_length(str));

	for(i = 0; i < safe_string_length(str) + 10; i++) {
		printf("%c", safe_string_index(str, i));
	}

	safe_string_delete(str);

	str = safe_string_new(NULL);

	printf("buffer: %s", str->s_string);

	return(0);
}
