/*
 * Control Panel CPL file (shell item) values functions
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

#include "libfwsi_control_panel_cpl_file_values.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"
#include "libfwsi_libuna.h"

/* Creates control panel CPL file values
 * Make sure the value control_panel_cpl_file_values is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_control_panel_cpl_file_values_initialize(
     libfwsi_control_panel_cpl_file_values_t **control_panel_cpl_file_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_control_panel_cpl_file_values_initialize";

	if( control_panel_cpl_file_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid control panel CPL file values.",
		 function );

		return( -1 );
	}
	if( *control_panel_cpl_file_values != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid control panel CPL file values value already set.",
		 function );

		return( -1 );
	}
	*control_panel_cpl_file_values = memory_allocate_structure(
	                                  libfwsi_control_panel_cpl_file_values_t );

	if( *control_panel_cpl_file_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create control panel CPL file values.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *control_panel_cpl_file_values,
	     0,
	     sizeof( libfwsi_control_panel_cpl_file_values_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear control panel CPL file values.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *control_panel_cpl_file_values != NULL )
	{
		memory_free(
		 *control_panel_cpl_file_values );

		*control_panel_cpl_file_values = NULL;
	}
	return( -1 );
}

/* Frees control panel CPL file values
 * Returns 1 if successful or -1 on error
 */
int libfwsi_control_panel_cpl_file_values_free(
     libfwsi_control_panel_cpl_file_values_t **control_panel_cpl_file_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_control_panel_cpl_file_values_free";

	if( control_panel_cpl_file_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid control panel CPL file values.",
		 function );

		return( -1 );
	}
	if( *control_panel_cpl_file_values != NULL )
	{
		memory_free(
		 *control_panel_cpl_file_values );

		*control_panel_cpl_file_values = NULL;
	}
	return( 1 );
}

/* Reads the control panel CPL file values
 * Returns the number of bytes read if successful, 0 if not able to read or -1 on error
 */
ssize_t libfwsi_control_panel_cpl_file_values_read(
         libfwsi_control_panel_cpl_file_values_t *control_panel_cpl_file_values,
         const uint8_t *shell_item_data,
         size_t shell_item_data_size,
         libcerror_error_t **error )
{
	static char *function                       = "libfwsi_control_panel_cpl_file_values_read";
	size_t shell_item_data_offset               = 0;
	size_t string_size                          = 0;
	uint32_t signature                          = 0;

#if defined( HAVE_DEBUG_OUTPUT )
	libcstring_system_character_t *value_string = NULL;
	size_t value_string_size                    = 0;
	uint32_t value_32bit                        = 0;
	uint16_t value_16bit                        = 0;
	int result                                  = 0;
#endif

	if( control_panel_cpl_file_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid control panel CPL file values.",
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
	if( shell_item_data_size < 24 )
	{
		return( 0 );
	}
	/* Do not try to parse unsupported shell item signatures
	 */
	byte_stream_copy_to_uint32_little_endian(
	 &( shell_item_data[ 4 ] ),
	 signature );

	if( signature != 0xffffff38UL )
	{
		return( 0 );
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: class type indicator\t: 0x%02" PRIx8 "\n",
		 function,
		 shell_item_data[ 2 ] );

		libcnotify_printf(
		 "%s: unknown1\t\t\t: 0x%02" PRIx8 "\n",
		 function,
		 shell_item_data[ 3 ] );

		libcnotify_printf(
		 "%s: signature\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 signature );

		byte_stream_copy_to_uint32_little_endian(
		 &( shell_item_data[ 8 ] ),
		 value_32bit );
		libcnotify_printf(
		 "%s: unknown2\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

		byte_stream_copy_to_uint32_little_endian(
		 &( shell_item_data[ 12 ] ),
		 value_32bit );
		libcnotify_printf(
		 "%s: unknown3\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

		byte_stream_copy_to_uint32_little_endian(
		 &( shell_item_data[ 16 ] ),
		 value_32bit );
		libcnotify_printf(
		 "%s: unknown4\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

		byte_stream_copy_to_uint16_little_endian(
		 &( shell_item_data[ 20 ] ),
		 value_16bit );
		libcnotify_printf(
		 "%s: unknown5\t\t\t: 0x%04" PRIx16 "\n",
		 function,
		 value_16bit );

		byte_stream_copy_to_uint16_little_endian(
		 &( shell_item_data[ 22 ] ),
		 value_16bit );
		libcnotify_printf(
		 "%s: unknown6\t\t\t: 0x%04" PRIx16 "\n",
		 function,
		 value_16bit );
	}
#endif
	shell_item_data_offset = 24;

	if( shell_item_data_offset <= ( shell_item_data_size - 2 ) )
	{
		for( string_size = shell_item_data_offset;
		     string_size < shell_item_data_size;
		     string_size += 2 )
		{
			if( shell_item_data[ string_size ] == 0 )
			{
				string_size += 2;

				break;
			}
		}
		string_size -= shell_item_data_offset;

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
			result = libuna_utf16_string_size_from_utf16_stream(
				  &( shell_item_data[ shell_item_data_offset ] ),
				  string_size,
				  LIBUNA_ENDIAN_LITTLE,
				  &value_string_size,
				  error );
#else
			result = libuna_utf8_string_size_from_utf16_stream(
				  &( shell_item_data[ shell_item_data_offset ] ),
				  string_size,
				  LIBUNA_ENDIAN_LITTLE,
				  &value_string_size,
				  error );
#endif
			if( result != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
				 "%s: unable to determine size of value string.",
				 function );

				goto on_error;
			}
			if( value_string_size > (size_t) ( SSIZE_MAX / sizeof( libcstring_system_character_t ) ) )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_VALUE_EXCEEDS_MAXIMUM,
				 "%s: invalid value string size value exceeds maximum.",
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
				 "%s: unable to create value string.",
				 function );

				goto on_error;
			}
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
			result = libuna_utf16_string_copy_from_utf16_stream(
				  (libuna_utf16_character_t *) value_string,
				  value_string_size,
				  &( shell_item_data[ shell_item_data_offset ] ),
				  string_size,
				  LIBUNA_ENDIAN_LITTLE,
				  error );
#else
			result = libuna_utf8_string_copy_from_utf16_stream(
				  (libuna_utf8_character_t *) value_string,
				  value_string_size,
				  &( shell_item_data[ shell_item_data_offset ] ),
				  string_size,
				  LIBUNA_ENDIAN_LITTLE,
				  error );
#endif
			if( result != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
				 "%s: unable to set value string.",
				 function );

				goto on_error;
			}
			libcnotify_printf(
			 "%s: CPL file path\t\t: %" PRIs_LIBCSTRING_SYSTEM "\n",
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
		for( string_size = shell_item_data_offset;
		     string_size < shell_item_data_size;
		     string_size += 2 )
		{
			if( shell_item_data[ string_size ] == 0 )
			{
				string_size += 2;

				break;
			}
		}
		string_size -= shell_item_data_offset;

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
			result = libuna_utf16_string_size_from_utf16_stream(
				  &( shell_item_data[ shell_item_data_offset ] ),
				  string_size,
				  LIBUNA_ENDIAN_LITTLE,
				  &value_string_size,
				  error );
#else
			result = libuna_utf8_string_size_from_utf16_stream(
				  &( shell_item_data[ shell_item_data_offset ] ),
				  string_size,
				  LIBUNA_ENDIAN_LITTLE,
				  &value_string_size,
				  error );
#endif
			if( result != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
				 "%s: unable to determine size of value string.",
				 function );

				goto on_error;
			}
			if( value_string_size > (size_t) ( SSIZE_MAX / sizeof( libcstring_system_character_t ) ) )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_VALUE_EXCEEDS_MAXIMUM,
				 "%s: invalid value string size value exceeds maximum.",
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
				 "%s: unable to create value string.",
				 function );

				goto on_error;
			}
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
			result = libuna_utf16_string_copy_from_utf16_stream(
				  (libuna_utf16_character_t *) value_string,
				  value_string_size,
				  &( shell_item_data[ shell_item_data_offset ] ),
				  string_size,
				  LIBUNA_ENDIAN_LITTLE,
				  error );
