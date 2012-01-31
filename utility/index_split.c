/*!
 * @file utility/index_split.c
 * @brief Splits a string based on an array of indexes.
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
 * @brief Splits a string based upon a list of indexes.
 * @param str source string
 * @param indexes array of indexes indicating offsets to split at
 * @param index_count the amount of indexes specified
 * @param count the amount of splits actually made
 * @return Array of strings split by the given indexes, or SAFE_STRING_INVALID if
 * an error was detected.
 * @note The index array will be sorted upon return.
 */
s_strings_t safe_string_index_split(s_string_t str, unsigned long int *indexes, unsigned long int index_count, unsigned long int *count)
{
	if(safe_string_valid(str) && indexes && count) {
		unsigned long int i = 0, j = 0, length = safe_string_length(str), temp = 0, swapped = 1;

		/* validate the indexes */
		for(i = 0; i < index_count; i++) {
			if(indexes[i] >= length) {
				safe_string_set_error(SAFE_STRING_ERROR_INVALID_ARG);
				return(SAFE_STRING_INVALID);
			}
		}

		/* sort the indexes */
		while(swapped) {
			swapped = 0;
			for(i = 1; i < index_count; i++) {
				if(indexes[i] < indexes[i - 1]) {
					temp = indexes[i];
					indexes[i] = indexes[i - 1];
					indexes[i - 1] = temp;
					swapped = 1;
				}
			}
		}

		s_strings_t retn = (s_strings_t)calloc(index_count + 2, sizeof(s_string_t)); /* maximum size */

		if(retn) {
			for(i = 0, j = 0; i < index_count; i++, j = indexes[i - 1]) {
				retn[i] = safe_string_substring(str, j, indexes[i]);
			}
			
			retn[i++] = safe_string_substring(str, j, safe_string_length(str)); /* always needed */
			
			if(realloc(retn, i * sizeof(s_string_t))) {
				*count = i;
				safe_string_set_error(SAFE_STRING_ERROR_NO_ERROR);
				return(retn);
			} else {
				*count = SAFE_STRING_EMPTY;
				safe_string_set_error(SAFE_STRING_ERROR_NO_ERROR);
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
