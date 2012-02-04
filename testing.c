#include <stdio.h>
#include "universal.h"
#include "utility.h"
#include "types/types.h"

extern s_string_t safe_string_replace(s_string_t, s_string_t, s_string_t);
extern unsigned long int safe_string_locate_set_char(s_string_t str, const char *sset, unsigned long int *index);

extern s_string_t safe_string_substring_replace(s_string_t str, unsigned long int start, unsigned long int end, s_string_t old, s_string_t new);

int main(int argc, char **argv)
{
	unsigned long int i = 0, j = 0, count = 0;
        char *freqs;
	s_string_t str = safe_string_new("z%%^ZHello, world!ZZzz%^");
	s_string_t str2, str3 = safe_string_new("WorLd");
        s_strings_t strz;
	unsigned long int vec[] = { 3, 5, 4, 0, 4, 7 };

	str = safe_string_replace(str, safe_string_new("heloool"), safe_string_new("L"));
	str = safe_string_trim_set_limit(str, "Zz%^", 0);

	str = safe_string_substring_reverse(str, 7, 11);

	str3 = safe_string_rpad(str3, safe_string_new(""), safe_string_length(str3) + 3);

	printf("%s (%lu)\n", safe_string_access_characters(str3, NULL), safe_string_length(str3));

	printf("%s\n", safe_string_access_characters(str, NULL));

	if(safe_string_locate_set_char(str, "w", &i)) {
		printf("%lu\n", i);
	}

	str2 = safe_string_substring_replace(safe_string_new("lHello, world!"), 5, 12, safe_string_new("o"), safe_string_new("ll"));
	
	printf("%s\n", safe_string_access_characters(str2, SAFE_STRING_INVALID));

	s_string_t delim = safe_string_new("l");

	strz = safe_string_token_split_char(str2, "lo", &count);

	printf("count: %lu\n", count);

	for(i = 0; i < count; i++) {
		const char *s = safe_string_access_characters(strz[i], &j);
		if(safe_string_error()) {
			printf("%d\n", safe_string_error_val());
		}
		printf("%s\n", s);
	}
	printf("%p, %p, %p\n", str2, vec, &count);

	strz = safe_string_index_split(str2, vec, 6, &count);

	printf("%d %lu\n", safe_string_error_val(), count);

	for(i = 0; i < count; i++) {
		const char *s = safe_string_access_characters(strz[i], &j);
		if(safe_string_error()) {
			printf("%d\n", safe_string_error_val());
		}
		printf("%s\n", s);
	}


	printf("%s\n", safe_string_access_characters(safe_string_join_char(strz, count, "l"), NULL));

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
