/*
 * Windows Shell Item functions
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

#include "libfwsi_acronis_tib_file_values.h"
#include "libfwsi_cdburn_values.h"
#include "libfwsi_compressed_folder_values.h"
#include "libfwsi_codepage.h"
#include "libfwsi_control_panel_category_values.h"
#include "libfwsi_control_panel_cpl_file_values.h"
#include "libfwsi_control_panel_item_values.h"
#include "libfwsi_definitions.h"
#include "libfwsi_delegate_folder_values.h"
#include "libfwsi_extension_block.h"
#include "libfwsi_file_attributes.h"
#include "libfwsi_file_entry_values.h"
#include "libfwsi_game_folder_values.h"
#include "libfwsi_item.h"
#include "libfwsi_libcdata.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"
#include "libfwsi_libfdatetime.h"
#include "libfwsi_libfguid.h"
#include "libfwsi_libuna.h"
#include "libfwsi_mtp_file_entry_values.h"
#include "libfwsi_mtp_volume_values.h"
#include "libfwsi_network_location_values.h"
#include "libfwsi_root_folder_values.h"
#include "libfwsi_shell_folder_identifier.h"
#include "libfwsi_types.h"
#include "libfwsi_uri_values.h"
#include "libfwsi_uri_sub_values.h"
#include "libfwsi_users_property_view_values.h"
#include "libfwsi_volume_values.h"
#include "libfwsi_web_site_values.h"

/* Creates an item
 * Make sure the value item is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_item_initialize(
     libfwsi_item_t **item,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item = NULL;
	static char *function                  = "libfwsi_item_initialize";

	if( item == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item.",
		 function );

		return( -1 );
	}
	if( *item != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid item value already set.",
		 function );

		return( -1 );
	}
	if( libfwsi_internal_item_initialize(
	     &internal_item,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
		 "%s: unable to create item.",
		 function );

		return( -1 );
	}
	*item = (libfwsi_item_t *) internal_item;

	return( 1 );
}

/* Creates an item
 * Make sure the value item is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_internal_item_initialize(
     libfwsi_internal_item_t **internal_item,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_internal_item_initialize";

	if( internal_item == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item.",
		 function );

		return( -1 );
	}
	if( *internal_item != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid item value already set.",
		 function );

		return( -1 );
	}
	*internal_item = memory_allocate_structure(
	                  libfwsi_internal_item_t );

	if( *internal_item == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create item.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *internal_item,
	     0,
	     sizeof( libfwsi_internal_item_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear item.",
		 function );

		goto on_error;
	}
	if( libcdata_array_initialize(
	     &( ( *internal_item )->extension_blocks_array ),
	     0,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
		 "%s: unable to create extension blocks array.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *internal_item != NULL )
	{
		memory_free(
		 *internal_item );

		*internal_item = NULL;
	}
	return( -1 );
}

/* Frees an item
 * Returns 1 if successful or -1 on error
 */
int libfwsi_item_free(
     libfwsi_item_t **item,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item = NULL;
	static char *function                  = "libfwsi_item_free";
	int result                             = 1;

	if( item == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item.",
		 function );

		return( -1 );
	}
	if( *item != NULL )
	{
		internal_item = (libfwsi_internal_item_t *) *item;

		if( internal_item->is_managed == 0 )
		{
			if( libfwsi_internal_item_free(
			     &internal_item,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
				 "%s: unable to free item.",
				 function );

				result = -1;
			}
		}
		*item = NULL;
	}
	return( result );
}

/* Frees an item
 * Returns 1 if successful or -1 on error
 */
int libfwsi_internal_item_free(
     libfwsi_internal_item_t **internal_item,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_internal_item_free";
	int result            = 1;

	if( internal_item == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item.",
		 function );

		return( -1 );
	}
	if( *internal_item != NULL )
	{
		if( ( *internal_item )->value != NULL )
		{
			if( ( *internal_item )->free_value != NULL )
			{
				if( ( *internal_item )->free_value(
				     &( ( *internal_item )->value ),
				     error ) != 1 )
				{
					libcerror_error_set(
					 error,
					 LIBCERROR_ERROR_DOMAIN_RUNTIME,
					 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
					 "%s: unable to free item value.",
					 function );

					result = -1;
				}
			}
		}
		if( libcdata_array_free(
		     &( ( *internal_item )->extension_blocks_array ),
		     (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_internal_extension_block_free,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
			 "%s: unable to free extension blocks array.",
			 function );

			result = -1;
		}
		memory_free(
		 *internal_item );

		*internal_item = NULL;
	}
	return( result );
}

/* Copies a shell item from a byte stream
 * Returns 1 if successful or -1 on error
 */
