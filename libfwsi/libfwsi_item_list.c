/*
 * Windows Shell Item list functions
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

#include "libfwsi_codepage.h"
#include "libfwsi_item.h"
#include "libfwsi_item_list.h"
#include "libfwsi_libcdata.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"
#include "libfwsi_types.h"

/* Creates an item list
 * Make sure the value X is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_item_list_initialize(
     libfwsi_item_list_t **item_list,
     libcerror_error_t **error )
{
	libfwsi_internal_item_list_t *internal_item_list = NULL;
	static char *function                            = "libfwsi_item_list_initialize";

	if( item_list == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item list.",
		 function );

		return( -1 );
	}
	if( *item_list != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid item list value already set.",
		 function );

		return( -1 );
	}
	internal_item_list = memory_allocate_structure(
	                      libfwsi_internal_item_list_t );

	if( internal_item_list == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create item list.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     internal_item_list,
	     0,
	     sizeof( libfwsi_internal_item_list_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear item list.",
		 function );

		goto on_error;
	}
	if( libcdata_array_initialize(
	     &( internal_item_list->items_array ),
	     0,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
		 "%s: unable to create items array.",
		 function );

		goto on_error;
	}
	*item_list = (libfwsi_item_list_t *) internal_item_list;

	return( 1 );

on_error:
	if( internal_item_list != NULL )
	{
		memory_free(
		 internal_item_list );
	}
	return( -1 );
}

/* Frees an item list
 * Returns 1 if successful or -1 on error
 */
int libfwsi_item_list_free(
     libfwsi_item_list_t **item_list,
     libcerror_error_t **error )
{
	libfwsi_internal_item_list_t *internal_item_list = NULL;
	static char *function                            = "libfwsi_item_list_free";
	int result                                       = 1;

	if( item_list == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item list.",
		 function );

		return( -1 );
	}
	if( *item_list != NULL )
	{
		internal_item_list = (libfwsi_internal_item_list_t *) *item_list;
		*item_list         = NULL;

		if( libcdata_array_free(
		     &( internal_item_list->items_array ),
		     (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_internal_item_free,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
			 "%s: unable to free the items array.",
			 function );

			result = -1;
		}
		memory_free(
		 internal_item_list );
	}
	return( result );
}

/* Copies a shell item list from a byte stream
 * Returns 1 if successful or -1 on error
 */
int libfwsi_item_list_copy_from_byte_stream(
     libfwsi_item_list_t *item_list,
     const uint8_t *byte_stream,
     size_t byte_stream_size,
     int ascii_codepage,
     libcerror_error_t **error )
{
	libfwsi_internal_item_t *internal_item           = NULL;
	libfwsi_internal_item_list_t *internal_item_list = NULL;
	libfwsi_item_t *parent_item                      = NULL;
	static char *function                            = "libfwsi_item_list_copy_from_byte_stream";
	uint16_t shell_item_size                         = 0;
	int item_list_index                              = 0;
	int shell_item_index                             = 0;

	if( item_list == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item list.",
		 function );

		return( -1 );
	}
	internal_item_list = (libfwsi_internal_item_list_t *) item_list;

	if( byte_stream == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid byte stream.",
		 function );

		return( -1 );
	}
	if( byte_stream_size < 2 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_TOO_SMALL,
		 "%s: byte stream too small.",
		 function );

		return( -1 );
	}
	if( byte_stream_size > (size_t) SSIZE_MAX )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: byte stream size exceeds maximum.",
		 function );

		return( -1 );
	}
	if( ( ascii_codepage != LIBFWSI_CODEPAGE_ASCII )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_874 )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_932 )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_936 )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_949 )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_950 )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_1250 )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_1251 )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_1252 )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_1253 )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_1254 )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_1255 )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_1256 )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_1257 )
	 && ( ascii_codepage != LIBFWSI_CODEPAGE_WINDOWS_1258 ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported ASCII codepage.",
		 function );

		return( -1 );
	}
	while( byte_stream_size >= 2 )
	{
		byte_stream_copy_to_uint16_little_endian(
		 byte_stream,
		 shell_item_size );

#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			libcnotify_printf(
			 "%s: shell item: %d size\t\t: %" PRIu16 "\n",
			 function,
			 shell_item_index,
			 shell_item_size );
		}
