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

#include <common.h>
#include <memory.h>
#include <types.h>

#include "libfwsi_control_panel_item_identifier.h"
#include "libfwsi_libcerror.h"

uint8_t libfwsi_control_panel_item_identifier_action_center_cpl[ 16 ] = {
	0xa7, 0xf8, 0x64, 0xbb, 0xe7, 0xbe, 0x1a, 0x4e, 0xab, 0x8d, 0x7d, 0x82, 0x73, 0xf7, 0xfd, 0xb6 };

uint8_t libfwsi_control_panel_item_identifier_add_new_hardware[ 16 ] = {
	0x62, 0x92, 0x97, 0x7a, 0xce, 0x40, 0xff, 0x46, 0xae, 0xee, 0x78, 0x84, 0xac, 0x3b, 0x61, 0x36 };

uint8_t libfwsi_control_panel_item_identifier_administrative_tools[ 16 ] = {
	0xe1, 0xa4, 0x0e, 0xd2, 0x57, 0x39, 0xd2, 0x11, 0xa4, 0x0b, 0x0c, 0x50, 0x20, 0x52, 0x41, 0x53 };

uint8_t libfwsi_control_panel_item_identifier_autoplay[ 16 ] = {
	0x1e, 0xde, 0x60, 0x9c, 0xfc, 0xe5, 0xf4, 0x40, 0xa4, 0x87, 0x46, 0x08, 0x51, 0xa8, 0xd9, 0x15 };

uint8_t libfwsi_control_panel_item_identifier_backup_and_restore[ 16 ] = {
	0xea, 0x2b, 0x8a, 0xb9, 0x42, 0x7d, 0x58, 0x45, 0x8b, 0xd1, 0x83, 0x2f, 0x41, 0xba, 0xc6, 0xfd };

uint8_t libfwsi_control_panel_item_identifier_backup_and_restore_center[ 16 ] = {
	0xdd, 0x31, 0x5a, 0x33, 0x4b, 0xf0, 0x76, 0x4d, 0xa9, 0x25, 0xd6, 0xb4, 0x7c, 0xf3, 0x60, 0xdf };

uint8_t libfwsi_control_panel_item_identifier_biometrics[ 16 ] = {
	0xd0, 0xe4, 0x42, 0x01, 0x7a, 0xfb, 0xdc, 0x11, 0xba, 0x4a, 0x00, 0x0f, 0xfe, 0x7a, 0xb4, 0x28 };

uint8_t libfwsi_control_panel_item_identifier_cardspace[ 16 ] = {
	0x7a, 0x14, 0xcb, 0x78, 0xea, 0x98, 0xa6, 0x4a, 0xb0, 0xdf, 0xc8, 0x68, 0x1f, 0x69, 0x34, 0x1c };

uint8_t libfwsi_control_panel_item_identifier_color_management[ 16 ] = {
	0xc6, 0x61, 0xc7, 0xb2, 0xbc, 0x29, 0x19, 0x4f, 0x92, 0x51, 0xe6, 0x19, 0x52, 0x65, 0xba, 0xf1 };

uint8_t libfwsi_control_panel_item_identifier_company_settings_sync[ 16 ] = {
	0x62, 0xab, 0xf2, 0x98, 0x29, 0x0e, 0x4c, 0x4e, 0x8e, 0xe7, 0xb5, 0x42, 0xe6, 0x67, 0x40, 0xb1 };

uint8_t libfwsi_control_panel_item_identifier_credential_manager[ 16 ] = {
	0xf1, 0xf5, 0x06, 0x12, 0x69, 0x05, 0x2c, 0x41, 0x8f, 0xec, 0x32, 0x04, 0x63, 0x0d, 0xfb, 0x70 };

uint8_t libfwsi_control_panel_item_identifier_date_and_time[ 16 ] = {
	0x4b, 0x93, 0xe7, 0xe2, 0xe5, 0xdc, 0xc4, 0x43, 0x95, 0x76, 0x7f, 0xe4, 0xf7, 0x5e, 0x74, 0x80 };

uint8_t libfwsi_control_panel_item_identifier_device_center[ 16 ] = {
	0x66, 0x1a, 0xa9, 0xa8, 0x7d, 0x3a, 0x24, 0x44, 0x8d, 0x24, 0x04, 0xe1, 0x80, 0x69, 0x5c, 0x7a };

