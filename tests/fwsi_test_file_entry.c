/*
 * Library file_entry type test program
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
#include "../libfwsi/libfwsi_item.h"
#endif

/* ASCII file entry (0x31) with file_size=0x1234, mod_time=0xb12446ae, attrs=0x0011, name="Users" */
uint8_t fwsi_test_file_entry_data1[ 20 ] = {
	0x14, 0x00, 0x31, 0x00, 0x34, 0x12, 0x00, 0x00, 0xae, 0x46, 0x24, 0xb1, 0x11, 0x00, 0x55, 0x73,
	0x65, 0x72, 0x73, 0x00 };

/* Unicode file entry (0x35) with file_size=0x5678, mod_time=0xb12446ae, attrs=0x0020, name=L"file" */
uint8_t fwsi_test_file_entry_data2[ 24 ] = {
	0x18, 0x00, 0x35, 0x00, 0x78, 0x56, 0x00, 0x00, 0xae, 0x46, 0x24, 0xb1, 0x20, 0x00, 0x66, 0x00,
	0x69, 0x00, 0x6c, 0x00, 0x65, 0x00, 0x00, 0x00 };

uint8_t fwsi_test_file_entry_other_item_data1[ 20 ] = {
	0x14, 0x00, 0x1f, 0x50, 0xe0, 0x4f, 0xd0, 0x20, 0xea, 0x3a, 0x69, 0x10, 0xa2, 0xd8, 0x08, 0x00,
	0x2b, 0x30, 0x30, 0x9d };

