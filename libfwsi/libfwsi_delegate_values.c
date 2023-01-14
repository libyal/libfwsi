/*
 * Delegate (shell item) values functions
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

#include <common.h>
#include <byte_stream.h>
#include <memory.h>
#include <types.h>

#include "libfwsi_debug.h"
#include "libfwsi_definitions.h"
#include "libfwsi_delegate_values.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"
#include "libfwsi_libfguid.h"
#include "libfwsi_libuna.h"
#include "libfwsi_shell_folder_identifier.h"

const uint8_t libfwsi_delegate_item_identifier[ 16 ] = {
        0x74, 0x1a, 0x59, 0x5e, 0x96, 0xdf, 0xd3, 0x48, 0x8d, 0x67, 0x17, 0x33, 0xbc, 0xee, 0x28, 0xba };

/* Creates delegate values
 * Make sure the value delegate_values is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_delegate_values_initialize(
     libfwsi_delegate_values_t **delegate_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_delegate_values_initialize";

	if( delegate_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid delegate values.",
		 function );

		return( -1 );
	}
	if( *delegate_values != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid delegate values value already set.",
		 function );

		return( -1 );
	}
	*delegate_values = memory_allocate_structure(
	                    libfwsi_delegate_values_t );

	if( *delegate_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create delegate values.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *delegate_values,
	     0,
	     sizeof( libfwsi_delegate_values_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear delegate values.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *delegate_values != NULL )
	{
		memory_free(
		 *delegate_values );

		*delegate_values = NULL;
	}
	return( -1 );
}

/* Frees delegate values
 * Returns 1 if successful or -1 on error
 */
int libfwsi_delegate_values_free(
     libfwsi_delegate_values_t **delegate_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_delegate_values_free";

	if( delegate_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid delegate values.",
		 function );

		return( -1 );
	}
	if( *delegate_values != NULL )
	{
		memory_free(
		 *delegate_values );

		*delegate_values = NULL;
	}
	return( 1 );
}

/* Reads the delegate values
 * Returns 1 if successful, 0 if not supported or -1 on error
 */
int libfwsi_delegate_values_read_data(
     libfwsi_delegate_values_t *delegate_values,
     const uint8_t *data,
     size_t data_size,
     libcerror_error_t **error )
{
	static char *function   = "libfwsi_delegate_values_read_data";
	size_t data_offset      = 0;
	uint16_t item_data_size = 0;

	if( delegate_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid delegate values.",
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
	if( data_size < 38 )
	{
		return( 0 );
	}
	/* Do not try to parse unknown class type indicators
	 */
	if( memory_compare(
	     &( data[ data_size - 32 ] ),
	     libfwsi_delegate_item_identifier,
	     16 ) != 0 )
	{
		return( 0 );
	}
	byte_stream_copy_to_uint32_little_endian(
	 &( data[ 4 ] ),
	 item_data_size );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: class type indicator\t\t\t: 0x%02" PRIx8 "\n",
		 function,
		 data[ 2 ] );

		libcnotify_printf(
		 "%s: unknown1\t\t\t\t: 0x%02" PRIx8 "\n",
		 function,
		 data[ 3 ] );

		libcnotify_printf(
		 "%s: delegate item data size\t\t: %" PRIu16 "\n",
		 function,
		 item_data_size );
	}
#endif
	data_offset = 6;

	if( item_data_size > 0 )
	{
		if( item_data_size > ( data_size - 32 ) )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
			 "%s: invalid data size value out of bounds.",
			 function );

			return( -1 );
		}
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			libcnotify_printf(
			 "%s: delegate item data:\n",
			 function );
			libcnotify_print_data(
			 &( data[ 6 ] ),
			 item_data_size,
			 LIBCNOTIFY_PRINT_DATA_FLAG_GROUP_DATA );
		}
#endif
		data_offset += item_data_size;
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		if( libfwsi_debug_print_guid_value(
		     function,
		     "delegate item class identifier\t",
		     &( data[ data_offset ] ),
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
	}
#endif
	data_offset += 16;

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		if( libfwsi_debug_print_guid_value(
		     function,
		     "item class identifier\t\t",
		     &( data[ data_offset ] ),
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
		 "%s: shell folder name\t\t\t: %s\n",
		 function,
		 libfwsi_shell_folder_identifier_get_name(
		  &( data[ data_offset ] ) ) );

		libcnotify_printf(
		 "\n" );
	}
#endif
	data_offset += 16;

	return( 1 );
}

