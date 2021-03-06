/*!
 * @file utility/substring_replace.h
 * @brief Header file for function to replace the contents of a substring
 * within a string with another given string.
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

#ifndef _SAFE_STRING_UTILITY_SUBSTRING_REPLACE_H_
#define _SAFE_STRING_UTILITY_SUBSTRING_REPLACE_H_

#include "types/types.h"

/*!
 * @brief Replaces strings within a substring of a given string.
 * @param str source string
 * @param start first index of substring
 * @param end last index of substring
 * @param old string to be replaced
 * @param new string to replace
 */
extern s_string_t safe_string_substring_replace_char(s_string_t, unsigned long int, unsigned long int, const char *, const char *);

/*!
 * @brief Replaces strings within a substring of a given string.
 * @param str source string
 * @param start first index of substring
 * @param end last index of substring
 * @param old string to be replaced
 * @param new string to replace
 * @param limit maximum amount of replacements to be made (0 for unlimited)
 */
extern s_string_t safe_string_substring_replace_limit_char(s_string_t, unsigned long int, unsigned long int, const char *, const char *, unsigned long int);

/*!
 * @brief Replaces strings within a substring of a given string.
 * @param str source string
 * @param start first index of substring
 * @param end last index of substring
 * @param old string to be replaced
 * @param new string to replace
 */
extern s_string_t safe_string_substring_replace(s_string_t, unsigned long int, unsigned long int, s_string_t, s_string_t);

/*!
 * @brief Replaces strings within a substring of a given string.
 * @param str source string
 * @param start first index of substring
 * @param end last index of substring
 * @param old string to be replaced
 * @param new string to replace
 * @param limit maximum amount of replacements to be made (0 for unlimited)
 */
extern s_string_t safe_string_substring_replace_limit(s_string_t, unsigned long int, unsigned long int, s_string_t, s_string_t, unsigned long int);

#endif
