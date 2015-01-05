/*
 * MTP storage device file entry (shell item) values functions
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

#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"
#include "libfwsi_libfguid.h"
#include "libfwsi_libfole.h"
#include "libfwsi_libuna.h"
#include "libfwsi_mtp_file_entry_values.h"

/* Creates MTP file entry values
 * Make sure the value mtp_file_entry_values is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_mtp_file_entry_values_initialize(
     libfwsi_mtp_file_entry_values_t **mtp_file_entry_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_mtp_file_entry_values_initialize";

	if( mtp_file_entry_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid MTP file entry values.",
		 function );

		return( -1 );
	}
	if( *mtp_file_entry_values != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid MTP file entry values value already set.",
		 function );

		return( -1 );
	}
	*mtp_file_entry_values = memory_allocate_structure(
	                          libfwsi_mtp_file_entry_values_t );

	if( *mtp_file_entry_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create MTP file entry values.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *mtp_file_entry_values,
	     0,
	     sizeof( libfwsi_mtp_file_entry_values_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear MTP file entry values.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *mtp_file_entry_values != NULL )
	{
		memory_free(
		 *mtp_file_entry_values );

		*mtp_file_entry_values = NULL;
	}
	return( -1 );
}

/* Frees MTP file entry values
 * Returns 1 if successful or -1 on error
 */
int libfwsi_mtp_file_entry_values_free(
     libfwsi_mtp_file_entry_values_t **mtp_file_entry_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_mtp_file_entry_values_free";

	if( mtp_file_entry_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid MTP file entry values.",
		 function );

		return( -1 );
	}
	if( *mtp_file_entry_values != NULL )
	{
		memory_free(
		 *mtp_file_entry_values );

		*mtp_file_entry_values = NULL;
	}
	return( 1 );
}

/* Reads the MTP file entry values
 * Returns the number of bytes read if successful, 0 if not able to read or -1 on error
 */
ssize_t libfwsi_mtp_file_entry_values_read(
         libfwsi_mtp_file_entry_values_t *mtp_file_entry_values,
         const uint8_t *shell_item_data,
         size_t shell_item_data_size,
         libcerror_error_t **error )
{
	static char *function                       = "libfwsi_mtp_file_entry_values_read";
	size_t shell_item_data_offset               = 0;
        uint32_t signature                          = 0;
	uint32_t identifier_string_size             = 0;
	uint32_t name_string_size                   = 0;
	uint32_t name2_string_size                  = 0;
	uint32_t number_of_properties               = 0;
	uint32_t property_index                     = 0;
	uint32_t property_value_type                = 0;
	uint32_t string_size                        = 0;
	uint16_t data_size                          = 0;

#if defined( HAVE_DEBUG_OUTPUT )
        libcstring_system_character_t guid_string[ 48 ];

	libcstring_system_character_t *value_string = NULL;
        libfguid_identifier_t *guid                 = NULL;
	size_t value_string_size                    = 0;
	uint32_t value_32bit                        = 0;
	uint16_t value_16bit                        = 0;
	int result                                  = 0;
#endif

	if( mtp_file_entry_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid MTP file entry values.",
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
	if( shell_item_data_size < 10 )
	{
		return( 0 );
	}
	/* Do not try to parse unsupported shell item signatures
	 */
	byte_stream_copy_to_uint32_little_endian(
	 &( shell_item_data[ 6 ] ),
	 signature );

	if( signature != 0x07192006UL )
	{
		return( 0 );
	}
	byte_stream_copy_to_uint32_little_endian(
	 &( shell_item_data[ 4 ] ),
	 data_size );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: class type indicator\t\t: 0x%02" PRIx8 "\n",
		 function,
		 shell_item_data[ 2 ] );

		libcnotify_printf(
		 "%s: unknown1\t\t\t\t: 0x%02" PRIx8 "\n",
		 function,
		 shell_item_data[ 3 ] );

		libcnotify_printf(
		 "%s: data size\t\t\t\t: %" PRIu16 "\n",
		 function,
		 data_size );

		libcnotify_printf(
		 "%s: signature\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 signature );
	}
#endif
	if( data_size == 0 )
	{
		return( 10 );
	}
	if( ( data_size < 44 )
	 && ( data_size > ( shell_item_data_size - 10 ) ) )
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
	}
