/*
 * Control panel category (shell item) functions
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

#include "libfwsi_control_panel_category.h"
#include "libfwsi_control_panel_category_values.h"
#include "libfwsi_definitions.h"
#include "libfwsi_item.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libuna.h"

/* Retrieves the control panel category identifier
 * Returns 1 if successful or -1 on error
 */
int libfwsi_control_panel_category_get_identifier(
     libfwsi_item_t *control_panel_category,
     uint32_t *identifier,
     libcerror_error_t **error )
{
	libfwsi_control_panel_category_values_t *control_panel_category_values = NULL;
	libfwsi_internal_item_t *internal_item                                 = NULL;
	static char *function                                                  = "libfwsi_control_panel_category_get_identifier";

	if( control_panel_category == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid control panel category.",
		 function );

		return( -1 );
	}
	internal_item = (libfwsi_internal_item_t *) control_panel_category;

	if( internal_item->type != LIBFWSI_ITEM_TYPE_CONTROL_PANEL_CATEGORY )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported item type.",
		 function );

		return( -1 );
	}
	if( internal_item->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid file entry - missing value.",
		 function );

		return( -1 );
	}
	control_panel_category_values = (libfwsi_control_panel_category_values_t *) internal_item->value;

	if( identifier == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid identifier.",
		 function );

		return( -1 );
	}
	*identifier = control_panel_category_values->identifier;

	return( 1 );
}

