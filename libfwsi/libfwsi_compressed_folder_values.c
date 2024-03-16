/*
 * Compressed folder (shell item) values functions
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

#include "libfwsi_compressed_folder_values.h"
#include "libfwsi_debug.h"
#include "libfwsi_definitions.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"
#include "libfwsi_libfdatetime.h"
#include "libfwsi_libuna.h"
#include "libfwsi_unused.h"

/* Creates compressed folder values
 * Make sure the value compressed_folder_values is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_compressed_folder_values_initialize(
     libfwsi_compressed_folder_values_t **compressed_folder_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_compressed_folder_values_initialize";

	if( compressed_folder_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid compressed folder values.",
		 function );

		return( -1 );
	}
	if( *compressed_folder_values != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid compressed folder values value already set.",
		 function );

		return( -1 );
	}
	*compressed_folder_values = memory_allocate_structure(
	                             libfwsi_compressed_folder_values_t );

	if( *compressed_folder_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create compressed folder values.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *compressed_folder_values,
	     0,
	     sizeof( libfwsi_compressed_folder_values_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear compressed folder values.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *compressed_folder_values != NULL )
	{
		memory_free(
		 *compressed_folder_values );

		*compressed_folder_values = NULL;
	}
	return( -1 );
}

/* Frees compressed folder values
 * Returns 1 if successful or -1 on error
 */
int libfwsi_compressed_folder_values_free(
     libfwsi_compressed_folder_values_t **compressed_folder_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_compressed_folder_values_free";

	if( compressed_folder_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid compressed folder values.",
		 function );

		return( -1 );
	}
	if( *compressed_folder_values != NULL )
	{
		if( ( *compressed_folder_values )->name != NULL )
		{
			memory_free(
			 ( *compressed_folder_values )->name );
		}
		memory_free(
		 *compressed_folder_values );

		*compressed_folder_values = NULL;
	}
	return( 1 );
}

/* Reads the compressed folder values
 * Returns 1 if successful, 0 if not supported or -1 on error
 */
