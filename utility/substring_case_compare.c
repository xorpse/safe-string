/*!
 * @file utility/substring_case_compare.c
 * @brief Comparison of a string within the source string (where case is not
 * considered)
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

#include "types/types.h"
#include "universal.h"
#include "utility.h"
#include "macro.h"

/*!
 * @brief (INTERNAL) Compares two single characters irrespective of their case
 * @param c1 character to compare
 * @param c2 character to compare
 * @return Computes the result of c1 - c2 where c1 and c2 are the same case
 * given they are from the standard ASCII alphabet
 */
static inline int _safe_string_char_case_compare(char c1, char c2)
{
	if(!((c1 == c2) || (c1 < 'A' || c1 > 'z' || c2 < 'A' || c2 > 'z'))) {
		if(c1 <= 'Z') {
			c1 += 32;
		} else {
			c1 -= 32;
		}
	}
	return(c1 - c2);
}

/*!
 * @brief Compares a substring of one string with another string using an upper
 * limit irrespective of their case
 * @param str1 source string
 * @param str2 comparison string
 * @param offset sub-string beginning offset within source string
 * @param offset of the maximum upper bound for the sub-string
 * @return Positive if str1 > str2, 0 if str1 = str2, negative if str1 < str2
 * @note Sets the error variable indicating success or failure
 */
int safe_string_substring_case_compare_limit(s_string_t str1, s_string_t str2, unsigned long int offset, unsigned long int limit)
{
	if(safe_string_valid(str1) && safe_string_valid(str2)) {
		if(safe_string_length(str1) > offset && limit >= offset) {
			int diff = 0;
			unsigned long int i = 0;
			limit = MIN(limit, MAX(safe_string_length(str1), safe_string_length(str2) + offset));

			while((offset < limit) && !diff && !safe_string_error()) {
				diff = _safe_string_char_case_compare(safe_string_index(str1, offset++), safe_string_index(str2, i++));
			}

			safe_string_set_error(safe_string_error());
			return(diff);
		} else {
			safe_string_set_error(SAFE_STRING_ERROR_INVALID_ARG);
			return(SAFE_STRING_EMPTY);
		}
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return(SAFE_STRING_EMPTY);
	}
}

/*!
 * @brief Compares a substring of one string with another string irrespective
 * of their case
 * @param str1 source string
 * @param str2 comparison string
 * @param offset sub-string beginning offset within source string
 * @return Positive if str1 > str2, 0 if str1 = str2, negative if str1 < str2
 * @note Sets the error variable indicating success or failure
 */
int safe_string_substring_case_compare(s_string_t str1, s_string_t str2, unsigned long int offset)
{
	if(safe_string_valid(str1) && safe_string_valid(str2)) {
		return(safe_string_substring_case_compare_limit(str1, str2, offset, MIN(safe_string_length(str1), safe_string_length(str2) + offset)));
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return(SAFE_STRING_EMPTY);
	}
}