int libfwsi_item_copy_from_byte_stream(
     libfwsi_item_t *item,
     const uint8_t *byte_stream,
     size_t byte_stream_size,
     int ascii_codepage,
     libcerror_error_t **error )
{
	libfwsi_delegate_folder_values_t *delegate_folder_values = NULL;
        libfwsi_internal_extension_block_t *extension_block      = NULL;
	libfwsi_internal_item_t *internal_item                   = NULL;
	libfwsi_internal_item_t *internal_parent_item            = NULL;
	static char *function                                    = "libfwsi_item_copy_from_byte_stream";
	const uint8_t *shell_item_data                           = NULL;
	size_t byte_stream_offset                                = 0;
	size_t delegate_class_identifier_offset                  = 0;
	size_t delegate_shell_item_data_size                     = 0;
	size_t shell_item_data_size                              = 0;
	uint32_t signature                                       = 0;
	uint16_t first_extension_block_offset                    = 0;
	int entry_index                                          = 0;
	int number_of_extension_blocks                           = 0;
	int result                                               = 0;

	if( item == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) item;

	if( byte_stream == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid byte stream.",
		 function );

		return( -1 );
	}
	if( ( byte_stream_size < 2 )
	 || ( byte_stream_size > (size_t) SSIZE_MAX ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: byte stream size value out of bounds.",
		 function );

		return( -1 );
	}
	if( ( ascii_codepage != LIBFWSI_CODEPAGE_ASCII )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_874 )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_932 )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_936 )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_949 )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_950 )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_1250 )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_1251 )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_1252 )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_1253 )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_1254 )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_1255 )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_1256 )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_1257 )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_1258 ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported ASCII codepage.",
		 function );

		return( -1 );
	}
	byte_stream_copy_to_uint16_little_endian(
	 byte_stream,
	 internal_item->data_size );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: size\t\t\t\t: %" PRIu16 "\n",
		 function,
		 internal_item->data_size );
	}
#endif
	if( internal_item->data_size == 0 )
	{
		return( 1 );
	}
	if( ( internal_item->data_size < 4 )
	 || ( (size_t) internal_item->data_size > byte_stream_size ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid shell item size value out of bounds.",
		 function );

		goto on_error;
	}
	shell_item_data      = byte_stream;
	shell_item_data_size = internal_item->data_size;

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: data:\n",
		 function );
		libcnotify_print_data(
		 &( shell_item_data[ 2 ] ),
		 shell_item_data_size - 2,
		 LIBCNOTIFY_PRINT_DATA_FLAG_GROUP_DATA );
	}