int libfwsi_compressed_folder_values_read_data(
     libfwsi_compressed_folder_values_t *compressed_folder_values,
     const uint8_t *data,
     size_t data_size,
     libcerror_error_t **error )
{
	static char *function     = "libfwsi_compressed_folder_values_read_data";
	size_t data_offset        = 0;
	uint32_t name_string_size = 0;
	uint32_t string2_size     = 0;
	uint8_t format            = 0;

#if defined( HAVE_DEBUG_OUTPUT )
	uint64_t value_64bit      = 0;
	uint32_t value_32bit      = 0;
	uint16_t value_16bit      = 0;
#endif

	if( compressed_folder_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid compressed folder values.",
		 function );

		return( -1 );
	}
	if( compressed_folder_values->name != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid compressed folder values - name value already set.",
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
	if( data_size < 68 )
	{
		return( 0 );
	}
	if( ( data_size >= 68 )
	 && ( data[ 28 ] == (uint8_t) '/' )
	 && ( data[ 29 ] == (uint8_t) 0 )
	 && ( data[ 34 ] == (uint8_t) '/' )
	 && ( data[ 35 ] == (uint8_t) 0 )
	 && ( data[ 40 ] == (uint8_t) ' ' )
	 && ( data[ 41 ] == (uint8_t) 0 )
	 && ( data[ 42 ] == (uint8_t) ' ' )
	 && ( data[ 43 ] == (uint8_t) 0 )
	 && ( data[ 48 ] == (uint8_t) ':' )
	 && ( data[ 49 ] == (uint8_t) 0 )
	 && ( data[ 54 ] == (uint8_t) 0 )
	 && ( data[ 55 ] == (uint8_t) 0 ) )
	{
		/* Windows XP compressed folder with a date and time sting */
		format = 1;
	}
	else if( ( data_size >= 92 )
	      && ( data[ 36 ] == (uint8_t) 'N' )
	      && ( data[ 37 ] == (uint8_t) 0 )
	      && ( data[ 38 ] == (uint8_t) '/' )
	      && ( data[ 39 ] == (uint8_t) 0 )
	      && ( data[ 40 ] == (uint8_t) 'A' )
	      && ( data[ 41 ] == (uint8_t) 0 )
	      && ( data[ 42 ] == (uint8_t) 0 )
	      && ( data[ 43 ] == (uint8_t) 0 ) )
	{
		/* Windows 10 compressed folder without a date and time sting */
		format = 2;
	}
	else if( ( data_size >= 92 )
	      && ( data[ 40 ] == (uint8_t) '/' )
	      && ( data[ 41 ] == (uint8_t) 0 )
	      && ( data[ 46 ] == (uint8_t) '/' )
	      && ( data[ 47 ] == (uint8_t) 0 )
	      && ( data[ 56 ] == (uint8_t) ' ' )
	      && ( data[ 57 ] == (uint8_t) 0 )
	      && ( data[ 58 ] == (uint8_t) ' ' )
	      && ( data[ 59 ] == (uint8_t) 0 )
	      && ( data[ 64 ] == (uint8_t) ':' )
	      && ( data[ 65 ] == (uint8_t) 0 )
	      && ( data[ 70 ] == (uint8_t) ':' )
	      && ( data[ 71 ] == (uint8_t) 0 )
	      && ( data[ 76 ] == (uint8_t) 0 )
	      && ( data[ 77 ] == (uint8_t) 0 ) )
	{
		/* Windows 10 compressed folder with a date and time sting */
		format = 3;
	}
	if( format == 0 )
	{
		/* Do not try to parse unsupported data
		 */
		return( 0 );
	}
	if( format == 1 )
	{
		byte_stream_copy_to_uint32_little_endian(
		 &( data[ 60 ] ),
		 name_string_size );

		byte_stream_copy_to_uint32_little_endian(
		 &( data[ 64 ] ),
		 string2_size );

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			byte_stream_copy_to_uint16_little_endian(
			 &( data[ 2 ] ),
			 value_16bit );
			libcnotify_printf(
			 "%s: unknown1\t\t\t: 0x%04" PRIx16 "\n",
			 function,
			 value_16bit );

			libcnotify_printf(
			 "%s: unknown2:\n",
			 function );
			libcnotify_print_data(
			 &( data[ 4 ] ),
			 16,
			 0 );

			byte_stream_copy_to_uint16_little_endian(
			 &( data[ 20 ] ),
			 value_16bit );
			libcnotify_printf(
			 "%s: unknown3\t\t\t: 0x%04" PRIx16 "\n",
			 function,
			 value_16bit );

			byte_stream_copy_to_uint16_little_endian(
			 &( data[ 22 ] ),
			 value_16bit );
			libcnotify_printf(
			 "%s: unknown3\t\t\t: 0x%04" PRIx16 "\n",
			 function,
			 value_16bit );

			libcnotify_printf(
			 "%s: unknown4:\n",
			 function );
			libcnotify_print_data(
			 &( data[ 24 ] ),
			 32,
			 0 );

			byte_stream_copy_to_uint16_little_endian(
			 &( data[ 56 ] ),
			 value_16bit );
			libcnotify_printf(
			 "%s: unknown5\t\t\t: 0x%04" PRIx16 "\n",
			 function,
			 value_16bit );

			byte_stream_copy_to_uint16_little_endian(
			 &( data[ 58 ] ),
			 value_16bit );
			libcnotify_printf(
			 "%s: unknown6\t\t\t: 0x%04" PRIx16 "\n",
			 function,
			 value_16bit );

			libcnotify_printf(
			 "%s: name string size\t\t: %" PRIzd " (%" PRIzd " characters)\n",
			 function,
			 ( name_string_size + 1 ) * 2,
			 name_string_size );

			libcnotify_printf(
			 "%s: string2 size\t\t: %" PRIu32 " (%" PRIu32 " characters)\n",
			 function,
			 ( string2_size + 1 ) * 2,
			 string2_size );
		}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

		data_offset = 68;
	}
	else
	{
		byte_stream_copy_to_uint32_little_endian(
		 &( data[ 84 ] ),
		 name_string_size );

		byte_stream_copy_to_uint32_little_endian(
		 &( data[ 88 ] ),
		 string2_size );

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			libcnotify_printf(
			 "%s: unknown1:\n",
			 function );
			libcnotify_print_data(
			 &( data[ 2 ] ),
			 6,
			 0 );

			byte_stream_copy_to_uint64_little_endian(
			 &( data[ 8 ] ),
			 value_64bit );
			libcnotify_printf(
			 "%s: uncompressed size\t\t: %" PRIu64 "\n",
			 function,
			 value_64bit );

			byte_stream_copy_to_uint64_little_endian(
			 &( data[ 16 ] ),
			 value_64bit );
			libcnotify_printf(
			 "%s: compressed size\t\t: %" PRIu64 "\n",
			 function,
			 value_64bit );

			byte_stream_copy_to_uint16_little_endian(
			 &( data[ 24 ] ),
			 value_16bit );
			libcnotify_printf(
			 "%s: compression method\t\t: %" PRIu16 "\n",
			 function,
			 value_16bit );

			byte_stream_copy_to_uint16_little_endian(
			 &( data[ 26 ] ),
			 value_16bit );
			libcnotify_printf(
			 "%s: unknown2\t\t\t: 0x%04" PRIx16 "\n",
			 function,
			 value_16bit );

			byte_stream_copy_to_uint32_little_endian(
			 &( data[ 28 ] ),
			 value_32bit );
			libcnotify_printf(
			 "%s: checksum\t\t\t: 0x%08" PRIx32 "\n",
			 function,
			 value_32bit );

			byte_stream_copy_to_uint16_little_endian(
			 &( data[ 32 ] ),
			 value_16bit );
			libcnotify_printf(
			 "%s: unknown3\t\t\t: 0x%04" PRIx16 "\n",
			 function,
			 value_16bit );

			byte_stream_copy_to_uint16_little_endian(
			 &( data[ 34 ] ),
			 value_16bit );
			libcnotify_printf(
			 "%s: unknown4\t\t\t: 0x%04" PRIx16 "\n",
			 function,
			 value_16bit );

			libcnotify_printf(
			 "%s: unknown5:\n",
			 function );
			libcnotify_print_data(
			 &( data[ 36 ] ),
			 42,
			 0 );

			byte_stream_copy_to_uint16_little_endian(
			 &( data[ 78 ] ),
			 value_16bit );
			libcnotify_printf(
			 "%s: unknown6\t\t\t: 0x%04" PRIx16 "\n",
			 function,
			 value_16bit );

			byte_stream_copy_to_uint16_little_endian(
			 &( data[ 80 ] ),
			 value_16bit );
			libcnotify_printf(
			 "%s: unknown7\t\t\t: 0x%04" PRIx16 "\n",
			 function,
			 value_16bit );

			byte_stream_copy_to_uint16_little_endian(
			 &( data[ 82 ] ),
			 value_16bit );
			libcnotify_printf(
			 "%s: unknown8\t\t\t: 0x%04" PRIx16 "\n",
			 function,
			 value_16bit );

			libcnotify_printf(
			 "%s: name string size\t\t: %" PRIzd " (%" PRIzd " characters)\n",
			 function,
			 ( name_string_size + 1 ) * 2,
			 name_string_size );

			libcnotify_printf(
			 "%s: string2 size\t\t: %" PRIu32 " (%" PRIu32 " characters)\n",
			 function,
			 ( string2_size + 1 ) * 2,
			 string2_size );
		}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

		data_offset = 92;
	}
	if( name_string_size > ( ( data_size - data_offset - 1 ) / 2 ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid name string size value out of bounds.",
		 function );

		goto on_error;
	}
	name_string_size += 1;
	name_string_size *= 2;

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: name string data:\n",
		 function );
		libcnotify_print_data(
		 &( data[ data_offset ] ),
		 name_string_size,
		 0 );
	}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

	if( name_string_size > (size_t) MEMORY_MAXIMUM_ALLOCATION_SIZE )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: invalid name string size value exceeds maximum.",
		 function );

		goto on_error;
	}
	compressed_folder_values->name = (uint8_t *) memory_allocate(
	                                              sizeof( uint8_t ) * name_string_size );

	if( compressed_folder_values->name == NULL )
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
	     compressed_folder_values->name,
	     &( data[ data_offset ] ),
	     name_string_size ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_COPY_FAILED,
		 "%s: unable to copy name.",
		 function );

		goto on_error;
	}
	compressed_folder_values->name_size = name_string_size;

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		if( libfwsi_debug_print_utf16_string_value(
		     function,
		     "name\t\t\t",
		     compressed_folder_values->name,
		     compressed_folder_values->name_size,
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
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

	data_offset += name_string_size;

	if( string2_size > ( ( data_size - data_offset - 1 ) / 2 ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid string2 size value out of bounds.",
		 function );

		goto on_error;
	}
	string2_size += 1;
	string2_size *= 2;

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: string2 data:\n",
		 function );
		libcnotify_print_data(
		 &( data[ data_offset ] ),
		 string2_size,
		 0 );
	}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		if( libfwsi_debug_print_utf16_string_value(
		     function,
		     "string2\t\t\t",
		     &( data[ data_offset ] ),
		     string2_size,
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
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

	data_offset += string2_size;

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
	if( compressed_folder_values->name != NULL )
	{
		memory_free(
		 compressed_folder_values->name );

		compressed_folder_values->name = NULL;
	}
	compressed_folder_values->name_size = 0;

	return( -1 );
}

