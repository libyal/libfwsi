/*
 * Volume (shell item) functions
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

#if !defined( _LIBFWSI_VOLUME_H )
#define _LIBFWSI_VOLUME_H

#include <common.h>
#include <types.h>

#include "libfwsi_extern.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_types.h"

#if defined( __cplusplus )
extern "C" {
#endif

LIBFWSI_EXTERN \
int libfwsi_volume_get_utf8_name_size(
     libfwsi_item_t *volume,
     size_t *utf8_string_size,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_volume_get_utf8_name(
     libfwsi_item_t *volume,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_volume_get_utf16_name_size(
     libfwsi_item_t *volume,
     size_t *utf16_string_size,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_volume_get_utf16_name(
     libfwsi_item_t *volume,
     uint16_t *utf16_string,
     size_t utf16_string_size,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_volume_get_identifier(
     libfwsi_item_t *volume,
     uint8_t *guid_data,
     size_t guid_data_size,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_volume_get_shell_folder_identifier(
     libfwsi_item_t *volume,
     uint8_t *guid_data,
     size_t guid_data_size,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFWSI_VOLUME_H ) */