#endif
/* TODO */
	byte_stream_copy_to_uint32_little_endian(
	 &( shell_item_data[ 62 ] ),
	 name_string_size );

	byte_stream_copy_to_uint32_little_endian(
	 &( shell_item_data[ 66 ] ),
	 name2_string_size );

	byte_stream_copy_to_uint32_little_endian(
	 &( shell_item_data[ 70 ] ),
	 identifier_string_size );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		byte_stream_copy_to_uint32_little_endian(
		 &( shell_item_data[ 10 ] ),
		 value_32bit );
		libcnotify_printf(
		 "%s: unknown2\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

		byte_stream_copy_to_uint16_little_endian(
		 &( shell_item_data[ 14 ] ),
		 value_16bit );
		libcnotify_printf(
		 "%s: unknown3\t\t\t\t: 0x%04" PRIx16 "\n",
		 function,
		 value_16bit );

		byte_stream_copy_to_uint16_little_endian(
		 &( shell_item_data[ 16 ] ),
		 value_16bit );
		libcnotify_printf(
		 "%s: unknown4\t\t\t\t: 0x%04" PRIx16 "\n",
		 function,
		 value_16bit );

		byte_stream_copy_to_uint16_little_endian(
		 &( shell_item_data[ 18 ] ),
		 value_16bit );
		libcnotify_printf(
		 "%s: unknown5\t\t\t\t: 0x%04" PRIx16 "\n",
		 function,
		 value_16bit );

		byte_stream_copy_to_uint16_little_endian(
		 &( shell_item_data[ 20 ] ),
		 value_16bit );
		libcnotify_printf(
		 "%s: unknown6\t\t\t\t: 0x%04" PRIx16 "\n",
		 function,
		 value_16bit );

		byte_stream_copy_to_uint32_little_endian(
		 &( shell_item_data[ 22 ] ),
		 value_32bit );
		libcnotify_printf(
		 "%s: unknown7\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

		libcnotify_printf(
		 "%s: unknown8:\n",
		 function );
		libcnotify_print_data(
		 &( shell_item_data[ 26 ] ),
		 8,
		 0 );

		byte_stream_copy_to_uint32_little_endian(
		 &( shell_item_data[ 34 ] ),
		 value_32bit );
		libcnotify_printf(
		 "%s: unknown9\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

/* TODO */
		libcnotify_printf(
		 "%s: name string size\t\t\t: %" PRIu32 "\n",
		 function,
		 name_string_size );

		libcnotify_printf(
		 "%s: name string size\t\t\t: %" PRIu32 "\n",
		 function,
		 name2_string_size );

		libcnotify_printf(
		 "%s: identifier string size\t\t: %" PRIu32 "\n",
		 function,
		 identifier_string_size );
	}
#endif
	shell_item_data_offset = 74;

	if( name_string_size > 0 )
	{
		name_string_size *= 2;

/* TODO check bounds */
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
			result = libuna_utf16_string_size_from_utf16_stream(
				  &( shell_item_data[ shell_item_data_offset ] ),
				  name_string_size,
				  LIBUNA_ENDIAN_LITTLE,
				  &value_string_size,
				  error );
#else
			result = libuna_utf8_string_size_from_utf16_stream(
				  &( shell_item_data[ shell_item_data_offset ] ),
				  name_string_size,
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
				 "%s: unable to determine size of name string.",
				 function );

				goto on_error;
			}
			if( value_string_size > (size_t) ( SSIZE_MAX / sizeof( libcstring_system_character_t ) ) )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_VALUE_EXCEEDS_MAXIMUM,
				 "%s: invalid name string size value exceeds maximum.",
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
				 "%s: unable to create name string.",
				 function );

				goto on_error;
			}
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
			result = libuna_utf16_string_copy_from_utf16_stream(
				  (libuna_utf16_character_t *) value_string,
				  value_string_size,
				  &( shell_item_data[ shell_item_data_offset ] ),
				  name_string_size,
				  LIBUNA_ENDIAN_LITTLE,
				  error );
#else
			result = libuna_utf8_string_copy_from_utf16_stream(
				  (libuna_utf8_character_t *) value_string,
				  value_string_size,
				  &( shell_item_data[ shell_item_data_offset ] ),
				  name_string_size,
				  LIBUNA_ENDIAN_LITTLE,
				  error );
