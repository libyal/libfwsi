/*
 * Library compressed_folder type test program
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

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
#include "../libfwsi/libfwsi_compressed_folder_values.h"
#endif

/* Windows XP compressed folder item with name "test" */
uint8_t fwsi_test_compressed_folder_data1[ 80 ] = {
	0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x31, 0x00, 0x2f, 0x00, 0x30, 0x00,
	0x31, 0x00, 0x2f, 0x00, 0x30, 0x00, 0x30, 0x00, 0x20, 0x00, 0x20, 0x00, 0x31, 0x00, 0x32, 0x00,
	0x3a, 0x00, 0x30, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x74, 0x00, 0x65, 0x00, 0x73, 0x00, 0x74, 0x00, 0x00, 0x00, 0x00, 0x00 };

uint8_t fwsi_test_compressed_folder_other_item_data1[ 20 ] = {
	0x14, 0x00, 0x1f, 0x50, 0xe0, 0x4f, 0xd0, 0x20, 0xea, 0x3a, 0x69, 0x10, 0xa2, 0xd8, 0x08, 0x00,
	0x2b, 0x30, 0x30, 0x9d };

/* Tests the libfwsi_compressed_folder_get_utf8_name_size function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_compressed_folder_get_utf8_name_size(
     libfwsi_item_t *compressed_folder,
     libfwsi_item_t *other_item )
{
	libcerror_error_t *error = NULL;
	size_t utf8_string_size  = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfwsi_compressed_folder_get_utf8_name_size(
	          compressed_folder,
	          &utf8_string_size,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_size",
	 utf8_string_size,
	 (size_t) 5 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwsi_compressed_folder_get_utf8_name_size(
	          NULL,
	          &utf8_string_size,
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

	result = libfwsi_compressed_folder_get_utf8_name_size(
	          other_item,
	          &utf8_string_size,
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

	result = libfwsi_compressed_folder_get_utf8_name_size(
	          compressed_folder,
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
	result = libfwsi_compressed_folder_values_get_utf8_name_size(
	          NULL,
	          &utf8_string_size,
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

/* Tests the libfwsi_compressed_folder_get_utf8_name function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_compressed_folder_get_utf8_name(
     libfwsi_item_t *compressed_folder,
     libfwsi_item_t *other_item )
{
	uint8_t utf8_string[ 16 ];

	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfwsi_compressed_folder_get_utf8_name(
	          compressed_folder,
	          utf8_string,
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
	          utf8_string,
	          "test",
	          5 );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	result = libfwsi_compressed_folder_get_utf8_name(
	          NULL,
	          utf8_string,
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

	result = libfwsi_compressed_folder_get_utf8_name(
	          other_item,
	          utf8_string,
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

	result = libfwsi_compressed_folder_get_utf8_name(
	          compressed_folder,
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

	result = libfwsi_compressed_folder_get_utf8_name(
	          compressed_folder,
	          utf8_string,
	          2,
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
	result = libfwsi_compressed_folder_values_get_utf8_name(
	          NULL,
	          utf8_string,
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

/* Tests the libfwsi_compressed_folder_get_utf16_name_size function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_compressed_folder_get_utf16_name_size(
     libfwsi_item_t *compressed_folder,
     libfwsi_item_t *other_item )
{
	libcerror_error_t *error = NULL;
	size_t utf16_string_size = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfwsi_compressed_folder_get_utf16_name_size(
	          compressed_folder,
	          &utf16_string_size,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_size",
	 utf16_string_size,
	 (size_t) 5 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwsi_compressed_folder_get_utf16_name_size(
	          NULL,
	          &utf16_string_size,
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

	result = libfwsi_compressed_folder_get_utf16_name_size(
	          other_item,
	          &utf16_string_size,
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

	result = libfwsi_compressed_folder_get_utf16_name_size(
	          compressed_folder,
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
	result = libfwsi_compressed_folder_values_get_utf16_name_size(
	          NULL,
	          &utf16_string_size,
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

/* Tests the libfwsi_compressed_folder_get_utf16_name function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_compressed_folder_get_utf16_name(
     libfwsi_item_t *compressed_folder,
     libfwsi_item_t *other_item )
{
	uint16_t expected_utf16_string[ 5 ] = { 't', 'e', 's', 't', 0 };
	uint16_t utf16_string[ 16 ];

	libcerror_error_t *error            = NULL;
	int result                          = 0;

	/* Test regular cases
	 */
	result = libfwsi_compressed_folder_get_utf16_name(
	          compressed_folder,
	          utf16_string,
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
	          utf16_string,
	          expected_utf16_string,
	          sizeof( uint16_t ) * 5 );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	result = libfwsi_compressed_folder_get_utf16_name(
	          NULL,
	          utf16_string,
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

	result = libfwsi_compressed_folder_get_utf16_name(
	          other_item,
	          utf16_string,
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

	result = libfwsi_compressed_folder_get_utf16_name(
	          compressed_folder,
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

	result = libfwsi_compressed_folder_get_utf16_name(
	          compressed_folder,
	          utf16_string,
	          2,
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
	result = libfwsi_compressed_folder_values_get_utf16_name(
	          NULL,
	          utf16_string,
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
	libcerror_error_t *error          = NULL;
	libfwsi_item_t *compressed_folder = NULL;
	libfwsi_item_t *other_item        = NULL;
	int result                        = 0;
#endif

	FWSI_TEST_UNREFERENCED_PARAMETER( argc )
	FWSI_TEST_UNREFERENCED_PARAMETER( argv )

#if !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 )

	result = libfwsi_item_initialize(
	          &compressed_folder,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "compressed_folder",
	 compressed_folder );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwsi_item_copy_from_byte_stream(
	          compressed_folder,
	          fwsi_test_compressed_folder_data1,
	          80,
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
	          fwsi_test_compressed_folder_other_item_data1,
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
	 "libfwsi_compressed_folder_get_utf8_name_size",
	 fwsi_test_compressed_folder_get_utf8_name_size,
	 compressed_folder,
	 other_item );

	FWSI_TEST_RUN_WITH_ARGS(
	 "libfwsi_compressed_folder_get_utf8_name",
	 fwsi_test_compressed_folder_get_utf8_name,
	 compressed_folder,
	 other_item );

	FWSI_TEST_RUN_WITH_ARGS(
	 "libfwsi_compressed_folder_get_utf16_name_size",
	 fwsi_test_compressed_folder_get_utf16_name_size,
	 compressed_folder,
	 other_item );

	FWSI_TEST_RUN_WITH_ARGS(
	 "libfwsi_compressed_folder_get_utf16_name",
	 fwsi_test_compressed_folder_get_utf16_name,
	 compressed_folder,
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
	          &compressed_folder,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "compressed_folder",
	 compressed_folder );

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
	if( compressed_folder != NULL )
	{
		libfwsi_item_free(
		 &compressed_folder,
		 NULL );
	}
#endif
	return( EXIT_FAILURE );
}
