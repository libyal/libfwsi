/*
 * OSS-Fuzz target for libfwsi item list type
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

/* Retrieves the values of an item list
 */
static void ossfuzz_libfwsi_walk_item_list(
      libfwsi_item_list_t *item_list )
{
	libfwsi_item_t *item         = NULL;
	size_t data_size             = 0;
	int number_of_items          = 0;
	int item_index               = 0;

	libfwsi_item_list_get_data_size(
	 item_list,
	 &data_size,
	 NULL );

	libfwsi_item_list_get_number_of_items(
	 item_list,
	 &number_of_items,
	 NULL );

	for( item_index = 0;
	     item_index < number_of_items;
	     item_index++ )
	{
		if( libfwsi_item_list_get_item(
		     item_list,
		     item_index,
		     &item,
		     NULL ) == 1 )
		{
			item = NULL;
		}
	}
}

extern "C" {

int LLVMFuzzerTestOneInput(
      const uint8_t *data,
      size_t size )
{
	libfwsi_item_list_t *item_list = NULL;

	if( libfwsi_item_list_initialize(
	     &item_list,
	     NULL ) != 1 )
	{
		return( 0 );
	}
	if( libfwsi_item_list_copy_from_byte_stream(
	     item_list,
	     data,
	     size,
	     ossfuzz_libfwsi_get_codepage(
		data,
		size ),
	     NULL ) == 1 )
	{
		ossfuzz_libfwsi_walk_item_list(
		 item_list );
	}
	libfwsi_item_list_free(
	 &item_list,
	 NULL );

	return( 0 );
}

} /* extern "C" */
