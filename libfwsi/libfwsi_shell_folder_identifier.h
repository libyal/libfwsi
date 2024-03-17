/*
 * Shell folder identifier functions
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

extern uint8_t libfwsi_shell_folder_identifier_3d_objects[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_activex_cache_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_add_network_place[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_administrative_tools[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_all_control_panel_items[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_all_tasks[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_all_tasks2[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_application_suggested_locations[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_applications[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_autoplay[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_backup_and_restore[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_backup_and_restore_center[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_biometrics[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_bluetooth_devices[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_briefcase[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_cabinet_file[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_command_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_common_places_fs_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_compressed_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_computer_delegate_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_computer_search_results_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_computers_and_devices[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_control_panel[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_control_panel_command_object_for_start_menu_and_desktop[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_credential_manager[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_db_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_default_location[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_desktop[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_device_center[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_device_center_initialization[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_devicepairingfolder_initialization[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_directory[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_display[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_dlna_content_directory_data_source[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_dlna_media_servers_data_source[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_dxp[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_ease_of_access[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_ecs[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_email[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_enhanced_storage_data_source[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_explorer_browser_results_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_extensions_manager_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_favorites[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_feedback_tool[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_file_backup_index[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_file_explorer[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_file_history_data_source[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_folder_options[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_folder_shortcut[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_font_settings[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_fonts[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_frequent_places_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_fusion_cache[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_games_explorer[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_help_and_support[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_history[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_history2[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_history3[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_history4[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_history_vault[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_home_group_control_panel[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_inbox[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_inbox2[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_install_new_programs[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_installed_updates[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_internet[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_internet_explorer[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_internet_explorer_history_and_feeds_shell_data_source_for_windows_search[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_internet_explorer_rss_feeds_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_internet_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_language_settings[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_layout_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_libraries_users_files_folder_delegate_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_library_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_location_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_manage_wireless_networks[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_microsoft_browser_architecture[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_microsoft_browser_architecture2[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_microsoft_ftp_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_microsoft_office_outlook[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_microsoft_onenote_namespace_extension_for_windows_desktop_search[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_microsoft_windows_font_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_mobile_broadband_profile_settings_editor[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_mobility_center_control_panel[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_ms_graph_recent_file_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_my_computer[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_my_documents[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_my_network_places[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_network_and_dialup_connections[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_network_and_dialup_connections2[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_network_and_sharing_center[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_network_map[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_network_setup_wizard[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_offline_files[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_offline_files_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_other_users_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_other_users_folder2[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_parental_controls[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_pc_settings[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_performance_information_and_tools[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_personalization_control_panel[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_portable_devices[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_portable_media_devices[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_power_options[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_previous_versions[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_previous_versions_delegate_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_previous_versions_results_delegate_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_previous_versions_results_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_printers_and_faxes[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_printhood_delegate_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_programs_and_features[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_programs_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_programs_folder_and_fast_items[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_proximity_cpl[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_public_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_quick_access[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_recent_items_instance_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_recent_places_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_recycle_bin[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_remote_printers[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_removable_drives[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_removable_storage_devices[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_results_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_run[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_scanners_and_cameras[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_scanners_and_cameras2[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_scheduled_tasks[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_search[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_search_connector_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_search_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_search_home[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_search_results[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_secure_startup[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_security_and_maintenance_cpl[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_security_center[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_sensors[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_server_manager[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_set_program_access_and_defaults[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_set_user_defaults[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_shared_documents_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_shell_docobject_viewer[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_shell_favorite_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_shell_file_system_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_shell_file_system_folder2[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_shell_file_system_netfolder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_shell_storage_folder_viewer[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_show_desktop[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_skydrive[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_softex_omnipass_encrypted_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_solidworks_enterprise_pdm[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_speech_recognition[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_start_menu_all_programs[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_start_menu_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_sticky_notes_namespace_extension_for_windows_desktop_search[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_storage_spaces[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_stream_backed_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_subscription_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_sync_center_conflict_delegate_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_sync_center_conflict_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_sync_center_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_sync_results_delegate_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_sync_results_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_sync_setup_delegate_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_sync_setup_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_system[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_system_recovery[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_system_restore[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_taskbar[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_taskbar_and_start_menu[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_temporary_internet_files[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_temporary_internet_files2[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_this_device[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_this_device2[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_this_pc[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_tree_property_value_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_troubleshooting[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_uncfatshellfolder_class[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_user_accounts[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_user_pinned[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_users_and_passwords[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_users_files_folder_delegate_folder[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_users_libraries[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_web_folders[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_welcome_center[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_window_switcher[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_windows_anytime_upgrade[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_windows_defender[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_windows_desktop_search[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_windows_desktop_search_mapi_namespace_extension_class[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_windows_features[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_windows_firewall[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_windows_search_service_media_center_namespace_extension_handler[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_windows_search_service_outlook_express_protocol_handler[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_windows_security[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_windows_sideshow[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_windows_update[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_workspaces_center[ 16 ];

extern uint8_t libfwsi_shell_folder_identifier_empty[ 16 ];
extern uint8_t libfwsi_shell_folder_identifier_unknown[ 16 ];

LIBFWSI_EXTERN \
const char *libfwsi_shell_folder_identifier_get_name(
             const uint8_t *shell_folder_identifier );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFWSI_SHELL_FOLDER_IDENTIFIER_H ) */

