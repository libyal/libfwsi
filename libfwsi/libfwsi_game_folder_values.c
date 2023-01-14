/*
 * Game folder (shell item) values functions
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
#include "libfwsi_game_folder_values.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"
#include "libfwsi_libfguid.h"

/* Creates game folder values
 * Make sure the value game_folder_values is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_game_folder_values_initialize(
     libfwsi_game_folder_values_t **game_folder_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_game_folder_values_initialize";

	if( game_folder_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid game folder values.",
		 function );

		return( -1 );
	}
	if( *game_folder_values != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid game folder values value already set.",
		 function );

		return( -1 );
	}
	*game_folder_values = memory_allocate_structure(
	                       libfwsi_game_folder_values_t );

	if( *game_folder_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create game folder values.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *game_folder_values,
	     0,
	     sizeof( libfwsi_game_folder_values_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear game folder values.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *game_folder_values != NULL )
	{
		memory_free(
		 *game_folder_values );

		*game_folder_values = NULL;
	}
	return( -1 );
}

/* Frees game folder values
 * Returns 1 if successful or -1 on error
 */
int libfwsi_game_folder_values_free(
     libfwsi_game_folder_values_t **game_folder_values,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_game_folder_values_free";

	if( game_folder_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid game folder values.",
		 function );

		return( -1 );
	}
	if( *game_folder_values != NULL )
	{
		memory_free(
		 *game_folder_values );

		*game_folder_values = NULL;
	}
	return( 1 );
}

/* Reads the game folder values
 * Returns 1 if successful, 0 if not supported or -1 on error
 */
int libfwsi_game_folder_values_read_data(
     libfwsi_game_folder_values_t *game_folder_values,
     const uint8_t *data,
     size_t data_size,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_game_folder_values_read_data";

#if defined( HAVE_DEBUG_OUTPUT )
	uint64_t value_64bit  = 0;
#endif

	if( game_folder_values == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid game folder values.",
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
	if( data_size < 32 )
	{
		return( 0 );
	}
	/* Do not try to parse unsupported shell item signatures
	 */
	if( memory_compare(
	     &( data[ 4 ] ),
	     "GFSI",
	     4 ) != 0 )
	{
		return( 0 );
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: class type indicator\t\t\t: 0x%02" PRIx8 "\n",
		 function,
		 data[ 2 ] );

		libcnotify_printf(
		 "%s: unknown1\t\t\t\t: 0x%02" PRIx8 "\n",
		 function,
		 data[ 3 ] );

		libcnotify_printf(
		 "%s: signature\t\t\t\t: %c%c%c%c\n",
		 function,
		 data[ 4 ],
		 data[ 5 ],
		 data[ 6 ],
		 data[ 7 ] );

		if( libfwsi_debug_print_guid_value(
		     function,
		     "class identifier\t\t\t",
		     &( data[ 8 ] ),
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
		byte_stream_copy_to_uint64_little_endian(
		 &( data[ 24 ] ),
		 value_64bit );
		libcnotify_printf(
		 "%s: unknown2\t\t\t\t: 0x%08" PRIx64 "\n",
		 function,
		 value_64bit );

		libcnotify_printf(
		 "\n" );
	}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

	return( 1 );
}

