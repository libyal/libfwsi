/*
 * Library control_panel_item_identifier type test program
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
#include <narrow_string.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fwsi_test_libfwsi.h"
#include "fwsi_test_macros.h"
#include "fwsi_test_unused.h"

#include "../libfwsi/libfwsi_control_panel_item_identifier.h"

#if defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT )

int fwsi_test_control_panel_item_identifier_get_name(
     void )
{
	uint8_t system_identifier[ 16 ] = {
		0xe4, 0xc0, 0x06, 0xbb, 0x93, 0xd2, 0x75, 0x4f, 0x8a, 0x90, 0xcb, 0x05, 0xb6, 0x47, 0x7e, 0xee };
	uint8_t unknown_identifier[ 16 ] = {
		0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10 };

	const char *name = NULL;
	int result       = 0;

	name = libfwsi_control_panel_item_identifier_get_name(
	        system_identifier );
	FWSI_TEST_ASSERT_IS_NOT_NULL( "name", name );
	result = narrow_string_compare( name, "System", 7 );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );

	name = libfwsi_control_panel_item_identifier_get_name(
	        unknown_identifier );
	FWSI_TEST_ASSERT_IS_NOT_NULL( "name", name );
	result = narrow_string_compare( name, "Unknown", 8 );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );

	name = libfwsi_control_panel_item_identifier_get_name(
	        NULL );
	FWSI_TEST_ASSERT_IS_NOT_NULL( "name", name );
	result = narrow_string_compare( name, "Invalid control panel item identifier", 38 );
	FWSI_TEST_ASSERT_EQUAL_INT( "result", result, 0 );

	return( 1 );

on_error:
	return( 0 );
}

#endif /* defined( __GNUC__ ) && !defined( LIBFWSI_DLL_IMPORT ) */

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
	 "libfwsi_control_panel_item_identifier_get_name",
	 fwsi_test_control_panel_item_identifier_get_name );

#endif

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}
