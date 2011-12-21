/* Copyright (c) 2011 Sam Thomas <s@ghost.sh>
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

#include <stdlib.h>
#include "types/types.h"
#include "universal/error.h"
#include "utility/index.h"
#include "utility/length.h"

void safe_string_copy_limit(s_string_t str1, s_string_t str2, unsigned long int length)
{
	if(str1 && str1->s_string && str2 && str2->s_string) {
		unsigned long int i = 0;
		length = (length > safe_string_length(str2) ? safe_string_length(str2) : length);
		
		if(safe_string_length(str1) != length) {
			char *new_string;
			new_string = (char *)realloc(str1->s_string, (length + 1) * sizeof(char));
			
			if(!new_string) {
				safe_string_set_error(SAFE_STRING_ERROR_MEM_ALLOC);
				return;
			} else {
				str1->s_string = new_string;
			}
		}

		for(i = 0; i < length; i++) {
			safe_string_index_set(str1, i, safe_string_index(str2, i));
		}

		safe_string_index_set(str1, i, '\0');
		
		str1->s_length = length + 1;

		safe_string_set_error(SAFE_STRING_ERROR_NO_ERROR);
		return;
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return;
	}
}

void safe_string_copy(s_string_t str1, s_string_t str2)
{
	if(str1 && str1->s_string && str2 && str2->s_string) {
		safe_string_copy_limit(str1, str2, safe_string_length(str2));
		return;
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return;
	}
}

