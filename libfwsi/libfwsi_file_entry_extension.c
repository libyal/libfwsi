/*
 * File entry extension functions
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

#include "libfwsi_extension_block.h"
#include "libfwsi_file_entry_extension.h"
#include "libfwsi_file_entry_extension_values.h"
#include "libfwsi_libcerror.h"
#include "libfwsi_libuna.h"

/* Retrieves the creation time
 * The returned time is a 32-bit version of a FAT date time value
 * Returns 1 if successful or -1 on error
 */
int libfwsi_file_entry_extension_get_creation_time(
     libfwsi_extension_block_t *file_entry_extension,
     uint32_t *creation_time,
     libcerror_error_t **error )
{
	libfwsi_internal_extension_block_t *internal_extension_block       = NULL;
	libfwsi_file_entry_extension_values_t *file_entry_extension_values = NULL;
	static char *function                                              = "libfwsi_file_entry_get_creation_time";

	if( file_entry_extension == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid file entry extension.",
		 function );

		return( -1 );
	}
	internal_extension_block = (libfwsi_internal_extension_block_t *) file_entry_extension;

	if( internal_extension_block->signature != 0xbeef0004UL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported extension block signature.",
		 function );

		return( -1 );
	}
	if( internal_extension_block->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block - missing value.",
		 function );

		return( -1 );
	}
	file_entry_extension_values = (libfwsi_file_entry_extension_values_t *) internal_extension_block->value;

	if( creation_time == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid creation time.",
		 function );

		return( -1 );
	}
	*creation_time = file_entry_extension_values->creation_time;

	return( 1 );
}

/* Retrieves the access time
 * The returned time is a 32-bit version of a FAT date time value
 * Returns 1 if successful or -1 on error
 */
int libfwsi_file_entry_extension_get_access_time(
     libfwsi_extension_block_t *file_entry_extension,
     uint32_t *access_time,
     libcerror_error_t **error )
{
	libfwsi_internal_extension_block_t *internal_extension_block       = NULL;
	libfwsi_file_entry_extension_values_t *file_entry_extension_values = NULL;
	static char *function                                              = "libfwsi_file_entry_get_access_time";

	if( file_entry_extension == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid file entry extension.",
		 function );

		return( -1 );
	}
	internal_extension_block = (libfwsi_internal_extension_block_t *) file_entry_extension;

	if( internal_extension_block->signature != 0xbeef0004UL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported extension block signature.",
		 function );

		return( -1 );
	}
	if( internal_extension_block->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block - missing value.",
		 function );

		return( -1 );
	}
	file_entry_extension_values = (libfwsi_file_entry_extension_values_t *) internal_extension_block->value;

	if( access_time == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid access time.",
		 function );

		return( -1 );
	}
	*access_time = file_entry_extension_values->access_time;

	return( 1 );
}

/* Retrieves the NTFS file reference
 * Returns 1 if successful, 0 if not available or -1 on error
 */
int libfwsi_file_entry_extension_get_file_reference(
     libfwsi_extension_block_t *file_entry_extension,
     uint64_t *file_reference,
     libcerror_error_t **error )
{
	libfwsi_internal_extension_block_t *internal_extension_block       = NULL;
	libfwsi_file_entry_extension_values_t *file_entry_extension_values = NULL;
	static char *function                                              = "libfwsi_file_entry_get_file_reference";

	if( file_entry_extension == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid file entry extension.",
		 function );

		return( -1 );
	}
	internal_extension_block = (libfwsi_internal_extension_block_t *) file_entry_extension;

	if( internal_extension_block->signature != 0xbeef0004UL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported extension block signature.",
		 function );

		return( -1 );
	}
	if( internal_extension_block->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block - missing value.",
		 function );

		return( -1 );
	}
	file_entry_extension_values = (libfwsi_file_entry_extension_values_t *) internal_extension_block->value;

	if( file_reference == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid file reference.",
		 function );

		return( -1 );
	}
	if( ( internal_extension_block->version < 7 )
	 || ( file_entry_extension_values->file_reference == 0 ) )
	{
		return( 0 );
	}
	*file_reference = file_entry_extension_values->file_reference;

	return( 1 );
}

/* Retrieves the size of the UTF-8 formatted long name
 * Returns 1 if successful, 0 if not available or -1 on error
 */
