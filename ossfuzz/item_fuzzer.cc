/*
 * OSS-Fuzz target for libfwsi item type
 *
 * Copyright (C) 2010-2026, Joachim Metz <joachim.metz@gmail.com>
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

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

extern "C" {

#include "ossfuzz_libfwsi.h"

} /* extern "C" */

/* Retrieves a codepage based on the input
 * The input is mapped onto one of the supported codepages such that
 * the fuzz target exercises the codepage specific data conversion path.
 * The last entry is an unsupported codepage to exercise the validation path
 */
static int ossfuzz_libfwsi_get_codepage(
      const uint8_t *data,
      size_t size )
{
	static const int codepages[ 16 ] = {
		LIBFWSI_CODEPAGE_US_ASCII,
		LIBFWSI_CODEPAGE_WINDOWS_874,
		LIBFWSI_CODEPAGE_WINDOWS_932,
		LIBFWSI_CODEPAGE_WINDOWS_936,
		LIBFWSI_CODEPAGE_WINDOWS_949,
		LIBFWSI_CODEPAGE_WINDOWS_950,
		LIBFWSI_CODEPAGE_WINDOWS_1250,
		LIBFWSI_CODEPAGE_WINDOWS_1251,
		LIBFWSI_CODEPAGE_WINDOWS_1252,
		LIBFWSI_CODEPAGE_WINDOWS_1253,
		LIBFWSI_CODEPAGE_WINDOWS_1254,
		LIBFWSI_CODEPAGE_WINDOWS_1255,
		LIBFWSI_CODEPAGE_WINDOWS_1256,
		LIBFWSI_CODEPAGE_WINDOWS_1257,
		LIBFWSI_CODEPAGE_WINDOWS_1258,
		LIBFWSI_CODEPAGE_ISO_LATIN_1
	};

	if( size == 0 )
	{
		return( LIBFWSI_CODEPAGE_US_ASCII );
	}
	return( codepages[ data[ 0 ] % 16 ] );
}

typedef int (ossfuzz_libfwsi_utf8_size_getter_t)(
      libfwsi_item_t *item,
      size_t *utf8_string_size,
      libfwsi_error_t **error );

typedef int (ossfuzz_libfwsi_utf8_name_getter_t)(
      libfwsi_item_t *item,
      uint8_t *utf8_string,
      size_t utf8_string_size,
      libfwsi_error_t **error );

typedef int (ossfuzz_libfwsi_utf16_size_getter_t)(
      libfwsi_item_t *item,
      size_t *utf16_string_size,
      libfwsi_error_t **error );

typedef int (ossfuzz_libfwsi_utf16_name_getter_t)(
      libfwsi_item_t *item,
      uint16_t *utf16_string,
      size_t utf16_string_size,
      libfwsi_error_t **error );

/* Calls the UTF-8 name or location getters
 */
static void ossfuzz_libfwsi_call_utf8_string_getters(
      libfwsi_item_t *item,
      ossfuzz_libfwsi_utf8_size_getter_t utf8_size_getter,
      ossfuzz_libfwsi_utf8_name_getter_t utf8_name_getter )
{
	uint8_t *utf8_string = NULL;
	size_t utf8_size     = 0;

	if( utf8_size_getter(
	     item,
	     &utf8_size,
	     NULL ) == 1 )
	{
		utf8_string = (uint8_t *) malloc(
	                        utf8_size );

		if( utf8_string != NULL )
		{
			utf8_name_getter(
			 item,
			 utf8_string,
			 utf8_size,
			 NULL );

			free(
			 utf8_string );

			utf8_string = NULL;
		}
	}
}

/* Calls the UTF-16 name or location getters
 */
static void ossfuzz_libfwsi_call_utf16_string_getters(
      libfwsi_item_t *item,
      ossfuzz_libfwsi_utf16_size_getter_t utf16_size_getter,
      ossfuzz_libfwsi_utf16_name_getter_t utf16_name_getter )
{
	uint16_t *utf16_string = NULL;
	size_t utf16_size      = 0;

	if( utf16_size_getter(
	     item,
	     &utf16_size,
	     NULL ) == 1 )
	{
		utf16_string = (uint16_t *) malloc(
	                         utf16_size * sizeof( uint16_t ) );

		if( utf16_string != NULL )
		{
			utf16_name_getter(
			 item,
			 utf16_string,
			 utf16_size,
			 NULL );

			free(
			 utf16_string );

			utf16_string = NULL;
		}
	}
}

