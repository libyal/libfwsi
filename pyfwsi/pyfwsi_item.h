/*
 * Python object wrapper of libfwsi_item_t
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

#if !defined( _PYFWSI_ITEM_H )
#define _PYFWSI_ITEM_H

#include <common.h>
#include <types.h>

#include "pyfwsi_item_list.h"
#include "pyfwsi_libcerror.h"
#include "pyfwsi_libfwsi.h"
#include "pyfwsi_python.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct pyfwsi_item pyfwsi_item_t;

struct pyfwsi_item
{
	/* Python object initialization
	 */
	PyObject_HEAD

	/* The libfwsi item
	 */
	libfwsi_item_t *item;

	/* The parent object
	 */
	PyObject *parent_object;
};

extern PyMethodDef pyfwsi_item_object_methods[];
extern PyTypeObject pyfwsi_item_type_object;

PyObject *pyfwsi_item_new(
           PyTypeObject *type_object,
           libfwsi_item_t *item,
           PyObject *parent_object );

int pyfwsi_item_init(
     pyfwsi_item_t *pyfwsi_item );

void pyfwsi_item_free(
      pyfwsi_item_t *pyfwsi_item );

PyObject *pyfwsi_item_copy_from_byte_stream(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments,
           PyObject *keywords );

PyObject *pyfwsi_item_get_class_type(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments );

PyObject *pyfwsi_item_get_data_size(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments );

#ifdef TODO
PyObject *pyfwsi_item_get_data(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments );
#endif

PyObject *pyfwsi_item_get_delegate_folder_identifier(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments );

PyObject *pyfwsi_item_get_number_of_extension_blocks(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments );

PyObject *pyfwsi_item_get_extension_block_by_index(
           PyObject *pyfwsi_item,
           int extension_block_index );

PyObject *pyfwsi_item_get_extension_block(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments,
           PyObject *keywords );

PyObject *pyfwsi_item_get_extension_blocks(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _PYFWSI_ITEM_H ) */