uint8_t libfwsi_control_panel_item_identifier_device_manager[ 16 ] = {
	0xfc, 0x6b, 0x24, 0x74, 0x96, 0x4c, 0xd0, 0x11, 0xab, 0xef, 0x00, 0x20, 0xaf, 0x6b, 0x0b, 0x7a };

uint8_t libfwsi_control_panel_item_identifier_dialup_networking[ 16 ] = {
	0xa0, 0xff, 0x2c, 0x99, 0x57, 0xf5, 0x1a, 0x10, 0x88, 0xec, 0x00, 0xdd, 0x01, 0x0c, 0xcc, 0x48 };

uint8_t libfwsi_control_panel_item_identifier_display[ 16 ] = {
	0x8b, 0x43, 0x55, 0xc5, 0x23, 0x3c, 0x69, 0x47, 0xa7, 0x1f, 0xb6, 0xd3, 0xd9, 0xb6, 0x05, 0x3a };

uint8_t libfwsi_control_panel_item_identifier_ease_of_access[ 16 ] = {
	0x5e, 0x64, 0x55, 0xd5, 0xf8, 0xd4, 0x29, 0x4c, 0xa8, 0x27, 0xd9, 0x3c, 0x85, 0x9c, 0x4f, 0x2a };

uint8_t libfwsi_control_panel_item_identifier_ecs[ 16 ] = {
	0x24, 0x09, 0xdb, 0xec, 0x08, 0x42, 0x1e, 0x45, 0x8e, 0xe0, 0x37, 0x3c, 0x09, 0x56, 0xde, 0x16 };

uint8_t libfwsi_control_panel_item_identifier_folder_options[ 16 ] = {
	0x5c, 0x7c, 0xfd, 0x6d, 0x51, 0x24, 0xd3, 0x11, 0xa2, 0x99, 0x00, 0xc0, 0x4f, 0x8e, 0xf6, 0xaf };

uint8_t libfwsi_control_panel_item_identifier_font_folder[ 16 ] = {
	0x80, 0xb3, 0x84, 0xbd, 0xa2, 0x8c, 0x69, 0x10, 0xab, 0x1d, 0x08, 0x00, 0x09, 0x48, 0xf5, 0x34 };

uint8_t libfwsi_control_panel_item_identifier_fonts[ 16 ] = {
	0xe1, 0xa4, 0x0e, 0xd2, 0x57, 0x39, 0xd2, 0x11, 0xa4, 0x0b, 0x0c, 0x50, 0x20, 0x52, 0x41, 0x52 };

uint8_t libfwsi_control_panel_item_identifier_get_programs_online[ 16 ] = {
	0x4c, 0xfb, 0x7e, 0x3e, 0xf1, 0xfa, 0x3d, 0x45, 0x89, 0xeb, 0x56, 0x02, 0x68, 0x75, 0xef, 0x90 };

uint8_t libfwsi_control_panel_item_identifier_history_vault[ 16 ] = {
	0x65, 0xe9, 0xb6, 0xf6, 0xb2, 0xe9, 0x4b, 0x44, 0x92, 0x86, 0x10, 0xc9, 0x15, 0x2e, 0xdb, 0xc5 };

uint8_t libfwsi_control_panel_item_identifier_homegroup_control_panel[ 16 ] = {
	0x50, 0x76, 0xca, 0x67, 0xe6, 0x96, 0xdd, 0x4f, 0xbb, 0x43, 0xa8, 0xe7, 0x74, 0xf7, 0x3a, 0x57 };

uint8_t libfwsi_control_panel_item_identifier_indexing_options[ 16 ] = {
	0x43, 0x6a, 0xd6, 0x87, 0x11, 0x7b, 0x28, 0x4a, 0x98, 0x11, 0xc8, 0x6e, 0xe3, 0x95, 0xac, 0xf7 };

uint8_t libfwsi_control_panel_item_identifier_infrared[ 16 ] = {
	0x11, 0x55, 0x27, 0xa0, 0x86, 0x0e, 0xca, 0x4e, 0x97, 0xc2, 0xec, 0xd8, 0xf1, 0x22, 0x1d, 0x08 };

