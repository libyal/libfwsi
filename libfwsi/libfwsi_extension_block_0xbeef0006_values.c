/*
 * Extension block 0xbeef0006 values functions
 *
 * Copyright (C) 2010-2015, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <byte_stream.h>
#include <memory.h>
#include <types.h>

#include "libfwsi_definitions.h"
#include "libfwsi_extension_block_0xbeef0006_values.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"
#include "libfwsi_libuna.h"

/* Creates extension block 0xbeef0006 values
 * Make sure the value extension_block_0xbeef0006_values is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_extension_block_0xbeef0006_values_initialize(
     libfwsi_extension_block_0xbeef0006_values_t **extension_block_0xbeef0006_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_extension_block_0xbeef0006_values_initialize";

	if( extension_block_0xbeef0006_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block 0xbeef0006 values.",
		 function );

		return( -1 );
	}
	if( *extension_block_0xbeef0006_values != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid extension block 0xbeef0006 values value already set.",
		 function );

		return( -1 );
	}
	*extension_block_0xbeef0006_values = memory_allocate_structure(
	                                      libfwsi_extension_block_0xbeef0006_values_t );

	if( *extension_block_0xbeef0006_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create extension block 0xbeef0006 values.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *extension_block_0xbeef0006_values,
	     0,
	     sizeof( libfwsi_extension_block_0xbeef0006_values_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear extension block 0xbeef0006 values.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *extension_block_0xbeef0006_values != NULL )
	{
		memory_free(
		 *extension_block_0xbeef0006_values );

		*extension_block_0xbeef0006_values = NULL;
	}
	return( -1 );
}

/* Frees extension block 0xbeef0006 values
 * Returns 1 if successful or -1 on error
 */
int libfwsi_extension_block_0xbeef0006_values_free(
     libfwsi_extension_block_0xbeef0006_values_t **extension_block_0xbeef0006_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_extension_block_0xbeef0006_values_free";

	if( extension_block_0xbeef0006_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block 0xbeef0006 values.",
		 function );

		return( -1 );
	}
	if( *extension_block_0xbeef0006_values != NULL )
	{
		memory_free(
		 *extension_block_0xbeef0006_values );

		*extension_block_0xbeef0006_values = NULL;
	}
	return( 1 );
}

/* Reads the extension block 0xbeef0006 values
 * Returns the number of bytes read or -1 on error
 */
ssize_t libfwsi_extension_block_0xbeef0006_values_read(
         libfwsi_extension_block_0xbeef0006_values_t *extension_block_0xbeef0006_values,
         const uint8_t *extension_block_data,
         size_t extension_block_data_size,
         libcerror_error_t **error )
{
	static char *function                       = "libfwsi_extension_block_0xbeef0006_values_read";
	size_t extension_block_data_offset          = 0;
	size_t string_size                          = 0;
	uint32_t signature                          = 0;

#if defined( HAVE_DEBUG_OUTPUT )
	libcstring_system_character_t *value_string = NULL;
	size_t value_string_size                    = 0;
	int result                                  = 0;
#endif

	if( extension_block_0xbeef0006_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block 0xbeef0006 values.",
		 function );

		return( -1 );
	}
	if( extension_block_data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block data.",
		 function );

		return( -1 );
	}
	if( extension_block_data_size > (size_t) SSIZE_MAX )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: extension block data size exceeds maximum.",
		 function );

		return( -1 );
	}
	/* Do not try to parse unsupported extension block data sizes
	 */
	if( extension_block_data_size < 12 )
	{
		return( 0 );
	}
	/* Do not try to parse unsupported extension block signatures
	 */
	byte_stream_copy_to_uint32_little_endian(
	 &( extension_block_data[ 4 ] ),
	 signature );

	if( signature != 0xbeef0006 )
	{
		return( 0 );
	}
	extension_block_data_offset = 8;

	for( string_size = extension_block_data_offset;
	     ( string_size + 1 ) < extension_block_data_size - 2;
	     string_size += 2 )
	{
		if( ( extension_block_data[ string_size ] == 0 )
		 && ( extension_block_data[ string_size + 1 ] == 0 ) )
		{
			string_size += 2;

			break;
		}
	}
	string_size -= extension_block_data_offset;

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
		result = libuna_utf16_string_size_from_utf16_stream(
			  &( extension_block_data[ extension_block_data_offset ] ),
			  string_size,
			  LIBUNA_ENDIAN_LITTLE,
			  &value_string_size,
			  error );
#else
		result = libuna_utf8_string_size_from_utf16_stream(
			  &( extension_block_data[ extension_block_data_offset ] ),
			  string_size,
			  LIBUNA_ENDIAN_LITTLE,
			  &value_string_size,
			  error );
#endif
		if( result != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
			 "%s: unable to determine size of username string.",
			 function );

			goto on_error;
		}
		if( value_string_size > (size_t) ( SSIZE_MAX / sizeof( libcstring_system_character_t ) ) )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_VALUE_EXCEEDS_MAXIMUM,
			 "%s: invalid username string size value exceeds maximum.",
			 function );

			goto on_error;
		}
		value_string = libcstring_system_string_allocate(
				value_string_size );

		if( value_string == NULL )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_MEMORY,
			 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
			 "%s: unable to create username string.",
			 function );

			goto on_error;
		}
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
		result = libuna_utf16_string_copy_from_utf16_stream(
			  (libuna_utf16_character_t *) value_string,
			  value_string_size,
			  &( extension_block_data[ extension_block_data_offset ] ),
			  string_size,
			  LIBUNA_ENDIAN_LITTLE,
			  error );
#else
		result = libuna_utf8_string_copy_from_utf16_stream(
			  (libuna_utf8_character_t *) value_string,
			  value_string_size,
			  &( extension_block_data[ extension_block_data_offset ] ),
			  string_size,
			  LIBUNA_ENDIAN_LITTLE,
			  error );
#endif
		if( result != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
			 "%s: unable to set username string.",
			 function );

			goto on_error;
		}
		libcnotify_printf(
		 "%s: username\t\t\t: %" PRIs_LIBCSTRING_SYSTEM "\n",
		 function,
		 value_string );

		memory_free(
		 value_string );

		value_string = NULL;
	}
#endif
	extension_block_data_offset += string_size;

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "\n" );
	}
#endif
	return( (ssize_t) extension_block_data_offset );

on_error:
#if defined( HAVE_DEBUG_OUTPUT )
	if( value_string != NULL )
	{
		memory_free(
		 value_string );
	}
#endif
	return( -1 );
}

