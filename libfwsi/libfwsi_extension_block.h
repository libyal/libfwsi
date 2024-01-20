/*
 * Windows Shell Item extension block functions
 *
 * Copyright (C) 2010-2024, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#if !defined( _LIBFWSI_INTERNAL_EXTENSION_BLOCK_H )
#define _LIBFWSI_INTERNAL_EXTENSION_BLOCK_H

#include <common.h>
#include <types.h>

#include "libfwsi_libcerror.h"
#include "libfwsi_extern.h"
#include "libfwsi_types.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libfwsi_internal_extension_block libfwsi_internal_extension_block_t;

struct libfwsi_internal_extension_block
{
	/* The data size
	 */
	uint16_t data_size;

	/* The version
	 */
	uint16_t version;

	/* The signature
	 */
	uint32_t signature;

	/* The extension block value
	 */
        intptr_t *value;

	/* The extension block free value function
	 */
	int (*free_value)(
	       intptr_t **value,
	       libcerror_error_t **error );
};

int libfwsi_extension_block_initialize(
     libfwsi_extension_block_t **extension_block,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_extension_block_free(
     libfwsi_extension_block_t **extension_block,
     libcerror_error_t **error );

int libfwsi_internal_extension_block_free(
     libfwsi_internal_extension_block_t **internal_extension_block,
     libcerror_error_t **error );

int libfwsi_extension_block_copy_from_byte_stream(
     libfwsi_internal_extension_block_t *internal_extension_block,
     const uint8_t *byte_stream,
     size_t byte_stream_size,
     int ascii_codepage,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_extension_block_get_signature(
     libfwsi_extension_block_t *extension_block,
     uint32_t *signature,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_extension_block_get_data_size(
     libfwsi_extension_block_t *extension_block,
     size_t *data_size,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFWSI_INTERNAL_EXTENSION_BLOCK_H ) */

