/*!
 * @file utility/index.c
 * @brief Indexing functions (getting and setting string elements)
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
 * @brief Obtains the element at a given string index
 * @param str source string
 * @param index element index to access
 * @return If the index is valid the element is returned, otherwise
 * a NULL value is returned
 * @note Sets the error variable indicating success or failure
 */
unsigned char safe_string_index(const s_string_t str, unsigned long int index)
{
	if(safe_string_valid(str)) {
		if(index < 0 || index > safe_string_length(str)) {
			safe_string_set_error(SAFE_STRING_ERROR_INDEX_BOUNDS);
			return('\0');
		} else {
			safe_string_set_error(SAFE_STRING_ERROR_NO_ERROR);
			return(str->s_string[index]);
		}
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return('\0');
	}
}

/*!
 * @brief Sets the element at a given string index
 * @param str destination string
 * @param index element index to set
 * @param c value to assign the element
 * @note Sets the error variable indicating success or failure
 */
void safe_string_index_set(s_string_t str, unsigned long int index, const char c)
{
	if(safe_string_valid(str)) {
		if(index < 0 || index > safe_string_length(str)) {
			safe_string_set_error(SAFE_STRING_ERROR_INDEX_BOUNDS);
			return;
		} else {
			str->s_string[index] = c;
			safe_string_set_error(SAFE_STRING_ERROR_NO_ERROR);
			return;
		}
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return;
	}
}
