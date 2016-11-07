/*
 * Library item type testing program
 *
 * Copyright (C) 2010-2016, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
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

/* Tests the libfwsi_item_initialize function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_item_initialize(
     void )
{
	libcerror_error_t *error = NULL;
	libfwsi_item_t *item      = NULL;
	int result               = 0;

	/* Test libfwsi_item_initialize
	 */
	result = libfwsi_item_initialize(
	          &item,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWSI_TEST_ASSERT_IS_NOT_NULL(
         "item",
         item );

        FWSI_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfwsi_item_free(
	          &item,
	          &error );

	FWSI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FWSI_TEST_ASSERT_IS_NULL(
         "item",
         item );

        FWSI_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfwsi_item_initialize(
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

	item = (libfwsi_item_t *) 0x12345678UL;

	result = libfwsi_item_initialize(
	          &item,
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

	item = NULL;

#if defined( HAVE_FWSI_TEST_MEMORY )

	/* Test libfwsi_item_initialize with malloc failing
	 */
	fwsi_test_malloc_attempts_before_fail = 0;

	result = libfwsi_item_initialize(
	          &item,
	          &error );

	if( fwsi_test_malloc_attempts_before_fail != -1 )
	{
		fwsi_test_malloc_attempts_before_fail = -1;

		if( item != NULL )
		{
			libfwsi_item_free(
			 &item,
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
		 "item",
		 item );

		FWSI_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Test libfwsi_item_initialize with memset failing
	 */
	fwsi_test_memset_attempts_before_fail = 0;

	result = libfwsi_item_initialize(
	          &item,
	          &error );

	if( fwsi_test_memset_attempts_before_fail != -1 )
	{
		fwsi_test_memset_attempts_before_fail = -1;

		if( item != NULL )
		{
			libfwsi_item_free(
			 &item,
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
		 "item",
		 item );

		FWSI_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_FWSI_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( item != NULL )
	{
		libfwsi_item_free(
		 &item,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwsi_item_free function
 * Returns 1 if successful or 0 if not
 */
int fwsi_test_item_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfwsi_item_free(
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

	FWSI_TEST_RUN(
	 "libfwsi_item_initialize",
	 fwsi_test_item_initialize );

	FWSI_TEST_RUN(
	 "libfwsi_item_free",
	 fwsi_test_item_free );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

