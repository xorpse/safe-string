/*!
 * @file utility/token_split.h
 * @brief Header file for function to split a string based upon a list
 * of characters.
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

#ifndef _SAFE_STRING_UTILITY_TOKEN_SPLIT_H_
#define _SAFE_STRING_UTILITY_TOKEN_SPLIT_H_

/*!
 * @brief Splits input string into tokens by splitting on elements specified by the elements of
 * another string.
 * @param str source string
 * @param tokens the string containing the characters to split on
 * @param count the amount of elements created by splitting
 * @return An array of strings created by splitting the source string.
 */
extern s_strings_t safe_string_token_split_char(s_string_t, const char *, unsigned long int *);

/*!
 * @brief Splits input string into tokens by splitting on elements specified by the elements of
 * another string.
 * @param str source string
 * @param tokens the string containing the characters to split on
 * @param limit the maximum amount of splits t make, 0 for unlimited splits
 * @param count the amount of elements created by splitting
 * @return An array of strings created by splitting the source string.
 */
extern s_strings_t safe_string_token_split_limit_char(s_string_t, const char *, unsigned long int, unsigned long int *);

/*!
 * @brief Splits input string into tokens by splitting on elements specified by the elements of
 * another string.
 * @param str source string
 * @param tokens the string containing the characters to split on
 * @param count the amount of elements created by splitting
 * @return An array of strings created by splitting the source string.
 */
extern s_strings_t safe_string_token_split(s_string_t, s_string_t, unsigned long int *);

/*!
 * @brief Splits input string into tokens by splitting on elements specified by the elements of
 * another string.
 * @param str source string
 * @param tokens the string containing the characters to split on
 * @param limit the maximum amount of splits t make, 0 for unlimited splits
 * @param count the amount of elements created by splitting
 * @return An array of strings created by splitting the source string.
 */
extern s_strings_t safe_string_token_split_limit(s_string_t, s_string_t, unsigned long int, unsigned long int *);

#endif
