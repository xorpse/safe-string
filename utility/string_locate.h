/*!
 * @file utility/string_locate.h
 * @brief Header file for string locating functions
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

#ifndef _SAFE_STRING_UTILITY_STRING_LOCATE_H_
#define _SAFE_STRING_UTILITY_STRING_LOCATE_H_

#include "types/types.h"

/*!
 * @brief Finds the offset of a substring of a given string between a lower
 * and upper bound.
 * @param haystack source string
 * @param needle string to find
 * @param offset starting offset to search from
 * @param limit ending offset to search to
 * @return The index of the first letter of the first occurance of the string
 * to be found within the source string. If the string is not found then
 * the error value is set to SAFE_STRING_INVALID_RETURN and 0 is returned.
 * @note The error value is set indicating success or failure.
 */
extern unsigned long int safe_string_string_locate_offset_limit(s_string_t, s_string_t, unsigned long int, unsigned long int);

/*!
 * @brief Finds the offset of a substring of a given string using an upper bound.
 * @param haystack source string
 * @param needle string to find
 * @param limit ending offset to search to
 * @return The index of the first letter of the first occurance of the string
 * to be found within the source string. If the string is not found then
 * the error value is set to SAFE_STRING_INVALID_RETURN and 0 is returned.
 * @note The error value is set indicating success or failure.
 */
extern unsigned long int safe_string_string_locate_limit(s_string_t, s_string_t, unsigned long int);

/*!
 * @brief Finds the offset of a substring of a given string using a lower bound.
 * @param haystack source string
 * @param needle string to find
 * @param offset starting offset to search from
 * @return The index of the first letter of the first occurance of the string
 * to be found within the source string. If the string is not found then
 * the error value is set to SAFE_STRING_INVALID_RETURN and 0 is returned.
 * @note The error value is set indicating success or failure.
 */
extern unsigned long int safe_string_string_locate_offset(s_string_t, s_string_t, unsigned long int);

/*!
 * @brief Finds the offset of a substring of a given string.
 * @param haystack source string
 * @param needle string to find
 * @return The index of the first letter of the first occurance of the string
 * to be found within the source string. If the string is not found then
 * the error value is set to SAFE_STRING_INVALID_RETURN and 0 is returned.
 * @note The error value is set indicating success or failure.
 */
extern unsigned long int safe_string_string_locate(s_string_t, s_string_t);

#endif
