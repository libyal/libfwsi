/*
 * Extension block 0xbeef0014 values functions
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
#include "libfwsi_extension_block_0xbeef0014_values.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"
#include "libfwsi_libfguid.h"

const uint8_t curi_class_identifier[ 16 ] = {
	0x13, 0xce, 0x2f, 0xdf, 0xec, 0x25, 0xbb, 0x45, 0x9d, 0x4c, 0xce, 0xcd, 0x47, 0xc2, 0x43, 0x0c };

/* Creates extension block 0xbeef0014 values
 * Make sure the value extension_block_0xbeef0014_values is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_extension_block_0xbeef0014_values_initialize(
     libfwsi_extension_block_0xbeef0014_values_t **extension_block_0xbeef0014_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_extension_block_0xbeef0014_values_initialize";

	if( extension_block_0xbeef0014_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block 0xbeef0014 values.",
		 function );

		return( -1 );
	}
	if( *extension_block_0xbeef0014_values != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid extension block 0xbeef0014 values value already set.",
		 function );

		return( -1 );
	}
	*extension_block_0xbeef0014_values = memory_allocate_structure(
	                                      libfwsi_extension_block_0xbeef0014_values_t );

	if( *extension_block_0xbeef0014_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create extension block 0xbeef0014 values.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *extension_block_0xbeef0014_values,
	     0,
	     sizeof( libfwsi_extension_block_0xbeef0014_values_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear extension block 0xbeef0014 values.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *extension_block_0xbeef0014_values != NULL )
	{
		memory_free(
		 *extension_block_0xbeef0014_values );

		*extension_block_0xbeef0014_values = NULL;
	}
	return( -1 );
}

/* Frees extension block 0xbeef0014 values
 * Returns 1 if successful or -1 on error
 */
int libfwsi_extension_block_0xbeef0014_values_free(
     libfwsi_extension_block_0xbeef0014_values_t **extension_block_0xbeef0014_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_extension_block_0xbeef0014_values_free";

	if( extension_block_0xbeef0014_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block 0xbeef0014 values.",
		 function );

		return( -1 );
	}
	if( *extension_block_0xbeef0014_values != NULL )
	{
		memory_free(
		 *extension_block_0xbeef0014_values );

		*extension_block_0xbeef0014_values = NULL;
	}
	return( 1 );
}

/* Reads the extension block 0xbeef0014 values
 * Returns 1 if successful, 0 if not supported or -1 on error
 */
int libfwsi_extension_block_0xbeef0014_values_read_data(
     libfwsi_extension_block_0xbeef0014_values_t *extension_block_0xbeef0014_values,
     const uint8_t *data,
     size_t data_size,
     libcerror_error_t **error )
{
	static char *function         = "libfwsi_extension_block_0xbeef0014_values_read_data";
	size_t data_offset            = 0;
	uint32_t number_of_properties = 0;
	uint32_t property_index       = 0;
	uint32_t property_size        = 0;
	uint32_t property_type        = 0;
	uint32_t signature            = 0;
	int result                    = 0;

#if defined( HAVE_DEBUG_OUTPUT )
	uint32_t value_32bit          = 0;
#endif

	if( extension_block_0xbeef0014_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block 0xbeef0014 values.",
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
	if( data_size < 26 )
	{
		return( 0 );
	}
	/* Do not try to parse unsupported extension block signatures
	 */
	byte_stream_copy_to_uint32_little_endian(
	 &( data[ 4 ] ),
	 signature );

	if( signature != 0xbeef0014 )
	{
		return( 0 );
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		if( libfwsi_debug_print_guid_value(
		     function,
		     "class identifier\t\t",
		     &( data[ 8 ] ),
		     16,
		     LIBFGUID_ENDIAN_LITTLE,
		     LIBFGUID_STRING_FORMAT_FLAG_USE_LOWER_CASE,
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
	result = memory_compare(
	          &( data[ 8 ] ),
	          curi_class_identifier,
	          16 );

	data_offset = 24;

	if( result == 0 )
	{
		if( data_size < 58 )
		{
			return( 0 );
		}
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			byte_stream_copy_to_uint32_little_endian(
			 &( data[ data_offset ] ),
			 value_32bit );

			libcnotify_printf(
			 "%s: data size\t\t\t: %" PRIu32 "\n",
			 function,
			 value_32bit );
		}
#endif
		data_offset += 4;

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			libcnotify_printf(
			 "%s: unknown1:\n",
			 function );
			libcnotify_print_data(
			 &( data[ data_offset ] ),
			 8,
			 0 );
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
			 "%s: unknown2\t\t\t: 0x%08" PRIx32 "\n",
			 function,
			 value_32bit );
		}
#endif
		data_offset += 4;

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			libcnotify_printf(
			 "%s: unknown3:\n",
			 function );
			libcnotify_print_data(
			 &( data[ data_offset ] ),
			 12,
			 0 );
		}
#endif
		data_offset += 12;

		/* Property table
		 */
		byte_stream_copy_to_uint32_little_endian(
		 &( data[ data_offset ] ),
		 number_of_properties );

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			libcnotify_printf(
			 "%s: number of properties\t: %" PRIu32 "\n",
			 function,
			 number_of_properties );
		}
#endif
		data_offset += 4;

		for( property_index = 0;
		     property_index < number_of_properties;
		     property_index++ )
		{
			if( data_offset > ( data_size - 8 ) )
			{
				return( 0 );
			}
			byte_stream_copy_to_uint32_little_endian(
			 &( data[ data_offset ] ),
			 property_type );

#if defined( HAVE_DEBUG_OUTPUT )
			if( libcnotify_verbose != 0 )
			{
				libcnotify_printf(
				 "%s: property: %" PRIu32 " type\t\t: %" PRIu32 "\n",
				 function,
				 property_index,
				 property_type );
			}
#endif
			data_offset += 4;

			byte_stream_copy_to_uint32_little_endian(
			 &( data[ data_offset ] ),
			 property_size );

#if defined( HAVE_DEBUG_OUTPUT )
			if( libcnotify_verbose != 0 )
			{
				libcnotify_printf(
				 "%s: property: %" PRIu32 " size\t\t: %" PRIu32 "\n",
				 function,
				 property_index,
				 property_size );
			}
#endif
			data_offset += 4;

			if( ( property_size > data_size )
			 || ( data_offset > ( data_size - property_size ) ) )
			{
				return( 0 );
			}
#if defined( HAVE_DEBUG_OUTPUT )
			if( libcnotify_verbose != 0 )
			{
				libcnotify_printf(
				 "%s: property: %" PRIu32 " data:\n",
				 function,
				 property_index );
				libcnotify_print_data(
				 &( data[ data_offset ] ),
				 property_size,
				 LIBCNOTIFY_PRINT_DATA_FLAG_GROUP_DATA );
			}
#endif
			data_offset += property_size;
		}
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

