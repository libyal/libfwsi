/*
 * MTP storage device volume (shell item) values functions
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
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"
#include "libfwsi_libfguid.h"
#include "libfwsi_libfole.h"
#include "libfwsi_libuna.h"
#include "libfwsi_mtp_volume_values.h"

/* Creates MTP volume values
 * Make sure the value mtp_volume_values is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_mtp_volume_values_initialize(
     libfwsi_mtp_volume_values_t **mtp_volume_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_mtp_volume_values_initialize";

	if( mtp_volume_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid MTP volume values.",
		 function );

		return( -1 );
	}
	if( *mtp_volume_values != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid MTP volume values value already set.",
		 function );

		return( -1 );
	}
	*mtp_volume_values = memory_allocate_structure(
	                      libfwsi_mtp_volume_values_t );

	if( *mtp_volume_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create MTP volume values.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *mtp_volume_values,
	     0,
	     sizeof( libfwsi_mtp_volume_values_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear MTP volume values.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *mtp_volume_values != NULL )
	{
		memory_free(
		 *mtp_volume_values );

		*mtp_volume_values = NULL;
	}
	return( -1 );
}

/* Frees MTP volume values
 * Returns 1 if successful or -1 on error
 */
int libfwsi_mtp_volume_values_free(
     libfwsi_mtp_volume_values_t **mtp_volume_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_mtp_volume_values_free";

	if( mtp_volume_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid MTP volume values.",
		 function );

		return( -1 );
	}
	if( *mtp_volume_values != NULL )
	{
		memory_free(
		 *mtp_volume_values );

		*mtp_volume_values = NULL;
	}
	return( 1 );
}

/* Reads the MTP volume values
 * Returns 1 if successful, 0 if not supported or -1 on error
 */
