/*
 * Library to access the Windows Shell Item format
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

#if !defined( _LIBFWSI_H )
#define _LIBFWSI_H

#include <libfwsi/codepage.h>
#include <libfwsi/definitions.h>
#include <libfwsi/error.h>
#include <libfwsi/extern.h>
#include <libfwsi/features.h>
#include <libfwsi/types.h>

#include <stdio.h>

#if defined( __cplusplus )
extern "C" {
#endif

/* -------------------------------------------------------------------------
 * Support functions
 * ------------------------------------------------------------------------- */

/* Returns the library version
 */
LIBFWSI_EXTERN \
const char *libfwsi_get_version(
             void );

/* -------------------------------------------------------------------------
 * Notify functions
 * ------------------------------------------------------------------------- */

/* Sets the verbose notification
 */
LIBFWSI_EXTERN \
void libfwsi_notify_set_verbose(
      int verbose );

/* Sets the notification stream
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_notify_set_stream(
     FILE *stream,
     libfwsi_error_t **error );

/* Opens the notification stream using a filename
 * The stream is opened in append mode
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_notify_stream_open(
     const char *filename,
     libfwsi_error_t **error );

/* Closes the notification stream if opened using a filename
 * Returns 0 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_notify_stream_close(
     libfwsi_error_t **error );

/* -------------------------------------------------------------------------
 * Error functions
 * ------------------------------------------------------------------------- */

/* Frees an error
 */
LIBFWSI_EXTERN \
void libfwsi_error_free(
      libfwsi_error_t **error );

/* Prints a descriptive string of the error to the stream
 * Returns the amount of printed characters if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_error_fprint(
     libfwsi_error_t *error,
     FILE *stream );

/* Prints a descriptive string of the error to the string
 * The end-of-string character is not included in the return value
 * Returns the amount of printed characters if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_error_sprint(
     libfwsi_error_t *error,
     char *string,
     size_t size );

/* Prints a backtrace of the error to the stream
 * Returns the amount of printed characters if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_error_backtrace_fprint(
     libfwsi_error_t *error,
     FILE *stream );

/* Prints a backtrace of the error to the string
 * The end-of-string character is not included in the return value
 * Returns the amount of printed characters if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_error_backtrace_sprint(
     libfwsi_error_t *error,
     char *string,
     size_t size );

/* -------------------------------------------------------------------------
 * Item list functions
 * ------------------------------------------------------------------------- */

/* Creates an item list
 * Make sure the value item_list is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_item_list_initialize(
     libfwsi_item_list_t **item_list,
     libfwsi_error_t **error );

/* Frees an item list
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_item_list_free(
     libfwsi_item_list_t **item_list,
     libfwsi_error_t **error );

/* Copies a shell item list from a byte stream
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_item_list_copy_from_byte_stream(
     libfwsi_item_list_t *item_list,
     const uint8_t *byte_stream,
     size_t byte_stream_size,
     int ascii_codepage,
     libfwsi_error_t **error );

/* Retrieves the data size
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_item_list_get_data_size(
     libfwsi_item_list_t *item_list,
     size_t *data_size,
     libfwsi_error_t **error );

/* Retrieves the number of items
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_item_list_get_number_of_items(
     libfwsi_item_list_t *item_list,
     int *number_of_items,
     libfwsi_error_t **error );

/* Retrieves a specific item
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_item_list_get_item(
     libfwsi_item_list_t *item_list,
     int item_index,
     libfwsi_item_t **item,
     libfwsi_error_t **error );

/* -------------------------------------------------------------------------
 * Item functions
 * ------------------------------------------------------------------------- */

/* Creates an item
 * Make sure the value item_list is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_item_initialize(
     libfwsi_item_t **item,
     libfwsi_error_t **error );

/* Frees an item
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_item_free(
     libfwsi_item_t **item,
     libfwsi_error_t **error );

/* Copies a shell item from a byte stream
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_item_copy_from_byte_stream(
     libfwsi_item_t *item,
     const uint8_t *byte_stream,
     size_t byte_stream_size,
     int ascii_codepage,
     libfwsi_error_t **error );

/* Retrieves the type
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_item_get_type(
     libfwsi_item_t *item,
     int *type,
     libfwsi_error_t **error );

/* Retrieves the class type
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_item_get_class_type(
     libfwsi_item_t *item,
     uint8_t *class_type,
     libfwsi_error_t **error );

/* Retrieves the signature
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_item_get_signature(
     libfwsi_item_t *item,
     uint32_t *signature,
     libfwsi_error_t **error );

/* Retrieves the data size
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_item_get_data_size(
     libfwsi_item_t *item,
     size_t *data_size,
     libfwsi_error_t **error );

/* Retrieves the delegate folder identifier
 * The identifier is a GUID and is 16 bytes of size
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_item_get_delegate_folder_identifier(
     libfwsi_item_t *item,
     uint8_t *guid_data,
     size_t guid_data_size,
     libfwsi_error_t **error );

/* Retrieves the number of extension blocks
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_item_get_number_of_extension_blocks(
     libfwsi_item_t *item,
     int *number_of_extension_blocks,
     libfwsi_error_t **error );

/* Retrieves a specific extension block
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_item_get_extension_block(
     libfwsi_item_t *item,
     int extension_block_index,
     libfwsi_extension_block_t **extension_block,
     libfwsi_error_t **error );

/* -------------------------------------------------------------------------
 * Root folder item functions
 * ------------------------------------------------------------------------- */

