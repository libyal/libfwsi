/*
 * Library network_location type test program
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

#include <common.h>
#include <file_stream.h>
#include <memory.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fwsi_test_libcerror.h"
#include "fwsi_test_libfwsi.h"
#include "fwsi_test_macros.h"
#include "fwsi_test_memory.h"
#include "fwsi_test_unused.h"

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
#include "../libfwsi/libfwsi_item.h"
#endif

/* Network location (0x42) with location="\\\\server", description="desc", comments="note" */
uint8_t fwsi_test_network_location_data1[ 26 ] = {
	0x1a, 0x00, 0x42, 0x00, 0xc0, 0x5c, 0x5c, 0x73, 0x65, 0x72, 0x76, 0x65, 0x72, 0x00, 0x64, 0x65,
	0x73, 0x63, 0x00, 0x6e, 0x6f, 0x74, 0x65, 0x00, 0x00, 0x00 };

/* Network location (0x41) with location="\\\\server" only */
uint8_t fwsi_test_network_location_data2[ 16 ] = {
	0x10, 0x00, 0x41, 0x00, 0x00, 0x5c, 0x5c, 0x73, 0x65, 0x72, 0x76, 0x65, 0x72, 0x00, 0x00, 0x00 };

uint8_t fwsi_test_network_location_other_item_data1[ 20 ] = {
	0x14, 0x00, 0x1f, 0x50, 0xe0, 0x4f, 0xd0, 0x20, 0xea, 0x3a, 0x69, 0x10, 0xa2, 0xd8, 0x08, 0x00,
	0x2b, 0x30, 0x30, 0x9d };

