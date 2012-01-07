/*!
 * @file utility/string_locate.c
 * @brief Returns the offset of a string within another string
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
 * @brief Finds the offset of a substring of a given string between a lower
 * and upper bound.
 * @param haystack source string
 * @param needle string to find
 * @param offset starting offset to search from
 * @param limit ending offset to search to
 * @return The index of the first letter of the first occurance of the string
 * to be found within the source string. If the string is not found then
 * the error value is set to SAFE_STRING_INVALID_RETURN and 0 is returned.
 * @note The error value is set indicating success or failure.
 */
unsigned long int safe_string_string_locate_offset_limit(s_string_t haystack, s_string_t needle, unsigned long int offset, unsigned long int limit)
{
	if(safe_string_valid(haystack) && safe_string_valid(needle)) {
		if(offset < safe_string_length(haystack) && limit <= safe_string_length(haystack) && offset <= limit) {
			unsigned long int search_limit = limit - safe_string_length(needle);

			if(search_limit < limit) { /* only fails if length of needle was greater than limit or the string is nothing */
				while(offset < limit) {
					if(!safe_string_substring_compare(haystack, needle, offset)) {
						safe_string_set_error(SAFE_STRING_ERROR_NO_ERROR);
						return(offset);
					}
					offset++;
				}
				
				safe_string_set_error(SAFE_STRING_ERROR_INVALID_RETURN);
				return(SAFE_STRING_EMPTY);
			} else {
				safe_string_set_error(SAFE_STRING_ERROR_INVALID_ARG);
				return(SAFE_STRING_EMPTY);
			}
		} else {
			safe_string_set_error(SAFE_STRING_ERROR_INVALID_ARG);
			return(SAFE_STRING_EMPTY);
		}
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NO_ERROR);
		return(SAFE_STRING_EMPTY);
	}
}

/*!
 * @brief Finds the offset of a substring of a given string using an upper bound.
 * @param haystack source string
 * @param needle string to find
 * @param limit ending offset to search to
 * @return The index of the first letter of the first occurance of the string
 * to be found within the source string. If the string is not found then
 * the error value is set to SAFE_STRING_INVALID_RETURN and 0 is returned.
 * @note The error value is set indicating success or failure.
 */
unsigned long int safe_string_string_locate_limit(s_string_t haystack, s_string_t needle, unsigned long int limit)
{
	return(safe_string_string_locate_offset_limit(haystack, needle, 0, limit));
}

/*!
 * @brief Finds the offset of a substring of a given string using a lower bound.
 * @param haystack source string
 * @param needle string to find
 * @param offset starting offset to search from
 * @return The index of the first letter of the first occurance of the string
 * to be found within the source string. If the string is not found then
 * the error value is set to SAFE_STRING_INVALID_RETURN and 0 is returned.
 * @note The error value is set indicating success or failure.
 */
unsigned long int safe_string_string_locate_offset(s_string_t haystack, s_string_t needle, unsigned long int offset)
{
	if(safe_string_valid(haystack)) {
		return(safe_string_string_locate_offset_limit(haystack, needle, offset, safe_string_length(haystack)));
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return(SAFE_STRING_EMPTY);
	}
}

/*!
 * @brief Finds the offset of a substring of a given string.
 * @param haystack source string
 * @param needle string to find
 * @return The index of the first letter of the first occurance of the string
 * to be found within the source string. If the string is not found then
 * the error value is set to SAFE_STRING_INVALID_RETURN and 0 is returned.
 * @note The error value is set indicating success or failure.
 */
unsigned long int safe_string_string_locate(s_string_t haystack, s_string_t needle)
{
	return(safe_string_string_locate_offset(haystack, needle, 0));
}
