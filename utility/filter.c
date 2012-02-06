/*!
 * @file utility/filter.c
 * @brief Filters the characters in a string based upon certain conditions.
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

#include <ctype.h>
#include "types/types.h"
#include "utility.h"
#include "universal.h"
#include "macro.h"

/*!
 * @brief Removes all non-printable characters from the string, replacing them
 * with '?'.
 * @param str the string to filter
 * @return The filtered string.
 */
s_string_t safe_string_filter_printable(s_string_t str)
{
	return(safe_string_filter_generic(str, isprint, '?'));
}

/*!
 * @brief Removes all characters not specified by a filter function, replacing them
 * with a given character.
 * @param str the string to filter
 * @param filter the function to use as the filter (returns 1 if allowed, 0 otherwise)
 * the prototype is of the form int filter(int c)
 * @param c character to replace invalid characters
 * @return filtered string
 */
s_string_t safe_string_filter_generic(s_string_t str, int(*filter)(int), const char c)
{
	if(safe_string_valid(str)) {
		unsigned long int i = 0;

		for(i = 0; i < safe_string_length(str); i++) {
			safe_string_index_set(str, i, (*filter)(safe_string_index(str, i)) ? safe_string_index(str, i) : c);
		}

		return(str);
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return(SAFE_STRING_INVALID);
	}
}
