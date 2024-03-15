/*
 * Compressed folder (shell item) values functions
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

#include "libfwsi_compressed_folder_values.h"
#include "libfwsi_debug.h"
#include "libfwsi_definitions.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"
#include "libfwsi_libfdatetime.h"
#include "libfwsi_libuna.h"
#include "libfwsi_unused.h"

/* Creates compressed folder values
 * Make sure the value compressed_folder_values is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_compressed_folder_values_initialize(
     libfwsi_compressed_folder_values_t **compressed_folder_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_compressed_folder_values_initialize";

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
	if( *compressed_folder_values != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid compressed folder values value already set.",
		 function );

		return( -1 );
	}
	*compressed_folder_values = memory_allocate_structure(
	                             libfwsi_compressed_folder_values_t );

	if( *compressed_folder_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create compressed folder values.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *compressed_folder_values,
	     0,
	     sizeof( libfwsi_compressed_folder_values_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear compressed folder values.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *compressed_folder_values != NULL )
	{
		memory_free(
		 *compressed_folder_values );

		*compressed_folder_values = NULL;
	}
	return( -1 );
}

/* Frees compressed folder values
 * Returns 1 if successful or -1 on error
 */
int libfwsi_compressed_folder_values_free(
     libfwsi_compressed_folder_values_t **compressed_folder_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_compressed_folder_values_free";

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
	if( *compressed_folder_values != NULL )
	{
		memory_free(
		 *compressed_folder_values );

		*compressed_folder_values = NULL;
	}
	return( 1 );
}

/* Reads the compressed folder values
 * Returns 1 if successful, 0 if not supported or -1 on error
 */
int libfwsi_compressed_folder_values_read_data(
     libfwsi_compressed_folder_values_t *compressed_folder_values,
     const uint8_t *data,
     size_t data_size,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_compressed_folder_values_read_data";
	size_t data_offset    = 0;

#if defined( HAVE_DEBUG_OUTPUT )
	uint64_t value_64bit  = 0;
	uint32_t value_32bit  = 0;
	uint16_t value_16bit  = 0;
#endif

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
	if( data_size < 68 )
	{
		return( 0 );
	}
	/* Do not try to parse unknown class type indicators
	 */
	if( ( data[ 28 ] == (uint8_t) '/' )
	 && ( data[ 29 ] == (uint8_t) 0 )
	 && ( data[ 34 ] == (uint8_t) '/' )
	 && ( data[ 35 ] == (uint8_t) 0 )
	 && ( data[ 40 ] == (uint8_t) ' ' )
	 && ( data[ 41 ] == (uint8_t) 0 )
	 && ( data[ 42 ] == (uint8_t) ' ' )
	 && ( data[ 43 ] == (uint8_t) 0 )
	 && ( data[ 48 ] == (uint8_t) ':' )
	 && ( data[ 49 ] == (uint8_t) 0 )
	 && ( data[ 54 ] == (uint8_t) 0 )
	 && ( data[ 55 ] == (uint8_t) 0 ) )
	{
		/* Windows XP compressed folder */

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			byte_stream_copy_to_uint16_little_endian(
			 &( data[ 2 ] ),
			 value_16bit );
			libcnotify_printf(
			 "%s: unknown1\t\t\t: 0x%04" PRIx16 "\n",
			 function,
			 value_16bit );

			libcnotify_printf(
			 "%s: unknown2:\n",
			 function );
			libcnotify_print_data(
			 &( data[ 4 ] ),
			 16,
			 0 );

			byte_stream_copy_to_uint16_little_endian(
			 &( data[ 20 ] ),
			 value_16bit );
			libcnotify_printf(
			 "%s: unknown3\t\t\t: 0x%04" PRIx16 "\n",
			 function,
			 value_16bit );

			byte_stream_copy_to_uint16_little_endian(
			 &( data[ 22 ] ),
			 value_16bit );
			libcnotify_printf(
			 "%s: unknown3\t\t\t: 0x%04" PRIx16 "\n",
			 function,
			 value_16bit );

			libcnotify_printf(
			 "%s: unknown4:\n",
			 function );
			libcnotify_print_data(
			 &( data[ 24 ] ),
			 32,
			 0 );

			byte_stream_copy_to_uint16_little_endian(
			 &( data[ 56 ] ),
			 value_16bit );
			libcnotify_printf(
			 "%s: unknown5\t\t\t: 0x%04" PRIx16 "\n",
			 function,
			 value_16bit );

			byte_stream_copy_to_uint16_little_endian(
			 &( data[ 58 ] ),
			 value_16bit );
			libcnotify_printf(
			 "%s: unknown6\t\t\t: 0x%04" PRIx16 "\n",
			 function,
			 value_16bit );

			byte_stream_copy_to_uint32_little_endian(
			 &( data[ 60 ] ),
			 value_32bit );
			libcnotify_printf(
			 "%s: string1 data size\t\t: %" PRIu32 "\n",
			 function,
			 value_32bit );

			byte_stream_copy_to_uint32_little_endian(
			 &( data[ 64 ] ),
			 value_32bit );
			libcnotify_printf(
			 "%s: string2 data size\t\t: %" PRIu32 "\n",
			 function,
			 value_32bit );
		}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

		data_offset = 68;
	}
	else if( ( data[ 36 ] == (uint8_t) 'N' )
	      && ( data[ 37 ] == (uint8_t) 0 )
	      && ( data[ 38 ] == (uint8_t) '/' )
	      && ( data[ 39 ] == (uint8_t) 0 )
	      && ( data[ 40 ] == (uint8_t) 'A' )
	      && ( data[ 41 ] == (uint8_t) 0 )
	      && ( data[ 42 ] == (uint8_t) 0 )
	      && ( data[ 43 ] == (uint8_t) 0 ) )
	{
		/* Windows 10 compressed folder */
	}
	else
	{
		return( 0 );
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		if( data_offset < data_size )
		{
			libcnotify_printf(
			 "%s: trailing data:\n",
			 function );
			libcnotify_print_data(
			 &( data[ data_offset ] ),
			 data_size - data_offset,
			 LIBCNOTIFY_PRINT_DATA_FLAG_GROUP_DATA );
		}
		else
		{
			libcnotify_printf(
			 "\n" );
		}
	}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

	return( 1 );
}

