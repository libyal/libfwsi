/*
 * URI (shell item) values functions
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

#include "libfwsi_debug.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"
#include "libfwsi_libfdatetime.h"
#include "libfwsi_libuna.h"
#include "libfwsi_uri_values.h"

/* Creates URI values
 * Make sure the value uri_values is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_uri_values_initialize(
     libfwsi_uri_values_t **uri_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_uri_values_initialize";

	if( uri_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid URI values.",
		 function );

		return( -1 );
	}
	if( *uri_values != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid URI values value already set.",
		 function );

		return( -1 );
	}
	*uri_values = memory_allocate_structure(
	               libfwsi_uri_values_t );

	if( *uri_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create URI values.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *uri_values,
	     0,
	     sizeof( libfwsi_uri_values_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear URI values.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *uri_values != NULL )
	{
		memory_free(
		 *uri_values );

		*uri_values = NULL;
	}
	return( -1 );
}

/* Frees URI values
 * Returns 1 if successful or -1 on error
 */
int libfwsi_uri_values_free(
     libfwsi_uri_values_t **uri_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_uri_values_free";

	if( uri_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid URI values.",
		 function );

		return( -1 );
	}
	if( *uri_values != NULL )
	{
		memory_free(
		 *uri_values );

		*uri_values = NULL;
	}
	return( 1 );
}

/* Reads the URI values
 * Returns 1 if successful, 0 if not supported or -1 on error
 */
int libfwsi_uri_values_read_data(
     libfwsi_uri_values_t *uri_values,
     const uint8_t *data,
     size_t data_size,
     int ascii_codepage,
     libcerror_error_t **error )
{
	static char *function     = "libfwsi_uri_values_read_data";
	size_t data_offset        = 0;
	size_t string_size        = 0;
	uint32_t string_data_size = 0;
	uint16_t item_data_size   = 0;
	uint8_t flags             = 0;

#if defined( HAVE_DEBUG_OUTPUT )
	uint32_t value_32bit      = 0;
	uint16_t value_16bit      = 0;
#endif

	if( uri_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid URI values.",
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
	if( data_size < 6 )
	{
		return( 0 );
	}
	/* Do not try to parse unsupported data
	 */
	if( data[ 2 ] != 0x61 )
	{
		return( 0 );
	}
	flags = data[ 3 ];

	byte_stream_copy_to_uint16_little_endian(
	 &( data[ 4 ] ),
	 item_data_size );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: flags\t\t\t\t\t: 0x%02" PRIx8 "\n",
		 function,
		 flags );

		libcnotify_printf(
		 "%s: data size\t\t\t\t\t: %" PRIu16 "\n",
		 function,
		 item_data_size );
	}
#endif
	data_offset = 6;

	if( item_data_size > 0 )
	{
		if( item_data_size > ( data_size - 6 ) )
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
			 "%s: data:\n",
			 function );
			libcnotify_print_data(
			 &( data[ 6 ] ),
			 item_data_size,
			 LIBCNOTIFY_PRINT_DATA_FLAG_GROUP_DATA );
		}
#endif
	}
#if defined( HAVE_DEBUG_OUTPUT )
	else if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "\n" );
	}
