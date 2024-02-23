/*
 * Python object wrapper of libfwsi_item_t type LIBFWSI_ITEM_TYPE_CONTROL_PANEL_ITEM
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

#if !defined( _PYFWSI_CONTROL_PANEL_ITEM_H )
#define _PYFWSI_CONTROL_PANEL_ITEM_H

#include <common.h>
#include <types.h>

#include "pyfwsi_item.h"
#include "pyfwsi_python.h"

#if defined( __cplusplus )
extern "C" {
#endif

extern PyMethodDef pyfwsi_control_panel_item_object_methods[];
extern PyTypeObject pyfwsi_control_panel_item_type_object;

PyObject *pyfwsi_control_panel_item_get_identifier(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _PYFWSI_CONTROL_PANEL_ITEM_H ) */

