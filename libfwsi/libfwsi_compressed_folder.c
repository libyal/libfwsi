/*
 * Compressed folder (shell item) functions
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

#include "libfwsi_compressed_folder.h"
#include "libfwsi_compressed_folder_values.h"
#include "libfwsi_definitions.h"
#include "libfwsi_item.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libuna.h"

/* Retrieves the size of the UTF-8 formatted name
 * Returns 1 if successful or -1 on error
 */
int libfwsi_compressed_folder_get_utf8_name_size(
     libfwsi_item_t *compressed_folder,
     size_t *utf8_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item = NULL;
	static char *function                  = "libfwsi_compressed_folder_get_utf8_name_size";

	if( compressed_folder == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid compressed folder.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) compressed_folder;

	if( internal_item->type != LIBFWSI_ITEM_TYPE_COMPRESSED_FOLDER )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported item type.",
		 function );

		return( -1 );
	}
	if( libfwsi_compressed_folder_values_get_utf8_name_size(
	     (libfwsi_compressed_folder_values_t *) internal_item->value,
	     utf8_string_size,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve size of UTF-8 string.",
		 function );

		return( -1 );
	}
	return( 1 );
}

/* Retrieves the UTF-8 formatted name
 * Returns 1 if successful or -1 on error
 */
int libfwsi_compressed_folder_get_utf8_name(
     libfwsi_item_t *compressed_folder,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item = NULL;
	static char *function                  = "libfwsi_compressed_folder_get_utf8_name";

	if( compressed_folder == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid compressed folder.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) compressed_folder;

	if( internal_item->type != LIBFWSI_ITEM_TYPE_COMPRESSED_FOLDER )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported item type.",
		 function );

		return( -1 );
	}
	if( libfwsi_compressed_folder_values_get_utf8_name(
	     (libfwsi_compressed_folder_values_t *) internal_item->value,
	     utf8_string,
	     utf8_string_size,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve UTF-8 string.",
		 function );

		return( -1 );
	}
	return( 1 );
}

/* Retrieves the size of the UTF-16 formatted name
 * Returns 1 if successful or -1 on error
 */
int libfwsi_compressed_folder_get_utf16_name_size(
     libfwsi_item_t *compressed_folder,
     size_t *utf16_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item = NULL;
	static char *function                  = "libfwsi_compressed_folder_get_utf16_name_size";

	if( compressed_folder == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid compressed folder.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) compressed_folder;

	if( internal_item->type != LIBFWSI_ITEM_TYPE_COMPRESSED_FOLDER )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported item type.",
		 function );

		return( -1 );
	}
	if( libfwsi_compressed_folder_values_get_utf16_name_size(
	     (libfwsi_compressed_folder_values_t *) internal_item->value,
	     utf16_string_size,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve size of UTF-16 string.",
		 function );

		return( -1 );
	}
	return( 1 );
}

/* Retrieves the UTF-16 formatted name
 * Returns 1 if successful or -1 on error
 */
int libfwsi_compressed_folder_get_utf16_name(
     libfwsi_item_t *compressed_folder,
     uint16_t *utf16_string,
     size_t utf16_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item = NULL;
	static char *function                  = "libfwsi_compressed_folder_get_utf16_name";

	if( compressed_folder == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid compressed folder.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) compressed_folder;

	if( internal_item->type != LIBFWSI_ITEM_TYPE_COMPRESSED_FOLDER )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported item type.",
		 function );

		return( -1 );
	}
	if( libfwsi_compressed_folder_values_get_utf16_name(
	     (libfwsi_compressed_folder_values_t *) internal_item->value,
	     utf16_string,
	     utf16_string_size,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve UTF-16 string.",
		 function );

		return( -1 );
	}
	return( 1 );
}

/* Retrieves the size of the UTF-8 formatted name
 * The size includes the end of string character
 * Returns 1 if successful or -1 on error
 */
int libfwsi_compressed_folder_values_get_utf8_name_size(
     libfwsi_compressed_folder_values_t *compressed_folder_values,
     size_t *utf8_string_size,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_compressed_folder_values_get_utf8_name_size";

	if( compressed_folder_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid compressed folder values.",
		 function );

		return( -1 );
	}
	if( libuna_utf8_string_size_from_utf16_stream(
	     compressed_folder_values->name,
	     compressed_folder_values->name_size,
	     LIBUNA_ENDIAN_LITTLE,
	     utf8_string_size,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to determine size of UTF-8 string.",
		 function );

		return( -1 );
	}
	return( 1 );
}

/* Retrieves the UTF-8 formatted name
 * The size should include the end of string character
 * Returns 1 if successful or -1 on error
 */
int libfwsi_compressed_folder_values_get_utf8_name(
     libfwsi_compressed_folder_values_t *compressed_folder_values,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_compressed_folder_values_get_utf8_name";

	if( compressed_folder_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid compressed folder values.",
		 function );

		return( -1 );
	}
	if( libuna_utf8_string_copy_from_utf16_stream(
	     utf8_string,
	     utf8_string_size,
	     compressed_folder_values->name,
	     compressed_folder_values->name_size,
	     LIBUNA_ENDIAN_LITTLE,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to set UTF-8 string.",
		 function );

		return( -1 );
	}
	return( 1 );
}

/* Retrieves the size of the UTF-16 formatted name
 * The size includes the end of string character
 * Returns 1 if successful or -1 on error
 */
int libfwsi_compressed_folder_values_get_utf16_name_size(
     libfwsi_compressed_folder_values_t *compressed_folder_values,
     size_t *utf16_string_size,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_compressed_folder_values_get_utf16_name_size";

	if( compressed_folder_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid compressed folder values.",
		 function );

		return( -1 );
	}
	if( libuna_utf16_string_size_from_utf16_stream(
	     compressed_folder_values->name,
	     compressed_folder_values->name_size,
	     LIBUNA_ENDIAN_LITTLE,
	     utf16_string_size,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to determine size of UTF-16 string.",
		 function );

		return( -1 );
	}
	return( 1 );
}

/* Retrieves the UTF-16 formatted name
 * The size should include the end of string character
 * Returns 1 if successful or -1 on error
 */
int libfwsi_compressed_folder_values_get_utf16_name(
     libfwsi_compressed_folder_values_t *compressed_folder_values,
     uint16_t *utf16_string,
     size_t utf16_string_size,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_compressed_folder_values_get_utf16_name";

	if( compressed_folder_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid compressed folder values.",
		 function );

		return( -1 );
	}
	if( libuna_utf16_string_copy_from_utf16_stream(
	     utf16_string,
	     utf16_string_size,
	     compressed_folder_values->name,
	     compressed_folder_values->name_size,
	     LIBUNA_ENDIAN_LITTLE,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to set UTF-16 string.",
		 function );

		return( -1 );
	}
	return( 1 );
}

