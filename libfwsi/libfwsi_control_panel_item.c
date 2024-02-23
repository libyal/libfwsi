/*
 * Control panel item (shell item) functions
 *
 * Copyright (C) 2010-2024, Joachim Metz <joachim.metz@gmail.com>
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

#include "libfwsi_control_panel_item.h"
#include "libfwsi_control_panel_item_values.h"
#include "libfwsi_definitions.h"
#include "libfwsi_item.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libuna.h"

/* Retrieves the identifier
 * The identifier is a GUID and is 16 bytes of size
 * Returns 1 if successful or -1 on error
 */
int libfwsi_control_panel_item_get_identifier(
     libfwsi_item_t *control_panel_item,
     uint8_t *guid_data,
     size_t guid_data_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item = NULL;
	static char *function                  = "libfwsi_control_panel_item_get_identifier";

	if( control_panel_item == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid control panel item.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) control_panel_item;

	if( internal_item->type != LIBFWSI_ITEM_TYPE_CONTROL_PANEL_ITEM )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported item type.",
		 function );

		return( -1 );
	}
	if( libfwsi_control_panel_item_values_get_identifier(
	     (libfwsi_control_panel_item_values_t *) internal_item->value,
	     guid_data,
	     guid_data_size,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve identifier.",
		 function );

		return( -1 );
	}
	return( 1 );
}

