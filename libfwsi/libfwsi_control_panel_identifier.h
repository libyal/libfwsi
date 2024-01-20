/*
 * Control panel identifier functions
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

#if !defined( _LIBFWSI_CONTROL_PANEL_IDENTIFIER_H )
#define _LIBFWSI_CONTROL_PANEL_IDENTIFIER_H

#include <common.h>
#include <types.h>

#include "libfwsi_extern.h"
#include "libfwsi_libcerror.h"

#if defined( __cplusplus )
extern "C" {
#endif

/* The CLSID is stored as a little endian GUID
 */
typedef struct libfwsi_control_panel_identifier_definition libfwsi_control_panel_identifier_definition_t;

struct libfwsi_control_panel_identifier_definition
{
	/* The folder identifier
	 */
	uint8_t *identifier;

	/* The folder name
	 */
	const char *name;
};

extern uint8_t libfwsi_control_panel_identifier_action_center[ 16 ];
extern uint8_t libfwsi_control_panel_identifier_connections[ 16 ];
extern uint8_t libfwsi_control_panel_identifier_network_and_sharing_center[ 16 ];
extern uint8_t libfwsi_control_panel_identifier_system[ 16 ];
extern uint8_t libfwsi_control_panel_identifier_windows_update[ 16 ];

LIBFWSI_EXTERN \
const char *libfwsi_control_panel_identifier_get_name(
             const uint8_t *control_panel_identifier );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFWSI_CONTROL_PANEL_IDENTIFIER_H ) */

