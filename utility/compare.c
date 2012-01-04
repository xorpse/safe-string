/*!
 * @file utility/compare.c
 * @brief Comparison functions
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
 * @brief Compares two strings with a limit
 * @param str1 string to compare
 * @param str2 string to compare
 * @param limit maximum amount of characters to compare from str1
 * @return The difference between either where two indexed characters from str1
 * and str2 aren't equal; or where the index has reached the limit value or the
 * end of str1; the difference is computed as follows: str1[i] - str2[i] or 0 in
 * the case of no differences
 * @note Sets the error variable indicating success or failure
 */
int safe_string_compare_limit(s_string_t str1, s_string_t str2, unsigned long int limit)
{
	if(safe_string_valid(str1) && safe_string_valid(str2)) {
		int diff = 0;
		unsigned long int i = 0;

		//limit = (limit > (str1->s_length > str2->s_length ? str1->s_length : str2->s_length) ? (str1->s_length > str2->s_length ? str1->s_length : str2->s_length) : limit);
		limit = MIN(limit, MAX(safe_string_length(str1), safe_string_length(str2)));
		while((i < limit) && !diff && !safe_string_error()) {
			diff = (safe_string_index(str1, i) - safe_string_index(str2, i));
			i++;
		}

		safe_string_set_error(safe_string_error_val());
		return(diff);
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return(SAFE_STRING_EMPTY);
	}
}

/*!
 * @brief Compares two strings
 * @param str1 string to compare
 * @param str2 string to compare
 * @return The difference between either where two indexed characters from str1
 * and str2 aren't equal; or where the index has reached the end of str1; the
 * difference is computed as follows: str1[i] - str2[i] or 0 in the case of no
 * differences
 * @note Sets the error variable indicating success or failure
 */
int safe_string_compare(s_string_t str1, s_string_t str2)
{
	if(safe_string_valid(str1) && safe_string_valid(str2)) { /* check it's safe to access the structure */
		return(safe_string_compare_limit(str1, str2, MIN(safe_string_length(str1), safe_string_length(str2))));
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return(SAFE_STRING_EMPTY);
	}
}
