/*
 * Network location (shell item) values functions
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
 * Returns the number of bytes read, 0 if not able to read or -1 on error
 */
ssize_t libfwsi_network_location_values_read(
         libfwsi_network_location_values_t *network_location_values,
         const uint8_t *shell_item_data,
         size_t shell_item_data_size,
         int ascii_codepage,
         libcerror_error_t **error )
{
	static char *function                       = "libfwsi_network_location_values_read";
	size_t shell_item_data_offset               = 0;
	size_t string_size                          = 0;
	uint8_t flags                               = 0;

#if defined( HAVE_DEBUG_OUTPUT )
	libcstring_system_character_t *value_string = NULL;
	size_t value_string_size                    = 0;
	uint16_t value_16bit                        = 0;
	int result                                  = 0;
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
	if( ( shell_item_data[ 2 ] != 0x41 )
	 && ( shell_item_data[ 2 ] != 0x42 )
	 && ( shell_item_data[ 2 ] != 0x46 )
	 && ( shell_item_data[ 2 ] != 0x47 )
	 && ( shell_item_data[ 2 ] != 0x4c )
	 && ( shell_item_data[ 2 ] != 0xc3 ) )
	{
		return( 0 );
	}
	network_location_values->ascii_codepage = ascii_codepage;

	flags = shell_item_data[ 4 ];

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: unknown0\t\t\t\t: 0x%02" PRIx8 "\n",
		 function,
		 shell_item_data[ 3 ] );

		libcnotify_printf(
		 "%s: flags\t\t\t\t: 0x%02" PRIx8 "\n",
		 function,
		 flags );
	}
#endif
	shell_item_data_offset = 5;

	/* Determine the network location
	 */
	for( string_size = shell_item_data_offset;
	     string_size < shell_item_data_size;
	     string_size++ )
	{
		if( shell_item_data[ string_size ] == 0 )
		{
			string_size++;

			break;
		}
	}
	string_size -= shell_item_data_offset;

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
	     &( shell_item_data[ shell_item_data_offset ] ),
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
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
		result = libuna_utf16_string_size_from_byte_stream(
			  network_location_values->location,
			  network_location_values->location_size,
			  ascii_codepage,
			  &value_string_size,
			  error );
#else
		result = libuna_utf8_string_size_from_byte_stream(
			  network_location_values->location,
			  network_location_values->location_size,
			  ascii_codepage,
			  &value_string_size,
			  error );
#endif
		if( result != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
			 "%s: unable to determine size of network location string.",
			 function );

			goto on_error;
		}
		if( value_string_size > (size_t) ( SSIZE_MAX / sizeof( libcstring_system_character_t ) ) )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_VALUE_EXCEEDS_MAXIMUM,
			 "%s: invalid network location string size value exceeds maximum.",
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
			 "%s: unable to create network location string.",
			 function );

			goto on_error;
		}
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
		result = libuna_utf16_string_copy_from_byte_stream(
			  (libuna_utf16_character_t *) value_string,
			  value_string_size,
			  network_location_values->location,
			  network_location_values->location_size,
			  ascii_codepage,
			  error );
#else
		result = libuna_utf8_string_copy_from_byte_stream(
			  (libuna_utf8_character_t *) value_string,
			  value_string_size,
			  network_location_values->location,
			  network_location_values->location_size,
			  ascii_codepage,
			  error );
#endif
		if( result != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
			 "%s: unable to set network location string.",
			 function );

			goto on_error;
		}
		libcnotify_printf(
		 "%s: network location\t\t\t: %" PRIs_LIBCSTRING_SYSTEM "\n",
		 function,
		 value_string );

		memory_free(
		 value_string );

		value_string = NULL;
	}
