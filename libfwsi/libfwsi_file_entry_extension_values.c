/*
 * File entry extension values functions
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
#include "libfwsi_file_entry_extension_values.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"
#include "libfwsi_libfdatetime.h"
#include "libfwsi_libuna.h"

/* Creates file entry extension values
 * Make sure the value file_entry_extension_values is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_file_entry_extension_values_initialize(
     libfwsi_file_entry_extension_values_t **file_entry_extension_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_file_entry_extension_values_initialize";

	if( file_entry_extension_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid file entry extension values.",
		 function );

		return( -1 );
	}
	if( *file_entry_extension_values != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid file entry extension values value already set.",
		 function );

		return( -1 );
	}
	*file_entry_extension_values = memory_allocate_structure(
	                                libfwsi_file_entry_extension_values_t );

	if( *file_entry_extension_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create file entry extension values.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *file_entry_extension_values,
	     0,
	     sizeof( libfwsi_file_entry_extension_values_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear file entry extension values.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *file_entry_extension_values != NULL )
	{
		memory_free(
		 *file_entry_extension_values );

		*file_entry_extension_values = NULL;
	}
	return( -1 );
}

/* Frees file entry extension values
 * Returns 1 if successful or -1 on error
 */
int libfwsi_file_entry_extension_values_free(
     libfwsi_file_entry_extension_values_t **file_entry_extension_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_file_entry_extension_values_free";

	if( file_entry_extension_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid file entry extension values.",
		 function );

		return( -1 );
	}
	if( *file_entry_extension_values != NULL )
	{
		if( ( *file_entry_extension_values )->long_name != NULL )
		{
			memory_free(
			 ( *file_entry_extension_values )->long_name );
		}
		if( ( *file_entry_extension_values )->localized_name != NULL )
		{
			memory_free(
			 ( *file_entry_extension_values )->localized_name );
		}
		memory_free(
		 *file_entry_extension_values );

		*file_entry_extension_values = NULL;
	}
	return( 1 );
}

/* Reads the file entry extension values
 * Returns the number of bytes read or -1 on error
 */
ssize_t libfwsi_file_entry_extension_values_read(
         libfwsi_file_entry_extension_values_t *file_entry_extension_values,
         const uint8_t *extension_block_data,
         size_t extension_block_data_size,
         int ascii_codepage,
         libcerror_error_t **error )
{
	static char *function                       = "libfwsi_file_entry_extension_values_read";
	size_t extension_block_data_offset          = 0;
	size_t string_size                          = 0;
	uint32_t signature                          = 0;
	uint16_t long_string_size                   = 0;
	uint16_t version                            = 0;

#if defined( HAVE_DEBUG_OUTPUT )
	libcstring_system_character_t date_time_string[ 32 ];

	libcstring_system_character_t *value_string = NULL;
	libfdatetime_fat_date_time_t *fat_date_time = NULL;
	size_t value_string_size                    = 0;
	uint16_t value_16bit                        = 0;
	int result                                  = 0;
#endif

	if( file_entry_extension_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid file entry extension values.",
		 function );

		return( -1 );
	}
	if( extension_block_data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block data.",
		 function );

		return( -1 );
	}
	if( extension_block_data_size > (size_t) SSIZE_MAX )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: extension block data size exceeds maximum.",
		 function );

		return( -1 );
	}
	/* Do not try to parse unsupported extension block data sizes
	 */
	if( extension_block_data_size < 20 )
	{
		return( 0 );
	}
	/* Do not try to parse unsupported extension block signatures
	 */
	byte_stream_copy_to_uint32_little_endian(
	 &( extension_block_data[ 4 ] ),
	 signature );

	if( signature != 0xbeef0004 )
	{
		return( 0 );
	}
	/* Do not try to parse unsupported version values
	 */
	byte_stream_copy_to_uint32_little_endian(
	 &( extension_block_data[ 2 ] ),
	 version );

	if( ( version != 3 )
	 && ( version != 7 )
	 && ( version != 8 )
	 && ( version != 9 ) )
	{
		return( 0 );
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		if( libfdatetime_fat_date_time_initialize(
		     &fat_date_time,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
			 "%s: unable to create FAT date time.",
			 function );

			goto on_error;
		}
	}
