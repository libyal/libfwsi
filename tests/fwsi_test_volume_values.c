/*
 * Library volume_values type test program
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

#include "../libfwsi/libfwsi_volume_values.h"

uint8_t fwsi_test_volume_values_data1[ 25 ] = {
	0x19, 0x00, 0x2f, 0x43, 0x3a, 0x5c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )

/* Tests the libfwsi_volume_values_initialize function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_volume_values_initialize(
     void )
{
	libcerror_error_t *error               = NULL;
	libfwsi_volume_values_t *volume_values = NULL;
	int result                             = 0;

#if defined( HAVE_FWSI_TEST_MEMORY )
	int number_of_malloc_fail_tests        = 1;
	int number_of_memset_fail_tests        = 1;
	int test_number                        = 0;
#endif

	/* Test regular cases
	 */
	result = libfwsi_volume_values_initialize(
	          &volume_values,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "volume_values",
	 volume_values );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwsi_volume_values_free(
	          &volume_values,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "volume_values",
	 volume_values );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwsi_volume_values_initialize(
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

	volume_values = (libfwsi_volume_values_t *) 0x12345678UL;

	result = libfwsi_volume_values_initialize(
	          &volume_values,
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

	volume_values = NULL;

#if defined( HAVE_FWSI_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libfwsi_volume_values_initialize with malloc failing
		 */
		fwsi_test_malloc_attempts_before_fail = test_number;

		result = libfwsi_volume_values_initialize(
		          &volume_values,
		          &error );

		if( fwsi_test_malloc_attempts_before_fail != -1 )
		{
			fwsi_test_malloc_attempts_before_fail = -1;

			if( volume_values != NULL )
			{
				libfwsi_volume_values_free(
				 &volume_values,
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
			 "volume_values",
			 volume_values );

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
		/* Test libfwsi_volume_values_initialize with memset failing
		 */
		fwsi_test_memset_attempts_before_fail = test_number;

		result = libfwsi_volume_values_initialize(
		          &volume_values,
		          &error );

		if( fwsi_test_memset_attempts_before_fail != -1 )
		{
			fwsi_test_memset_attempts_before_fail = -1;

			if( volume_values != NULL )
			{
				libfwsi_volume_values_free(
				 &volume_values,
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
			 "volume_values",
			 volume_values );

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
	if( volume_values != NULL )
	{
		libfwsi_volume_values_free(
		 &volume_values,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwsi_volume_values_free function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_volume_values_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfwsi_volume_values_free(
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

/* Tests the libfwsi_volume_values_read_data function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_volume_values_read_data(
     void )
{
	uint8_t short_data[ 19 ]      = { 0x13, 0x00, 0x2f };
	uint8_t wrong_type_data[ 25 ] = { 0x19, 0x00, 0x20 };
	uint8_t guid_vol_data[ 20 ]   = {
		0x14, 0x00, 0x2e, 0x80,
		0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
		0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10 };
	uint8_t sf_vol_data[ 41 ]     = {
		0x29, 0x00, 0x2f, 'C', ':', '\\', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x20, 0xd0, 0x4f, 0xe0, 0x3a, 0xea, 0x69, 0x10,
		0xa2, 0xd8, 0x08, 0x00, 0x2b, 0x30, 0x30, 0x9d };
	uint8_t empty_sf_data[ 41 ]   = {
		0x29, 0x00, 0x2f, 'D', ':', '\\', 0x00 };
	uint8_t utf8_string[ 32 ];
	uint16_t utf16_string[ 32 ];
	uint8_t guid_data[ 16 ];
	libcerror_error_t *error               = NULL;
	libfwsi_volume_values_t *volume_values = NULL;
	size_t string_size                     = 0;
	int result                             = 0;

	/* Initialize test
	 */
	result = libfwsi_volume_values_initialize(
	          &volume_values,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "volume_values",
	 volume_values );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfwsi_volume_values_read_data(
	          volume_values,
	          fwsi_test_volume_values_data1,
	          25,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test class 0x2e (GUID identifier)
	 */
	result = libfwsi_volume_values_read_data(
	          volume_values,
	          guid_vol_data,
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

	/* Getters when only identifier is set
	 */
	result = libfwsi_volume_values_get_utf8_name_size(
	          volume_values,
	          &string_size,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	result = libfwsi_volume_values_get_utf8_name(
	          volume_values,
	          utf8_string,
	          32,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	result = libfwsi_volume_values_get_utf16_name_size(
	          volume_values,
	          &string_size,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	result = libfwsi_volume_values_get_utf16_name(
	          volume_values,
	          utf16_string,
	          32,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	result = libfwsi_volume_values_get_identifier(
	          volume_values,
	          guid_data,
	          16,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = libfwsi_volume_values_get_shell_folder_identifier(
	          volume_values,
	          guid_data,
	          16,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test class 0x2f with empty shell folder identifier
	 */
	result = libfwsi_volume_values_read_data(
	          volume_values,
	          empty_sf_data,
	          41,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	/* Test class 0x2f with non-empty shell folder identifier
	 */
	result = libfwsi_volume_values_read_data(
	          volume_values,
	          sf_vol_data,
	          41,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = libfwsi_volume_values_get_utf8_name_size(
	          volume_values,
	          &string_size,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = libfwsi_volume_values_get_utf8_name(
	          volume_values,
	          utf8_string,
	          32,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = libfwsi_volume_values_get_utf16_name_size(
	          volume_values,
	          &string_size,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = libfwsi_volume_values_get_utf16_name(
	          volume_values,
	          utf16_string,
	          32,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = libfwsi_volume_values_get_identifier(
	          volume_values,
	          guid_data,
	          16,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	result = libfwsi_volume_values_get_shell_folder_identifier(
	          volume_values,
	          guid_data,
	          16,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	/* Test getter error cases
	 */
	result = libfwsi_volume_values_get_utf8_name_size(
	          NULL,
	          &string_size,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );
	libcerror_error_free(
	 &error );

	result = libfwsi_volume_values_get_utf8_name_size(
	          volume_values,
	          NULL,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );
	libcerror_error_free(
	 &error );

	result = libfwsi_volume_values_get_utf8_name(
	          NULL,
	          utf8_string,
	          32,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );
	libcerror_error_free(
	 &error );

	result = libfwsi_volume_values_get_utf8_name(
	          volume_values,
	          utf8_string,
	          1,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );
	libcerror_error_free(
	 &error );

	result = libfwsi_volume_values_get_utf16_name_size(
	          NULL,
	          &string_size,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );
	libcerror_error_free(
	 &error );

	result = libfwsi_volume_values_get_utf16_name_size(
	          volume_values,
	          NULL,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );
	libcerror_error_free(
	 &error );

	result = libfwsi_volume_values_get_utf16_name(
	          NULL,
	          utf16_string,
	          32,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );
	libcerror_error_free(
	 &error );

	result = libfwsi_volume_values_get_utf16_name(
	          volume_values,
	          utf16_string,
	          1,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );
	libcerror_error_free(
	 &error );

	result = libfwsi_volume_values_get_identifier(
	          NULL,
	          guid_data,
	          16,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );
	libcerror_error_free(
	 &error );

	result = libfwsi_volume_values_get_identifier(
	          volume_values,
	          NULL,
	          16,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );
	libcerror_error_free(
	 &error );

	result = libfwsi_volume_values_get_identifier(
	          volume_values,
	          guid_data,
	          8,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );
	libcerror_error_free(
	 &error );

	result = libfwsi_volume_values_get_shell_folder_identifier(
	          NULL,
	          guid_data,
	          16,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );
	libcerror_error_free(
	 &error );

	result = libfwsi_volume_values_get_shell_folder_identifier(
	          volume_values,
	          NULL,
	          16,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );
	libcerror_error_free(
	 &error );

	result = libfwsi_volume_values_get_shell_folder_identifier(
	          volume_values,
	          guid_data,
	          8,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );
	libcerror_error_free(
	 &error );

	/* Test unsupported data cases
	 */
	result = libfwsi_volume_values_read_data(
	          volume_values,
	          short_data,
	          19,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	result = libfwsi_volume_values_read_data(
	          volume_values,
	          wrong_type_data,
	          25,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	result = libfwsi_volume_values_read_data(
	          volume_values,
	          fwsi_test_volume_values_data1,
	          24,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	result = libfwsi_volume_values_read_data(
	          NULL,
	          fwsi_test_volume_values_data1,
	          25,
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

	result = libfwsi_volume_values_read_data(
	          volume_values,
	          NULL,
	          25,
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

	result = libfwsi_volume_values_read_data(
	          volume_values,
	          fwsi_test_volume_values_data1,
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

	/* Clean up
	 */
	result = libfwsi_volume_values_free(
	          &volume_values,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "volume_values",
	 volume_values );

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
	if( volume_values != NULL )
	{
		libfwsi_volume_values_free(
		 &volume_values,
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
	 "libfwsi_volume_values_initialize",
	 fwsi_test_volume_values_initialize );

	FWSI_TEST_RUN(
	 "libfwsi_volume_values_free",
	 fwsi_test_volume_values_free );

	FWSI_TEST_RUN(
	 "libfwsi_volume_values_read_data",
	 fwsi_test_volume_values_read_data );

#endif /* defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

