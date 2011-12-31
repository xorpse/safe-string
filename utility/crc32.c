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

#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include "types/types.h"
#include "universal.h"
#include "utility.h"
#include "macro.h"

#define _S_8BIT  8  /*!< Alias for 8 bits */
#define _S_24BIT 24 /*!< Alias for 24 bits */
#define _S_32BIT 32 /*!< Alias for 32 bits */
#define _S_POLYNOMINAL 0x04C11DB7 /*!< Value of ISO 3309 CRC32 polynominal */

uint32_t *_s_crc32_lookup_table = SAFE_STRING_INVALID; /*!< (INTERNAL) Lookup table for computing CRC32 checksums */

/*!
 * @brief (INTERNAL) Bit reflection (swaps bit positions about a central point)
 * @param value the 32-bit value to be operated upon
 * @param bits the size of the value to be operated upon
 * @return The value after being reflected
 */
uint32_t _safe_string_crc32_reflect_bits(uint32_t value, uint32_t bits)
{
	uint32_t i = 0, output = 0;

	for(i = 0; i < bits; i++, value >>= 1) {
		if(value & 1) {
			output |= 1 << (bits - (i + 1));
		}
	}

	return(output);
}

/*!
 * @brief (INTERNAL) Generates a lookup table to aid in calculation of the CRC32 checksum
 * @note Sets the error variable indicating success or failure
 */
void _safe_string_crc32_lookup_table_generate(void)
{
	if(!_s_crc32_lookup_table) {
		_s_crc32_lookup_table = (uint32_t *)calloc(S_CHARSET_LIMIT, sizeof(uint32_t));

		if(_s_crc32_lookup_table) {
			uint32_t i = 0, j = 0;

			for(i = 0; i < S_CHARSET_LIMIT; i++) {
				_s_crc32_lookup_table[i] = _safe_string_crc32_reflect_bits(i, _S_8BIT) << _S_24BIT;

				for(j = 0; j < _S_8BIT; j++) {
					_s_crc32_lookup_table[i] = (_s_crc32_lookup_table[i] << 1) ^ ((_s_crc32_lookup_table[i] & 0x80000000) ? _S_POLYNOMINAL : 0);
				}

				_s_crc32_lookup_table[i] = _safe_string_crc32_reflect_bits(_s_crc32_lookup_table[i], _S_32BIT);
			}
		} else {
			safe_string_set_error(SAFE_STRING_ERROR_MEM_ALLOC);
		}
	}
	return;
}

/*!
 * @brief Frees the memory held by the CRC32 lookup table
 */
void safe_string_crc32_delete(void)
{
	if(_s_crc32_lookup_table) {
		free(_s_crc32_lookup_table);
	}
}

/*!
 * @brief Generates the CRC32 checksum of a given safe string
 * @param str the source string
 * @return The CRC32 checksum calculated from the given string
 * @note Sets the error variable indicating success or failure
 */
uint32_t safe_string_crc32(s_string_t str)
{
	if(!_s_crc32_lookup_table) {
		_safe_string_crc32_lookup_table_generate();
		if(safe_string_error()) {
			return(SAFE_STRING_EMPTY);
		}
	}

	if(safe_string_valid(str)) {
		uint32_t crc = 0xFFFFFFFF, i = 0;

		for(i = 0; i < safe_string_length(str); i++) {
			crc = (crc >> _S_8BIT) ^ _s_crc32_lookup_table[(crc & 0xFF) ^ (unsigned char)safe_string_index(str, i)];
		}

		safe_string_set_error(SAFE_STRING_ERROR_NO_ERROR);
		return(crc ^ 0xFFFFFFFF);
	} else {
		safe_string_set_error(SAFE_STRING_ERROR_NULL_POINTER);
		return(SAFE_STRING_EMPTY);
	}
}
