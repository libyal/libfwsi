/*
 * Library file_entry_extension type test program
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
#include "../libfwsi/libfwsi_extension_block.h"
#endif

/* File entry item with version 9 0xbeef0004 extension block (file_reference, UTF-16 long_name & localized_name) */
uint8_t fwsi_test_file_entry_extension_item_data1[ 120 ] = {
	0x78, 0x00, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0xae, 0x46, 0x24, 0xb1, 0x11, 0x00, 0x55, 0x73,
	0x65, 0x72, 0x73, 0x00, 0x64, 0x00, 0x09, 0x00, 0x04, 0x00, 0xef, 0xbe, 0x99, 0x46, 0xf2, 0x14,
	0xae, 0x46, 0x24, 0xb1, 0x2e, 0x00, 0x00, 0x00, 0x58, 0x57, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x13,
	0x29, 0x01, 0x55, 0x00, 0x73, 0x00, 0x65, 0x00, 0x72, 0x00, 0x73, 0x00, 0x00, 0x00, 0x40, 0x00,
	0x73, 0x00, 0x68, 0x00, 0x65, 0x00, 0x6c, 0x00, 0x6c, 0x00, 0x33, 0x00, 0x32, 0x00, 0x2e, 0x00,
	0x64, 0x00, 0x6c, 0x00, 0x6c, 0x00, 0x2c, 0x00, 0x2d, 0x00, 0x32, 0x00, 0x31, 0x00, 0x38, 0x00,
	0x31, 0x00, 0x33, 0x00, 0x00, 0x00, 0x14, 0x00 };

/* File entry item with version 3 0xbeef0004 extension block (no file_reference, UTF-16 long_name="long", ASCII localized_name="loc") */
uint8_t fwsi_test_file_entry_extension_item_data2[ 56 ] = {
	0x38, 0x00, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0xae, 0x46, 0x24, 0xb1, 0x10, 0x00, 0x74, 0x65,
	0x73, 0x74, 0x00, 0x00, 0x24, 0x00, 0x03, 0x00, 0x04, 0x00, 0xef, 0xbe, 0x99, 0x46, 0xf2, 0x14,
	0xae, 0x46, 0x24, 0xb1, 0x14, 0x00, 0x1e, 0x00, 0x6c, 0x00, 0x6f, 0x00, 0x6e, 0x00, 0x67, 0x00,
	0x00, 0x00, 0x6c, 0x6f, 0x63, 0x00, 0x14, 0x00 };

/* File entry item with version 7 0xbeef0004 extension block (file_reference=0, no long_name, no localized_name) */
uint8_t fwsi_test_file_entry_extension_item_data3[ 60 ] = {
	0x3c, 0x00, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0xae, 0x46, 0x24, 0xb1, 0x10, 0x00, 0x74, 0x65,
	0x73, 0x74, 0x00, 0x00, 0x28, 0x00, 0x07, 0x00, 0x04, 0x00, 0xef, 0xbe, 0x99, 0x46, 0xf2, 0x14,
	0xae, 0x46, 0x24, 0xb1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00 };

/* File entry item with 0xbeef0000 extension block (wrong signature) */
uint8_t fwsi_test_file_entry_extension_other_item_data1[ 34 ] = {
	0x22, 0x00, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0xae, 0x46, 0x24, 0xb1, 0x10, 0x00, 0x74, 0x65,
	0x73, 0x74, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0xef, 0xbe, 0x00, 0x00, 0x00, 0x00,
	0x14, 0x00 };

