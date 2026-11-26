/*
 * Library compressed_folder_values type test program
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

#include "../libfwsi/libfwsi_compressed_folder_values.h"

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )

/* Tests the libfwsi_compressed_folder_values_initialize function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_compressed_folder_values_initialize(
     void )
{
	libcerror_error_t *error                                     = NULL;
	libfwsi_compressed_folder_values_t *compressed_folder_values = NULL;
	int result                                                   = 0;

#if defined( HAVE_FWSI_TEST_MEMORY )
	int number_of_malloc_fail_tests                              = 1;
	int number_of_memset_fail_tests                              = 1;
	int test_number                                              = 0;
#endif

	/* Test regular cases
	 */
	result = libfwsi_compressed_folder_values_initialize(
	          &compressed_folder_values,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "compressed_folder_values",
	 compressed_folder_values );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwsi_compressed_folder_values_free(
	          &compressed_folder_values,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "compressed_folder_values",
	 compressed_folder_values );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwsi_compressed_folder_values_initialize(
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

	compressed_folder_values = (libfwsi_compressed_folder_values_t *) 0x12345678UL;

	result = libfwsi_compressed_folder_values_initialize(
	          &compressed_folder_values,
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

	compressed_folder_values = NULL;

#if defined( HAVE_FWSI_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libfwsi_compressed_folder_values_initialize with malloc failing
		 */
		fwsi_test_malloc_attempts_before_fail = test_number;

		result = libfwsi_compressed_folder_values_initialize(
		          &compressed_folder_values,
		          &error );

		if( fwsi_test_malloc_attempts_before_fail != -1 )
		{
			fwsi_test_malloc_attempts_before_fail = -1;

			if( compressed_folder_values != NULL )
			{
				libfwsi_compressed_folder_values_free(
				 &compressed_folder_values,
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
			 "compressed_folder_values",
			 compressed_folder_values );

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
		/* Test libfwsi_compressed_folder_values_initialize with memset failing
		 */
		fwsi_test_memset_attempts_before_fail = test_number;

		result = libfwsi_compressed_folder_values_initialize(
		          &compressed_folder_values,
		          &error );

		if( fwsi_test_memset_attempts_before_fail != -1 )
		{
			fwsi_test_memset_attempts_before_fail = -1;

			if( compressed_folder_values != NULL )
			{
				libfwsi_compressed_folder_values_free(
				 &compressed_folder_values,
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
			 "compressed_folder_values",
			 compressed_folder_values );

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
	if( compressed_folder_values != NULL )
	{
		libfwsi_compressed_folder_values_free(
		 &compressed_folder_values,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwsi_compressed_folder_values_free function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_compressed_folder_values_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfwsi_compressed_folder_values_free(
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

#endif /* defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT ) */

/* Tests the libfwsi_compressed_folder_values_read_data function
 * Returns 1 if successful or 0 if not
 */
#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )

int fwsi_test_compressed_folder_values_read_data(
     void )
{
	/* Format 1 (Windows XP) */
	uint8_t data_format1[ 80 ] = {
		0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x31, 0x00, 0x2f, 0x00, 0x30, 0x00,
		0x31, 0x00, 0x2f, 0x00, 0x30, 0x00, 0x30, 0x00, 0x20, 0x00, 0x20, 0x00, 0x31, 0x00, 0x32, 0x00,
		0x3a, 0x00, 0x30, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x74, 0x00, 0x65, 0x00, 0x73, 0x00, 0x74, 0x00, 0x00, 0x00, 0x00, 0x00 };

	/* Format 2 (Windows 10 without date/time: "N/A") */
	uint8_t data_format2[ 100 ] = {
		0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x4e, 0x00, 0x2f, 0x00, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x61, 0x00, 0x62, 0x00,
		0x00, 0x00, 0x00, 0x00 };

	/* Format 3 (Windows 10 with date/time) */
	uint8_t data_format3[ 100 ] = {
		0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x31, 0x00, 0x2f, 0x00, 0x30, 0x00, 0x31, 0x00, 0x2f, 0x00,
		0x32, 0x00, 0x30, 0x00, 0x32, 0x00, 0x30, 0x00, 0x20, 0x00, 0x20, 0x00, 0x31, 0x00, 0x32, 0x00,
		0x3a, 0x00, 0x30, 0x00, 0x30, 0x00, 0x3a, 0x00, 0x30, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x61, 0x00, 0x62, 0x00,
		0x00, 0x00, 0x00, 0x00 };

	uint8_t unsupported_data[ 92 ] = { 0 };

	libcerror_error_t *error                                     = NULL;
	libfwsi_compressed_folder_values_t *compressed_folder_values = NULL;
	int result                                                   = 0;

	/* Format 1 */
	result = libfwsi_compressed_folder_values_initialize( &compressed_folder_values, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

	result = libfwsi_compressed_folder_values_read_data( compressed_folder_values, data_format1, 80, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	/* Error: name already set */
	result = libfwsi_compressed_folder_values_read_data( compressed_folder_values, data_format1, 80, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_compressed_folder_values_free( &compressed_folder_values, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

	/* Format 2 */
	result = libfwsi_compressed_folder_values_initialize( &compressed_folder_values, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

	result = libfwsi_compressed_folder_values_read_data( compressed_folder_values, data_format2, 100, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_compressed_folder_values_free( &compressed_folder_values, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

	/* Format 3 */
	result = libfwsi_compressed_folder_values_initialize( &compressed_folder_values, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

	result = libfwsi_compressed_folder_values_read_data( compressed_folder_values, data_format3, 100, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_compressed_folder_values_free( &compressed_folder_values, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

	/* Unsupported and error cases */
	result = libfwsi_compressed_folder_values_initialize( &compressed_folder_values, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

	/* Size < 68 */
	result = libfwsi_compressed_folder_values_read_data( compressed_folder_values, data_format1, 60, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	/* Unsupported format */
	result = libfwsi_compressed_folder_values_read_data( compressed_folder_values, unsupported_data, 92, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	/* Name string size out of bounds */
	result = libfwsi_compressed_folder_values_read_data( compressed_folder_values, data_format1, 70, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	/* String2 size out of bounds */
	result = libfwsi_compressed_folder_values_read_data( compressed_folder_values, data_format1, 78, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	/* NULL args & SSIZE_MAX */
	result = libfwsi_compressed_folder_values_read_data( NULL, data_format1, 80, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_compressed_folder_values_read_data( compressed_folder_values, NULL, 80, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_compressed_folder_values_read_data( compressed_folder_values, data_format1, (size_t) SSIZE_MAX + 1, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_compressed_folder_values_free( &compressed_folder_values, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free( &error );
	}
	if( compressed_folder_values != NULL )
	{
		libfwsi_compressed_folder_values_free( &compressed_folder_values, NULL );
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
	 "libfwsi_compressed_folder_values_initialize",
	 fwsi_test_compressed_folder_values_initialize );

	FWSI_TEST_RUN(
	 "libfwsi_compressed_folder_values_free",
	 fwsi_test_compressed_folder_values_free );

	FWSI_TEST_RUN(
	 "libfwsi_compressed_folder_values_read_data",
	 fwsi_test_compressed_folder_values_read_data );

#endif /* defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