/* Retrieves the values of a root folder item
 */
static void ossfuzz_libfwsi_walk_root_folder_item(
      libfwsi_item_t *root_folder )
{
	uint8_t shell_folder_identifier[ 16 ] = { 0 };

	libfwsi_root_folder_get_shell_folder_identifier(
	 root_folder,
	 shell_folder_identifier,
	 sizeof( shell_folder_identifier ),
	 NULL );
}

/* Retrieves the values of a volume item
 */
static void ossfuzz_libfwsi_walk_volume_item(
      libfwsi_item_t *volume )
{
	uint8_t identifier[ 16 ] = { 0 };

	ossfuzz_libfwsi_call_utf8_string_getters(
	 volume,
	 &libfwsi_volume_get_utf8_name_size,
	 &libfwsi_volume_get_utf8_name );

	ossfuzz_libfwsi_call_utf16_string_getters(
	 volume,
	 &libfwsi_volume_get_utf16_name_size,
	 &libfwsi_volume_get_utf16_name );

	libfwsi_volume_get_identifier(
	 volume,
	 identifier,
	 sizeof( identifier ),
	 NULL );

	libfwsi_volume_get_shell_folder_identifier(
	 volume,
	 identifier,
	 sizeof( identifier ),
	 NULL );
}

/* Retrieves the values of a file entry item
 */
static void ossfuzz_libfwsi_walk_file_entry_item(
      libfwsi_item_t *file_entry )
{
	uint32_t file_size             = 0;
	uint32_t fat_date_time         = 0;
	uint32_t file_attribute_flags  = 0;

	libfwsi_file_entry_get_file_size(
	 file_entry,
	 &file_size,
	 NULL );

	libfwsi_file_entry_get_modification_time(
	 file_entry,
	 &fat_date_time,
	 NULL );

	libfwsi_file_entry_get_file_attribute_flags(
	 file_entry,
	 &file_attribute_flags,
	 NULL );

	ossfuzz_libfwsi_call_utf8_string_getters(
	 file_entry,
	 &libfwsi_file_entry_get_utf8_name_size,
	 &libfwsi_file_entry_get_utf8_name );

	ossfuzz_libfwsi_call_utf16_string_getters(
	 file_entry,
	 &libfwsi_file_entry_get_utf16_name_size,
	 &libfwsi_file_entry_get_utf16_name );
}

/* Retrieves the values of a network location item
 */
static void ossfuzz_libfwsi_walk_network_location_item(
      libfwsi_item_t *network_location )
{
	ossfuzz_libfwsi_call_utf8_string_getters(
	 network_location,
	 &libfwsi_network_location_get_utf8_location_size,
	 &libfwsi_network_location_get_utf8_location );

	ossfuzz_libfwsi_call_utf16_string_getters(
	 network_location,
	 &libfwsi_network_location_get_utf16_location_size,
	 &libfwsi_network_location_get_utf16_location );

	ossfuzz_libfwsi_call_utf8_string_getters(
	 network_location,
	 &libfwsi_network_location_get_utf8_description_size,
	 &libfwsi_network_location_get_utf8_description );

	ossfuzz_libfwsi_call_utf16_string_getters(
	 network_location,
	 &libfwsi_network_location_get_utf16_description_size,
	 &libfwsi_network_location_get_utf16_description );

	ossfuzz_libfwsi_call_utf8_string_getters(
	 network_location,
	 &libfwsi_network_location_get_utf8_comments_size,
	 &libfwsi_network_location_get_utf8_comments );

	ossfuzz_libfwsi_call_utf16_string_getters(
	 network_location,
	 &libfwsi_network_location_get_utf16_comments_size,
	 &libfwsi_network_location_get_utf16_comments );
}

/* Retrieves the values of a compressed folder item
 */
static void ossfuzz_libfwsi_walk_compressed_folder_item(
      libfwsi_item_t *compressed_folder )
{
	ossfuzz_libfwsi_call_utf8_string_getters(
	 compressed_folder,
	 &libfwsi_compressed_folder_get_utf8_name_size,
	 &libfwsi_compressed_folder_get_utf8_name );

	ossfuzz_libfwsi_call_utf16_string_getters(
	 compressed_folder,
	 &libfwsi_compressed_folder_get_utf16_name_size,
	 &libfwsi_compressed_folder_get_utf16_name );
}

/* Retrieves the values of a control panel item
 */
