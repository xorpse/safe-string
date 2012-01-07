/*!
 * @file utility/substring.h
 * @brief Header file for substring functions
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

#ifndef _SAFE_STRING_UTILITY_SUBSTRING_H_
#define _SAFE_STRING_UTILITY_SUBSTRING_H_

#include "types/types.h"

/*!
 * @brief Extracts a string from within another string.
 * @param str source string
 * @param offset starting index for extraction
 * @param limit ending index for extraction
 * @return A safe string containing the substring defined by the bounaries 'offset'
 * and 'limit'.
 * @note Sets the error value indicating success or failure.
 */
extern s_string_t safe_string_substring(s_string_t str, unsigned long int, unsigned long int);

/*!
 * @brief Extracts a string from within another string. Using only a starting position,
 * extraction is performed using the length of the string as an upper bound.
 * @param str source string
 * @param offset starting index for extraction
 * @return A safe string containing the substring defined by the bounary 'offset'
 * and the length of the source string.
 * @note Sets the error value indicating success or failure.
 */
extern s_string_t safe_string_substring_auto(s_string_t str, unsigned long int);

#endif
