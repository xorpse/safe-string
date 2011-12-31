/*!
 * @file utility/count_chars.c
 * @brief Adapted implementation of PHP's count_chars function
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

#include "stdlib.h"
#include "limits.h"
#include "types/types.h"
#include "universal.h"
#include "utility.h"
#include "macro.h"

/*!
 * @brief Returns specific frequencies of characters from a given string
 * @param str source string
 * @param mode for valid modes see the s_string_count_chars_mode_t definition
 * @param count address of the variable to store the amount of elements in the returned array
 * @return Array containing frequencies of characters specified by the mode
 * @note Sets the error variable indicating success or failure
 */
unsigned long int *_safe_string_count_chars_freqs(s_string_t str, s_string_count_chars_mode_t mode, unsigned long int *count)
{
	if(_S_COUNT_CHARS_MODE_FREQS(mode)) {
		if(safe_string_valid(str) && count) {
			unsigned long int *counts = (unsigned long int *)calloc(S_CHARSET_LIMIT, sizeof(unsigned long int));

			if(counts) {
				unsigned long int i = 0;

				for(i = 0; i < safe_string_length(str); i++) {
					counts[safe_string_index(str, i)]++;
				}
				
				switch(mode) {
					case S_COUNT_CHARS_MODE_FREQS_COUNT:
						safe_string_set_error(SAFE_STRING_ERROR_NO_ERROR);
						*count = S_CHARSET_LIMIT;
						return(counts);
						break;
					default:
						/* some strange error */
						safe_string_set_error(SAFE_STRING_ERROR_BAD_VALUE);
						free(counts);
						*count = SAFE_STRING_EMPTY;
						return(SAFE_STRING_INVALID);
						break;
				}
			} else {
				safe_string_set_error(SAFE_STRING_ERROR_MEM_ALLOC);
				return(SAFE_STRING_INVALID);
			}
		} else {
			safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
			return(SAFE_STRING_INVALID);
		}
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_INVALID_ARG);
		return(SAFE_STRING_INVALID);
	}
}

/*!
 * @brief Returns specific characters from a given string
 * @param str source string
 * @param mode for valid modes see the s_string_count_chars_mode_t definition
 * @param count address of the variable to store the amount of elements in the returned array
 * @return Array containing characters from the string specified by the mode
 * @note Sets the error variable indicating success or failure
 */
char *_safe_string_count_chars_chars(s_string_t str, s_string_count_chars_mode_t mode, unsigned long int *count)
{
	if(_S_COUNT_CHARS_MODE_CHARS(mode)) {
		if(safe_string_valid(str) && count) {
			char *rcounts = (char *)calloc(S_CHARSET_LIMIT, sizeof(char));
			unsigned long int *counts = (unsigned long int *)calloc(S_CHARSET_LIMIT, sizeof(unsigned long int));

			if(counts && rcounts) {
				unsigned long int i = 0, j = 0;

				for(i = 0; i < safe_string_length(str); i++) {
					counts[safe_string_index(str, i)]++;
				}

				switch(mode) {
					case S_COUNT_CHARS_MODE_CHARS_USED:
						for(i = 0, j = 0; i < S_CHARSET_LIMIT; i++) {
							if(counts[i] > 0) {
								rcounts[j++] = (char)i;
							}
						}
						break;
					case S_COUNT_CHARS_MODE_CHARS_UNUSED:
						for(i = 0, j = 0; i < S_CHARSET_LIMIT; i++) {
							if(counts[i] == 0) { /* clarity */
								rcounts[j++] = (char)i;
							}
						}
						break;
					case S_COUNT_CHARS_MODE_CHARS_UNIQUE:
						for(i = 0, j = 0; i < S_CHARSET_LIMIT; i++) {
							if(counts[i] == 1) {
								rcounts[j++] = (char)i;
							}
						}
						break;
					case S_COUNT_CHARS_MODE_CHARS_NOT_UNIQUE:
						for(i = 0, j = 0; i < S_CHARSET_LIMIT; i++) {
							if(counts[i] > 1) {
								rcounts[j++] = (char)i;
							}
						}
						break;
					default:
						/* some strange error */
						safe_string_set_error(SAFE_STRING_ERROR_BAD_VALUE);
						free(counts);
						*count = SAFE_STRING_EMPTY;
						return(SAFE_STRING_INVALID);
						break;
				}

				if(!j || realloc(rcounts, j * sizeof(char))) {
					safe_string_set_error(SAFE_STRING_ERROR_NO_ERROR);
					free(counts);
					*count = j;
					return(rcounts);
				} else {
					safe_string_set_error(SAFE_STRING_ERROR_MEM_ALLOC);
					free(counts);
					free(rcounts);
					*count = SAFE_STRING_EMPTY;
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
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_INVALID_ARG);
		return(SAFE_STRING_INVALID);
	}
}
