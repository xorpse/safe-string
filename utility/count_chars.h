/*!
 * @file utility/count_chars.h
 * @brief Header for implementation of count_chars
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

#ifndef _SAFE_STRING_UTILITY_COUNT_CHARS_H_
#define _SAFE_STRING_UTILITY_COUNT_CHARS_H_

#include "types/types.h"

typedef enum { \
	S_COUNT_CHARS_MODE_FREQS_COUNT      /*!< Return a integer array containing the frequency that characters occur in the string */, \
	S_COUNT_CHARS_MODE_CHARS_USED       /*!< Return a character array containing all of the used characters (in order of appearance) */, \
	S_COUNT_CHARS_MODE_CHARS_UNUSED     /*!< Return a character array containing all of the unused characters (in character set order) */, \
	S_COUNT_CHARS_MODE_CHARS_UNIQUE     /*!< Return a character array containing all of the characters that appeared only once */, \
	S_COUNT_CHARS_MODE_CHARS_NOT_UNIQUE /*!< Return a character array containing off of the characters that appeared more than once */ \
} s_string_count_chars_mode_t;

#define _S_COUNT_CHARS_MODE_FREQS_MIN S_COUNT_CHARS_MODE_FREQS_COUNT /*!< (INTERNAL) First mode of the frequency type */
#define _S_COUNT_CHARS_MODE_FREQS_MAX S_COUNT_CHARS_MODE_FREQS_COUNT /*!< (INTERNAL) Last mode of the frequency type */

#define _S_COUNT_CHARS_MODE_CHARS_MIN S_COUNT_CHARS_MODE_CHARS_USED       /*!< (INTERNAL) First mode of the character type */
#define _S_COUNT_CHARS_MODE_CHARS_MAX S_COUNT_CHARS_MODE_CHARS_NOT_UNIQUE /*!< (INTERNAL) Last mode of the character type */

#define _S_COUNT_CHARS_MODE_FREQS(m) (m >= _S_COUNT_CHARS_MODE_FREQS_MIN && m <= _S_COUNT_CHARS_MODE_FREQS_MAX) /*!< (INTERNAL) Tests if mode is valid for frequencies */
#define _S_COUNT_CHARS_MODE_CHARS(m) (m >= _S_COUNT_CHARS_MODE_CHARS_MIN && m <= _S_COUNT_CHARS_MODE_CHARS_MAX) /*!< (INTERNAL) Tests if mode is valid for characters */

#define safe_string_count_chars(string, mode, count) \
	_S_COUNT_CHARS_MODE_FREQS(mode) ? (unsigned long int *)_safe_string_count_chars_freqs(string, mode, count) : (char *)_safe_string_count_chars_chars(string, mode, count)

/*!
 * @brief Returns specific frequencies of characters from a given string
 * @param str source string
 * @param mode for valid modes see the s_string_count_chars_mode_t definition
 * @param count address of the variable to store the amount of elements in the returned array
 * @return Array containing frequencies of characters specified by the mode
 * @note Sets the error variable indicating success or failure
 */
extern unsigned long int *_safe_string_count_chars_freqs(s_string_t str, s_string_count_chars_mode_t mode, unsigned long int *count);

/*!
 * @brief Returns specific characters from a given string
 * @param str source string
 * @param mode for valid modes see the s_string_count_chars_mode_t definition
 * @param count address of the variable to store the amount of elements in the returned array
 * @return Array containing characters from the string specified by the mode
 * @note Sets the error variable indicating success or failure
 */
extern char *_safe_string_count_chars_chars(s_string_t str, s_string_count_chars_mode_t mode, unsigned long int *count);

#endif
