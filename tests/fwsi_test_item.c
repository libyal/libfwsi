/*
 * Library item type test program
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

	/* TODO: add tests for libfwsi_item_get_extension_block */

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

