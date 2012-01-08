/*!
 * @file utility/access.c
 * @brief Provides an interface for accessing the data stored within a
 * safe string.
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

const char *safe_string_access_characters(s_string_t str, unsigned long int *count)
{
	if(safe_string_valid(str)) {
		safe_string_set_error(SAFE_STRING_ERROR_NO_ERROR);
		*count = safe_string_length(str);
		return(str->s_string);
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		*count = SAFE_STRING_EMPTY;
		return(SAFE_STRING_INVALID);
	}
}

char *safe_string_access_characters_duplicate(s_string_t str, unsigned long int *count)
{
	if(safe_string_valid(str)) {
		char *retn = (char *)calloc(str->s_length, sizeof(char));

		if(retn) {
			unsigned long int i = 0;

			for(i = 0; i < safe_string_length(str); i++) {
				retn[i] = safe_string_index(str, i);
			}

			if(!safe_string_error()) {
				safe_string_set_error(SAFE_STRING_ERROR_NO_ERROR);
				return(retn);
			} else {
				free(retn); /* carry the error value */
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
