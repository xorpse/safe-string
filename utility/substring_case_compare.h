/*!
 * @file utility/substring_case_compare.c
 * @brief Header file for comparison of substrings (where case is not considered)
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

#ifndef _SAFE_STRING_UTILITY_SUBSTRING_CASE_COMPARE_H_
#define _SAFE_STRING_UTILITY_SUBSTRING_CASE_COMPARE_H_

#include "types/types.h"

/*!
 * @brief Compares a substring of one string with another string using an upper
 * limit irrespective of their case
 * @param str1 source string
 * @param str2 comparison string
 * @param offset sub-string beginning offset within source string
 * @param offset of the maximum upper bound for the sub-string
 * @return Positive if str1 > str2, 0 if str1 = str2, negative if str1 < str2
 * @note Sets the error variable indicating success or failure
 */
extern int safe_string_substring_case_compare_limit(s_string_t str1, s_string_t str2, unsigned long int offset, unsigned long int limit);

/*!
 * @brief Compares a substring of one string with another string irrespective
 * of their case
 * @param str1 source string
 * @param str2 comparison string
 * @param offset sub-string beginning offset within source string
 * @return Positive if str1 > str2, 0 if str1 = str2, negative if str1 < str2
 * @note Sets the error variable indicating success or failure
 */
extern int safe_string_substring_case_compare(s_string_t str1, s_string_t str2, unsigned long int offset);

#endif
