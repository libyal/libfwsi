/*
 * Users property view (shell item) values functions
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

#include "libfwsi_known_folder_identifier.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"
#include "libfwsi_libfguid.h"
#include "libfwsi_libfwps.h"
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
		memory_free(
		 *users_property_view_values );

		*users_property_view_values = NULL;
	}
	return( 1 );
}

/* Reads the users property view values
 * Returns the number of bytes read if successful, 0 if not able to read or -1 on error
 */
ssize_t libfwsi_users_property_view_values_read(
         libfwsi_users_property_view_values_t *users_property_view_values,
         const uint8_t *shell_item_data,
         size_t shell_item_data_size,
         int ascii_codepage,
         libcerror_error_t **error )
{
	static char *function               = "libfwsi_users_property_view_values_read";
	size_t shell_item_data_offset       = 0;
	uint32_t signature                  = 0;
	uint16_t data_size                  = 0;
	uint16_t identifier_size            = 0;
	uint16_t property_store_size        = 0;

#if defined( HAVE_DEBUG_OUTPUT )
        libcstring_system_character_t guid_string[ 48 ];

        libfguid_identifier_t *guid         = NULL;
        libfwps_storage_t *property_storage = NULL;
	uint32_t value_32bit                = 0;
	uint16_t value_16bit                = 0;
	int result                          = 0;
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
	if( shell_item_data_size < 14 )
	{
		return( 0 );
	}
	/* Do not try to parse unsupported shell item signatures
	 */
	byte_stream_copy_to_uint32_little_endian(
	 &( shell_item_data[ 6 ] ),
	 signature );

	switch( signature )
	{
		case 0x10141981UL:
		case 0x23a3dfd5UL:
		case 0x23febbeeUL:
		case 0x3b93afbbUL:
		case 0xbeebee00UL:
			break;

		default:
			return( 0 );
	}
	byte_stream_copy_to_uint32_little_endian(
	 &( shell_item_data[ 4 ] ),
	 data_size );

	byte_stream_copy_to_uint16_little_endian(
	 &( shell_item_data[ 10 ] ),
	 property_store_size );

	byte_stream_copy_to_uint16_little_endian(
	 &( shell_item_data[ 12 ] ),
	 identifier_size );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: class type indicator\t\t: 0x%02" PRIx8 "\n",
		 function,
		 shell_item_data[ 2 ] );

		libcnotify_printf(
		 "%s: unknown1\t\t\t: 0x%02" PRIx8 "\n",
		 function,
		 shell_item_data[ 3 ] );

		libcnotify_printf(
		 "%s: data size\t\t\t: %" PRIu16 "\n",
		 function,
		 data_size );

		libcnotify_printf(
		 "%s: data signature\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 signature );

		libcnotify_printf(
		 "%s: property store size\t\t: %" PRIu16 "\n",
		 function,
		 property_store_size );

		libcnotify_printf(
		 "%s: identifier size\t\t: %" PRIu16 "\n",
		 function,
		 identifier_size );
	}
#endif
	shell_item_data_offset = 14;

	if( data_size != 0 )
	{
		if( data_size <= 2 )
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

/* TODO add identifier_size bounds check */
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: identifier data:\n",
		 function );
		libcnotify_print_data(
		 &( shell_item_data[ shell_item_data_offset ] ),
		 identifier_size,
		 0 );
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
					 &( shell_item_data[ shell_item_data_offset ] ),
					 value_32bit );
					libcnotify_printf(
					 "%s: identifier\t\t\t: 0x%08" PRIx32 "\n",
					 function,
					 value_32bit );
				}
#endif
				shell_item_data_offset += 4;
			}
			break;

		case 0x23febbeeUL:
			if( identifier_size == 16 )
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
					 "%s: known folder identifier\t: %" PRIs_LIBCSTRING_SYSTEM "\n",
					 function,
					 guid_string );
					libcnotify_printf(
					 "%s: known folder name\t\t: %s\n",
					 function,
					 libfwsi_known_folder_identifier_get_name(
					  &( shell_item_data[ shell_item_data_offset ] ) ) );
				}
#endif
				shell_item_data_offset += 16;
			}
			break;

		default:
			shell_item_data_offset += identifier_size;
			break;
	}
/* TODO add property store size bounds check */

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: property store data:\n",
		 function );
		libcnotify_print_data(
		 &( shell_item_data[ shell_item_data_offset ] ),
		 property_store_size,
		 LIBCNOTIFY_PRINT_DATA_FLAG_GROUP_DATA );
	}
#endif
	if( property_store_size > 0 )
	{
/* TODO look for multiple stores */
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( libfwps_storage_initialize(
			     &property_storage,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create property storage.",
				 function );

				goto on_error;
			}
			if( libfwps_storage_copy_from_byte_stream(
			     property_storage,
			     &( shell_item_data[ shell_item_data_offset ] ),
			     property_store_size,
			     ascii_codepage,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
				 "%s: unable to copy byte stream to property storage.",
				 function );

				goto on_error;
			}
			if( libfwps_storage_free(
			     &property_storage,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
				 "%s: unable to free property storage.",
				 function );

				goto on_error;
			}
		}
#endif
		shell_item_data_offset += property_store_size;
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		byte_stream_copy_to_uint16_little_endian(
		 &( shell_item_data[ shell_item_data_offset ] ),
		 value_16bit );

		libcnotify_printf(
		 "%s: unknown1 size\t\t\t: %" PRIu16 "\n",
		 function,
		 value_16bit );
	}
#endif
	shell_item_data_offset += 2;

	if( signature == 0x23a3dfd5UL )
	{
		if( shell_item_data_offset > shell_item_data_size - 32 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
			 "%s: invalid shell item data size value out of bounds.",
			 function );

			goto on_error;
		}
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
			 "%s: delegate item identifier\t: %" PRIs_LIBCSTRING_SYSTEM "\n",
			 function,
			 guid_string );
		}
#endif
		shell_item_data_offset += 16;

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
			 "%s: item class identifier\t\t: %" PRIs_LIBCSTRING_SYSTEM "\n",
			 function,
			 guid_string );
			libcnotify_printf(
			 "%s: shell folder name\t\t: %s\n",
			 function,
			 libfwsi_shell_folder_identifier_get_name(
			  &( shell_item_data[ shell_item_data_offset ] ) ) );
		}
#endif
		shell_item_data_offset += 16;
	}
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
	if( property_storage != NULL )
	{
		libfwps_storage_free(
		 &property_storage,
		 NULL );
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

