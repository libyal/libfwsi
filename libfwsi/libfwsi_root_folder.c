/*
 * Root folder (shell item) functions
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
#include <memory.h>
#include <types.h>

#include "libfwsi_libcerror.h"
#include "libfwsi_item.h"
#include "libfwsi_root_folder.h"
#include "libfwsi_root_folder_values.h"

/* Retrieves the shell folder identifier
 * The identifier is a GUID and is 16 bytes of size
 * Returns 1 if successful or -1 on error
 */
int libfwsi_root_folder_get_shell_folder_identifier(
     libfwsi_item_t *root_folder,
     uint8_t *guid_data,
     size_t guid_data_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item           = NULL;
	libfwsi_root_folder_values_t *root_folder_values = NULL;
	static char *function                            = "libfwsi_root_folder_get_shell_folder_identifier";

	if( root_folder == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid root folder.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) root_folder;

	if( internal_item->class_type != 0x1f )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported class type.",
		 function );

		return( -1 );
	}
	if( internal_item->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid root folder - missing value.",
		 function );

		return( -1 );
	}
	root_folder_values = (libfwsi_root_folder_values_t *) internal_item->value;

	if( guid_data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid GUID data.",
		 function );

		return( -1 );
	}
	if( guid_data_size < 16 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_TOO_SMALL,
		 "%s: GUID data size too small.",
		 function );

		return( -1 );
	}
	if( memory_copy(
	     guid_data,
	     root_folder_values->shell_folder_identifier,
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
	return( 1 );
}

