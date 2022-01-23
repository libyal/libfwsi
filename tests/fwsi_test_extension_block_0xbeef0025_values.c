/*
 * Library extension_block_0xbeef0025_values type test program
 *
 * Copyright (C) 2010-2022, Joachim Metz <joachim.metz@gmail.com>
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

#include "../libfwsi/libfwsi_extension_block_0xbeef0025_values.h"

uint8_t fwsi_test_extension_block_0xbeef0025_values_data1[ 30 ] = {
	0x1e, 0x00, 0x00, 0x00, 0x25, 0x00, 0xef, 0xbe, 0x11, 0x00, 0x00, 0x00, 0x8a, 0xa4, 0xd8, 0xae,
	0xa6, 0x58, 0xce, 0x01, 0x44, 0xc6, 0x34, 0xc4, 0x51, 0xe5, 0xce, 0x01, 0x14, 0x00 };

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )

/* Tests the libfwsi_extension_block_0xbeef0025_values_initialize function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_extension_block_0xbeef0025_values_initialize(
     void )
{
	libcerror_error_t *error                                                       = NULL;
	libfwsi_extension_block_0xbeef0025_values_t *extension_block_0xbeef0025_values = NULL;
	int result                                                                     = 0;

#if defined( HAVE_FWSI_TEST_MEMORY )
	int number_of_malloc_fail_tests                                                = 1;
	int number_of_memset_fail_tests                                                = 1;
	int test_number                                                                = 0;
#endif

	/* Test regular cases
	 */
	result = libfwsi_extension_block_0xbeef0025_values_initialize(
	          &extension_block_0xbeef0025_values,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "extension_block_0xbeef0025_values",
	 extension_block_0xbeef0025_values );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwsi_extension_block_0xbeef0025_values_free(
	          &extension_block_0xbeef0025_values,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "extension_block_0xbeef0025_values",
	 extension_block_0xbeef0025_values );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwsi_extension_block_0xbeef0025_values_initialize(
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

	extension_block_0xbeef0025_values = (libfwsi_extension_block_0xbeef0025_values_t *) 0x12345678UL;

	result = libfwsi_extension_block_0xbeef0025_values_initialize(
	          &extension_block_0xbeef0025_values,
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

	extension_block_0xbeef0025_values = NULL;

#if defined( HAVE_FWSI_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libfwsi_extension_block_0xbeef0025_values_initialize with malloc failing
		 */
		fwsi_test_malloc_attempts_before_fail = test_number;

		result = libfwsi_extension_block_0xbeef0025_values_initialize(
		          &extension_block_0xbeef0025_values,
		          &error );

		if( fwsi_test_malloc_attempts_before_fail != -1 )
		{
			fwsi_test_malloc_attempts_before_fail = -1;

			if( extension_block_0xbeef0025_values != NULL )
			{
				libfwsi_extension_block_0xbeef0025_values_free(
				 &extension_block_0xbeef0025_values,
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
			 "extension_block_0xbeef0025_values",
			 extension_block_0xbeef0025_values );

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
		/* Test libfwsi_extension_block_0xbeef0025_values_initialize with memset failing
		 */
		fwsi_test_memset_attempts_before_fail = test_number;

		result = libfwsi_extension_block_0xbeef0025_values_initialize(
		          &extension_block_0xbeef0025_values,
		          &error );

		if( fwsi_test_memset_attempts_before_fail != -1 )
		{
			fwsi_test_memset_attempts_before_fail = -1;

			if( extension_block_0xbeef0025_values != NULL )
			{
				libfwsi_extension_block_0xbeef0025_values_free(
				 &extension_block_0xbeef0025_values,
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
			 "extension_block_0xbeef0025_values",
			 extension_block_0xbeef0025_values );

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
	if( extension_block_0xbeef0025_values != NULL )
	{
		libfwsi_extension_block_0xbeef0025_values_free(
		 &extension_block_0xbeef0025_values,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwsi_extension_block_0xbeef0025_values_free function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_extension_block_0xbeef0025_values_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfwsi_extension_block_0xbeef0025_values_free(
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

/* Tests the libfwsi_extension_block_0xbeef0025_values_read_data function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_extension_block_0xbeef0025_values_read_data(
     void )
{
	libcerror_error_t *error                                                       = NULL;
	libfwsi_extension_block_0xbeef0025_values_t *extension_block_0xbeef0025_values = NULL;
	int result                                                                     = 0;

	/* Initialize test
	 */
	result = libfwsi_extension_block_0xbeef0025_values_initialize(
	          &extension_block_0xbeef0025_values,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "extension_block_0xbeef0025_values",
	 extension_block_0xbeef0025_values );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfwsi_extension_block_0xbeef0025_values_read_data(
	          extension_block_0xbeef0025_values,
	          fwsi_test_extension_block_0xbeef0025_values_data1,
	          30,
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
	result = libfwsi_extension_block_0xbeef0025_values_read_data(
	          NULL,
	          fwsi_test_extension_block_0xbeef0025_values_data1,
	          30,
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

	result = libfwsi_extension_block_0xbeef0025_values_read_data(
	          extension_block_0xbeef0025_values,
	          NULL,
	          30,
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

	result = libfwsi_extension_block_0xbeef0025_values_read_data(
	          extension_block_0xbeef0025_values,
	          fwsi_test_extension_block_0xbeef0025_values_data1,
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

	/* Clean up
	 */
	result = libfwsi_extension_block_0xbeef0025_values_free(
	          &extension_block_0xbeef0025_values,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "extension_block_0xbeef0025_values",
	 extension_block_0xbeef0025_values );

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
	if( extension_block_0xbeef0025_values != NULL )
	{
		libfwsi_extension_block_0xbeef0025_values_free(
		 &extension_block_0xbeef0025_values,
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
	 "libfwsi_extension_block_0xbeef0025_values_initialize",
	 fwsi_test_extension_block_0xbeef0025_values_initialize );

	FWSI_TEST_RUN(
	 "libfwsi_extension_block_0xbeef0025_values_free",
	 fwsi_test_extension_block_0xbeef0025_values_free );

	FWSI_TEST_RUN(
	 "libfwsi_extension_block_0xbeef0025_values_read_data",
	 fwsi_test_extension_block_0xbeef0025_values_read_data );

#endif /* defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

