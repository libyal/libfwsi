/*
 * Debug functions
 *
 * Copyright (C) 2010-2015, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <memory.h>
#include <types.h>

#include "libfwsi_debug.h"

#if defined( HAVE_DEBUG_OUTPUT )

/* Prints the dirve type
 */
const char *libfwsi_debug_print_control_panel_category(
             uint32_t control_panel_category )
{
	switch( control_panel_category )
	{
		case 0:
			return( "All Control Panel Items" );

		case 1:
			return( "Appearance and Personalization" );

		case 2:
			return( "Hardware and Sound" );

		case 3:
			return( "Network and Internet" );

		case 4:
			return( "Sounds, Speech, and Audio Devices" );

		case 5:
			return( "System and Security" );

		case 6:
			return( "Clock, Language, and Region" );

		case 7:
			return( "Ease of Access" );

		case 8:
			return( "Programs" );

		case 9:
			return( "User Accounts" );

		case 10:
			return( "Security Center" );

		case 11:
			return( "Mobile PC" );
	}
	return( "_UNKNOWN_" );
}

#endif

