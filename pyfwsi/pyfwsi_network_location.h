/*
 * Python object wrapper of libfwsi_item_t type LIBFWSI_ITEM_TYPE_NETWORK_LOCATION
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

#if !defined( _PYFWSI_NETWORK_LOCATION_H )
#define _PYFWSI_NETWORK_LOCATION_H

#include <common.h>
#include <types.h>

#include "pyfwsi_item.h"
#include "pyfwsi_python.h"

#if defined( __cplusplus )
extern "C" {
#endif

extern PyMethodDef pyfwsi_network_location_object_methods[];
extern PyTypeObject pyfwsi_network_location_type_object;

PyObject *pyfwsi_network_location_get_location(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments );

PyObject *pyfwsi_network_location_get_description(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments );

PyObject *pyfwsi_network_location_get_comments(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _PYFWSI_NETWORK_LOCATION_H ) */

