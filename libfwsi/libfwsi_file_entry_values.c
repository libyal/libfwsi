/*
 * File entry (shell item) values functions
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
#include "libfwsi_file_attributes.h"
#include "libfwsi_file_entry_values.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"
#include "libfwsi_libfdatetime.h"
#include "libfwsi_libfguid.h"
#include "libfwsi_libuna.h"
#include "libfwsi_shell_folder_identifier.h"
#include "libfwsi_unused.h"

/* Creates file entry values
 * Make sure the value file_entry_values is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_file_entry_values_initialize(
     libfwsi_file_entry_values_t **file_entry_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_file_entry_values_initialize";

	if( file_entry_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid file entry values.",
		 function );

		return( -1 );
	}
	if( *file_entry_values != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid file entry values value already set.",
		 function );

		return( -1 );
	}
	*file_entry_values = memory_allocate_structure(
	                      libfwsi_file_entry_values_t );

	if( *file_entry_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create file entry values.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *file_entry_values,
	     0,
	     sizeof( libfwsi_file_entry_values_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear file entry values.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *file_entry_values != NULL )
	{
		memory_free(
		 *file_entry_values );

		*file_entry_values = NULL;
	}
	return( -1 );
}

/* Frees file entry values
 * Returns 1 if successful or -1 on error
 */
int libfwsi_file_entry_values_free(
     libfwsi_file_entry_values_t **file_entry_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_file_entry_values_free";

	if( file_entry_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid file entry values.",
		 function );

		return( -1 );
	}
	if( *file_entry_values != NULL )
	{
		if( ( *file_entry_values )->name != NULL )
		{
			memory_free(
			 ( *file_entry_values )->name );
		}
		memory_free(
		 *file_entry_values );

		*file_entry_values = NULL;
	}
	return( 1 );
}

/* Reads the file entry values
 * Returns 1 if successful, 0 if not supported or -1 on error
 */