uint8_t libfwsi_control_panel_item_identifier_install_new_programs[ 16 ] = {
	0x2e, 0xe9, 0xea, 0x15, 0x7a, 0xf1, 0x31, 0x44, 0x9f, 0x28, 0x80, 0x5e, 0x48, 0x2d, 0xaf, 0xd4 };

uint8_t libfwsi_control_panel_item_identifier_internet_options[ 16 ] = {
	0x92, 0x4f, 0xdd, 0xa3, 0x8a, 0x65, 0x0f, 0x41, 0x84, 0xfd, 0x6f, 0xbb, 0xbe, 0xf2, 0xff, 0xfe };

uint8_t libfwsi_control_panel_item_identifier_iscsi_initiator[ 16 ] = {
	0x9d, 0x25, 0x04, 0xa3, 0xb8, 0x52, 0x26, 0x45, 0x8b, 0x1a, 0xa1, 0xd6, 0xce, 0xcc, 0x82, 0x43 };

uint8_t libfwsi_control_panel_item_identifier_keyboard[ 16 ] = {
	0xf7, 0xe8, 0x5b, 0x72, 0x8e, 0x66, 0x7b, 0x4c, 0x8f, 0x90, 0x46, 0xbd, 0xb0, 0x93, 0x64, 0x30 };

uint8_t libfwsi_control_panel_item_identifier_language_settings[ 16 ] = {
	0xc9, 0x2c, 0x78, 0xbf, 0x52, 0x5a, 0x17, 0x4a, 0x80, 0x6c, 0x2a, 0x89, 0x4f, 0xfe, 0xea, 0xc5 };

uint8_t libfwsi_control_panel_item_identifier_mobility_center[ 16 ] = {
	0x48, 0xf1, 0xa4, 0x5e, 0x8c, 0x30, 0xd7, 0x46, 0x98, 0xa9, 0x49, 0x04, 0x1b, 0x1d, 0xd4, 0x68 };

uint8_t libfwsi_control_panel_item_identifier_mouse[ 16 ] = {
	0x18, 0xec, 0x8e, 0x6c, 0x75, 0x8d, 0xb2, 0x41, 0xa1, 0x77, 0x88, 0x31, 0xd5, 0x9d, 0x2d, 0x50 };

uint8_t libfwsi_control_panel_item_identifier_network_and_sharing_center[ 16 ] = {
	0xc9, 0x8f, 0x90, 0x8e, 0xcc, 0xbe, 0xf6, 0x40, 0x91, 0x5b, 0xf4, 0xca, 0x0e, 0x70, 0xd0, 0x3d };

uint8_t libfwsi_control_panel_item_identifier_network_connections[ 16 ] = {
	0xc7, 0xac, 0x07, 0x70, 0x02, 0x32, 0xd1, 0x11, 0xaa, 0xd2, 0x00, 0x80, 0x5f, 0xc1, 0x27, 0x0e };

uint8_t libfwsi_control_panel_item_identifier_network_map[ 16 ] = {
	0x1a, 0x9b, 0xde, 0xe7, 0x33, 0x75, 0x56, 0x45, 0x94, 0x84, 0xb2, 0x6f, 0xb4, 0x86, 0x47, 0x5e };

uint8_t libfwsi_control_panel_item_identifier_parental_controls[ 16 ] = {
	0x84, 0x8d, 0xae, 0x96, 0x50, 0xa2, 0x20, 0x45, 0x95, 0xa5, 0xa4, 0x7a, 0x7e, 0x3c, 0x54, 0x8b };

uint8_t libfwsi_control_panel_item_identifier_pen_and_touch[ 16 ] = {
	0xf7, 0xf8, 0x2d, 0xf8, 0x9f, 0x8b, 0x2e, 0x44, 0xa4, 0x8c, 0x81, 0x8e, 0xa7, 0x35, 0xff, 0x9b };

uint8_t libfwsi_control_panel_item_identifier_performance_information_and_tools[ 16 ] = {
	0x5e, 0x95, 0xf3, 0x78, 0x90, 0x3b, 0x84, 0x41, 0xbd, 0x14, 0x53, 0x97, 0xc1, 0x5f, 0x1e, 0xfc };