#endif
	if( shell_item_data_size >= 38 )
	{
		byte_stream_copy_to_uint16_little_endian(
		 &( byte_stream[ internal_item->data_size - 2 ] ),
		 delegate_class_identifier_offset );

		if( ( delegate_class_identifier_offset >= 32 )
		 && ( delegate_class_identifier_offset < ( shell_item_data_size - 2 ) ) )
		{
			delegate_shell_item_data_size = delegate_class_identifier_offset;
		}
		else
		{
			delegate_class_identifier_offset = shell_item_data_size;
			delegate_shell_item_data_size    = shell_item_data_size;
		}
		delegate_class_identifier_offset -= 32;

		if( memory_compare(
		     &( shell_item_data[ delegate_class_identifier_offset ] ),
		     libfwsi_delegate_class_identifier,
		     16 ) == 0 )
		{
			if( libfwsi_delegate_folder_values_initialize(
			     &delegate_folder_values,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create delegate folder values.",
				 function );

				goto on_error;
			}
			if( libfwsi_delegate_folder_values_read_data(
			     delegate_folder_values,
			     shell_item_data,
			     delegate_shell_item_data_size,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_IO,
				 LIBCERROR_IO_ERROR_READ_FAILED,
				 "%s: unable to read delegate folder values.",
				 function );

				goto on_error;
			}
			if( memory_copy(
			     internal_item->delegate_folder_identifier,
			     delegate_folder_values->identifier,
			     16 ) == NULL )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_MEMORY,
				 LIBCERROR_MEMORY_ERROR_COPY_FAILED,
				 "%s: unable to copy delegate folder identifier.",
				 function );

				goto on_error;
			}
			internal_item->has_delegate_folder_identifier = 1;

			if( memory_compare(
			     delegate_folder_values->identifier,
			     libfwsi_shell_folder_identifier_search_folder,
			     16 ) == 0 )
			{
				/* Do not realign shell_item_data */
			}
			else if( memory_compare(
			          delegate_folder_values->identifier,
			          libfwsi_shell_folder_identifier_users_files_folder_delegate_folder,
			          16 ) == 0 )
			{
/* TODO debug print unknown data */
				shell_item_data      = &( delegate_folder_values->inner_data[ 4 ] );
				shell_item_data_size = delegate_folder_values->inner_data_size - 4;
			}
			else if( memory_compare(
			          delegate_folder_values->identifier,
			          libfwsi_shell_folder_identifier_removable_drives,
			          16 ) == 0 )
			{
/* TODO debug print unknown data */
				shell_item_data      = &( delegate_folder_values->inner_data[ 4 ] );
				shell_item_data_size = delegate_folder_values->inner_data_size - 4;
			}
			else
			{
				shell_item_data      = delegate_folder_values->inner_data;
				shell_item_data_size = delegate_folder_values->inner_data_size;
			}
			if( libfwsi_delegate_folder_values_free(
			     &delegate_folder_values,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
				 "%s: unable to free delegate folder values.",
				 function );

				goto on_error;
			}
		}
	}
	if( ( internal_item->type == 0 )
	 && ( shell_item_data_size >= 6 ) )
	{
		byte_stream_copy_to_uint32_little_endian(
		 &( shell_item_data[ 2 ] ),
		 signature );

		switch( signature )
		{
			case 0xacb16752UL:
				internal_item->type = LIBFWSI_ITEM_TYPE_ACRONIS_TIB_FILE;
				break;

			default:
				break;
		}
	}
	if( ( internal_item->type == 0 )
	 && ( shell_item_data_size >= 8 ) )
	{
		byte_stream_copy_to_uint32_little_endian(
		 &( shell_item_data[ 4 ] ),
		 signature );

		switch( signature )
		{
			case 0x39de2184UL:
				internal_item->type = LIBFWSI_ITEM_TYPE_CONTROL_PANEL_CATEGORY;
				break;

			/* "AugM" */
			case 0x4d677541UL:
				internal_item->type = LIBFWSI_ITEM_TYPE_CDBURN;
				break;

			/* "GFSI" */
			case 0x49534647UL:
				internal_item->type = LIBFWSI_ITEM_TYPE_GAME_FOLDER;
				break;

			case 0xc001b000UL:
				internal_item->type = LIBFWSI_ITEM_TYPE_WEB_SITE;
				break;

			case 0xffffff38UL:
				internal_item->type = LIBFWSI_ITEM_TYPE_CONTROL_PANEL_CPL_FILE;
				break;

			default:
				break;
		}
	}
	if( ( internal_item->type == 0 )
	 && ( shell_item_data_size >= 10 ) )
	{
		byte_stream_copy_to_uint32_little_endian(
		 &( shell_item_data[ 6 ] ),
		 signature );

		switch( signature )
		{
			case 0x07192006UL:
				internal_item->type = LIBFWSI_ITEM_TYPE_MTP_FILE_ENTRY;
				break;

			case 0x10312005UL:
				internal_item->type = LIBFWSI_ITEM_TYPE_MTP_VOLUME;
				break;

			case 0x10141981UL:
			case 0x23a3dfd5UL:
			case 0x23febbeeUL:
			case 0x3b93afbbUL:
			case 0x49505241UL:
			case 0xbeebee00UL:
				internal_item->type = LIBFWSI_ITEM_TYPE_USERS_PROPERTY_VIEW;
				break;

			default:
				break;
		}
	}
	if( ( internal_item->type == 0 )
	 && ( shell_item_data_size >= 56 ) )
	{
		if( ( shell_item_data[ 28 ] == (uint8_t) '/' )
		 && ( shell_item_data[ 29 ] == (uint8_t) 0 )
		 && ( shell_item_data[ 34 ] == (uint8_t) '/' )
		 && ( shell_item_data[ 35 ] == (uint8_t) 0 )
		 && ( shell_item_data[ 40 ] == (uint8_t) ' ' )
		 && ( shell_item_data[ 41 ] == (uint8_t) 0 )
		 && ( shell_item_data[ 42 ] == (uint8_t) ' ' )
		 && ( shell_item_data[ 43 ] == (uint8_t) 0 )
		 && ( shell_item_data[ 48 ] == (uint8_t) ':' )
		 && ( shell_item_data[ 49 ] == (uint8_t) 0 )
		 && ( shell_item_data[ 54 ] == (uint8_t) 0 )
		 && ( shell_item_data[ 55 ] == (uint8_t) 0 ) )
		{
			internal_item->type = LIBFWSI_ITEM_TYPE_COMPRESSED_FOLDER;
		}
	}
	if( ( internal_item->type == 0 )
	 && ( shell_item_data_size >= 78 ) )
	{
		if( ( shell_item_data[ 36 ] == (uint8_t) 'N' )
		 && ( shell_item_data[ 37 ] == (uint8_t) 0 )
		 && ( shell_item_data[ 38 ] == (uint8_t) '/' )
		 && ( shell_item_data[ 39 ] == (uint8_t) 0 )
		 && ( shell_item_data[ 40 ] == (uint8_t) 'A' )
		 && ( shell_item_data[ 41 ] == (uint8_t) 0 )
		 && ( shell_item_data[ 42 ] == (uint8_t) 0 )
		 && ( shell_item_data[ 43 ] == (uint8_t) 0 ) )
		{
			internal_item->type = LIBFWSI_ITEM_TYPE_COMPRESSED_FOLDER;
		}
		else if( ( shell_item_data[ 40 ] == (uint8_t) '/' )
		      && ( shell_item_data[ 41 ] == (uint8_t) 0 )
		      && ( shell_item_data[ 46 ] == (uint8_t) '/' )
		      && ( shell_item_data[ 47 ] == (uint8_t) 0 )
		      && ( shell_item_data[ 56 ] == (uint8_t) ' ' )
		      && ( shell_item_data[ 57 ] == (uint8_t) 0 )
		      && ( shell_item_data[ 58 ] == (uint8_t) ' ' )
		      && ( shell_item_data[ 59 ] == (uint8_t) 0 )
		      && ( shell_item_data[ 64 ] == (uint8_t) ':' )
		      && ( shell_item_data[ 65 ] == (uint8_t) 0 )
		      && ( shell_item_data[ 70 ] == (uint8_t) ':' )
		      && ( shell_item_data[ 71 ] == (uint8_t) 0 )
		      && ( shell_item_data[ 76 ] == (uint8_t) 0 )
		      && ( shell_item_data[ 77 ] == (uint8_t) 0 ) )
		{
			internal_item->type = LIBFWSI_ITEM_TYPE_COMPRESSED_FOLDER;
		}
	}
	if( ( internal_item->type == 0 )
	 && ( shell_item_data_size >= 3 ) )
	{
		internal_item->class_type = shell_item_data[ 2 ];

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			libcnotify_printf(
			 "%s: class type indicator\t\t: 0x%02" PRIx8 "\n",
			 function,
			 internal_item->class_type );
		}
