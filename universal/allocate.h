/*!
 * @file universal/allocate.h
 * @brief Header file for string allocation and deletion functions
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

#ifndef _SAFE_STRING_UNIVERSAL_ALLOCATE_H_
#define _SAFE_STRING_UNIVERSAL_ALLOCATE_H_

#include "types/types.h"

/*!
 * @brief Allocates a new string with a given value
 * @param str value to assign the string
 * @return The newly created string, or an invalid string
 * if there was an error
 * @note Sets the error variable indicating success or failure
 */
extern s_string_t safe_string_new(const char *);

/*!
 * @brief Deletes a given string
 * @param str source string
 * @note Sets the error variable indicating success or failure
 */
extern void safe_string_delete(s_string_t);

/*!
 * @brief Deletes a given array of strings
 * @param strs source array of strings
 * @param count number of elements in the array
 * @note Sets the error variable indicating success or failure
 */
extern void safe_string_array_delete(s_strings_t strs, int count);

#endif
