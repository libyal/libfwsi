/*
 * Python object wrapper of libfwsi_item_list_t
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

#if !defined( _PYFWSI_ITEM_LIST_H )
#define _PYFWSI_ITEM_LIST_H

#include <common.h>
#include <types.h>

#include "pyfwsi_libcerror.h"
#include "pyfwsi_libfwsi.h"
#include "pyfwsi_python.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct pyfwsi_item_list pyfwsi_item_list_t;

struct pyfwsi_item_list
{
	/* Python object initialization
	 */
	PyObject_HEAD

	/* The libfwsi item list
	 */
	libfwsi_item_list_t *item_list;
};

extern PyMethodDef pyfwsi_item_list_object_methods[];
extern PyTypeObject pyfwsi_item_list_type_object;

PyObject *pyfwsi_item_list_new(
           void );

int pyfwsi_item_list_init(
     pyfwsi_item_list_t *pyfwsi_item_list );

void pyfwsi_item_list_free(
      pyfwsi_item_list_t *pyfwsi_item_list );

PyObject *pyfwsi_item_list_copy_from_byte_stream(
           pyfwsi_item_list_t *pyfwsi_item_list,
           PyObject *arguments,
           PyObject *keywords );

PyObject *pyfwsi_item_list_get_number_of_items(
           pyfwsi_item_list_t *pyfwsi_item_list,
           PyObject *arguments );

PyObject *pyfwsi_item_list_get_item_by_index(
           PyObject *pyfwsi_item_list,
           int item_index );

PyObject *pyfwsi_item_list_get_item(
           pyfwsi_item_list_t *pyfwsi_item_list,
           PyObject *arguments,
           PyObject *keywords );

PyObject *pyfwsi_item_list_get_items(
           pyfwsi_item_list_t *pyfwsi_item_list,
           PyObject *arguments );

#if defined( __cplusplus )
}
#endif

#endif

