/*!
 * @file utility/case_compare.c
 * @brief Comparison functions irrespective of the case (assumes ASCII
 * character set)
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
#include "universal/error.h"
#include "utility/index.h"
#include "utility/length.h"

/*!
 * @brief (INTERNAL) Compares two single characters irrespective of their case
 * @param c1 character to compare
 * @param c2 character to compare
 * @return Computes the result of c1 - c2 where c1 and c2 are the same case
 * given they are from the standard ASCII alphabet
 */
int _safe_string_char_case_compare(char c1, char c2)
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
 * @brief Compares two strings irrespective of their case with a limit
 * @param str1 string to compare
 * @param str2 string to compare
 * @param limit maximum amount of characters to compare
 * @return Computes the result of where a character indexed by str1 differs
 * from that in str2 from at most the first 'limit' characters in str1; the
 * difference is calculated from str1[i] - str2[i], where if the elements are
 * from the alphabet then they are compared using the same case 
 * @note Sets the error variable indicating success or failure
 */
int safe_string_case_compare_limit(s_string_t str1, s_string_t str2, unsigned long int limit)
{
	if((str1 && str1->s_string) && (str2 && str2->s_string)) {
		if(limit >= 0) {
			unsigned long int i = 0, diff = 0;

			limit = (limit > (str1->s_length > str2->s_length ? str1->s_length : str2->s_length) ? (str1->s_length > str2->s_length ? str1->s_length : str2->s_length) : limit);
			while((i < limit) && !diff) {
				diff = _safe_string_char_case_compare(safe_string_index(str1, i), safe_string_index(str2, i));
				i++;
			}

			safe_string_set_error(SAFE_STRING_ERROR_NO_ERROR);
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
 * @brief Compares two strings irrespective of their case
 * @param str1 string to compare
 * @param str2 string to compare
 * @return Computes the result of where a character indexed by str1 differs
 * from that in str2, using all of the characters from str1; the difference
 * is calculated from str1[i] - str2[i], where if the elements are from the
 * alphabet then they are compared using the same case
 * @note Sets the error variable indicating success or failure
 */
int safe_string_case_compare(s_string_t str1, s_string_t str2)
{
	if((str1 && str1->s_string) && (str2 && str2->s_string)) { /* check it's safe to access the structure */
		return(safe_string_case_compare_limit(str1, str2, (safe_string_length(str1) < safe_string_length(str2)) ? safe_string_length(str1) : safe_string_length(str2)));
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return(SAFE_STRING_EMPTY);
	}
}
