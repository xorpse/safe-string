#include <stdio.h>
#include "universal.h"
#include "utility.h"
#include "types/types.h"

int main(int argc, char **argv)
{
	unsigned long int i = 0, j = 0, count = 0;
        char *freqs;
	s_string_t str = safe_string_new("Hello, world!");
	s_string_t str2, str3 = safe_string_new("WorLd");
        s_strings_t strz;

	str2 = safe_string_new("lHello, world!l");
	s_string_t delim = safe_string_new("l");

	strz = safe_string_split_limit_char(str2, "l", 0, &count);

	for(i = 0; i < count; i++) {
		const char *s = safe_string_access_characters(strz[i], &j);
		if(safe_string_error()) {
			printf("ERROR\n");
		}
		printf("%s\n", s ? s : "null");
	}

	printf("str1 == str2 ? %s\n", !safe_string_case_compare_limit(str, str2, 100) ? "true" : "false");

	safe_string_index_set(str2, 9, 'R');

	printf("str1 == str2 ? %s\n", !safe_string_compare_limit(str, str2, 5) ? "true" : "false");

	printf("str1(7) == str3 ? %s\n", !safe_string_substring_case_compare(str, str3, 7) ? "true" : "false");

	printf("error? %s\n", safe_string_error() ? "yes" : "no");

	s_string_t str4 = safe_string_substring(str, 7, 11);

	printf("%lu\n", safe_string_string_locate(str, str4));

	safe_string_concatenate_limit(str, str2, 200);

	safe_string_copy(str, str2);

	safe_string_array_delete(strz, count);
	
	strz = safe_string_chunk_split(str2, 2, NULL, &i);

	j = i;

	printf("%d %d\n", safe_string_error(), i);

	for(i = 0; i < j; i++) {
		if(strz[i]->s_string) {
			printf("%s\n", strz[i]->s_string);
		} else {
			printf("null\n");
		}
	}
	printf("buffer: %s\nlength: %lu\n", str->s_string, safe_string_length(str));

	for(i = 0; i < safe_string_length(str) + 10; i++) {
		printf("%c", safe_string_index(str, i));
	}

	//safe_string_delete(str);
	safe_string_array_delete(strz, j);

	freqs = safe_string_count_chars(str, S_COUNT_CHARS_MODE_CHARS_NOT_UNIQUE, &i);

	printf("%lu\n", i);

	while(i--) {
		printf("%c\n", freqs[i]);
	}

	printf("buffer: %s", str->s_string);
	
	safe_string_delete(str);
	return(0);
}