#endif
	file_entry_extension_values->ascii_codepage = ascii_codepage;

	byte_stream_copy_to_uint32_little_endian(
	 &( extension_block_data[ 8 ] ),
	 file_entry_extension_values->creation_time );

	byte_stream_copy_to_uint32_little_endian(
	 &( extension_block_data[ 12 ] ),
	 file_entry_extension_values->access_time );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		if( libfdatetime_fat_date_time_copy_from_byte_stream(
		     fat_date_time,
		     &( extension_block_data[ 8 ] ),
		     4,
		     LIBFDATETIME_ENDIAN_LITTLE,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
			 "%s: unable to copy byte stream to FAT date time.",
			 function );

			goto on_error;
		}
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
		result = libfdatetime_fat_date_time_copy_to_utf16_string(
			  fat_date_time,
			  (uint16_t *) date_time_string,
			  32,
			  LIBFDATETIME_STRING_FORMAT_TYPE_CTIME | LIBFDATETIME_STRING_FORMAT_FLAG_DATE_TIME,
			  error );
#else
		result = libfdatetime_fat_date_time_copy_to_utf8_string(
			  fat_date_time,
			  (uint8_t *) date_time_string,
			  32,
			  LIBFDATETIME_STRING_FORMAT_TYPE_CTIME | LIBFDATETIME_STRING_FORMAT_FLAG_DATE_TIME,
			  error );
#endif
		if( result != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
			 "%s: unable to copy FAT date time to string.",
			 function );

			goto on_error;
		}
		libcnotify_printf(
		 "%s: creation time\t\t\t: %" PRIs_LIBCSTRING_SYSTEM " UTC\n",
		 function,
		 date_time_string );

		if( libfdatetime_fat_date_time_copy_from_byte_stream(
		     fat_date_time,
		     &( extension_block_data[ 12 ] ),
		     4,
		     LIBFDATETIME_ENDIAN_LITTLE,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
			 "%s: unable to copy byte stream to FAT date time.",
			 function );

			goto on_error;
		}
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
		result = libfdatetime_fat_date_time_copy_to_utf16_string(
			  fat_date_time,
			  (uint16_t *) date_time_string,
			  32,
			  LIBFDATETIME_STRING_FORMAT_TYPE_CTIME | LIBFDATETIME_STRING_FORMAT_FLAG_DATE_TIME,
			  error );
#else
		result = libfdatetime_fat_date_time_copy_to_utf8_string(
			  fat_date_time,
			  (uint8_t *) date_time_string,
			  32,
			  LIBFDATETIME_STRING_FORMAT_TYPE_CTIME | LIBFDATETIME_STRING_FORMAT_FLAG_DATE_TIME,
			  error );
#endif
		if( result != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
			 "%s: unable to copy FAT date time to string.",
			 function );

			goto on_error;
		}
		libcnotify_printf(
		 "%s: access time\t\t\t: %" PRIs_LIBCSTRING_SYSTEM " UTC\n",
		 function,
		 date_time_string );

		byte_stream_copy_to_uint16_little_endian(
		 &( extension_block_data[ 16 ] ),
		 value_16bit );
		libcnotify_printf(
		 "%s: unknown1\t\t\t: 0x%04" PRIx16 "\n",
		 function,
		 value_16bit );
	}
#endif
	extension_block_data_offset = 18;

	if( version >= 7 )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			byte_stream_copy_to_uint16_little_endian(
			 &( extension_block_data[ extension_block_data_offset ] ),
			 value_16bit );

			libcnotify_printf(
			 "%s: unknown2\t\t\t: 0x%04" PRIx16 "\n",
			 function,
			 value_16bit );
		}
