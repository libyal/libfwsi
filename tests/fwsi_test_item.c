/*
 * Library item type test program
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

unsigned char fwsi_test_item_data1[ 120 ] = {
	0x78, 0x00, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0xae, 0x46, 0x24, 0xb1, 0x11, 0x00, 0x55, 0x73,
	0x65, 0x72, 0x73, 0x00, 0x64, 0x00, 0x09, 0x00, 0x04, 0x00, 0xef, 0xbe, 0x99, 0x46, 0xf2, 0x14,
	0xae, 0x46, 0x24, 0xb1, 0x2e, 0x00, 0x00, 0x00, 0x58, 0x57, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x13,
	0x29, 0x01, 0x55, 0x00, 0x73, 0x00, 0x65, 0x00, 0x72, 0x00, 0x73, 0x00, 0x00, 0x00, 0x40, 0x00,
	0x73, 0x00, 0x68, 0x00, 0x65, 0x00, 0x6c, 0x00, 0x6c, 0x00, 0x33, 0x00, 0x32, 0x00, 0x2e, 0x00,
	0x64, 0x00, 0x6c, 0x00, 0x6c, 0x00, 0x2c, 0x00, 0x2d, 0x00, 0x32, 0x00, 0x31, 0x00, 0x38, 0x00,
	0x31, 0x00, 0x33, 0x00, 0x00, 0x00, 0x14, 0x00 };

/* Tests the libfwsi_item_initialize function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_item_initialize(
     void )
{
	libcerror_error_t *error        = NULL;
	libfwsi_item_t *item            = NULL;
	int result                      = 0;

#if defined( HAVE_FWSI_TEST_MEMORY )
	int number_of_malloc_fail_tests = 1;
	int number_of_memset_fail_tests = 1;
	int test_number                 = 0;
#endif

	/* Test regular cases
	 */
	result = libfwsi_item_initialize(
	          &item,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "item",
	 item );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwsi_item_free(
	          &item,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "item",
	 item );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwsi_item_initialize(
	          NULL,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	item = (libfwsi_item_t *) 0x12345678UL;

	result = libfwsi_item_initialize(
	          &item,
	          &error );

	item = NULL;

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_FWSI_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libfwsi_item_initialize with malloc failing
		 */
		fwsi_test_malloc_attempts_before_fail = test_number;

		result = libfwsi_item_initialize(
		          &item,
		          &error );

		if( fwsi_test_malloc_attempts_before_fail != -1 )
		{
			fwsi_test_malloc_attempts_before_fail = -1;

			if( item != NULL )
			{
				libfwsi_item_free(
				 &item,
				 NULL );
			}
		}
		else
		{
			FWSI_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			FWSI_TEST_ASSERT_IS_NULL(
			 "item",
			 item );

			FWSI_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test libfwsi_item_initialize with memset failing
		 */
		fwsi_test_memset_attempts_before_fail = test_number;

		result = libfwsi_item_initialize(
		          &item,
		          &error );

		if( fwsi_test_memset_attempts_before_fail != -1 )
		{
			fwsi_test_memset_attempts_before_fail = -1;

			if( item != NULL )
			{
				libfwsi_item_free(
				 &item,
				 NULL );
			}
		}
		else
		{
			FWSI_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			FWSI_TEST_ASSERT_IS_NULL(
			 "item",
			 item );

			FWSI_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_FWSI_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( item != NULL )
	{
		libfwsi_item_free(
		 &item,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwsi_item_free function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_item_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfwsi_item_free(
	          NULL,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfwsi_item_copy_from_byte_stream function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_item_copy_from_byte_stream(
     void )
{
	libcerror_error_t *error = NULL;
	libfwsi_item_t *item     = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libfwsi_item_initialize(
	          &item,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "item",
	 item );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test to copy security identifier from byte stream
	 */
	result = libfwsi_item_copy_from_byte_stream(
	          item,
	          fwsi_test_item_data1,
	          120,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwsi_item_copy_from_byte_stream(
	          NULL,
	          fwsi_test_item_data1,
	          120,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfwsi_item_copy_from_byte_stream(
	          item,
	          NULL,
	          120,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfwsi_item_copy_from_byte_stream(
	          item,
	          fwsi_test_item_data1,
	          0,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfwsi_item_copy_from_byte_stream(
	          item,
	          fwsi_test_item_data1,
	          (size_t) SSIZE_MAX + 1,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfwsi_item_copy_from_byte_stream(
	          item,
	          fwsi_test_item_data1,
	          8,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfwsi_item_copy_from_byte_stream(
	          item,
	          fwsi_test_item_data1,
	          120,
	          (uint8_t) 'X',
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfwsi_item_free(
	          &item,
	          NULL );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "item",
	 item );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test additional item types, delegate folders, parent items, and extension blocks
	 */
	{
		uint8_t zero_item[ 2 ]        = { 0x00, 0x00 };
		uint8_t small_item[ 4 ]       = { 0x03, 0x00, 0x00, 0x00 };
		uint8_t unknown_item[ 8 ]     = { 0x08, 0x00, 0x99, 0x00, 0x00, 0x00, 0x00, 0x00 };
		uint8_t root_folder_item[ 20 ] = {
			0x14, 0x00, 0x1f, 0x50,
			0xe0, 0x4f, 0xd0, 0x20, 0xea, 0x3a, 0x69, 0x10,
			0xa2, 0xd8, 0x08, 0x00, 0x2b, 0x30, 0x30, 0x9d };
		uint8_t volume_item[ 25 ]     = {
			0x19, 0x00, 0x2f, 'C', ':', '\\', 0x00 };
		uint8_t net_loc_item[ 20 ]    = {
			0x14, 0x00, 0x47, 0x00, 0x02, 'E', 'n', 't', 'i', 'r', 'e', 0x00 };
		uint8_t uri_item[ 14 ]        = {
			0x0e, 0x00, 0x61, 0x00, 0x00, 0x00, 'h', 't', 't', 'p', 0x00, 0x00, 0x00, 0x00 };
		uint8_t cpl_item[ 32 ]        = {
			0x20, 0x00, 0x71, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10,
			0x00, 0x00 };
		uint8_t cpl_cat_item[ 12 ]    = {
			0x0c, 0x00, 0x00, 0x00, 0x84, 0x21, 0xde, 0x39, 0x05, 0x00, 0x00, 0x00 };
		uint8_t cpl_file_item[ 28 ]   = {
			0x1c, 0x00, 0x00, 0x00, 0x38, 0xff, 0xff, 0xff };
		uint8_t cdburn_item[ 16 ]     = {
			0x10, 0x00, 0x00, 0x00, 0x41, 0x75, 0x67, 0x4d };
		uint8_t game_item[ 28 ]       = {
			0x1c, 0x00, 0x00, 0x00, 0x47, 0x46, 0x53, 0x49 };
		uint8_t web_site_item[ 16 ]   = {
			0x10, 0x00, 0x00, 0x00, 0x00, 0xb0, 0x01, 0xc0 };
		uint8_t mtp_fe_item[ 10 ]     = {
			0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x20, 0x19, 0x07 };
		uint8_t mtp_vol_item[ 10 ]    = {
			0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x20, 0x31, 0x10 };
		uint8_t upv_item[ 32 ]        = {
			0x20, 0x00, 0x00, 0x00, 0x1a, 0x00, 0xee, 0xbb, 0xfe, 0x23, 0x00, 0x00, 0x10, 0x00,
			0x71, 0xd5, 0xd8, 0x4b, 0x19, 0x6d, 0xd3, 0x48, 0xbe, 0x97, 0x42, 0x22, 0x20, 0x08, 0x0e, 0x43,
			0x00, 0x00 };
		uint8_t acronis_item[ 50 ]    = {
			0x32, 0x00, 0x52, 0x67, 0xb1, 0xac };
		uint8_t bad_fe_item[ 14 ]     = {
			0x0e, 0x00, 0x32, 0x00 };
		uint8_t cf1_item[ 80 ];
		uint8_t cf2_item[ 88 ];
		uint8_t cf3_item[ 88 ];
		uint8_t ext_term_item[ 28 ];
		uint8_t ext_nonbeef_item[ 32 ];
		uint8_t ext_bad_item[ 32 ];
		const uint8_t *valid_items[ 17 ];
		size_t valid_sizes[ 17 ];
		int item_index                = 0;

		memory_set( cf1_item, 0, sizeof( cf1_item ) );
		cf1_item[ 0 ] = 80;
		cf1_item[ 28 ] = '/'; cf1_item[ 34 ] = '/';
		cf1_item[ 40 ] = ' '; cf1_item[ 42 ] = ' '; cf1_item[ 48 ] = ':';
		cf1_item[ 60 ] = 4;
		cf1_item[ 68 ] = 't'; cf1_item[ 70 ] = 'e'; cf1_item[ 72 ] = 's'; cf1_item[ 74 ] = 't';

		memory_set( cf2_item, 0, sizeof( cf2_item ) );
		cf2_item[ 0 ] = 88;
		cf2_item[ 36 ] = 'N'; cf2_item[ 38 ] = '/'; cf2_item[ 40 ] = 'A';
		cf2_item[ 78 ] = 'b'; cf2_item[ 80 ] = 0;

		memory_set( cf3_item, 0, sizeof( cf3_item ) );
		cf3_item[ 0 ] = 88;
		cf3_item[ 40 ] = '/'; cf3_item[ 46 ] = '/';
		cf3_item[ 56 ] = ' '; cf3_item[ 58 ] = ' ';
		cf3_item[ 64 ] = ':'; cf3_item[ 70 ] = ':';
		cf3_item[ 78 ] = 'c'; cf3_item[ 80 ] = 0;

		/* Extension block loop: terminator (size 0 -> data_size 2)
		 */
		memory_set( ext_term_item, 0, sizeof( ext_term_item ) );
		ext_term_item[ 0 ]  = 28;
		ext_term_item[ 2 ]  = 0x1f;
		ext_term_item[ 26 ] = 20;

		/* Extension block loop: non-beef signature (result == 0 -> break)
		 */
		memory_set( ext_nonbeef_item, 0, sizeof( ext_nonbeef_item ) );
		ext_nonbeef_item[ 0 ]  = 32;
		ext_nonbeef_item[ 2 ]  = 0x1f;
		ext_nonbeef_item[ 20 ] = 10;
		ext_nonbeef_item[ 30 ] = 20;

		/* Extension block loop: OOB size (result == -1 -> error)
		 */
		memory_set( ext_bad_item, 0, sizeof( ext_bad_item ) );
		ext_bad_item[ 0 ]  = 32;
		ext_bad_item[ 2 ]  = 0x1f;
		ext_bad_item[ 20 ] = 40;
		ext_bad_item[ 24 ] = 0x04;
		ext_bad_item[ 26 ] = 0xef;
		ext_bad_item[ 27 ] = 0xbe;
		ext_bad_item[ 30 ] = 20;

		valid_items[ 0 ]  = zero_item;        valid_sizes[ 0 ]  = 2;
		valid_items[ 1 ]  = unknown_item;     valid_sizes[ 1 ]  = 8;
		valid_items[ 2 ]  = root_folder_item; valid_sizes[ 2 ]  = 20;
		valid_items[ 3 ]  = volume_item;      valid_sizes[ 3 ]  = 25;
		valid_items[ 4 ]  = net_loc_item;     valid_sizes[ 4 ]  = 20;
		valid_items[ 5 ]  = uri_item;         valid_sizes[ 5 ]  = 14;
		valid_items[ 6 ]  = cpl_item;         valid_sizes[ 6 ]  = 32;
		valid_items[ 7 ]  = cpl_cat_item;     valid_sizes[ 7 ]  = 12;
		valid_items[ 8 ]  = cpl_file_item;    valid_sizes[ 8 ]  = 28;
		valid_items[ 9 ]  = cdburn_item;      valid_sizes[ 9 ]  = 16;
		valid_items[ 10 ] = game_item;        valid_sizes[ 10 ] = 28;
		valid_items[ 11 ] = web_site_item;    valid_sizes[ 11 ] = 16;
		valid_items[ 12 ] = mtp_fe_item;      valid_sizes[ 12 ] = 10;
		valid_items[ 13 ] = mtp_vol_item;     valid_sizes[ 13 ] = 10;
		valid_items[ 14 ] = upv_item;         valid_sizes[ 14 ] = 32;
		valid_items[ 15 ] = cf1_item;         valid_sizes[ 15 ] = 80;
		valid_items[ 16 ] = cf2_item;         valid_sizes[ 16 ] = 88;

		for( item_index = 0;
		     item_index < 17;
		     item_index++ )
		{
			result = libfwsi_item_initialize(
			          &item,
			          &error );
			FWSI_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			result = libfwsi_item_copy_from_byte_stream(
			          item,
			          valid_items[ item_index ],
			          valid_sizes[ item_index ],
			          LIBFWSI_CODEPAGE_WINDOWS_1252,
			          &error );
			FWSI_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );
			FWSI_TEST_ASSERT_IS_NULL(
			 "error",
			 error );

			result = libfwsi_item_free(
			          &item,
			          &error );
			FWSI_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );
		}
		/* Test cf3, ext_term_item, ext_nonbeef_item
		 */
		result = libfwsi_item_initialize( &item, &error );
		FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
		result = libfwsi_item_copy_from_byte_stream( item, cf3_item, 88, LIBFWSI_CODEPAGE_WINDOWS_1252, &error );
		FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
		result = libfwsi_item_free( &item, &error );
		FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

		result = libfwsi_item_initialize( &item, &error );
		FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
		result = libfwsi_item_copy_from_byte_stream( item, ext_term_item, 28, LIBFWSI_CODEPAGE_WINDOWS_1252, &error );
		FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
		result = libfwsi_item_free( &item, &error );
		FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

		result = libfwsi_item_initialize( &item, &error );
		FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
		result = libfwsi_item_copy_from_byte_stream( item, ext_nonbeef_item, 32, LIBFWSI_CODEPAGE_WINDOWS_1252, &error );
		FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
		result = libfwsi_item_free( &item, &error );
		FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

		/* Test error items: small_item (< 4), bad_fe_item, acronis_item, ext_bad_item
		 */
		result = libfwsi_item_initialize( &item, &error );
		FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
		result = libfwsi_item_copy_from_byte_stream( item, small_item, 4, LIBFWSI_CODEPAGE_WINDOWS_1252, &error );
		FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
		libcerror_error_free( &error );
		result = libfwsi_item_free( &item, &error );
		FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

		result = libfwsi_item_initialize( &item, &error );
		FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
		result = libfwsi_item_copy_from_byte_stream( item, bad_fe_item, 14, LIBFWSI_CODEPAGE_WINDOWS_1252, &error );
		FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
		libcerror_error_free( &error );
		result = libfwsi_item_free( &item, &error );
		FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

		result = libfwsi_item_initialize( &item, &error );
		FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
		result = libfwsi_item_copy_from_byte_stream( item, acronis_item, 50, LIBFWSI_CODEPAGE_WINDOWS_1252, &error );
		FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
		libcerror_error_free( &error );
		result = libfwsi_item_free( &item, &error );
		FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

		result = libfwsi_item_initialize( &item, &error );
		FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
		result = libfwsi_item_copy_from_byte_stream( item, ext_bad_item, 32, LIBFWSI_CODEPAGE_WINDOWS_1252, &error );
		FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
		libcerror_error_free( &error );
		result = libfwsi_item_free( &item, &error );
		FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
		{
			uint8_t delegate_class_guid[ 16 ] = {
				0x74, 0x1a, 0x59, 0x5e, 0x96, 0xdf, 0xd3, 0x48,
				0x8d, 0x67, 0x17, 0x33, 0xbc, 0xee, 0x28, 0xba };
			uint8_t search_folder_guid[ 16 ] = {
				0x67, 0x1b, 0x73, 0x04, 0x33, 0xd9, 0x0a, 0x45,
				0x90, 0xe6, 0x4a, 0xcd, 0x2e, 0x94, 0x08, 0xfe };
			uint8_t users_files_delegate_guid[ 16 ] = {
				0xc5, 0xcd, 0xfa, 0xdf, 0x9f, 0x67, 0x56, 0x41,
				0x89, 0x47, 0xc5, 0xc7, 0x6b, 0xc0, 0xb6, 0x7f };
			uint8_t removable_drives_guid[ 16 ] = {
				0x77, 0x2c, 0xfb, 0xf5, 0x2f, 0x0e, 0x16, 0x4a,
				0xa3, 0x81, 0x3e, 0x56, 0x0c, 0x68, 0xbc, 0x83 };
			uint8_t del_item[ 64 ];
			uint8_t guid_buf[ 16 ];
			libfwsi_item_t *parent_item            = NULL;
			libfwsi_item_t *retrieved_parent       = NULL;
			libfwsi_internal_item_t *internal_item = NULL;

			/* Test internal_item_initialize and free error cases
			 */
			result = libfwsi_internal_item_initialize( NULL, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
			libcerror_error_free( &error );

			internal_item = (libfwsi_internal_item_t *) 0x12345678UL;
			result = libfwsi_internal_item_initialize( &internal_item, &error );
			internal_item = NULL;
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
			libcerror_error_free( &error );

			result = libfwsi_internal_item_free( NULL, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
			libcerror_error_free( &error );

			/* Test parent_item getter/setter errors and valid parent handling
			 */
			result = libfwsi_item_set_parent_item( NULL, NULL, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
			libcerror_error_free( &error );

			result = libfwsi_item_get_parent_item( NULL, &retrieved_parent, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
			libcerror_error_free( &error );

			/* Child of URI -> URI_SUB_VALUES
			 */
			result = libfwsi_item_initialize( &parent_item, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
			result = libfwsi_item_copy_from_byte_stream( parent_item, uri_item, 14, LIBFWSI_CODEPAGE_WINDOWS_1252, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

			result = libfwsi_item_get_parent_item( parent_item, NULL, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
			libcerror_error_free( &error );

			result = libfwsi_item_initialize( &item, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
			result = libfwsi_item_set_parent_item( item, parent_item, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
			result = libfwsi_item_copy_from_byte_stream( item, unknown_item, 8, LIBFWSI_CODEPAGE_WINDOWS_1252, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
			result = libfwsi_item_free( &item, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
			result = libfwsi_item_free( &parent_item, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

			/* Child of COMPRESSED_FOLDER -> COMPRESSED_FOLDER
			 */
			result = libfwsi_item_initialize( &parent_item, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
			result = libfwsi_item_copy_from_byte_stream( parent_item, cf1_item, 80, LIBFWSI_CODEPAGE_WINDOWS_1252, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

			result = libfwsi_item_initialize( &item, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
			result = libfwsi_item_set_parent_item( item, parent_item, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
			result = libfwsi_item_copy_from_byte_stream( item, cf1_item, 80, LIBFWSI_CODEPAGE_WINDOWS_1252, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
			result = libfwsi_item_free( &item, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
			result = libfwsi_item_free( &parent_item, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

			/* Generic delegate folder item (size 58: 6 header + 20 inner + 16 delegate class + 16 folder guid)
			 */
			memory_set( del_item, 0, sizeof( del_item ) );
			del_item[ 0 ] = 58;
			del_item[ 2 ] = 0x74;
			del_item[ 4 ] = 20;
			memory_copy( &( del_item[ 6 ] ), root_folder_item, 20 );
			memory_copy( &( del_item[ 26 ] ), delegate_class_guid, 16 );
			del_item[ 42 ] = 0x01;

			result = libfwsi_item_initialize( &item, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
			result = libfwsi_item_copy_from_byte_stream( item, del_item, 58, LIBFWSI_CODEPAGE_WINDOWS_1252, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

			result = libfwsi_item_get_delegate_folder_identifier( item, guid_buf, 16, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

			result = libfwsi_item_free( &item, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

			/* Delegate folder with delegate_class_identifier_offset in last 2 bytes (62 bytes, offset = 58)
			 */
			del_item[ 0 ]  = 62;
			del_item[ 60 ] = 58;
			del_item[ 61 ] = 0;
			result = libfwsi_item_initialize( &item, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
			result = libfwsi_item_copy_from_byte_stream( item, del_item, 62, LIBFWSI_CODEPAGE_WINDOWS_1252, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
			result = libfwsi_item_free( &item, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

			/* Delegate folder: search_folder
			 */
			del_item[ 0 ] = 58;
			memory_copy( &( del_item[ 42 ] ), search_folder_guid, 16 );
			result = libfwsi_item_initialize( &item, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
			result = libfwsi_item_copy_from_byte_stream( item, del_item, 58, LIBFWSI_CODEPAGE_WINDOWS_1252, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
			result = libfwsi_item_free( &item, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

			/* Delegate folder: users_files_folder_delegate_folder (valid & inner_data_size < 4)
			 */
			memory_copy( &( del_item[ 42 ] ), users_files_delegate_guid, 16 );
			result = libfwsi_item_initialize( &item, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
			result = libfwsi_item_copy_from_byte_stream( item, del_item, 58, LIBFWSI_CODEPAGE_WINDOWS_1252, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
			result = libfwsi_item_free( &item, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

			del_item[ 4 ] = 2;
			result = libfwsi_item_initialize( &item, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
			result = libfwsi_item_copy_from_byte_stream( item, del_item, 58, LIBFWSI_CODEPAGE_WINDOWS_1252, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
			libcerror_error_free( &error );
			result = libfwsi_item_free( &item, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

			/* Delegate folder: removable_drives (valid & inner_data_size < 4)
			 */
			del_item[ 4 ] = 20;
			memory_copy( &( del_item[ 42 ] ), removable_drives_guid, 16 );
			result = libfwsi_item_initialize( &item, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
			result = libfwsi_item_copy_from_byte_stream( item, del_item, 58, LIBFWSI_CODEPAGE_WINDOWS_1252, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
			result = libfwsi_item_free( &item, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

			del_item[ 4 ] = 2;
			result = libfwsi_item_initialize( &item, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
			result = libfwsi_item_copy_from_byte_stream( item, del_item, 58, LIBFWSI_CODEPAGE_WINDOWS_1252, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
			libcerror_error_free( &error );
			result = libfwsi_item_free( &item, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

			/* Delegate folder: inner_data_size OOB -> delegate_folder_values_read_data error
			 */
			del_item[ 4 ] = 50;
			result = libfwsi_item_initialize( &item, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
			result = libfwsi_item_copy_from_byte_stream( item, del_item, 58, LIBFWSI_CODEPAGE_WINDOWS_1252, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
			libcerror_error_free( &error );
			result = libfwsi_item_free( &item, &error );
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
		}
#endif /* defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT ) */
	}
	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( item != NULL )
	{
		libfwsi_item_free(
		 &item,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwsi_item_get_type function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_item_get_type(
     libfwsi_item_t *item )
{
	libcerror_error_t *error = NULL;
	int result               = 0;
	int type                 = 0;

	/* Test regular cases
	 */
	result = libfwsi_item_get_type(
	          item,
	          &type,
	          &error );

	FWSI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwsi_item_get_type(
	          NULL,
	          &type,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfwsi_item_get_type(
	          item,
	          NULL,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfwsi_item_get_class_type function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_item_get_class_type(
     libfwsi_item_t *item )
{
	libcerror_error_t *error = NULL;
	uint8_t class_type       = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfwsi_item_get_class_type(
	          item,
	          &class_type,
	          &error );

	FWSI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwsi_item_get_class_type(
	          NULL,
	          &class_type,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfwsi_item_get_class_type(
	          item,
	          NULL,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfwsi_item_get_signature function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_item_get_signature(
     libfwsi_item_t *item )
{
	libcerror_error_t *error = NULL;
	uint32_t signature       = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfwsi_item_get_signature(
	          item,
	          &signature,
	          &error );

	FWSI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwsi_item_get_signature(
	          NULL,
	          &signature,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfwsi_item_get_signature(
	          item,
	          NULL,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfwsi_item_get_data_size function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_item_get_data_size(
     libfwsi_item_t *item )
{
	libcerror_error_t *error = NULL;
	size_t data_size         = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfwsi_item_get_data_size(
	          item,
	          &data_size,
	          &error );

	FWSI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwsi_item_get_data_size(
	          NULL,
	          &data_size,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfwsi_item_get_data_size(
	          item,
	          NULL,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfwsi_item_get_number_of_extension_blocks function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_item_get_number_of_extension_blocks(
     libfwsi_item_t *item )
{
	libcerror_error_t *error       = NULL;
	int number_of_extension_blocks = 0;
	int result                     = 0;

	/* Test regular cases
	 */
	result = libfwsi_item_get_number_of_extension_blocks(
	          item,
	          &number_of_extension_blocks,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwsi_item_get_number_of_extension_blocks(
	          NULL,
	          &number_of_extension_blocks,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfwsi_item_get_number_of_extension_blocks(
	          item,
	          NULL,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfwsi_item_get_delegate_folder_identifier function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_item_get_delegate_folder_identifier(
     libfwsi_item_t *item )
{
	uint8_t guid_data[ 16 ];

	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases (not a delegate folder -> 0)
	 */
	result = libfwsi_item_get_delegate_folder_identifier(
	          item,
	          guid_data,
	          16,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwsi_item_get_delegate_folder_identifier(
	          NULL,
	          guid_data,
	          16,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfwsi_item_get_delegate_folder_identifier(
	          item,
	          NULL,
	          16,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfwsi_item_get_delegate_folder_identifier(
	          item,
	          guid_data,
	          8,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfwsi_item_get_extension_block function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_item_get_extension_block(
     libfwsi_item_t *item )
{
	libcerror_error_t *error                   = NULL;
	libfwsi_extension_block_t *extension_block = NULL;
	int result                                 = 0;

	/* Test regular cases
	 */
	result = libfwsi_item_get_extension_block(
	          item,
	          0,
	          &extension_block,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "extension_block",
	 extension_block );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwsi_extension_block_free(
	          &extension_block,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "extension_block",
	 extension_block );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwsi_item_get_extension_block(
	          NULL,
	          0,
	          &extension_block,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfwsi_item_get_extension_block(
	          item,
	          -1,
	          &extension_block,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfwsi_item_get_extension_block(
	          item,
	          999,
	          &extension_block,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfwsi_item_get_extension_block(
	          item,
	          0,
	          NULL,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( extension_block != NULL )
	{
		libfwsi_extension_block_free(
		 &extension_block,
		 NULL );
	}
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
	libcerror_error_t *error = NULL;
	libfwsi_item_t *item     = NULL;
	int result               = 0;
#endif

	FWSI_TEST_UNREFERENCED_PARAMETER( argc )
	FWSI_TEST_UNREFERENCED_PARAMETER( argv )

	FWSI_TEST_RUN(
	 "libfwsi_item_initialize",
	 fwsi_test_item_initialize );

	FWSI_TEST_RUN(
	 "libfwsi_item_free",
	 fwsi_test_item_free );

	FWSI_TEST_RUN(
	 "libfwsi_item_copy_from_byte_stream",
	 fwsi_test_item_copy_from_byte_stream );

#if !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 )

	/* Initialize item for tests
	 */
	result = libfwsi_item_initialize(
	          &item,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "item",
	 item );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwsi_item_copy_from_byte_stream(
	          item,
	          fwsi_test_item_data1,
	          120,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	FWSI_TEST_RUN_WITH_ARGS(
	 "libfwsi_item_get_type",
	 fwsi_test_item_get_type,
	 item );

	FWSI_TEST_RUN_WITH_ARGS(
	 "libfwsi_item_get_class_type",
	 fwsi_test_item_get_class_type,
	 item );

	FWSI_TEST_RUN_WITH_ARGS(
	 "libfwsi_item_get_signature",
	 fwsi_test_item_get_signature,
	 item );

	FWSI_TEST_RUN_WITH_ARGS(
	 "libfwsi_item_get_data_size",
	 fwsi_test_item_get_data_size,
	 item );

	FWSI_TEST_RUN_WITH_ARGS(
	 "libfwsi_item_get_number_of_extension_blocks",
	 fwsi_test_item_get_number_of_extension_blocks,
	 item );

	FWSI_TEST_RUN_WITH_ARGS(
	 "libfwsi_item_get_delegate_folder_identifier",
	 fwsi_test_item_get_delegate_folder_identifier,
	 item );

	FWSI_TEST_RUN_WITH_ARGS(
	 "libfwsi_item_get_extension_block",
	 fwsi_test_item_get_extension_block,
	 item );

	/* Clean up
	 */
	result = libfwsi_item_free(
	          &item,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "item",
	 item );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

#endif /* !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 ) */

	return( EXIT_SUCCESS );

on_error:
#if !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 )

	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( item != NULL )
	{
		libfwsi_item_free(
		 &item,
		 NULL );
	}
#endif /* !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 ) */

	return( EXIT_FAILURE );
}

