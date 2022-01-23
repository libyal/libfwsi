/*
 * MTP storage device volume (shell item) values functions
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

#if !defined( _LIBFWSI_MTP_VOLUME_VALUES_H )
#define _LIBFWSI_MTP_VOLUME_VALUES_H

#include <common.h>
#include <types.h>

#include "libfwsi_libcerror.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libfwsi_mtp_volume_values libfwsi_mtp_volume_values_t;

struct libfwsi_mtp_volume_values
{
	/* Dummy
	 */
	int dummy;
};

int libfwsi_mtp_volume_values_initialize(
     libfwsi_mtp_volume_values_t **mtp_volume_values,
     libcerror_error_t **error );

int libfwsi_mtp_volume_values_free(
     libfwsi_mtp_volume_values_t **mtp_volume_values,
     libcerror_error_t **error );

int libfwsi_mtp_volume_values_read_data(
     libfwsi_mtp_volume_values_t *mtp_volume_values,
     const uint8_t *data,
     size_t data_size,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFWSI_MTP_VOLUME_VALUES_H ) */

