/* Copyright (c) 2011 Sam Thomas <s@ghost.sh>
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

int safe_string_case_compare(s_string_t str1, s_string_t str2)
{
	if((str1 && str1->s_string) && (str2 && str2->s_string)) { /* check it's safe to access the structure */
		return(safe_string_case_compare_limit(str1, str2, (safe_string_length(str1) < safe_string_length(str2)) ? safe_string_length(str1) : safe_string_length(str2)));
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return(SAFE_STRING_EMPTY);
	}
}
