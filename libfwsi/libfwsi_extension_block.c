/*
 * Windows Shell Item extension block functions
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

#include "libfwsi_definitions.h"
#include "libfwsi_extension_block.h"
#include "libfwsi_extension_block_0xbeef0000_values.h"
#include "libfwsi_extension_block_0xbeef0001_values.h"
#include "libfwsi_extension_block_0xbeef0003_values.h"
#include "libfwsi_extension_block_0xbeef0005_values.h"
#include "libfwsi_extension_block_0xbeef0006_values.h"
#include "libfwsi_extension_block_0xbeef000a_values.h"
#include "libfwsi_extension_block_0xbeef0013_values.h"
#include "libfwsi_extension_block_0xbeef0014_values.h"
#include "libfwsi_extension_block_0xbeef0019_values.h"
#include "libfwsi_extension_block_0xbeef0025_values.h"
#include "libfwsi_file_entry_extension_values.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libcnotify.h"
#include "libfwsi_types.h"

/* Creates an extension block
 * Make sure the value extension_block is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libfwsi_extension_block_initialize(
     libfwsi_extension_block_t **extension_block,
     libcerror_error_t **error )
{
	libfwsi_internal_extension_block_t *internal_extension_block = NULL;
	static char *function                                        = "libfwsi_extension_block_initialize";

	if( extension_block == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block.",
		 function );

		return( -1 );
	}
	if( *extension_block != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid extension block value already set.",
		 function );

		return( -1 );
	}
	internal_extension_block = memory_allocate_structure(
	                            libfwsi_internal_extension_block_t );

	if( internal_extension_block == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create extension block.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     internal_extension_block,
	     0,
	     sizeof( libfwsi_internal_extension_block_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear extension block.",
		 function );

		goto on_error;
	}
	*extension_block = (libfwsi_extension_block_t *) internal_extension_block;

	return( 1 );

on_error:
	if( internal_extension_block != NULL )
	{
		memory_free(
		 internal_extension_block );
	}
	return( -1 );
}

/* Frees an extension block
 * Returns 1 if successful or -1 on error
 */
int libfwsi_extension_block_free(
     libfwsi_extension_block_t **extension_block,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_extension_block_free";

	if( extension_block == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block.",
		 function );

		return( -1 );
	}
	if( *extension_block != NULL )
	{
		*extension_block = NULL;
	}
	return( 1 );
}

/* Frees an extension block
 * Returns 1 if successful or -1 on error
 */
int libfwsi_internal_extension_block_free(
     libfwsi_internal_extension_block_t **internal_extension_block,
     libcerror_error_t **error )
{
	static char *function = "libfwsi_internal_extension_block_free";
	int result            = 1;

	if( internal_extension_block == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block.",
		 function );

		return( -1 );
	}
	if( *internal_extension_block != NULL )
	{
		if( ( *internal_extension_block )->value != NULL )
		{
			if( ( *internal_extension_block )->free_value != NULL )
			{
				if( ( *internal_extension_block )->free_value(
				     &( ( *internal_extension_block )->value ),
				     error ) != 1 )
				{
					libcerror_error_set(
					 error,
					 LIBCERROR_ERROR_DOMAIN_RUNTIME,
					 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
					 "%s: unable to free extension block value.",
					 function );

					result = -1;
				}
			}
		}
		memory_free(
		 *internal_extension_block );

		*internal_extension_block = NULL;
	}
	return( result );
}

/* Copies a shell extension block from a byte stream
 * Returns 1 if successful, 0 if not able to read or -1 on error
 */