#else
			result = libuna_utf8_string_copy_from_utf16_stream(
				  (libuna_utf8_character_t *) value_string,
				  value_string_size,
				  &( shell_item_data[ shell_item_data_offset ] ),
				  string_size,
				  LIBUNA_ENDIAN_LITTLE,
				  error );
#endif
			if( result != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
				 "%s: unable to set value string.",
				 function );

				goto on_error;
			}
			libcnotify_printf(
			 "%s: name\t\t\t: %" PRIs_LIBCSTRING_SYSTEM "\n",
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
		for( string_size = shell_item_data_offset;
		     string_size < shell_item_data_size;
		     string_size += 2 )
		{
			if( shell_item_data[ string_size ] == 0 )
			{
				string_size += 2;

				break;
			}
		}
		string_size -= shell_item_data_offset;

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
			result = libuna_utf16_string_size_from_utf16_stream(
				  &( shell_item_data[ shell_item_data_offset ] ),
				  string_size,
				  LIBUNA_ENDIAN_LITTLE,
				  &value_string_size,
				  error );
#else
			result = libuna_utf8_string_size_from_utf16_stream(
				  &( shell_item_data[ shell_item_data_offset ] ),
				  string_size,
				  LIBUNA_ENDIAN_LITTLE,
				  &value_string_size,
				  error );
#endif
			if( result != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
				 "%s: unable to determine size of value string.",
				 function );

				goto on_error;
			}
			if( value_string_size > (size_t) ( SSIZE_MAX / sizeof( libcstring_system_character_t ) ) )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_VALUE_EXCEEDS_MAXIMUM,
				 "%s: invalid value string size value exceeds maximum.",
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
				 "%s: unable to create value string.",
				 function );

				goto on_error;
			}
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
			result = libuna_utf16_string_copy_from_utf16_stream(
				  (libuna_utf16_character_t *) value_string,
				  value_string_size,
				  &( shell_item_data[ shell_item_data_offset ] ),
				  string_size,
				  LIBUNA_ENDIAN_LITTLE,
				  error );
#else
			result = libuna_utf8_string_copy_from_utf16_stream(
				  (libuna_utf8_character_t *) value_string,
				  value_string_size,
				  &( shell_item_data[ shell_item_data_offset ] ),
				  string_size,
				  LIBUNA_ENDIAN_LITTLE,
				  error );
#endif
			if( result != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
				 "%s: unable to set value string.",
				 function );

				goto on_error;
			}
			libcnotify_printf(
			 "%s: comments\t\t\t: %" PRIs_LIBCSTRING_SYSTEM "\n",
			 function,
			 value_string );

			memory_free(
			 value_string );

			value_string = NULL;
		}
#endif
		shell_item_data_offset += string_size;
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
	return( -1 );
}

