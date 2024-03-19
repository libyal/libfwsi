/*
 * Control panel item identifier functions
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

#if !defined( _LIBFWSI_CONTROL_PANEL_ITEM_IDENTIFIER_H )
#define _LIBFWSI_CONTROL_PANEL_ITEM_IDENTIFIER_H

#include <common.h>
#include <types.h>

#include "libfwsi_extern.h"
#include "libfwsi_libcerror.h"

#if defined( __cplusplus )
extern "C" {
#endif

/* The CLSID is stored as a little endian GUID
 */
typedef struct libfwsi_control_panel_item_identifier_definition libfwsi_control_panel_item_identifier_definition_t;

struct libfwsi_control_panel_item_identifier_definition
{
	/* The identifier
	 */
	uint8_t *identifier;

	/* The name
	 */
	const char *name;
};

extern uint8_t libfwsi_control_panel_item_identifier_action_center_cpl[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_add_new_hardware[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_administrative_tools[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_autoplay[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_backup_and_restore[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_backup_and_restore_center[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_biometrics[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_cardspace[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_color_management[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_company_settings_sync[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_credential_manager[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_date_and_time[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_device_center[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_device_manager[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_dialup_networking[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_display[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_ease_of_access[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_ecs[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_folder_options[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_font_folder[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_fonts[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_get_programs_online[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_history_vault[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_homegroup_control_panel[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_indexing_options[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_infrared[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_install_new_programs[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_internet_options[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_iscsi_initiator[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_keyboard[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_language_settings[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_mobility_center[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_mouse[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_network_and_sharing_center[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_network_connections[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_network_map[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_parental_controls[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_pen_and_touch[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_performance_information_and_tools[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_personalization[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_phone_and_modem[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_portable_media_devices[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_portable_workspace_creator[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_power_options[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_printers[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_problem_reports_and_solutions[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_programs_and_features[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_recovery[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_region_and_language[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_scanner_and_camera_control_panel[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_scanners_and_cameras[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_scheduled_tasks[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_secure_startup[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_sensors[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_set_user_defaults[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_sound[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_speech_recognition[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_storage_spaces[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_sync_center_folder[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_system[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_tablet_pc_settings[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_taskbar_and_start_menu[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_taskbar_notification_icons_control_panel[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_text_to_speech[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_troubleshooting[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_user_accounts[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_view_available_networks[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_welcome_center[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_windows_anytime_upgrade[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_windows_defender[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_windows_firewall[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_windows_sidebar_properties[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_windows_sideshow[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_windows_update[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_workspaces_center[ 16 ];
extern uint8_t libfwsi_control_panel_item_identifier_x86_control_panel[ 16 ];

extern uint8_t libfwsi_control_panel_item_identifier_unknown[ 16 ];

LIBFWSI_EXTERN \
const char *libfwsi_control_panel_item_identifier_get_name(
             const uint8_t *control_panel_item_identifier );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFWSI_CONTROL_PANEL_ITEM_IDENTIFIER_H ) */

