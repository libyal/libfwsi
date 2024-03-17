/*
 * Users property view (shell item) values functions
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
#include "libfwsi_known_folder_identifier.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"
#include "libfwsi_libfguid.h"
#include "libfwsi_shell_folder_identifier.h"
#include "libfwsi_users_property_view_values.h"

/* Creates users property view values
 * Make sure the value users_property_view_values is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_users_property_view_values_initialize(
     libfwsi_users_property_view_values_t **users_property_view_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_users_property_view_values_initialize";

	if( users_property_view_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid users property view values.",
		 function );

		return( -1 );
	}
	if( *users_property_view_values != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid users property view values value already set.",
		 function );

		return( -1 );
	}
	*users_property_view_values = memory_allocate_structure(
	                               libfwsi_users_property_view_values_t );

	if( *users_property_view_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create users property view values.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *users_property_view_values,
	     0,
	     sizeof( libfwsi_users_property_view_values_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear users property view values.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *users_property_view_values != NULL )
	{
		memory_free(
		 *users_property_view_values );

		*users_property_view_values = NULL;
	}
	return( -1 );
}

/* Frees users property view values
 * Returns 1 if successful or -1 on error
 */
int libfwsi_users_property_view_values_free(
     libfwsi_users_property_view_values_t **users_property_view_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_users_property_view_values_free";

	if( users_property_view_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid users property view values.",
		 function );

		return( -1 );
	}
	if( *users_property_view_values != NULL )
	{
		if( ( *users_property_view_values )->property_store_data != NULL )
		{
			memory_free(
			 ( *users_property_view_values )->property_store_data );
		}
		memory_free(
		 *users_property_view_values );

		*users_property_view_values = NULL;
	}
	return( 1 );
}

/* Reads the users property view values
 * Returns 1 if successful, 0 if not supported or -1 on error
 */
int libfwsi_users_property_view_values_read_data(
     libfwsi_users_property_view_values_t *users_property_view_values,
     const uint8_t *data,
     size_t data_size,
     int ascii_codepage,
     libcerror_error_t **error )
{
	static char *function        = "libfwsi_users_property_view_values_read_data";
	size_t data_offset           = 0;
	uint32_t signature           = 0;
	uint16_t identifier_size     = 0;
	uint16_t item_data_size      = 0;
	uint16_t property_store_size = 0;

#if defined( HAVE_DEBUG_OUTPUT )
	uint32_t value_32bit         = 0;
	uint16_t value_16bit         = 0;
#endif

	if( users_property_view_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid users property view values.",
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
	/* Do not try to parse unsupported shell item signatures
	 */
	byte_stream_copy_to_uint32_little_endian(
	 &( data[ 6 ] ),
	 signature );

	switch( signature )
	{
		case 0x10141981UL:
		case 0x23a3dfd5UL:
		case 0x23febbeeUL:
		case 0x3b93afbbUL:
		case 0x49505241UL:
		case 0xbeebee00UL:
			break;

		default:
			return( 0 );
	}
	users_property_view_values->has_known_folder_identifier = 0;

	byte_stream_copy_to_uint32_little_endian(
	 &( data[ 4 ] ),
	 item_data_size );

	byte_stream_copy_to_uint16_little_endian(
	 &( data[ 10 ] ),
	 property_store_size );

	byte_stream_copy_to_uint16_little_endian(
	 &( data[ 12 ] ),
	 identifier_size );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: class type indicator\t: 0x%02" PRIx8 "\n",
		 function,
		 data[ 2 ] );

		libcnotify_printf(
		 "%s: unknown1\t\t\t: 0x%02" PRIx8 "\n",
		 function,
		 data[ 3 ] );

		libcnotify_printf(
		 "%s: data size\t\t\t: %" PRIu16 "\n",
		 function,
		 item_data_size );

		libcnotify_printf(
		 "%s: data signature\t\t: 0x%08" PRIx32 "\n",
		 function,
		 signature );

		libcnotify_printf(
		 "%s: property store size\t: %" PRIu16 "\n",
		 function,
		 property_store_size );

		libcnotify_printf(
		 "%s: identifier size\t\t: %" PRIu16 "\n",
		 function,
		 identifier_size );
	}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

	data_offset = 14;

	if( item_data_size != 0 )
	{
		if( item_data_size <= 2 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
			 "%s: invalid data size value out of bounds.",
			 function );

			goto on_error;
		}
	}
	if( ( identifier_size > data_size )
	 || ( data_offset > ( data_size - identifier_size ) ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid identifier size value out of bounds.",
		 function );

		goto on_error;
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: identifier data:\n",
		 function );
		libcnotify_print_data(
		 &( data[ data_offset ] ),
		 identifier_size,
		 LIBCNOTIFY_PRINT_DATA_FLAG_GROUP_DATA );
	}