/* Retrieves the shell folder identifier
 * The identifier is a GUID and is 16 bytes of size
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_root_folder_get_shell_folder_identifier(
     libfwsi_item_t *root_folder,
     uint8_t *guid_data,
     size_t guid_data_size,
     libfwsi_error_t **error );

/* -------------------------------------------------------------------------
 * Volume item functions
 * ------------------------------------------------------------------------- */

/* Retrieves the size of the UTF-8 formatted name
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_volume_get_utf8_name_size(
     libfwsi_item_t *volume,
     size_t *utf8_string_size,
     libfwsi_error_t **error );

/* Retrieves the UTF-8 formatted name
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_volume_get_utf8_name(
     libfwsi_item_t *volume,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     libfwsi_error_t **error );

/* Retrieves the size of the UTF-16 formatted name
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_volume_get_utf16_name_size(
     libfwsi_item_t *volume,
     size_t *utf16_string_size,
     libfwsi_error_t **error );

/* Retrieves the UTF-16 formatted name
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_volume_get_utf16_name(
     libfwsi_item_t *volume,
     uint16_t *utf16_string,
     size_t utf16_string_size,
     libfwsi_error_t **error );

/* Retrieves the identifier
 * The identifier is a GUID and is 16 bytes of size
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_volume_get_identifier(
     libfwsi_item_t *volume,
     uint8_t *guid_data,
     size_t guid_data_size,
     libfwsi_error_t **error );

/* Retrieves the shell folder identifier
 * The identifier is a GUID and is 16 bytes of size
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_volume_get_shell_folder_identifier(
     libfwsi_item_t *volume,
     uint8_t *guid_data,
     size_t guid_data_size,
     libfwsi_error_t **error );

/* -------------------------------------------------------------------------
 * File entry item functions
 * ------------------------------------------------------------------------- */

/* Retrieves the file size
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_file_entry_get_file_size(
     libfwsi_item_t *file_entry,
     uint32_t *file_size,
     libfwsi_error_t **error );

/* Retrieves the modification time
 * The returned time is a 32-bit version of a FAT date time value
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_file_entry_get_modification_time(
     libfwsi_item_t *file_entry,
     uint32_t *fat_date_time,
     libfwsi_error_t **error );

/* Retrieves the file attribute flags
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_file_entry_get_file_attribute_flags(
     libfwsi_item_t *file_entry,
     uint32_t *file_attribute_flags,
     libfwsi_error_t **error );

/* Retrieves the size of the UTF-8 formatted name
 * This function uses UTF-8 RFC 2279 (or 6-byte UTF-8) to support characters outside Unicode
 * The size includes the end of string character
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_file_entry_get_utf8_name_size(
     libfwsi_item_t *file_entry,
     size_t *utf8_string_size,
     libfwsi_error_t **error );

/* Retrieves the UTF-8 formatted name
 * This function uses UTF-8 RFC 2279 (or 6-byte UTF-8) to support characters outside Unicode
 * The size should include the end of string character
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_file_entry_get_utf8_name(
     libfwsi_item_t *file_entry,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     libfwsi_error_t **error );

/* Retrieves the size of the UTF-16 formatted name
 * This function uses UCS-2 (with surrogates) to support characters outside Unicode
 * The size includes the end of string character
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_file_entry_get_utf16_name_size(
     libfwsi_item_t *file_entry,
     size_t *utf16_string_size,
     libfwsi_error_t **error );

/* Retrieves the UTF-16 formatted name
 * This function uses UCS-2 (with surrogates) to support characters outside Unicode
 * The size should include the end of string character
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_file_entry_get_utf16_name(
     libfwsi_item_t *file_entry,
     uint16_t *utf16_string,
     size_t utf16_string_size,
     libfwsi_error_t **error );

/* -------------------------------------------------------------------------
 * Network location item functions
 * ------------------------------------------------------------------------- */

