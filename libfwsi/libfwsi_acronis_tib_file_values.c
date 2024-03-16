/*
 * Acronis True Image (TIB) file (shell item) values functions
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

#include "libfwsi_acronis_tib_file_values.h"
#include "libfwsi_debug.h"
#include "libfwsi_definitions.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"
#include "libfwsi_libfdatetime.h"
#include "libfwsi_libuna.h"
#include "libfwsi_unused.h"

/* Creates compressed folder values
 * Make sure the value acronis_tib_file_values is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_acronis_tib_file_values_initialize(
     libfwsi_acronis_tib_file_values_t **acronis_tib_file_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_acronis_tib_file_values_initialize";

	if( acronis_tib_file_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid compressed folder values.",
		 function );

		return( -1 );
	}
	if( *acronis_tib_file_values != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid compressed folder values value already set.",
		 function );

		return( -1 );
	}
	*acronis_tib_file_values = memory_allocate_structure(
	                            libfwsi_acronis_tib_file_values_t );

	if( *acronis_tib_file_values == NULL )
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
	     *acronis_tib_file_values,
	     0,
	     sizeof( libfwsi_acronis_tib_file_values_t ) ) == NULL )
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
	if( *acronis_tib_file_values != NULL )
	{
		memory_free(
		 *acronis_tib_file_values );

		*acronis_tib_file_values = NULL;
	}
	return( -1 );
}

/* Frees compressed folder values
 * Returns 1 if successful or -1 on error
 */
int libfwsi_acronis_tib_file_values_free(
     libfwsi_acronis_tib_file_values_t **acronis_tib_file_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_acronis_tib_file_values_free";

	if( acronis_tib_file_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid compressed folder values.",
		 function );

		return( -1 );
	}
	if( *acronis_tib_file_values != NULL )
	{
		memory_free(
		 *acronis_tib_file_values );

		*acronis_tib_file_values = NULL;
	}
	return( 1 );
}

/* Reads the compressed folder values
 * Returns 1 if successful, 0 if not supported or -1 on error
 */