#endif
		switch( internal_item->class_type & 0x70 )
		{
			case 0x10:
				if( internal_item->class_type == 0x1f )
				{
					internal_item->type = LIBFWSI_ITEM_TYPE_ROOT_FOLDER;
				}
				break;

			case 0x20:
				internal_item->type = LIBFWSI_ITEM_TYPE_VOLUME;
				break;

			case 0x30:
				internal_item->type = LIBFWSI_ITEM_TYPE_FILE_ENTRY;
				break;

			case 0x40:
				internal_item->type = LIBFWSI_ITEM_TYPE_NETWORK_LOCATION;
				break;

			case 0x60:
				if( internal_item->class_type == 0x61 )
				{
					internal_item->type = LIBFWSI_ITEM_TYPE_URI;
				}
				break;

			case 0x70:
				if( internal_item->class_type == 0x71 )
				{
					internal_item->type = LIBFWSI_ITEM_TYPE_CONTROL_PANEL_ITEM;
				}
				break;

			default:
				break;
		}
	}
	if( libfwsi_item_get_parent_item(
	     (libfwsi_item_t *) internal_item,
	     (libfwsi_item_t **) &internal_parent_item,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve parent shell item.",
		 function );

		goto on_error;
	}
	if( internal_parent_item != NULL )
	{
		switch( internal_parent_item->type )
		{
			case LIBFWSI_ITEM_TYPE_COMPRESSED_FOLDER:
				internal_item->type = LIBFWSI_ITEM_TYPE_COMPRESSED_FOLDER;
				break;

			case LIBFWSI_ITEM_TYPE_URI:
				internal_item->type = LIBFWSI_ITEM_TYPE_URI_SUB_VALUES;
				break;
		}
	}
	switch( internal_item->type )
	{
		case LIBFWSI_ITEM_TYPE_ACRONIS_TIB_FILE:
			internal_item->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_acronis_tib_file_values_free;

			if( libfwsi_acronis_tib_file_values_initialize(
			     (libfwsi_acronis_tib_file_values_t **) &( internal_item->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create Acronis True Image (TIB) file values.",
				 function );

				goto on_error;
			}
			result = libfwsi_acronis_tib_file_values_read_data(
			          (libfwsi_acronis_tib_file_values_t *) internal_item->value,
			          shell_item_data,
			          shell_item_data_size,
			          error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_IO,
				 LIBCERROR_IO_ERROR_READ_FAILED,
				 "%s: unable to read Acronis True Image (TIB) file values.",
				 function );

				goto on_error;
			}
			break;

		case LIBFWSI_ITEM_TYPE_CDBURN:
			internal_item->signature  = signature;
			internal_item->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_cdburn_values_free;

			if( libfwsi_cdburn_values_initialize(
			     (libfwsi_cdburn_values_t **) &( internal_item->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create CD burn values.",
				 function );

				goto on_error;
			}
			result = libfwsi_cdburn_values_read_data(
			          (libfwsi_cdburn_values_t *) internal_item->value,
			          shell_item_data,
			          shell_item_data_size,
			          error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_IO,
				 LIBCERROR_IO_ERROR_READ_FAILED,
				 "%s: unable to read CD burn values.",
				 function );

				goto on_error;
			}
			break;

		case LIBFWSI_ITEM_TYPE_COMPRESSED_FOLDER:
			internal_item->signature  = signature;
			internal_item->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_compressed_folder_values_free;

			if( libfwsi_compressed_folder_values_initialize(
			     (libfwsi_compressed_folder_values_t **) &( internal_item->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create compressed folder values.",
				 function );

				goto on_error;
			}
			result = libfwsi_compressed_folder_values_read_data(
			          (libfwsi_compressed_folder_values_t *) internal_item->value,
			          shell_item_data,
			          shell_item_data_size,
			          error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_IO,
				 LIBCERROR_IO_ERROR_READ_FAILED,
				 "%s: unable to read compressed folder values.",
				 function );

				goto on_error;
			}
			break;

		case LIBFWSI_ITEM_TYPE_CONTROL_PANEL_ITEM:
			internal_item->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_control_panel_item_values_free;

			if( libfwsi_control_panel_item_values_initialize(
			     (libfwsi_control_panel_item_values_t **) &( internal_item->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create control panel item values.",
				 function );

				goto on_error;
			}
			result = libfwsi_control_panel_item_values_read_data(
			          (libfwsi_control_panel_item_values_t *) internal_item->value,
			          shell_item_data,
			          shell_item_data_size,
			          error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_IO,
				 LIBCERROR_IO_ERROR_READ_FAILED,
				 "%s: unable to read control panel item values.",
				 function );

				goto on_error;
			}
			break;

		case LIBFWSI_ITEM_TYPE_CONTROL_PANEL_CATEGORY:
			internal_item->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_control_panel_category_values_free;

			if( libfwsi_control_panel_category_values_initialize(
			     (libfwsi_control_panel_category_values_t **) &( internal_item->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create control panel category values.",
				 function );

				goto on_error;
			}
			result = libfwsi_control_panel_category_values_read_data(
			          (libfwsi_control_panel_category_values_t *) internal_item->value,
			          shell_item_data,
			          shell_item_data_size,
			          error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_IO,
				 LIBCERROR_IO_ERROR_READ_FAILED,
				 "%s: unable to read control panel category values.",
				 function );

				goto on_error;
			}
			break;

		case LIBFWSI_ITEM_TYPE_CONTROL_PANEL_CPL_FILE:
			internal_item->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_control_panel_cpl_file_values_free;

			if( libfwsi_control_panel_cpl_file_values_initialize(
			     (libfwsi_control_panel_cpl_file_values_t **) &( internal_item->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create control panel CPL file values.",
				 function );

				goto on_error;
			}
			result = libfwsi_control_panel_cpl_file_values_read_data(
			          (libfwsi_control_panel_cpl_file_values_t *) internal_item->value,
			          shell_item_data,
			          shell_item_data_size,
			          error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_IO,
				 LIBCERROR_IO_ERROR_READ_FAILED,
				 "%s: unable to read control panel CPL file values.",
				 function );

				goto on_error;
			}
			break;

		case LIBFWSI_ITEM_TYPE_FILE_ENTRY:
			internal_item->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_file_entry_values_free;

			if( libfwsi_file_entry_values_initialize(
			     (libfwsi_file_entry_values_t **) &( internal_item->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create file entry values.",
				 function );

				goto on_error;
			}
			result = libfwsi_file_entry_values_read_data(
			          (libfwsi_file_entry_values_t *) internal_item->value,
			          shell_item_data,
			          shell_item_data_size,
			          ascii_codepage,
			          error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_IO,
				 LIBCERROR_IO_ERROR_READ_FAILED,
				 "%s: unable to read file entry values.",
				 function );

				goto on_error;
			}
			break;

		case LIBFWSI_ITEM_TYPE_GAME_FOLDER:
			internal_item->signature  = signature;
			internal_item->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_game_folder_values_free;

			if( libfwsi_game_folder_values_initialize(
			     (libfwsi_game_folder_values_t **) &( internal_item->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create game folder values.",
				 function );

				goto on_error;
			}
			result = libfwsi_game_folder_values_read_data(
			          (libfwsi_game_folder_values_t *) internal_item->value,
			          shell_item_data,
			          shell_item_data_size,
			          error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_IO,
				 LIBCERROR_IO_ERROR_READ_FAILED,
				 "%s: unable to read game folder values.",
				 function );

				goto on_error;
			}
			break;

		case LIBFWSI_ITEM_TYPE_MTP_FILE_ENTRY:
			internal_item->signature  = signature;
			internal_item->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_mtp_file_entry_values_free;

			if( libfwsi_mtp_file_entry_values_initialize(
			     (libfwsi_mtp_file_entry_values_t **) &( internal_item->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create MTP file entry values.",
				 function );

				goto on_error;
			}
			result = libfwsi_mtp_file_entry_values_read_data(
			          (libfwsi_mtp_file_entry_values_t *) internal_item->value,
			          shell_item_data,
			          shell_item_data_size,
			          error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_IO,
				 LIBCERROR_IO_ERROR_READ_FAILED,
				 "%s: unable to read MTP file entry values.",
				 function );

				goto on_error;
			}
			break;

		case LIBFWSI_ITEM_TYPE_MTP_VOLUME:
			internal_item->signature  = signature;
			internal_item->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_mtp_volume_values_free;

			if( libfwsi_mtp_volume_values_initialize(
			     (libfwsi_mtp_volume_values_t **) &( internal_item->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create MTP volume values.",
				 function );

				goto on_error;
			}
			result = libfwsi_mtp_volume_values_read_data(
			          (libfwsi_mtp_volume_values_t *) internal_item->value,
			          shell_item_data,
			          shell_item_data_size,
			          error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_IO,
				 LIBCERROR_IO_ERROR_READ_FAILED,
				 "%s: unable to read MTP volume values.",
				 function );

				goto on_error;
			}
			break;

		case LIBFWSI_ITEM_TYPE_NETWORK_LOCATION:
			internal_item->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_network_location_values_free;

			if( libfwsi_network_location_values_initialize(
			     (libfwsi_network_location_values_t **) &( internal_item->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create network location values.",
				 function );

				goto on_error;
			}
			result = libfwsi_network_location_values_read_data(
			          (libfwsi_network_location_values_t *) internal_item->value,
			          shell_item_data,
			          shell_item_data_size,
			          ascii_codepage,
			          error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_IO,
				 LIBCERROR_IO_ERROR_READ_FAILED,
				 "%s: unable to read network location values.",
				 function );

				goto on_error;
			}
			break;

		case LIBFWSI_ITEM_TYPE_ROOT_FOLDER:
			internal_item->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_root_folder_values_free;

			if( libfwsi_root_folder_values_initialize(
			     (libfwsi_root_folder_values_t **) &( internal_item->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create root folder values.",
				 function );

				goto on_error;
			}
			result = libfwsi_root_folder_values_read_data(
				  (libfwsi_root_folder_values_t *) internal_item->value,
				  shell_item_data,
				  shell_item_data_size,
				  error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_IO,
				 LIBCERROR_IO_ERROR_READ_FAILED,
				 "%s: unable to read root folder values.",
				 function );

				goto on_error;
			}
			break;

		case LIBFWSI_ITEM_TYPE_URI:
			internal_item->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_uri_values_free;

			if( libfwsi_uri_values_initialize(
			     (libfwsi_uri_values_t **) &( internal_item->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create URI values.",
				 function );

				goto on_error;
			}
			result = libfwsi_uri_values_read_data(
			          (libfwsi_uri_values_t *) internal_item->value,
			          shell_item_data,
			          shell_item_data_size,
			          ascii_codepage,
			          error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_IO,
				 LIBCERROR_IO_ERROR_READ_FAILED,
				 "%s: unable to read URI values.",
				 function );

				goto on_error;
			}
			break;

		case LIBFWSI_ITEM_TYPE_URI_SUB_VALUES:
			internal_item->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_uri_sub_values_free;

			if( libfwsi_uri_sub_values_initialize(
			     (libfwsi_uri_sub_values_t **) &( internal_item->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create URI sub values.",
				 function );

				goto on_error;
			}
			result = libfwsi_uri_sub_values_read_data(
			          (libfwsi_uri_sub_values_t *) internal_item->value,
			          shell_item_data,
			          shell_item_data_size,
			          ascii_codepage,
			          error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_IO,
				 LIBCERROR_IO_ERROR_READ_FAILED,
				 "%s: unable to read URI sub values.",
				 function );

				goto on_error;
			}
			break;

		case LIBFWSI_ITEM_TYPE_USERS_PROPERTY_VIEW:
			internal_item->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_users_property_view_values_free;

			if( libfwsi_users_property_view_values_initialize(
			     (libfwsi_users_property_view_values_t **) &( internal_item->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create users property view values.",
				 function );

				goto on_error;
			}
			result = libfwsi_users_property_view_values_read_data(
			          (libfwsi_users_property_view_values_t *) internal_item->value,
			          shell_item_data,
			          shell_item_data_size,
			          ascii_codepage,
			          error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_IO,
				 LIBCERROR_IO_ERROR_READ_FAILED,
				 "%s: unable to read users property view values.",
				 function );

				goto on_error;
			}
			break;

		case LIBFWSI_ITEM_TYPE_VOLUME:
			internal_item->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_volume_values_free;

			if( libfwsi_volume_values_initialize(
			     (libfwsi_volume_values_t **) &( internal_item->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create volume values.",
				 function );

				goto on_error;
			}
			result = libfwsi_volume_values_read_data(
			          (libfwsi_volume_values_t *) internal_item->value,
			          shell_item_data,
			          shell_item_data_size,
			          ascii_codepage,
			          error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_IO,
				 LIBCERROR_IO_ERROR_READ_FAILED,
				 "%s: unable to read volume values.",
				 function );

				goto on_error;
			}
			break;

		case LIBFWSI_ITEM_TYPE_WEB_SITE:
			internal_item->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_web_site_values_free;

			if( libfwsi_web_site_values_initialize(
			     (libfwsi_web_site_values_t **) &( internal_item->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create web site values.",
				 function );

				goto on_error;
			}
			result = libfwsi_web_site_values_read_data(
			          (libfwsi_web_site_values_t *) internal_item->value,
			          shell_item_data,
			          shell_item_data_size,
			          error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_IO,
				 LIBCERROR_IO_ERROR_READ_FAILED,
				 "%s: unable to read web site values.",
				 function );

				goto on_error;
			}
			break;

		case LIBFWSI_ITEM_TYPE_UNKNOWN:
		default:
			break;
	}
	if( result == 0 )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			libcnotify_printf(
			 "%s: unsupported shell item type.\n",
			 function );
		}
