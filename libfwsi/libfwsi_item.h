/*
 * Windows Shell Item functions
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

#if !defined( _LIBFWSI_INTERNAL_ITEM_H )
#define _LIBFWSI_INTERNAL_ITEM_H

#include <common.h>
#include <types.h>

#include "libfwsi_extern.h"
#include "libfwsi_libcdata.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_types.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libfwsi_internal_item libfwsi_internal_item_t;

struct libfwsi_internal_item
{
	/* The (item) type
	 */
	int type;

	/* The class type
	 */
	uint8_t class_type;

	/* The signature (mainly used for class type 0x00)
	 */
	uint32_t signature;

	/* The data size
	 */
	uint16_t data_size;

	/* The item value
	 */
        intptr_t *value;

	/* The item free value function
	 */
	int (*free_value)(
	       intptr_t **value,
	       libcerror_error_t **error );

	/* Value to indicate the delegate folder identifier is set
	 */
	uint8_t has_delegate_folder_identifier;

	/* The delegate folder identifier
	 */
	uint8_t delegate_folder_identifier[ 16 ];

	/* The extension blocks array
	 */
	libcdata_array_t *extension_blocks_array;

	/* The parent shell item
	 */
	libfwsi_item_t *parent_item;

	/* The codepage of the extended ASCII strings
	 */
	int ascii_codepage;

	/* Value to indicate if the item is managed by a list
	 */
	uint8_t is_managed;
};

LIBFWSI_EXTERN \
int libfwsi_item_initialize(
     libfwsi_item_t **item,
     libcerror_error_t **error );

int libfwsi_internal_item_initialize(
     libfwsi_internal_item_t **internal_item,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_item_free(
     libfwsi_item_t **item,
     libcerror_error_t **error );

int libfwsi_internal_item_free(
     libfwsi_internal_item_t **internal_item,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_item_copy_from_byte_stream(
     libfwsi_item_t *item,
     const uint8_t *byte_stream,
     size_t byte_stream_size,
     int ascii_codepage,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_item_get_type(
     libfwsi_item_t *item,
     int *type,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_item_get_class_type(
     libfwsi_item_t *item,
     uint8_t *class_type,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_item_get_signature(
     libfwsi_item_t *item,
     uint32_t *signature,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_item_get_data_size(
     libfwsi_item_t *item,
     size_t *data_size,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_item_get_delegate_folder_identifier(
     libfwsi_item_t *item,
     uint8_t *guid_data,
     size_t guid_data_size,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_item_get_number_of_extension_blocks(
     libfwsi_item_t *item,
     int *number_of_extension_blocks,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_item_get_extension_block(
     libfwsi_item_t *item,
     int extension_block_index,
     libfwsi_extension_block_t **extension_block,
     libcerror_error_t **error );

int libfwsi_item_get_parent_item(
     libfwsi_item_t *item,
     libfwsi_item_t **parent_item,
     libcerror_error_t **error );

int libfwsi_item_set_parent_item(
     libfwsi_item_t *item,
     libfwsi_item_t *parent_item,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFWSI_INTERNAL_ITEM_H ) */

