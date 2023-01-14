/*
 * Volume (shell item) values functions
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

#if !defined( _LIBFWSI_VOLUME_VALUES_H )
#define _LIBFWSI_VOLUME_VALUES_H

#include <common.h>
#include <types.h>

#include "libfwsi_libcerror.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libfwsi_volume_values libfwsi_volume_values_t;

struct libfwsi_volume_values
{
	/* Value to indicate the name is set
	 */
	uint8_t has_name;

	/* The name
	 */
	uint8_t name[ 20 ];

	/* The name size
	 */
	size_t name_size;

	/* The identifier
	 */
	uint8_t identifier[ 16 ];

	/* The shell folder (class) identifier
	 */
	uint8_t shell_folder_identifier[ 16 ];

	/* The ASCII codepage
	 */
	int ascii_codepage;
};

int libfwsi_volume_values_initialize(
     libfwsi_volume_values_t **volume_values,
     libcerror_error_t **error );

int libfwsi_volume_values_free(
     libfwsi_volume_values_t **volume_values,
     libcerror_error_t **error );

int libfwsi_volume_values_read_data(
     libfwsi_volume_values_t *volume_values,
     const uint8_t *data,
     size_t data_size,
     int ascii_codepage,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFWSI_VOLUME_VALUES_H ) */