uint8_t libfwsi_control_panel_item_identifier_personalization[ 16 ] = {
	0xd6, 0x4e, 0x83, 0xed, 0x5a, 0x4b, 0xfe, 0x4b, 0x8f, 0x11, 0xa6, 0x26, 0xdc, 0xb6, 0xa9, 0x21 };

uint8_t libfwsi_control_panel_item_identifier_phone_and_modem[ 16 ] = {
	0x85, 0x94, 0x41, 0x40, 0x44, 0xc4, 0x67, 0x45, 0x85, 0x1a, 0x2d, 0xd7, 0xbf, 0xa1, 0x68, 0x4d };

uint8_t libfwsi_control_panel_item_identifier_portable_media_devices[ 16 ] = {
	0xb4, 0x67, 0x01, 0x64, 0xb0, 0x59, 0xa6, 0x47, 0xb3, 0x35, 0xa6, 0xb3, 0xc0, 0x69, 0x5a, 0xea };

uint8_t libfwsi_control_panel_item_identifier_portable_workspace_creator[ 16 ] = {
	0x9d, 0x27, 0x0c, 0x8e, 0xd1, 0x0b, 0xc3, 0x43, 0x9e, 0xbd, 0x31, 0xc3, 0xdc, 0x5b, 0x8a, 0x77 };

uint8_t libfwsi_control_panel_item_identifier_power_options[ 16 ] = {
	0x37, 0x59, 0x5a, 0x02, 0xbe, 0xa6, 0x86, 0x46, 0xa8, 0x44, 0x36, 0xfe, 0x4b, 0xec, 0x8b, 0x6d };

uint8_t libfwsi_control_panel_item_identifier_printers[ 16 ] = {
	0x80, 0xa2, 0x27, 0x22, 0xea, 0x3a, 0x69, 0x10, 0xa2, 0xde, 0x08, 0x00, 0x2b, 0x30, 0x30, 0x9d };

uint8_t libfwsi_control_panel_item_identifier_problem_reports_and_solutions[ 16 ] = {
	0xae, 0xec, 0xfe, 0xfc, 0x1b, 0xee, 0x49, 0x48, 0xae, 0x50, 0x68, 0x5d, 0xcf, 0x77, 0x17, 0xec };

uint8_t libfwsi_control_panel_item_identifier_programs_and_features[ 16 ] = {
	0x6a, 0xbe, 0x81, 0x7b, 0x2b, 0xce, 0x76, 0x46, 0xa2, 0x9e, 0xeb, 0x90, 0x7a, 0x51, 0x26, 0xc5 };

uint8_t libfwsi_control_panel_item_identifier_recovery[ 16 ] = {
	0xfd, 0x3a, 0xe6, 0x9f, 0xcf, 0x59, 0x19, 0x44, 0x97, 0x75, 0xab, 0xcc, 0x38, 0x49, 0xf8, 0x61 };

uint8_t libfwsi_control_panel_item_identifier_region_and_language[ 16 ] = {
	0x13, 0xed, 0xd8, 0x62, 0xd0, 0xc9, 0xe8, 0x4c, 0xa9, 0x14, 0x47, 0xdd, 0x62, 0x8f, 0xb1, 0xb0 };

uint8_t libfwsi_control_panel_item_identifier_scanner_and_camera_control_panel[ 16 ] = {
	0x6f, 0x88, 0xf2, 0x00, 0x64, 0xcd, 0xc9, 0x4f, 0x8e, 0xc5, 0x30, 0xef, 0x6c, 0xdb, 0xe8, 0xc3 };

uint8_t libfwsi_control_panel_item_identifier_scanners_and_cameras[ 16 ] = {
	0x36, 0xb7, 0x11, 0xe2, 0xfd, 0x43, 0xd1, 0x11, 0x9e, 0xfb, 0x00, 0x00, 0xf8, 0x75, 0x7f, 0xcd };

uint8_t libfwsi_control_panel_item_identifier_scheduled_tasks[ 16 ] = {
	0x90, 0x79, 0x27, 0xd6, 0x6a, 0x4c, 0xcf, 0x11, 0x8d, 0x87, 0x00, 0xaa, 0x00, 0x60, 0xf5, 0xbf };