int libfwsi_file_entry_values_read_data(
     libfwsi_file_entry_values_t *file_entry_values,
     const uint8_t *data,
     size_t data_size,
     int ascii_codepage,
     libcerror_error_t **error )
{
	static char *function          = "libfwsi_file_entry_values_read_data";
	size_t data_offset             = 0;
	size_t string_alignment_offset = 0;
	size_t string_alignment_size   = 0;
	size_t string_size             = 0;
	uint16_t extension_size        = 0;
	uint8_t class_type_indicator   = 0;
	int has_swn1                   = 0;

#if defined( HAVE_DEBUG_OUTPUT )
	uint64_t value_64bit           = 0;
	uint32_t value_32bit           = 0;
	uint16_t value_16bit           = 0;
#endif

	if( file_entry_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid file entry values.",
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
	if( data_size < 14 )
	{
		return( 0 );
	}
	/* Do not try to parse unknown class type indicators
	 */
	if( ( data[ 2 ] != 0x30 )
	 && ( data[ 2 ] != 0x31 )
	 && ( data[ 2 ] != 0x32 )
	 && ( data[ 2 ] != 0x35 )
	 && ( data[ 2 ] != 0x36 )
	 && ( data[ 2 ] != 0xb1 ) )
	{
		return( 0 );
	}
	class_type_indicator = data[ 2 ];

	byte_stream_copy_to_uint32_little_endian(
	 &( data[ 4 ] ),
	 file_entry_values->file_size );

	byte_stream_copy_to_uint32_little_endian(
	 &( data[ 8 ] ),
	 file_entry_values->modification_time );

	byte_stream_copy_to_uint16_little_endian(
	 &( data[ 12 ] ),
	 file_entry_values->file_attribute_flags );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: unknown1\t\t\t\t: 0x%02" PRIx8 "\n",
		 function,
		 data[ 3 ] );

		libcnotify_printf(
		 "%s: file size\t\t\t\t: %" PRIu32 "\n",
		 function,
		 file_entry_values->file_size );

		if( libfwsi_debug_print_fat_date_time_value(
		     function,
		     "modification time\t\t\t",
		     &( data[ 8 ] ),
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

			goto on_error;
		}
		libcnotify_printf(
		 "%s: file attribute flags\t\t: 0x%04" PRIx16 "\n",
		 function,
		 file_entry_values->file_attribute_flags );
		libfwsi_file_attributes_print(
		 file_entry_values->file_attribute_flags );
		libcnotify_printf(
		 "\n" );
	}
#endif
	data_offset = 14;

	/* Check for SWN1 signature at offset -30
	 */
	has_swn1 = -1;

	if( ( data_offset + 30 ) <= data_size )
	{
		has_swn1 = memory_compare(
		            &( data[ data_size - 30 ] ),
		            "S.W.N.1",
		            7 );
	}
	if( ( has_swn1 == 0 )
	 || ( ( class_type_indicator & LIBFWSI_FILE_ENTRY_FLAG_IS_UNICODE ) != 0 ) )
	{
		file_entry_values->is_unicode = 1;
	}
	else
	{
		file_entry_values->is_unicode = 0;
	}
	string_size = data_offset;

	/* Determine the size of the primary name
	 */
	if( file_entry_values->is_unicode != 0 )
	{
		while( ( string_size + 1 ) < data_size )
		{
			if( ( data[ string_size ] == 0 )
			 && ( data[ string_size + 1 ] == 0 ) )
			{
				string_size += 2;

				break;
			}
			string_size += 2;
		}
		string_size          -= data_offset;
		string_alignment_size = 0;
	}
	else
	{
		while( string_size < data_size )
		{
			if( data[ string_size ] == 0 )
			{
				string_size++;

				break;
			}
			string_size++;
		}
		string_size          -= data_offset;
		string_alignment_size = string_size % 2;
	}
	if( ( string_size == 0 )
	 || ( string_size > (size_t) MEMORY_MAXIMUM_ALLOCATION_SIZE ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid name string size value out of bounds.",
		 function );

		goto on_error;
	}
	file_entry_values->name = (uint8_t *) memory_allocate(
	                                       sizeof( uint8_t ) * string_size );

	if( file_entry_values->name == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create name.",
		 function );

		goto on_error;
	}
	if( memory_copy(
	     file_entry_values->name,
	     &( data[ data_offset ] ),
	     string_size ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_COPY_FAILED,
		 "%s: unable to copy name.",
		 function );

		goto on_error;
	}
	file_entry_values->name_size = string_size;

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		if( file_entry_values->is_unicode != 0 )
		{
			if( libfwsi_debug_print_utf16_string_value(
			     function,
			     "primary name\t\t\t",
			     file_entry_values->name,
			     file_entry_values->name_size,
			     LIBUNA_ENDIAN_LITTLE,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_PRINT_FAILED,
				 "%s: unable to print UTF-16 string value.",
				 function );

				goto on_error;
			}
		}
		else
		{
			if( libfwsi_debug_print_string_value(
			     function,
			     "primary name\t\t\t",
			     file_entry_values->name,
			     file_entry_values->name_size,
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
	}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

	data_offset            += string_size;
	string_alignment_offset = data_offset + string_alignment_size;

	if( ( string_alignment_offset < data_size )
	 && ( ( data_size - string_alignment_offset ) >= 2 ) )
	{
		/* Look ahead if the extension size makes sense
		 * if not we're dealing with a Windows 2000 or earlier entry
		 * otherwise a Windows XP or later
		 */
		byte_stream_copy_to_uint16_little_endian(
		 &( data[ string_alignment_offset ] ),
		 extension_size );
	}
	if( ( has_swn1 != 0 )
	 && ( ( ( data_size - string_alignment_offset ) < 2 )
	  ||  ( extension_size > data_size ) ) )
	{
		file_entry_values->in_pre_xp_format = 1;

		string_size = data_offset;

		/* Determine the size of the secondary name
		 */
		if( file_entry_values->is_unicode != 0 )
		{
			while( ( string_size + 1 ) < data_size )
			{
				if( ( data[ string_size ] == 0 )
				 && ( data[ string_size + 1 ] == 0 ) )
				{
					string_size += 2;

					break;
				}
				string_size += 2;
			}
		}
		else
		{
			while( string_size < data_size )
			{
				if( data[ string_size ] == 0 )
				{
					string_size++;

					break;
				}
				string_size++;
			}
		}
		string_size -= data_offset;

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( file_entry_values->is_unicode != 0 )
			{
				if( libfwsi_debug_print_utf16_string_value(
				     function,
				     "secondary name\t\t\t",
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

					goto on_error;
				}
			}
			else
			{
				if( libfwsi_debug_print_string_value(
				     function,
				     "secondary name\t\t\t",
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

					goto on_error;
				}
			}
		}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

		data_offset += string_size;
	}
	else
	{
		data_offset += string_alignment_size;
	}
	if( has_swn1 == 0 )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			byte_stream_copy_to_uint16_little_endian(
			 &( data[ data_offset ] ),
			 value_16bit );
			libcnotify_printf(
			 "%s: extension block size\t\t\t: %" PRIu16 "\n",
			 function,
			 value_16bit );
		}
#endif
		data_offset += 2;

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			libcnotify_printf(
			 "%s: signature\t\t\t\t: %c%c%c%c%c%c%c\\x%02" PRIx8 "\n",
			 function,
			 data[ data_offset ],
			 data[ data_offset + 1 ],
			 data[ data_offset + 2 ],
			 data[ data_offset + 3 ],
			 data[ data_offset + 4 ],
			 data[ data_offset + 5 ],
			 data[ data_offset + 6 ],
			 data[ data_offset + 7 ] );
		}
#endif
		data_offset += 8;

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			byte_stream_copy_to_uint32_little_endian(
			 &( data[ data_offset ] ),
			 value_32bit );
			libcnotify_printf(
			 "%s: unknown1\t\t\t\t: 0x%08" PRIx32 "\n",
			 function,
			 value_32bit );
		}
