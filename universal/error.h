/*!
 * @file universal/error.h
 * @brief Header file for error handling functions
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

#ifndef _SAFE_STRING_UNIVERSAL_ERROR_H_
#define _SAFE_STRING_UNIVERSAL_ERROR_H_

/*!
 * @brief Type definition for error value enumeration
 */
typedef enum { \
	SAFE_STRING_ERROR_NO_ERROR /*!< Success */, \
	SAFE_STRING_ERROR_INVALID_ARG /*!< Invalid argument passed to the function */, \
	SAFE_STRING_ERROR_MEM_ALLOC /*!< Couldn't allocate memory and thus could not continue execution of the function */, \
	SAFE_STRING_ERROR_NULL_POINTER /*!< A NULL pointer was passed to the function and it couldn't be handled */, \
	SAFE_STRING_ERROR_INDEX_BOUNDS /*!< An attempt was made to access memory outside of the defined boundaries */, \
	SAFE_STRING_ERROR_BAD_VALUE /*!< An invalid value was produced/taken */ \
} s_string_error_t;

/*!
 * @brief Sets the error variable
 * @param err value to set the error variable
 */
extern void safe_string_set_error(s_string_error_t);

/*!
 * @brief Gets the error variable's value
 * @return The value of the error variable
 */
extern s_string_error_t safe_string_error_val(void);

/*!
 * @brief Checks if there is an error without regard to it's type
 * @return Non-zero if there was no error, zero otherwise
 */
int safe_string_error(void);

#endif