#endif
			if( result != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
				 "%s: unable to set name string.",
				 function );

				goto on_error;
			}
			libcnotify_printf(
			 "%s: name\t\t\t\t: %" PRIs_LIBCSTRING_SYSTEM "\n",
			 function,
			 value_string );

			memory_free(
			 value_string );

			value_string = NULL;
		}
#endif
		shell_item_data_offset += name_string_size;
	}
	if( name2_string_size > 0 )
	{
		name2_string_size *= 2;

/* TODO check bounds */
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
			result = libuna_utf16_string_size_from_utf16_stream(
				  &( shell_item_data[ shell_item_data_offset ] ),
				  name2_string_size,
				  LIBUNA_ENDIAN_LITTLE,
				  &value_string_size,
				  error );
#else
			result = libuna_utf8_string_size_from_utf16_stream(
				  &( shell_item_data[ shell_item_data_offset ] ),
				  name2_string_size,
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
				 "%s: unable to determine size of name string.",
				 function );

				goto on_error;
			}
			if( value_string_size > (size_t) ( SSIZE_MAX / sizeof( libcstring_system_character_t ) ) )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_VALUE_EXCEEDS_MAXIMUM,
				 "%s: invalid name string size value exceeds maximum.",
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
				 "%s: unable to create name string.",
				 function );

				goto on_error;
			}
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
			result = libuna_utf16_string_copy_from_utf16_stream(
				  (libuna_utf16_character_t *) value_string,
				  value_string_size,
				  &( shell_item_data[ shell_item_data_offset ] ),
				  name2_string_size,
				  LIBUNA_ENDIAN_LITTLE,
				  error );
#else
			result = libuna_utf8_string_copy_from_utf16_stream(
				  (libuna_utf8_character_t *) value_string,
				  value_string_size,
				  &( shell_item_data[ shell_item_data_offset ] ),
				  name2_string_size,
				  LIBUNA_ENDIAN_LITTLE,
				  error );
#endif
			if( result != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
				 "%s: unable to set name string.",
				 function );

				goto on_error;
			}
			libcnotify_printf(
			 "%s: name\t\t\t\t: %" PRIs_LIBCSTRING_SYSTEM "\n",
			 function,
			 value_string );

			memory_free(
			 value_string );

			value_string = NULL;
		}
#endif
		shell_item_data_offset += name2_string_size;
	}
	if( identifier_string_size > 0 )
	{
		identifier_string_size *= 2;

/* TODO check bounds */
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
			result = libuna_utf16_string_size_from_utf16_stream(
				  &( shell_item_data[ shell_item_data_offset ] ),
				  identifier_string_size,
				  LIBUNA_ENDIAN_LITTLE,
				  &value_string_size,
				  error );
#else
			result = libuna_utf8_string_size_from_utf16_stream(
				  &( shell_item_data[ shell_item_data_offset ] ),
				  identifier_string_size,
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
				 "%s: unable to determine size of identifier string.",
				 function );

				goto on_error;
			}
			if( value_string_size > (size_t) ( SSIZE_MAX / sizeof( libcstring_system_character_t ) ) )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_VALUE_EXCEEDS_MAXIMUM,
				 "%s: invalid identifier string size value exceeds maximum.",
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
				 "%s: unable to create identifier string.",
				 function );

				goto on_error;
			}
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
			result = libuna_utf16_string_copy_from_utf16_stream(
				  (libuna_utf16_character_t *) value_string,
				  value_string_size,
				  &( shell_item_data[ shell_item_data_offset ] ),
				  identifier_string_size,
				  LIBUNA_ENDIAN_LITTLE,
				  error );
#else
			result = libuna_utf8_string_copy_from_utf16_stream(
				  (libuna_utf8_character_t *) value_string,
				  value_string_size,
				  &( shell_item_data[ shell_item_data_offset ] ),
				  identifier_string_size,
				  LIBUNA_ENDIAN_LITTLE,
				  error );
