/*
 * Known folder identifier functions
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

#include "libfwsi_known_folder_identifier.h"
#include "libfwsi_libcerror.h"

uint8_t libfwsi_known_folder_identifier_common_files[ 16 ] = {
	0x24, 0x4d, 0x97, 0xde, 0xc6, 0xd9, 0x3e, 0x4d, 0xbf, 0x91, 0xf4, 0x45, 0x51, 0x20, 0xb9, 0x17 };

uint8_t libfwsi_known_folder_identifier_common_places[ 16 ] = {
	0x80, 0xa6, 0x3c, 0x32, 0x4d, 0xc2, 0x99, 0x40, 0xb9, 0x4d, 0x44, 0x6d, 0xd2, 0xd7, 0x24, 0x9e };

uint8_t libfwsi_known_folder_identifier_documents[ 16 ] = {
	0xd0, 0x9a, 0xd3, 0xfd, 0x8f, 0x23, 0xaf, 0x46, 0xad, 0xb4, 0x6c, 0x85, 0x48, 0x03, 0x69, 0xc7 };

uint8_t libfwsi_known_folder_identifier_documents_library[ 16 ] = {
	0x7d, 0xb1, 0x0d, 0x7b, 0xd2, 0x9c, 0x93, 0x4a, 0x97, 0x33, 0x46, 0xcc, 0x89, 0x02, 0x2e, 0x7c };

uint8_t libfwsi_known_folder_identifier_downloads[ 16 ] = {
	0x90, 0xe2, 0x4d, 0x37, 0x3f, 0x12, 0x65, 0x45, 0x91, 0x64, 0x39, 0xc4, 0x92, 0x5e, 0x46, 0x7b };

uint8_t libfwsi_known_folder_identifier_music[ 16 ] = {
	0x71, 0xd5, 0xd8, 0x4b, 0x19, 0x6d, 0xd3, 0x48, 0xbe, 0x97, 0x42, 0x22, 0x20, 0x08, 0x0e, 0x43 };

uint8_t libfwsi_known_folder_identifier_music_public[ 16 ] = {
	0xb5, 0xfa, 0x14, 0x32, 0x57, 0x97, 0x98, 0x42, 0xbb, 0x61, 0x92, 0xa9, 0xde, 0xaa, 0x44, 0xff };

uint8_t libfwsi_known_folder_identifier_pictures[ 16 ] = {
	0x30, 0x81, 0xe2, 0x33, 0x1e, 0x4e, 0x76, 0x46, 0x83, 0x5a, 0x98, 0x39, 0x5c, 0x3b, 0xc3, 0xbb };

uint8_t libfwsi_known_folder_identifier_pictures_public[ 16 ] = {
	0x86, 0xfb, 0xeb, 0xb6, 0x07, 0x69, 0x3c, 0x41, 0x9a, 0xf7, 0x4f, 0xc2, 0xab, 0xf0, 0x7c, 0xc5 };

uint8_t libfwsi_known_folder_identifier_program_files[ 16 ] = {
	0xb6, 0x63, 0x5e, 0x90, 0xbf, 0xc1, 0x4e, 0x49, 0xb2, 0x9c, 0x65, 0xb7, 0x32, 0xd3, 0xd2, 0x1a };

uint8_t libfwsi_known_folder_identifier_program_files_x86[ 16 ] = {
	0xef, 0x40, 0x5a, 0x7c, 0xfb, 0xa0, 0xfc, 0x4b, 0x87, 0x4a, 0xc0, 0xf2, 0xe0, 0xb9, 0xfa, 0x8e };

uint8_t libfwsi_known_folder_identifier_public[ 16 ] = {
	0xa2, 0x76, 0xdf, 0xdf, 0x2a, 0xc8, 0x63, 0x4d, 0x90, 0x6a, 0x56, 0x44, 0xac, 0x45, 0x73, 0x85 };

uint8_t libfwsi_known_folder_identifier_saved_searches[ 16 ] = {
	0x04, 0x3a, 0x1d, 0x7d, 0xbb, 0xde, 0x15, 0x41, 0x95, 0xcf, 0x2f, 0x29, 0xda, 0x29, 0x20, 0xda };

uint8_t libfwsi_known_folder_identifier_system32[ 16 ] = {
	0x77, 0x4e, 0xc1, 0x1a, 0xe7, 0x02, 0x5d, 0x4e, 0xb7, 0x44, 0x2e, 0xb1, 0xae, 0x51, 0x98, 0xb7 };

uint8_t libfwsi_known_folder_identifier_system32_x86[ 16 ] = {
	0xb0, 0x31, 0x52, 0xd6, 0xf1, 0xb2, 0x57, 0x48, 0xa4, 0xce, 0xa8, 0xe7, 0xc6, 0xea, 0x7d, 0x27 };

uint8_t libfwsi_known_folder_identifier_user_files[ 16 ] = {
	0x7c, 0x0f, 0xce, 0xf3, 0x01, 0x49, 0xcc, 0x4a, 0x86, 0x48, 0xd5, 0xd4, 0x4b, 0x04, 0xef, 0x8f };

uint8_t libfwsi_known_folder_identifier_videos_public[ 16 ] = {
	0x3a, 0x18, 0x00, 0x24, 0x85, 0x61, 0xfb, 0x49, 0xa2, 0xd8, 0x4a, 0x39, 0x2a, 0x60, 0x2b, 0xa3 };

uint8_t libfwsi_known_folder_identifier_windows[ 16 ] = {
	0x04, 0xf4, 0x8b, 0xf3, 0x43, 0x1d, 0xf2, 0x42, 0x93, 0x05, 0x67, 0xde, 0x0b, 0x28, 0xfc, 0x23 };

uint8_t libfwsi_known_folder_identifier_unknown[ 16 ] = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };

/* The known folder identifiers
 */
