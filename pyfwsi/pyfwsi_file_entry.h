/*
 * Python object definition of the libfwsi file entry item
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

#if !defined( _PYFWSI_FILE_ENTRY_H )
#define _PYFWSI_FILE_ENTRY_H

#include <common.h>
#include <types.h>

#include "pyfwsi_item.h"
#include "pyfwsi_python.h"

#if defined( __cplusplus )
extern "C" {
#endif

extern PyMethodDef pyfwsi_file_entry_object_methods[];
extern PyTypeObject pyfwsi_file_entry_type_object;

PyObject *pyfwsi_file_entry_get_file_size(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments );

PyObject *pyfwsi_file_entry_get_modification_time(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments );

PyObject *pyfwsi_file_entry_get_modification_time_as_integer(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments );

PyObject *pyfwsi_file_entry_get_file_attribute_flags(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments );

PyObject *pyfwsi_file_entry_get_name(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _PYFWSI_FILE_ENTRY_H ) */