int libfwsi_acronis_tib_file_values_read_data(
     libfwsi_acronis_tib_file_values_t *acronis_tib_file_values,
     const uint8_t *data,
     size_t data_size,
     libcerror_error_t **error )
{
	static char *function     = "libfwsi_acronis_tib_file_values_read_data";
	size_t data_offset        = 0;
	uint32_t string_data_size = 0;

#if defined( HAVE_DEBUG_OUTPUT )
	uint64_t value_64bit      = 0;
	uint32_t value_32bit      = 0;
	uint16_t value_16bit      = 0;
#endif

	if( acronis_tib_file_values == NULL )
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
	if( data_size < 50 )
	{
		return( 0 );
	}
	/* Do not try to parse unsupported data
	 */
	if( ( data[ 2 ] != 0x52 )
	 || ( data[ 3 ] != 0x67 )
	 || ( data[ 4 ] != 0xb1 )
	 || ( data[ 5 ] != 0xac ) )
	{
		return( 0 );
	}
	byte_stream_copy_to_uint32_little_endian(
	 &( data[ data_offset ] ),
	 string_data_size );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: unknown1\t\t\t\t: 0x%02" PRIx8 "\n",
		 function,
		 data[ 3 ] );

		byte_stream_copy_to_uint16_little_endian(
		 &( data[ 4 ] ),
		 value_16bit );
		libcnotify_printf(
		 "%s: unknown2\t\t\t\t: 0x%04" PRIx16 "\n",
		 function,
		 value_16bit );

		byte_stream_copy_to_uint32_little_endian(
		 &( data[ 6 ] ),
		 value_32bit );
		libcnotify_printf(
		 "%s: unknown3\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

		byte_stream_copy_to_uint64_little_endian(
		 &( data[ 10 ] ),
		 value_64bit );
		libcnotify_printf(
		 "%s: unknown4\t\t\t\t: 0x%08" PRIx64 "\n",
		 function,
		 value_64bit );

		byte_stream_copy_to_uint32_little_endian(
		 &( data[ 18 ] ),
		 value_32bit );
		libcnotify_printf(
		 "%s: unknown5\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

		byte_stream_copy_to_uint32_little_endian(
		 &( data[ 22 ] ),
		 value_32bit );
		libcnotify_printf(
		 "%s: unknown6\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

		if( libfwsi_debug_print_fat_date_time_value(
		     function,
		     "unknown time1\t\t\t",
		     &( data[ 26 ] ),
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
		 &( data[ 30 ] ),
		 value_32bit );
		libcnotify_printf(
		 "%s: unknown7\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

		if( libfwsi_debug_print_fat_date_time_value(
		     function,
		     "unknown time2\t\t\t",
		     &( data[ 34 ] ),
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
		 &( data[ 38 ] ),
		 value_64bit );
		libcnotify_printf(
		 "%s: unknown8\t\t\t\t: 0x%08" PRIx64 "\n",
		 function,
		 value_64bit );

		libcnotify_printf(
		 "%s: string1 data size\t\t: %" PRIu32 "\n",
		 function,
		 string_data_size );
	}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

	data_offset = 50;

	if( string_data_size > ( ( data_size - data_offset ) / 2 ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid string1 data size value out of bounds.",
		 function );

		return( -1 );
	}
	string_data_size *= 2;

	if( string_data_size > 0 )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( libfwsi_debug_print_utf16_string_value(
			     function,
			     "string1\t\t\t\t",
			     &( data[ data_offset ] ),
			     string_data_size,
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
		data_offset += string_data_size;
	}
	if( data_offset >= ( data_size - 4 ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid data size value out of bounds.",
		 function );

		return( -1 );
	}
	byte_stream_copy_to_uint32_little_endian(
	 &( data[ data_offset ] ),
	 string_data_size );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: string2 data size\t\t: %" PRIu32 "\n",
		 function,
		 string_data_size );
	}
#endif
	data_offset += 4;

	if( string_data_size > ( ( data_size - data_offset ) / 2 ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid string2 data size value out of bounds.",
		 function );

		return( -1 );
	}
	string_data_size *= 2;

	if( string_data_size > 0 )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( libfwsi_debug_print_utf16_string_value(
			     function,
			     "string2\t\t\t\t",
			     &( data[ data_offset ] ),
			     string_data_size,
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
		data_offset += string_data_size;
	}
	if( data_offset >= ( data_size - 4 ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid data size value out of bounds.",
		 function );

		return( -1 );
	}
	byte_stream_copy_to_uint32_little_endian(
	 &( data[ data_offset ] ),
	 string_data_size );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: string3 data size\t\t: %" PRIu32 "\n",
		 function,
		 string_data_size );
	}
#endif
	data_offset += 4;

	if( string_data_size > ( ( data_size - data_offset ) / 2 ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid string3 data size value out of bounds.",
		 function );

		return( -1 );
	}
	string_data_size *= 2;

	if( string_data_size > 0 )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( libfwsi_debug_print_utf16_string_value(
			     function,
			     "string3\t\t\t\t",
			     &( data[ data_offset ] ),
			     string_data_size,
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
		data_offset += string_data_size;
	}
	if( data_offset >= ( data_size - 4 ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid data size value out of bounds.",
		 function );

		return( -1 );
	}
	byte_stream_copy_to_uint32_little_endian(
	 &( data[ data_offset ] ),
	 string_data_size );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: string4 data size\t\t: %" PRIu32 "\n",
		 function,
		 string_data_size );
	}
#endif
	data_offset += 4;

	if( string_data_size > ( ( data_size - data_offset ) / 2 ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid string4 data size value out of bounds.",
		 function );

		return( -1 );
	}
	string_data_size *= 2;

	if( string_data_size > 0 )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( libfwsi_debug_print_utf16_string_value(
			     function,
			     "string4\t\t\t\t",
			     &( data[ data_offset ] ),
			     string_data_size,
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
	return( 1 );
}

