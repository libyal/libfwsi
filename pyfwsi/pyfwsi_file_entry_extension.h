/*
 * Python object definition of the libfwsi file entry extension block
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

#if !defined( _PYFWSI_FILE_ENTRY_EXTENSION_H )
#define _PYFWSI_FILE_ENTRY_EXTENSION_H

#include <common.h>
#include <types.h>

#include "pyfwsi_extension_block.h"
#include "pyfwsi_python.h"

#if defined( __cplusplus )
extern "C" {
#endif

extern PyMethodDef pyfwsi_file_entry_extension_object_methods[];
extern PyTypeObject pyfwsi_file_entry_extension_type_object;

PyObject *pyfwsi_file_entry_extension_get_creation_time(
           pyfwsi_extension_block_t *pyfwsi_extension_block,
           PyObject *arguments );

PyObject *pyfwsi_file_entry_extension_get_creation_time_as_integer(
           pyfwsi_extension_block_t *pyfwsi_extension_block,
           PyObject *arguments );

PyObject *pyfwsi_file_entry_extension_get_access_time(
           pyfwsi_extension_block_t *pyfwsi_extension_block,
           PyObject *arguments );

PyObject *pyfwsi_file_entry_extension_get_access_time_as_integer(
           pyfwsi_extension_block_t *pyfwsi_extension_block,
           PyObject *arguments );

PyObject *pyfwsi_file_entry_extension_get_long_name(
           pyfwsi_extension_block_t *pyfwsi_extension_block,
           PyObject *arguments );

PyObject *pyfwsi_file_entry_extension_get_localized_name(
           pyfwsi_extension_block_t *pyfwsi_extension_block,
           PyObject *arguments );

PyObject *pyfwsi_file_entry_extension_get_file_reference(
           pyfwsi_extension_block_t *pyfwsi_extension_block,
           PyObject *arguments );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _PYFWSI_FILE_ENTRY_EXTENSION_H ) */