/* Tests the libfwsi_file_entry_get_file_size function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_file_entry_get_file_size(
     libfwsi_item_t *file_entry,
     libfwsi_item_t *other_item )
{
	libcerror_error_t *error   = NULL;
	uint32_t file_size         = 0;
	int result                 = 0;

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
	libfwsi_item_t *empty_item = NULL;
#endif

	/* Test regular cases
	 */
	result = libfwsi_file_entry_get_file_size(
	          file_entry,
	          &file_size,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_EQUAL_UINT32(
	 "file_size",
	 file_size,
	 (uint32_t) 0x1234 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwsi_file_entry_get_file_size(
	          NULL,
	          &file_size,
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

	result = libfwsi_file_entry_get_file_size(
	          other_item,
	          &file_size,
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

	result = libfwsi_file_entry_get_file_size(
	          file_entry,
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
	result = libfwsi_item_initialize(
	          &empty_item,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	( (libfwsi_internal_item_t *) empty_item )->type = LIBFWSI_ITEM_TYPE_FILE_ENTRY;

	result = libfwsi_file_entry_get_file_size(
	          empty_item,
	          &file_size,
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

	result = libfwsi_item_free(
	          &empty_item,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );
#endif /* defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
	if( empty_item != NULL )
	{
		libfwsi_item_free(
		 &empty_item,
		 NULL );
	}
#endif
	return( 0 );
}

/* Tests the libfwsi_file_entry_get_modification_time function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_file_entry_get_modification_time(
     libfwsi_item_t *file_entry,
     libfwsi_item_t *other_item )
{
	libcerror_error_t *error   = NULL;
	uint32_t fat_date_time     = 0;
	int result                 = 0;

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
	libfwsi_item_t *empty_item = NULL;
#endif

	/* Test regular cases
	 */
	result = libfwsi_file_entry_get_modification_time(
	          file_entry,
	          &fat_date_time,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_EQUAL_UINT32(
	 "fat_date_time",
	 fat_date_time,
	 (uint32_t) 0xb12446aeUL );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwsi_file_entry_get_modification_time(
	          NULL,
	          &fat_date_time,
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

	result = libfwsi_file_entry_get_modification_time(
	          other_item,
	          &fat_date_time,
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

	result = libfwsi_file_entry_get_modification_time(
	          file_entry,
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
	result = libfwsi_item_initialize(
	          &empty_item,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	( (libfwsi_internal_item_t *) empty_item )->type = LIBFWSI_ITEM_TYPE_FILE_ENTRY;

	result = libfwsi_file_entry_get_modification_time(
	          empty_item,
	          &fat_date_time,
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

	result = libfwsi_item_free(
	          &empty_item,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );
#endif /* defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
	if( empty_item != NULL )
	{
		libfwsi_item_free(
		 &empty_item,
		 NULL );
	}
#endif
	return( 0 );
}

/* Tests the libfwsi_file_entry_get_file_attribute_flags function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_file_entry_get_file_attribute_flags(
     libfwsi_item_t *file_entry,
     libfwsi_item_t *other_item )
{
	libcerror_error_t *error      = NULL;
	uint32_t file_attribute_flags = 0;
	int result                    = 0;

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
	libfwsi_item_t *empty_item    = NULL;
#endif

	/* Test regular cases
	 */
	result = libfwsi_file_entry_get_file_attribute_flags(
	          file_entry,
	          &file_attribute_flags,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_EQUAL_UINT32(
	 "file_attribute_flags",
	 file_attribute_flags,
	 (uint32_t) 0x0011 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwsi_file_entry_get_file_attribute_flags(
	          NULL,
	          &file_attribute_flags,
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

	result = libfwsi_file_entry_get_file_attribute_flags(
	          other_item,
	          &file_attribute_flags,
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

	result = libfwsi_file_entry_get_file_attribute_flags(
	          file_entry,
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
	result = libfwsi_item_initialize(
	          &empty_item,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	( (libfwsi_internal_item_t *) empty_item )->type = LIBFWSI_ITEM_TYPE_FILE_ENTRY;

	result = libfwsi_file_entry_get_file_attribute_flags(
	          empty_item,
	          &file_attribute_flags,
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

	result = libfwsi_item_free(
	          &empty_item,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );
#endif /* defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
	if( empty_item != NULL )
	{
		libfwsi_item_free(
		 &empty_item,
		 NULL );
	}
#endif
	return( 0 );
}

/* Tests the libfwsi_file_entry_get_utf8_name_size function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_file_entry_get_utf8_name_size(
     libfwsi_item_t *file_entry1,
     libfwsi_item_t *file_entry2,
     libfwsi_item_t *other_item )
{
	libcerror_error_t *error = NULL;
	size_t utf8_string_size  = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfwsi_file_entry_get_utf8_name_size(
	          file_entry1,
	          &utf8_string_size,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_EQUAL_SIZE(
	 "utf8_string_size",
	 utf8_string_size,
	 (size_t) 6 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwsi_file_entry_get_utf8_name_size(
	          file_entry2,
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
	result = libfwsi_file_entry_get_utf8_name_size(
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

	result = libfwsi_file_entry_get_utf8_name_size(
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

	result = libfwsi_file_entry_get_utf8_name_size(
	          file_entry1,
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

/* Tests the libfwsi_file_entry_get_utf8_name function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_file_entry_get_utf8_name(
     libfwsi_item_t *file_entry1,
     libfwsi_item_t *file_entry2,
     libfwsi_item_t *other_item )
{
	uint8_t utf8_string[ 16 ];

	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfwsi_file_entry_get_utf8_name(
	          file_entry1,
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
	          "Users",
	          6 );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	result = libfwsi_file_entry_get_utf8_name(
	          file_entry2,
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
	          "file",
	          5 );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	result = libfwsi_file_entry_get_utf8_name(
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

	result = libfwsi_file_entry_get_utf8_name(
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

	result = libfwsi_file_entry_get_utf8_name(
	          file_entry1,
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

	result = libfwsi_file_entry_get_utf8_name(
	          file_entry1,
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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfwsi_file_entry_get_utf16_name_size function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_file_entry_get_utf16_name_size(
     libfwsi_item_t *file_entry1,
     libfwsi_item_t *file_entry2,
     libfwsi_item_t *other_item )
{
	libcerror_error_t *error = NULL;
	size_t utf16_string_size = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfwsi_file_entry_get_utf16_name_size(
	          file_entry1,
	          &utf16_string_size,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_EQUAL_SIZE(
	 "utf16_string_size",
	 utf16_string_size,
	 (size_t) 6 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwsi_file_entry_get_utf16_name_size(
	          file_entry2,
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
	result = libfwsi_file_entry_get_utf16_name_size(
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

	result = libfwsi_file_entry_get_utf16_name_size(
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

	result = libfwsi_file_entry_get_utf16_name_size(
	          file_entry1,
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

/* Tests the libfwsi_file_entry_get_utf16_name function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_file_entry_get_utf16_name(
     libfwsi_item_t *file_entry1,
     libfwsi_item_t *file_entry2,
     libfwsi_item_t *other_item )
{
	uint16_t expected_utf16_string1[ 6 ] = { 'U', 's', 'e', 'r', 's', 0 };
	uint16_t expected_utf16_string2[ 5 ] = { 'f', 'i', 'l', 'e', 0 };
	uint16_t utf16_string[ 16 ];

	libcerror_error_t *error             = NULL;
	int result                           = 0;

	/* Test regular cases
	 */
	result = libfwsi_file_entry_get_utf16_name(
	          file_entry1,
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
	          expected_utf16_string1,
	          sizeof( uint16_t ) * 6 );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	result = libfwsi_file_entry_get_utf16_name(
	          file_entry2,
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
	          expected_utf16_string2,
	          sizeof( uint16_t ) * 5 );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	/* Test error cases
	 */
	result = libfwsi_file_entry_get_utf16_name(
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

	result = libfwsi_file_entry_get_utf16_name(
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

	result = libfwsi_file_entry_get_utf16_name(
	          file_entry1,
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

	result = libfwsi_file_entry_get_utf16_name(
	          file_entry1,
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
	libcerror_error_t *error    = NULL;
	libfwsi_item_t *file_entry1 = NULL;
	libfwsi_item_t *file_entry2 = NULL;
	libfwsi_item_t *other_item  = NULL;
	int result                  = 0;
#endif

	FWSI_TEST_UNREFERENCED_PARAMETER( argc )
	FWSI_TEST_UNREFERENCED_PARAMETER( argv )

#if !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 )

	result = libfwsi_item_initialize(
	          &file_entry1,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = libfwsi_item_copy_from_byte_stream(
	          file_entry1,
	          fwsi_test_file_entry_data1,
	          20,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = libfwsi_item_initialize(
	          &file_entry2,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = libfwsi_item_copy_from_byte_stream(
	          file_entry2,
	          fwsi_test_file_entry_data2,
	          24,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = libfwsi_item_initialize(
	          &other_item,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = libfwsi_item_copy_from_byte_stream(
	          other_item,
	          fwsi_test_file_entry_other_item_data1,
	          20,
	          LIBFWSI_CODEPAGE_WINDOWS_1252,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_RUN_WITH_ARGS(
	 "libfwsi_file_entry_get_file_size",
	 fwsi_test_file_entry_get_file_size,
	 file_entry1,
	 other_item );

	FWSI_TEST_RUN_WITH_ARGS(
	 "libfwsi_file_entry_get_modification_time",
	 fwsi_test_file_entry_get_modification_time,
	 file_entry1,
	 other_item );

	FWSI_TEST_RUN_WITH_ARGS(
	 "libfwsi_file_entry_get_file_attribute_flags",
	 fwsi_test_file_entry_get_file_attribute_flags,
	 file_entry1,
	 other_item );

	FWSI_TEST_RUN_WITH_ARGS(
	 "libfwsi_file_entry_get_utf8_name_size",
	 fwsi_test_file_entry_get_utf8_name_size,
	 file_entry1,
	 file_entry2,
	 other_item );

	FWSI_TEST_RUN_WITH_ARGS(
	 "libfwsi_file_entry_get_utf8_name",
	 fwsi_test_file_entry_get_utf8_name,
	 file_entry1,
	 file_entry2,
	 other_item );

	FWSI_TEST_RUN_WITH_ARGS(
	 "libfwsi_file_entry_get_utf16_name_size",
	 fwsi_test_file_entry_get_utf16_name_size,
	 file_entry1,
	 file_entry2,
	 other_item );

	FWSI_TEST_RUN_WITH_ARGS(
	 "libfwsi_file_entry_get_utf16_name",
	 fwsi_test_file_entry_get_utf16_name,
	 file_entry1,
	 file_entry2,
	 other_item );

	result = libfwsi_item_free(
	          &other_item,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = libfwsi_item_free(
	          &file_entry2,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	result = libfwsi_item_free(
	          &file_entry1,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

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
	if( file_entry2 != NULL )
	{
		libfwsi_item_free(
		 &file_entry2,
		 NULL );
	}
	if( file_entry1 != NULL )
	{
		libfwsi_item_free(
		 &file_entry1,
		 NULL );
	}
#endif
	return( EXIT_FAILURE );
}