#endif
	if( item_data_size >= 36 )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			byte_stream_copy_to_uint32_little_endian(
			 &( data[ 6 ] ),
			 value_32bit );
			libcnotify_printf(
			 "%s: unknown1\t\t\t\t\t: %" PRIu32 "\n",
			 function,
			 value_32bit );

			byte_stream_copy_to_uint32_little_endian(
			 &( data[ 10 ] ),
			 value_32bit );
			libcnotify_printf(
			 "%s: unknown2\t\t\t\t\t: %" PRIu32 "\n",
			 function,
			 value_32bit );

			if( libfwsi_debug_print_filetime_value(
			     function,
			     "unknown3 time\t\t\t\t",
			     &( data[ 14 ] ),
			     8,
			     LIBFDATETIME_ENDIAN_LITTLE,
			     LIBFDATETIME_STRING_FORMAT_TYPE_CTIME | LIBFDATETIME_STRING_FORMAT_FLAG_DATE_TIME_NANO_SECONDS,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_PRINT_FAILED,
				 "%s: unable to print filetime value.",
				 function );

				return( -1 );
			}
			byte_stream_copy_to_uint32_little_endian(
			 &( data[ 22 ] ),
			 value_32bit );
			libcnotify_printf(
			 "%s: unknown4\t\t\t\t\t: 0x%08" PRIx32 "\n",
			 function,
			 value_32bit );

			libcnotify_printf(
			 "%s: unknown5:\n",
			 function );
			libcnotify_print_data(
			 &( data[ 26 ] ),
			 12,
			 0 );

			byte_stream_copy_to_uint32_little_endian(
			 &( data[ 38 ] ),
			 value_32bit );
			libcnotify_printf(
			 "%s: unknown6\t\t\t\t\t: %" PRIu32 "\n",
			 function,
			 value_32bit );
		}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

		data_offset    += 36;
		item_data_size -= 36;

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

		data_offset += 4;

		if( ( item_data_size < 4 )
		 || ( string_data_size > (uint32_t) ( item_data_size - 4 ) ) )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
			 "%s: invalid string1 data size value out of bounds.",
			 function );

			return( -1 );
		}
		item_data_size -= 4;

		if( data_offset >= data_size )
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
			 "%s: string1 data size\t\t\t\t: %" PRIu32 "\n",
			 function,
			 string_data_size );

			libcnotify_printf(
			 "%s: string1 data:\n",
			 function );
			libcnotify_print_data(
			 &( data[ data_offset ] ),
			 string_data_size,
			 0 );
		}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

		data_offset    += string_data_size;
		item_data_size -= string_data_size;

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

		data_offset += 4;

		if( ( item_data_size < 4 )
		 || ( string_data_size > (uint32_t) ( item_data_size - 4 ) ) )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
			 "%s: invalid string2 data size value out of bounds.",
			 function );

			return( -1 );
		}
		item_data_size -= 4;

		if( data_offset >= data_size )
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
			 "%s: string2 data size\t\t\t\t: %" PRIu32 "\n",
			 function,
			 string_data_size );

			libcnotify_printf(
			 "%s: string2 data:\n",
			 function );
			libcnotify_print_data(
			 &( data[ data_offset ] ),
			 string_data_size,
			 0 );
		}
#endif
		data_offset    += string_data_size;
		item_data_size -= string_data_size;

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

		data_offset += 4;

		if( ( item_data_size < 4 )
		 || ( string_data_size > (uint32_t) ( item_data_size - 4 ) ) )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
			 "%s: invalid string3 data size value out of bounds.",
			 function );

			return( -1 );
		}
		item_data_size -= 4;

		if( data_offset >= data_size )
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
			 "%s: string3 data size\t\t\t\t: %" PRIu32 "\n",
			 function,
			 string_data_size );

			if( string_data_size > item_data_size )
			{
				string_data_size = item_data_size;
			}
			libcnotify_printf(
			 "%s: string3 data:\n",
			 function );
			libcnotify_print_data(
			 &( data[ data_offset ] ),
			 string_data_size,
			 0 );
		}
#endif
		data_offset    += string_data_size;
		item_data_size -= string_data_size;
	}
	if( item_data_size > 0 )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			libcnotify_printf(
			 "%s: trailing data:\n",
			 function );
			libcnotify_print_data(
			 &( data[ data_offset ] ),
			 item_data_size,
			 0 );
		}
#endif
		data_offset += item_data_size;
	}
	if( data_offset >= data_size )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid data size value out of bounds.",
		 function );

		return( -1 );
	}
	/* Determine the URI size
	 */
	if( ( flags & 0x80 ) != 0 )
	{
		for( string_size = data_offset;
		     ( string_size + 1 ) < data_size;
		     string_size += 2 )
		{
			if( ( data[ string_size ] == 0 )
			 && ( data[ string_size + 1 ] == 0 ) )
			{
				string_size += 2;

				break;
			}
		}
		string_size -= data_offset;
	}
	else
	{
		for( string_size = data_offset;
		     string_size < data_size;
		     string_size++ )
		{
			if( data[ string_size ] == 0 )
			{
				string_size++;

				break;
			}
		}
		string_size -= data_offset;
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		if( ( flags & 0x80 ) != 0 )
		{
			if( libfwsi_debug_print_utf16_string_value(
			     function,
			     "URI\t\t\t\t\t",
			     &( data[ data_offset ] ),
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
		else
		{
			if( libfwsi_debug_print_string_value(
			     function,
			     "URI\t\t\t\t\t",
			     &( data[ data_offset ] ),
			     string_size,
			     ascii_codepage,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_PRINT_FAILED,
				 "%s: unable to print string value.",
				 function );

				return( -1 );
			}
		}
	}
#endif
	data_offset += string_size;

/* TODO value likely controlled by flags */
	if( data_offset < data_size )
	{
		if( data_offset >= ( data_size - 2 ) )
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
			byte_stream_copy_to_uint16_little_endian(
			 &( data[ data_offset ] ),
			 value_16bit );

			libcnotify_printf(
			 "%s: unknown9\t\t\t\t\t: %" PRIu16 "\n",
			 function,
			 value_16bit );
		}
#endif
		data_offset += 2;
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