#endif
		if( shell_item_size > byte_stream_size )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
			 LIBCERROR_ARGUMENT_ERROR_VALUE_OUT_OF_BOUNDS,
			 "%s: invalid shell item size value out of bounds.",
			 function );

			goto on_error;
		}
		if( shell_item_size == 0 )
		{
			byte_stream                   += 2;
			byte_stream_size              -= 2;
			internal_item_list->data_size += 2;

			break;
		}
		if( libfwsi_internal_item_initialize(
		     &internal_item,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
			 "%s: unable to create shell item.",
			 function );

			goto on_error;
		}
		if( libfwsi_item_set_parent_item(
		     (libfwsi_item_t *) internal_item,
		     parent_item,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
			 "%s: unable to set parent shell item.",
			 function );

			goto on_error;
		}
		if( internal_item == NULL )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
			 "%s: missing shell item.",
			 function );

			goto on_error;
		}
		internal_item->is_managed = 1;

		if( libfwsi_item_copy_from_byte_stream(
		     (libfwsi_item_t *) internal_item,
		     byte_stream,
		     byte_stream_size,
		     ascii_codepage,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
			 "%s: unable to copy byte stream to shell item.",
			 function );

			goto on_error;
		}
		byte_stream                   += shell_item_size;
		byte_stream_size              -= shell_item_size;
		internal_item_list->data_size += (size_t) shell_item_size;

		if( libcdata_array_append_entry(
		     internal_item_list->items_array,
		     &item_list_index,
		     (intptr_t *) internal_item,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_APPEND_FAILED,
			 "%s: unable to append shell item: %d.",
			 function,
			 shell_item_index );

			goto on_error;
		}
		parent_item   = (libfwsi_item_t *) internal_item;
		internal_item = NULL;

		shell_item_index++;
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "\n" );
	}
#endif
	internal_item_list->ascii_codepage = ascii_codepage;

	return( 1 );

on_error:
	if( internal_item != NULL )
	{
		libfwsi_internal_item_free(
		 &internal_item,
		 NULL );
	}
	return( -1 );
}

/* Retrieves the data size
 * Returns 1 if successful or -1 on error
 */
int libfwsi_item_list_get_data_size(
     libfwsi_item_list_t *item_list,
     size_t *data_size,
     libcerror_error_t **error )
{
	libfwsi_internal_item_list_t *internal_item_list = NULL;
	static char *function                            = "libfwsi_item_list_get_data_size";

	if( item_list == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item list.",
		 function );

		return( -1 );
	}
	internal_item_list = (libfwsi_internal_item_list_t *) item_list;

	if( data_size == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid data size.",
		 function );

		return( -1 );
	}
	*data_size = internal_item_list->data_size;

	return( 1 );
}

/* Retrieves the number of items
 * Returns 1 if successful or -1 on error
 */
int libfwsi_item_list_get_number_of_items(
     libfwsi_item_list_t *item_list,
     int *number_of_items,
     libcerror_error_t **error )
{
	libfwsi_internal_item_list_t *internal_item_list = NULL;
	static char *function                            = "libfwsi_item_list_get_number_of_items";

	if( item_list == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item list.",
		 function );

		return( -1 );
	}
	internal_item_list = (libfwsi_internal_item_list_t *) item_list;

	if( libcdata_array_get_number_of_entries(
	     internal_item_list->items_array,
	     number_of_items,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve number of entries.",
		 function );

		return( -1 );
	}
	return( 1 );
}

/* Retrieves a specific item
 * Returns 1 if successful or -1 on error
 */
int libfwsi_item_list_get_item(
     libfwsi_item_list_t *item_list,
     int item_index,
     libfwsi_item_t **item,
     libcerror_error_t **error )
{
	libfwsi_internal_item_list_t *internal_item_list = NULL;
	static char *function                            = "libfwsi_item_list_get_item";

	if( item_list == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid item list.",
		 function );

		return( -1 );
	}
	internal_item_list = (libfwsi_internal_item_list_t *) item_list;

	if( libcdata_array_get_entry_by_index(
	     internal_item_list->items_array,
	     item_index,
	     (intptr_t **) item,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve list item: %d.",
		 function,
		 item_index );

		return( -1 );
	}
	return( 1 );
}