/* Tests the libfwsi_network_location_get_utf8_location_size and related functions
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_network_location_get_location(
     libfwsi_item_t *network_location1,
     libfwsi_item_t *other_item )
{
	uint16_t expected_utf16[ 9 ] = { '\\', '\\', 's', 'e', 'r', 'v', 'e', 'r', 0 };
	uint16_t utf16_string[ 16 ];
	uint8_t utf8_string[ 16 ];

	libcerror_error_t *error     = NULL;
	size_t utf16_string_size     = 0;
	size_t utf8_string_size      = 0;
	int result                   = 0;

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
	libfwsi_item_t *empty_item   = NULL;
#endif

	/* Test regular cases
	 */
	result = libfwsi_network_location_get_utf8_location_size(
	          network_location1,
	          &utf8_string_size,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_EQUAL_SIZE( "utf8_string_size", utf8_string_size, (size_t) 9 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_network_location_get_utf8_location(
	          network_location1,
	          utf8_string,
	          16,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );
	FWSI_TEST_ASSERT_EQUAL_INT( "compare", memory_compare( utf8_string, "\\\\server", 9 ), 0 );

	result = libfwsi_network_location_get_utf16_location_size(
	          network_location1,
	          &utf16_string_size,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_EQUAL_SIZE( "utf16_string_size", utf16_string_size, (size_t) 9 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_network_location_get_utf16_location(
	          network_location1,
	          utf16_string,
	          16,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );
	FWSI_TEST_ASSERT_EQUAL_INT( "compare", memory_compare( utf16_string, expected_utf16, sizeof( uint16_t ) * 9 ), 0 );

	/* Test error cases: NULL item, wrong type, NULL output, buffer too small
	 */
	result = libfwsi_network_location_get_utf8_location_size( NULL, &utf8_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf8_location_size( other_item, &utf8_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf8_location_size( network_location1, NULL, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf8_location( NULL, utf8_string, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf8_location( other_item, utf8_string, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf8_location( network_location1, NULL, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf8_location( network_location1, utf8_string, 2, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf16_location_size( NULL, &utf16_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf16_location_size( other_item, &utf16_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf16_location_size( network_location1, NULL, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf16_location( NULL, utf16_string, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf16_location( other_item, utf16_string, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf16_location( network_location1, NULL, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf16_location( network_location1, utf16_string, 2, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
	result = libfwsi_item_initialize( &empty_item, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	( (libfwsi_internal_item_t *) empty_item )->type = LIBFWSI_ITEM_TYPE_NETWORK_LOCATION;

	result = libfwsi_network_location_get_utf8_location_size( empty_item, &utf8_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf8_location( empty_item, utf8_string, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf16_location_size( empty_item, &utf16_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf16_location( empty_item, utf16_string, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_item_free( &empty_item, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
#endif /* defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free( &error );
	}
#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
	if( empty_item != NULL )
	{
		libfwsi_item_free( &empty_item, NULL );
	}
#endif
	return( 0 );
}

/* Tests the libfwsi_network_location_get_*_description* functions
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_network_location_get_description(
     libfwsi_item_t *network_location1,
     libfwsi_item_t *network_location2,
     libfwsi_item_t *other_item )
{
	uint16_t expected_utf16[ 5 ] = { 'd', 'e', 's', 'c', 0 };
	uint16_t utf16_string[ 16 ];
	uint8_t utf8_string[ 16 ];

	libcerror_error_t *error     = NULL;
	size_t utf16_string_size     = 0;
	size_t utf8_string_size      = 0;
	int result                   = 0;

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
	libfwsi_item_t *empty_item   = NULL;
#endif

	/* Test regular cases (present and absent)
	 */
	result = libfwsi_network_location_get_utf8_description_size( network_location1, &utf8_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_EQUAL_SIZE( "utf8_string_size", utf8_string_size, (size_t) 5 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_network_location_get_utf8_description_size( network_location2, &utf8_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_network_location_get_utf8_description( network_location1, utf8_string, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );
	FWSI_TEST_ASSERT_EQUAL_INT( "compare", memory_compare( utf8_string, "desc", 5 ), 0 );

	result = libfwsi_network_location_get_utf8_description( network_location2, utf8_string, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_network_location_get_utf16_description_size( network_location1, &utf16_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_EQUAL_SIZE( "utf16_string_size", utf16_string_size, (size_t) 5 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_network_location_get_utf16_description_size( network_location2, &utf16_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_network_location_get_utf16_description( network_location1, utf16_string, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );
	FWSI_TEST_ASSERT_EQUAL_INT( "compare", memory_compare( utf16_string, expected_utf16, sizeof( uint16_t ) * 5 ), 0 );

	result = libfwsi_network_location_get_utf16_description( network_location2, utf16_string, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	/* Test error cases
	 */
	result = libfwsi_network_location_get_utf8_description_size( NULL, &utf8_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf8_description_size( other_item, &utf8_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf8_description_size( network_location1, NULL, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf8_description( NULL, utf8_string, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf8_description( other_item, utf8_string, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf8_description( network_location1, NULL, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf8_description( network_location1, utf8_string, 2, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf16_description_size( NULL, &utf16_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf16_description_size( other_item, &utf16_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf16_description_size( network_location1, NULL, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf16_description( NULL, utf16_string, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf16_description( other_item, utf16_string, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf16_description( network_location1, NULL, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf16_description( network_location1, utf16_string, 2, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
	result = libfwsi_item_initialize( &empty_item, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	( (libfwsi_internal_item_t *) empty_item )->type = LIBFWSI_ITEM_TYPE_NETWORK_LOCATION;

	result = libfwsi_network_location_get_utf8_description_size( empty_item, &utf8_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf8_description( empty_item, utf8_string, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf16_description_size( empty_item, &utf16_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf16_description( empty_item, utf16_string, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_item_free( &empty_item, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
#endif /* defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free( &error );
	}
#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
	if( empty_item != NULL )
	{
		libfwsi_item_free( &empty_item, NULL );
	}
#endif
	return( 0 );
}

/* Tests the libfwsi_network_location_get_*_comments* functions
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_network_location_get_comments(
     libfwsi_item_t *network_location1,
     libfwsi_item_t *network_location2,
     libfwsi_item_t *other_item )
{
	uint16_t expected_utf16[ 5 ] = { 'n', 'o', 't', 'e', 0 };
	uint16_t utf16_string[ 16 ];
	uint8_t utf8_string[ 16 ];

	libcerror_error_t *error     = NULL;
	size_t utf16_string_size     = 0;
	size_t utf8_string_size      = 0;
	int result                   = 0;

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
	libfwsi_item_t *empty_item   = NULL;
#endif

	/* Test regular cases (present and absent)
	 */
	result = libfwsi_network_location_get_utf8_comments_size( network_location1, &utf8_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_EQUAL_SIZE( "utf8_string_size", utf8_string_size, (size_t) 5 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_network_location_get_utf8_comments_size( network_location2, &utf8_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_network_location_get_utf8_comments( network_location1, utf8_string, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );
	FWSI_TEST_ASSERT_EQUAL_INT( "compare", memory_compare( utf8_string, "note", 5 ), 0 );

	result = libfwsi_network_location_get_utf8_comments( network_location2, utf8_string, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_network_location_get_utf16_comments_size( network_location1, &utf16_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_EQUAL_SIZE( "utf16_string_size", utf16_string_size, (size_t) 5 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_network_location_get_utf16_comments_size( network_location2, &utf16_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_network_location_get_utf16_comments( network_location1, utf16_string, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );
	FWSI_TEST_ASSERT_EQUAL_INT( "compare", memory_compare( utf16_string, expected_utf16, sizeof( uint16_t ) * 5 ), 0 );

	result = libfwsi_network_location_get_utf16_comments( network_location2, utf16_string, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	/* Test error cases
	 */
	result = libfwsi_network_location_get_utf8_comments_size( NULL, &utf8_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf8_comments_size( other_item, &utf8_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf8_comments_size( network_location1, NULL, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf8_comments( NULL, utf8_string, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf8_comments( other_item, utf8_string, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf8_comments( network_location1, NULL, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf8_comments( network_location1, utf8_string, 2, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf16_comments_size( NULL, &utf16_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf16_comments_size( other_item, &utf16_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf16_comments_size( network_location1, NULL, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf16_comments( NULL, utf16_string, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf16_comments( other_item, utf16_string, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf16_comments( network_location1, NULL, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf16_comments( network_location1, utf16_string, 2, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
	result = libfwsi_item_initialize( &empty_item, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	( (libfwsi_internal_item_t *) empty_item )->type = LIBFWSI_ITEM_TYPE_NETWORK_LOCATION;

	result = libfwsi_network_location_get_utf8_comments_size( empty_item, &utf8_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf8_comments( empty_item, utf8_string, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf16_comments_size( empty_item, &utf16_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_network_location_get_utf16_comments( empty_item, utf16_string, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_item_free( &empty_item, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
#endif /* defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free( &error );
	}
#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
	if( empty_item != NULL )
	{
		libfwsi_item_free( &empty_item, NULL );
	}
#endif
	return( 0 );
}

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc FWSI_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] FWSI_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc FWSI_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] FWSI_TEST_ATTRIBUTE_UNUSED )
#endif
{
#if !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 )
	libcerror_error_t *error          = NULL;
	libfwsi_item_t *network_location1 = NULL;
	libfwsi_item_t *network_location2 = NULL;
	libfwsi_item_t *other_item        = NULL;
	int result                        = 0;
#endif

	FWSI_TEST_UNREFERENCED_PARAMETER( argc )
	FWSI_TEST_UNREFERENCED_PARAMETER( argv )

#if !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 )

	result = libfwsi_item_initialize( &network_location1, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

	result = libfwsi_item_copy_from_byte_stream(
	          network_location1,
	          fwsi_test_network_location_data1,
	          26,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

	result = libfwsi_item_initialize( &network_location2, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

	result = libfwsi_item_copy_from_byte_stream(
	          network_location2,
	          fwsi_test_network_location_data2,
	          16,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

	result = libfwsi_item_initialize( &other_item, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

	result = libfwsi_item_copy_from_byte_stream(
	          other_item,
	          fwsi_test_network_location_other_item_data1,
	          20,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

	FWSI_TEST_RUN_WITH_ARGS(
	 "libfwsi_network_location_get_location",
	 fwsi_test_network_location_get_location,
	 network_location1,
	 other_item );

	FWSI_TEST_RUN_WITH_ARGS(
	 "libfwsi_network_location_get_description",
	 fwsi_test_network_location_get_description,
	 network_location1,
	 network_location2,
	 other_item );

	FWSI_TEST_RUN_WITH_ARGS(
	 "libfwsi_network_location_get_comments",
	 fwsi_test_network_location_get_comments,
	 network_location1,
	 network_location2,
	 other_item );

	result = libfwsi_item_free( &other_item, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

	result = libfwsi_item_free( &network_location2, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

	result = libfwsi_item_free( &network_location1, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

#endif /* !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 ) */

	return( EXIT_SUCCESS );

on_error:
#if !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 )
	if( error != NULL )
	{
		libcerror_error_free( &error );
	}
	if( other_item != NULL )
	{
		libfwsi_item_free( &other_item, NULL );
	}
	if( network_location2 != NULL )
	{
		libfwsi_item_free( &network_location2, NULL );
	}
	if( network_location1 != NULL )
	{
		libfwsi_item_free( &network_location1, NULL );
	}
#endif
	return( EXIT_FAILURE );
}
