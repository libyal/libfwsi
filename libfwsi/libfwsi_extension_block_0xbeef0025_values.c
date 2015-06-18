/*
 * Extension block 0xbeef0025 values functions
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
#include "libfwsi_extension_block_0xbeef0025_values.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"
#include "libfwsi_libfdatetime.h"

/* Creates extension block 0xbeef0025 values
 * Make sure the value extension_block_0xbeef0025_values is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_extension_block_0xbeef0025_values_initialize(
     libfwsi_extension_block_0xbeef0025_values_t **extension_block_0xbeef0025_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_extension_block_0xbeef0025_values_initialize";

	if( extension_block_0xbeef0025_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block 0xbeef0025 values.",
		 function );

		return( -1 );
	}
	if( *extension_block_0xbeef0025_values != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid extension block 0xbeef0025 values value already set.",
		 function );

		return( -1 );
	}
	*extension_block_0xbeef0025_values = memory_allocate_structure(
	                                      libfwsi_extension_block_0xbeef0025_values_t );

	if( *extension_block_0xbeef0025_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create extension block 0xbeef0025 values.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *extension_block_0xbeef0025_values,
	     0,
	     sizeof( libfwsi_extension_block_0xbeef0025_values_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear extension block 0xbeef0025 values.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *extension_block_0xbeef0025_values != NULL )
	{
		memory_free(
		 *extension_block_0xbeef0025_values );

		*extension_block_0xbeef0025_values = NULL;
	}
	return( -1 );
}

/* Frees extension block 0xbeef0025 values
 * Returns 1 if successful or -1 on error
 */
int libfwsi_extension_block_0xbeef0025_values_free(
     libfwsi_extension_block_0xbeef0025_values_t **extension_block_0xbeef0025_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_extension_block_0xbeef0025_values_free";

	if( extension_block_0xbeef0025_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block 0xbeef0025 values.",
		 function );

		return( -1 );
	}
	if( *extension_block_0xbeef0025_values != NULL )
	{
		memory_free(
		 *extension_block_0xbeef0025_values );

		*extension_block_0xbeef0025_values = NULL;
	}
	return( 1 );
}

/* Reads the extension block 0xbeef0025 values
 * Returns the number of bytes read or -1 on error
 */
ssize_t libfwsi_extension_block_0xbeef0025_values_read(
         libfwsi_extension_block_0xbeef0025_values_t *extension_block_0xbeef0025_values,
         const uint8_t *extension_block_data,
         size_t extension_block_data_size,
         libcerror_error_t **error )
{
	static char *function             = "libfwsi_extension_block_0xbeef0025_values_read";
	uint32_t signature                = 0;

#if defined( HAVE_DEBUG_OUTPUT )
	libcstring_system_character_t date_time_string[ 32 ];

	libfdatetime_filetime_t *filetime = NULL;
	uint32_t value_32bit              = 0;
	int result                        = 0;
#endif

	if( extension_block_0xbeef0025_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block 0xbeef0025 values.",
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
	if( extension_block_data_size != 30 )
	{
		return( 0 );
	}
	/* Do not try to parse unsupported extension block signatures
	 */
	byte_stream_copy_to_uint32_little_endian(
	 &( extension_block_data[ 4 ] ),
	 signature );

	if( signature != 0xbeef0025 )
	{
		return( 0 );
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		byte_stream_copy_to_uint32_little_endian(
		 &( extension_block_data[ 8 ] ),
		 value_32bit );
		libcnotify_printf(
		 "%s: unknown1\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

		if( libfdatetime_filetime_initialize(
		     &filetime,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
			 "%s: unable to create filetime.",
			 function );

			goto on_error;
		}
		if( libfdatetime_filetime_copy_from_byte_stream(
		     filetime,
		     &( extension_block_data[ 12 ] ),
		     8,
		     LIBFDATETIME_ENDIAN_LITTLE,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
			 "%s: unable to copy byte stream to filetime.",
			 function );

			goto on_error;
		}
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
		result = libfdatetime_filetime_copy_to_utf16_string(
			  filetime,
			  (uint16_t *) date_time_string,
			  32,
			  LIBFDATETIME_STRING_FORMAT_TYPE_CTIME | LIBFDATETIME_STRING_FORMAT_FLAG_DATE_TIME_NANO_SECONDS,
			  error );
#else
		result = libfdatetime_filetime_copy_to_utf8_string(
			  filetime,
			  (uint8_t *) date_time_string,
			  32,
			  LIBFDATETIME_STRING_FORMAT_TYPE_CTIME | LIBFDATETIME_STRING_FORMAT_FLAG_DATE_TIME_NANO_SECONDS,
			  error );
#endif
		if( result != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
			 "%s: unable to copy filetime to string.",
			 function );

			goto on_error;
		}
		libcnotify_printf(
		 "%s: unknown2 time\t\t: %" PRIs_LIBCSTRING_SYSTEM " UTC\n",
		 function,
		 date_time_string );

		if( libfdatetime_filetime_copy_from_byte_stream(
		     filetime,
		     &( extension_block_data[ 20 ] ),
		     8,
		     LIBFDATETIME_ENDIAN_LITTLE,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
			 "%s: unable to copy byte stream to filetime.",
			 function );

			goto on_error;
		}
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
		result = libfdatetime_filetime_copy_to_utf16_string(
			  filetime,
			  (uint16_t *) date_time_string,
			  32,
			  LIBFDATETIME_STRING_FORMAT_TYPE_CTIME | LIBFDATETIME_STRING_FORMAT_FLAG_DATE_TIME_NANO_SECONDS,
			  error );
#else
		result = libfdatetime_filetime_copy_to_utf8_string(
			  filetime,
			  (uint8_t *) date_time_string,
			  32,
			  LIBFDATETIME_STRING_FORMAT_TYPE_CTIME | LIBFDATETIME_STRING_FORMAT_FLAG_DATE_TIME_NANO_SECONDS,
			  error );
#endif
		if( result != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
			 "%s: unable to copy filetime to string.",
			 function );

			goto on_error;
		}
		libcnotify_printf(
		 "%s: unknown3 time\t\t: %" PRIs_LIBCSTRING_SYSTEM " UTC\n",
		 function,
		 date_time_string );

		if( libfdatetime_filetime_free(
		     &filetime,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
			 "%s: unable to free filetime.",
			 function );

			goto on_error;
		}
		libcnotify_printf(
		 "\n" );
	}
#endif
	return( 28 );

on_error:
#if defined( HAVE_DEBUG_OUTPUT )
	if( filetime != NULL )
	{
		libfdatetime_filetime_free(
		 &filetime,
		 NULL );
	}
#endif
	return( -1 );
}

