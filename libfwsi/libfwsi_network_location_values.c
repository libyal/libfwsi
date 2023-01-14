/*
 * Network location (shell item) values functions
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
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"
#include "libfwsi_libuna.h"
#include "libfwsi_network_location_values.h"

/* Creates network location values
 * Make sure the value network_location_values is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_network_location_values_initialize(
     libfwsi_network_location_values_t **network_location_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_network_location_values_initialize";

	if( network_location_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid network location values.",
		 function );

		return( -1 );
	}
	if( *network_location_values != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid network location values value already set.",
		 function );

		return( -1 );
	}
	*network_location_values = memory_allocate_structure(
	                            libfwsi_network_location_values_t );

	if( *network_location_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create network location values.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *network_location_values,
	     0,
	     sizeof( libfwsi_network_location_values_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear network location values.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *network_location_values != NULL )
	{
		memory_free(
		 *network_location_values );

		*network_location_values = NULL;
	}
	return( -1 );
}

/* Frees network location values
 * Returns 1 if successful or -1 on error
 */
int libfwsi_network_location_values_free(
     libfwsi_network_location_values_t **network_location_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_network_location_values_free";

	if( network_location_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid network location values.",
		 function );

		return( -1 );
	}
	if( *network_location_values != NULL )
	{
		if( ( *network_location_values )->location != NULL )
		{
			memory_free(
			 ( *network_location_values )->location );
		}
		if( ( *network_location_values )->description != NULL )
		{
			memory_free(
			 ( *network_location_values )->description );
		}
		if( ( *network_location_values )->comments != NULL )
		{
			memory_free(
			 ( *network_location_values )->comments );
		}
		memory_free(
		 *network_location_values );

		*network_location_values = NULL;
	}
	return( 1 );
}

/* Reads the network location values
 * Returns 1 if successful, 0 if not supported or -1 on error
 */
int libfwsi_network_location_values_read_data(
     libfwsi_network_location_values_t *network_location_values,
     const uint8_t *data,
     size_t data_size,
     int ascii_codepage,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_network_location_values_read_data";
	size_t data_offset    = 0;
	size_t string_size    = 0;
	uint8_t flags         = 0;

#if defined( HAVE_DEBUG_OUTPUT )
	uint16_t value_16bit  = 0;
#endif

	if( network_location_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid network location values.",
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
	/* Do not try to parse unknown class type indicators
	 */
	if( ( data[ 2 ] != 0x41 )
	 && ( data[ 2 ] != 0x42 )
	 && ( data[ 2 ] != 0x46 )
	 && ( data[ 2 ] != 0x47 )
	 && ( data[ 2 ] != 0x4c )
	 && ( data[ 2 ] != 0xc3 ) )
	{
		return( 0 );
	}
	network_location_values->ascii_codepage = ascii_codepage;

	flags = data[ 4 ];

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: unknown0\t\t\t: 0x%02" PRIx8 "\n",
		 function,
		 data[ 3 ] );

		libcnotify_printf(
		 "%s: flags\t\t\t: 0x%02" PRIx8 "\n",
		 function,
		 flags );
	}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

	data_offset = 5;

	/* Determine the network location
	 */
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

	if( ( string_size == 0 )
	 || ( string_size > (size_t) MEMORY_MAXIMUM_ALLOCATION_SIZE ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid location string size value out of bounds.",
		 function );

		goto on_error;
	}
	network_location_values->location = (uint8_t *) memory_allocate(
	                                                 sizeof( uint8_t ) * string_size );

	if( network_location_values->location == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create location.",
		 function );

		goto on_error;
	}
	if( memory_copy(
	     network_location_values->location,
	     &( data[ data_offset ] ),
	     string_size ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_COPY_FAILED,
		 "%s: unable to copy location.",
		 function );

		goto on_error;
	}
	network_location_values->location_size = string_size;

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		if( libfwsi_debug_print_string_value(
		     function,
		     "network location\t\t",
		     network_location_values->location,
		     network_location_values->location_size,
		     ascii_codepage,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_PRINT_FAILED,
			 "%s: unable to print string value.",
			 function );

			goto on_error;
		}
	}
#endif
	data_offset += string_size;

	if( ( ( flags & 0x80 ) != 0 )
	 && ( data_offset < data_size ) )
	{
		/* Determine the network description
		 */
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

		if( ( string_size == 0 )
		 || ( string_size > (size_t) MEMORY_MAXIMUM_ALLOCATION_SIZE ) )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
			 "%s: invalid description string size value out of bounds.",
			 function );

			goto on_error;
		}
		network_location_values->description = (uint8_t *) memory_allocate(
		                                                    sizeof( uint8_t ) * string_size );

		if( network_location_values->description == NULL )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_MEMORY,
			 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
			 "%s: unable to create description.",
			 function );

			goto on_error;
		}
		if( memory_copy(
		     network_location_values->description,
		     &( data[ data_offset ] ),
		     string_size ) == NULL )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_MEMORY,
			 LIBCERROR_MEMORY_ERROR_COPY_FAILED,
			 "%s: unable to copy description.",
			 function );

			goto on_error;
		}
		network_location_values->description_size = string_size;

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( libfwsi_debug_print_string_value(
			     function,
			     "network description\t\t",
			     network_location_values->description,
			     network_location_values->description_size,
			     ascii_codepage,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_PRINT_FAILED,
				 "%s: unable to print string value.",
				 function );

				goto on_error;
			}
		}
#endif
		data_offset += string_size;
	}
	if( ( ( flags & 0x40 ) != 0 )
	 && ( data_size > 0 ) )
	{
		/* Determine the network comments
		 */
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

		if( ( string_size == 0 )
		 || ( string_size > (size_t) MEMORY_MAXIMUM_ALLOCATION_SIZE ) )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
			 "%s: invalid comments string size value out of bounds.",
			 function );

			goto on_error;
		}
		network_location_values->comments = (uint8_t *) memory_allocate(
		                                                 sizeof( uint8_t ) * string_size );

		if( network_location_values->comments == NULL )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_MEMORY,
			 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
			 "%s: unable to create comments.",
			 function );

			goto on_error;
		}
		if( memory_copy(
		     network_location_values->comments,
		     &( data[ data_offset ] ),
		     string_size ) == NULL )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_MEMORY,
			 LIBCERROR_MEMORY_ERROR_COPY_FAILED,
			 "%s: unable to copy comments.",
			 function );

			goto on_error;
		}
		network_location_values->comments_size = string_size;

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( libfwsi_debug_print_string_value(
			     function,
			     "network comments\t\t",
			     network_location_values->comments,
			     network_location_values->comments_size,
			     ascii_codepage,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_PRINT_FAILED,
				 "%s: unable to print string value.",
				 function );

				goto on_error;
			}
		}
#endif
		data_offset += string_size;
	}
	if( data_offset <= ( data_size - 2 ) )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			byte_stream_copy_to_uint16_little_endian(
			 &( data[ data_offset ] ),
			 value_16bit );

			libcnotify_printf(
			 "%s: unknown1\t\t\t: 0x%04" PRIx16 "\n",
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

on_error:
	if( network_location_values->comments != NULL )
	{
		memory_free(
		 network_location_values->comments );

		network_location_values->comments = NULL;
	}
	network_location_values->comments_size = 0;

	if( network_location_values->description != NULL )
	{
		memory_free(
		 network_location_values->description );

		network_location_values->description = NULL;
	}
	network_location_values->description_size = 0;

	if( network_location_values->location != NULL )
	{
		memory_free(
		 network_location_values->location );

		network_location_values->location = NULL;
	}
	network_location_values->location_size = 0;

	return( -1 );
}