int libfwsi_mtp_volume_values_read_data(
     libfwsi_mtp_volume_values_t *mtp_volume_values,
     const uint8_t *data,
     size_t data_size,
     libcerror_error_t **error )
{
	static char *function            = "libfwsi_mtp_volume_values_read_data";
	size_t data_offset               = 0;
	uint32_t file_system_string_size = 0;
	uint32_t guid_string_index       = 0;
	uint32_t identifier_string_size  = 0;
	uint32_t name_string_size        = 0;
	uint32_t number_of_guid_strings  = 0;
	uint32_t number_of_properties    = 0;
	uint32_t property_index          = 0;
	uint32_t property_value_type     = 0;
        uint32_t signature               = 0;
	uint32_t string_size             = 0;
	uint16_t item_data_size          = 0;

#if defined( HAVE_DEBUG_OUTPUT )
	uint32_t value_32bit             = 0;
	uint16_t value_16bit             = 0;
#endif

	if( mtp_volume_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid MTP volume values.",
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
	if( data_size < 10 )
	{
		return( 0 );
	}
	/* Do not try to parse unsupported shell item signatures
	 */
	byte_stream_copy_to_uint32_little_endian(
	 &( data[ 6 ] ),
	 signature );

	if( signature != 0x10312005UL )
	{
		return( 0 );
	}
	byte_stream_copy_to_uint32_little_endian(
	 &( data[ 4 ] ),
	 item_data_size );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: class type indicator\t\t: 0x%02" PRIx8 "\n",
		 function,
		 data[ 2 ] );

		libcnotify_printf(
		 "%s: unknown1\t\t\t\t: 0x%02" PRIx8 "\n",
		 function,
		 data[ 3 ] );

		libcnotify_printf(
		 "%s: data size\t\t\t\t: %" PRIu16 "\n",
		 function,
		 item_data_size );

		libcnotify_printf(
		 "%s: signature\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 signature );
	}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

	if( item_data_size == 0 )
	{
		return( 10 );
	}
	if( ( item_data_size < 44 )
	 && ( item_data_size > ( data_size - 10 ) ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid data size value out of bounds.",
		 function );

		return( -1 );
	}
	byte_stream_copy_to_uint32_little_endian(
	 &( data[ 38 ] ),
	 name_string_size );

	byte_stream_copy_to_uint32_little_endian(
	 &( data[ 42 ] ),
	 identifier_string_size );

	byte_stream_copy_to_uint32_little_endian(
	 &( data[ 46 ] ),
	 file_system_string_size );

	byte_stream_copy_to_uint32_little_endian(
	 &( data[ 50 ] ),
	 number_of_guid_strings );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		byte_stream_copy_to_uint32_little_endian(
		 &( data[ 10 ] ),
		 value_32bit );
		libcnotify_printf(
		 "%s: unknown2\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

		byte_stream_copy_to_uint16_little_endian(
		 &( data[ 14 ] ),
		 value_16bit );
		libcnotify_printf(
		 "%s: unknown3\t\t\t\t: 0x%04" PRIx16 "\n",
		 function,
		 value_16bit );

		byte_stream_copy_to_uint16_little_endian(
		 &( data[ 16 ] ),
		 value_16bit );
		libcnotify_printf(
		 "%s: unknown4\t\t\t\t: 0x%04" PRIx16 "\n",
		 function,
		 value_16bit );

		byte_stream_copy_to_uint16_little_endian(
		 &( data[ 18 ] ),
		 value_16bit );
		libcnotify_printf(
		 "%s: unknown5\t\t\t\t: 0x%04" PRIx16 "\n",
		 function,
		 value_16bit );

		byte_stream_copy_to_uint16_little_endian(
		 &( data[ 20 ] ),
		 value_16bit );
		libcnotify_printf(
		 "%s: unknown6\t\t\t\t: 0x%04" PRIx16 "\n",
		 function,
		 value_16bit );

		byte_stream_copy_to_uint32_little_endian(
		 &( data[ 22 ] ),
		 value_32bit );
		libcnotify_printf(
		 "%s: unknown7\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

		libcnotify_printf(
		 "%s: unknown8:\n",
		 function );
		libcnotify_print_data(
		 &( data[ 26 ] ),
		 8,
		 0 );

		byte_stream_copy_to_uint32_little_endian(
		 &( data[ 34 ] ),
		 value_32bit );
		libcnotify_printf(
		 "%s: unknown9\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

		libcnotify_printf(
		 "%s: name string size\t\t\t: %" PRIu32 "\n",
		 function,
		 name_string_size );

		libcnotify_printf(
		 "%s: identifier string size\t\t: %" PRIu32 "\n",
		 function,
		 identifier_string_size );

		libcnotify_printf(
		 "%s: file system string size\t\t: %" PRIu32 "\n",
		 function,
		 file_system_string_size );

		libcnotify_printf(
		 "%s: number of GUID strings\t\t: %" PRIu32 "\n",
		 function,
		 number_of_guid_strings );
	}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

	data_offset = 54;

	if( name_string_size > 0 )
	{
		name_string_size *= 2;

/* TODO check bounds */
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( libfwsi_debug_print_utf16_string_value(
			     function,
			     "name\t\t\t\t",
			     &( data[ data_offset ] ),
			     name_string_size,
			     LIBUNA_ENDIAN_LITTLE,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_PRINT_FAILED,
				 "%s: unable to print UTF-16 string value.",
				 function );

				return( -1 );
			}
		}
#endif
		data_offset += name_string_size;
	}
	if( identifier_string_size > 0 )
	{
		identifier_string_size *= 2;

/* TODO check bounds */
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( libfwsi_debug_print_utf16_string_value(
			     function,
			     "identifier\t\t\t\t",
			     &( data[ data_offset ] ),
			     identifier_string_size,
			     LIBUNA_ENDIAN_LITTLE,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_PRINT_FAILED,
				 "%s: unable to print UTF-16 string value.",
				 function );

				return( -1 );
			}
		}
#endif
		data_offset += identifier_string_size;
	}
	if( file_system_string_size > 0 )
	{
		file_system_string_size *= 2;

/* TODO check bounds */
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( libfwsi_debug_print_utf16_string_value(
			     function,
			     "file system\t\t\t",
			     &( data[ data_offset ] ),
			     file_system_string_size,
			     LIBUNA_ENDIAN_LITTLE,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_PRINT_FAILED,
				 "%s: unable to print UTF-16 string value.",
				 function );

				return( -1 );
			}
		}
#endif
		data_offset += file_system_string_size;
	}
	for( guid_string_index = 0;
	     guid_string_index < number_of_guid_strings;
	     guid_string_index++ )
	{
/* TODO check bounds */
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( libfwsi_debug_print_utf16_string_value(
			     function,
			     "GUID\t\t\t\t",
			     &( data[ data_offset ] ),
			     78,
			     LIBUNA_ENDIAN_LITTLE,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_PRINT_FAILED,
				 "%s: unable to print UTF-16 string value.",
				 function );

				return( -1 );
			}
		}
#endif
		data_offset += 78;
	}
/* TODO move to common MTP property values function */
	if( data_offset < ( data_size - 4 ) )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			byte_stream_copy_to_uint32_little_endian(
			 &( data[ data_offset ] ),
			 value_32bit );
			libcnotify_printf(
			 "%s: unknown10\t\t\t\t: 0x%08" PRIx32 "\n",
			 function,
			 value_32bit );
		}
