/*!
 * @file utility/filter.h
 * @brief Header file for applying filters to safe strings.
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

#ifndef _SAFE_STRING_UTILITY_FILTER_H_
#define _SAFE_STRING_UTILITY_FILTER_H_

#include "types/types.h"

/*!
 * @brief Removes all non-printable characters from the string, replacing them
 * with '?'.
 * @param str the string to filter
 * @return The filtered string.
 */
extern s_string_t safe_string_filter_printable(s_string_t);

/*!
 * @brief Removes all characters not specified by a filter function, replacing them
 * with a given character.
 * @param str the string to filter
 * @param filter the function to use as the filter (returns 1 if allowed, 0 otherwise)
 * the prototype is of the form int filter(int c)
 * @param c character to replace invalid characters
 * @return filtered string
 */
extern s_string_t safe_string_filter_generic(s_string_t, int(*)(int), const char);

#endif