int libfwsi_extension_block_copy_from_byte_stream(
     libfwsi_internal_extension_block_t *internal_extension_block,
     const uint8_t *byte_stream,
     size_t byte_stream_size,
     int ascii_codepage,
     libcerror_error_t **error )
{
	static char *function     = "libfwsi_extension_block_copy_from_byte_stream";
	size_t byte_stream_offset = 0;
	uint32_t signature        = 0;
	uint16_t data_size        = 0;
	int result                = 0;

#if defined( HAVE_DEBUG_OUTPUT )
	uint16_t value_16bit      = 0;
#endif

	if( internal_extension_block == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block.",
		 function );

		return( -1 );
	}
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
	/* Do not try to parse unsupported byte stream sizes
	 */
	if( byte_stream_size < 2 )
	{
		return( 0 );
	}
	byte_stream_copy_to_uint16_little_endian(
	 byte_stream,
	 data_size );

	if( data_size == 0 )
	{
		internal_extension_block->data_size = 2;

		return( 1 );
	}
	/* Do not try to parse unsupported extension block sizes
	 */
	if( data_size < 10 )
	{
		return( 0 );
	}
	/* Do not try to parse unsupported byte stream sizes
	 */
	if( byte_stream_size < 8 )
	{
		return( 0 );
	}
	byte_stream_copy_to_uint32_little_endian(
	 &( byte_stream[ 4 ] ),
	 signature );

	/* Do not try to parse unsupported extension block signatures
	 */
	if( ( signature >> 16 ) != 0xbeef )
	{
		return( 0 );
	}
	byte_stream_copy_to_uint16_little_endian(
	 &( byte_stream[ 2 ] ),
	 internal_extension_block->version );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: size\t\t\t: %" PRIu16 "\n",
		 function,
		 data_size );

		libcnotify_printf(
		 "%s: version\t\t\t: %" PRIu16 "\n",
		 function,
		 internal_extension_block->version );

		libcnotify_printf(
		 "%s: signature\t\t: 0x%08" PRIx32 "\n",
		 function,
		 signature );
	}
