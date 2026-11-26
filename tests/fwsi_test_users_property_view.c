/*
 * Library users_property_view type test program
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

/* Users property view with known folder identifier (0x23febbee) and 8-byte property store */
uint8_t fwsi_test_users_property_view_data1[ 40 ] = {
	0x28, 0x00, 0x00, 0x00, 0x20, 0x00, 0xee, 0xbb, 0xfe, 0x23, 0x08, 0x00, 0x10, 0x00, 0x11, 0x22,
	0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x01, 0xa1, 0xa2,
	0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0x00, 0x00 };

/* Users property view without known folder identifier (0x23a3dfd5) and empty property store */
uint8_t fwsi_test_users_property_view_data2[ 20 ] = {
	0x14, 0x00, 0x00, 0x00, 0x0c, 0x00, 0xd5, 0xdf, 0xa3, 0x23, 0x00, 0x00, 0x04, 0x00, 0x01, 0x02,
	0x03, 0x04, 0x00, 0x00 };

uint8_t fwsi_test_users_property_view_other_item_data1[ 20 ] = {
	0x14, 0x00, 0x1f, 0x50, 0xe0, 0x4f, 0xd0, 0x20, 0xea, 0x3a, 0x69, 0x10, 0xa2, 0xd8, 0x08, 0x00,
	0x2b, 0x30, 0x30, 0x9d };

/* Tests the libfwsi_users_property_view_get_known_folder_identifier function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_users_property_view_get_known_folder_identifier(
     libfwsi_item_t *users_property_view1,
     libfwsi_item_t *users_property_view2,
     libfwsi_item_t *other_item )
{
	uint8_t expected_guid_data[ 16 ] = {
		0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x01 };

	uint8_t guid_data[ 16 ];

	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfwsi_users_property_view_get_known_folder_identifier(
	          users_property_view1,
	          guid_data,
	          16,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          guid_data,
	          expected_guid_data,
	          16 );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	result = libfwsi_users_property_view_get_known_folder_identifier(
	          users_property_view2,
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
	result = libfwsi_users_property_view_get_known_folder_identifier(
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

	result = libfwsi_users_property_view_get_known_folder_identifier(
	          other_item,
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

	result = libfwsi_users_property_view_get_known_folder_identifier(
	          users_property_view1,
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

	result = libfwsi_users_property_view_get_known_folder_identifier(
	          users_property_view1,
	          guid_data,
	          15,
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

/* Tests the libfwsi_users_property_view_get_property_store_data_size function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_users_property_view_get_property_store_data_size(
     libfwsi_item_t *users_property_view1,
     libfwsi_item_t *other_item )
{
	libcerror_error_t *error = NULL;
	size_t data_size         = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfwsi_users_property_view_get_property_store_data_size(
	          users_property_view1,
	          &data_size,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_EQUAL_SIZE(
	 "data_size",
	 data_size,
	 (size_t) 8 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwsi_users_property_view_get_property_store_data_size(
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

	result = libfwsi_users_property_view_get_property_store_data_size(
	          other_item,
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

	result = libfwsi_users_property_view_get_property_store_data_size(
	          users_property_view1,
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

/* Tests the libfwsi_users_property_view_copy_property_store_data function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_users_property_view_copy_property_store_data(
     libfwsi_item_t *users_property_view1,
     libfwsi_item_t *other_item )
{
	uint8_t expected_data[ 8 ] = { 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8 };
	uint8_t data[ 8 ];

	libcerror_error_t *error   = NULL;
	int result                 = 0;

	/* Test regular cases
	 */
	result = libfwsi_users_property_view_copy_property_store_data(
	          users_property_view1,
	          data,
	          8,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = memory_compare(
	          data,
	          expected_data,
	          8 );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	result = libfwsi_users_property_view_copy_property_store_data(
	          NULL,
	          data,
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

	result = libfwsi_users_property_view_copy_property_store_data(
	          other_item,
	          data,
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

	result = libfwsi_users_property_view_copy_property_store_data(
	          users_property_view1,
	          NULL,
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

	result = libfwsi_users_property_view_copy_property_store_data(
	          users_property_view1,
	          data,
	          4,
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

	result = libfwsi_users_property_view_copy_property_store_data(
	          users_property_view1,
	          data,
	          (size_t) SSIZE_MAX + 1,
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

#if defined( HAVE_FWSI_TEST_MEMORY )
	fwsi_test_memcpy_attempts_before_fail = 0;

	result = libfwsi_users_property_view_copy_property_store_data(
	          users_property_view1,
	          data,
	          8,
	          &error );

	if( fwsi_test_memcpy_attempts_before_fail != -1 )
	{
		fwsi_test_memcpy_attempts_before_fail = -1;
	}
	else
	{
		FWSI_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FWSI_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_FWSI_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
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
	libcerror_error_t *error             = NULL;
	libfwsi_item_t *other_item           = NULL;
	libfwsi_item_t *users_property_view1 = NULL;
	libfwsi_item_t *users_property_view2 = NULL;
	int result                           = 0;
#endif

	FWSI_TEST_UNREFERENCED_PARAMETER( argc )
	FWSI_TEST_UNREFERENCED_PARAMETER( argv )

#if !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 )

	result = libfwsi_item_initialize(
	          &users_property_view1,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "users_property_view1",
	 users_property_view1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwsi_item_copy_from_byte_stream(
	          users_property_view1,
	          fwsi_test_users_property_view_data1,
	          40,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwsi_item_initialize(
	          &users_property_view2,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "users_property_view2",
	 users_property_view2 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwsi_item_copy_from_byte_stream(
	          users_property_view2,
	          fwsi_test_users_property_view_data2,
	          20,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwsi_item_initialize(
	          &other_item,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "other_item",
	 other_item );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwsi_item_copy_from_byte_stream(
	          other_item,
	          fwsi_test_users_property_view_other_item_data1,
	          20,
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
	 "libfwsi_users_property_view_get_known_folder_identifier",
	 fwsi_test_users_property_view_get_known_folder_identifier,
	 users_property_view1,
	 users_property_view2,
	 other_item );

	FWSI_TEST_RUN_WITH_ARGS(
	 "libfwsi_users_property_view_get_property_store_data_size",
	 fwsi_test_users_property_view_get_property_store_data_size,
	 users_property_view1,
	 other_item );

	FWSI_TEST_RUN_WITH_ARGS(
	 "libfwsi_users_property_view_copy_property_store_data",
	 fwsi_test_users_property_view_copy_property_store_data,
	 users_property_view1,
	 other_item );

	result = libfwsi_item_free(
	          &other_item,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "other_item",
	 other_item );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwsi_item_free(
	          &users_property_view2,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "users_property_view2",
	 users_property_view2 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwsi_item_free(
	          &users_property_view1,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "users_property_view1",
	 users_property_view1 );

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
	if( other_item != NULL )
	{
		libfwsi_item_free(
		 &other_item,
		 NULL );
	}
	if( users_property_view2 != NULL )
	{
		libfwsi_item_free(
		 &users_property_view2,
		 NULL );
	}
	if( users_property_view1 != NULL )
	{
		libfwsi_item_free(
		 &users_property_view1,
		 NULL );
	}
#endif
	return( EXIT_FAILURE );
}