#endif
		internal_item->type       = LIBFWSI_ITEM_TYPE_UNKNOWN;
		internal_item->class_type = 0;
		internal_item->signature  = 0;
	}
	byte_stream_copy_to_uint16_little_endian(
	 &( byte_stream[ internal_item->data_size - 2 ] ),
	 first_extension_block_offset );

	if( ( first_extension_block_offset >= 4 )
	 && ( first_extension_block_offset < ( internal_item->data_size - 2 ) ) )
	{
		byte_stream_offset   = (size_t) first_extension_block_offset;
		shell_item_data_size = internal_item->data_size - byte_stream_offset;

		while( shell_item_data_size > 2 )
		{
			if( libfwsi_extension_block_initialize(
			     (libfwsi_extension_block_t **) &extension_block,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create extension block.",
				 function );

				goto on_error;
			}
			result = libfwsi_extension_block_copy_from_byte_stream(
				  extension_block,
				  &( byte_stream[ byte_stream_offset ] ),
				  shell_item_data_size,
				  ascii_codepage,
				  error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
				 "%s: unable to copy byte stream to extension block.",
				 function );

				goto on_error;
			}
			else if( result == 0 )
			{
				break;
			}
			byte_stream_offset   += extension_block->data_size;
			shell_item_data_size -= extension_block->data_size;

			if( extension_block->data_size == 2 )
			{
				break;
			}
			if( libcdata_array_append_entry(
			     internal_item->extension_blocks_array,
			     &entry_index,
			     (intptr_t *) extension_block,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_APPEND_FAILED,
				 "%s: unable to append extension block.",
				 function );

				goto on_error;
			}
			extension_block = NULL;

			number_of_extension_blocks++;
		}
		if( extension_block != NULL )
		{
			if( libfwsi_internal_extension_block_free(
			     &extension_block,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
				 "%s: unable to free extension block.",
				 function );

				goto on_error;
			}
		}
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			if( ( number_of_extension_blocks > 0 )
			 && ( shell_item_data_size > 0 ) )
			{
				libcnotify_printf(
				 "%s: trailing data:\n",
				 function );
				libcnotify_print_data(
				 &( byte_stream[ byte_stream_offset ] ),
				 shell_item_data_size,
				 LIBCNOTIFY_PRINT_DATA_FLAG_GROUP_DATA );
			}
		}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */
	}
	internal_item->ascii_codepage = ascii_codepage;

	return( 1 );

