/*!
 * @file utility/trim.h
 * @brief Header file for trimming strings.
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

/*!
 * @brief Removes at most a given amount of characters specified by a given set
 * from the left (beginning) of a given string.
 * @param str source string
 * @param set set of characters to be removed
 * @param limit maximum number of characters to be removed (if 0 then there is no
 * limit)
 * @return The trimmed string.
 */
extern s_string_t safe_string_ltrim_set_limit(s_string_t str, const char *set, unsigned long int limit);

/*!
 * @brief Removes at most a given amount of characters specified by a given set
 * from the right (ending) of a given string.
 * @param str source string
 * @param set set of characters to be removed
 * @param limit maximum number of characters to be removed (if 0 then there is no
 * limit)
 * @return The trimmed string.
 */
extern s_string_t safe_string_rtrim_set_limit(s_string_t str, const char *set, unsigned long int limit);

/*!
 * @brief Removes at most a given amount of characters specified by a given set
 * from the right and left (start and ending) of a given string.
 * @param str source string
 * @param set set of characters to be removed
 * @param limit maximum number of characters to be removed (if 0 then there is no
 * limit)
 * @return The trimmed string.
 */
extern s_string_t safe_string_trim_set_limit(s_string_t str, const char *set, unsigned long int limit);