#endif
	shell_item_data_offset += string_size;

	if( ( ( flags & 0x80 ) != 0 )
	 && ( shell_item_data_offset < shell_item_data_size ) )
	{
		/* Determine the network description
		 */
		for( string_size = shell_item_data_offset;
		     string_size < shell_item_data_size;
		     string_size++ )
		{
			if( shell_item_data[ string_size ] == 0 )
			{
				string_size++;

				break;
			}
		}
		string_size -= shell_item_data_offset;

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
		     &( shell_item_data[ shell_item_data_offset ] ),
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
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
			result = libuna_utf16_string_size_from_byte_stream(
			          network_location_values->description,
			          network_location_values->description_size,
				  ascii_codepage,
				  &value_string_size,
				  error );
#else
			result = libuna_utf8_string_size_from_byte_stream(
			          network_location_values->description,
			          network_location_values->description_size,
				  ascii_codepage,
				  &value_string_size,
				  error );
#endif
			if( result != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
				 "%s: unable to determine size of description string.",
				 function );

				goto on_error;
			}
			if( value_string_size > (size_t) ( SSIZE_MAX / sizeof( libcstring_system_character_t ) ) )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_VALUE_EXCEEDS_MAXIMUM,
				 "%s: invalid description string size value exceeds maximum.",
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
				 "%s: unable to create description string.",
				 function );

				goto on_error;
			}
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
			result = libuna_utf16_string_copy_from_byte_stream(
				  (libuna_utf16_character_t *) value_string,
				  value_string_size,
			          network_location_values->description,
			          network_location_values->description_size,
				  ascii_codepage,
				  error );
#else
			result = libuna_utf8_string_copy_from_byte_stream(
				  (libuna_utf8_character_t *) value_string,
				  value_string_size,
			          network_location_values->description,
			          network_location_values->description_size,
				  ascii_codepage,
				  error );
#endif
			if( result != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
				 "%s: unable to set description string.",
				 function );

				goto on_error;
			}
			libcnotify_printf(
			 "%s: network description\t\t: %" PRIs_LIBCSTRING_SYSTEM "\n",
			 function,
			 value_string );

			memory_free(
			 value_string );

			value_string = NULL;
		}
#endif
		shell_item_data_offset += string_size;
	}
	if( ( ( flags & 0x40 ) != 0 )
	 && ( shell_item_data_size > 0 ) )
	{
		/* Determine the network comments
		 */
		for( string_size = shell_item_data_offset;
		     string_size < shell_item_data_size;
		     string_size++ )
		{
			if( shell_item_data[ string_size ] == 0 )
			{
				string_size++;

				break;
			}
		}
		string_size -= shell_item_data_offset;

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
		     &( shell_item_data[ shell_item_data_offset ] ),
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
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
			result = libuna_utf16_string_size_from_byte_stream(
			          network_location_values->comments,
			          network_location_values->comments_size,
				  ascii_codepage,
				  &value_string_size,
				  error );
#else
			result = libuna_utf8_string_size_from_byte_stream(
			          network_location_values->comments,
			          network_location_values->comments_size,
				  ascii_codepage,
				  &value_string_size,
				  error );
#endif
			if( result != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
				 "%s: unable to determine size of comments string.",
				 function );

				goto on_error;
			}
			if( value_string_size > (size_t) ( SSIZE_MAX / sizeof( libcstring_system_character_t ) ) )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_VALUE_EXCEEDS_MAXIMUM,
				 "%s: invalid comments string size value exceeds maximum.",
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
				 "%s: unable to create comments string.",
				 function );

				goto on_error;
			}
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
			result = libuna_utf16_string_copy_from_byte_stream(
				  (libuna_utf16_character_t *) value_string,
				  value_string_size,
			          network_location_values->comments,
			          network_location_values->comments_size,
				  ascii_codepage,
				  error );
#else
			result = libuna_utf8_string_copy_from_byte_stream(
				  (libuna_utf8_character_t *) value_string,
				  value_string_size,
			          network_location_values->comments,
			          network_location_values->comments_size,
				  ascii_codepage,
				  error );
#endif
			if( result != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
				 "%s: unable to set comments string.",
				 function );

				goto on_error;
			}
			libcnotify_printf(
			 "%s: network comments\t\t\t: %" PRIs_LIBCSTRING_SYSTEM "\n",
			 function,
			 value_string );

			memory_free(
			 value_string );

			value_string = NULL;
		}
#endif
		shell_item_data_offset += string_size;
	}
	if( shell_item_data_offset <= ( shell_item_data_size - 2 ) )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			byte_stream_copy_to_uint16_little_endian(
			 &( shell_item_data[ shell_item_data_offset ] ),
			 value_16bit );

			libcnotify_printf(
			 "%s: unknown1\t\t\t\t: 0x%04" PRIx16 "\n",
			 function,
			 value_16bit );
		}
#endif
		shell_item_data_offset += 2;
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "\n" );
	}
#endif
	return( (ssize_t) shell_item_data_offset );

on_error:
#if defined( HAVE_DEBUG_OUTPUT )
	if( value_string != NULL )
	{
		memory_free(
		 value_string );
	}
#endif
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

