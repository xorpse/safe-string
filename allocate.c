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

#include <stdlib.h> /* calloc */
#include "types/types.h"

s_string_t safe_string_new(const char *str)
{
	if(str) {
		int i = 0, j = 0;
		s_string_t rstring = (s_string_t)calloc(1, sizeof(_s_string_t));

		while(str[i++]) {
			; /* calculate the length */
		}

		rstring->s_string = (char *)calloc(i, sizeof(char));

		if(!rstring->s_string) {
			return(SAFE_STRING_INVALID);
		} else {
			rstring->s_length = i;

			for(i = j = 0; i < rstring->s_length; i++, j++) {
				rstring->s_string[i] = str[j];
			}

			return(rstring);
		}
	} else {
		return(SAFE_STRING_INVALID);
	}
}

void safe_string_delete(s_string_t str)
{
	if(str && str->s_length) {
		free(str->s_string);
		free(str);
	} else if(str && !str->s_length) {
		free(str);
	}
	str = SAFE_STRING_INVALID;
}
