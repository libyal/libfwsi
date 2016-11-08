/*
 * Compressed folder (shell item) values functions
 *
 * Copyright (C) 2010-2016, Joachim Metz <joachim.metz@gmail.com>
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
 * Returns the number of bytes read if successful, 0 if not able to read or -1 on error
 */
ssize_t libfwsi_compressed_folder_values_read(
         libfwsi_compressed_folder_values_t *compressed_folder_values,
         const uint8_t *shell_item_data,
         size_t shell_item_data_size,
         libcerror_error_t **error )
{
	static char *function         = "libfwsi_compressed_folder_values_read";
	size_t shell_item_data_offset = 0;
	uint32_t string_size          = 0;

#if defined( HAVE_DEBUG_OUTPUT )
	uint64_t value_64bit          = 0;
	uint32_t value_32bit          = 0;
	uint16_t value_16bit          = 0;
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
	if( shell_item_data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid shell item data.",
		 function );

		return( -1 );
	}
	if( shell_item_data_size > (size_t) SSIZE_MAX )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: shell item data size exceeds maximum.",
		 function );

		return( -1 );
	}
	/* Do not try to parse unsupported shell item data sizes
	 */
	if( shell_item_data_size < 6 )
	{
		return( 0 );
	}
	/* Do not try to parse unknown class type indicators
	 */
	if( shell_item_data[ 2 ] != 0x52 )
	{
		return( 0 );
	}
/* TODO: other variants not supported yet */
	if( ( shell_item_data[ 3 ] != 0x67 )
	 || ( shell_item_data[ 4 ] != 0xb1 )
	 || ( shell_item_data[ 5 ] != 0xac ) )
	{
		return( 0 );
	}
	if( ( shell_item_data[ 3 ] == 0x67 )
	 && ( shell_item_data[ 4 ] == 0xb1 )
	 && ( shell_item_data[ 5 ] == 0xac ) )
	{
		if( shell_item_data_size < 50 )
		{
			return( 0 );
		}
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			libcnotify_printf(
			 "%s: unknown1\t\t\t\t: 0x%02" PRIx8 "\n",
			 function,
			 shell_item_data[ 3 ] );

			byte_stream_copy_to_uint16_little_endian(
			 &( shell_item_data[ 4 ] ),
			 value_16bit );
			libcnotify_printf(
			 "%s: unknown2\t\t\t\t: 0x%04" PRIx16 "\n",
			 function,
			 value_16bit );

			byte_stream_copy_to_uint32_little_endian(
			 &( shell_item_data[ 6 ] ),
			 value_32bit );
			libcnotify_printf(
			 "%s: unknown3\t\t\t\t: 0x%08" PRIx32 "\n",
			 function,
			 value_32bit );

			byte_stream_copy_to_uint64_little_endian(
			 &( shell_item_data[ 10 ] ),
			 value_64bit );
			libcnotify_printf(
			 "%s: unknown4\t\t\t\t: 0x%08" PRIx64 "\n",
			 function,
			 value_64bit );

			byte_stream_copy_to_uint32_little_endian(
			 &( shell_item_data[ 18 ] ),
			 value_32bit );
			libcnotify_printf(
			 "%s: unknown5\t\t\t\t: 0x%08" PRIx32 "\n",
			 function,
			 value_32bit );

			byte_stream_copy_to_uint32_little_endian(
			 &( shell_item_data[ 22 ] ),
			 value_32bit );
			libcnotify_printf(
			 "%s: unknown6\t\t\t\t: 0x%08" PRIx32 "\n",
			 function,
			 value_32bit );

			if( libfwsi_debug_print_fat_date_time_value(
			     function,
			     "unknown time1\t\t\t",
			     &( shell_item_data[ 26 ] ),
			     4,
			     LIBFDATETIME_ENDIAN_LITTLE,
			     LIBFDATETIME_STRING_FORMAT_TYPE_CTIME | LIBFDATETIME_STRING_FORMAT_FLAG_DATE_TIME,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_PRINT_FAILED,
				 "%s: unable to print FAT date time value.",
				 function );

				return( -1 );
			}
			byte_stream_copy_to_uint32_little_endian(
			 &( shell_item_data[ 30 ] ),
			 value_32bit );
			libcnotify_printf(
			 "%s: unknown7\t\t\t\t: 0x%08" PRIx32 "\n",
			 function,
			 value_32bit );

			if( libfwsi_debug_print_fat_date_time_value(
			     function,
			     "unknown time2\t\t\t",
			     &( shell_item_data[ 34 ] ),
			     4,
			     LIBFDATETIME_ENDIAN_LITTLE,
			     LIBFDATETIME_STRING_FORMAT_TYPE_CTIME | LIBFDATETIME_STRING_FORMAT_FLAG_DATE_TIME,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_PRINT_FAILED,
				 "%s: unable to print FAT date time value.",
				 function );

				return( -1 );
			}
			byte_stream_copy_to_uint64_little_endian(
			 &( shell_item_data[ 38 ] ),
			 value_64bit );
			libcnotify_printf(
			 "%s: unknown8\t\t\t\t: 0x%08" PRIx64 "\n",
			 function,
			 value_64bit );
		}
