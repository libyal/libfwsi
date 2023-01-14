/*
 * File entry extension values functions
 *
 * Copyright (C) 2010-2023, Joachim Metz <joachim.metz@gmail.com>
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

#if !defined( _LIBFWSI_FILE_ENTRY_EXTENSION_VALUES_H )
#define _LIBFWSI_FILE_ENTRY_EXTENSION_VALUES_H

#include <common.h>
#include <types.h>

#include "libfwsi_libcerror.h"
#include "libfwsi_extension_block.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libfwsi_file_entry_extension_values libfwsi_file_entry_extension_values_t;

struct libfwsi_file_entry_extension_values
{
	/* The creation time
	 */
	uint32_t creation_time;

	/* The access time
	 */
	uint32_t access_time;

	/* The NTFS file reference
	 */
	uint64_t file_reference;

	/* The long name
	 */
	uint8_t *long_name;

	/* The long name size
	 */
	size_t long_name_size;

	/* The localized name
	 */
	uint8_t *localized_name;

	/* The localized name size
	 */
	size_t localized_name_size;

	/* The ASCII codepage
	 */
	int ascii_codepage;
};

int libfwsi_file_entry_extension_values_initialize(
     libfwsi_file_entry_extension_values_t **file_entry_extension_values,
     libcerror_error_t **error );

int libfwsi_file_entry_extension_values_free(
     libfwsi_file_entry_extension_values_t **file_entry_extension_values,
     libcerror_error_t **error );

int libfwsi_file_entry_extension_values_read_data(
     libfwsi_file_entry_extension_values_t *file_entry_extension_values,
     const uint8_t *data,
     size_t data_size,
     int ascii_codepage,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFWSI_FILE_ENTRY_EXTENSION_VALUES_H ) */