#endif
	switch( signature )
	{
		case 0x23a3dfd5UL:
		case 0x3b93afbbUL:
		case 0xbeebee00UL:
			if( identifier_size == 4 )
			{
#if defined( HAVE_DEBUG_OUTPUT )
				if( libcnotify_verbose != 0 )
				{
					byte_stream_copy_to_uint32_little_endian(
					 &( data[ data_offset ] ),
					 value_32bit );
					libcnotify_printf(
					 "%s: identifier\t\t: 0x%08" PRIx32 "\n",
					 function,
					 value_32bit );
				}
#endif
				data_offset += 4;
			}
			break;

		case 0x23febbeeUL:
			if( identifier_size == 16 )
			{
				if( memory_copy(
				     users_property_view_values->known_folder_identifier,
				     &( data[ data_offset ] ),
				     16 ) == NULL )
				{
					libcerror_error_set(
					 error,
					 LIBCERROR_ERROR_DOMAIN_MEMORY,
					 LIBCERROR_MEMORY_ERROR_COPY_FAILED,
					 "%s: unable to copy known folder identifier.",
					 function );

					goto on_error;
				}
				users_property_view_values->has_known_folder_identifier = 1;

#if defined( HAVE_DEBUG_OUTPUT )
				if( libcnotify_verbose != 0 )
				{
					if( libfwsi_debug_print_guid_value(
					     function,
					     "known folder identifier\t",
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
					 "%s: known folder name\t\t: %s\n",
					 function,
					 libfwsi_known_folder_identifier_get_name(
					  &( data[ data_offset ] ) ) );
				}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

				data_offset += 16;
			}
			break;

		default:
			data_offset += identifier_size;
			break;
	}
	if( ( property_store_size > data_size )
	 || ( data_offset > ( data_size - property_store_size ) ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid property store size value out of bounds.",
		 function );

		goto on_error;
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: property store data:\n",
		 function );
		libcnotify_print_data(
		 &( data[ data_offset ] ),
		 property_store_size,
		 LIBCNOTIFY_PRINT_DATA_FLAG_GROUP_DATA );
	}
#endif
	if( property_store_size > 0 )
	{
		users_property_view_values->property_store_data = (uint8_t *) memory_allocate(
		                                                               sizeof( uint8_t ) * property_store_size );

		if( users_property_view_values->property_store_data == NULL )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_MEMORY,
			 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
			 "%s: unable to create property store data.",
			 function );

			goto on_error;
		}
		if( memory_copy(
		     users_property_view_values->property_store_data,
		     &( data[ data_offset ] ),
		     property_store_size ) == NULL )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_MEMORY,
			 LIBCERROR_MEMORY_ERROR_COPY_FAILED,
			 "%s: unable to copy property store data.",
			 function );

			goto on_error;
		}
		users_property_view_values->property_store_data_size = property_store_size;

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( libfwsi_debug_print_property_store_value(
			     users_property_view_values->property_store_data,
			     users_property_view_values->property_store_data_size,
			     ascii_codepage,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_PRINT_FAILED,
				 "%s: unable to print property store value.",
				 function );

				goto on_error;
			}
		}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

		data_offset += property_store_size;
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		byte_stream_copy_to_uint16_little_endian(
		 &( data[ data_offset ] ),
		 value_16bit );

		libcnotify_printf(
		 "%s: unknown1 size\t\t: %" PRIu16 "\n",
		 function,
		 value_16bit );

		libcnotify_printf(
		 "\n" );
	}
#endif
	return( 1 );

on_error:
	if( users_property_view_values->property_store_data != NULL )
	{
		memory_free(
		 users_property_view_values->property_store_data );

		users_property_view_values->property_store_data = NULL;
	}
	users_property_view_values->property_store_data_size = 0;

	return( -1 );
}

/* Retrieves the known folder identifier
 * The identifier is a GUID and is 16 bytes of size
 * Returns 1 if successful, 0 if not available or -1 on error
 */
int libfwsi_users_property_view_values_get_known_folder_identifier(
     libfwsi_users_property_view_values_t *users_property_view_values,
     uint8_t *guid_data,
     size_t guid_data_size,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_users_property_view_values_get_known_folder_identifier";

	if( users_property_view_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid users property view values.",
		 function );

		return( -1 );
	}
	if( guid_data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid GUID data.",
		 function );

		return( -1 );
	}
	if( guid_data_size < 16 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_TOO_SMALL,
		 "%s: GUID data size too small.",
		 function );

		return( -1 );
	}
	if( users_property_view_values->has_known_folder_identifier == 0 )
	{
		return( 0 );
	}
	if( memory_copy(
	     guid_data,
	     users_property_view_values->known_folder_identifier,
	     16 ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_COPY_FAILED,
		 "%s: unable to copy known folder identifier.",
		 function );

		return( -1 );
	}
	return( 1 );
}

