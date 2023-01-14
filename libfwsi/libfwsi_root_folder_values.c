/*
 * Root folder (shell item) values functions
 *
 * Copyright (C) 2010-2023, Joachim Metz <joachim.metz@gmail.com>
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
#include <byte_stream.h>
#include <memory.h>
#include <types.h>

#include "libfwsi_debug.h"
#include "libfwsi_definitions.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"
#include "libfwsi_libfguid.h"
#include "libfwsi_root_folder_values.h"
#include "libfwsi_shell_folder_identifier.h"
#include "libfwsi_unused.h"

/* Creates root folder values
 * Make sure the value root_folder_values is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_root_folder_values_initialize(
     libfwsi_root_folder_values_t **root_folder_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_root_folder_values_initialize";

	if( root_folder_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid root folder values.",
		 function );

		return( -1 );
	}
	if( *root_folder_values != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid root folder values value already set.",
		 function );

		return( -1 );
	}
	*root_folder_values = memory_allocate_structure(
	                       libfwsi_root_folder_values_t );

	if( *root_folder_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create root folder values.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *root_folder_values,
	     0,
	     sizeof( libfwsi_root_folder_values_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear root folder values.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *root_folder_values != NULL )
	{
		memory_free(
		 *root_folder_values );

		*root_folder_values = NULL;
	}
	return( -1 );
}

/* Frees root folder values
 * Returns 1 if successful or -1 on error
 */
int libfwsi_root_folder_values_free(
     libfwsi_root_folder_values_t **root_folder_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_root_folder_values_free";

	if( root_folder_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid root folder values.",
		 function );

		return( -1 );
	}
	if( *root_folder_values != NULL )
	{
		memory_free(
		 *root_folder_values );

		*root_folder_values = NULL;
	}
	return( 1 );
}

/* Reads the root folder values
 * Returns 1 if successful, 0 if not supported or -1 on error
 */
int libfwsi_root_folder_values_read_data(
     libfwsi_root_folder_values_t *root_folder_values,
     const uint8_t *data,
     size_t data_size,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_root_folder_values_read_data";

	if( root_folder_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid root folder values.",
		 function );

		return( -1 );
	}
	if( data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid data.",
		 function );

		return( -1 );
	}
	if( data_size > (size_t) SSIZE_MAX )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: data size exceeds maximum.",
		 function );

		return( -1 );
	}
	/* Do not try to parse unsupported data sizes
	 */
	if( data_size < 20 )
	{
		return( 0 );
	}
	/* Do not try to parse unknown class type indicators
	 */
	if( data[ 2 ] != 0x1f )
	{
		return( 0 );
	}
	if( memory_copy(
	     root_folder_values->shell_folder_identifier,
	     &( data[ 4 ] ),
	     16 ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_COPY_FAILED,
		 "%s: unable to copy shell folder identifier.",
		 function );

		return( -1 );
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: sort order\t\t\t: 0x%02" PRIx8 "\n",
		 function,
		 data[ 3 ] );

		if( libfwsi_debug_print_guid_value(
		     function,
		     "shell folder identifier\t\t",
		     root_folder_values->shell_folder_identifier,
		     16,
		     LIBFGUID_ENDIAN_LITTLE,
		     LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_PRINT_FAILED,
			 "%s: unable to print GUID value.",
			 function );

			return( -1 );
		}
		libcnotify_printf(
		 "%s: shell folder name\t\t\t: %s\n",
		 function,
		 libfwsi_shell_folder_identifier_get_name(
		  root_folder_values->shell_folder_identifier ) );

		libcnotify_printf(
		 "\n" );
	}
#endif
	return( 1 );
}