#endif
		extension_block_data_offset += 2;

		byte_stream_copy_to_uint64_little_endian(
		 &( extension_block_data[ extension_block_data_offset ] ),
		 file_entry_extension_values->file_reference );

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( file_entry_extension_values->file_reference == 0 )
			{
				libcnotify_printf(
				 "%s: file reference\t\t: %" PRIu64 "\n",
				 function,
				 file_entry_extension_values->file_reference );
			}
			else
			{
				libcnotify_printf(
				 "%s: file reference\t\t: MFT entry: %" PRIu64 ", sequence: %" PRIu64 "\n",
				 function,
				 file_entry_extension_values->file_reference & 0xffffffffffffUL,
				 file_entry_extension_values->file_reference >> 48 );
			}
		}
#endif
		extension_block_data_offset += 8;

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			libcnotify_printf(
			 "%s: unknown4:\n",
			 function );
			libcnotify_print_data(
			 &( extension_block_data[ extension_block_data_offset ] ),
			 8,
			 0 );
		}
#endif
		extension_block_data_offset += 8;
	}
	byte_stream_copy_to_uint16_little_endian(
	 &( extension_block_data[ extension_block_data_offset ] ),
	 long_string_size );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: long string size\t\t: %" PRIu16 "\n",
		 function,
		 long_string_size );
	}
#endif
	extension_block_data_offset += 2;

	if( version >= 9 )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			libcnotify_printf(
			 "%s: unknown5:\n",
			 function );
			libcnotify_print_data(
			 &( extension_block_data[ extension_block_data_offset ] ),
			 4,
			 0 );
		}
#endif
		extension_block_data_offset += 4;
	}
	if( version >= 8 )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			libcnotify_printf(
			 "%s: unknown6:\n",
			 function );
			libcnotify_print_data(
			 &( extension_block_data[ extension_block_data_offset ] ),
			 4,
			 0 );
		}
#endif
		extension_block_data_offset += 4;
	}
	/* Determine the long name size
	 */
	for( string_size = extension_block_data_offset;
	     ( string_size + 1 ) < extension_block_data_size - 2;
	     string_size += 2 )
	{
		if( ( extension_block_data[ string_size ] == 0 )
		 && ( extension_block_data[ string_size + 1 ] == 0 ) )
		{
			string_size += 2;

			break;
		}
	}
	string_size -= extension_block_data_offset;

	file_entry_extension_values->long_name = (uint8_t *) memory_allocate(
	                                                      sizeof( uint8_t ) * string_size );

	if( file_entry_extension_values->long_name == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create long name.",
		 function );

		goto on_error;
	}
	if( memory_copy(
	     file_entry_extension_values->long_name,
	     &( extension_block_data[ extension_block_data_offset ] ),
	     string_size ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_COPY_FAILED,
		 "%s: unable to copy long name.",
		 function );

		goto on_error;
	}
	file_entry_extension_values->long_name_size = string_size;

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
		result = libuna_utf16_string_size_from_utf16_stream(
			  file_entry_extension_values->long_name,
			  file_entry_extension_values->long_name_size,
			  LIBUNA_ENDIAN_LITTLE,
			  &value_string_size,
			  error );
#else
		result = libuna_utf8_string_size_from_utf16_stream(
			  file_entry_extension_values->long_name,
			  file_entry_extension_values->long_name_size,
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
			 "%s: unable to determine size of long name string.",
			 function );

			goto on_error;
		}
		if( value_string_size > (size_t) ( SSIZE_MAX / sizeof( libcstring_system_character_t ) ) )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_VALUE_EXCEEDS_MAXIMUM,
			 "%s: invalid long name string size value exceeds maximum.",
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
			 "%s: unable to create long name string.",
			 function );

			goto on_error;
		}
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
		result = libuna_utf16_string_copy_from_utf16_stream(
			  (libuna_utf16_character_t *) value_string,
			  value_string_size,
			  file_entry_extension_values->long_name,
			  file_entry_extension_values->long_name_size,
			  LIBUNA_ENDIAN_LITTLE,
			  error );
#else
		result = libuna_utf8_string_copy_from_utf16_stream(
			  (libuna_utf8_character_t *) value_string,
			  value_string_size,
			  file_entry_extension_values->long_name,
			  file_entry_extension_values->long_name_size,
			  LIBUNA_ENDIAN_LITTLE,
			  error );
