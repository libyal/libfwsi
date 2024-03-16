/*
 * Control panel item (shell item) values functions
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
#include <byte_stream.h>
#include <memory.h>
#include <types.h>

#include "libfwsi_control_panel_identifier.h"
#include "libfwsi_control_panel_item_values.h"
#include "libfwsi_debug.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"
#include "libfwsi_libfguid.h"

/* Creates control panel item values
 * Make sure the value control_panel_item_values is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_control_panel_item_values_initialize(
     libfwsi_control_panel_item_values_t **control_panel_item_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_control_panel_item_values_initialize";

	if( control_panel_item_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid control panel item values.",
		 function );

		return( -1 );
	}
	if( *control_panel_item_values != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid control panel item values value already set.",
		 function );

		return( -1 );
	}
	*control_panel_item_values = memory_allocate_structure(
	                              libfwsi_control_panel_item_values_t );

	if( *control_panel_item_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create control panel item values.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *control_panel_item_values,
	     0,
	     sizeof( libfwsi_control_panel_item_values_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear control panel item values.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *control_panel_item_values != NULL )
	{
		memory_free(
		 *control_panel_item_values );

		*control_panel_item_values = NULL;
	}
	return( -1 );
}

/* Frees control panel item values
 * Returns 1 if successful or -1 on error
 */
int libfwsi_control_panel_item_values_free(
     libfwsi_control_panel_item_values_t **control_panel_item_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_control_panel_item_values_free";

	if( control_panel_item_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid control panel item values.",
		 function );

		return( -1 );
	}
	if( *control_panel_item_values != NULL )
	{
		memory_free(
		 *control_panel_item_values );

		*control_panel_item_values = NULL;
	}
	return( 1 );
}

/* Reads the control panel item values
 * Returns 1 if successful, 0 if not supported or -1 on error
 */
int libfwsi_control_panel_item_values_read_data(
     libfwsi_control_panel_item_values_t *control_panel_item_values,
     const uint8_t *data,
     size_t data_size,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_control_panel_item_values_read_data";

	if( control_panel_item_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid control panel item values.",
		 function );

		return( -1 );
	}
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
	if( data_size > (size_t) SSIZE_MAX )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: data size exceeds maximum.",
		 function );

		return( -1 );
	}
	/* Do not try to parse unsupported data sizes
	 */
	if( data_size < 30 )
	{
		return( 0 );
	}
	/* Do not try to parse unsupported data
	 */
	if( data[ 2 ] != 0x71 )
	{
		return( 0 );
	}
	if( memory_copy(
	     control_panel_item_values->identifier,
	     &( data[ 14 ] ),
	     16 ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_COPY_FAILED,
		 "%s: unable to copy control panel identifier.",
		 function );

		return( -1 );
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: unknown1\t\t\t: 0x%02" PRIx8 "\n",
		 function,
		 data[ 3 ] );

		libcnotify_printf(
		 "%s: unknown2:\n",
		 function );
		libcnotify_print_data(
		 &( data[ 4 ] ),
		 10,
		 0 );

		if( libfwsi_debug_print_guid_value(
		     function,
		     "control panel identifier\t",
		     control_panel_item_values->identifier,
		     16,
		     LIBFGUID_ENDIAN_LITTLE,
		     LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_PRINT_FAILED,
			 "%s: unable to print GUID value.",
			 function );

			return( -1 );
		}
		libcnotify_printf(
		 "%s: control panel name\t\t: %s\n",
		 function,
		 libfwsi_control_panel_identifier_get_name(
		  control_panel_item_values->identifier ) );

		libcnotify_printf(
		 "\n" );
	}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

	return( 1 );
}

/* Retrieves the identifier
 * The identifier is a GUID and is 16 bytes of size
 * Returns 1 if successful or -1 on error
 */
int libfwsi_control_panel_item_values_get_identifier(
     libfwsi_control_panel_item_values_t *control_panel_item_values,
     uint8_t *guid_data,
     size_t guid_data_size,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_control_panel_item_values_get_identifier";

	if( control_panel_item_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid control panel item values.",
		 function );

		return( -1 );
	}
	if( guid_data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid GUID data.",
		 function );

		return( -1 );
	}
	if( guid_data_size < 16 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_TOO_SMALL,
		 "%s: GUID data size too small.",
		 function );

		return( -1 );
	}
	if( memory_copy(
	     guid_data,
	     control_panel_item_values->identifier,
	     16 ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_COPY_FAILED,
		 "%s: unable to copy identifier.",
		 function );

		return( -1 );
	}
	return( 1 );
}

