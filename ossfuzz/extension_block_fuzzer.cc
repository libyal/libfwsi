/*
 * OSS-Fuzz target for libfwsi extension block type
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
#include <string.h>

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

typedef int (ossfuzz_libfwsi_extension_block_utf8_size_getter_t)(
      libfwsi_extension_block_t *extension_block,
      size_t *utf8_string_size,
      libfwsi_error_t **error );

typedef int (ossfuzz_libfwsi_extension_block_utf8_name_getter_t)(
      libfwsi_extension_block_t *extension_block,
      uint8_t *utf8_string,
      size_t utf8_string_size,
      libfwsi_error_t **error );

typedef int (ossfuzz_libfwsi_extension_block_utf16_size_getter_t)(
      libfwsi_extension_block_t *extension_block,
      size_t *utf16_string_size,
      libfwsi_error_t **error );

typedef int (ossfuzz_libfwsi_extension_block_utf16_name_getter_t)(
      libfwsi_extension_block_t *extension_block,
      uint16_t *utf16_string,
      size_t utf16_string_size,
      libfwsi_error_t **error );

/* Calls the extension block UTF-8 name getters
 */
static void ossfuzz_libfwsi_call_extension_block_utf8_string_getters(
      libfwsi_extension_block_t *extension_block,
      ossfuzz_libfwsi_extension_block_utf8_size_getter_t utf8_size_getter,
      ossfuzz_libfwsi_extension_block_utf8_name_getter_t utf8_name_getter )
{
	uint8_t *utf8_string = NULL;
	size_t utf8_size     = 0;

	if( utf8_size_getter(
	     extension_block,
	     &utf8_size,
	     NULL ) == 1 )
	{
		utf8_string = (uint8_t *) malloc(
	                        utf8_size );

		if( utf8_string != NULL )
		{
			utf8_name_getter(
			 extension_block,
			 utf8_string,
			 utf8_size,
			 NULL );

			free(
			 utf8_string );

			utf8_string = NULL;
		}
	}
}

/* Calls the extension block UTF-16 name getters
 */
static void ossfuzz_libfwsi_call_extension_block_utf16_string_getters(
      libfwsi_extension_block_t *extension_block,
      ossfuzz_libfwsi_extension_block_utf16_size_getter_t utf16_size_getter,
      ossfuzz_libfwsi_extension_block_utf16_name_getter_t utf16_name_getter )
{
	uint16_t *utf16_string = NULL;
	size_t utf16_size      = 0;

	if( utf16_size_getter(
	     extension_block,
	     &utf16_size,
	     NULL ) == 1 )
	{
		utf16_string = (uint16_t *) malloc(
	                         utf16_size * sizeof( uint16_t ) );

		if( utf16_string != NULL )
		{
			utf16_name_getter(
			 extension_block,
			 utf16_string,
			 utf16_size,
			 NULL );

			free(
			 utf16_string );

			utf16_string = NULL;
		}
	}
}

/* Retrieves the values of an extension block
 */
static void ossfuzz_libfwsi_walk_extension_block(
      libfwsi_extension_block_t *extension_block )
{
	uint32_t signature     = 0;
	uint32_t fat_date_time  = 0;
	uint64_t file_reference = 0;
	size_t data_size        = 0;

	libfwsi_extension_block_get_signature(
	 extension_block,
	 &signature,
	 NULL );

	if( ( signature >> 16 ) != 0xbeef )
	{
		return;
	}
	libfwsi_extension_block_get_data_size(
	 extension_block,
	 &data_size,
	 NULL );

	libfwsi_file_entry_extension_get_creation_time(
	 extension_block,
	 &fat_date_time,
	 NULL );

	libfwsi_file_entry_extension_get_access_time(
	 extension_block,
	 &fat_date_time,
	 NULL );

	libfwsi_file_entry_extension_get_file_reference(
	 extension_block,
	 &file_reference,
	 NULL );

	ossfuzz_libfwsi_call_extension_block_utf8_string_getters(
	 extension_block,
	 &libfwsi_file_entry_extension_get_utf8_long_name_size,
	 &libfwsi_file_entry_extension_get_utf8_long_name );

	ossfuzz_libfwsi_call_extension_block_utf16_string_getters(
	 extension_block,
	 &libfwsi_file_entry_extension_get_utf16_long_name_size,
	 &libfwsi_file_entry_extension_get_utf16_long_name );

	ossfuzz_libfwsi_call_extension_block_utf8_string_getters(
	 extension_block,
	 &libfwsi_file_entry_extension_get_utf8_localized_name_size,
	 &libfwsi_file_entry_extension_get_utf8_localized_name );

	ossfuzz_libfwsi_call_extension_block_utf16_string_getters(
	 extension_block,
	 &libfwsi_file_entry_extension_get_utf16_localized_name_size,
	 &libfwsi_file_entry_extension_get_utf16_localized_name );
}

/* Retrieves the values of the extension blocks of an item
 */
static void ossfuzz_libfwsi_walk_item_extension_blocks(
      libfwsi_item_t *item )
{
	libfwsi_extension_block_t *extension_block = NULL;
	int number_of_extension_blocks  = 0;
	int extension_block_index       = 0;

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
			ossfuzz_libfwsi_walk_extension_block(
			 extension_block );

			extension_block = NULL;
		}
	}
}

extern "C" {

int LLVMFuzzerTestOneInput(
      const uint8_t *data,
      size_t size )
{
	libfwsi_item_t *item        = NULL;
	uint8_t *shell_item_data    = NULL;
	size_t shell_item_data_size = 0;

	/* The shell item data size is stored in the first two bytes
	 * and therefore limited to 16-bit
	 */
	if( size > (size_t) 0xffe9 )
	{
		return( 0 );
	}
	shell_item_data_size = size + 6;

	shell_item_data = (uint8_t *) malloc(
	                      shell_item_data_size );

	if( shell_item_data == NULL )
	{
		return( 0 );
	}
	/* Wrap the extension block data into a minimal shell item
	 * consisting of the data size, an unused class type,
	 * the extension block data and the offset of the first
	 * extension block
	 */
	shell_item_data[ 0 ] = (uint8_t) ( size );
	shell_item_data[ 1 ] = (uint8_t) ( size >> 8 );
	shell_item_data[ 2 ] = 0;
	shell_item_data[ 3 ] = 0;
	memcpy(
	 &( shell_item_data[ 4 ] ),
	 data,
	 size );
	shell_item_data[ 4 + size ]     = 4;
	shell_item_data[ 4 + size + 1 ] = 0;

	if( libfwsi_item_initialize(
	     &item,
	     NULL ) != 1 )
	{
		free(
		 shell_item_data );

		return( 0 );
	}
	if( libfwsi_item_copy_from_byte_stream(
	     item,
	     shell_item_data,
	     shell_item_data_size,
	     ossfuzz_libfwsi_get_codepage(
		data,
		size ),
	     NULL ) == 1 )
	{
		ossfuzz_libfwsi_walk_item_extension_blocks(
		 item );
	}
	libfwsi_item_free(
	 &item,
	 NULL );

	free(
	 shell_item_data );

	return( 0 );
}

} /* extern "C" */
