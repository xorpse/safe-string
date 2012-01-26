/*!
 * @file utility/reverse.c
 * @brief String and substring reversal functions.
 * each joined string.
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

#include "types/types.h"
#include "utility.h"
#include "universal.h"

/*!
 * @brief Swaps two elements in a string. (internal)
 * @param str source string
 * @param start first element to exchange
 * @param end second element to exchange
 */
inline void _safe_string_index_swap(s_string_t str, unsigned long int start, unsigned long int end)
{
	if(safe_string_valid(str)) {
		if(start <= end && end < safe_string_length(str)) {
			char c = safe_string_index(str, start);

			safe_string_index_set(str, start, safe_string_index(str, end));
			safe_string_index_set(str, end, c);

			/* if an error was detected then it will be
			 * returned from one of the indexing functions
			 */

			return;
		} else {
			safe_string_set_error(SAFE_STRING_ERROR_INVALID_ARG);
			return;
		}
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return;
	}
}

/*!
 * @brief Reverses the order of characters of a substring of a string.
 * @param str source string
 * @param start starting index of the string 
 * @param end ending index of the string 
 * @return String with inner substring reversed.
 */
s_string_t safe_string_substring_reverse(s_string_t str, unsigned long int start, unsigned long int end)
{
	if(safe_string_valid(str)) {
			if(start <= end && end < safe_string_length(str)) {
				while(start < end) {
					_safe_string_index_swap(str, start, end);
					start++; end--;
				}

				safe_string_set_error(SAFE_STRING_ERROR_NO_ERROR);
				return(str);
			} else {
				safe_string_set_error(SAFE_STRING_ERROR_INVALID_ARG);
				return(SAFE_STRING_INVALID);
			}
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return(SAFE_STRING_INVALID);
	}
}

/*
 * @brief Reverses the order of characters of a string.
 * @param str source string
 * @return String with order of characters reversed.
 */
s_string_t safe_string_reverse(s_string_t str)
{
	if(safe_string_valid(str)) {
		return(safe_string_substring_reverse(str, 0, safe_string_length(str) - 1));
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return(SAFE_STRING_INVALID);
	}
}
