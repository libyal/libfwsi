/*
 * Control panel category (shell item) values functions
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
#include <byte_stream.h>
#include <memory.h>
#include <types.h>

#include "libfwsi_control_panel_category_values.h"
#include "libfwsi_debug.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"

/* Creates control panel category values
 * Make sure the value control_panel_category_values is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_control_panel_category_values_initialize(
     libfwsi_control_panel_category_values_t **control_panel_category_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_control_panel_category_values_initialize";

	if( control_panel_category_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid control panel category values.",
		 function );

		return( -1 );
	}
	if( *control_panel_category_values != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid control panel category values value already set.",
		 function );

		return( -1 );
	}
	*control_panel_category_values = memory_allocate_structure(
	                                  libfwsi_control_panel_category_values_t );

	if( *control_panel_category_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create control panel category values.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *control_panel_category_values,
	     0,
	     sizeof( libfwsi_control_panel_category_values_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear control panel category values.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *control_panel_category_values != NULL )
	{
		memory_free(
		 *control_panel_category_values );

		*control_panel_category_values = NULL;
	}
	return( -1 );
}

/* Frees control panel category values
 * Returns 1 if successful or -1 on error
 */
int libfwsi_control_panel_category_values_free(
     libfwsi_control_panel_category_values_t **control_panel_category_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_control_panel_category_values_free";

	if( control_panel_category_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid control panel category values.",
		 function );

		return( -1 );
	}
	if( *control_panel_category_values != NULL )
	{
		memory_free(
		 *control_panel_category_values );

		*control_panel_category_values = NULL;
	}
	return( 1 );
}

/* Reads the control panel category values
 * Returns 1 if successful, 0 if not supported or -1 on error
 */
int libfwsi_control_panel_category_values_read_data(
     libfwsi_control_panel_category_values_t *control_panel_category_values,
     const uint8_t *data,
     size_t data_size,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_control_panel_category_values_read_data";
        uint32_t signature    = 0;

	if( control_panel_category_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid control panel category values.",
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
	if( data_size < 12 )
	{
		return( 0 );
	}
	/* Do not try to parse unsupported shell item signatures
	 */
	byte_stream_copy_to_uint32_little_endian(
	 &( data[ 4 ] ),
	 signature );

	if( signature != 0x39de2184UL )
	{
		return( 0 );
	}
	byte_stream_copy_to_uint32_little_endian(
	 &( data[ 8 ] ),
	 control_panel_category_values->identifier );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: class type indicator\t: 0x%02" PRIx8 "\n",
		 function,
		 data[ 2 ] );

		libcnotify_printf(
		 "%s: unknown1\t\t: 0x%02" PRIx8 "\n",
		 function,
		 data[ 3 ] );

		libcnotify_printf(
		 "%s: signature\t\t: 0x%08" PRIx32 "\n",
		 function,
		 signature );

		libcnotify_printf(
		 "%s: identifier\t\t: %" PRIu32 " (%s)\n",
		 function,
		 control_panel_category_values->identifier,
		 libfwsi_debug_print_control_panel_category(
		  control_panel_category_values->identifier ) );

		libcnotify_printf(
		 "\n" );
	}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

	return( 1 );
}

