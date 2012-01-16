/*!
 * @file utility/split.h
 * @brief Header file for string splitter (similar to PHP's split
 * function)
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
 * @brief Splits a string based upon a delimeter into at most 'elements' strings
 * @param str source string to split
 * @param delim delimeter to split on
 * @param elements the amount of times (at most) to split (can be 0, if this is the case we treat elements as infinite)
 * @param count the amount of strings to be returned
 * @return Strings containing the split substrings of the source string, some elements may be NULL where the delimeter has
 * repeated, or where there was no string before or after. (Should be checked by caller).
 * @note Error value is set to indicate success or failure.
 */
extern s_strings_t safe_string_split(s_string_t, s_string_t, unsigned long int *);

/*!
 * @brief Splits the string using a C string delimeter
 * @param str source string
 * @param delim C string delimeter to split on
 * @param element the amount of splits to perform
 * @param count stores the amount of strings created from splitting
 * @return Strings containing the split substrings of the source string, some elements may be NULL where the delimeter has
 * repeated, or where there was no string before or after. (Should be checked by caller).
 * @note Error value is set to indicate success or failure.
 */
extern s_strings_t safe_string_split_limit(s_string_t, s_string_t, unsigned long int, unsigned long int *);

/*!
 * @brief Splits the string using a C string delimeter with no limit to amount of splits
 * @param str source string
 * @param delim C string delimeter to split on
 * @param count stores the amount of strings created from splitting
 * @return Strings containing the split substrings of the source string, some elements may be NULL where the delimeter has
 * repeated, or where there was no string before or after. (Should be checked by caller).
 * @note Error value is set to indicate success or failure.
 */
extern s_strings_t safe_string_split_char(s_string_t, const char *, unsigned long int *);

/*!
 * @brief Splits the string using a delimeter with no limit on amount of splits
 * @param str source string
 * @param delim C string delimeter to split on
 * @param count stores the amount of strings created from splitting
 * @return Strings containing the split substrings of the source string, some elements may be NULL where the delimeter has
 * repeated, or where there was no string before or after. (Should be checked by caller).
 * @note Error value is set to indicate success or failure.
 */
extern s_strings_t safe_string_split_limit_char(s_string_t, const char *, unsigned long int, unsigned long int *);