int libfwsi_file_entry_extension_get_utf8_long_name_size(
     libfwsi_extension_block_t *file_entry_extension,
     size_t *utf8_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_extension_block_t *internal_extension_block       = NULL;
	libfwsi_file_entry_extension_values_t *file_entry_extension_values = NULL;
	static char *function                                              = "libfwsi_file_entry_extension_get_utf8_long_name_size";

	if( file_entry_extension == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid file entry extension.",
		 function );

		return( -1 );
	}
	internal_extension_block = (libfwsi_internal_extension_block_t *) file_entry_extension;

	if( internal_extension_block->signature != 0xbeef0004UL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported extension block signature.",
		 function );

		return( -1 );
	}
	if( internal_extension_block->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block - missing value.",
		 function );

		return( -1 );
	}
	file_entry_extension_values = (libfwsi_file_entry_extension_values_t *) internal_extension_block->value;

	if( ( file_entry_extension_values->long_name == NULL )
	 || ( file_entry_extension_values->long_name_size == 0 ) )
	{
		return( 0 );
	}
	if( libuna_utf8_string_size_from_utf16_stream(
	     file_entry_extension_values->long_name,
	     file_entry_extension_values->long_name_size,
	     LIBUNA_ENDIAN_LITTLE,
	     utf8_string_size,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to determine size of UTF-8 string.",
		 function );

		return( -1 );
	}
	return( 1 );
}

/* Retrieves the UTF-8 formatted long name
 * Returns 1 if successful, 0 if not available or -1 on error
 */
int libfwsi_file_entry_extension_get_utf8_long_name(
     libfwsi_extension_block_t *file_entry_extension,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_extension_block_t *internal_extension_block       = NULL;
	libfwsi_file_entry_extension_values_t *file_entry_extension_values = NULL;
	static char *function                                              = "libfwsi_file_entry_extension_get_utf8_long_name";

	if( file_entry_extension == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid file entry extension.",
		 function );

		return( -1 );
	}
	internal_extension_block = (libfwsi_internal_extension_block_t *) file_entry_extension;

	if( internal_extension_block->signature != 0xbeef0004UL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported extension block signature.",
		 function );

		return( -1 );
	}
	if( internal_extension_block->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block - missing value.",
		 function );

		return( -1 );
	}
	file_entry_extension_values = (libfwsi_file_entry_extension_values_t *) internal_extension_block->value;

	if( ( file_entry_extension_values->long_name == NULL )
	 || ( file_entry_extension_values->long_name_size == 0 ) )
	{
		return( 0 );
	}
	if( libuna_utf8_string_copy_from_utf16_stream(
	     utf8_string,
	     utf8_string_size,
	     file_entry_extension_values->long_name,
	     file_entry_extension_values->long_name_size,
	     LIBUNA_ENDIAN_LITTLE,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to set UTF-8 string.",
		 function );

		return( -1 );
	}
	return( 1 );
}

/* Retrieves the size of the UTF-16 formatted long name
 * Returns 1 if successful, 0 if not available or -1 on error
 */
int libfwsi_file_entry_extension_get_utf16_long_name_size(
     libfwsi_extension_block_t *file_entry_extension,
     size_t *utf16_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_extension_block_t *internal_extension_block       = NULL;
	libfwsi_file_entry_extension_values_t *file_entry_extension_values = NULL;
	static char *function                                              = "libfwsi_file_entry_extension_get_utf16_long_name_size";

	if( file_entry_extension == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid file entry extension.",
		 function );

		return( -1 );
	}
	internal_extension_block = (libfwsi_internal_extension_block_t *) file_entry_extension;

	if( internal_extension_block->signature != 0xbeef0004UL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported extension block signature.",
		 function );

		return( -1 );
	}
	if( internal_extension_block->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block - missing value.",
		 function );

		return( -1 );
	}
	file_entry_extension_values = (libfwsi_file_entry_extension_values_t *) internal_extension_block->value;

	if( ( file_entry_extension_values->long_name == NULL )
	 || ( file_entry_extension_values->long_name_size == 0 ) )
	{
		return( 0 );
	}
	if( libuna_utf16_string_size_from_utf16_stream(
	     file_entry_extension_values->long_name,
	     file_entry_extension_values->long_name_size,
	     LIBUNA_ENDIAN_LITTLE,
	     utf16_string_size,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to determine size of UTF-16 string.",
		 function );

		return( -1 );
	}
	return( 1 );
}

/* Retrieves the UTF-16 formatted long name
 * Returns 1 if successful, 0 if not available or -1 on error
 */
