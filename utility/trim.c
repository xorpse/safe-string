/*!
 * @file utility/trim.c
 * @brief Trims characters from the beginning and end of strings.
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

/*!
 * @brief Internal function to check if specific character is in a given set
 * @param c character to test for
 * @param set set to test if character is in
 * @return 1 if character is in set, 0 otherwise
 */
static inline int _char_in_set(char c, const char *set)
{
	if(set) {
		unsigned long int i = 0, length = 0;

		while(*(set + length)) {
			length++;
		}

		safe_string_set_error(SAFE_STRING_ERROR_NO_ERROR);

		for(i = 0; i < length; i++) {
			if(c == set[i]) {
				return(1);
			}
		}
		
		return(0);
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return(0);
	}
}

/*!
 * @brief Removes at most a given amount of characters specified by a given set
 * from the left (beginning) of a given string.
 * @param str source string
 * @param set set of characters to be removed
 * @param limit maximum number of characters to be removed (if 0 then there is no
 * limit)
 * @return The trimmed string.
 */
s_string_t safe_string_ltrim_set_limit(s_string_t str, const char *set, unsigned long int limit)
{
	if(safe_string_valid(str) && set) {
		unsigned long int i = 0;
		s_string_t retn;

		limit = MIN(limit, safe_string_length(str));
		
		while(i < limit || !limit) {
			if(!_char_in_set(safe_string_index(str, i), set)) {
				break;
			}
			i++;
		}

		retn = safe_string_substring(str, i, safe_string_length(str));

		if(safe_string_error()) {
			return(SAFE_STRING_INVALID);
		} else {
			safe_string_delete(str);
			return(retn);
		}
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return(SAFE_STRING_INVALID);
	}
}

/*!
 * @brief Removes at most a given amount of characters specified by a given set
 * from the right (ending) of a given string.
 * @param str source string
 * @param set set of characters to be removed
 * @param limit maximum number of characters to be removed (if 0 then there is no
 * limit)
 * @return The trimmed string.
 */
s_string_t safe_string_rtrim_set_limit(s_string_t str, const char *set, unsigned long int limit)
{
	if(safe_string_valid(str) && set) {
		unsigned long int i = 0, length = safe_string_length(str);
		s_string_t retn;

		limit = MIN(limit, length);
		
		while(i < limit || !limit) {
			if(!_char_in_set(safe_string_index(str, (length - i) - 1), set)) {
				break;
			}
			i++;
		}

		retn = safe_string_substring(str, 0, length - i);

		if(safe_string_error()) {
			return(SAFE_STRING_INVALID);
		} else {
			safe_string_delete(str);
			return(retn);
		}
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return(SAFE_STRING_INVALID);
	}
}

/*!
 * @brief Removes at most a given amount of characters specified by a given set
 * from the right and left (start and ending) of a given string.
 * @param str source string
 * @param set set of characters to be removed
 * @param limit maximum number of characters to be removed (if 0 then there is no
 * limit)
 * @return The trimmed string.
 */
s_string_t safe_string_trim_set_limit(s_string_t str, const char *set, unsigned long int limit)
{
	if(safe_string_valid(str) && set) {
		unsigned long int i = 0, j = 0, length = safe_string_length(str);
		s_string_t retn;

		limit = MIN(limit, length);

		while(i < limit || !limit) {
			if(!_char_in_set(safe_string_index(str, i), set)) {
				break;
			}
			i++;
		}
		
		while(j < limit || !limit) {
			if(!_char_in_set(safe_string_index(str, (length - j) - 1), set)) {
				break;
			}
			j++;
		}

		retn = safe_string_substring(str, i, length - j);

		if(safe_string_error()) {
			return(SAFE_STRING_INVALID);
		} else {
			safe_string_delete(str);
			return(retn);
		}
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return(SAFE_STRING_INVALID);
	}
}

/*!
 * @brief Removes at most a given amount of white space characters from  the left
 * (start) of a given string.
 * @param str source string
 * @param limit maximum number of characters to be removed (if 0 then there is no
 * limit)
 * @return The trimmed string.
 */
s_string_t safe_string_ltrim_limit(s_string_t str, unsigned long int limit)
{
	return(safe_string_ltrim_set_limit(str, " \t\n\r\v", limit));
}

/*!
 * @brief Removes at most a given amount of characters specified by a given set
 * from the right (ending) of a given string.
 * @param str source string
 * @param set set of characters to be removed
 * @param limit maximum number of characters to be removed (if 0 then there is no
 * limit)
 * @return The trimmed string.
 */
s_string_t safe_string_rtrim_limit(s_string_t str, unsigned long int limit)
{
	return(safe_string_rtrim_set_limit(str, " \t\n\r\v", limit));
}

/*!
 * @brief Removes at most a given amount of characters specified by a given set
 * from the right and left (start and ending) of a given string.
 * @param str source string
 * @param set set of characters to be removed
 * @param limit maximum number of characters to be removed (if 0 then there is no
 * limit)
 * @return The trimmed string.
 */
s_string_t safe_string_trim_limit(s_string_t str, unsigned long int limit)
{
	return(safe_string_trim_set_limit(str, " \t\n\r\v", limit));
}

/*!
 * @brief Removes all of the characters specified by a given set from the left
 * (start) of a given string.
 * @param str source string
 * @param set set of characters to be removed
 * @return The trimmed string.
 */
s_string_t safe_string_ltrim_set(s_string_t str, const char *set)
{
	return(safe_string_ltrim_set_limit(str, set, 0));
}

/*!
 * @brief Removes all of the characters specified by a given set from the right
 * (ending) of a given string.
 * @param str source string
 * @param set set of characters to be removed
 * @return The trimmed string.
 */
s_string_t safe_string_rtrim_set(s_string_t str, const char *set)
{
	return(safe_string_rtrim_set_limit(str, set, 0));
}

/*!
 * @brief Removes all of the characters specified by a given set from the left and
 * right (start and ending) of a given string.
 * @param str source string
 * @param set set of characters to be removed
 * @return The trimmed string.
 */
s_string_t safe_string_trim_set(s_string_t str, const char *set)
{
	return(safe_string_trim_set_limit(str, set, 0));
}

/*!
 * @brief Removes all white space characters from the left (start) of a given
 * string.
 * @param str source string
 * @return The trimmed string.
 */
s_string_t safe_string_ltrim(s_string_t str)
{
	return(safe_string_ltrim_set_limit(str, " \t\n\r\v", 0));
}

/*!
 * @brief Removes all white space characters from the right (ending) of a given
 * string.
 * @param str source string
 * @return The trimmed string.
 */
s_string_t safe_string_rtrim(s_string_t str)
{
	return(safe_string_rtrim_set_limit(str, " \t\n\r\v", 0));
}

/*!
 * @brief Removes all white space characters from the left and right (start and
 * ending) of a given string.
 * @param str source string
 * @return The trimmed string.
 */
s_string_t safe_string_trim(s_string_t str)
{
	return(safe_string_trim_set_limit(str, " \t\n\r\v", 0));
}
