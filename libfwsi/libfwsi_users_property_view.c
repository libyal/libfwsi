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

#include <common.h>
#include <memory.h>
#include <types.h>

#include "libfwsi_definitions.h"
#include "libfwsi_item.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libuna.h"
#include "libfwsi_users_property_view.h"
#include "libfwsi_users_property_view_values.h"

/* Retrieves the known folder identifier
 * The identifier is a GUID and is 16 bytes of size
 * Returns 1 if successful, 0 if not available or -1 on error
 */
int libfwsi_users_property_view_get_known_folder_identifier(
     libfwsi_item_t *users_property_view,
     uint8_t *guid_data,
     size_t guid_data_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item = NULL;
	static char *function                  = "libfwsi_users_property_view_get_known_folder_identifier";
	int result                             = 0;

	if( users_property_view == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid users property view.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) users_property_view;

	if( internal_item->type != LIBFWSI_ITEM_TYPE_USERS_PROPERTY_VIEW )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported item type.",
		 function );

		return( -1 );
	}
	result = libfwsi_users_property_view_values_get_known_folder_identifier(
	          (libfwsi_users_property_view_values_t *) internal_item->value,
	          guid_data,
	          guid_data_size,
	          error );

	if( result == -1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve known folder identifier.",
		 function );

		return( -1 );
	}
	return( result );
}

/* Retrieves the property store data size
 * Returns 1 if successful or -1 on error
 */
int libfwsi_users_property_view_get_property_store_data_size(
     libfwsi_item_t *users_property_view,
     size_t *data_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item                           = NULL;
	libfwsi_users_property_view_values_t *users_property_view_values = NULL;
	static char *function                                            = "libfwsi_users_property_view_get_property_store_data_size";

	if( users_property_view == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid users property view.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) users_property_view;

	if( internal_item->type != LIBFWSI_ITEM_TYPE_USERS_PROPERTY_VIEW )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported item type.",
		 function );

		return( -1 );
	}
	users_property_view_values = (libfwsi_users_property_view_values_t *) internal_item->value;

	if( data_size == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid data size.",
		 function );

		return( -1 );
	}
	*data_size = (size_t) users_property_view_values->property_store_data_size;

	return( 1 );
}

/* Copies the property store data to the buffer
 * Returns 1 if successful or -1 on error
 */
int libfwsi_users_property_view_copy_property_store_data(
     libfwsi_item_t *users_property_view,
     uint8_t *data,
     size_t data_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item                           = NULL;
	libfwsi_users_property_view_values_t *users_property_view_values = NULL;
	static char *function                                            = "libfwsi_users_property_view_copy_property_store_data";

	if( users_property_view == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid users property view.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) users_property_view;

	if( internal_item->type != LIBFWSI_ITEM_TYPE_USERS_PROPERTY_VIEW )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported item type.",
		 function );

		return( -1 );
	}
	users_property_view_values = (libfwsi_users_property_view_values_t *) internal_item->value;

	if( data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid data.",
		 function );

		return( -1 );
	}
	if( ( data_size < (size_t) users_property_view_values->property_store_data_size )
	 || ( data_size > (size_t) SSIZE_MAX ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid data size value out of bounds.",
		 function );

		return( -1 );
	}
	if( memory_copy(
	     data,
	     users_property_view_values->property_store_data,
	     users_property_view_values->property_store_data_size ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_COPY_FAILED,
		 "%s: unable to copy property store data.",
		 function );

		return( -1 );
	}
	return( 1 );
}

