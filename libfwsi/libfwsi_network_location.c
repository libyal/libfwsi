/*
 * Network location (shell item) functions
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
#include "libfwsi_network_location.h"
#include "libfwsi_network_location_values.h"

/* Retrieves the size of the UTF-8 formatted location
 * Returns 1 if successful or -1 on error
 */
int libfwsi_network_location_get_utf8_location_size(
     libfwsi_item_t *network_location,
     size_t *utf8_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item                     = NULL;
	libfwsi_network_location_values_t *network_location_values = NULL;
	static char *function                                      = "libfwsi_network_location_get_utf8_location_size";

	if( network_location == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid network location.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) network_location;

	if( internal_item->type != LIBFWSI_ITEM_TYPE_NETWORK_LOCATION )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported item type.",
		 function );

		return( -1 );
	}
	if( internal_item->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid network location - missing value.",
		 function );

		return( -1 );
	}
	network_location_values = (libfwsi_network_location_values_t *) internal_item->value;

	if( libuna_utf8_string_size_from_byte_stream(
	     network_location_values->location,
	     network_location_values->location_size,
	     network_location_values->ascii_codepage,
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

/* Retrieves the UTF-8 formatted location
 * Returns 1 if successful or -1 on error
 */
int libfwsi_network_location_get_utf8_location(
     libfwsi_item_t *network_location,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item                     = NULL;
	libfwsi_network_location_values_t *network_location_values = NULL;
	static char *function                                      = "libfwsi_network_location_get_utf8_location";

	if( network_location == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid network location.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) network_location;

	if( internal_item->type != LIBFWSI_ITEM_TYPE_NETWORK_LOCATION )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported item type.",
		 function );

		return( -1 );
	}
	if( internal_item->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid network location - missing value.",
		 function );

		return( -1 );
	}
	network_location_values = (libfwsi_network_location_values_t *) internal_item->value;

	if( libuna_utf8_string_copy_from_byte_stream(
	     utf8_string,
	     utf8_string_size,
	     network_location_values->location,
	     network_location_values->location_size,
	     network_location_values->ascii_codepage,
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

/* Retrieves the size of the UTF-16 formatted location
 * Returns 1 if successful or -1 on error
 */
int libfwsi_network_location_get_utf16_location_size(
     libfwsi_item_t *network_location,
     size_t *utf16_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item                     = NULL;
	libfwsi_network_location_values_t *network_location_values = NULL;
	static char *function                                      = "libfwsi_network_location_get_utf16_location_size";

	if( network_location == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid network location.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) network_location;

	if( internal_item->type != LIBFWSI_ITEM_TYPE_NETWORK_LOCATION )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported item type.",
		 function );

		return( -1 );
	}
	if( internal_item->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid network location - missing value.",
		 function );

		return( -1 );
	}
	network_location_values = (libfwsi_network_location_values_t *) internal_item->value;

	if( libuna_utf16_string_size_from_byte_stream(
	     network_location_values->location,
	     network_location_values->location_size,
	     network_location_values->ascii_codepage,
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

/* Retrieves the UTF-16 formatted location
 * Returns 1 if successful or -1 on error
 */
int libfwsi_network_location_get_utf16_location(
     libfwsi_item_t *network_location,
     uint16_t *utf16_string,
     size_t utf16_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item                     = NULL;
	libfwsi_network_location_values_t *network_location_values = NULL;
	static char *function                                      = "libfwsi_network_location_get_utf16_location";

	if( network_location == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid network location.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) network_location;

	if( internal_item->type != LIBFWSI_ITEM_TYPE_NETWORK_LOCATION )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported item type.",
		 function );

		return( -1 );
	}
	if( internal_item->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid network location - missing value.",
		 function );

		return( -1 );
	}
	network_location_values = (libfwsi_network_location_values_t *) internal_item->value;

	if( libuna_utf16_string_copy_from_byte_stream(
	     utf16_string,
	     utf16_string_size,
	     network_location_values->location,
	     network_location_values->location_size,
	     network_location_values->ascii_codepage,
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

/* Retrieves the size of the UTF-8 formatted description
 * Returns 1 if successful, 0 if not available or -1 on error
 */
int libfwsi_network_location_get_utf8_description_size(
     libfwsi_item_t *network_location,
     size_t *utf8_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item                     = NULL;
	libfwsi_network_location_values_t *network_location_values = NULL;
	static char *function                                      = "libfwsi_network_location_get_utf8_description_size";

	if( network_location == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid network location.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) network_location;

	if( internal_item->type != LIBFWSI_ITEM_TYPE_NETWORK_LOCATION )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported item type.",
		 function );

		return( -1 );
	}
	if( internal_item->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid network location - missing value.",
		 function );

		return( -1 );
	}
	network_location_values = (libfwsi_network_location_values_t *) internal_item->value;

	if( ( network_location_values->description == NULL )
	 || ( network_location_values->description_size == 0 ) )
	{
		return( 0 );
	}
	if( libuna_utf8_string_size_from_byte_stream(
	     network_location_values->description,
	     network_location_values->description_size,
	     network_location_values->ascii_codepage,
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

/* Retrieves the UTF-8 formatted description
 * Returns 1 if successful, 0 if not available or -1 on error
 */
int libfwsi_network_location_get_utf8_description(
     libfwsi_item_t *network_location,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item                     = NULL;
	libfwsi_network_location_values_t *network_location_values = NULL;
	static char *function                                      = "libfwsi_network_location_get_utf8_description";

	if( network_location == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid network location.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) network_location;

	if( internal_item->type != LIBFWSI_ITEM_TYPE_NETWORK_LOCATION )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported item type.",
		 function );

		return( -1 );
	}
	if( internal_item->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid network location - missing value.",
		 function );

		return( -1 );
	}
	network_location_values = (libfwsi_network_location_values_t *) internal_item->value;

	if( ( network_location_values->description == NULL )
	 || ( network_location_values->description_size == 0 ) )
	{
		return( 0 );
	}
	if( libuna_utf8_string_copy_from_byte_stream(
	     utf8_string,
	     utf8_string_size,
	     network_location_values->description,
	     network_location_values->description_size,
	     network_location_values->ascii_codepage,
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

/* Retrieves the size of the UTF-16 formatted description
 * Returns 1 if successful, 0 if not available or -1 on error
 */
int libfwsi_network_location_get_utf16_description_size(
     libfwsi_item_t *network_location,
     size_t *utf16_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item                     = NULL;
	libfwsi_network_location_values_t *network_location_values = NULL;
	static char *function                                      = "libfwsi_network_location_get_utf16_description_size";

	if( network_location == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid network location.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) network_location;

	if( internal_item->type != LIBFWSI_ITEM_TYPE_NETWORK_LOCATION )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported item type.",
		 function );

		return( -1 );
	}
	if( internal_item->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid network location - missing value.",
		 function );

		return( -1 );
	}
	network_location_values = (libfwsi_network_location_values_t *) internal_item->value;

	if( ( network_location_values->description == NULL )
	 || ( network_location_values->description_size == 0 ) )
	{
		return( 0 );
	}
	if( libuna_utf16_string_size_from_byte_stream(
	     network_location_values->description,
	     network_location_values->description_size,
	     network_location_values->ascii_codepage,
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

/* Retrieves the UTF-16 formatted description
 * Returns 1 if successful, 0 if not available or -1 on error
 */
int libfwsi_network_location_get_utf16_description(
     libfwsi_item_t *network_location,
     uint16_t *utf16_string,
     size_t utf16_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item                     = NULL;
	libfwsi_network_location_values_t *network_location_values = NULL;
	static char *function                                      = "libfwsi_network_location_get_utf16_description";

	if( network_location == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid network location.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) network_location;

	if( internal_item->type != LIBFWSI_ITEM_TYPE_NETWORK_LOCATION )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported item type.",
		 function );

		return( -1 );
	}
	if( internal_item->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid network location - missing value.",
		 function );

		return( -1 );
	}
	network_location_values = (libfwsi_network_location_values_t *) internal_item->value;

	if( ( network_location_values->description == NULL )
	 || ( network_location_values->description_size == 0 ) )
	{
		return( 0 );
	}
	if( libuna_utf16_string_copy_from_byte_stream(
	     utf16_string,
	     utf16_string_size,
	     network_location_values->description,
	     network_location_values->description_size,
	     network_location_values->ascii_codepage,
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

/* Retrieves the size of the UTF-8 formatted comments
 * Returns 1 if successful, 0 if not available or -1 on error
 */
int libfwsi_network_location_get_utf8_comments_size(
     libfwsi_item_t *network_location,
     size_t *utf8_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item                     = NULL;
	libfwsi_network_location_values_t *network_location_values = NULL;
	static char *function                                      = "libfwsi_network_location_get_utf8_comments_size";

	if( network_location == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid network location.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) network_location;

	if( internal_item->type != LIBFWSI_ITEM_TYPE_NETWORK_LOCATION )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported item type.",
		 function );

		return( -1 );
	}
	if( internal_item->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid network location - missing value.",
		 function );

		return( -1 );
	}
	network_location_values = (libfwsi_network_location_values_t *) internal_item->value;

	if( ( network_location_values->comments == NULL )
	 || ( network_location_values->comments_size == 0 ) )
	{
		return( 0 );
	}
	if( libuna_utf8_string_size_from_byte_stream(
	     network_location_values->comments,
	     network_location_values->comments_size,
	     network_location_values->ascii_codepage,
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

/* Retrieves the UTF-8 formatted comments
 * Returns 1 if successful, 0 if not available or -1 on error
 */
int libfwsi_network_location_get_utf8_comments(
     libfwsi_item_t *network_location,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item                     = NULL;
	libfwsi_network_location_values_t *network_location_values = NULL;
	static char *function                                      = "libfwsi_network_location_get_utf8_comments";

	if( network_location == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid network location.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) network_location;

	if( internal_item->type != LIBFWSI_ITEM_TYPE_NETWORK_LOCATION )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported item type.",
		 function );

		return( -1 );
	}
	if( internal_item->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid network location - missing value.",
		 function );

		return( -1 );
	}
	network_location_values = (libfwsi_network_location_values_t *) internal_item->value;

	if( ( network_location_values->comments == NULL )
	 || ( network_location_values->comments_size == 0 ) )
	{
		return( 0 );
	}
	if( libuna_utf8_string_copy_from_byte_stream(
	     utf8_string,
	     utf8_string_size,
	     network_location_values->comments,
	     network_location_values->comments_size,
	     network_location_values->ascii_codepage,
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

/* Retrieves the size of the UTF-16 formatted comments
 * Returns 1 if successful, 0 if not available or -1 on error
 */
int libfwsi_network_location_get_utf16_comments_size(
     libfwsi_item_t *network_location,
     size_t *utf16_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item                     = NULL;
	libfwsi_network_location_values_t *network_location_values = NULL;
	static char *function                                      = "libfwsi_network_location_get_utf16_comments_size";

	if( network_location == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid network location.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) network_location;

	if( internal_item->type != LIBFWSI_ITEM_TYPE_NETWORK_LOCATION )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported item type.",
		 function );

		return( -1 );
	}
	if( internal_item->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid network location - missing value.",
		 function );

		return( -1 );
	}
	network_location_values = (libfwsi_network_location_values_t *) internal_item->value;

	if( ( network_location_values->comments == NULL )
	 || ( network_location_values->comments_size == 0 ) )
	{
		return( 0 );
	}
	if( libuna_utf16_string_size_from_byte_stream(
	     network_location_values->comments,
	     network_location_values->comments_size,
	     network_location_values->ascii_codepage,
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

/* Retrieves the UTF-16 formatted comments
 * Returns 1 if successful, 0 if not available or -1 on error
 */
int libfwsi_network_location_get_utf16_comments(
     libfwsi_item_t *network_location,
     uint16_t *utf16_string,
     size_t utf16_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item                     = NULL;
	libfwsi_network_location_values_t *network_location_values = NULL;
	static char *function                                      = "libfwsi_network_location_get_utf16_comments";

	if( network_location == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid network location.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) network_location;

	if( internal_item->type != LIBFWSI_ITEM_TYPE_NETWORK_LOCATION )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported item type.",
		 function );

		return( -1 );
	}
	if( internal_item->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid network location - missing value.",
		 function );

		return( -1 );
	}
	network_location_values = (libfwsi_network_location_values_t *) internal_item->value;

	if( ( network_location_values->comments == NULL )
	 || ( network_location_values->comments_size == 0 ) )
	{
		return( 0 );
	}
	if( libuna_utf16_string_copy_from_byte_stream(
	     utf16_string,
	     utf16_string_size,
	     network_location_values->comments,
	     network_location_values->comments_size,
	     network_location_values->ascii_codepage,
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