static void ossfuzz_libfwsi_walk_control_panel_item_item(
      libfwsi_item_t *control_panel_item )
{
	uint8_t identifier[ 16 ] = { 0 };

	libfwsi_control_panel_item_get_identifier(
	 control_panel_item,
	 identifier,
	 sizeof( identifier ),
	 NULL );
}

/* Retrieves the values of a control panel category item
 */
static void ossfuzz_libfwsi_walk_control_panel_category_item(
      libfwsi_item_t *control_panel_category )
{
	uint32_t identifier = 0;

	libfwsi_control_panel_category_get_identifier(
	 control_panel_category,
	 &identifier,
	 NULL );
}

/* Retrieves the values of a users property view item
 */
static void ossfuzz_libfwsi_walk_users_property_view_item(
      libfwsi_item_t *users_property_view )
{
	uint8_t *property_store_data   = NULL;
	uint8_t identifier[ 16 ]       = { 0 };
	size_t property_store_data_size = 0;

	libfwsi_users_property_view_get_known_folder_identifier(
	 users_property_view,
	 identifier,
	 sizeof( identifier ),
	 NULL );

	libfwsi_users_property_view_get_property_store_data_size(
	 users_property_view,
	 &property_store_data_size,
	 NULL );

	if( property_store_data_size > 0 )
	{
		property_store_data = (uint8_t *) malloc(
	                                 property_store_data_size );

		if( property_store_data != NULL )
		{
			libfwsi_users_property_view_copy_property_store_data(
			 users_property_view,
			 property_store_data,
			 property_store_data_size,
			 NULL );

			free(
			 property_store_data );

			property_store_data = NULL;
		}
	}
}

/* Retrieves the values of an item
 */
static void ossfuzz_libfwsi_walk_item(
      libfwsi_item_t *item )
{
	libfwsi_extension_block_t *extension_block = NULL;
	uint8_t identifier[ 16 ]        = { 0 };
	uint8_t class_type              = 0;
	uint32_t signature              = 0;
	size_t data_size                = 0;
	int type                        = 0;
	int number_of_extension_blocks  = 0;
	int extension_block_index       = 0;

	libfwsi_item_get_type(
	 item,
	 &type,
	 NULL );

	libfwsi_item_get_class_type(
	 item,
	 &class_type,
	 NULL );

	libfwsi_item_get_signature(
	 item,
	 &signature,
	 NULL );

	libfwsi_item_get_data_size(
	 item,
	 &data_size,
	 NULL );

	libfwsi_item_get_delegate_folder_identifier(
	 item,
	 identifier,
	 sizeof( identifier ),
	 NULL );

	libfwsi_item_get_number_of_extension_blocks(
	 item,
	 &number_of_extension_blocks,
	 NULL );

	for( extension_block_index = 0;
	     extension_block_index < number_of_extension_blocks;
	     extension_block_index++ )
	{
		if( libfwsi_item_get_extension_block(
		     item,
		     extension_block_index,
		     &extension_block,
		     NULL ) == 1 )
		{
			libfwsi_extension_block_get_signature(
			 extension_block,
			 &signature,
			 NULL );

			libfwsi_extension_block_get_data_size(
			 extension_block,
			 &data_size,
			 NULL );

			extension_block = NULL;
		}
	}
	ossfuzz_libfwsi_walk_compressed_folder_item(
	 item );

	ossfuzz_libfwsi_walk_control_panel_category_item(
	 item );

	ossfuzz_libfwsi_walk_control_panel_item_item(
	 item );

	ossfuzz_libfwsi_walk_file_entry_item(
	 item );

	ossfuzz_libfwsi_walk_network_location_item(
	 item );

	ossfuzz_libfwsi_walk_root_folder_item(
	 item );

	ossfuzz_libfwsi_walk_users_property_view_item(
	 item );

	ossfuzz_libfwsi_walk_volume_item(
	 item );
}

extern "C" {

int LLVMFuzzerTestOneInput(
      const uint8_t *data,
      size_t size )
{
	libfwsi_item_t *item = NULL;

	if( libfwsi_item_initialize(
	     &item,
	     NULL ) != 1 )
	{
		return( 0 );
	}
	if( libfwsi_item_copy_from_byte_stream(
	     item,
	     data,
	     size,
	     ossfuzz_libfwsi_get_codepage(
		data,
		size ),
	     NULL ) == 1 )
	{
		ossfuzz_libfwsi_walk_item(
		 item );
	}
	libfwsi_item_free(
	 &item,
	 NULL );

	return( 0 );
}

} /* extern "C" */
