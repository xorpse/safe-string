/*!
 * @file utility/locate_set.h
 * @brief Header file for finding the first occurrence of a character from
 * a given set within a specified string.
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

#ifndef _SAFE_STRING_UTILITY_LOCATE_SET_H_
#define _SAFE_STRING_UTILITY_LOCATE_SET_H_

#include "types/types.h"

/*!
 * @brief Find the first occurrence of a character from a given set within a specified string
 * @param str source string
 * @param sset set to find characters from
 * @index index location of the first occurrence of a character from the given set in the
 * source string
 * @return 1 if found, 0 otherwise.
 */
extern unsigned long int safe_string_locate_set(s_string_t, s_string_t, unsigned long int *);

/*!
 * @brief Find the first occurrence of a character from a given set within a specified string
 * @param str source string
 * @param sset set to find characters from
 * @index index location of the first occurrence of a character from the given set in the
 * source string
 * @return 1 if found, 0 otherwise.
 */
extern unsigned long int safe_string_locate_set_char(s_string_t, const char *, unsigned long int *);

#endif