libfwsi_known_folder_identifier_definition_t libfwsi_known_folder_identifier_definitions[ ] = {
	{ libfwsi_known_folder_identifier_common_files,			"Common Files" },
	{ libfwsi_known_folder_identifier_common_places,		"Common Places" },
	{ libfwsi_known_folder_identifier_documents,			"Documents" },
	{ libfwsi_known_folder_identifier_downloads,			"Downloads" },
	{ libfwsi_known_folder_identifier_documents_library,		"Documents (Library)" },
	{ libfwsi_known_folder_identifier_music,			"Music" },
	{ libfwsi_known_folder_identifier_music_public,			"Public Music" },
	{ libfwsi_known_folder_identifier_pictures,			"Pictures" },
	{ libfwsi_known_folder_identifier_pictures_public,		"Public Pictures" },
	{ libfwsi_known_folder_identifier_program_files,		"Program Files" },
	{ libfwsi_known_folder_identifier_program_files_x86,		"Program Files (x86)" },
	{ libfwsi_known_folder_identifier_public,			"Public" },
	{ libfwsi_known_folder_identifier_saved_searches,		"Saved Searches" },
	{ libfwsi_known_folder_identifier_system32,			"System32" },
	{ libfwsi_known_folder_identifier_system32_x86,			"System32 (x86)" },
	{ libfwsi_known_folder_identifier_user_files,			"User's Files" },
	{ libfwsi_known_folder_identifier_videos_public,		"Public Videos" },
	{ libfwsi_known_folder_identifier_windows,			"Windows" },

	{ libfwsi_known_folder_identifier_unknown,			"Unknown" } };

/* Retrieves a string containing the name of the folder identifier
 */
const char *libfwsi_known_folder_identifier_get_name(
             const uint8_t *known_folder_identifier )
{
	int iterator = 0;

	if( known_folder_identifier == NULL )
	{
		return( "Invalid known folder identifier" );
	}
	while( memory_compare(
	        ( libfwsi_known_folder_identifier_definitions[ iterator ] ).identifier,
	        libfwsi_known_folder_identifier_unknown,
	        16 ) != 0 )
	{
		if( memory_compare(
		     ( libfwsi_known_folder_identifier_definitions[ iterator ] ).identifier,
		     known_folder_identifier,
		     16 ) == 0 )
		{
			break;
		}
		iterator++;
	}
	return(
	 ( libfwsi_known_folder_identifier_definitions[ iterator ] ).name );
}