#endif
		data_offset += 4;

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			byte_stream_copy_to_uint32_little_endian(
			 &( data[ data_offset ] ),
			 value_32bit );
			libcnotify_printf(
			 "%s: unknown2\t\t\t\t: 0x%08" PRIx32 "\n",
			 function,
			 value_32bit );
		}
#endif
		data_offset += 4;

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			byte_stream_copy_to_uint64_little_endian(
			 &( data[ data_offset ] ),
			 value_64bit );
			libcnotify_printf(
			 "%s: unknown3\t\t\t\t: 0x%08" PRIx64 "\n",
			 function,
			 value_64bit );
		}
#endif
		data_offset += 8;

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			libcnotify_printf(
			 "%s: unknown4:\n",
			 function );
			libcnotify_print_data(
			 &( data[ data_offset ] ),
			 6,
			 0 );
		}
#endif
		data_offset += 6;
	}
	if( ( file_entry_values->in_pre_xp_format != 0 )
	 && ( ( class_type_indicator & 0x80 ) != 0 )
	 && ( data_offset <= ( data_size - 16 ) ) )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( libfwsi_debug_print_guid_value(
			     function,
			     "shell folder identifier\t\t\t",
			     &( data[ data_offset ] ),
			     16,
			     LIBFGUID_ENDIAN_LITTLE,
			     LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_PRINT_FAILED,
				 "%s: unable to print GUID value.",
				 function );

				goto on_error;
			}
			libcnotify_printf(
			 "%s: shell folder name\t\t\t: %s\n",
			 function,
			 libfwsi_shell_folder_identifier_get_name(
			  &( data[ data_offset ] ) ) );
		}
#endif
		data_offset += 16;
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
	if( file_entry_values->name != NULL )
	{
		memory_free(
		 file_entry_values->name );

		file_entry_values->name = NULL;
	}
	file_entry_values->name_size = 0;

	return( -1 );
}