/* Tests creation_time, access_time, and file_reference getters
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_file_entry_extension_get_metadata(
     libfwsi_extension_block_t *ext_v9,
     libfwsi_extension_block_t *ext_v3,
     libfwsi_extension_block_t *ext_v7_empty,
     libfwsi_extension_block_t *other_ext )
{
	libcerror_error_t *error           = NULL;
	uint64_t file_reference            = 0;
	uint32_t access_time               = 0;
	uint32_t creation_time             = 0;
	int result                         = 0;

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
	libfwsi_extension_block_t *empty_ext = NULL;
#endif

	/* Creation time
	 */
	result = libfwsi_file_entry_extension_get_creation_time( ext_v9, &creation_time, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_EQUAL_UINT32( "creation_time", creation_time, (uint32_t) 0x14f24699UL );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_file_entry_extension_get_creation_time( NULL, &creation_time, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_creation_time( other_ext, &creation_time, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_creation_time( ext_v9, NULL, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	/* Access time
	 */
	result = libfwsi_file_entry_extension_get_access_time( ext_v9, &access_time, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_EQUAL_UINT32( "access_time", access_time, (uint32_t) 0xb12446aeUL );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_file_entry_extension_get_access_time( NULL, &access_time, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_access_time( other_ext, &access_time, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_access_time( ext_v9, NULL, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	/* File reference
	 */
	result = libfwsi_file_entry_extension_get_file_reference( ext_v9, &file_reference, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_EQUAL_UINT64( "file_reference", file_reference, (uint64_t) 0x0001000000015758ULL );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_file_entry_extension_get_file_reference( ext_v3, &file_reference, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_file_entry_extension_get_file_reference( ext_v7_empty, &file_reference, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_file_entry_extension_get_file_reference( NULL, &file_reference, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_file_reference( other_ext, &file_reference, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_file_reference( ext_v9, NULL, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
	result = libfwsi_extension_block_initialize( &empty_ext, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	( (libfwsi_internal_extension_block_t *) empty_ext )->signature = 0xbeef0004UL;

	result = libfwsi_file_entry_extension_get_creation_time( empty_ext, &creation_time, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_access_time( empty_ext, &access_time, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_file_reference( empty_ext, &file_reference, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_internal_extension_block_free( (libfwsi_internal_extension_block_t **) &empty_ext, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
#endif /* defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free( &error );
	}
#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
	if( empty_ext != NULL )
	{
		libfwsi_internal_extension_block_free( (libfwsi_internal_extension_block_t **) &empty_ext, NULL );
	}
#endif
	return( 0 );
}

/* Tests long_name getters
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_file_entry_extension_get_long_name(
     libfwsi_extension_block_t *ext_v9,
     libfwsi_extension_block_t *ext_v7_empty,
     libfwsi_extension_block_t *other_ext )
{
	uint16_t expected_utf16[ 6 ] = { 'U', 's', 'e', 'r', 's', 0 };
	uint16_t utf16_string[ 32 ];
	uint8_t utf8_string[ 32 ];

	libcerror_error_t *error             = NULL;
	size_t utf16_string_size             = 0;
	size_t utf8_string_size              = 0;
	int result                           = 0;

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
	libfwsi_extension_block_t *empty_ext = NULL;
#endif

	/* Regular cases (present & absent)
	 */
	result = libfwsi_file_entry_extension_get_utf8_long_name_size( ext_v9, &utf8_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_EQUAL_SIZE( "utf8_string_size", utf8_string_size, (size_t) 6 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_file_entry_extension_get_utf8_long_name_size( ext_v7_empty, &utf8_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_file_entry_extension_get_utf8_long_name( ext_v9, utf8_string, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );
	FWSI_TEST_ASSERT_EQUAL_INT( "compare", memory_compare( utf8_string, "Users", 6 ), 0 );

	result = libfwsi_file_entry_extension_get_utf8_long_name( ext_v7_empty, utf8_string, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_file_entry_extension_get_utf16_long_name_size( ext_v9, &utf16_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_EQUAL_SIZE( "utf16_string_size", utf16_string_size, (size_t) 6 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_file_entry_extension_get_utf16_long_name_size( ext_v7_empty, &utf16_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_file_entry_extension_get_utf16_long_name( ext_v9, utf16_string, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );
	FWSI_TEST_ASSERT_EQUAL_INT( "compare", memory_compare( utf16_string, expected_utf16, sizeof( uint16_t ) * 6 ), 0 );

	result = libfwsi_file_entry_extension_get_utf16_long_name( ext_v7_empty, utf16_string, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	/* Error cases
	 */
	result = libfwsi_file_entry_extension_get_utf8_long_name_size( NULL, &utf8_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf8_long_name_size( other_ext, &utf8_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf8_long_name_size( ext_v9, NULL, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf8_long_name( NULL, utf8_string, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf8_long_name( other_ext, utf8_string, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf8_long_name( ext_v9, NULL, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf8_long_name( ext_v9, utf8_string, 2, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf16_long_name_size( NULL, &utf16_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf16_long_name_size( other_ext, &utf16_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf16_long_name_size( ext_v9, NULL, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf16_long_name( NULL, utf16_string, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf16_long_name( other_ext, utf16_string, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf16_long_name( ext_v9, NULL, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf16_long_name( ext_v9, utf16_string, 2, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
	result = libfwsi_extension_block_initialize( &empty_ext, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	( (libfwsi_internal_extension_block_t *) empty_ext )->signature = 0xbeef0004UL;

	result = libfwsi_file_entry_extension_get_utf8_long_name_size( empty_ext, &utf8_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf8_long_name( empty_ext, utf8_string, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf16_long_name_size( empty_ext, &utf16_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf16_long_name( empty_ext, utf16_string, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_internal_extension_block_free( (libfwsi_internal_extension_block_t **) &empty_ext, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
#endif /* defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free( &error );
	}
#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
	if( empty_ext != NULL )
	{
		libfwsi_internal_extension_block_free( (libfwsi_internal_extension_block_t **) &empty_ext, NULL );
	}
#endif
	return( 0 );
}

/* Tests localized_name getters
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_file_entry_extension_get_localized_name(
     libfwsi_extension_block_t *ext_v9,
     libfwsi_extension_block_t *ext_v3,
     libfwsi_extension_block_t *ext_v7_empty,
     libfwsi_extension_block_t *other_ext )
{
	uint16_t expected_utf16_v3[ 4 ] = { 'l', 'o', 'c', 0 };
	uint16_t utf16_string[ 32 ];
	uint8_t utf8_string[ 32 ];

	libcerror_error_t *error             = NULL;
	size_t utf16_string_size             = 0;
	size_t utf8_string_size              = 0;
	int result                           = 0;

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
	libfwsi_extension_block_t *empty_ext = NULL;
	uint16_t saved_version               = 0;
#endif

	/* Regular cases: version 9 (UTF-16), version 3 (ASCII), and absent
	 */
	result = libfwsi_file_entry_extension_get_utf8_localized_name_size( ext_v9, &utf8_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_EQUAL_SIZE( "utf8_string_size", utf8_string_size, (size_t) 20 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_file_entry_extension_get_utf8_localized_name( ext_v9, utf8_string, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );
	FWSI_TEST_ASSERT_EQUAL_INT( "compare", memory_compare( utf8_string, "@shell32.dll,-21813", 20 ), 0 );

	result = libfwsi_file_entry_extension_get_utf16_localized_name_size( ext_v9, &utf16_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_EQUAL_SIZE( "utf16_string_size", utf16_string_size, (size_t) 20 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_file_entry_extension_get_utf16_localized_name( ext_v9, utf16_string, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	/* Version 3 (ASCII localized_name) */
	result = libfwsi_file_entry_extension_get_utf8_localized_name_size( ext_v3, &utf8_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_EQUAL_SIZE( "utf8_string_size", utf8_string_size, (size_t) 4 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_file_entry_extension_get_utf8_localized_name( ext_v3, utf8_string, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );
	FWSI_TEST_ASSERT_EQUAL_INT( "compare", memory_compare( utf8_string, "loc", 4 ), 0 );

	result = libfwsi_file_entry_extension_get_utf16_localized_name_size( ext_v3, &utf16_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_EQUAL_SIZE( "utf16_string_size", utf16_string_size, (size_t) 4 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_file_entry_extension_get_utf16_localized_name( ext_v3, utf16_string, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );
	FWSI_TEST_ASSERT_EQUAL_INT( "compare", memory_compare( utf16_string, expected_utf16_v3, sizeof( uint16_t ) * 4 ), 0 );

	/* Absent localized_name */
	result = libfwsi_file_entry_extension_get_utf8_localized_name_size( ext_v7_empty, &utf8_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_file_entry_extension_get_utf8_localized_name( ext_v7_empty, utf8_string, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_file_entry_extension_get_utf16_localized_name_size( ext_v7_empty, &utf16_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	result = libfwsi_file_entry_extension_get_utf16_localized_name( ext_v7_empty, utf16_string, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );
	FWSI_TEST_ASSERT_IS_NULL( "error", error );

	/* Error cases
	 */
	result = libfwsi_file_entry_extension_get_utf8_localized_name_size( NULL, &utf8_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf8_localized_name_size( other_ext, &utf8_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf8_localized_name_size( ext_v9, NULL, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf8_localized_name( NULL, utf8_string, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf8_localized_name( other_ext, utf8_string, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf8_localized_name( ext_v9, NULL, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf8_localized_name( ext_v9, utf8_string, 2, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf16_localized_name_size( NULL, &utf16_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf16_localized_name_size( other_ext, &utf16_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf16_localized_name_size( ext_v9, NULL, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf16_localized_name( NULL, utf16_string, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf16_localized_name( other_ext, utf16_string, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf16_localized_name( ext_v9, NULL, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf16_localized_name( ext_v9, utf16_string, 2, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
	/* Version < 3 returns 0 for localized_name */
	saved_version = ( (libfwsi_internal_extension_block_t *) ext_v3 )->version;
	( (libfwsi_internal_extension_block_t *) ext_v3 )->version = 2;

	result = libfwsi_file_entry_extension_get_utf8_localized_name_size( ext_v3, &utf8_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );

	result = libfwsi_file_entry_extension_get_utf8_localized_name( ext_v3, utf8_string, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );

	result = libfwsi_file_entry_extension_get_utf16_localized_name_size( ext_v3, &utf16_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );

	result = libfwsi_file_entry_extension_get_utf16_localized_name( ext_v3, utf16_string, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );

	( (libfwsi_internal_extension_block_t *) ext_v3 )->version = saved_version;

	/* Missing value */
	result = libfwsi_extension_block_initialize( &empty_ext, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	( (libfwsi_internal_extension_block_t *) empty_ext )->signature = 0xbeef0004UL;

	result = libfwsi_file_entry_extension_get_utf8_localized_name_size( empty_ext, &utf8_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf8_localized_name( empty_ext, utf8_string, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf16_localized_name_size( empty_ext, &utf16_string_size, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_file_entry_extension_get_utf16_localized_name( empty_ext, utf16_string, 32, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, -1 );
	libcerror_error_free( &error );

	result = libfwsi_internal_extension_block_free( (libfwsi_internal_extension_block_t **) &empty_ext, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
#endif /* defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free( &error );
	}
#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )
	if( empty_ext != NULL )
	{
		libfwsi_internal_extension_block_free( (libfwsi_internal_extension_block_t **) &empty_ext, NULL );
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
	libcerror_error_t *error                = NULL;
	libfwsi_extension_block_t *ext_v9       = NULL;
	libfwsi_extension_block_t *ext_v3       = NULL;
	libfwsi_extension_block_t *ext_v7_empty = NULL;
	libfwsi_extension_block_t *other_ext    = NULL;
	libfwsi_item_t *item1                   = NULL;
	libfwsi_item_t *item2                   = NULL;
	libfwsi_item_t *item3                   = NULL;
	libfwsi_item_t *other_item              = NULL;
	int result                              = 0;
#endif

	FWSI_TEST_UNREFERENCED_PARAMETER( argc )
	FWSI_TEST_UNREFERENCED_PARAMETER( argv )

#if !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 )

	result = libfwsi_item_initialize( &item1, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	result = libfwsi_item_copy_from_byte_stream( item1, fwsi_test_file_entry_extension_item_data1, 120, LIBFWSI_CODEPAGE_WINDOWS_1252, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	result = libfwsi_item_get_extension_block( item1, 0, &ext_v9, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

	result = libfwsi_item_initialize( &item2, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	result = libfwsi_item_copy_from_byte_stream( item2, fwsi_test_file_entry_extension_item_data2, 56, LIBFWSI_CODEPAGE_WINDOWS_1252, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	result = libfwsi_item_get_extension_block( item2, 0, &ext_v3, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

	result = libfwsi_item_initialize( &item3, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	result = libfwsi_item_copy_from_byte_stream( item3, fwsi_test_file_entry_extension_item_data3, 60, LIBFWSI_CODEPAGE_WINDOWS_1252, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	result = libfwsi_item_get_extension_block( item3, 0, &ext_v7_empty, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

	result = libfwsi_item_initialize( &other_item, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	result = libfwsi_item_copy_from_byte_stream( other_item, fwsi_test_file_entry_extension_other_item_data1, 34, LIBFWSI_CODEPAGE_WINDOWS_1252, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	result = libfwsi_item_get_extension_block( other_item, 0, &other_ext, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

	FWSI_TEST_RUN_WITH_ARGS(
	 "libfwsi_file_entry_extension_get_metadata",
	 fwsi_test_file_entry_extension_get_metadata,
	 ext_v9,
	 ext_v3,
	 ext_v7_empty,
	 other_ext );

	FWSI_TEST_RUN_WITH_ARGS(
	 "libfwsi_file_entry_extension_get_long_name",
	 fwsi_test_file_entry_extension_get_long_name,
	 ext_v9,
	 ext_v7_empty,
	 other_ext );

	FWSI_TEST_RUN_WITH_ARGS(
	 "libfwsi_file_entry_extension_get_localized_name",
	 fwsi_test_file_entry_extension_get_localized_name,
	 ext_v9,
	 ext_v3,
	 ext_v7_empty,
	 other_ext );

	result = libfwsi_extension_block_free( &other_ext, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	result = libfwsi_extension_block_free( &ext_v7_empty, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	result = libfwsi_extension_block_free( &ext_v3, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	result = libfwsi_extension_block_free( &ext_v9, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

	result = libfwsi_item_free( &other_item, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	result = libfwsi_item_free( &item3, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	result = libfwsi_item_free( &item2, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );
	result = libfwsi_item_free( &item1, &error );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 1 );

#endif /* !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 ) */

	return( EXIT_SUCCESS );

on_error:
#if !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 )
	if( error != NULL )
	{
		libcerror_error_free( &error );
	}
	if( other_ext != NULL )
	{
		libfwsi_extension_block_free( &other_ext, NULL );
	}
	if( ext_v7_empty != NULL )
	{
		libfwsi_extension_block_free( &ext_v7_empty, NULL );
	}
	if( ext_v3 != NULL )
	{
		libfwsi_extension_block_free( &ext_v3, NULL );
	}
	if( ext_v9 != NULL )
	{
		libfwsi_extension_block_free( &ext_v9, NULL );
	}
	if( other_item != NULL )
	{
		libfwsi_item_free( &other_item, NULL );
	}
	if( item3 != NULL )
	{
		libfwsi_item_free( &item3, NULL );
	}
	if( item2 != NULL )
	{
		libfwsi_item_free( &item2, NULL );
	}
	if( item1 != NULL )
	{
		libfwsi_item_free( &item1, NULL );
	}
#endif
	return( EXIT_FAILURE );
}