on_error:
	if( extension_block != NULL )
	{
		libfwsi_internal_extension_block_free(
		 &extension_block,
		 NULL );
	}
	if( delegate_folder_values != NULL )
	{
		libfwsi_delegate_folder_values_free(
		 &delegate_folder_values,
		 NULL );
	}
	if( ( internal_item->value != NULL )
	 && ( internal_item->free_value != NULL ) )
	{
		internal_item->free_value(
		 &( internal_item->value ),
		 NULL );
	}
	return( -1 );
}

/* Retrieves the type
 * Returns 1 if successful or -1 on error
 */
int libfwsi_item_get_type(
     libfwsi_item_t *item,
     int *type,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item = NULL;
	static char *function                  = "libfwsi_item_get_type";

	if( item == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) item;

	if( type == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid type.",
		 function );

		return( -1 );
	}
	*type = internal_item->type;

	return( 1 );
}

/* Retrieves the class type
 * Returns 1 if successful or -1 on error
 */
int libfwsi_item_get_class_type(
     libfwsi_item_t *item,
     uint8_t *class_type,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item = NULL;
	static char *function                  = "libfwsi_item_get_class_type";

	if( item == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) item;

	if( class_type == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid class type.",
		 function );

		return( -1 );
	}
	*class_type = internal_item->class_type;

	return( 1 );
}

