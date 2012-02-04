/*!
 * @file utility/replace.c
 * @brief Replaces an ordered set of chracters with another within a
 * specified string.
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

/*!
 * @brief Replaces all of the occurrences of a given character pattern with
 * another in a specified string.
 * @param str source string
 * @param s1 string to be replaced
 * @param s2 string to use as replacement
 * @return Original string with patterns replaced, otherwise SAFE_STRING_INVALID
 * on error.
 */
s_string_t safe_string_replace_char(s_string_t str, const char *s1, const char *s2)
{
	return(safe_string_replace_limit_char(str, s1, s2, 0));
}

/*!
 * @brief Replaces an amount of the occurrences of a given character pattern with
 * another in a specified string.
 * @param str source string
 * @param s1 string to be replaced
 * @param s2 string to use as replacement
 * @param limit the maximum amount of changes to make, if 0 then will replace all
 * found
 * @return Original string with patterns replaced, otherwise SAFE_STRING_INVALID
 * on error.
 */
s_string_t safe_string_replace_limit_char(s_string_t str, const char *s1, const char *s2, unsigned long int limit)
{
	if(s1 && s2) {
		s_string_t s1t, s2t;

		s1t = safe_string_new(s1);

		if(safe_string_valid(s1t)) {
			s2t = safe_string_new(s2);
			if(safe_string_valid(s2t)) {
				s_string_t retn = safe_string_replace_limit(str, s1t, s2t, limit);
				safe_string_delete(s1t); safe_string_delete(s2t);
				return(retn);
			} else {
				safe_string_delete(s1t);
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

/*!
 * @brief Replaces all of the occurrences of a given character pattern with
 * another in a specified string.
 * @param str source string
 * @param s1 string to be replaced
 * @param s2 string to use as replacement
 * @return Original string with patterns replaced, otherwise SAFE_STRING_INVALID
 * on error.
 */
s_string_t safe_string_replace(s_string_t str, s_string_t s1, s_string_t s2)
{
	return(safe_string_replace_limit(str, s1, s2, 0));
}

/*!
 * @brief Replaces an amount of the occurrences of a given character pattern with
 * another in a specified string.
 * @param str source string
 * @param s1 string to be replaced
 * @param s2 string to use as replacement
 * @param limit the maximum amount of changes to make, if 0 then will replace all
 * found
 * @return Original string with patterns replaced, otherwise SAFE_STRING_INVALID
 * on error.
 */
s_string_t safe_string_replace_limit(s_string_t str, s_string_t s1, s_string_t s2, unsigned long int limit)
{
	unsigned long int count = 0;
	s_strings_t strs = safe_string_split_limit(str, s1, limit, &count);

	if(!safe_string_error()) {
		if(count == 1) {
			return(strs[0]);
		} else {
			s_string_t retn = safe_string_join(strs, count, s2);
			safe_string_array_delete(strs, count);

			return(!safe_string_error() ? retn : SAFE_STRING_INVALID);
		}
	} else {
		return(SAFE_STRING_INVALID);
	}
}
