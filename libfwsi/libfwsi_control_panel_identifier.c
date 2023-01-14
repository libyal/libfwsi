/*
 * Control panel identifier functions
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

#include "libfwsi_control_panel_identifier.h"
#include "libfwsi_libcerror.h"

uint8_t libfwsi_control_panel_identifier_action_center[ 16 ] = {
	0xa7, 0xf8, 0x64, 0xbb, 0xe7, 0xbe, 0x1a, 0x4e, 0xab, 0x8d, 0x7d, 0x82, 0x73, 0xf7, 0xfd, 0xb6 };

uint8_t libfwsi_control_panel_identifier_connections[ 16 ] = {
	0xc7, 0xac, 0x07, 0x70, 0x02, 0x32, 0xd1, 0x11, 0xaa, 0xd2, 0x00, 0x80, 0x5f, 0xc1, 0x27, 0x0e };

uint8_t libfwsi_control_panel_identifier_network_and_sharing_center[ 16 ] = {
	0xc9, 0x8f, 0x90, 0x8e, 0xcc, 0xbe, 0xf6, 0x40, 0x91, 0x5b, 0xf4, 0xca, 0x0e, 0x70, 0xd0, 0x3d };

uint8_t libfwsi_control_panel_identifier_system[ 16 ] = {
	0xe4, 0xc0, 0x06, 0xbb, 0x93, 0xd2, 0x75, 0x4f, 0x8a, 0x90, 0xcb, 0x05, 0xb6, 0x47, 0x7e, 0xee };

uint8_t libfwsi_control_panel_identifier_windows_update[ 16 ] = {
	0xdb, 0xf7, 0xee, 0x36, 0xad, 0x88, 0x81, 0x4e, 0xad, 0x49, 0x0e, 0x31, 0x3f, 0x0c, 0x35, 0xf8 };

uint8_t libfwsi_control_panel_identifier_unknown[ 16 ] = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };

/* The control panel identifiers
 */
libfwsi_control_panel_identifier_definition_t libfwsi_control_panel_identifier_definitions[ ] = {
	{ libfwsi_control_panel_identifier_action_center,		"Action Center" },
	{ libfwsi_control_panel_identifier_connections,			"Connections" },
	{ libfwsi_control_panel_identifier_network_and_sharing_center,	"Network and Sharing Center" },
	{ libfwsi_control_panel_identifier_system,			"System" },
	{ libfwsi_control_panel_identifier_windows_update,		"Windows Update" },

	{ libfwsi_control_panel_identifier_unknown,			"Unknown" } };

/* Retrieves a string containing the name of the folder identifier
 */
const char *libfwsi_control_panel_identifier_get_name(
             const uint8_t *control_panel_identifier )
{
	int iterator = 0;

	if( control_panel_identifier == NULL )
	{
		return( "Invalid control panel identifier" );
	}
	while( memory_compare(
	        ( libfwsi_control_panel_identifier_definitions[ iterator ] ).identifier,
	        libfwsi_control_panel_identifier_unknown,
	        16 ) != 0 )
	{
		if( memory_compare(
		     ( libfwsi_control_panel_identifier_definitions[ iterator ] ).identifier,
		     control_panel_identifier,
		     16 ) == 0 )
		{
			break;
		}
		iterator++;
	}
	return(
	 ( libfwsi_control_panel_identifier_definitions[ iterator ] ).name );
}