#endif
		data_offset += 4;
	}
	if( data_offset < ( data_size - 16 ) )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( libfwsi_debug_print_guid_value(
			     function,
			     "class identifier\t\t\t",
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
	}
	if( data_offset < ( data_size - 4 ) )
	{
		byte_stream_copy_to_uint32_little_endian(
		 &( data[ data_offset ] ),
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
		data_offset += 4;
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
		if( data_offset < ( data_size - 16 ) )
		{
#if defined( HAVE_DEBUG_OUTPUT )
			if( libcnotify_verbose != 0 )
			{
				if( libfwsi_debug_print_guid_value(
				     function,
				     "property set identifier\t\t",
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
		}
		if( data_offset < ( data_size - 4 ) )
		{
#if defined( HAVE_DEBUG_OUTPUT )
			if( libcnotify_verbose != 0 )
			{
				byte_stream_copy_to_uint32_little_endian(
				 &( data[ data_offset ] ),
				 value_32bit );
				libcnotify_printf(
				 "%s: property value identifier\t\t: %" PRIu32 "\n",
				 function,
				 value_32bit );
			}
#endif
			data_offset += 4;
		}
		if( data_offset < ( data_size - 4 ) )
		{
			byte_stream_copy_to_uint32_little_endian(
			 &( data[ data_offset ] ),
			 property_value_type );

#if defined( HAVE_DEBUG_OUTPUT )
			if( libcnotify_verbose != 0 )
			{
				libcnotify_printf(
				 "%s: property value type\t\t: 0x%08" PRIx32 " (%s : %s)\n",
				 function,
				 property_value_type,
				 libfole_value_type_get_identifier(
				  property_value_type ),
				 libfole_value_type_get_description(
				  property_value_type ) );
			}
#endif
			data_offset += 4;
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
					 &( data[ data_offset ] ),
					 8,
					 0 );
				}
#endif
				data_offset += 8;

				break;

			case 0x0000000bUL:
			case 0x00000012UL:
				if( data_offset < ( data_size - 2 ) )
				{
#if defined( HAVE_DEBUG_OUTPUT )
					if( libcnotify_verbose != 0 )
					{
						byte_stream_copy_to_uint16_little_endian(
						 &( data[ data_offset ] ),
						 value_16bit );
						libcnotify_printf(
						 "%s: value\t\t\t\t: 0x%04" PRIx16 "\n",
						 function,
						 value_16bit );

						libcnotify_printf(
						 "\n" );
					}
#endif
					data_offset += 2;
				}
				break;

			case 0x0000000aUL:
			case 0x00000013UL:
				if( data_offset < ( data_size - 4 ) )
				{
#if defined( HAVE_DEBUG_OUTPUT )
					if( libcnotify_verbose != 0 )
					{
						byte_stream_copy_to_uint32_little_endian(
						 &( data[ data_offset ] ),
						 value_32bit );
						libcnotify_printf(
						 "%s: value\t\t\t\t: 0x%08" PRIx32 "\n",
						 function,
						 value_32bit );

						libcnotify_printf(
						 "\n" );
					}
#endif
					data_offset += 4;
				}
				break;

			case 0x0000001fUL:
				if( data_offset < ( data_size - 4 ) )
				{
					byte_stream_copy_to_uint32_little_endian(
					 &( data[ data_offset ] ),
					 string_size );

#if defined( HAVE_DEBUG_OUTPUT )
					if( libcnotify_verbose != 0 )
					{
						libcnotify_printf(
						 "%s: string size\t\t\t: %" PRIu32 "\n",
						 function,
						 string_size );
					}
#endif
					data_offset += 4;

					if( string_size > 0 )
					{
#if defined( HAVE_DEBUG_OUTPUT )
						if( libcnotify_verbose != 0 )
						{
							if( libfwsi_debug_print_utf16_string_value(
							     function,
							     "string\t\t\t\t",
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

								return( -1 );
							}
							libcnotify_printf(
							 "\n" );
						}
#endif
						data_offset += string_size;
					}
				}
				break;

			case 0x00000048UL:
				if( data_offset < ( data_size - 16 ) )
				{
#if defined( HAVE_DEBUG_OUTPUT )
					if( libcnotify_verbose != 0 )
					{
						if( libfwsi_debug_print_guid_value(
						     function,
						     "GUID\t\t\t\t",
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
						 "\n" );
					}
#endif
					data_offset += 16;
				}
				break;
		}
	}
/* TODO */

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "\n" );
	}
#endif
	return( 1 );
}

