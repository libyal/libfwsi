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

#include <common.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( HAVE_WINAPI )
#include <stdlib.h>
#endif

#include "pyfwsi_extension_blocks.h"
#include "pyfwsi_item.h"
#include "pyfwsi_libcerror.h"
#include "pyfwsi_libfwsi.h"
#include "pyfwsi_python.h"

PySequenceMethods pyfwsi_extension_blocks_sequence_methods = {
	/* sq_length */
	(lenfunc) pyfwsi_extension_blocks_len,
	/* sq_concat */
	0,
	/* sq_repeat */
	0,
	/* sq_item */
	(ssizeargfunc) pyfwsi_extension_blocks_getitem,
	/* sq_slice */
	0,
	/* sq_ass_item */
	0,
	/* sq_ass_slice */
	0,
	/* sq_contains */
	0,
	/* sq_inplace_concat */
	0,
	/* sq_inplace_repeat */
	0
};

PyTypeObject pyfwsi_extension_blocks_type_object = {
	PyVarObject_HEAD_INIT( NULL, 0 )

	/* tp_name */
	"pyfwsi._extension_blocks",
	/* tp_basicsize */
	sizeof( pyfwsi_extension_blocks_t ),
	/* tp_itemsize */
	0,
	/* tp_dealloc */
	(destructor) pyfwsi_extension_blocks_free,
	/* tp_print */
	0,
	/* tp_getattr */
	0,
	/* tp_setattr */
	0,
	/* tp_compare */
	0,
	/* tp_repr */
	0,
	/* tp_as_number */
	0,
	/* tp_as_sequence */
	&pyfwsi_extension_blocks_sequence_methods,
	/* tp_as_mapping */
	0,
	/* tp_hash */
	0,
	/* tp_call */
	0,
	/* tp_str */
	0,
	/* tp_getattro */
	0,
	/* tp_setattro */
	0,
	/* tp_as_buffer */
	0,
	/* tp_flags */
	Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_ITER,
	/* tp_doc */
	"internal pyfwsi extension blocks sequence and iterator object",
	/* tp_traverse */
	0,
	/* tp_clear */
	0,
	/* tp_richcompare */
	0,
	/* tp_weaklistoffset */
	0,
	/* tp_iter */
	(getiterfunc) pyfwsi_extension_blocks_iter,
	/* tp_iternext */
	(iternextfunc) pyfwsi_extension_blocks_iternext,
	/* tp_methods */
	0,
	/* tp_members */
	0,
	/* tp_getset */
	0,
	/* tp_base */
	0,
	/* tp_dict */
	0,
	/* tp_descr_get */
	0,
	/* tp_descr_set */
	0,
	/* tp_dictoffset */
	0,
	/* tp_init */
	(initproc) pyfwsi_extension_blocks_init,
	/* tp_alloc */
	0,
	/* tp_new */
	0,
	/* tp_free */
	0,
	/* tp_is_gc */
	0,
	/* tp_bases */
	NULL,
	/* tp_mro */
	NULL,
	/* tp_cache */
	NULL,
	/* tp_lasses */
	NULL,
	/* tp_weaklist */
	NULL,
	/* tp_del */
	0
};

/* Creates a new extension blocks object
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_extension_blocks_new(
           pyfwsi_item_t *item_object,
           PyObject* (*get_extension_block_by_index)(
                        pyfwsi_item_t *item_object,
                        int extension_block_index ),
           int number_of_extension_blocks )
{
	pyfwsi_extension_blocks_t *pyfwsi_extension_blocks = NULL;
	static char *function                              = "pyfwsi_extension_blocks_new";

	if( item_object == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid item object.",
		 function );

		return( NULL );
	}
	if( get_extension_block_by_index == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid get extension block by index function.",
		 function );

		return( NULL );
	}
	/* Make sure the extension blocks values are initialized
	 */
	pyfwsi_extension_blocks = PyObject_New(
	                           struct pyfwsi_extension_blocks,
	                           &pyfwsi_extension_blocks_type_object );

	if( pyfwsi_extension_blocks == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize extension blocks.",
		 function );

		goto on_error;
	}
	if( pyfwsi_extension_blocks_init(
	     pyfwsi_extension_blocks ) != 0 )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize extension blocks.",
		 function );

		goto on_error;
	}
	pyfwsi_extension_blocks->item_object                  = item_object;
	pyfwsi_extension_blocks->get_extension_block_by_index = get_extension_block_by_index;
	pyfwsi_extension_blocks->number_of_extension_blocks   = number_of_extension_blocks;

	Py_IncRef(
	 (PyObject *) pyfwsi_extension_blocks->item_object );

	return( (PyObject *) pyfwsi_extension_blocks );

on_error:
	if( pyfwsi_extension_blocks != NULL )
	{
		Py_DecRef(
		 (PyObject *) pyfwsi_extension_blocks );
	}
	return( NULL );
}

/* Intializes an extension blocks object
 * Returns 0 if successful or -1 on error
 */