uint8_t libfwsi_control_panel_item_identifier_secure_startup[ 16 ] = {
	0x27, 0x87, 0xef, 0xd9, 0xc2, 0xca, 0x60, 0x4e, 0x80, 0x9e, 0x86, 0xf8, 0x0a, 0x66, 0x6c, 0x91 };

uint8_t libfwsi_control_panel_item_identifier_sensors[ 16 ] = {
	0x54, 0x01, 0x95, 0xe9, 0x18, 0xc4, 0x9e, 0x41, 0xa9, 0x0a, 0x20, 0xc5, 0x28, 0x7a, 0xe2, 0x4b };

uint8_t libfwsi_control_panel_item_identifier_set_user_defaults[ 16 ] = {
	0x88, 0x94, 0xcd, 0x17, 0x28, 0x12, 0x2f, 0x4b, 0x88, 0xce, 0x42, 0x98, 0xe9, 0x3e, 0x09, 0x66 };

uint8_t libfwsi_control_panel_item_identifier_sound[ 16 ] = {
	0x82, 0xfc, 0xdd, 0xf2, 0x12, 0x8f, 0xdd, 0x4c, 0xb7, 0xdc, 0xd4, 0xfe, 0x14, 0x25, 0xaa, 0x4d };

uint8_t libfwsi_control_panel_item_identifier_speech_recognition[ 16 ] = {
	0x45, 0xc7, 0xe3, 0x58, 0x71, 0xd9, 0x81, 0x40, 0x90, 0x34, 0x86, 0xe3, 0x4b, 0x30, 0x83, 0x6a };

uint8_t libfwsi_control_panel_item_identifier_storage_spaces[ 16 ] = {
	0x06, 0xc6, 0x42, 0xf9, 0x14, 0x09, 0xab, 0x47, 0xbe, 0x56, 0x13, 0x21, 0xb8, 0x03, 0x50, 0x96 };

uint8_t libfwsi_control_panel_item_identifier_sync_center_folder[ 16 ] = {
	0xe5, 0xf5, 0x73, 0x9c, 0xe7, 0x7a, 0x32, 0x4e, 0xa8, 0xe8, 0x8d, 0x23, 0xb8, 0x52, 0x55, 0xbf };

uint8_t libfwsi_control_panel_item_identifier_system[ 16 ] = {
	0xe4, 0xc0, 0x06, 0xbb, 0x93, 0xd2, 0x75, 0x4f, 0x8a, 0x90, 0xcb, 0x05, 0xb6, 0x47, 0x7e, 0xee };

uint8_t libfwsi_control_panel_item_identifier_tablet_pc_settings[ 16 ] = {
	0xd5, 0xf1, 0xf3, 0x80, 0xca, 0xfe, 0xf3, 0x45, 0xbc, 0x32, 0x75, 0x2c, 0x15, 0x2e, 0x45, 0x6e };

uint8_t libfwsi_control_panel_item_identifier_taskbar_and_start_menu[ 16 ] = {
	0xaa, 0x4e, 0xf4, 0x0d, 0x21, 0xff, 0x12, 0x44, 0x82, 0x8e, 0x26, 0x0a, 0x87, 0x28, 0xe7, 0xf1 };

uint8_t libfwsi_control_panel_item_identifier_taskbar_notification_icons_control_panel[ 16 ] = {
	0xf4, 0xb0, 0xd7, 0x05, 0x21, 0x21, 0xff, 0x4e, 0xbf, 0x6b, 0xed, 0x3f, 0x69, 0xb8, 0x94, 0xd9 };

uint8_t libfwsi_control_panel_item_identifier_text_to_speech[ 16 ] = {
	0x6d, 0x1d, 0x7d, 0xd1, 0x3f, 0xcc, 0x15, 0x48, 0x8f, 0xe3, 0x60, 0x7e, 0x7d, 0x5d, 0x10, 0xb3 };

uint8_t libfwsi_control_panel_item_identifier_troubleshooting[ 16 ] = {
	0x93, 0x48, 0x8c, 0xc5, 0xe0, 0x3b, 0x45, 0x4b, 0xab, 0xb5, 0xa6, 0x3e, 0x4b, 0x8c, 0x86, 0x51 };