/* Retrieves the signature
 * Returns 1 if successful or -1 on error
 */
int libfwsi_item_get_signature(
     libfwsi_item_t *item,
     uint32_t *signature,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item = NULL;
	static char *function                  = "libfwsi_item_get_signature";

	if( item == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) item;

	if( signature == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid signature.",
		 function );

		return( -1 );
	}
	*signature = internal_item->signature;

	return( 1 );
}

/* Retrieves the data size
 * Returns 1 if successful or -1 on error
 */
int libfwsi_item_get_data_size(
     libfwsi_item_t *item,
     size_t *data_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item = NULL;
	static char *function                  = "libfwsi_item_get_data_size";

	if( item == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) item;

	if( data_size == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid data size.",
		 function );

		return( -1 );
	}
	*data_size = (size_t) internal_item->data_size;

	return( 1 );
}

/* Retrieves the delegate folder identifier
 * The identifier is a GUID and is 16 bytes of size
 * Returns 1 if successful, 0 if not available or -1 on error
 */
int libfwsi_item_get_delegate_folder_identifier(
     libfwsi_item_t *item,
     uint8_t *guid_data,
     size_t guid_data_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item = NULL;
	static char *function                  = "libfwsi_item_get_delegate_folder_identifier";

	if( item == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) item;

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
	if( internal_item->has_delegate_folder_identifier == 0 )
	{
		return( 0 );
	}
	if( memory_copy(
	     guid_data,
	     internal_item->delegate_folder_identifier,
	     16 ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_COPY_FAILED,
		 "%s: unable to copy delegate folder identifier.",
		 function );

		return( -1 );
	}
	return( 1 );
}

