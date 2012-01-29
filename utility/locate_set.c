/*!
 * @file utility/locate_set.c
 * @brief Locates the index of the first character specified in a given set
 * of characters.
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
 * @brief Internal function to check if specific character is in a given set
 * @param c character to test for
 * @param set set to test if character is in
 * @return 1 if character is in set, 0 otherwise
 */
static inline int _char_in_set(char c, s_string_t set)
{
	if(safe_string_valid(set)) {
		unsigned long int i = 0;

		for(i = 0; i < safe_string_length(set); i++) {
			if(c == safe_string_index(set, i)) {
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
 * @brief Find the first occurrence of a character from a given set within a specified string
 * @param str source string
 * @param sset set to find characters from
 * @index index location of the first occurrence of a character from the given set in the
 * source string
 * @return 1 if found, 0 otherwise.
 */
unsigned long int safe_string_locate_set(s_string_t str, s_string_t sset, unsigned long int *index)
{
	if(safe_string_valid(str) && safe_string_valid(sset) && index) {
		unsigned int i = 0;

		for(i = 0; i < safe_string_length(str); i++) {
			if(_char_in_set(safe_string_index(str, i), sset)) {
				*index = i;
				return(1);
			}
		}

		return(0); // index is undefined if not found
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return(SAFE_STRING_EMPTY);
	}
}

/*!
 * @brief Find the first occurrence of a character from a given set within a specified string
 * @param str source string
 * @param sset set to find characters from
 * @index index location of the first occurrence of a character from the given set in the
 * source string
 * @return 1 if found, 0 otherwise.
 */
unsigned long int safe_string_locate_set_char(s_string_t str, const char *sset, unsigned long int *index)
{
	s_string_t temp = safe_string_new(sset);
	unsigned long int retn = safe_string_locate_set(str, temp, index);
	safe_string_delete(temp);
	return(retn);
}
