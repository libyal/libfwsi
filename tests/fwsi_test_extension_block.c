/*
 * Library extension_block type test program
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

#include "../libfwsi/libfwsi_extension_block.h"

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )

/* Tests the libfwsi_extension_block_initialize function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_extension_block_initialize(
     void )
{
	libcerror_error_t *error                   = NULL;
	libfwsi_extension_block_t *extension_block = NULL;
	int result                                 = 0;

#if defined( HAVE_FWSI_TEST_MEMORY )
	int number_of_malloc_fail_tests            = 1;
	int number_of_memset_fail_tests            = 1;
	int test_number                            = 0;
#endif

	/* Test regular cases
	 */
	result = libfwsi_extension_block_initialize(
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

	result = libfwsi_internal_extension_block_free(
	          (libfwsi_internal_extension_block_t **) &extension_block,
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
	result = libfwsi_extension_block_initialize(
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

	extension_block = (libfwsi_extension_block_t *) 0x12345678UL;

	result = libfwsi_extension_block_initialize(
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

	extension_block = NULL;

#if defined( HAVE_FWSI_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libfwsi_extension_block_initialize with malloc failing
		 */
		fwsi_test_malloc_attempts_before_fail = test_number;

		result = libfwsi_extension_block_initialize(
		          &extension_block,
		          &error );

		if( fwsi_test_malloc_attempts_before_fail != -1 )
		{
			fwsi_test_malloc_attempts_before_fail = -1;

			if( extension_block != NULL )
			{
				libfwsi_internal_extension_block_free(
				 (libfwsi_internal_extension_block_t **) &extension_block,
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
			 "extension_block",
			 extension_block );

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
		/* Test libfwsi_extension_block_initialize with memset failing
		 */
		fwsi_test_memset_attempts_before_fail = test_number;

		result = libfwsi_extension_block_initialize(
		          &extension_block,
		          &error );

		if( fwsi_test_memset_attempts_before_fail != -1 )
		{
			fwsi_test_memset_attempts_before_fail = -1;

			if( extension_block != NULL )
			{
				libfwsi_internal_extension_block_free(
				 (libfwsi_internal_extension_block_t **) &extension_block,
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
			 "extension_block",
			 extension_block );

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
	if( extension_block != NULL )
	{
		libfwsi_internal_extension_block_free(
		 (libfwsi_internal_extension_block_t **) &extension_block,
		 NULL );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT ) */

/* Tests the libfwsi_extension_block_free function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_extension_block_free(
     void )
{
	libcerror_error_t *error                   = NULL;
	libfwsi_extension_block_t *extension_block = NULL;
	int result                                 = 0;

	/* Test regular cases
	 */
	extension_block = (libfwsi_extension_block_t *) 0x12345678UL;

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
	result = libfwsi_extension_block_free(
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

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )

	result = libfwsi_internal_extension_block_free(
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

#endif /* defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )

/* Tests the libfwsi_extension_block_copy_from_byte_stream function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_extension_block_copy_from_byte_stream(
     void )
{
	uint8_t zero_data[ 2 ]        = { 0x00, 0x00 };
	uint8_t small_block[ 10 ]     = { 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0xef, 0xbe, 0x00, 0x00 };
	uint8_t non_beef[ 12 ]        = { 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	uint8_t oob_block[ 10 ]       = { 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0xef, 0xbe, 0x00, 0x00 };
	uint8_t bad_0004_block[ 22 ]  = {
		0x16, 0x00, 0x03, 0x00, 0x04, 0x00, 0xef, 0xbe,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x14, 0x00, 0x00, 0x00, 0x14, 0x00 };
	uint32_t signatures[ 15 ]     = {
		0xbeef0000UL, 0xbeef0001UL, 0xbeef0003UL, 0xbeef0004UL, 0xbeef0005UL,
		0xbeef0006UL, 0xbeef000aUL, 0xbeef0013UL, 0xbeef0014UL, 0xbeef0019UL,
		0xbeef0025UL, 0xbeef0026UL, 0xbeef0027UL, 0xbeef0029UL, 0xbeef9999UL };
	uint8_t block_data[ 64 ];
	libcerror_error_t *error                   = NULL;
	libfwsi_extension_block_t *extension_block = NULL;
	int result                                 = 0;
	int sig_index                              = 0;

	/* Initialize test
	 */
	result = libfwsi_extension_block_initialize(
	          &extension_block,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	/* Test zero-size terminator block
	 */
	result = libfwsi_extension_block_copy_from_byte_stream(
	          (libfwsi_internal_extension_block_t *) extension_block,
	          zero_data,
	          2,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	/* Test unsupported data cases (returns 0)
	 */
	result = libfwsi_extension_block_copy_from_byte_stream(
	          (libfwsi_internal_extension_block_t *) extension_block,
	          zero_data,
	          1,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	result = libfwsi_extension_block_copy_from_byte_stream(
	          (libfwsi_internal_extension_block_t *) extension_block,
	          small_block,
	          10,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	result = libfwsi_extension_block_copy_from_byte_stream(
	          (libfwsi_internal_extension_block_t *) extension_block,
	          non_beef,
	          7,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	result = libfwsi_extension_block_copy_from_byte_stream(
	          (libfwsi_internal_extension_block_t *) extension_block,
	          non_beef,
	          12,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	result = libfwsi_extension_block_copy_from_byte_stream(
	          NULL,
	          zero_data,
	          2,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );
	libcerror_error_free(
	 &error );

	result = libfwsi_extension_block_copy_from_byte_stream(
	          (libfwsi_internal_extension_block_t *) extension_block,
	          NULL,
	          2,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );
	libcerror_error_free(
	 &error );

	result = libfwsi_extension_block_copy_from_byte_stream(
	          (libfwsi_internal_extension_block_t *) extension_block,
	          zero_data,
	          (size_t) SSIZE_MAX + 1,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );
	libcerror_error_free(
	 &error );

	result = libfwsi_extension_block_copy_from_byte_stream(
	          (libfwsi_internal_extension_block_t *) extension_block,
	          oob_block,
	          10,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );
	libcerror_error_free(
	 &error );

	result = libfwsi_extension_block_copy_from_byte_stream(
	          (libfwsi_internal_extension_block_t *) extension_block,
	          bad_0004_block,
	          22,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );
	libcerror_error_free(
	 &error );

	result = libfwsi_internal_extension_block_free(
	          (libfwsi_internal_extension_block_t **) &extension_block,
	          &error );
	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	/* Test all supported and unknown 0xbeefxxxx signatures
	 */
	for( sig_index = 0;
	     sig_index < 15;
	     sig_index++ )
	{
		memory_set(
		 block_data,
		 0,
		 sizeof( block_data ) );
		block_data[ 0 ] = 64;
		block_data[ 1 ] = 0;
		block_data[ 2 ] = 7;
		block_data[ 3 ] = 0;
		block_data[ 4 ] = (uint8_t) ( signatures[ sig_index ] & 0xff );
		block_data[ 5 ] = (uint8_t) ( ( signatures[ sig_index ] >> 8 ) & 0xff );
		block_data[ 6 ] = (uint8_t) ( ( signatures[ sig_index ] >> 16 ) & 0xff );
		block_data[ 7 ] = (uint8_t) ( ( signatures[ sig_index ] >> 24 ) & 0xff );

		result = libfwsi_extension_block_initialize(
		          &extension_block,
		          &error );
		FWSI_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		result = libfwsi_extension_block_copy_from_byte_stream(
		          (libfwsi_internal_extension_block_t *) extension_block,
		          block_data,
		          64,
		          LIBFWSI_CODEPAGE_WINDOWS_1252,
		          &error );
		FWSI_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );
		FWSI_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libfwsi_internal_extension_block_free(
		          (libfwsi_internal_extension_block_t **) &extension_block,
		          &error );
		FWSI_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );
	}
	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( extension_block != NULL )
	{
		libfwsi_internal_extension_block_free(
		 (libfwsi_internal_extension_block_t **) &extension_block,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwsi_extension_block_get_signature function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_extension_block_get_signature(
     void )
{
	libcerror_error_t *error                   = NULL;
	libfwsi_extension_block_t *extension_block = NULL;
	uint32_t signature                         = 0;
	int result                                 = 0;
	int signature_is_set                       = 0;

	/* Initialize test
	 */
	result = libfwsi_extension_block_initialize(
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

	/* Test regular cases
	 */
	result = libfwsi_extension_block_get_signature(
	          extension_block,
	          &signature,
	          &error );

	FWSI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	signature_is_set = result;

	/* Test error cases
	 */
	result = libfwsi_extension_block_get_signature(
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

	if( signature_is_set != 0 )
	{
		result = libfwsi_extension_block_get_signature(
		          extension_block,
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
	/* Clean up
	 */
	result = libfwsi_internal_extension_block_free(
	          (libfwsi_internal_extension_block_t **) &extension_block,
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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( extension_block != NULL )
	{
		libfwsi_internal_extension_block_free(
		 (libfwsi_internal_extension_block_t **) &extension_block,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwsi_extension_block_get_data_size function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_extension_block_get_data_size(
     void )
{
	libcerror_error_t *error                   = NULL;
	libfwsi_extension_block_t *extension_block = NULL;
	size_t data_size                           = 0;
	int data_size_is_set                       = 0;
	int result                                 = 0;

	/* Initialize test
	 */
	result = libfwsi_extension_block_initialize(
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

	/* Test regular cases
	 */
	result = libfwsi_extension_block_get_data_size(
	          extension_block,
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
	result = libfwsi_extension_block_get_data_size(
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
		result = libfwsi_extension_block_get_data_size(
		          extension_block,
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
	/* Clean up
	 */
	result = libfwsi_internal_extension_block_free(
	          (libfwsi_internal_extension_block_t **) &extension_block,
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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( extension_block != NULL )
	{
		libfwsi_internal_extension_block_free(
		 (libfwsi_internal_extension_block_t **) &extension_block,
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
	 "libfwsi_extension_block_initialize",
	 fwsi_test_extension_block_initialize );

#endif /* defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT ) */

	FWSI_TEST_RUN(
	 "libfwsi_extension_block_free",
	 fwsi_test_extension_block_free );

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )

	FWSI_TEST_RUN(
	 "libfwsi_extension_block_copy_from_byte_stream",
	 fwsi_test_extension_block_copy_from_byte_stream );

	FWSI_TEST_RUN(
	 "libfwsi_extension_block_get_signature",
	 fwsi_test_extension_block_get_signature );

	FWSI_TEST_RUN(
	 "libfwsi_extension_block_get_data_size",
	 fwsi_test_extension_block_get_data_size );

#endif /* defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

