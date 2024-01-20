/*
 * Windows Shell Item list functions
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

#if !defined( _LIBFWSI_INTERNAL_LIST_H )
#define _LIBFWSI_INTERNAL_LIST_H

#include <common.h>
#include <types.h>

#include "libfwsi_extern.h"
#include "libfwsi_libcdata.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_types.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libfwsi_internal_item_list libfwsi_internal_item_list_t;

struct libfwsi_internal_item_list
{
	/* The items array
	 */
	libcdata_array_t *items_array;

	/* The data size
	 */
	size_t data_size;

	/* The codepage of the extended ASCII strings
	 */
	int ascii_codepage;
};

LIBFWSI_EXTERN \
int libfwsi_item_list_initialize(
     libfwsi_item_list_t **item_list,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_item_list_free(
     libfwsi_item_list_t **item_list,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_item_list_copy_from_byte_stream(
     libfwsi_item_list_t *item_list,
     const uint8_t *byte_stream,
     size_t byte_stream_size,
     int ascii_codepage,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_item_list_get_data_size(
     libfwsi_item_list_t *item_list,
     size_t *data_size,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_item_list_get_number_of_items(
     libfwsi_item_list_t *item_list,
     int *number_of_items,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_item_list_get_item(
     libfwsi_item_list_t *item_list,
     int item_index,
     libfwsi_item_t **item,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFWSI_INTERNAL_LIST_H ) */