/* Retrieves the size of the UTF-8 formatted location
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_network_location_get_utf8_location_size(
     libfwsi_item_t *network_location,
     size_t *utf8_string_size,
     libfwsi_error_t **error );

/* Retrieves the UTF-8 formatted location
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_network_location_get_utf8_location(
     libfwsi_item_t *network_location,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     libfwsi_error_t **error );

/* Retrieves the size of the UTF-16 formatted location
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_network_location_get_utf16_location_size(
     libfwsi_item_t *network_location,
     size_t *utf16_string_size,
     libfwsi_error_t **error );

/* Retrieves the UTF-16 formatted location
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_network_location_get_utf16_location(
     libfwsi_item_t *network_location,
     uint16_t *utf16_string,
     size_t utf16_string_size,
     libfwsi_error_t **error );

/* Retrieves the size of the UTF-8 formatted description
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_network_location_get_utf8_description_size(
     libfwsi_item_t *network_location,
     size_t *utf8_string_size,
     libfwsi_error_t **error );

/* Retrieves the UTF-8 formatted description
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_network_location_get_utf8_description(
     libfwsi_item_t *network_location,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     libfwsi_error_t **error );

/* Retrieves the size of the UTF-16 formatted description
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_network_location_get_utf16_description_size(
     libfwsi_item_t *network_location,
     size_t *utf16_string_size,
     libfwsi_error_t **error );

/* Retrieves the UTF-16 formatted description
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_network_location_get_utf16_description(
     libfwsi_item_t *network_location,
     uint16_t *utf16_string,
     size_t utf16_string_size,
     libfwsi_error_t **error );

/* Retrieves the size of the UTF-8 formatted comments
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_network_location_get_utf8_comments_size(
     libfwsi_item_t *network_location,
     size_t *utf8_string_size,
     libfwsi_error_t **error );

/* Retrieves the UTF-8 formatted comments
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_network_location_get_utf8_comments(
     libfwsi_item_t *network_location,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     libfwsi_error_t **error );

/* Retrieves the size of the UTF-16 formatted comments
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_network_location_get_utf16_comments_size(
     libfwsi_item_t *network_location,
     size_t *utf16_string_size,
     libfwsi_error_t **error );

/* Retrieves the UTF-16 formatted comments
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_network_location_get_utf16_comments(
     libfwsi_item_t *network_location,
     uint16_t *utf16_string,
     size_t utf16_string_size,
     libfwsi_error_t **error );

/* -------------------------------------------------------------------------
 * Compressed folder functions
 * ------------------------------------------------------------------------- */

/* Retrieves the size of the UTF-8 formatted name
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_compressed_folder_get_utf8_name_size(
     libfwsi_item_t *compressed_folder,
     size_t *utf8_string_size,
     libfwsi_error_t **error );

/* Retrieves the UTF-8 formatted name
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_compressed_folder_get_utf8_name(
     libfwsi_item_t *compressed_folder,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     libfwsi_error_t **error );

/* Retrieves the size of the UTF-16 formatted name
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_compressed_folder_get_utf16_name_size(
     libfwsi_item_t *compressed_folder,
     size_t *utf16_string_size,
     libfwsi_error_t **error );

/* Retrieves the UTF-16 formatted name
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_compressed_folder_get_utf16_name(
     libfwsi_item_t *compressed_folder,
     uint16_t *utf16_string,
     size_t utf16_string_size,
     libfwsi_error_t **error );

/* -------------------------------------------------------------------------
 * Control panel category functions
 * ------------------------------------------------------------------------- */

/* Retrieves the control panel category identifier
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_control_panel_category_get_identifier(
     libfwsi_item_t *control_panel_category,
     uint32_t *identifier,
     libfwsi_error_t **error );

/* -------------------------------------------------------------------------
 * Control panel item functions
 * ------------------------------------------------------------------------- */

/* Retrieves the identifier
 * The identifier is a GUID and is 16 bytes of size
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_control_panel_item_get_identifier(
     libfwsi_item_t *control_panel_item,
     uint8_t *guid_data,
     size_t guid_data_size,
     libfwsi_error_t **error );

/* -------------------------------------------------------------------------
 * Users property view functions
 * ------------------------------------------------------------------------- */

