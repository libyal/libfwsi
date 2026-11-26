/*
 * Library uri_values type test program
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

#include "../libfwsi/libfwsi_uri_values.h"

uint8_t fwsi_test_uri_values_data1[ 390 ] = {
	0x86, 0x01, 0x61, 0x80, 0x00, 0x00, 0x00, 0x00, 0x68, 0x00, 0x74, 0x00, 0x74, 0x00, 0x70, 0x00,
	0x3a, 0x00, 0x2f, 0x00, 0x2f, 0x00, 0x67, 0x00, 0x6f, 0x00, 0x2e, 0x00, 0x6d, 0x00, 0x69, 0x00,
	0x63, 0x00, 0x72, 0x00, 0x6f, 0x00, 0x73, 0x00, 0x6f, 0x00, 0x66, 0x00, 0x74, 0x00, 0x2e, 0x00,
	0x63, 0x00, 0x6f, 0x00, 0x6d, 0x00, 0x2f, 0x00, 0x66, 0x00, 0x77, 0x00, 0x6c, 0x00, 0x69, 0x00,
	0x6e, 0x00, 0x6b, 0x00, 0x2f, 0x00, 0x3f, 0x00, 0x4c, 0x00, 0x69, 0x00, 0x6e, 0x00, 0x6b, 0x00,
	0x49, 0x00, 0x64, 0x00, 0x3d, 0x00, 0x36, 0x00, 0x38, 0x00, 0x31, 0x00, 0x39, 0x00, 0x39, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x22, 0x01, 0x00, 0x00, 0x14, 0x00, 0xef, 0xbe, 0x13, 0xce, 0x2f, 0xdf,
	0xec, 0x25, 0xbb, 0x45, 0x9d, 0x4c, 0xce, 0xcd, 0x47, 0xc2, 0x43, 0x0c, 0x0a, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84, 0x2b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
	0x5a, 0x00, 0x00, 0x00, 0x68, 0x00, 0x74, 0x00, 0x74, 0x00, 0x70, 0x00, 0x3a, 0x00, 0x2f, 0x00,
	0x2f, 0x00, 0x67, 0x00, 0x6f, 0x00, 0x2e, 0x00, 0x6d, 0x00, 0x69, 0x00, 0x63, 0x00, 0x72, 0x00,
	0x6f, 0x00, 0x73, 0x00, 0x6f, 0x00, 0x66, 0x00, 0x74, 0x00, 0x2e, 0x00, 0x63, 0x00, 0x6f, 0x00,
	0x6d, 0x00, 0x2f, 0x00, 0x66, 0x00, 0x77, 0x00, 0x6c, 0x00, 0x69, 0x00, 0x6e, 0x00, 0x6b, 0x00,
	0x2f, 0x00, 0x3f, 0x00, 0x4c, 0x00, 0x69, 0x00, 0x6e, 0x00, 0x6b, 0x00, 0x49, 0x00, 0x64, 0x00,
	0x3d, 0x00, 0x36, 0x00, 0x38, 0x00, 0x31, 0x00, 0x39, 0x00, 0x39, 0x00, 0x00, 0x00, 0x06, 0x00,
	0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x67, 0x00, 0x6f, 0x00, 0x2e, 0x00, 0x6d, 0x00, 0x69, 0x00,
	0x63, 0x00, 0x72, 0x00, 0x6f, 0x00, 0x73, 0x00, 0x6f, 0x00, 0x66, 0x00, 0x74, 0x00, 0x2e, 0x00,
	0x63, 0x00, 0x6f, 0x00, 0x6d, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00,
	0x2f, 0x00, 0x66, 0x00, 0x77, 0x00, 0x6c, 0x00, 0x69, 0x00, 0x6e, 0x00, 0x6b, 0x00, 0x2f, 0x00,
	0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x0a, 0x00,
	0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x4c, 0x00, 0x69, 0x00, 0x6e, 0x00, 0x6b, 0x00,
	0x49, 0x00, 0x64, 0x00, 0x3d, 0x00, 0x36, 0x00, 0x38, 0x00, 0x31, 0x00, 0x39, 0x00, 0x39, 0x00,
	0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x68, 0x00, 0x74, 0x00, 0x74, 0x00,
	0x70, 0x00, 0x00, 0x00, 0x64, 0x00 };

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )

/* Tests the libfwsi_uri_values_initialize function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_uri_values_initialize(
     void )
{
	libcerror_error_t *error         = NULL;
	libfwsi_uri_values_t *uri_values = NULL;
	int result                       = 0;

#if defined( HAVE_FWSI_TEST_MEMORY )
	int number_of_malloc_fail_tests  = 1;
	int number_of_memset_fail_tests  = 1;
	int test_number                  = 0;
#endif

	/* Test regular cases
	 */
	result = libfwsi_uri_values_initialize(
	          &uri_values,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "uri_values",
	 uri_values );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwsi_uri_values_free(
	          &uri_values,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "uri_values",
	 uri_values );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwsi_uri_values_initialize(
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

	uri_values = (libfwsi_uri_values_t *) 0x12345678UL;

	result = libfwsi_uri_values_initialize(
	          &uri_values,
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

	uri_values = NULL;

#if defined( HAVE_FWSI_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libfwsi_uri_values_initialize with malloc failing
		 */
		fwsi_test_malloc_attempts_before_fail = test_number;

		result = libfwsi_uri_values_initialize(
		          &uri_values,
		          &error );

		if( fwsi_test_malloc_attempts_before_fail != -1 )
		{
			fwsi_test_malloc_attempts_before_fail = -1;

			if( uri_values != NULL )
			{
				libfwsi_uri_values_free(
				 &uri_values,
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
			 "uri_values",
			 uri_values );

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
		/* Test libfwsi_uri_values_initialize with memset failing
		 */
		fwsi_test_memset_attempts_before_fail = test_number;

		result = libfwsi_uri_values_initialize(
		          &uri_values,
		          &error );

		if( fwsi_test_memset_attempts_before_fail != -1 )
		{
			fwsi_test_memset_attempts_before_fail = -1;

			if( uri_values != NULL )
			{
				libfwsi_uri_values_free(
				 &uri_values,
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
			 "uri_values",
			 uri_values );

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
	if( uri_values != NULL )
	{
		libfwsi_uri_values_free(
		 &uri_values,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwsi_uri_values_free function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_uri_values_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfwsi_uri_values_free(
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

/* Tests the libfwsi_uri_values_read_data function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_uri_values_read_data(
     void )
{
	uint8_t short_data[ 5 ]          = { 0x05, 0x00, 0x61, 0x00, 0x00 };
	uint8_t wrong_type_data[ 8 ]     = { 0x08, 0x00, 0x62, 0x00, 0x00, 0x00, 0x00, 0x00 };
	uint8_t ascii_uri_data[ 14 ]     = { 0x0e, 0x00, 0x61, 0x00, 0x00, 0x00, 'h', 't', 't', 'p', 0x00, 0x01, 0x02, 0x03 };
	uint8_t ascii_uri_bad_tail[ 12 ] = { 0x0c, 0x00, 0x61, 0x00, 0x00, 0x00, 'h', 't', 't', 'p', 0x00, 0x01 };
	uint8_t bad_item_size_data[ 8 ]  = { 0x08, 0x00, 0x61, 0x00, 0x10, 0x00, 0x00, 0x00 };
	uint8_t no_uri_data[ 6 ]         = { 0x06, 0x00, 0x61, 0x00, 0x00, 0x00 };
	uint8_t ext_uri_data[ 70 ]       = {
		0x46, 0x00, 0x61, 0x00, 0x34, 0x00,
		/* 36 bytes header */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		/* string1 size = 0 */
		0x00, 0x00, 0x00, 0x00,
		/* string2 size = 0 */
		0x00, 0x00, 0x00, 0x00,
		/* string3 size = 0 */
		0x00, 0x00, 0x00, 0x00,
		/* 4 bytes trailing item data */
		0x01, 0x02, 0x03, 0x04,
		/* ASCII URI */
		'h', 't', 't', 'p', ':', '/', '/', 'a', 0x00, 0x00, 0x00, 0x00 };
	uint8_t ext_uri_err[ 70 ];
	libcerror_error_t *error         = NULL;
	libfwsi_uri_values_t *uri_values = NULL;
	int result                       = 0;

	/* Initialize test
	 */
	result = libfwsi_uri_values_initialize(
	          &uri_values,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "uri_values",
	 uri_values );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfwsi_uri_values_read_data(
	          uri_values,
	          fwsi_test_uri_values_data1,
	          390,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test ASCII URI with trailing data
	 */
	result = libfwsi_uri_values_read_data(
	          uri_values,
	          ascii_uri_data,
	          14,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test ASCII URI with no trailing data
	 */
	result = libfwsi_uri_values_read_data(
	          uri_values,
	          ascii_uri_data,
	          11,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test extended URI data with item_data_size >= 36 and trailing item data
	 */
	result = libfwsi_uri_values_read_data(
	          uri_values,
	          ext_uri_data,
	          70,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test unsupported data cases
	 */
	result = libfwsi_uri_values_read_data(
	          uri_values,
	          short_data,
	          5,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwsi_uri_values_read_data(
	          uri_values,
	          wrong_type_data,
	          8,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
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
	result = libfwsi_uri_values_read_data(
	          NULL,
	          fwsi_test_uri_values_data1,
	          390,
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

	result = libfwsi_uri_values_read_data(
	          uri_values,
	          NULL,
	          390,
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

	result = libfwsi_uri_values_read_data(
	          uri_values,
	          fwsi_test_uri_values_data1,
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

	/* item_data_size out of bounds
	 */
	result = libfwsi_uri_values_read_data(
	          uri_values,
	          bad_item_size_data,
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

	/* data_offset >= data_size before URI
	 */
	result = libfwsi_uri_values_read_data(
	          uri_values,
	          no_uri_data,
	          6,
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

	/* trailing unknown9 too small
	 */
	result = libfwsi_uri_values_read_data(
	          uri_values,
	          ascii_uri_bad_tail,
	          12,
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

	/* item_data_size >= 36 error branches: string1/2/3 OOB
	 */
	memory_copy(
	 ext_uri_err,
	 ext_uri_data,
	 70 );
	ext_uri_err[ 4 ] = 36;
	result = libfwsi_uri_values_read_data(
	          uri_values,
	          ext_uri_err,
	          44,
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

	result = libfwsi_uri_values_read_data(
	          uri_values,
	          ext_uri_err,
	          60,
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

	/* string1 data_offset >= data_size
	 */
	ext_uri_err[ 4 ] = 40;
	result = libfwsi_uri_values_read_data(
	          uri_values,
	          ext_uri_err,
	          46,
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

	/* string2 data_offset >= data_size - 4
	 */
	result = libfwsi_uri_values_read_data(
	          uri_values,
	          ext_uri_err,
	          48,
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

	/* string2 item_data_size < 4
	 */
	result = libfwsi_uri_values_read_data(
	          uri_values,
	          ext_uri_err,
	          60,
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

	/* string2 data_offset >= data_size
	 */
	ext_uri_err[ 4 ] = 44;
	result = libfwsi_uri_values_read_data(
	          uri_values,
	          ext_uri_err,
	          50,
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

	/* string3 data_offset >= data_size - 4
	 */
	result = libfwsi_uri_values_read_data(
	          uri_values,
	          ext_uri_err,
	          52,
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

	/* string3 item_data_size < 4
	 */
	result = libfwsi_uri_values_read_data(
	          uri_values,
	          ext_uri_err,
	          60,
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

	/* string3 data_offset >= data_size
	 */
	ext_uri_err[ 4 ] = 48;
	result = libfwsi_uri_values_read_data(
	          uri_values,
	          ext_uri_err,
	          54,
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

	/* Clean up
	 */
	result = libfwsi_uri_values_free(
	          &uri_values,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "uri_values",
	 uri_values );

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
	if( uri_values != NULL )
	{
		libfwsi_uri_values_free(
		 &uri_values,
		 NULL );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT ) */

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
	FWSI_TEST_UNREFERENCED_PARAMETER( argc )
	FWSI_TEST_UNREFERENCED_PARAMETER( argv )

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )

	FWSI_TEST_RUN(
	 "libfwsi_uri_values_initialize",
	 fwsi_test_uri_values_initialize );

	FWSI_TEST_RUN(
	 "libfwsi_uri_values_free",
	 fwsi_test_uri_values_free );

	FWSI_TEST_RUN(
	 "libfwsi_uri_values_read_data",
	 fwsi_test_uri_values_read_data );

#endif /* defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

