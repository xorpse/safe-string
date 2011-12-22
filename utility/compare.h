/*!
 * @file utility/compare.h
 * @brief Header file for basic comparison functions
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

#ifndef _SAFE_STRING_UTILITY_COMPARE_H_
#define _SAFE_STRING_UTILITY_COMPARE_H_

#include "types/types.h"

/*!
 * @brief Compares two strings with a limit
 * @param str1 string to compare
 * @param str2 string to compare
 * @param limit maximum amount of characters to compare from str1
 * @return The difference between either where two indexed characters from str1
 * and str2 aren't equal; or where the index has reached the limit value or the
 * end of str1; the difference is computed as follows: str1[i] - str2[i] or 0 in
 * the case of no differences
 * @note Sets the error variable indicating success or failure
 */
extern int safe_string_compare_limit(s_string_t, s_string_t, unsigned long int);

/*!
 * @brief Compares two strings
 * @param str1 string to compare
 * @param str2 string to compare
 * @return The difference between either where two indexed characters from str1
 * and str2 aren't equal; or where the index has reached the end of str1; the
 * difference is computed as follows: str1[i] - str2[i] or 0 in the case of no
 * differences
 * @note Sets the error variable indicating success or failure
 */
extern int safe_string_compare(s_string_t, s_string_t);

#endif
