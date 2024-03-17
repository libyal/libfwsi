/*
 * Users property view (shell item) functions
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

#if !defined( _LIBFWSI_USERS_PROPERTY_VIEW_H )
#define _LIBFWSI_USERS_PROPERTY_VIEW_H

#include <common.h>
#include <types.h>

#include "libfwsi_extern.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_types.h"

#if defined( __cplusplus )
extern "C" {
#endif

LIBFWSI_EXTERN \
int libfwsi_users_property_view_get_known_folder_identifier(
     libfwsi_item_t *users_property_view,
     uint8_t *guid_data,
     size_t guid_data_size,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_users_property_view_get_property_store_data_size(
     libfwsi_item_t *users_property_view,
     size_t *data_size,
     libcerror_error_t **error );

LIBFWSI_EXTERN \
int libfwsi_users_property_view_copy_property_store_data(
     libfwsi_item_t *users_property_view,
     uint8_t *data,
     size_t data_size,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFWSI_USERS_PROPERTY_VIEW_H ) */

