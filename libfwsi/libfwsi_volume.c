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

#include <common.h>
#include <memory.h>
#include <types.h>

#include "libfwsi_definitions.h"
#include "libfwsi_item.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libuna.h"
#include "libfwsi_volume.h"
#include "libfwsi_volume_values.h"

/* Retrieves the size of the UTF-8 formatted name
 * Returns 1 if successful, 0 if not available or -1 on error
 */
int libfwsi_volume_get_utf8_name_size(
     libfwsi_item_t *volume,
     size_t *utf8_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item = NULL;
	static char *function                  = "libfwsi_volume_get_utf8_name_size";
	int result                             = 0;

	if( volume == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid volume.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) volume;

	if( internal_item->type != LIBFWSI_ITEM_TYPE_VOLUME )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported item type.",
		 function );

		return( -1 );
	}
	result = libfwsi_volume_values_get_utf8_name_size(
	          (libfwsi_volume_values_t *) internal_item->value,
	          utf8_string_size,
	          internal_item->ascii_codepage,
	          error );

	if( result == -1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve size of UTF-8 string.",
		 function );

		return( -1 );
	}
	return( result );
}

/* Retrieves the UTF-8 formatted name
 * Returns 1 if successful, 0 if not available or -1 on error
 */
int libfwsi_volume_get_utf8_name(
     libfwsi_item_t *volume,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item = NULL;
	static char *function                  = "libfwsi_volume_get_utf8_name";
	int result                             = 0;

	if( volume == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid volume.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) volume;

	if( internal_item->type != LIBFWSI_ITEM_TYPE_VOLUME )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported item type.",
		 function );

		return( -1 );
	}
	result = libfwsi_volume_values_get_utf8_name(
	          (libfwsi_volume_values_t *) internal_item->value,
	          utf8_string,
	          utf8_string_size,
	          internal_item->ascii_codepage,
	          error );

	if( result == -1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve UTF-8 string.",
		 function );

		return( -1 );
	}
	return( result );
}

/* Retrieves the size of the UTF-16 formatted name
 * Returns 1 if successful, 0 if not available or -1 on error
 */
int libfwsi_volume_get_utf16_name_size(
     libfwsi_item_t *volume,
     size_t *utf16_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item = NULL;
	static char *function                  = "libfwsi_volume_get_utf16_name_size";
	int result                             = 0;

	if( volume == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid volume.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) volume;

	if( internal_item->type != LIBFWSI_ITEM_TYPE_VOLUME )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported item type.",
		 function );

		return( -1 );
	}
	result = libfwsi_volume_values_get_utf16_name_size(
	          (libfwsi_volume_values_t *) internal_item->value,
	          utf16_string_size,
	          internal_item->ascii_codepage,
	          error );

	if( result == -1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve size of UTF-16 string.",
		 function );

		return( -1 );
	}
	return( result );
}

/* Retrieves the UTF-16 formatted name
 * Returns 1 if successful, 0 if not available or -1 on error
 */
int libfwsi_volume_get_utf16_name(
     libfwsi_item_t *volume,
     uint16_t *utf16_string,
     size_t utf16_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item = NULL;
	static char *function                  = "libfwsi_volume_get_utf16_name";
	int result                             = 0;

	if( volume == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid volume.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) volume;

	if( internal_item->type != LIBFWSI_ITEM_TYPE_VOLUME )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported item type.",
		 function );

		return( -1 );
	}
	result = libfwsi_volume_values_get_utf16_name(
	          (libfwsi_volume_values_t *) internal_item->value,
	          utf16_string,
	          utf16_string_size,
	          internal_item->ascii_codepage,
	          error );

	if( result == -1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve UTF-16 string.",
		 function );

		return( -1 );
	}
	return( result );
}

/* Retrieves the identifier
 * The identifier is a GUID and is 16 bytes of size
 * Returns 1 if successful, 0 if not available or -1 on error
 */
int libfwsi_volume_get_identifier(
     libfwsi_item_t *volume,
     uint8_t *guid_data,
     size_t guid_data_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item = NULL;
	static char *function                  = "libfwsi_volume_get_identifier";
	int result                             = 0;

	if( volume == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid volume.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) volume;

	if( internal_item->type != LIBFWSI_ITEM_TYPE_VOLUME )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported item type.",
		 function );

		return( -1 );
	}
	result = libfwsi_volume_values_get_identifier(
	          (libfwsi_volume_values_t *) internal_item->value,
	          guid_data,
	          guid_data_size,
	          error );

	if( result == -1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve identifier.",
		 function );

		return( -1 );
	}
	return( result );
}

/* Retrieves the shell folder identifier
 * The identifier is a GUID and is 16 bytes of size
 * Returns 1 if successful, 0 if not available or -1 on error
 */
int libfwsi_volume_get_shell_folder_identifier(
     libfwsi_item_t *volume,
     uint8_t *guid_data,
     size_t guid_data_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item = NULL;
	static char *function                  = "libfwsi_volume_get_shell_folder_identifier";
	int result                             = 0;

	if( volume == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid volume.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) volume;

	if( internal_item->type != LIBFWSI_ITEM_TYPE_VOLUME )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported item type.",
		 function );

		return( -1 );
	}
	result = libfwsi_volume_values_get_shell_folder_identifier(
	          (libfwsi_volume_values_t *) internal_item->value,
	          guid_data,
	          guid_data_size,
	          error );

	if( result == -1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve shell folder identifier.",
		 function );

		return( -1 );
	}
	return( result );
}

