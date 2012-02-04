/*!
 * @file utility/token_split.c
 * @brief Splits a string based upon a list of characters.
 * @author Sam Thomas <s@ghost.sh>
 *
 * @section LICENSE
 * Copyright (c) 2012 Sam Thomas <s@ghost.sh>
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include "types/types.h"
#include "utility.h"
#include "universal.h"
#include "macro.h"

/*!
 * @brief Internal function to check if specific character is in a given set
 * @param c character to test for
 * @param set set to test if character is in
 * @return 1 if character is in set, 0 otherwise
 */
static inline int _char_in_set(char c, s_string_t set)
{
	if(safe_string_valid(set)) {
		unsigned long int i = 0;

		for(i = 0; i < safe_string_length(set); i++) {
			if(c == safe_string_index(set, i)) {
				return(1);
			}
		}
		
		return(0);
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return(0);
	}
}

/*!
 * @brief Splits input string into tokens by splitting on elements specified by the elements of
 * another string.
 * @param str source string
 * @param tokens the string containing the characters to split on
 * @param count the amount of elements created by splitting
 * @return An array of strings created by splitting the source string.
 */
s_strings_t safe_string_token_split_char(s_string_t str, const char *tokens, unsigned long int *count)
{
	return(safe_string_token_split_limit_char(str, tokens, 0, count));
}

/*!
 * @brief Splits input string into tokens by splitting on elements specified by the elements of
 * another string.
 * @param str source string
 * @param tokens the string containing the characters to split on
 * @param limit the maximum amount of splits t make, 0 for unlimited splits
 * @param count the amount of elements created by splitting
 * @return An array of strings created by splitting the source string.
 */
s_strings_t safe_string_token_split_limit_char(s_string_t str, const char *tokens, unsigned long int limit, unsigned long int *count)
{
	if(tokens) {
		s_string_t temp = safe_string_new(tokens);

		if(!safe_string_error()) {
			s_strings_t retn = safe_string_token_split_limit(str, temp, limit, count);
			safe_string_delete(temp);
			return(retn);
		} else {
			return(SAFE_STRING_INVALID);
		}
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return(SAFE_STRING_INVALID);
	}
}

/*!
 * @brief Splits input string into tokens by splitting on elements specified by the elements of
 * another string.
 * @param str source string
 * @param tokens the string containing the characters to split on
 * @param count the amount of elements created by splitting
 * @return An array of strings created by splitting the source string.
 */
s_strings_t safe_string_token_split(s_string_t str, s_string_t tokens, unsigned long int *count)
{
	return(safe_string_token_split_limit(str, tokens, 0, count));
}

/*!
 * @brief Splits input string into tokens by splitting on elements specified by the elements of
 * another string.
 * @param str source string
 * @param tokens the string containing the characters to split on
 * @param limit the maximum amount of splits t make, 0 for unlimited splits
 * @param count the amount of elements created by splitting
 * @return An array of strings created by splitting the source string.
 */
s_strings_t safe_string_token_split_limit(s_string_t str, s_string_t tokens, unsigned long int limit, unsigned long int *count)
{
	if(safe_string_valid(str) && safe_string_valid(tokens) && count) {
		unsigned long int i = 0, j = 0, found = 0, length = safe_string_length(str);
		unsigned long int *offsets = (unsigned long int *)malloc(sizeof(unsigned long int) * safe_string_length(str));

		if(offsets) {
			while((i < length) && ((found < limit) || !limit)) { /* if limit = 0, then we don't care how many we find */
				if(_char_in_set(safe_string_index(str, i), tokens)) {
					offsets[found++] = i;
				}
				i++;
			}
				

			s_strings_t retn = (s_strings_t)calloc(found + 2, sizeof(s_string_t)); /* maximum size */

			if(retn) {

				for(i = 0; i < found; j = offsets[i] + 1, i++) {
					retn[i] = safe_string_substring(str, j, offsets[i]);
				}

				retn[i++] = (j >= safe_string_length(str)) ? safe_string_new("") :  safe_string_substring(str, j, safe_string_length(str)); /* always needed */
				if(realloc(retn, i * sizeof(s_string_t))) {
					free(offsets);
					*count = i;
					safe_string_set_error(SAFE_STRING_ERROR_NO_ERROR);
					return(retn);
				} else {
					*count = SAFE_STRING_EMPTY;
					free(offsets);
					safe_string_set_error(SAFE_STRING_ERROR_NO_ERROR);
					return(SAFE_STRING_INVALID);
				}
			} else {
				free(offsets);
				safe_string_set_error(SAFE_STRING_ERROR_MEM_ALLOC);
				return(SAFE_STRING_INVALID);
			}
		} else {
			safe_string_set_error(SAFE_STRING_ERROR_MEM_ALLOC);
			return(SAFE_STRING_INVALID);
		}
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return(SAFE_STRING_INVALID);
	}
}
