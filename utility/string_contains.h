/*!
 * @file utility/string_contains.h
 * @brief Checks if a string is contained within another string
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

#ifndef _SAFE_STRING_UTILITY_STRING_CONTAINS_H_
#define _SAFE_STRING_UTILITY_STRING_CONTAINS_H_

#include "types/types.h"
#include "utility.h"

/*!
 * @brief Checks to see if the substring defined by given limits contains a given
 * string.
 * @param haystack source string
 * @param needle string to search for
 * @param offset index to start the search
 * @param limit index to stop the search
 * @return Zero if not found, non-zero otherwise.
 * @note Sets error value indicating success or failure.
 */
#define safe_string_string_contains_offset_limit(haystack, needle, offset, limit) (safe_string_string_locate_offset_limit(haystack, needle, offset, limit) || !safe_string_error())

/*!
 * @brief Checks to see if the substring defined by a given upper limit contains a given
 * string.
 * @param haystack source string
 * @param needle string to search for
 * @param limit index to stop the search
 * @return Zero if not found, non-zero otherwise.
 * @note Sets error value indicating success or failure.
 */
#define safe_string_string_contains_limit(haystack, needle, limit) (safe_string_string_locate_limit(haystack, needle, limit) || !safe_string_error())

/*!
 * @brief Checks to see if the substring defined by a given lower limit contains a given
 * string.
 * @param haystack source string
 * @param needle string to search for
 * @param offset index to start the search
 * @return Zero if not found, non-zero otherwise.
 * @note Sets error value indicating success or failure.
 */
#define safe_string_string_contains_offset(haystack, needle, offset) (safe_string_string_locate_offset(haystack, needle, offset) || !safe_string_error())

/*!
 * @brief Checks to see if a string contains another given string.
 * @param haystack source string
 * @param needle string to search for
 * @return Zero if not found, non-zero otherwise.
 * @note Sets error value indicating success or failure.
 */
#define safe_string_string_contains(haystack, needle) (safe_string_string_locate(haystack, needle) || !safe_string_error())

#endif
