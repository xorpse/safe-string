/*!
 * @file utility/crc32.c
 * @brief Implementation of crc32 operating on safe strings
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

#ifndef _SAFE_STRING_UTILITY_CRC32_H_
#define _SAFE_STRING_UTILITY_CRC32_H_

#include <stdint.h>
#include "types/types.h"

/*!
 * @brief Generates the CRC32 checksum of a given safe string
 * @param str the source string
 * @return The CRC32 checksum calculated from the given string
 * @note Sets the error variable indicating success or failure
 */
extern uint32_t safe_string_crc32(s_string_t);

/*!
 * @brief Frees the memory held by the CRC32 lookup table
 */
extern void safe_string_crc32_delete(void);

#endif
