/*
 * Library web_site_values type test program
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

#include "../libfwsi/libfwsi_web_site_values.h"

/* Valid web site item: 24 header + 4 string1 + 20 mid + 4 string2 + 12 footer = 64 bytes */
uint8_t fwsi_test_web_site_values_data1[ 64 ] = {
	0x40, 0x00, 0x00, 0x00, 0x00, 0xb0, 0x01, 0xc0, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
	0x62, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

/* Error data: string1 size out of bounds */
uint8_t fwsi_test_web_site_values_error_data1[ 32 ] = {
	0x20, 0x00, 0x00, 0x00, 0x00, 0xb0, 0x01, 0xc0, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

/* Error data: string2 size out of bounds */
uint8_t fwsi_test_web_site_values_error_data2[ 52 ] = {
	0x34, 0x00, 0x00, 0x00, 0x00, 0xb0, 0x01, 0xc0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00 };

/* Unsupported signature */
uint8_t fwsi_test_web_site_values_unsupported_data1[ 32 ] = {
	0x20, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )

/* Tests the libfwsi_web_site_values_initialize function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_web_site_values_initialize(
     void )
{
	libcerror_error_t *error                   = NULL;
	libfwsi_web_site_values_t *web_site_values = NULL;
	int result                                 = 0;

#if defined( HAVE_FWSI_TEST_MEMORY )
	int number_of_malloc_fail_tests            = 1;
	int number_of_memset_fail_tests            = 1;
	int test_number                            = 0;
#endif

	result = libfwsi_web_site_values_initialize( &web_site_values, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_IS_NOT_NULL( "web_site_values", web_site_values );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_web_site_values_free( &web_site_values, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_IS_NULL( "web_site_values", web_site_values );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	/* Error cases */
	result = libfwsi_web_site_values_initialize( NULL, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	FWSI_TEST_ASSERT_IS_NOT_NULL( "error", error );
	libcerror_error_free( &error );

	web_site_values = (libfwsi_web_site_values_t *) 0x12345678UL;

	result = libfwsi_web_site_values_initialize( &web_site_values, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	FWSI_TEST_ASSERT_IS_NOT_NULL( "error", error );
	libcerror_error_free( &error );

	web_site_values = NULL;

#if defined( HAVE_FWSI_TEST_MEMORY )
	for( test_number = 0; test_number < number_of_malloc_fail_tests; test_number++ )
	{
		fwsi_test_malloc_attempts_before_fail = test_number;
		result = libfwsi_web_site_values_initialize( &web_site_values, &error );
		if( fwsi_test_malloc_attempts_before_fail != -1 )
		{
			fwsi_test_malloc_attempts_before_fail = -1;
			if( web_site_values != NULL )
			{
				libfwsi_web_site_values_free( &web_site_values, NULL );
			}
		}
		else
		{
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
			FWSI_TEST_ASSERT_IS_NULL( "web_site_values", web_site_values );
			FWSI_TEST_ASSERT_IS_NOT_NULL( "error", error );
			libcerror_error_free( &error );
		}
	}
	for( test_number = 0; test_number < number_of_memset_fail_tests; test_number++ )
	{
		fwsi_test_memset_attempts_before_fail = test_number;
		result = libfwsi_web_site_values_initialize( &web_site_values, &error );
		if( fwsi_test_memset_attempts_before_fail != -1 )
		{
			fwsi_test_memset_attempts_before_fail = -1;
			if( web_site_values != NULL )
			{
				libfwsi_web_site_values_free( &web_site_values, NULL );
			}
		}
		else
		{
			FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
			FWSI_TEST_ASSERT_IS_NULL( "web_site_values", web_site_values );
			FWSI_TEST_ASSERT_IS_NOT_NULL( "error", error );
			libcerror_error_free( &error );
		}
	}
#endif /* defined( HAVE_FWSI_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free( &error );
	}
	if( web_site_values != NULL )
	{
		libfwsi_web_site_values_free( &web_site_values, NULL );
	}
	return( 0 );
}

/* Tests the libfwsi_web_site_values_free function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_web_site_values_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	result = libfwsi_web_site_values_free( NULL, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	FWSI_TEST_ASSERT_IS_NOT_NULL( "error", error );
	libcerror_error_free( &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free( &error );
	}
	return( 0 );
}

/* Tests the libfwsi_web_site_values_read_data function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_web_site_values_read_data(
     void )
{
	libcerror_error_t *error                   = NULL;
	libfwsi_web_site_values_t *web_site_values = NULL;
	int result                                 = 0;

	result = libfwsi_web_site_values_initialize( &web_site_values, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

	/* Regular case */
	result = libfwsi_web_site_values_read_data( web_site_values, fwsi_test_web_site_values_data1, 64, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	/* Unsupported data size */
	result = libfwsi_web_site_values_read_data( web_site_values, fwsi_test_web_site_values_data1, 16, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	/* Unsupported signature */
	result = libfwsi_web_site_values_read_data( web_site_values, fwsi_test_web_site_values_unsupported_data1, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	/* Error cases */
	result = libfwsi_web_site_values_read_data( NULL, fwsi_test_web_site_values_data1, 64, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_web_site_values_read_data( web_site_values, NULL, 64, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_web_site_values_read_data( web_site_values, fwsi_test_web_site_values_data1, (size_t) SSIZE_MAX + 1, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	/* string1 out of bounds */
	result = libfwsi_web_site_values_read_data( web_site_values, fwsi_test_web_site_values_error_data1, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	/* Truncated before 20-byte mid header */
	result = libfwsi_web_site_values_read_data( web_site_values, fwsi_test_web_site_values_data1, 40, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	/* string2 out of bounds */
	result = libfwsi_web_site_values_read_data( web_site_values, fwsi_test_web_site_values_error_data2, 52, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	/* Truncated before 12-byte footer */
	result = libfwsi_web_site_values_read_data( web_site_values, fwsi_test_web_site_values_data1, 56, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_web_site_values_free( &web_site_values, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free( &error );
	}
	if( web_site_values != NULL )
	{
		libfwsi_web_site_values_free( &web_site_values, NULL );
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
	 "libfwsi_web_site_values_initialize",
	 fwsi_test_web_site_values_initialize );

	FWSI_TEST_RUN(
	 "libfwsi_web_site_values_free",
	 fwsi_test_web_site_values_free );

	FWSI_TEST_RUN(
	 "libfwsi_web_site_values_read_data",
	 fwsi_test_web_site_values_read_data );

#endif /* defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}
