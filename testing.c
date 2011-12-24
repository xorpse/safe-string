#include <stdio.h>

#include "universal.h"
#include "utility.h"
#include "types/types.h"

int main(int argc, char **argv)
{
	unsigned long int i = 0, j = 0;
	s_string_t str = safe_string_new("Hello, world!");
	s_string_t str2;
        s_strings_t strz;

	str2 = safe_string_new("Hello, world!");

	printf("str1 == str2 ? %s\n", !safe_string_case_compare_limit(str, str2, 100) ? "true" : "false");

	safe_string_index_set(str2, 9, 'r');

	printf("str1 == str2 ? %s\n", !safe_string_compare_limit(str, str2, 5) ? "true" : "false");

	safe_string_concatenate_limit(str, str2, 200);

	safe_string_copy(str, str2);

	strz = safe_string_chunk_split(str2, 2, NULL, &i);

	j = i;

	printf("%d %d\n", safe_string_error(), i);

	while(i) {
		printf("%s", strz[--i]->s_string);
	}
	printf("buffer: %s\nlength: %lu\n", str->s_string, safe_string_length(str));

	for(i = 0; i < safe_string_length(str) + 10; i++) {
		printf("%c", safe_string_index(str, i));
	}

	safe_string_delete(str);
	safe_string_array_delete(strz, j);

	str = safe_string_new(NULL);

	printf("buffer: %s", str->s_string);

	return(0);
}