/* Retrieves the known folder identifier
 * The identifier is a GUID and is 16 bytes of size
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_users_property_view_get_known_folder_identifier(
     libfwsi_item_t *users_property_view,
     uint8_t *guid_data,
     size_t guid_data_size,
     libfwsi_error_t **error );

/* Retrieves the property store data size
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_users_property_view_get_property_store_data_size(
     libfwsi_item_t *users_property_view,
     size_t *data_size,
     libfwsi_error_t **error );

/* Copies the property store data to the buffer
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_users_property_view_copy_property_store_data(
     libfwsi_item_t *users_property_view,
     uint8_t *data,
     size_t data_size,
     libfwsi_error_t **error );

/* -------------------------------------------------------------------------
 * Extension block functions
 * ------------------------------------------------------------------------- */

/* Frees an extension block
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_extension_block_free(
     libfwsi_extension_block_t **extension_block,
     libfwsi_error_t **error );

/* Retrieves the signature
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_extension_block_get_signature(
     libfwsi_extension_block_t *extension_block,
     uint32_t *signature,
     libfwsi_error_t **error );

/* Retrieves the data size
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_extension_block_get_data_size(
     libfwsi_extension_block_t *extension_block,
     size_t *data_size,
     libfwsi_error_t **error );

/* -------------------------------------------------------------------------
 * File entry extension functions
 * ------------------------------------------------------------------------- */

/* Retrieves the creation time
 * The returned time is a 32-bit version of a FAT date time value
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_file_entry_extension_get_creation_time(
     libfwsi_extension_block_t *file_entry_extension,
     uint32_t *fat_date_time,
     libfwsi_error_t **error );

/* Retrieves the access time
 * The returned time is a 32-bit version of a FAT date time value
 * Returns 1 if successful or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_file_entry_extension_get_access_time(
     libfwsi_extension_block_t *file_entry_extension,
     uint32_t *fat_date_time,
     libfwsi_error_t **error );

/* Retrieves the NTFS file reference
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_file_entry_extension_get_file_reference(
     libfwsi_extension_block_t *file_entry_extension,
     uint64_t *file_reference,
     libfwsi_error_t **error );

/* Retrieves the size of the UTF-8 formatted long name
 * This function uses UTF-8 RFC 2279 (or 6-byte UTF-8) to support characters outside Unicode
 * The size includes the end of string character
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_file_entry_extension_get_utf8_long_name_size(
     libfwsi_extension_block_t *file_entry_extension,
     size_t *utf8_string_size,
     libfwsi_error_t **error );

/* Retrieves the UTF-8 formatted long name
 * This function uses UTF-8 RFC 2279 (or 6-byte UTF-8) to support characters outside Unicode
 * The size should include the end of string character
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_file_entry_extension_get_utf8_long_name(
     libfwsi_extension_block_t *file_entry_extension,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     libfwsi_error_t **error );

/* Retrieves the size of the UTF-16 formatted long name
 * This function uses UCS-2 (with surrogates) to support characters outside Unicode
 * The size includes the end of string character
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_file_entry_extension_get_utf16_long_name_size(
     libfwsi_extension_block_t *file_entry_extension,
     size_t *utf16_string_size,
     libfwsi_error_t **error );

/* Retrieves the UTF-16 formatted long name
 * This function uses UCS-2 (with surrogates) to support characters outside Unicode
 * The size should include the end of string character
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_file_entry_extension_get_utf16_long_name(
     libfwsi_extension_block_t *file_entry_extension,
     uint16_t *utf16_string,
     size_t utf16_string_size,
     libfwsi_error_t **error );

/* Retrieves the size of the UTF-8 formatted localized name
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_file_entry_extension_get_utf8_localized_name_size(
     libfwsi_extension_block_t *file_entry_extension,
     size_t *utf8_string_size,
     libfwsi_error_t **error );

/* Retrieves the UTF-8 formatted localized name
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_file_entry_extension_get_utf8_localized_name(
     libfwsi_extension_block_t *file_entry_extension,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     libfwsi_error_t **error );

/* Retrieves the size of the UTF-16 formatted localized name
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_file_entry_extension_get_utf16_localized_name_size(
     libfwsi_extension_block_t *file_entry_extension,
     size_t *utf16_string_size,
     libfwsi_error_t **error );

/* Retrieves the UTF-16 formatted localized name
 * Returns 1 if successful, 0 if not available or -1 on error
 */
LIBFWSI_EXTERN \
int libfwsi_file_entry_extension_get_utf16_localized_name(
     libfwsi_extension_block_t *file_entry_extension,
     uint16_t *utf16_string,
     size_t utf16_string_size,
     libfwsi_error_t **error );

/* -------------------------------------------------------------------------
 * Shell folder identifier functions
 * ------------------------------------------------------------------------- */

/* Retrieves a string containing the name of the folder identifier
 */
LIBFWSI_EXTERN \
const char *libfwsi_shell_folder_identifier_get_name(
             const uint8_t *shell_folder_identifier );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFWSI_H ) */

