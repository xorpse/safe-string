/*!
 * @file utility/pad.c
 * @brief Pads the given string with a given amount of characters
 * from a specified set.
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
 * @brief Pads the right-hand-side of the string with a given amount of
 * characters from a specified set.
 * @param str source string
 * @param pstr string containing set of characters to use as padding
 * @param length length of the new string
 */
s_string_t safe_string_lpad_char(s_string_t str, const char *pstr, unsigned long int length)
{
	s_string_t temp = safe_string_new(pstr), retn;
	retn = safe_string_lpad(str, temp, length);
	safe_string_delete(temp);
	return(retn);
}

/*!
 * @brief Pads the left-hand-side of the string with a given amount of
 * characters from a specified set.
 * @param str source string
 * @param pstr string containing set of characters to use as padding
 * @param length length of the new string
 */
s_string_t safe_string_rpad_char(s_string_t str, const char *pstr, unsigned long int length)
{
	s_string_t temp = safe_string_new(pstr), retn;
	retn = safe_string_rpad(str, temp, length);
	safe_string_delete(temp);
	return(retn);
}

/*!
 * @brief Pads the left-hand-side of the string with a given amount of
 * characters from a specified set.
 * @param str source string
 * @param pstr string containing set of characters to use as padding
 * @param length length of the new string
 */
s_string_t safe_string_lpad(s_string_t str, s_string_t pstr, unsigned long int length)
{
	if(safe_string_valid(str) && safe_string_valid(pstr)) {
		if(length > safe_string_length(str) && safe_string_length(pstr)) {
			unsigned long int i = 0, plength = safe_string_length(pstr);
			
			length -= safe_string_length(str);

			for(i = 0; i < length; i+= plength) {
				safe_string_concatenate_limit(str, pstr, (length - i < plength) ? length - i : plength);
			}

			safe_string_set_error(SAFE_STRING_ERROR_NO_ERROR);
			return(str);
		} else {
			safe_string_set_error(SAFE_STRING_ERROR_INVALID_ARG);
			return(str); /* not exactly an error, however report it anyway */
		}
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return(SAFE_STRING_INVALID);
	}
}

/*!
 * @brief Pads the right-hand-side of the string with a given amount of
 * characters from a specified set.
 * @param str source string
 * @param pstr string containing set of characters to use as padding
 * @param length length of the new string
 */
s_string_t safe_string_rpad(s_string_t str, s_string_t pstr, unsigned long int length)
{
	if(safe_string_valid(str) && safe_string_valid(pstr)) {
		if(length > safe_string_length(str) && safe_string_length(pstr)) {
			unsigned long int i = 0, plength = safe_string_length(pstr);
			s_string_t temp = safe_string_new("");

			if(!safe_string_error()) {

				length -= safe_string_length(str);

				for(i = 0; i < length; i+= plength) {
					safe_string_concatenate_limit(temp, pstr, (length - i < plength) ? length - i : plength);
				}

				safe_string_concatenate(temp, str);
				safe_string_delete(str);

				safe_string_set_error(SAFE_STRING_ERROR_NO_ERROR);
				return(temp);
			} else {
				return(SAFE_STRING_INVALID);
			}
		} else {
			safe_string_set_error(SAFE_STRING_ERROR_INVALID_ARG);
			return(str); /* not exactly an error, however report it anyway */
		}
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return(SAFE_STRING_INVALID);
	}
}
