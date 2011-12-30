/*!
 * @file utility/chunk_split.c
 * @brief Implementation of PHP's chunk_split
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
#include <string.h>
#include "types/types.h"
#include "universal.h"
#include "utility.h"
#include "macro.h"

/*!
 * @brief Splits a string into chunks of a certain size, with an optional delimeter concatenated
 * @param str source string
 * @param size length of each chunk
 * @param delim the delimeter to concatenate to each chunk (if NULL then nothing is concatenated)
 * @param count the variable to store the amount of strings that will be returned
 * @return An array of strings, or SAFE_STRING_INVALID in case of an error
 * @note Sets the error variable indicating success or failure
 */
s_strings_t safe_string_chunk_split(s_string_t str, unsigned long int size, const char *delim, unsigned long int *count)
{
	if(size) {
		if(safe_string_valid(str) && count) {
			s_string_t delimeter = safe_string_new(delim);
			char *strn = (char *)calloc(size + 1, size);
			*count = (safe_string_length(str) / size) + (safe_string_length(str) % size ? 1 : 0);

			s_strings_t chunks = (s_string_t *)calloc(*count, sizeof(s_string_t));

			if(chunks && strn && delimeter) {
				unsigned long int i = 0;

				for(i = 0; i < *count; i++) {
					strncpy(strn, (str->s_string + (i * size)), size);
					chunks[i] = safe_string_new(strn);
					safe_string_concatenate(chunks[i], delimeter); 

					if(!chunks[i]) {
						while(i) {
							safe_string_delete(chunks[--i]);
						}
						free(chunks);
						
						safe_string_set_error(SAFE_STRING_ERROR_MEM_ALLOC);
						return(SAFE_STRING_INVALID);
					}
				}

				safe_string_set_error(SAFE_STRING_ERROR_NO_ERROR);
				safe_string_delete(delimeter);
				return(chunks);
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
