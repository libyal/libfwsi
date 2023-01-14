/*
 * Unknown 0x74 (shell item) values functions
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
#include "libfwsi_file_attributes.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"
#include "libfwsi_libfdatetime.h"
#include "libfwsi_libfguid.h"
#include "libfwsi_shell_folder_identifier.h"
#include "libfwsi_unknown_0x74_values.h"

/* Creates unknown 0x74 values
 * Make sure the value unknown_0x74_values is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_unknown_0x74_values_initialize(
     libfwsi_unknown_0x74_values_t **unknown_0x74_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_unknown_0x74_values_initialize";

	if( unknown_0x74_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid unknown 0x74 values.",
		 function );

		return( -1 );
	}
	if( *unknown_0x74_values != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid unknown 0x74 values value already set.",
		 function );

		return( -1 );
	}
	*unknown_0x74_values = memory_allocate_structure(
	                        libfwsi_unknown_0x74_values_t );

	if( *unknown_0x74_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create unknown 0x74 values.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *unknown_0x74_values,
	     0,
	     sizeof( libfwsi_unknown_0x74_values_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear unknown 0x74 values.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *unknown_0x74_values != NULL )
	{
		memory_free(
		 *unknown_0x74_values );

		*unknown_0x74_values = NULL;
	}
	return( -1 );
}

/* Frees unknown 0x74 values
 * Returns 1 if successful or -1 on error
 */
int libfwsi_unknown_0x74_values_free(
     libfwsi_unknown_0x74_values_t **unknown_0x74_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_unknown_0x74_values_free";

	if( unknown_0x74_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid unknown 0x74 values.",
		 function );

		return( -1 );
	}
	if( *unknown_0x74_values != NULL )
	{
		memory_free(
		 *unknown_0x74_values );

		*unknown_0x74_values = NULL;
	}
	return( 1 );
}

/* Reads the unknown 0x74 values
 * Returns 1 if successful, 0 if not supported or -1 on error
 */
int libfwsi_unknown_0x74_values_read_data(
     libfwsi_unknown_0x74_values_t *unknown_0x74_values,
     const uint8_t *data,
     size_t data_size,
     int ascii_codepage,
     libcerror_error_t **error )
{
	static char *function        = "libfwsi_unknown_0x74_values_read_data";
	size_t data_offset           = 0;
	size_t string_alignment_size = 0;
	size_t string_size           = 0;
	uint16_t item_data_size      = 0;

#if defined( HAVE_DEBUG_OUTPUT )
	uint32_t value_32bit         = 0;
	uint16_t value_16bit         = 0;
#endif

	if( unknown_0x74_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid unknown 0x74 values.",
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
	if( data_size < 12 )
	{
		return( 0 );
	}
	/* Do not try to parse unsupported shell item signatures
	 */
	if( memory_compare(
	     &( data[ 6 ] ),
	     "CFSF",
	     4 ) != 0 )
	{
		return( 0 );
	}
	byte_stream_copy_to_uint32_little_endian(
	 &( data[ 10 ] ),
	 item_data_size );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: class type indicator\t\t\t: 0x%02" PRIx8 "\n",
		 function,
		 data[ 2 ] );

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

		libcnotify_printf(
		 "%s: signature\t\t\t\t: %c%c%c%c\n",
		 function,
		 data[ 6 ],
		 data[ 7 ],
		 data[ 8 ],
		 data[ 9 ] );

		libcnotify_printf(
		 "%s: data size\t\t\t\t: %" PRIu16 "\n",
		 function,
		 item_data_size );
	}
#endif
	data_offset = 12;

	if( item_data_size > 0 )
	{
		if( ( item_data_size < 2 )
		 && ( item_data_size > ( data_size - 12 ) ) )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
			 "%s: invalid data size value out of bounds.",
			 function );

			return( -1 );
		}
		item_data_size -= 2;

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			libcnotify_printf(
			 "%s: data:\n",
			 function );
			libcnotify_print_data(
			 &( data[ 12 ] ),
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
/* TODO move to sub item parsing ? */
	if( item_data_size >= 16 )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			byte_stream_copy_to_uint16_little_endian(
			 &( data[ 12 ] ),
			 value_16bit );
			libcnotify_printf(
			 "%s: unknown3\t\t\t\t: 0x%04" PRIx16 "\n",
			 function,
			 value_16bit );

			byte_stream_copy_to_uint32_little_endian(
			 &( data[ 14 ] ),
			 value_32bit );
			libcnotify_printf(
			 "%s: file size\t\t\t\t: %" PRIu32 "\n",
			 function,
			 value_32bit );

			if( libfwsi_debug_print_fat_date_time_value(
			     function,
			     "modification time\t\t\t",
			     &( data[ 18 ] ),
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
			byte_stream_copy_to_uint16_little_endian(
			 &( data[ 22 ] ),
			 value_16bit );
			libcnotify_printf(
			 "%s: file attribute flags\t\t\t: 0x%04" PRIx16 "\n",
			 function,
			 value_16bit );
			libfwsi_file_attributes_print(
			 value_16bit );
			libcnotify_printf(
			 "\n" );
		}
#endif
		data_offset += 12;

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

		string_alignment_size = string_size % 2;

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( libfwsi_debug_print_string_value(
			     function,
			     "primary name\t\t\t\t",
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
#endif
		data_offset += string_size + string_alignment_size;

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			byte_stream_copy_to_uint16_little_endian(
			 &( data[ data_offset ] ),
			 value_16bit );

			libcnotify_printf(
			 "%s: unknown5\t\t\t\t: 0x%04" PRIx16 "\n",
			 function,
			 value_16bit );
		}
#endif
		data_offset += 2;
	}
	if( data_offset > ( data_size - 32 ) )
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
		if( libfwsi_debug_print_guid_value(
		     function,
		     "delagate item class identifier\t",
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

			return( -1 );
		}
	}
#endif
	data_offset += 16;

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		if( libfwsi_debug_print_guid_value(
		     function,
		     "item class identifier\t\t\t",
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

			return( -1 );
		}
		libcnotify_printf(
		 "%s: shell folder name\t\t\t: %s\n",
		 function,
		 libfwsi_shell_folder_identifier_get_name(
		  &( data[ data_offset ] ) ) );

		libcnotify_printf(
		 "\n" );
	}
#endif
	data_offset += 16;

	return( 1 );
}

