/*!
 * @file utility/join.c
 * @brief Joins a collection of strings with an optional delimeter between
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
#include "universal.h"
#include "utility.h"
#include "macro.h"

s_string_t safe_string_join_limit(s_strings_t strs, unsigned long int count, s_string_t delim, unsigned long int limit)
{
	if(safe_strings_valid(strs, count) && safe_string_valid(delim)) {
		if(count && limit) {
			unsigned int i = 0;
			s_string_t retn = safe_string_new("");

			limit = MIN(limit, count);

			if(!safe_string_error()) {
				for(i = 0; i < limit - 1; i++) {
					safe_string_concatenate(retn, strs[i]);
					safe_string_concatenate(retn, delim);
				}

				safe_string_concatenate(retn, strs[i]);

				safe_string_set_error(SAFE_STRING_ERROR_NO_ERROR);
				return(retn);
			} else {
				if(safe_string_valid(retn)) {
					safe_string_delete(retn);
				}
				return(SAFE_STRING_INVALID);
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


s_string_t safe_string_join(s_strings_t strs, unsigned long int count, s_string_t delim)
{
	return(safe_string_join_limit(strs, count, delim, count));
}

s_string_t safe_string_join_limit_char(s_strings_t strs, unsigned long int count, const char *delim, unsigned long int limit)
{
	s_string_t temp = safe_string_new(delim);
	s_string_t retn = safe_string_join_limit(strs, count, temp, limit);
	s_string_error_t error = safe_string_error_val();
	safe_string_delete(temp);
	safe_string_set_error(error);
	return(retn);
}

s_string_t safe_string_join_char(s_strings_t strs, unsigned long int count, const char *delim)
{
	return(safe_string_join_limit_char(strs, count, delim, count));
}
