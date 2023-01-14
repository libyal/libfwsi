/*
 * Shell folder identifier functions
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

#if !defined( _LIBFWSI_SHELL_FOLDER_IDENTIFIER_H )
#define _LIBFWSI_SHELL_FOLDER_IDENTIFIER_H

#include <common.h>
#include <types.h>

#include "libfwsi_extern.h"
#include "libfwsi_libcerror.h"

#if defined( __cplusplus )
extern "C" {
#endif

/* The CLSID is stored as a little endian GUID
 */
typedef struct libfwsi_shell_folder_identifier_definition libfwsi_shell_folder_identifier_definition_t;

struct libfwsi_shell_folder_identifier_definition
{
	/* The folder identifier
	 */
	uint8_t *identifier;

	/* The folder name
	 */
	const char *name;
};

extern uint8_t libfwsi_shell_folder_identifier_briefcase[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_computer_and_devices[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_common_places[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_control_panel[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_control_panel_desktop[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_control_panel_vista[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_file_explorer[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_games_explorer[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_help_and_support[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_internet_explorer[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_my_computer[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_my_documents[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_my_network_places[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_network_and_sharing_center[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_network_connections[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_parential_controls[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_printer_and_faxes[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_portable_devices[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_programs_and_features[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_public[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_recent_places[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_recycle_bin[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_run[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_search_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_search_home[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_shared_documents[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_show_desktop[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_system[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_taskbar[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_users_libraries[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_window_switcher[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_windows_update[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_unknown[ 16 ];

LIBFWSI_EXTERN \
const char *libfwsi_shell_folder_identifier_get_name(
             const uint8_t *shell_folder_identifier );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFWSI_SHELL_FOLDER_IDENTIFIER_H ) */