#endif
		if( result != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
			 "%s: unable to set long name string.",
			 function );

			goto on_error;
		}
		libcnotify_printf(
		 "%s: long name\t\t\t: %" PRIs_LIBCSTRING_SYSTEM "\n",
		 function,
		 value_string );

		memory_free(
		 value_string );

		value_string = NULL;
	}
#endif
	extension_block_data_offset += string_size;

	if( long_string_size > 0 )
	{
		if( version >= 7 )
		{
			/* Determine the localized name size
			 */
			for( string_size = extension_block_data_offset;
			     ( string_size + 1 ) < extension_block_data_size - 2;
			     string_size += 2 )
			{
				if( ( extension_block_data[ string_size ] == 0 )
				 && ( extension_block_data[ string_size + 1 ] == 0 ) )
				{
					string_size += 2;

					break;
				}
			}
			string_size -= extension_block_data_offset;

			file_entry_extension_values->localized_name = (uint8_t *) memory_allocate(
			                                                           sizeof( uint8_t ) * string_size );

			if( file_entry_extension_values->localized_name == NULL )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_MEMORY,
				 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
				 "%s: unable to create localized name.",
				 function );

				goto on_error;
			}
			if( memory_copy(
			     file_entry_extension_values->localized_name,
			     &( extension_block_data[ extension_block_data_offset ] ),
			     string_size ) == NULL )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_MEMORY,
				 LIBCERROR_MEMORY_ERROR_COPY_FAILED,
				 "%s: unable to copy localized name.",
				 function );

				goto on_error;
			}
			file_entry_extension_values->localized_name_size = string_size;

#if defined( HAVE_DEBUG_OUTPUT )
			if( libcnotify_verbose != 0 )
			{
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
				result = libuna_utf16_string_size_from_utf16_stream(
					  file_entry_extension_values->localized_name,
					  file_entry_extension_values->localized_name_size,
					  LIBUNA_ENDIAN_LITTLE,
					  &value_string_size,
					  error );
#else
				result = libuna_utf8_string_size_from_utf16_stream(
					  file_entry_extension_values->localized_name,
					  file_entry_extension_values->localized_name_size,
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
					 "%s: unable to determine size of localized name string.",
					 function );

					goto on_error;
				}
				if( value_string_size > (size_t) ( SSIZE_MAX / sizeof( libcstring_system_character_t ) ) )
				{
					libcerror_error_set(
					 error,
					 LIBCERROR_ERROR_DOMAIN_RUNTIME,
					 LIBCERROR_RUNTIME_ERROR_VALUE_EXCEEDS_MAXIMUM,
					 "%s: invalid localized name string size value exceeds maximum.",
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
					 "%s: unable to create localized name string.",
					 function );

					goto on_error;
				}
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
				result = libuna_utf16_string_copy_from_utf16_stream(
					  (libuna_utf16_character_t *) value_string,
					  value_string_size,
					  file_entry_extension_values->localized_name,
					  file_entry_extension_values->localized_name_size,
					  LIBUNA_ENDIAN_LITTLE,
					  error );
#else
				result = libuna_utf8_string_copy_from_utf16_stream(
					  (libuna_utf8_character_t *) value_string,
					  value_string_size,
					  file_entry_extension_values->localized_name,
					  file_entry_extension_values->localized_name_size,
					  LIBUNA_ENDIAN_LITTLE,
					  error );
#endif
				if( result != 1 )
				{
					libcerror_error_set(
					 error,
					 LIBCERROR_ERROR_DOMAIN_RUNTIME,
					 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
					 "%s: unable to set localized name string.",
					 function );

					goto on_error;
				}
				libcnotify_printf(
				 "%s: localized name\t\t: %" PRIs_LIBCSTRING_SYSTEM "\n",
				 function,
				 value_string );

				memory_free(
				 value_string );

				value_string = NULL;
			}
