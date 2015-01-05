/*
 * Extension block 0xbeef0000 values functions
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
#include "libfwsi_extension_block_0xbeef0000_values.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"
#include "libfwsi_libfguid.h"

/* Creates extension block 0xbeef0000 values
 * Make sure the value extension_block_0xbeef0000_values is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_extension_block_0xbeef0000_values_initialize(
     libfwsi_extension_block_0xbeef0000_values_t **extension_block_0xbeef0000_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_extension_block_0xbeef0000_values_initialize";

	if( extension_block_0xbeef0000_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block 0xbeef0000 values.",
		 function );

		return( -1 );
	}
	if( *extension_block_0xbeef0000_values != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid extension block 0xbeef0000 values value already set.",
		 function );

		return( -1 );
	}
	*extension_block_0xbeef0000_values = memory_allocate_structure(
	                                      libfwsi_extension_block_0xbeef0000_values_t );

	if( *extension_block_0xbeef0000_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create extension block 0xbeef0000 values.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *extension_block_0xbeef0000_values,
	     0,
	     sizeof( libfwsi_extension_block_0xbeef0000_values_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear extension block 0xbeef0000 values.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *extension_block_0xbeef0000_values != NULL )
	{
		memory_free(
		 *extension_block_0xbeef0000_values );

		*extension_block_0xbeef0000_values = NULL;
	}
	return( -1 );
}

/* Frees extension block 0xbeef0000 values
 * Returns 1 if successful or -1 on error
 */
int libfwsi_extension_block_0xbeef0000_values_free(
     libfwsi_extension_block_0xbeef0000_values_t **extension_block_0xbeef0000_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_extension_block_0xbeef0000_values_free";

	if( extension_block_0xbeef0000_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block 0xbeef0000 values.",
		 function );

		return( -1 );
	}
	if( *extension_block_0xbeef0000_values != NULL )
	{
		memory_free(
		 *extension_block_0xbeef0000_values );

		*extension_block_0xbeef0000_values = NULL;
	}
	return( 1 );
}

/* Reads the extension block 0xbeef0000 values
 * Returns the number of bytes read or -1 on error
 */
ssize_t libfwsi_extension_block_0xbeef0000_values_read(
         libfwsi_extension_block_0xbeef0000_values_t *extension_block_0xbeef0000_values,
         const uint8_t *extension_block_data,
         size_t extension_block_data_size,
         libcerror_error_t **error )
{
	static char *function              = "libfwsi_extension_block_0xbeef0000_values_read";
	size_t extension_block_data_offset = 0;
	uint32_t signature                 = 0;

#if defined( HAVE_DEBUG_OUTPUT )
        libcstring_system_character_t guid_string[ 48 ];

        libfguid_identifier_t *guid        = NULL;
	uint32_t value_32bit               = 0;
	int result                         = 0;
#endif

	if( extension_block_0xbeef0000_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block 0xbeef0000 values.",
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
	if( ( extension_block_data_size != 14 )
	 && ( extension_block_data_size != 42 ) )
	{
		return( 0 );
	}
	/* Do not try to parse unsupported extension block signatures
	 */
	byte_stream_copy_to_uint32_little_endian(
	 &( extension_block_data[ 4 ] ),
	 signature );

	if( signature != 0xbeef0000 )
	{
		return( 0 );
	}
	if( extension_block_data_size == 14 )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			byte_stream_copy_to_uint16_little_endian(
			 &( extension_block_data[ 8 ] ),
			 value_32bit );
			libcnotify_printf(
			 "%s: unknown1\t\t\t\t\t: 0x%08" PRIx32 "\n",
			 function,
			 value_32bit );
		}
#endif
		extension_block_data_offset = 12;
	}
	else if( extension_block_data_size == 42 )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( libfguid_identifier_initialize(
			     &guid,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create GUID.",
				 function );

				goto on_error;
			}
			if( libfguid_identifier_copy_from_byte_stream(
			     guid,
			     &( extension_block_data[ 8 ] ),
			     16,
			     LIBFGUID_ENDIAN_LITTLE,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
				 "%s: unable to copy byte stream to GUID.",
				 function );

				goto on_error;
			}
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
			result = libfguid_identifier_copy_to_utf16_string(
				  guid,
				  (uint16_t *) guid_string,
				  48,
				  LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
				  error );
#else
			result = libfguid_identifier_copy_to_utf8_string(
				  guid,
				  (uint8_t *) guid_string,
				  48,
				  LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
				  error );
#endif
			if( result != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
				 "%s: unable to copy GUID to string.",
				 function );

				goto on_error;
			}
			libcnotify_printf(
			 "%s: folder type identifier\t: %" PRIs_LIBCSTRING_SYSTEM "\n",
			 function,
			 guid_string );

			if( libfguid_identifier_copy_from_byte_stream(
			     guid,
			     &( extension_block_data[ 24 ] ),
			     16,
			     LIBFGUID_ENDIAN_LITTLE,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
				 "%s: unable to copy byte stream to GUID.",
				 function );

				goto on_error;
			}
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
			result = libfguid_identifier_copy_to_utf16_string(
				  guid,
				  (uint16_t *) guid_string,
				  48,
				  LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
				  error );
#else
			result = libfguid_identifier_copy_to_utf8_string(
				  guid,
				  (uint8_t *) guid_string,
				  48,
				  LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
				  error );
#endif
			if( result != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
				 "%s: unable to copy GUID to string.",
				 function );

				goto on_error;
			}
			libcnotify_printf(
			 "%s: unknown identifier\t: %" PRIs_LIBCSTRING_SYSTEM "\n",
			 function,
			 guid_string );

			if( libfguid_identifier_free(
			     &guid,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
				 "%s: unable to free GUID.",
				 function );

				goto on_error;
			}
		}
#endif
		extension_block_data_offset = 40;
	}
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
	if( guid != NULL )
	{
		libfguid_identifier_free(
		 &guid,
		 NULL );
	}
#endif
	return( -1 );
}