uint8_t libfwsi_control_panel_item_identifier_user_accounts[ 16 ] = {
	0x54, 0x27, 0x63, 0x60, 0x23, 0xc5, 0x62, 0x4b, 0xb4, 0x5c, 0x41, 0x72, 0xda, 0x01, 0x26, 0x19 };

uint8_t libfwsi_control_panel_item_identifier_view_available_networks[ 16 ] = {
	0x28, 0x85, 0xa9, 0x38, 0xbf, 0x6c, 0xa9, 0x4c, 0x8d, 0xc0, 0xb1, 0xe1, 0xd1, 0x0f, 0x7b, 0x1b };

uint8_t libfwsi_control_panel_item_identifier_welcome_center[ 16 ] = {
	0x8c, 0x7f, 0x1b, 0xcb, 0x0a, 0xc5, 0x76, 0x41, 0xb6, 0x04, 0x9e, 0x24, 0xde, 0xe8, 0xd4, 0xd1 };

uint8_t libfwsi_control_panel_item_identifier_windows_anytime_upgrade[ 16 ] = {
	0x0e, 0x2a, 0x12, 0xbe, 0x03, 0x45, 0xda, 0x11, 0x8b, 0xde, 0xf6, 0x6b, 0xad, 0x1e, 0x3f, 0x3a };

uint8_t libfwsi_control_panel_item_identifier_windows_defender[ 16 ] = {
	0xb9, 0x9e, 0x55, 0xd8, 0xc0, 0x20, 0x0e, 0x41, 0xbe, 0xda, 0x7e, 0xd4, 0x16, 0xae, 0xcc, 0x2a };

uint8_t libfwsi_control_panel_item_identifier_windows_firewall[ 16 ] = {
	0x2f, 0x49, 0x26, 0x40, 0x69, 0x2f, 0xb8, 0x46, 0xb9, 0xbf, 0x56, 0x54, 0xfc, 0x07, 0xe4, 0x23 };

uint8_t libfwsi_control_panel_item_identifier_windows_sidebar_properties[ 16 ] = {
	0x4d, 0xd4, 0xef, 0x37, 0x8d, 0xef, 0xb1, 0x41, 0x94, 0x0d, 0x96, 0x97, 0x3a, 0x50, 0xe9, 0xe0 };

uint8_t libfwsi_control_panel_item_identifier_windows_sideshow[ 16 ] = {
	0x61, 0x48, 0x5a, 0xe9, 0x7a, 0xd5, 0xe1, 0x4b, 0xad, 0x0f, 0x35, 0x26, 0x7e, 0x26, 0x17, 0x39 };

uint8_t libfwsi_control_panel_item_identifier_windows_update[ 16 ] = {
	0xdb, 0xf7, 0xee, 0x36, 0xad, 0x88, 0x81, 0x4e, 0xad, 0x49, 0x0e, 0x31, 0x3f, 0x0c, 0x35, 0xf8 };

uint8_t libfwsi_control_panel_item_identifier_workspaces_center[ 16 ] = {
	0x96, 0x7c, 0x1d, 0x24, 0xbf, 0xf8, 0x85, 0x4f, 0xb0, 0x1f, 0xe2, 0xb0, 0x43, 0x34, 0x1a, 0x4b };

uint8_t libfwsi_control_panel_item_identifier_x86_control_panel[ 16 ] = {
	0xa3, 0x81, 0xf5, 0x09, 0x64, 0x1f, 0x5b, 0x4e, 0x8d, 0xb3, 0x88, 0xf5, 0x59, 0x30, 0x80, 0xcc };


uint8_t libfwsi_control_panel_item_identifier_unknown[ 16 ] = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };

/* The control panel item identifiers
 */
