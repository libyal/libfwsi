/*
 * Library item list copy from byte stream testing program
 *
 * Copyright (C) 2010-2015, Joachim Metz <joachim.metz@gmail.com>
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
#include <memory.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include <stdio.h>

#include "fwsi_test_libcerror.h"
#include "fwsi_test_libcfile.h"
#include "fwsi_test_libcstring.h"
#include "fwsi_test_libfwsi.h"

/* Define to make cfile_test_read generate verbose output
#define FWSI_TEST_ITEM_LIST_COPY_FROM_BYTE_STREAM_VERBOSE
 */

/* The main program
 */
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
int wmain( int argc, wchar_t * const argv[] )
#else
int main( int argc, char * const argv[] )
#endif
{
	libcerror_error_t *error             = NULL;
	libcfile_file_t *file                = NULL;
	libfwsi_item_list_t *shell_item_list = NULL;
	uint8_t *file_data                   = NULL;
	size64_t file_size                   = 0;

	if( argc < 2 )
	{
		fprintf(
		 stderr,
		 "Missing filename.\n" );

		return( EXIT_FAILURE );
	}
#if defined( HAVE_DEBUG_OUTPUT ) && defined( FWSI_TEST_ITEM_LIST_COPY_FROM_BYTE_STREAM_VERBOSE )
	libfwsi_notify_set_verbose(
	 1 );
	libfwsi_notify_set_file(
	 stderr,
	 NULL );
#endif
	/* Read test data from file
	 */
	if( libcfile_file_initialize(
	     &file,
	     &error ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to create file.\n" );

		goto on_error;
	}
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
	if( libcfile_file_open_wide(
	     file,
	     argv[ 1 ],
	     LIBCFILE_OPEN_READ,
	     &error ) != 1 )
#else
	if( libcfile_file_open(
	     file,
	     argv[ 1 ],
	     LIBCFILE_OPEN_READ,
	     &error ) != 1 )
#endif
	{
		fprintf(
		 stderr,
		 "Unable to open file.\n" );

		goto on_error;
	}
	if( libcfile_file_get_size(
	     file,
	     &file_size,
	     &error ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to retrieve file size.\n" );

		goto on_error;
	}
	if( file_size > ( 4 * 1024 * 1024 ) )
	{
		fprintf(
		 stderr,
		 "File size exceeds maximum.\n" );

		goto on_error;
	}
	file_data = (uint8_t *) memory_allocate(
	                         sizeof( uint8_t ) * (size_t) file_size );

	if( file_data == NULL )
	{
		fprintf(
		 stderr,
		 "Unable to create file data.\n" );

		goto on_error;
	}
	if( libcfile_file_read_buffer(
	     file,
	     file_data,
	     (size_t) file_size,
	     &error ) == -1 )
	{
		fprintf(
		 stderr,
		 "Unable to read file.\n" );

		goto on_error;
	}
	if( libcfile_file_close(
	     file,
	     &error ) != 0 )
	{
		fprintf(
		 stderr,
		 "Unable to close file.\n" );

		goto on_error;
	}
	if( libcfile_file_free(
	     &file,
	     &error ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to free file.\n" );

		goto on_error;
	}
	if( libfwsi_item_list_initialize(
	     &shell_item_list,
	     &error ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to create item list.\n" );

		goto on_error;
	}
	if( libfwsi_item_list_copy_from_byte_stream(
	     shell_item_list,
	     file_data,
	     file_size,
	     LIBFWSI_CODEPAGE_WINDOWS_1252,
	     &error ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to copy item list from byte stream.\n" );

		goto on_error;
	}
	if( libfwsi_item_list_free(
	     &shell_item_list,
	     &error ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to free item list.\n" );

		goto on_error;
	}
	memory_free(
	 file_data );

	return( EXIT_SUCCESS );

on_error:
	if( error != NULL )
	{
		libcerror_error_backtrace_fprint(
		 error,
		 stderr );
		libcerror_error_free(
		 &error );
	}
	if( shell_item_list != NULL )
	{
		libfwsi_item_list_free(
		 &shell_item_list,
		 NULL );
	}
	if( file_data != NULL )
	{
		memory_free(
		 file_data );
	}
	if( file != NULL )
	{
		libcfile_file_close(
		 file,
		 NULL );
		libcfile_file_free(
		 &file,
		 NULL );
	}
	return( EXIT_FAILURE );
}

