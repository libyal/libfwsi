/*
 * CD burn (shell item) values functions
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

#include "libfwsi_cdburn_values.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"

/* Creates CD burn values
 * Make sure the value cdburn_values is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_cdburn_values_initialize(
     libfwsi_cdburn_values_t **cdburn_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_cdburn_values_initialize";

	if( cdburn_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid CD burn values.",
		 function );

		return( -1 );
	}
	if( *cdburn_values != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid CD burn values value already set.",
		 function );

		return( -1 );
	}
	*cdburn_values = memory_allocate_structure(
	                  libfwsi_cdburn_values_t );

	if( *cdburn_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create CD burn values.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *cdburn_values,
	     0,
	     sizeof( libfwsi_cdburn_values_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear CD burn values.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *cdburn_values != NULL )
	{
		memory_free(
		 *cdburn_values );

		*cdburn_values = NULL;
	}
	return( -1 );
}

/* Frees CD burn values
 * Returns 1 if successful or -1 on error
 */
int libfwsi_cdburn_values_free(
     libfwsi_cdburn_values_t **cdburn_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_cdburn_values_free";

	if( cdburn_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid CD burn values.",
		 function );

		return( -1 );
	}
	if( *cdburn_values != NULL )
	{
		memory_free(
		 *cdburn_values );

		*cdburn_values = NULL;
	}
	return( 1 );
}

/* Reads the CD burn values
 * Returns 1 if successful, 0 if not supported or -1 on error
 */
int libfwsi_cdburn_values_read_data(
     libfwsi_cdburn_values_t *cdburn_values,
     const uint8_t *data,
     size_t data_size,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_cdburn_values_read_data";
	size_t data_offset    = 0;
	uint32_t unknown2     = 0;

#if defined( HAVE_DEBUG_OUTPUT )
	uint32_t value_32bit  = 0;
#endif

	if( cdburn_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid CD burn values.",
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
	if( data_size < 18 )
	{
		return( 0 );
	}
	/* Do not try to parse unsupported shell item signatures
	 */
	if( memory_compare(
	     &( data[ 4 ] ),
	     "AugM",
	     4 ) != 0 )
	{
		return( 0 );
	}
	byte_stream_copy_to_uint32_little_endian(
	 &( data[ 8 ] ),
	 unknown2 );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: class type indicator\t\t\t: 0x%02" PRIx8 "\n",
		 function,
		 data[ 2 ] );

		libcnotify_printf(
		 "%s: unknown1\t\t\t\t\t: 0x%02" PRIx8 "\n",
		 function,
		 data[ 3 ] );

		libcnotify_printf(
		 "%s: signature\t\t\t\t\t: %c%c%c%c\n",
		 function,
		 data[ 4 ],
		 data[ 5 ],
		 data[ 6 ],
		 data[ 7 ] );

		libcnotify_printf(
		 "%s: unknown2\t\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 unknown2 );

		byte_stream_copy_to_uint32_little_endian(
		 &( data[ 12 ] ),
		 value_32bit );
		libcnotify_printf(
		 "%s: unknown3\t\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

		if( ( unknown2 == 4 )
		 && ( data_size >= 22 ) )
		{
			byte_stream_copy_to_uint32_little_endian(
			 &( data[ 16 ] ),
			 value_32bit );
			libcnotify_printf(
			 "%s: unknown4\t\t\t\t\t: 0x%08" PRIx32 "\n",
			 function,
			 value_32bit );
		}
	}
#endif
	/* Do not try to parse unsupported unknown2 values
	 */
	if( unknown2 == 2 )
	{
		data_offset = 16;
	}
	else if( unknown2 == 4 )
	{
		data_offset = 20;
	}
	if( data_offset > 0 )
	{
/* TODO parse sub shell item list */
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