libfwsi_control_panel_item_identifier_definition_t libfwsi_control_panel_item_identifier_definitions[ ] = {

	{ libfwsi_control_panel_item_identifier_action_center_cpl,
	  "Action Center CPL" },
	{ libfwsi_control_panel_item_identifier_add_new_hardware,
	  "Add New Hardware" },
	{ libfwsi_control_panel_item_identifier_administrative_tools,
	  "Administrative Tools" },
	{ libfwsi_control_panel_item_identifier_autoplay,
	  "AutoPlay" },
	{ libfwsi_control_panel_item_identifier_backup_and_restore,
	  "Backup And Restore" },
	{ libfwsi_control_panel_item_identifier_backup_and_restore_center,
	  "Backup and Restore Center" },
	{ libfwsi_control_panel_item_identifier_biometrics,
	  "Biometrics" },
	{ libfwsi_control_panel_item_identifier_cardspace,
	  "CardSpace" },
	{ libfwsi_control_panel_item_identifier_color_management,
	  "Color Management" },
	{ libfwsi_control_panel_item_identifier_company_settings_sync,
	  "Company Settings Sync" },
	{ libfwsi_control_panel_item_identifier_credential_manager,
	  "Credential Manager" },
	{ libfwsi_control_panel_item_identifier_date_and_time,
	  "Date and Time" },
	{ libfwsi_control_panel_item_identifier_device_center,
	  "Device Center" },
	{ libfwsi_control_panel_item_identifier_device_manager,
	  "Device Manager" },
	{ libfwsi_control_panel_item_identifier_dialup_networking,
	  "Dial-Up Networking" },
	{ libfwsi_control_panel_item_identifier_display,
	  "Display" },
	{ libfwsi_control_panel_item_identifier_ease_of_access,
	  "Ease of Access" },
	{ libfwsi_control_panel_item_identifier_ecs,
	  "ECS" },
	{ libfwsi_control_panel_item_identifier_folder_options,
	  "Folder Options" },
	{ libfwsi_control_panel_item_identifier_font_folder,
	  "Font Folder" },
	{ libfwsi_control_panel_item_identifier_fonts,
	  "Fonts" },
	{ libfwsi_control_panel_item_identifier_get_programs_online,
	  "Get Programs Online" },
	{ libfwsi_control_panel_item_identifier_history_vault,
	  "History Vault" },
	{ libfwsi_control_panel_item_identifier_homegroup_control_panel,
	  "HomeGroup Control Panel" },
	{ libfwsi_control_panel_item_identifier_indexing_options,
	  "Indexing Options" },
	{ libfwsi_control_panel_item_identifier_infrared,
	  "Infrared" },
	{ libfwsi_control_panel_item_identifier_install_new_programs,
	  "Install New Programs" },
	{ libfwsi_control_panel_item_identifier_internet_options,
	  "Internet Options" },
	{ libfwsi_control_panel_item_identifier_iscsi_initiator,
	  "iSCSI Initiator" },
	{ libfwsi_control_panel_item_identifier_keyboard,
	  "Keyboard" },
	{ libfwsi_control_panel_item_identifier_language_settings,
	  "Language Settings" },
	{ libfwsi_control_panel_item_identifier_mobility_center,
	  "Mobility Center" },
	{ libfwsi_control_panel_item_identifier_mouse,
	  "Mouse" },
	{ libfwsi_control_panel_item_identifier_network_and_sharing_center,
	  "Network and Sharing Center" },
	{ libfwsi_control_panel_item_identifier_network_connections,
	  "Network Connections" },
	{ libfwsi_control_panel_item_identifier_network_map,
	  "Network Map" },
	{ libfwsi_control_panel_item_identifier_parental_controls,
	  "Parental Controls" },
	{ libfwsi_control_panel_item_identifier_pen_and_touch,
	  "Pen and Touch" },
	{ libfwsi_control_panel_item_identifier_performance_information_and_tools,
	  "Performance Information and Tools" },
	{ libfwsi_control_panel_item_identifier_personalization,
	  "Personalization" },
	{ libfwsi_control_panel_item_identifier_phone_and_modem,
	  "Phone and Modem" },
	{ libfwsi_control_panel_item_identifier_portable_media_devices,
	  "Portable Media Devices" },
	{ libfwsi_control_panel_item_identifier_portable_workspace_creator,
	  "Portable Workspace Creator" },
	{ libfwsi_control_panel_item_identifier_power_options,
	  "Power Options" },
	{ libfwsi_control_panel_item_identifier_printers,
	  "Printers" },
	{ libfwsi_control_panel_item_identifier_problem_reports_and_solutions,
	  "Problem Reports and Solutions" },
	{ libfwsi_control_panel_item_identifier_programs_and_features,
	  "Programs and Features" },
	{ libfwsi_control_panel_item_identifier_recovery,
	  "Recovery" },
	{ libfwsi_control_panel_item_identifier_region_and_language,
	  "Region and Language" },
	{ libfwsi_control_panel_item_identifier_scanner_and_camera_control_panel,
	  "Scanner and Camera Control Panel" },
	{ libfwsi_control_panel_item_identifier_scanners_and_cameras,
	  "Scanners & Cameras" },
	{ libfwsi_control_panel_item_identifier_scheduled_tasks,
	  "Scheduled Tasks" },
	{ libfwsi_control_panel_item_identifier_secure_startup,
	  "Secure Startup" },
	{ libfwsi_control_panel_item_identifier_sensors,
	  "Sensors" },
	{ libfwsi_control_panel_item_identifier_set_user_defaults,
	  "Set User Defaults" },
	{ libfwsi_control_panel_item_identifier_sound,
	  "Sound" },
	{ libfwsi_control_panel_item_identifier_speech_recognition,
	  "Speech Recognition" },
	{ libfwsi_control_panel_item_identifier_storage_spaces,
	  "Storage Spaces" },
	{ libfwsi_control_panel_item_identifier_sync_center_folder,
	  "Sync Center Folder" },
	{ libfwsi_control_panel_item_identifier_system,
	  "System" },
	{ libfwsi_control_panel_item_identifier_tablet_pc_settings,
	  "Tablet PC Settings" },
	{ libfwsi_control_panel_item_identifier_taskbar_and_start_menu,
	  "Taskbar and Start Menu" },
	{ libfwsi_control_panel_item_identifier_taskbar_notification_icons_control_panel,
	  "Taskbar Notification Icons Control Panel" },
	{ libfwsi_control_panel_item_identifier_text_to_speech,
	  "Text to Speech" },
	{ libfwsi_control_panel_item_identifier_troubleshooting,
	  "Troubleshooting" },
	{ libfwsi_control_panel_item_identifier_user_accounts,
	  "User Accounts" },
	{ libfwsi_control_panel_item_identifier_view_available_networks,
	  "View Available Networks" },
	{ libfwsi_control_panel_item_identifier_welcome_center,
	  "Welcome Center" },
	{ libfwsi_control_panel_item_identifier_windows_anytime_upgrade,
	  "Windows Anytime Upgrade" },
	{ libfwsi_control_panel_item_identifier_windows_defender,
	  "Windows Defender" },
	{ libfwsi_control_panel_item_identifier_windows_firewall,
	  "Windows Firewall" },
	{ libfwsi_control_panel_item_identifier_windows_sidebar_properties,
	  "Windows Sidebar Properties" },
	{ libfwsi_control_panel_item_identifier_windows_sideshow,
	  "Windows SideShow" },
	{ libfwsi_control_panel_item_identifier_windows_update,
	  "Windows Update" },
	{ libfwsi_control_panel_item_identifier_workspaces_center,
	  "Workspaces Center" },
	{ libfwsi_control_panel_item_identifier_x86_control_panel,
	  "x86 Control Panel" },

	{ libfwsi_control_panel_item_identifier_unknown,
	  "Unknown" } };

/* Retrieves a string containing the name of the folder identifier
 */
const char *libfwsi_control_panel_item_identifier_get_name(
             const uint8_t *control_panel_item_identifier )
{
	int iterator = 0;

	if( control_panel_item_identifier == NULL )
	{
		return( "Invalid control panel item identifier" );
	}
	while( memory_compare(
	        ( libfwsi_control_panel_item_identifier_definitions[ iterator ] ).identifier,
	        libfwsi_control_panel_item_identifier_unknown,
	        16 ) != 0 )
	{
		if( memory_compare(
		     ( libfwsi_control_panel_item_identifier_definitions[ iterator ] ).identifier,
		     control_panel_item_identifier,
		     16 ) == 0 )
		{
			break;
		}
		iterator++;
	}
	return(
	 ( libfwsi_control_panel_item_identifier_definitions[ iterator ] ).name );
}

