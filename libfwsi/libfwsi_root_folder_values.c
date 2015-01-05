/*
 * Root folder (shell item) values functions
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
#include <byte_stream.h>
#include <memory.h>
#include <types.h>

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
 * Returns the number of bytes read if successful, 0 if not able to read or -1 on error
 */
ssize_t libfwsi_root_folder_values_read(
         libfwsi_root_folder_values_t *root_folder_values,
         const uint8_t *shell_item_data,
         size_t shell_item_data_size,
         libcerror_error_t **error )
{
	static char *function       = "libfwsi_root_folder_values_read";

#if defined( HAVE_DEBUG_OUTPUT )
        libcstring_system_character_t guid_string[ 48 ];

        libfguid_identifier_t *guid = NULL;
	int result                  = 0;
#endif

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
	if( shell_item_data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid shell item data.",
		 function );

		return( -1 );
	}
	if( shell_item_data_size > (size_t) SSIZE_MAX )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: shell item data size exceeds maximum.",
		 function );

		return( -1 );
	}
	/* Do not try to parse unsupported shell item data sizes
	 */
	if( shell_item_data_size < 20 )
	{
		return( 0 );
	}
	/* Do not try to parse unknown class type indicators
	 */
	if( shell_item_data[ 2 ] != 0x1f )
	{
		return( 0 );
	}
	if( memory_copy(
	     root_folder_values->shell_folder_identifier,
	     &( shell_item_data[ 4 ] ),
	     16 ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_COPY_FAILED,
		 "%s: unable to copy shell folder identifier.",
		 function );

		goto on_error;
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: sort order\t\t\t\t: 0x%02" PRIx8 "\n",
		 function,
		 shell_item_data[ 3 ] );

		if( libfguid_identifier_initialize(
		     &guid,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
			 "%s: unable to create GUID.",
			 function );

			goto on_error;
		}
		if( libfguid_identifier_copy_from_byte_stream(
		     guid,
		     root_folder_values->shell_folder_identifier,
		     16,
		     LIBFGUID_ENDIAN_LITTLE,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
			 "%s: unable to copy byte stream to GUID.",
			 function );

			goto on_error;
		}
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
		result = libfguid_identifier_copy_to_utf16_string(
			  guid,
			  (uint16_t *) guid_string,
			  48,
			  LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
			  error );
#else
		result = libfguid_identifier_copy_to_utf8_string(
			  guid,
			  (uint8_t *) guid_string,
			  48,
			  LIBFGUID_STRING_FORMAT_FLAG_USE_UPPER_CASE | LIBFGUID_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES,
			  error );
#endif
		if( result != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
			 "%s: unable to copy GUID to string.",
			 function );

			goto on_error;
		}
		libcnotify_printf(
		 "%s: shell folder identifier\t\t: %" PRIs_LIBCSTRING_SYSTEM "\n",
		 function,
		 guid_string );
		libcnotify_printf(
		 "%s: shell folder name\t\t\t: %s\n",
		 function,
		 libfwsi_shell_folder_identifier_get_name(
		  root_folder_values->shell_folder_identifier ) );

		if( libfguid_identifier_free(
		     &guid,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
			 "%s: unable to free GUID.",
			 function );

			goto on_error;
		}
		libcnotify_printf(
		 "\n" );
	}
#endif
	return( 20 );

on_error:
#if defined( HAVE_DEBUG_OUTPUT )
	if( guid != NULL )
	{
		libfguid_identifier_free(
		 &guid,
		 NULL );
	}
#endif
	return( -1 );
}

