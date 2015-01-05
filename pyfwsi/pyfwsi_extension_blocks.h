/*
 * Python object definition of the extension blocks sequence and iterator
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

#if !defined( _PYFWSI_EXTENSION_BLOCKS_H )
#define _PYFWSI_EXTENSION_BLOCKS_H

#include <common.h>
#include <types.h>

#include "pyfwsi_extension_block.h"
#include "pyfwsi_item.h"
#include "pyfwsi_libfwsi.h"
#include "pyfwsi_python.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct pyfwsi_extension_blocks pyfwsi_extension_blocks_t;

struct pyfwsi_extension_blocks
{
	/* Python object initialization
	 */
	PyObject_HEAD

	/* The item object
	 */
	pyfwsi_item_t *item_object;

	/* The get extension block by index callback function
	 */
	PyObject* (*get_extension_block_by_index)(
	             pyfwsi_item_t *item_object,
	             int extension_block_index );

	/* The (current) extension block index
	 */
	int extension_block_index;

	/* The number of extension blocks
	 */
	int number_of_extension_blocks;
};

extern PyTypeObject pyfwsi_extension_blocks_type_object;

PyObject *pyfwsi_extension_blocks_new(
           pyfwsi_item_t *item_object,
           PyObject* (*get_extension_block_by_index)(
                        pyfwsi_item_t *item_object,
                        int extension_block_index ),
           int number_of_extension_blocks );

int pyfwsi_extension_blocks_init(
     pyfwsi_extension_blocks_t *pyfwsi_extension_blocks );

void pyfwsi_extension_blocks_free(
      pyfwsi_extension_blocks_t *pyfwsi_extension_blocks );

Py_ssize_t pyfwsi_extension_blocks_len(
            pyfwsi_extension_blocks_t *pyfwsi_extension_blocks );

PyObject *pyfwsi_extension_blocks_getitem(
           pyfwsi_extension_blocks_t *pyfwsi_extension_blocks,
           Py_ssize_t extension_block_index );

PyObject *pyfwsi_extension_blocks_iter(
           pyfwsi_extension_blocks_t *pyfwsi_extension_blocks );

PyObject *pyfwsi_extension_blocks_iternext(
           pyfwsi_extension_blocks_t *pyfwsi_extension_blocks );

#if defined( __cplusplus )
}
#endif

#endif

