/*
 * Library file_entry_values type test program
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
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fwsi_test_libcerror.h"
#include "fwsi_test_libfwsi.h"
#include "fwsi_test_macros.h"
#include "fwsi_test_memory.h"
#include "fwsi_test_unused.h"

#include "../libfwsi/libfwsi_file_entry_values.h"

uint8_t fwsi_test_file_entry_values_data1[ 72 ] = {
	0x48, 0x00, 0x32, 0x00, 0x00, 0x46, 0x03, 0x00, 0x04, 0x31, 0x00, 0x68, 0x20, 0x00, 0x77, 0x6f,
	0x72, 0x64, 0x70, 0x61, 0x64, 0x2e, 0x65, 0x78, 0x65, 0x00, 0x2e, 0x00, 0x03, 0x00, 0x04, 0x00,
	0xef, 0xbe, 0x0a, 0x31, 0xc9, 0x7e, 0x09, 0x31, 0x00, 0xb8, 0x14, 0x00, 0x00, 0x00, 0x77, 0x00,
	0x6f, 0x00, 0x72, 0x00, 0x64, 0x00, 0x70, 0x00, 0x61, 0x00, 0x64, 0x00, 0x2e, 0x00, 0x65, 0x00,
	0x78, 0x00, 0x65, 0x00, 0x00, 0x00, 0x1a, 0x00 };

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )

/* Tests the libfwsi_file_entry_values_initialize function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_file_entry_values_initialize(
     void )
{
	libcerror_error_t *error                       = NULL;
	libfwsi_file_entry_values_t *file_entry_values = NULL;
	int result                                     = 0;

#if defined( HAVE_FWSI_TEST_MEMORY )
	int number_of_malloc_fail_tests                = 1;
	int number_of_memset_fail_tests                = 1;
	int test_number                                = 0;
#endif

	/* Test regular cases
	 */
	result = libfwsi_file_entry_values_initialize(
	          &file_entry_values,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "file_entry_values",
	 file_entry_values );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwsi_file_entry_values_free(
	          &file_entry_values,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "file_entry_values",
	 file_entry_values );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwsi_file_entry_values_initialize(
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

	file_entry_values = (libfwsi_file_entry_values_t *) 0x12345678UL;

	result = libfwsi_file_entry_values_initialize(
	          &file_entry_values,
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

	file_entry_values = NULL;

#if defined( HAVE_FWSI_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libfwsi_file_entry_values_initialize with malloc failing
		 */
		fwsi_test_malloc_attempts_before_fail = test_number;

		result = libfwsi_file_entry_values_initialize(
		          &file_entry_values,
		          &error );

		if( fwsi_test_malloc_attempts_before_fail != -1 )
		{
			fwsi_test_malloc_attempts_before_fail = -1;

			if( file_entry_values != NULL )
			{
				libfwsi_file_entry_values_free(
				 &file_entry_values,
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
			 "file_entry_values",
			 file_entry_values );

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
		/* Test libfwsi_file_entry_values_initialize with memset failing
		 */
		fwsi_test_memset_attempts_before_fail = test_number;

		result = libfwsi_file_entry_values_initialize(
		          &file_entry_values,
		          &error );

		if( fwsi_test_memset_attempts_before_fail != -1 )
		{
			fwsi_test_memset_attempts_before_fail = -1;

			if( file_entry_values != NULL )
			{
				libfwsi_file_entry_values_free(
				 &file_entry_values,
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
			 "file_entry_values",
			 file_entry_values );

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
	if( file_entry_values != NULL )
	{
		libfwsi_file_entry_values_free(
		 &file_entry_values,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwsi_file_entry_values_free function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_file_entry_values_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfwsi_file_entry_values_free(
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

/* Tests the libfwsi_file_entry_values_read_data function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_file_entry_values_read_data(
     void )
{
	uint8_t short_data[ 13 ]      = { 0x0d, 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	uint8_t wrong_type_data[ 16 ] = { 0x10, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 'a', 0x00 };
	uint8_t empty_name_data[ 14 ] = { 0x0e, 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	uint8_t unicode_data[ 22 ]    = {
		0x16, 0x00, 0x35, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00,
		'a', 0x00, 'b', 0x00, 0x00, 0x00, 0x00, 0x00 };
	uint8_t swn1_data[ 52 ]       = {
		0x34, 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00,
		'a', 0x00, 'b', 0x00, 0x00, 0x00, 0x20, 0x00,
		'S', '.', 'W', '.', 'N', '.', '1', 0x00,
		0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
		0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	uint8_t pre_xp_ascii_data[ 36 ] = {
		0x24, 0x00, 0xb1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00,
		'a', 'b', 0x00, 'c', 'd', 0x00,
		0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10 };
	uint8_t pre_xp_unicode_data[ 22 ] = {
		0x16, 0x00, 0x35, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00,
		'a', 0x00, 0x00, 0x00, 'b', 0x00, 0x00, 0x00 };
	uint8_t utf8_string[ 32 ];
	uint16_t utf16_string[ 32 ];
	libcerror_error_t *error                       = NULL;
	libfwsi_file_entry_values_t *file_entry_values = NULL;
	size_t string_size                             = 0;
	int result                                     = 0;

	/* Initialize test
	 */
	result = libfwsi_file_entry_values_initialize(
	          &file_entry_values,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "file_entry_values",
	 file_entry_values );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfwsi_file_entry_values_read_data(
	          file_entry_values,
	          fwsi_test_file_entry_values_data1,
	          72,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test getters on ASCII file entry values
	 */
	result = libfwsi_file_entry_values_get_utf8_name_size(
	          file_entry_values,
	          &string_size,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwsi_file_entry_values_get_utf8_name(
	          file_entry_values,
	          utf8_string,
	          32,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwsi_file_entry_values_get_utf16_name_size(
	          file_entry_values,
	          &string_size,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwsi_file_entry_values_get_utf16_name(
	          file_entry_values,
	          utf16_string,
	          32,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test getter error cases
	 */
	result = libfwsi_file_entry_values_get_utf8_name_size(
	          NULL,
	          &string_size,
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

	result = libfwsi_file_entry_values_get_utf8_name_size(
	          file_entry_values,
	          NULL,
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

	result = libfwsi_file_entry_values_get_utf8_name(
	          NULL,
	          utf8_string,
	          32,
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

	result = libfwsi_file_entry_values_get_utf8_name(
	          file_entry_values,
	          utf8_string,
	          1,
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

	result = libfwsi_file_entry_values_get_utf16_name_size(
	          NULL,
	          &string_size,
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

	result = libfwsi_file_entry_values_get_utf16_name_size(
	          file_entry_values,
	          NULL,
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

	result = libfwsi_file_entry_values_get_utf16_name(
	          NULL,
	          utf16_string,
	          32,
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

	result = libfwsi_file_entry_values_get_utf16_name(
	          file_entry_values,
	          utf16_string,
	          1,
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

	/* Test Unicode class type (0x35) and getters
	 */
	result = libfwsi_file_entry_values_free(
	          &file_entry_values,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );
	result = libfwsi_file_entry_values_initialize(
	          &file_entry_values,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = libfwsi_file_entry_values_read_data(
	          file_entry_values,
	          unicode_data,
	          22,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );
	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwsi_file_entry_values_get_utf8_name_size(
	          file_entry_values,
	          &string_size,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = libfwsi_file_entry_values_get_utf8_name(
	          file_entry_values,
	          utf8_string,
	          32,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = libfwsi_file_entry_values_get_utf16_name_size(
	          file_entry_values,
	          &string_size,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = libfwsi_file_entry_values_get_utf16_name(
	          file_entry_values,
	          utf16_string,
	          32,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	/* Test S.W.N.1 format
	 */
	result = libfwsi_file_entry_values_free(
	          &file_entry_values,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );
	result = libfwsi_file_entry_values_initialize(
	          &file_entry_values,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = libfwsi_file_entry_values_read_data(
	          file_entry_values,
	          swn1_data,
	          52,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );
	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test pre-XP ASCII format with 0x80 flag and GUID
	 */
	result = libfwsi_file_entry_values_free(
	          &file_entry_values,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );
	result = libfwsi_file_entry_values_initialize(
	          &file_entry_values,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = libfwsi_file_entry_values_read_data(
	          file_entry_values,
	          pre_xp_ascii_data,
	          36,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );
	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test pre-XP Unicode format
	 */
	result = libfwsi_file_entry_values_free(
	          &file_entry_values,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );
	result = libfwsi_file_entry_values_initialize(
	          &file_entry_values,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = libfwsi_file_entry_values_read_data(
	          file_entry_values,
	          pre_xp_unicode_data,
	          22,
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
	result = libfwsi_file_entry_values_read_data(
	          file_entry_values,
	          short_data,
	          13,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );
	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwsi_file_entry_values_read_data(
	          file_entry_values,
	          wrong_type_data,
	          16,
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
	result = libfwsi_file_entry_values_read_data(
	          NULL,
	          fwsi_test_file_entry_values_data1,
	          72,
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

	result = libfwsi_file_entry_values_read_data(
	          file_entry_values,
	          NULL,
	          72,
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

	result = libfwsi_file_entry_values_read_data(
	          file_entry_values,
	          fwsi_test_file_entry_values_data1,
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

	/* Empty name (data_size == 14)
	 */
	result = libfwsi_file_entry_values_read_data(
	          file_entry_values,
	          empty_name_data,
	          14,
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
	result = libfwsi_file_entry_values_free(
	          &file_entry_values,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "file_entry_values",
	 file_entry_values );

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
	if( file_entry_values != NULL )
	{
		libfwsi_file_entry_values_free(
		 &file_entry_values,
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
	 "libfwsi_file_entry_values_initialize",
	 fwsi_test_file_entry_values_initialize );

	FWSI_TEST_RUN(
	 "libfwsi_file_entry_values_free",
	 fwsi_test_file_entry_values_free );

	FWSI_TEST_RUN(
	 "libfwsi_file_entry_values_read_data",
	 fwsi_test_file_entry_values_read_data );

#endif /* defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