#endif
			if( result != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
				 "%s: unable to set identifier string.",
				 function );

				goto on_error;
			}
			libcnotify_printf(
			 "%s: identifier\t\t\t\t: %" PRIs_LIBCSTRING_SYSTEM "\n",
			 function,
			 value_string );

			memory_free(
			 value_string );

			value_string = NULL;
		}
#endif
		shell_item_data_offset += identifier_string_size;
	}
/* TODO refactor */
	if( shell_item_data_offset < ( shell_item_data_size - 4 ) )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			byte_stream_copy_to_uint32_little_endian(
			 &( shell_item_data[ shell_item_data_offset ] ),
			 value_32bit );
			libcnotify_printf(
			 "%s: unknown10\t\t\t\t: 0x%08" PRIx32 "\n",
			 function,
			 value_32bit );
		}
#endif
		shell_item_data_offset += 4;
	}
	if( shell_item_data_offset < ( shell_item_data_size - 16 ) )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( libfguid_identifier_copy_from_byte_stream(
			     guid,
			     &( shell_item_data[ shell_item_data_offset ] ),
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
				  LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
				  error );
#else
			result = libfguid_identifier_copy_to_utf8_string(
				  guid,
				  (uint8_t *) guid_string,
				  48,
				  LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
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
			 "%s: class identifier\t\t\t: %" PRIs_LIBCSTRING_SYSTEM "\n",
			 function,
			 guid_string );
		}
#endif
		shell_item_data_offset += 16;
	}
	if( shell_item_data_offset < ( shell_item_data_size - 4 ) )
	{
		byte_stream_copy_to_uint32_little_endian(
		 &( shell_item_data[ shell_item_data_offset ] ),
		 number_of_properties );

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			libcnotify_printf(
			 "%s: number of properties\t\t: %" PRIu32 "\n",
			 function,
			 number_of_properties );
		}
#endif
		shell_item_data_offset += 4;
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "\n" );
	}
#endif
	for( property_index = 0;
	     property_index < number_of_properties;
	     property_index++ )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			libcnotify_printf(
			 "%s: property value: %" PRIu32 "\n",
			 function,
			 property_index );
		}