int pyfwsi_extension_blocks_init(
     pyfwsi_extension_blocks_t *pyfwsi_extension_blocks )
{
	static char *function = "pyfwsi_extension_blocks_init";

	if( pyfwsi_extension_blocks == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid extension blocks.",
		 function );

		return( -1 );
	}
	/* Make sure the extension blocks values are initialized
	 */
	pyfwsi_extension_blocks->item_object                  = NULL;
	pyfwsi_extension_blocks->get_extension_block_by_index = NULL;
	pyfwsi_extension_blocks->extension_block_index        = 0;
	pyfwsi_extension_blocks->number_of_extension_blocks   = 0;

	return( 0 );
}

/* Frees an extension blocks object
 */
void pyfwsi_extension_blocks_free(
      pyfwsi_extension_blocks_t *pyfwsi_extension_blocks )
{
	struct _typeobject *ob_type = NULL;
	static char *function       = "pyfwsi_extension_blocks_free";

	if( pyfwsi_extension_blocks == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid extension blocks.",
		 function );

		return;
	}
	ob_type = Py_TYPE(
	           pyfwsi_extension_blocks );

	if( ob_type == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: missing ob_type.",
		 function );

		return;
	}
	if( ob_type->tp_free == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid ob_type - missing tp_free.",
		 function );

		return;
	}
	if( pyfwsi_extension_blocks->item_object != NULL )
	{
		Py_DecRef(
		 (PyObject *) pyfwsi_extension_blocks->item_object );
	}
	ob_type->tp_free(
	 (PyObject*) pyfwsi_extension_blocks );
}

/* The extension blocks len() function
 */
Py_ssize_t pyfwsi_extension_blocks_len(
            pyfwsi_extension_blocks_t *pyfwsi_extension_blocks )
{
	static char *function = "pyfwsi_extension_blocks_len";

	if( pyfwsi_extension_blocks == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid extension blocks.",
		 function );

		return( -1 );
	}
	return( (Py_ssize_t) pyfwsi_extension_blocks->number_of_extension_blocks );
}

/* The extension blocks getitem() function
 */
PyObject *pyfwsi_extension_blocks_getitem(
           pyfwsi_extension_blocks_t *pyfwsi_extension_blocks,
           Py_ssize_t extension_block_index )
{
	PyObject *extension_block_object = NULL;
	static char *function            = "pyfwsi_extension_blocks_getitem";

	if( pyfwsi_extension_blocks == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid extension blocks.",
		 function );

		return( NULL );
	}
	if( pyfwsi_extension_blocks->get_extension_block_by_index == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid extension blocks - missing get extension block by index function.",
		 function );

		return( NULL );
	}
	if( pyfwsi_extension_blocks->number_of_extension_blocks < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid extension blocks - invalid number of extension blocks.",
		 function );

		return( NULL );
	}
	if( ( extension_block_index < 0 )
	 || ( extension_block_index >= (Py_ssize_t) pyfwsi_extension_blocks->number_of_extension_blocks ) )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid invalid extension block index value out of bounds.",
		 function );

		return( NULL );
	}
	extension_block_object = pyfwsi_extension_blocks->get_extension_block_by_index(
	                          pyfwsi_extension_blocks->item_object,
	                          (int) extension_block_index );

	return( extension_block_object );
}

/* The extension blocks iter() function
 */
PyObject *pyfwsi_extension_blocks_iter(
           pyfwsi_extension_blocks_t *pyfwsi_extension_blocks )
{
	static char *function = "pyfwsi_extension_blocks_iter";

	if( pyfwsi_extension_blocks == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid extension blocks.",
		 function );

		return( NULL );
	}
	Py_IncRef(
	 (PyObject *) pyfwsi_extension_blocks );

	return( (PyObject *) pyfwsi_extension_blocks );
}

/* The extension blocks iternext() function
 */
PyObject *pyfwsi_extension_blocks_iternext(
           pyfwsi_extension_blocks_t *pyfwsi_extension_blocks )
{
	PyObject *extension_block_object = NULL;
	static char *function            = "pyfwsi_extension_blocks_iternext";

	if( pyfwsi_extension_blocks == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid extension blocks.",
		 function );

		return( NULL );
	}
	if( pyfwsi_extension_blocks->get_extension_block_by_index == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid extension blocks - missing get extension block by index function.",
		 function );

		return( NULL );
	}
	if( pyfwsi_extension_blocks->extension_block_index < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid extension blocks - invalid extension block index.",
		 function );

		return( NULL );
	}
	if( pyfwsi_extension_blocks->number_of_extension_blocks < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid extension blocks - invalid number of extension blocks.",
		 function );

		return( NULL );
	}
	if( pyfwsi_extension_blocks->extension_block_index >= pyfwsi_extension_blocks->number_of_extension_blocks )
	{
		PyErr_SetNone(
		 PyExc_StopIteration );

		return( NULL );
	}
	extension_block_object = pyfwsi_extension_blocks->get_extension_block_by_index(
	                          pyfwsi_extension_blocks->item_object,
	                          pyfwsi_extension_blocks->extension_block_index );

	if( extension_block_object != NULL )
	{
		pyfwsi_extension_blocks->extension_block_index++;
	}
	return( extension_block_object );
}

