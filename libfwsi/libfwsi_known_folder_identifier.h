/*
 * Known folder identifier functions
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

#if !defined( _LIBFWSI_KNOWN_FOLDER_IDENTIFIER_H )
#define _LIBFWSI_KNOWN_FOLDER_IDENTIFIER_H

#include <common.h>
#include <types.h>

#include "libfwsi_extern.h"
#include "libfwsi_libcerror.h"

#if defined( __cplusplus )
extern "C" {
#endif

/* The CLSID is stored as a little endian GUID
 */
typedef struct libfwsi_known_folder_identifier_definition libfwsi_known_folder_identifier_definition_t;

struct libfwsi_known_folder_identifier_definition
{
	/* The folder identifier
	 */
	uint8_t *identifier;

	/* The folder name
	 */
	const char *name;
};

extern uint8_t libfwsi_known_folder_identifier_common_files[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_common_places[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_documents[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_documents_library[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_downloads[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_music[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_music_public[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_pictures[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_pictures_public[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_program_files[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_program_files_x86[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_public[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_saved_searches[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_system32[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_system32_x86[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_user_files[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_videos_public[ 16 ];
extern uint8_t libfwsi_known_folder_identifier_windows[ 16 ];

LIBFWSI_EXTERN \
const char *libfwsi_known_folder_identifier_get_name(
             const uint8_t *known_folder_identifier );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFWSI_KNOWN_FOLDER_IDENTIFIER_H ) */