int libfwsi_file_entry_extension_get_utf16_long_name(
     libfwsi_extension_block_t *file_entry_extension,
     uint16_t *utf16_string,
     size_t utf16_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_extension_block_t *internal_extension_block       = NULL;
	libfwsi_file_entry_extension_values_t *file_entry_extension_values = NULL;
	static char *function                                              = "libfwsi_file_entry_extension_get_utf16_long_name";

	if( file_entry_extension == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid file entry extension.",
		 function );

		return( -1 );
	}
	internal_extension_block = (libfwsi_internal_extension_block_t *) file_entry_extension;

	if( internal_extension_block->signature != 0xbeef0004UL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported extension block signature.",
		 function );

		return( -1 );
	}
	if( internal_extension_block->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block - missing value.",
		 function );

		return( -1 );
	}
	file_entry_extension_values = (libfwsi_file_entry_extension_values_t *) internal_extension_block->value;

	if( ( file_entry_extension_values->long_name == NULL )
	 || ( file_entry_extension_values->long_name_size == 0 ) )
	{
		return( 0 );
	}
	if( libuna_utf16_string_copy_from_utf16_stream(
	     utf16_string,
	     utf16_string_size,
	     file_entry_extension_values->long_name,
	     file_entry_extension_values->long_name_size,
	     LIBUNA_ENDIAN_LITTLE,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to set UTF-16 string.",
		 function );

		return( -1 );
	}
	return( 1 );
}

/* Retrieves the size of the UTF-8 formatted localized name
 * Returns 1 if successful, 0 if not available or -1 on error
 */
int libfwsi_file_entry_extension_get_utf8_localized_name_size(
     libfwsi_extension_block_t *file_entry_extension,
     size_t *utf8_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_extension_block_t *internal_extension_block       = NULL;
	libfwsi_file_entry_extension_values_t *file_entry_extension_values = NULL;
	static char *function                                              = "libfwsi_file_entry_extension_get_utf8_localized_name_size";
	int result                                                         = 0;

	if( file_entry_extension == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid file entry extension.",
		 function );

		return( -1 );
	}
	internal_extension_block = (libfwsi_internal_extension_block_t *) file_entry_extension;

	if( internal_extension_block->signature != 0xbeef0004UL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported extension block signature.",
		 function );

		return( -1 );
	}
	if( internal_extension_block->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block - missing value.",
		 function );

		return( -1 );
	}
	file_entry_extension_values = (libfwsi_file_entry_extension_values_t *) internal_extension_block->value;

	if( ( file_entry_extension_values->localized_name == NULL )
	 || ( file_entry_extension_values->localized_name_size == 0 ) )
	{
		return( 0 );
	}
	if( internal_extension_block->version >= 7 )
	{
		result = libuna_utf8_string_size_from_utf16_stream(
		          file_entry_extension_values->localized_name,
		          file_entry_extension_values->localized_name_size,
		          LIBUNA_ENDIAN_LITTLE,
		          utf8_string_size,
		          error );
	}
	else if( internal_extension_block->version >= 3 )
	{
		result = libuna_utf8_string_size_from_byte_stream(
		          file_entry_extension_values->localized_name,
		          file_entry_extension_values->localized_name_size,
		          file_entry_extension_values->ascii_codepage,
		          utf8_string_size,
		          error );
	}
	else
	{
		return( 0 );
	}
	if( result != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to determine size of UTF-8 string.",
		 function );

		return( -1 );
	}
	return( 1 );
}

/* Retrieves the UTF-8 formatted localized name
 * Returns 1 if successful, 0 if not available or -1 on error
 */
int libfwsi_file_entry_extension_get_utf8_localized_name(
     libfwsi_extension_block_t *file_entry_extension,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_extension_block_t *internal_extension_block       = NULL;
	libfwsi_file_entry_extension_values_t *file_entry_extension_values = NULL;
	static char *function                                              = "libfwsi_file_entry_extension_get_utf8_localized_name";
	int result                                                         = 0;

	if( file_entry_extension == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid file entry extension.",
		 function );

		return( -1 );
	}
	internal_extension_block = (libfwsi_internal_extension_block_t *) file_entry_extension;

	if( internal_extension_block->signature != 0xbeef0004UL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported extension block signature.",
		 function );

		return( -1 );
	}
	if( internal_extension_block->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block - missing value.",
		 function );

		return( -1 );
	}
	file_entry_extension_values = (libfwsi_file_entry_extension_values_t *) internal_extension_block->value;

	if( ( file_entry_extension_values->localized_name == NULL )
	 || ( file_entry_extension_values->localized_name_size == 0 ) )
	{
		return( 0 );
	}
	if( internal_extension_block->version >= 7 )
	{
		result = libuna_utf8_string_copy_from_utf16_stream(
		          utf8_string,
		          utf8_string_size,
		          file_entry_extension_values->localized_name,
		          file_entry_extension_values->localized_name_size,
		          LIBUNA_ENDIAN_LITTLE,
		          error );
	}
	else if( internal_extension_block->version >= 3 )
	{
		result = libuna_utf8_string_copy_from_byte_stream(
		          utf8_string,
		          utf8_string_size,
		          file_entry_extension_values->localized_name,
		          file_entry_extension_values->localized_name_size,
		          file_entry_extension_values->ascii_codepage,
		          error );
	}
	else
	{
		return( 0 );
	}
	if( result != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to set UTF-8 string.",
		 function );

		return( -1 );
	}
	return( 1 );
}