/* Retrieves the number of extension blocks
 * Returns 1 if successful or -1 on error
 */
int libfwsi_item_get_number_of_extension_blocks(
     libfwsi_item_t *item,
     int *number_of_extension_blocks,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item = NULL;
	static char *function                  = "libfwsi_item_get_number_of_extension_blocks";

	if( item == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) item;

	if( libcdata_array_get_number_of_entries(
	     internal_item->extension_blocks_array,
	     number_of_extension_blocks,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve number of entries.",
		 function );

		return( -1 );
	}
	return( 1 );
}

/* Retrieves a specific extension block
 * Returns 1 if successful or -1 on error
 */
int libfwsi_item_get_extension_block(
     libfwsi_item_t *item,
     int extension_block_index,
     libfwsi_extension_block_t **extension_block,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item = NULL;
	static char *function                  = "libfwsi_item_get_extension_block";

	if( item == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) item;

	if( libcdata_array_get_entry_by_index(
	     internal_item->extension_blocks_array,
	     extension_block_index,
	     (intptr_t **) extension_block,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve extension block: %d.",
		 function,
		 extension_block_index );

		return( -1 );
	}
	return( 1 );
}

/* Retrieves the parent shell item
 * Returns 1 if successful or -1 on error
 */
int libfwsi_item_get_parent_item(
     libfwsi_item_t *item,
     libfwsi_item_t **parent_item,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item = NULL;
	static char *function                  = "libfwsi_item_get_parent_item";

	if( item == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) item;

	if( parent_item == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid parent item.",
		 function );

		return( -1 );
	}
	*parent_item = internal_item->parent_item;

	return( 1 );
}

/* Sets the parent shell item
 * Returns 1 if successful or -1 on error
 */
int libfwsi_item_set_parent_item(
     libfwsi_item_t *item,
     libfwsi_item_t *parent_item,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item = NULL;
	static char *function                  = "libfwsi_item_set_parent_item";

	if( item == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) item;

	internal_item->parent_item = parent_item;

	return( 1 );
}

