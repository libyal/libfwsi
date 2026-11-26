/*
 * Library control_panel_category type test program
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

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
#include "../libfwsi/libfwsi_item.h"
#endif

uint8_t fwsi_test_control_panel_category_data1[ 12 ] = {
	0x0c, 0x00, 0x00, 0x00, 0x84, 0x21, 0xde, 0x39, 0x05, 0x00, 0x00, 0x00 };

uint8_t fwsi_test_control_panel_category_other_item_data1[ 20 ] = {
	0x14, 0x00, 0x1f, 0x50, 0xe0, 0x4f, 0xd0, 0x20, 0xea, 0x3a, 0x69, 0x10, 0xa2, 0xd8, 0x08, 0x00,
	0x2b, 0x30, 0x30, 0x9d };

/* Tests the libfwsi_control_panel_category_get_identifier function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_control_panel_category_get_identifier(
     libfwsi_item_t *control_panel_category,
     libfwsi_item_t *other_item )
{
	libcerror_error_t *error   = NULL;
	uint32_t identifier        = 0;
	int result                 = 0;

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
	libfwsi_item_t *empty_item = NULL;
#endif

	/* Test regular cases
	 */
	result = libfwsi_control_panel_category_get_identifier(
	          control_panel_category,
	          &identifier,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_EQUAL_UINT32(
	 "identifier",
	 identifier,
	 (uint32_t) 5 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwsi_control_panel_category_get_identifier(
	          NULL,
	          &identifier,
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

	result = libfwsi_control_panel_category_get_identifier(
	          other_item,
	          &identifier,
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

	result = libfwsi_control_panel_category_get_identifier(
	          control_panel_category,
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

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "empty_item",
	 empty_item );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	( (libfwsi_internal_item_t *) empty_item )->type = LIBFWSI_ITEM_TYPE_CONTROL_PANEL_CATEGORY;

	result = libfwsi_control_panel_category_get_identifier(
	          empty_item,
	          &identifier,
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

	FWSI_TEST_ASSERT_IS_NULL(
	 "empty_item",
	 empty_item );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );
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
	libcerror_error_t *error               = NULL;
	libfwsi_item_t *control_panel_category = NULL;
	libfwsi_item_t *other_item             = NULL;
	int result                             = 0;
#endif

	FWSI_TEST_UNREFERENCED_PARAMETER( argc )
	FWSI_TEST_UNREFERENCED_PARAMETER( argv )

#if !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 )

	result = libfwsi_item_initialize(
	          &control_panel_category,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NOT_NULL(
	 "control_panel_category",
	 control_panel_category );

	FWSI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwsi_item_copy_from_byte_stream(
	          control_panel_category,
	          fwsi_test_control_panel_category_data1,
	          12,
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
	          fwsi_test_control_panel_category_other_item_data1,
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
	 "libfwsi_control_panel_category_get_identifier",
	 fwsi_test_control_panel_category_get_identifier,
	 control_panel_category,
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
	          &control_panel_category,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWSI_TEST_ASSERT_IS_NULL(
	 "control_panel_category",
	 control_panel_category );

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
	if( control_panel_category != NULL )
	{
		libfwsi_item_free(
		 &control_panel_category,
		 NULL );
	}
#endif
	return( EXIT_FAILURE );
}