#endif
	if( (size_t) data_size > byte_stream_size )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid extension block size value out of bounds.",
		 function );

		goto on_error;
	}
	internal_extension_block->data_size = data_size;
	internal_extension_block->signature = signature;

	switch( internal_extension_block->signature )
	{
		case 0xbeef0000UL:
			internal_extension_block->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_extension_block_0xbeef0000_values_free;

			if( libfwsi_extension_block_0xbeef0000_values_initialize(
			     (libfwsi_extension_block_0xbeef0000_values_t **) &( internal_extension_block->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create extension block 0xbeef0000 values.",
				 function );

				goto on_error;
			}
			result = libfwsi_extension_block_0xbeef0000_values_read_data(
			          (libfwsi_extension_block_0xbeef0000_values_t *) internal_extension_block->value,
			          byte_stream,
			          internal_extension_block->data_size,
			          error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
				 "%s: unable to copy byte stream to extension block 0xbeef0000 values.",
				 function );

				goto on_error;
			}
			break;

		case 0xbeef0001UL:
			internal_extension_block->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_extension_block_0xbeef0001_values_free;

			if( libfwsi_extension_block_0xbeef0001_values_initialize(
			     (libfwsi_extension_block_0xbeef0001_values_t **) &( internal_extension_block->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create extension block 0xbeef0001 values.",
				 function );

				goto on_error;
			}
			result = libfwsi_extension_block_0xbeef0001_values_read_data(
			          (libfwsi_extension_block_0xbeef0001_values_t *) internal_extension_block->value,
			          byte_stream,
			          internal_extension_block->data_size,
			          error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
				 "%s: unable to copy byte stream to extension block 0xbeef0001 values.",
				 function );

				goto on_error;
			}
			break;

		case 0xbeef0003UL:
			internal_extension_block->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_extension_block_0xbeef0003_values_free;

			if( libfwsi_extension_block_0xbeef0003_values_initialize(
			     (libfwsi_extension_block_0xbeef0003_values_t **) &( internal_extension_block->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create extension block 0xbeef0003 values.",
				 function );

				goto on_error;
			}
			result = libfwsi_extension_block_0xbeef0003_values_read_data(
			          (libfwsi_extension_block_0xbeef0003_values_t *) internal_extension_block->value,
			          byte_stream,
			          internal_extension_block->data_size,
			          error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
				 "%s: unable to copy byte stream to extension block 0xbeef0003 values.",
				 function );

				goto on_error;
			}
			break;

		case 0xbeef0004UL:
			internal_extension_block->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_file_entry_extension_values_free;

			if( libfwsi_file_entry_extension_values_initialize(
			     (libfwsi_file_entry_extension_values_t **) &( internal_extension_block->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create file entry extension values.",
				 function );

				goto on_error;
			}
			result = libfwsi_file_entry_extension_values_read_data(
			          (libfwsi_file_entry_extension_values_t *) internal_extension_block->value,
			          byte_stream,
			          internal_extension_block->data_size,
			          ascii_codepage,
			          error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
				 "%s: unable to copy byte stream to file entry extension values.",
				 function );

				goto on_error;
			}
			break;

		case 0xbeef0005UL:
			internal_extension_block->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_extension_block_0xbeef0005_values_free;

			if( libfwsi_extension_block_0xbeef0005_values_initialize(
			     (libfwsi_extension_block_0xbeef0005_values_t **) &( internal_extension_block->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create extension block 0xbeef0005 values.",
				 function );

				goto on_error;
			}
			result = libfwsi_extension_block_0xbeef0005_values_read_data(
			          (libfwsi_extension_block_0xbeef0005_values_t *) internal_extension_block->value,
			          byte_stream,
			          internal_extension_block->data_size,
			          error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
				 "%s: unable to copy byte stream to extension block 0xbeef0005 values.",
				 function );

				goto on_error;
			}
			break;

		case 0xbeef0006UL:
			internal_extension_block->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_extension_block_0xbeef0006_values_free;

			if( libfwsi_extension_block_0xbeef0006_values_initialize(
			     (libfwsi_extension_block_0xbeef0006_values_t **) &( internal_extension_block->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create extension block 0xbeef0006 values.",
				 function );

				goto on_error;
			}
			result = libfwsi_extension_block_0xbeef0006_values_read_data(
			          (libfwsi_extension_block_0xbeef0006_values_t *) internal_extension_block->value,
			          byte_stream,
			          internal_extension_block->data_size,
			          error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
				 "%s: unable to copy byte stream to extension block 0xbeef0006 values.",
				 function );

				goto on_error;
			}
			break;

		case 0xbeef000aUL:
			internal_extension_block->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_extension_block_0xbeef000a_values_free;

			if( libfwsi_extension_block_0xbeef000a_values_initialize(
			     (libfwsi_extension_block_0xbeef000a_values_t **) &( internal_extension_block->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create extension block 0xbeef000a values.",
				 function );

				goto on_error;
			}
			result = libfwsi_extension_block_0xbeef000a_values_read_data(
			          (libfwsi_extension_block_0xbeef000a_values_t *) internal_extension_block->value,
			          byte_stream,
			          internal_extension_block->data_size,
			          error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
				 "%s: unable to copy byte stream to extension block 0xbeef000a values.",
				 function );

				goto on_error;
			}
			break;

		case 0xbeef0013UL:
			internal_extension_block->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_extension_block_0xbeef0013_values_free;

			if( libfwsi_extension_block_0xbeef0013_values_initialize(
			     (libfwsi_extension_block_0xbeef0013_values_t **) &( internal_extension_block->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create extension block 0xbeef0013 values.",
				 function );

				goto on_error;
			}
			result = libfwsi_extension_block_0xbeef0013_values_read_data(
			          (libfwsi_extension_block_0xbeef0013_values_t *) internal_extension_block->value,
			          byte_stream,
			          internal_extension_block->data_size,
			          error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
				 "%s: unable to copy byte stream to extension block 0xbeef0013 values.",
				 function );

				goto on_error;
			}
			break;

		case 0xbeef0014UL:
			internal_extension_block->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_extension_block_0xbeef0014_values_free;

			if( libfwsi_extension_block_0xbeef0014_values_initialize(
			     (libfwsi_extension_block_0xbeef0014_values_t **) &( internal_extension_block->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create extension block 0xbeef0014 values.",
				 function );

				goto on_error;
			}
			result = libfwsi_extension_block_0xbeef0014_values_read_data(
			          (libfwsi_extension_block_0xbeef0014_values_t *) internal_extension_block->value,
			          byte_stream,
			          internal_extension_block->data_size,
			          error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
				 "%s: unable to copy byte stream to extension block 0xbeef0014 values.",
				 function );

				goto on_error;
			}
			break;

		case 0xbeef0019UL:
			internal_extension_block->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_extension_block_0xbeef0019_values_free;

			if( libfwsi_extension_block_0xbeef0019_values_initialize(
			     (libfwsi_extension_block_0xbeef0019_values_t **) &( internal_extension_block->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create extension block 0xbeef0019 values.",
				 function );

				goto on_error;
			}
			result = libfwsi_extension_block_0xbeef0019_values_read_data(
			          (libfwsi_extension_block_0xbeef0019_values_t *) internal_extension_block->value,
			          byte_stream,
			          internal_extension_block->data_size,
			          error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
				 "%s: unable to copy byte stream to extension block 0xbeef0019 values.",
				 function );

				goto on_error;
			}
			break;

		case 0xbeef0025UL:
			internal_extension_block->free_value = (int (*)(intptr_t **, libcerror_error_t **)) &libfwsi_extension_block_0xbeef0025_values_free;

			if( libfwsi_extension_block_0xbeef0025_values_initialize(
			     (libfwsi_extension_block_0xbeef0025_values_t **) &( internal_extension_block->value ),
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
				 "%s: unable to create extension block 0xbeef0025 values.",
				 function );

				goto on_error;
			}
			result = libfwsi_extension_block_0xbeef0025_values_read_data(
			          (libfwsi_extension_block_0xbeef0025_values_t *) internal_extension_block->value,
			          byte_stream,
			          internal_extension_block->data_size,
			          error );

			if( result == -1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_COPY_FAILED,
				 "%s: unable to copy byte stream to extension block 0xbeef0025 values.",
				 function );

				goto on_error;
			}
			break;

		default:
			break;
	}
	if( result == 0 )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			libcnotify_printf(
			 "%s: unsupported extension block.\n",
			 function );
		}
