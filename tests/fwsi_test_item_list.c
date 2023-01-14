/*
 * Library item_list type test program
 *
 * Copyright (C) 2010-2023, Joachim Metz <joachim.metz@gmail.com>
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
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fwsi_test_libcerror.h"
#include "fwsi_test_libfwsi.h"
#include "fwsi_test_macros.h"
#include "fwsi_test_memory.h"
#include "fwsi_test_unused.h"

unsigned char fwsi_test_item_list_data1[ 345 ] = {
	0x57, 0x01, 0x14, 0x00, 0x1f, 0x50, 0xe0, 0x4f, 0xd0, 0x20, 0xea, 0x3a, 0x69, 0x10, 0xa2, 0xd8,
	0x08, 0x00, 0x2b, 0x30, 0x30, 0x9d, 0x19, 0x00, 0x2f, 0x43, 0x3a, 0x5c, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78,
	0x00, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0xae, 0x46, 0x24, 0xb1, 0x11, 0x00, 0x55, 0x73, 0x65,
	0x72, 0x73, 0x00, 0x64, 0x00, 0x09, 0x00, 0x04, 0x00, 0xef, 0xbe, 0x99, 0x46, 0xf2, 0x14, 0xae,
	0x46, 0x24, 0xb1, 0x2e, 0x00, 0x00, 0x00, 0x58, 0x57, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x13, 0x29,
	0x01, 0x55, 0x00, 0x73, 0x00, 0x65, 0x00, 0x72, 0x00, 0x73, 0x00, 0x00, 0x00, 0x40, 0x00, 0x73,
	0x00, 0x68, 0x00, 0x65, 0x00, 0x6c, 0x00, 0x6c, 0x00, 0x33, 0x00, 0x32, 0x00, 0x2e, 0x00, 0x64,
	0x00, 0x6c, 0x00, 0x6c, 0x00, 0x2c, 0x00, 0x2d, 0x00, 0x32, 0x00, 0x31, 0x00, 0x38, 0x00, 0x31,
	0x00, 0x33, 0x00, 0x00, 0x00, 0x14, 0x00, 0x4e, 0x00, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0xae,
	0x46, 0x8c, 0xb1, 0x10, 0x00, 0x74, 0x65, 0x73, 0x74, 0x00, 0x00, 0x3a, 0x00, 0x09, 0x00, 0x04,
	0x00, 0xef, 0xbe, 0xae, 0x46, 0x24, 0xb1, 0xae, 0x46, 0x8c, 0xb1, 0x2e, 0x00, 0x00, 0x00, 0x08,
	0x9d, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x47, 0x8d, 0x00, 0x74, 0x00, 0x65, 0x00, 0x73, 0x00, 0x74,
	0x00, 0x00, 0x00, 0x14, 0x00, 0x62, 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0xae, 0x46, 0x4e,
	0xb2, 0x20, 0x00, 0x43, 0x4f, 0x50, 0x59, 0x49, 0x4e, 0x47, 0x2e, 0x74, 0x78, 0x74, 0x00, 0x48,
	0x00, 0x09, 0x00, 0x04, 0x00, 0xef, 0xbe, 0xae, 0x46, 0x4e, 0xb2, 0xae, 0x46, 0x4e, 0xb2, 0x2e,
	0x00, 0x00, 0x00, 0xa4, 0x9c, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb2, 0x62, 0xd7, 0x00, 0x43, 0x00, 0x4f,
	0x00, 0x50, 0x00, 0x59, 0x00, 0x49, 0x00, 0x4e, 0x00, 0x47, 0x00, 0x2e, 0x00, 0x74, 0x00, 0x78,
	0x00, 0x74, 0x00, 0x00, 0x00, 0x1a, 0x00, 0x00, 0x00 };

/* Tests the libfwsi_item_list_initialize function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_item_list_initialize(
     void )
{
	libcerror_error_t *error        = NULL;
	libfwsi_item_list_t *item_list  = NULL;
	int result                      = 0;

#if defined( HAVE_FWSI_TEST_MEMORY )
	int number_of_malloc_fail_tests = 1;
	int number_of_memset_fail_tests = 1;
	int test_number                 = 0;
#endif

	/* Test regular cases
	 */
	result = libfwsi_item_list_initialize(
	          &item_list,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "item_list",
	 item_list );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwsi_item_list_free(
	          &item_list,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "item_list",
	 item_list );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwsi_item_list_initialize(
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

	item_list = (libfwsi_item_list_t *) 0x12345678UL;

	result = libfwsi_item_list_initialize(
	          &item_list,
	          &error );

	item_list = NULL;

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
		/* Test libfwsi_item_list_initialize with malloc failing
		 */
		fwsi_test_malloc_attempts_before_fail = test_number;

		result = libfwsi_item_list_initialize(
		          &item_list,
		          &error );

		if( fwsi_test_malloc_attempts_before_fail != -1 )
		{
			fwsi_test_malloc_attempts_before_fail = -1;

			if( item_list != NULL )
			{
				libfwsi_item_list_free(
				 &item_list,
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
			 "item_list",
			 item_list );

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
		/* Test libfwsi_item_list_initialize with memset failing
		 */
		fwsi_test_memset_attempts_before_fail = test_number;

		result = libfwsi_item_list_initialize(
		          &item_list,
		          &error );

		if( fwsi_test_memset_attempts_before_fail != -1 )
		{
			fwsi_test_memset_attempts_before_fail = -1;

			if( item_list != NULL )
			{
				libfwsi_item_list_free(
				 &item_list,
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
			 "item_list",
			 item_list );

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
	if( item_list != NULL )
	{
		libfwsi_item_list_free(
		 &item_list,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwsi_item_list_free function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_item_list_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfwsi_item_list_free(
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

/* Tests the libfwsi_item_list_copy_from_byte_stream function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_item_list_copy_from_byte_stream(
     void )
{
	libcerror_error_t *error       = NULL;
	libfwsi_item_list_t *item_list = NULL;
	int result                     = 0;

	/* Initialize test
	 */
	result = libfwsi_item_list_initialize(
	          &item_list,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "item_list",
	 item_list );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test to copy security identifier from byte stream
	 */
	result = libfwsi_item_list_copy_from_byte_stream(
	          item_list,
	          fwsi_test_item_list_data1,
	          345,
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
	result = libfwsi_item_list_copy_from_byte_stream(
	          NULL,
	          fwsi_test_item_list_data1,
	          345,
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

	result = libfwsi_item_list_copy_from_byte_stream(
	          item_list,
	          NULL,
	          345,
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

	result = libfwsi_item_list_copy_from_byte_stream(
	          item_list,
	          fwsi_test_item_list_data1,
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

	result = libfwsi_item_list_copy_from_byte_stream(
	          item_list,
	          fwsi_test_item_list_data1,
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

	result = libfwsi_item_list_copy_from_byte_stream(
	          item_list,
	          fwsi_test_item_list_data1,
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

	result = libfwsi_item_list_copy_from_byte_stream(
	          item_list,
	          fwsi_test_item_list_data1,
	          345,
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
	result = libfwsi_item_list_free(
	          &item_list,
	          NULL );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "item_list",
	 item_list );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( item_list != NULL )
	{
		libfwsi_item_list_free(
		 &item_list,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwsi_item_list_get_data_size function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_item_list_get_data_size(
     libfwsi_item_list_t *item_list )
{
	libcerror_error_t *error = NULL;
	size_t data_size         = 0;
	int data_size_is_set     = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfwsi_item_list_get_data_size(
	          item_list,
	          &data_size,
	          &error );

	FWSI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	data_size_is_set = result;

	/* Test error cases
	 */
	result = libfwsi_item_list_get_data_size(
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

	if( data_size_is_set != 0 )
	{
		result = libfwsi_item_list_get_data_size(
		          item_list,
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
	}
	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfwsi_item_list_get_number_of_items function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_item_list_get_number_of_items(
     libfwsi_item_list_t *item_list )
{
	libcerror_error_t *error = NULL;
	int number_of_items      = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfwsi_item_list_get_number_of_items(
	          item_list,
	          &number_of_items,
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
	result = libfwsi_item_list_get_number_of_items(
	          NULL,
	          &number_of_items,
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

	result = libfwsi_item_list_get_number_of_items(
	          item_list,
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
	libcerror_error_t *error       = NULL;
	libfwsi_item_list_t *item_list = NULL;
	int result                     = 0;

	FWSI_TEST_UNREFERENCED_PARAMETER( argc )
	FWSI_TEST_UNREFERENCED_PARAMETER( argv )

	FWSI_TEST_RUN(
	 "libfwsi_item_list_initialize",
	 fwsi_test_item_list_initialize );

	FWSI_TEST_RUN(
	 "libfwsi_item_list_free",
	 fwsi_test_item_list_free );

	FWSI_TEST_RUN(
	 "libfwsi_item_list_copy_from_byte_stream",
	 fwsi_test_item_list_copy_from_byte_stream );

#if !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 )

	/* Initialize item_list for tests
	 */
	result = libfwsi_item_list_initialize(
	          &item_list,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "item_list",
	 item_list );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwsi_item_list_copy_from_byte_stream(
	          item_list,
	          fwsi_test_item_list_data1,
	          345,
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
	 "libfwsi_item_list_get_data_size",
	 fwsi_test_item_list_get_data_size,
	 item_list );

	FWSI_TEST_RUN_WITH_ARGS(
	 "libfwsi_item_list_get_number_of_items",
	 fwsi_test_item_list_get_number_of_items,
	 item_list );

	/* TODO: add tests for libfwsi_item_list_get_item */

	/* Clean up
	 */
	result = libfwsi_item_list_free(
	          &item_list,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "item_list",
	 item_list );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

#endif /* !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 ) */

	return( EXIT_SUCCESS );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( item_list != NULL )
	{
		libfwsi_item_list_free(
		 &item_list,
		 NULL );
	}
	return( EXIT_FAILURE );
}

