/*
 * Web site (shell item) values functions
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
#include "libfwsi_definitions.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"
#include "libfwsi_libuna.h"
#include "libfwsi_web_site_values.h"

/* Creates web site values
 * Make sure the value web_site_values is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_web_site_values_initialize(
     libfwsi_web_site_values_t **web_site_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_web_site_values_initialize";

	if( web_site_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid web site values.",
		 function );

		return( -1 );
	}
	if( *web_site_values != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid web site values value already set.",
		 function );

		return( -1 );
	}
	*web_site_values = memory_allocate_structure(
	                    libfwsi_web_site_values_t );

	if( *web_site_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create web site values.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *web_site_values,
	     0,
	     sizeof( libfwsi_web_site_values_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear web site values.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *web_site_values != NULL )
	{
		memory_free(
		 *web_site_values );

		*web_site_values = NULL;
	}
	return( -1 );
}

/* Frees web site values
 * Returns 1 if successful or -1 on error
 */
int libfwsi_web_site_values_free(
     libfwsi_web_site_values_t **web_site_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_web_site_values_free";

	if( web_site_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid web site values.",
		 function );

		return( -1 );
	}
	if( *web_site_values != NULL )
	{
		if( ( *web_site_values )->location != NULL )
		{
			memory_free(
			 ( *web_site_values )->location );
		}
		memory_free(
		 *web_site_values );

		*web_site_values = NULL;
	}
	return( 1 );
}

/* Reads the web site values
 * Returns 1 if successful, 0 if not supported or -1 on error
 */
int libfwsi_web_site_values_read_data(
     libfwsi_web_site_values_t *web_site_values,
     const uint8_t *data,
     size_t data_size,
     libcerror_error_t **error )
{
	static char *function     = "libfwsi_web_site_values_read_data";
	size_t data_offset        = 0;
	uint32_t string_data_size = 0;

#if defined( HAVE_DEBUG_OUTPUT )
	uint32_t value_32bit      = 0;
	uint16_t value_16bit      = 0;
#endif

	if( web_site_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid web site values.",
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
	if( data_size < 24 )
	{
		return( 0 );
	}
	/* Do not try to parse unsupported data
	 */
	if( ( data[ 4 ] != 0x00 )
	 || ( data[ 5 ] != 0xb0 )
	 || ( data[ 6 ] != 0x01 )
	 || ( data[ 7 ] != 0xc0 ) )
	{
		return( 0 );
	}
	byte_stream_copy_to_uint32_little_endian(
	 &( data[ 20 ] ),
	 string_data_size );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		byte_stream_copy_to_uint16_little_endian(
		 &( data[ 2 ] ),
		 value_16bit );
		libcnotify_printf(
		 "%s: unknown1\t\t\t\t: 0x%04" PRIx16 "\n",
		 function,
		 value_16bit );

		byte_stream_copy_to_uint32_little_endian(
		 &( data[ 4 ] ),
		 value_32bit );
		libcnotify_printf(
		 "%s: signature\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

		byte_stream_copy_to_uint32_little_endian(
		 &( data[ 8 ] ),
		 value_32bit );
		libcnotify_printf(
		 "%s: data size\t\t\t\t: %" PRIu32 "\n",
		 function,
		 value_32bit );

		byte_stream_copy_to_uint32_little_endian(
		 &( data[ 12 ] ),
		 value_32bit );
		libcnotify_printf(
		 "%s: unknown2\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

		byte_stream_copy_to_uint32_little_endian(
		 &( data[ 16 ] ),
		 value_32bit );
		libcnotify_printf(
		 "%s: unknown3\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

		libcnotify_printf(
		 "%s: string1 data size\t\t\t: %" PRIu32 "\n",
		 function,
		 string_data_size );
	}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

	data_offset = 24;

	if( ( string_data_size > data_size )
	 || ( data_offset > ( data_size - string_data_size ) ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid string1 data size value out of bounds.",
		 function );

		goto on_error;
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: string1 data:\n",
		 function );
		libcnotify_print_data(
		 &( data[ data_offset ] ),
		 string_data_size,
		 0 );
	}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

	data_offset += string_data_size;

	if( data_offset > ( data_size - 20 ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid data size value out of bounds.",
		 function );

		goto on_error;
	}
	byte_stream_copy_to_uint32_little_endian(
	 &( data[ data_offset + 16 ] ),
	 string_data_size );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		byte_stream_copy_to_uint32_little_endian(
		 &( data[ data_offset ] ),
		 value_32bit );
		libcnotify_printf(
		 "%s: unknown4\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

		byte_stream_copy_to_uint32_little_endian(
		 &( data[ data_offset + 4 ] ),
		 value_32bit );
		libcnotify_printf(
		 "%s: unknown5\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

		byte_stream_copy_to_uint32_little_endian(
		 &( data[ data_offset + 8 ] ),
		 value_32bit );
		libcnotify_printf(
		 "%s: unknown6\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

		byte_stream_copy_to_uint32_little_endian(
		 &( data[ data_offset + 12 ] ),
		 value_32bit );
		libcnotify_printf(
		 "%s: unknown7\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

		libcnotify_printf(
		 "%s: string2 data size\t\t\t: %" PRIu32 "\n",
		 function,
		 string_data_size );
	}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

	data_offset += 20;

	if( ( string_data_size > data_size )
	 || ( data_offset > ( data_size - string_data_size ) ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid string2 data size value out of bounds.",
		 function );

		goto on_error;
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: string2 data:\n",
		 function );
		libcnotify_print_data(
		 &( data[ data_offset ] ),
		 string_data_size,
		 0 );
	}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

	data_offset += string_data_size;

	if( data_offset > ( data_size - 12 ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid data size value out of bounds.",
		 function );

		goto on_error;
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		byte_stream_copy_to_uint32_little_endian(
		 &( data[ data_offset ] ),
		 value_32bit );
		libcnotify_printf(
		 "%s: unknown8\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

		byte_stream_copy_to_uint32_little_endian(
		 &( data[ data_offset + 4 ] ),
		 value_32bit );
		libcnotify_printf(
		 "%s: unknown9\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

		byte_stream_copy_to_uint16_little_endian(
		 &( data[ data_offset + 8 ] ),
		 value_16bit );
		libcnotify_printf(
		 "%s: unknown10\t\t\t\t: 0x%04" PRIx16 "\n",
		 function,
		 value_16bit );

		byte_stream_copy_to_uint16_little_endian(
		 &( data[ data_offset + 10 ] ),
		 value_16bit );
		libcnotify_printf(
		 "%s: unknown11\t\t\t\t: 0x%04" PRIx16 "\n",
		 function,
		 value_16bit );
	}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

	data_offset += 12;

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

on_error:
	if( web_site_values->location != NULL )
	{
		memory_free(
		 web_site_values->location );

		web_site_values->location = NULL;
	}
	web_site_values->location_size = 0;

	return( -1 );
}

