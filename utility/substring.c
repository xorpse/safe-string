/*!
 * @file utility/substring.c
 * @brief Returns a substring of a string
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
#include "universal.h"
#include "utility.h"
#include "macro.h"

/*!
 * @brief Extracts a string from within another string.
 * @param str source string
 * @param offset starting index for extraction
 * @param limit ending index for extraction
 * @return A safe string containing the substring defined by the bounaries 'offset'
 * and 'limit'.
 * @note Sets the error value indicating success or failure.
 */
s_string_t safe_string_substring(s_string_t str, unsigned long int offset, unsigned long int limit)
{
	if(safe_string_valid(str)) {
		if(offset < safe_string_length(str) && offset <= limit) {
			limit = MIN(safe_string_length(str), limit);

			if(limit - offset) {
				char *string = (char *)calloc((limit - offset) + 1, sizeof(char));

				if(string) {
					unsigned int i = 0;
					s_string_t retn;

					while(offset <= limit) {
						string[i++] = safe_string_index(str, offset++);
					}

					retn = safe_string_new(string);
					free(string);

					return(retn); /* use the error code from safe_string_new */
				} else {
					safe_string_set_error(SAFE_STRING_ERROR_MEM_ALLOC);
					return(SAFE_STRING_INVALID);
				}
			} else {
				return(safe_string_new(SAFE_STRING_INVALID));
			}
		} else {
			safe_string_set_error(SAFE_STRING_ERROR_INVALID_ARG);
			return(SAFE_STRING_INVALID);
		}
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return(SAFE_STRING_INVALID);
	}
}

/*!
 * @brief Extracts a string from within another string. Using only a starting position,
 * extraction is performed using the length of the string as an upper bound.
 * @param str source string
 * @param offset starting index for extraction
 * @return A safe string containing the substring defined by the bounary 'offset'
 * and the length of the source string.
 * @note Sets the error value indicating success or failure.
 */
s_string_t safe_string_substring_auto(s_string_t str, unsigned long int offset)
{
	if(safe_string_valid(str)) {
		return(safe_string_substring(str, offset, safe_string_length(str)));
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return(SAFE_STRING_INVALID);
	}
}