#endif
		shell_item_data_offset = 46;
	}
	byte_stream_copy_to_uint32_little_endian(
	 &( shell_item_data[ shell_item_data_offset ] ),
	 string_size );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: string size\t\t\t: %" PRIu32 "\n",
		 function,
		 string_size );
	}
#endif
	shell_item_data_offset += 4;

	string_size *= 2;

	if( ( string_size > 0 )
         && ( string_size <= shell_item_data_size )
	 && ( shell_item_data_offset <= ( shell_item_data_size - string_size ) ) )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( libfwsi_debug_print_utf16_string_value(
			     function,
			     "string\t\t\t\t",
			     &( shell_item_data[ shell_item_data_offset ] ),
			     string_size,
			     LIBUNA_ENDIAN_LITTLE,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_PRINT_FAILED,
				 "%s: unable to print UTF-16 string value.",
				 function );

				return( -1 );
			}
		}
#endif
		shell_item_data_offset += string_size;
	}
	byte_stream_copy_to_uint32_little_endian(
	 &( shell_item_data[ shell_item_data_offset ] ),
	 string_size );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: string size\t\t\t: %" PRIu32 "\n",
		 function,
		 string_size );
	}
#endif
	shell_item_data_offset += 4;

	string_size *= 2;

	if( ( string_size > 0 )
         && ( string_size <= shell_item_data_size )
	 && ( shell_item_data_offset <= ( shell_item_data_size - string_size ) ) )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( libfwsi_debug_print_utf16_string_value(
			     function,
			     "string\t\t\t\t",
			     &( shell_item_data[ shell_item_data_offset ] ),
			     string_size,
			     LIBUNA_ENDIAN_LITTLE,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_PRINT_FAILED,
				 "%s: unable to print UTF-16 string value.",
				 function );

				return( -1 );
			}
		}
#endif
		shell_item_data_offset += string_size;
	}
	byte_stream_copy_to_uint32_little_endian(
	 &( shell_item_data[ shell_item_data_offset ] ),
	 string_size );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: string size\t\t\t: %" PRIu32 "\n",
		 function,
		 string_size );
	}
#endif
	shell_item_data_offset += 4;

	string_size *= 2;

	if( ( string_size > 0 )
         && ( string_size <= shell_item_data_size )
	 && ( shell_item_data_offset <= ( shell_item_data_size - string_size ) ) )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( libfwsi_debug_print_utf16_string_value(
			     function,
			     "string\t\t\t\t",
			     &( shell_item_data[ shell_item_data_offset ] ),
			     string_size,
			     LIBUNA_ENDIAN_LITTLE,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_PRINT_FAILED,
				 "%s: unable to print UTF-16 string value.",
				 function );

				return( -1 );
			}
		}
#endif
		shell_item_data_offset += string_size;
	}
	byte_stream_copy_to_uint32_little_endian(
	 &( shell_item_data[ shell_item_data_offset ] ),
	 string_size );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: string size\t\t\t: %" PRIu32 "\n",
		 function,
		 string_size );
	}
#endif
	shell_item_data_offset += 4;

	string_size *= 2;

	if( ( string_size > 0 )
         && ( string_size <= shell_item_data_size )
	 && ( shell_item_data_offset <= ( shell_item_data_size - string_size ) ) )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( libfwsi_debug_print_utf16_string_value(
			     function,
			     "string\t\t\t\t",
			     &( shell_item_data[ shell_item_data_offset ] ),
			     string_size,
			     LIBUNA_ENDIAN_LITTLE,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_PRINT_FAILED,
				 "%s: unable to print UTF-16 string value.",
				 function );

				return( -1 );
			}
		}
#endif
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "\n" );
	}
#endif
	return( (ssize_t) shell_item_data_offset );
}