#endif
		}
		else if( version >= 3 )
		{
			/* Determine the localized name size
			 */
			for( string_size = extension_block_data_offset;
			     string_size < extension_block_data_size - 2;
			     string_size += 1 )
			{
				if( extension_block_data[ string_size ] == 0 )
				{
					string_size += 1;

					break;
				}
			}
			string_size -= extension_block_data_offset;

			file_entry_extension_values->localized_name = (uint8_t *) memory_allocate(
			                                                           sizeof( uint8_t ) * string_size );

			if( file_entry_extension_values->localized_name == NULL )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_MEMORY,
				 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
				 "%s: unable to create localized name.",
				 function );

				goto on_error;
			}
			if( memory_copy(
			     file_entry_extension_values->localized_name,
			     &( extension_block_data[ extension_block_data_offset ] ),
			     string_size ) == NULL )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_MEMORY,
				 LIBCERROR_MEMORY_ERROR_COPY_FAILED,
				 "%s: unable to copy localized name.",
				 function );

				goto on_error;
			}
			file_entry_extension_values->localized_name_size = string_size;

#if defined( HAVE_DEBUG_OUTPUT )
			if( libcnotify_verbose != 0 )
			{
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
				result = libuna_utf16_string_size_from_byte_stream(
					  file_entry_extension_values->localized_name,
					  file_entry_extension_values->localized_name_size,
					  ascii_codepage,
					  &value_string_size,
					  error );
#else
				result = libuna_utf8_string_size_from_byte_stream(
					  file_entry_extension_values->localized_name,
					  file_entry_extension_values->localized_name_size,
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
					 "%s: unable to determine size of localized name string.",
					 function );

					goto on_error;
				}
				if( value_string_size > (size_t) ( SSIZE_MAX / sizeof( libcstring_system_character_t ) ) )
				{
					libcerror_error_set(
					 error,
					 LIBCERROR_ERROR_DOMAIN_RUNTIME,
					 LIBCERROR_RUNTIME_ERROR_VALUE_EXCEEDS_MAXIMUM,
					 "%s: invalid localized name string size value exceeds maximum.",
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
					 "%s: unable to create localized name string.",
					 function );

					goto on_error;
				}
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
				result = libuna_utf16_string_copy_from_byte_stream(
					  (libuna_utf16_character_t *) value_string,
					  value_string_size,
					  file_entry_extension_values->localized_name,
					  file_entry_extension_values->localized_name_size,
					  ascii_codepage,
					  error );
#else
				result = libuna_utf8_string_copy_from_byte_stream(
					  (libuna_utf8_character_t *) value_string,
					  value_string_size,
					  file_entry_extension_values->localized_name,
					  file_entry_extension_values->localized_name_size,
					  ascii_codepage,
					  error );
#endif
				if( result != 1 )
				{
					libcerror_error_set(
					 error,
					 LIBCERROR_ERROR_DOMAIN_RUNTIME,
					 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
					 "%s: unable to set localized name string.",
					 function );

					goto on_error;
				}
				libcnotify_printf(
				 "%s: localized name\t\t: %" PRIs_LIBCSTRING_SYSTEM "\n",
				 function,
				 value_string );

				memory_free(
				 value_string );

				value_string = NULL;
			}
#endif
		}
		extension_block_data_offset += string_size;
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		if( libfdatetime_fat_date_time_free(
		     &fat_date_time,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
			 "%s: unable to free FAT date time.",
			 function );

			goto on_error;
		}
		libcnotify_printf(
		 "\n" );
	}
#endif
	return( (ssize_t) extension_block_data_offset );

on_error:
#if defined( HAVE_DEBUG_OUTPUT )
	if( value_string != NULL )
	{
		memory_free(
		 value_string );
	}
	if( fat_date_time != NULL )
	{
		libfdatetime_fat_date_time_free(
		 &fat_date_time,
		 NULL );
	}
#endif
	if( file_entry_extension_values->localized_name != NULL )
	{
		memory_free(
		 file_entry_extension_values->localized_name );

		file_entry_extension_values->localized_name = NULL;
	}
	file_entry_extension_values->localized_name_size = 0;

	if( file_entry_extension_values->long_name != NULL )
	{
		memory_free(
		 file_entry_extension_values->long_name );

		file_entry_extension_values->long_name = NULL;
	}
	file_entry_extension_values->long_name_size = 0;

	return( -1 );
}

