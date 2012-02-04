/*!
 * @file utility/substring_replace.c
 * @brief Replaces the contents of a substring within a string with another
 * given string.
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
#include "macro.h"

s_string_t safe_string_substring_replace_char(s_string_t str, unsigned long int start, unsigned long int end, const char *old, const char *new)
{
	return(safe_string_substring_replace_limit_char(str, start, end, old, new, 0));
}

s_string_t safe_string_substring_replace_limit_char(s_string_t str, unsigned long int start, unsigned long int end, const char *old, const char *new, unsigned long int limit)
{
	if(old && new) {
		s_string_t oldt, newt;

		oldt = safe_string_new(old);

		if(safe_string_valid(oldt)) {
			newt = safe_string_new(new);
			if(safe_string_valid(newt)) {
				s_string_t retn = safe_string_substring_replace_limit(str, start, end, oldt, newt, limit);
				safe_string_delete(oldt); safe_string_delete(newt);
				return(retn);
			} else {
				safe_string_delete(oldt);
				safe_string_set_error(SAFE_STRING_ERROR_MEM_ALLOC);
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

s_string_t safe_string_substring_replace(s_string_t str, unsigned long int start, unsigned long int end, s_string_t old, s_string_t new)
{
	return(safe_string_substring_replace_limit(str, start, end, old, new, 0));
}

s_string_t safe_string_substring_replace_limit(s_string_t str, unsigned long int start, unsigned long int end, s_string_t old, s_string_t new, unsigned long int limit)
{
	if(safe_string_valid(str) && safe_string_valid(old) && safe_string_valid(new)) {
		unsigned long int vector[2], amount;

		vector[0] = start; vector[1] = end;

		s_strings_t strs = safe_string_index_split(str, vector, 2, &amount);

		if(!safe_string_error()) {
			s_string_t temp = safe_string_replace_limit(strs[1], old, new, limit); /* since always 3 splits */

			safe_string_delete(strs[1]);
			strs[1] = temp;

			return(safe_string_join_char(strs, 3, ""));
		} else {
			return(SAFE_STRING_INVALID);
		}
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return(SAFE_STRING_INVALID);
	}
}