#endif
/* TODO at least 24 bytes in size ? */
		if( shell_item_data_offset < ( shell_item_data_size - 16 ) )
		{
#if defined( HAVE_DEBUG_OUTPUT )
			if( libcnotify_verbose != 0 )
			{
				if( libfguid_identifier_copy_from_byte_stream(
				     guid,
				     &( shell_item_data[ shell_item_data_offset ] ),
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
					  LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
					  error );
#else
				result = libfguid_identifier_copy_to_utf8_string(
					  guid,
					  (uint8_t *) guid_string,
					  48,
					  LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
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
				 "%s: property set identifier\t\t: %" PRIs_LIBCSTRING_SYSTEM "\n",
				 function,
				 guid_string );
			}
#endif
			shell_item_data_offset += 16;
		}
		if( shell_item_data_offset < ( shell_item_data_size - 4 ) )
		{
#if defined( HAVE_DEBUG_OUTPUT )
			if( libcnotify_verbose != 0 )
			{
				byte_stream_copy_to_uint32_little_endian(
				 &( shell_item_data[ shell_item_data_offset ] ),
				 value_32bit );
				libcnotify_printf(
				 "%s: property value identifier\t\t: %" PRIu32 "\n",
				 function,
				 value_32bit );
			}
#endif
			shell_item_data_offset += 4;
		}
		if( shell_item_data_offset < ( shell_item_data_size - 4 ) )
		{
			byte_stream_copy_to_uint32_little_endian(
			 &( shell_item_data[ shell_item_data_offset ] ),
			 property_value_type );

#if defined( HAVE_DEBUG_OUTPUT )
			if( libcnotify_verbose != 0 )
			{
				libcnotify_printf(
				 "%s: property value type\t\t\t: 0x%08" PRIx32 " (%s : %s)\n",
				 function,
				 property_value_type,
				 libfole_value_type_get_identifier(
				  property_value_type ),
				 libfole_value_type_get_description(
				  property_value_type ) );
			}
#endif
			shell_item_data_offset += 4;
		}
/* TODO merge with FOLE */
		switch( property_value_type )
		{
			case 0x00000005UL:
			case 0x00000007UL:
			case 0x00000015UL:
#if defined( HAVE_DEBUG_OUTPUT )
				if( libcnotify_verbose != 0 )
				{
					libcnotify_printf(
					 "%s: value data:\n",
					 function );
					libcnotify_print_data(
					 &( shell_item_data[ shell_item_data_offset ] ),
					 8,
					 0 );
				}
#endif
				shell_item_data_offset += 8;

				break;

			case 0x0000000bUL:
			case 0x00000012UL:
				if( shell_item_data_offset < ( shell_item_data_size - 2 ) )
				{
#if defined( HAVE_DEBUG_OUTPUT )
					if( libcnotify_verbose != 0 )
					{
						byte_stream_copy_to_uint16_little_endian(
						 &( shell_item_data[ shell_item_data_offset ] ),
						 value_16bit );
						libcnotify_printf(
						 "%s: value\t\t\t\t: 0x%04" PRIx16 "\n",
						 function,
						 value_16bit );

						libcnotify_printf(
						 "\n" );
					}
#endif
					shell_item_data_offset += 2;
				}
				break;

			case 0x0000000aUL:
			case 0x00000013UL:
				if( shell_item_data_offset < ( shell_item_data_size - 4 ) )
				{
#if defined( HAVE_DEBUG_OUTPUT )
					if( libcnotify_verbose != 0 )
					{
						byte_stream_copy_to_uint32_little_endian(
						 &( shell_item_data[ shell_item_data_offset ] ),
						 value_32bit );
						libcnotify_printf(
						 "%s: value\t\t\t\t: 0x%08" PRIx32 "\n",
						 function,
						 value_32bit );

						libcnotify_printf(
						 "\n" );
					}
#endif
					shell_item_data_offset += 4;
				}
				break;

			case 0x0000001fUL:
				if( shell_item_data_offset < ( shell_item_data_size - 4 ) )
				{
					byte_stream_copy_to_uint32_little_endian(
					 &( shell_item_data[ shell_item_data_offset ] ),
					 string_size );

#if defined( HAVE_DEBUG_OUTPUT )
					if( libcnotify_verbose != 0 )
					{
						libcnotify_printf(
						 "%s: string size\t\t\t\t: %" PRIu32 "\n",
						 function,
						 string_size );
					}
#endif
					shell_item_data_offset += 4;

					if( string_size > 0 )
					{
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
								 "%s: unable to determine size of string.",
								 function );

								goto on_error;
							}
							if( value_string_size > (size_t) ( SSIZE_MAX / sizeof( libcstring_system_character_t ) ) )
							{
								libcerror_error_set(
								 error,
								 LIBCERROR_ERROR_DOMAIN_RUNTIME,
								 LIBCERROR_RUNTIME_ERROR_VALUE_EXCEEDS_MAXIMUM,
								 "%s: invalid string size value exceeds maximum.",
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
								 "%s: unable to create string.",
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
								 "%s: unable to set string.",
								 function );

								goto on_error;
							}
							libcnotify_printf(
							 "%s: string\t\t\t\t: %" PRIs_LIBCSTRING_SYSTEM "\n",
							 function,
							 value_string );

							memory_free(
							 value_string );

							value_string = NULL;

							libcnotify_printf(
							 "\n" );
						}
#endif
						shell_item_data_offset += string_size;
					}
				}
				break;

			case 0x00000048UL:
				if( shell_item_data_offset < ( shell_item_data_size - 16 ) )
				{
#if defined( HAVE_DEBUG_OUTPUT )
					if( libcnotify_verbose != 0 )
					{
						if( libfguid_identifier_copy_from_byte_stream(
						     guid,
						     &( shell_item_data[ shell_item_data_offset ] ),
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
							  LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
							  error );
#else
						result = libfguid_identifier_copy_to_utf8_string(
							  guid,
							  (uint8_t *) guid_string,
							  48,
							  LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
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
						 "%s: GUID\t\t\t\t: %" PRIs_LIBCSTRING_SYSTEM "\n",
						 function,
						 guid_string );

						libcnotify_printf(
						 "\n" );
					}
#endif
					shell_item_data_offset += 16;
				}
				break;
		}
	}
/* TODO */

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
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
	if( guid != NULL )
	{
		libfguid_identifier_free(
		 &guid,
		 NULL );
	}
#endif
	return( -1 );
}