/* Retrieves the size of the UTF-16 formatted localized name
 * Returns 1 if successful, 0 if not available or -1 on error
 */
int libfwsi_file_entry_extension_get_utf16_localized_name_size(
     libfwsi_extension_block_t *file_entry_extension,
     size_t *utf16_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_extension_block_t *internal_extension_block       = NULL;
	libfwsi_file_entry_extension_values_t *file_entry_extension_values = NULL;
	static char *function                                              = "libfwsi_file_entry_extension_get_utf16_localized_name_size";
	int result                                                         = 0;

	if( file_entry_extension == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid file entry extension.",
		 function );

		return( -1 );
	}
	internal_extension_block = (libfwsi_internal_extension_block_t *) file_entry_extension;

	if( internal_extension_block->signature != 0xbeef0004UL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported extension block signature.",
		 function );

		return( -1 );
	}
	if( internal_extension_block->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block - missing value.",
		 function );

		return( -1 );
	}
	file_entry_extension_values = (libfwsi_file_entry_extension_values_t *) internal_extension_block->value;

	if( ( file_entry_extension_values->localized_name == NULL )
	 || ( file_entry_extension_values->localized_name_size == 0 ) )
	{
		return( 0 );
	}
	if( internal_extension_block->version >= 7 )
	{
		result = libuna_utf16_string_size_from_utf16_stream(
		          file_entry_extension_values->localized_name,
		          file_entry_extension_values->localized_name_size,
		          LIBUNA_ENDIAN_LITTLE,
		          utf16_string_size,
		          error );
	}
	else if( internal_extension_block->version >= 3 )
	{
		result = libuna_utf16_string_size_from_byte_stream(
		          file_entry_extension_values->localized_name,
		          file_entry_extension_values->localized_name_size,
		          file_entry_extension_values->ascii_codepage,
		          utf16_string_size,
		          error );
	}
	else
	{
		return( 0 );
	}
	if( result != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to determine size of UTF-16 string.",
		 function );

		return( -1 );
	}
	return( 1 );
}

/* Retrieves the UTF-16 formatted localized name
 * Returns 1 if successful, 0 if not available or -1 on error
 */
int libfwsi_file_entry_extension_get_utf16_localized_name(
     libfwsi_extension_block_t *file_entry_extension,
     uint16_t *utf16_string,
     size_t utf16_string_size,
     libcerror_error_t **error )
{
	libfwsi_internal_extension_block_t *internal_extension_block       = NULL;
	libfwsi_file_entry_extension_values_t *file_entry_extension_values = NULL;
	static char *function                                              = "libfwsi_file_entry_extension_get_utf16_localized_name";
	int result                                                         = 0;

	if( file_entry_extension == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid file entry extension.",
		 function );

		return( -1 );
	}
	internal_extension_block = (libfwsi_internal_extension_block_t *) file_entry_extension;

	if( internal_extension_block->signature != 0xbeef0004UL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported extension block signature.",
		 function );

		return( -1 );
	}
	if( internal_extension_block->value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid extension block - missing value.",
		 function );

		return( -1 );
	}
	file_entry_extension_values = (libfwsi_file_entry_extension_values_t *) internal_extension_block->value;

	if( ( file_entry_extension_values->localized_name == NULL )
	 || ( file_entry_extension_values->localized_name_size == 0 ) )
	{
		return( 0 );
	}
	if( internal_extension_block->version >= 7 )
	{
		result = libuna_utf16_string_copy_from_utf16_stream(
		          utf16_string,
		          utf16_string_size,
		          file_entry_extension_values->localized_name,
		          file_entry_extension_values->localized_name_size,
		          LIBUNA_ENDIAN_LITTLE,
		          error );
	}
	else if( internal_extension_block->version >= 3 )
	{
		result = libuna_utf16_string_copy_from_byte_stream(
		          utf16_string,
		          utf16_string_size,
		          file_entry_extension_values->localized_name,
		          file_entry_extension_values->localized_name_size,
		          file_entry_extension_values->ascii_codepage,
		          error );
	}
	else
	{
		return( 0 );
	}
	if( result != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to set UTF-16 string.",
		 function );

		return( -1 );
	}
	return( 1 );
}