#endif
	}
	byte_stream_offset += internal_extension_block->data_size - 2;

	if( byte_stream_offset > (size_t) ( internal_extension_block->data_size - 2 ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid extension block data size value out of bounds.",
		 function );

		goto on_error;
	}
	if( byte_stream_offset < (size_t) ( internal_extension_block->data_size - 2 ) )
	{
#if defined( HAVE_DEBUG_OUTPUT )
		if( libcnotify_verbose != 0 )
		{
			libcnotify_printf(
			 "%s: trailing data:\n",
			 function );
			libcnotify_print_data(
			 &( byte_stream[ byte_stream_offset ] ),
			 internal_extension_block->data_size - 2,
			 LIBCNOTIFY_PRINT_DATA_FLAG_GROUP_DATA );
		}
#endif
		byte_stream_offset += internal_extension_block->data_size - 2;
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		byte_stream_copy_to_uint16_little_endian(
		 &( byte_stream[ byte_stream_offset ] ),
		 value_16bit );

		libcnotify_printf(
		 "%s: version offset\t\t: %" PRIu16 "\n",
		 function,
		 value_16bit );
	}
#endif
	byte_stream_offset += 2;

	return( 1 );

on_error:
	if( ( internal_extension_block->value != NULL )
	 && ( internal_extension_block->free_value != NULL ) )
	{
		internal_extension_block->free_value(
		 &( internal_extension_block->value ),
		 NULL );
	}
	return( -1 );
}

/* Retrieves the signature
 * Returns 1 if successful or -1 on error
 */
int libfwsi_extension_block_get_signature(
     libfwsi_extension_block_t *extension_block,
     uint32_t *signature,
     libcerror_error_t **error )
{
	libfwsi_internal_extension_block_t *internal_extension_block = NULL;
	static char *function                                        = "libfwsi_extension_block_get_signature";

	if( extension_block == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block.",
		 function );

		return( -1 );
	}
	internal_extension_block = (libfwsi_internal_extension_block_t *) extension_block;

	if( signature == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid signature.",
		 function );

		return( -1 );
	}
	*signature = internal_extension_block->signature;

	return( 1 );
}

/* Retrieves the data size
 * Returns 1 if successful or -1 on error
 */
int libfwsi_extension_block_get_data_size(
     libfwsi_extension_block_t *extension_block,
     size_t *data_size,
     libcerror_error_t **error )
{
	libfwsi_internal_extension_block_t *internal_extension_block = NULL;
	static char *function                                        = "libfwsi_extension_block_get_data_size";

	if( extension_block == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block.",
		 function );

		return( -1 );
	}
	internal_extension_block = (libfwsi_internal_extension_block_t *) extension_block;

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
	*data_size = (size_t) internal_extension_block->data_size;

	return( 1 );
}

