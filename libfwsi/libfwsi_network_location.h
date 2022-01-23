/*
 * Network location (shell item) functions
 *
 * Copyright (C) 2010-2022, Joachim Metz <joachim.metz@gmail.com>
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

#if !defined( _LIBFWSI_NETWORK_LOCATION_H )
#define _LIBFWSI_NETWORK_LOCATION_H

#include <common.h>
#include <types.h>

#include "libfwsi_extern.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_types.h"

#if defined( __cplusplus )
extern "C" {
#endif

LIBFWSI_EXTERN \
int libfwsi_network_location_get_utf8_location_size(
     libfwsi_item_t *network_location,
     size_t *utf8_string_size,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_network_location_get_utf8_location(
     libfwsi_item_t *network_location,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_network_location_get_utf16_location_size(
     libfwsi_item_t *network_location,
     size_t *utf16_string_size,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_network_location_get_utf16_location(
     libfwsi_item_t *network_location,
     uint16_t *utf16_string,
     size_t utf16_string_size,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_network_location_get_utf8_description_size(
     libfwsi_item_t *network_location,
     size_t *utf8_string_size,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_network_location_get_utf8_description(
     libfwsi_item_t *network_location,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_network_location_get_utf16_description_size(
     libfwsi_item_t *network_location,
     size_t *utf16_string_size,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_network_location_get_utf16_description(
     libfwsi_item_t *network_location,
     uint16_t *utf16_string,
     size_t utf16_string_size,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_network_location_get_utf8_comments_size(
     libfwsi_item_t *network_location,
     size_t *utf8_string_size,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_network_location_get_utf8_comments(
     libfwsi_item_t *network_location,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_network_location_get_utf16_comments_size(
     libfwsi_item_t *network_location,
     size_t *utf16_string_size,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_network_location_get_utf16_comments(
     libfwsi_item_t *network_location,
     uint16_t *utf16_string,
     size_t utf16_string_size,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFWSI_NETWORK_LOCATION_H ) */

