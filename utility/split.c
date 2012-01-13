/*!
 * @file utility/split.c
 * @brief Splits a string based on a delimeter (similar to PHP's split
 * function)
 * @author Sam Thomas <s@ghost.sh>
 *
 * @section LICENSE
 * Copyright (c) 2011 Sam Thomas <s@ghost.sh>
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
/*
s_strings_t safe_string_split_limit_char(s_string_t str, const char *delim, unsigned long int elements, unsigned long int *count)
{
	s_string_t temp = safe_string_new(delim);
	s_strings_t retn = safe_string_split_limit(str, temp, elements, count);
	s_string_error_t error = safe_string_error_val();
	safe_string_delete(temp);
	safe_string_set_error(error);
	return(retn);
}
*/

s_strings_t safe_string_split_limit(s_string_t str, s_string_t delim, unsigned long int elements, unsigned long int *count)
{
	if(safe_string_valid(str) && safe_string_valid(delim) && count) {
		if(safe_string_length(delim) < safe_string_length(str)) {
			unsigned long int i = 0, j = 0, limit = safe_string_length(str) / safe_string_length(delim), found = 0;
			unsigned long int *offsets = (unsigned long int *)malloc(sizeof(unsigned long int) * limit);

			if(offsets) {
				while((i < limit) && ((found < elements) || !elements)) { /* if elements = 0, then we don't care how many we find */
					offsets[found] = safe_string_string_locate_offset(str, delim, i);

					if(safe_string_error()) {
						if(safe_string_error_val() != SAFE_STRING_ERROR_INVALID_RETURN) {
							free(offsets);
							return(SAFE_STRING_INVALID);
						} else {
							break;
						}
					} else {
						i = offsets[found++] + safe_string_length(delim) ;
					}
				}

				s_strings_t retn = (s_strings_t)calloc(found + 2, sizeof(s_string_t)); /* maximum size */

				if(retn) {

					for(i = 0; i < found; j = offsets[i] + safe_string_length(delim), i++) {
						retn[i] = safe_string_substring(str, j, offsets[i]);
						printf("(%lu,%lu)\n", j, offsets[i]);
					}

					retn[i++] = safe_string_substring(str, j, safe_string_length(str)); /* always needed */

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
			s_strings_t retn = (s_strings_t)calloc(1, sizeof(s_string_t));
			if(retn) {
				unsigned long int chars;
				retn[0] = safe_string_new(safe_string_access_characters(str, &chars));
				if(retn[0]) {
					*count = 1;
					safe_string_set_error(SAFE_STRING_ERROR_NO_ERROR);
					return(retn); /* this is the case where we don't need to split */
				} else {
					free(retn);
					*count = SAFE_STRING_EMPTY;
					safe_string_set_error(SAFE_STRING_ERROR_MEM_ALLOC);
					return(SAFE_STRING_INVALID);
				}
			} else 	{
				*count = SAFE_STRING_EMPTY;
				safe_string_set_error(SAFE_STRING_ERROR_MEM_ALLOC);
				return(SAFE_STRING_INVALID);
			}
		}
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return(SAFE_STRING_INVALID);
	}
}
/*
s_strings_t safe_string_split_char(s_string_t str, const char *delim, unsigned long int *count)
{
	s_string_t temp = safe_string_new(delim);
	s_strings_t retn = safe_string_split(str, temp);
	s_string_error_t error = safe_string_error_val();
	safe_string_delete(temp);
	safe_string_set_error(error);
	return(retn);
}

s_strings_t safe_string_split(s_string_t str, s_string_t delim)
{
}
*/
