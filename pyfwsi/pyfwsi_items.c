/*
 * Python object definition of the items sequence and iterator
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

#include "pyfwsi_item.h"
#include "pyfwsi_items.h"
#include "pyfwsi_libcerror.h"
#include "pyfwsi_libfwsi.h"
#include "pyfwsi_python.h"

PySequenceMethods pyfwsi_items_sequence_methods = {
	/* sq_length */
	(lenfunc) pyfwsi_items_len,
	/* sq_concat */
	0,
	/* sq_repeat */
	0,
	/* sq_item */
	(ssizeargfunc) pyfwsi_items_getitem,
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

PyTypeObject pyfwsi_items_type_object = {
	PyVarObject_HEAD_INIT( NULL, 0 )

	/* tp_name */
	"pyfwsi._items",
	/* tp_basicsize */
	sizeof( pyfwsi_items_t ),
	/* tp_itemsize */
	0,
	/* tp_dealloc */
	(destructor) pyfwsi_items_free,
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
	&pyfwsi_items_sequence_methods,
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
	"internal pyfwsi items sequence and iterator object",
	/* tp_traverse */
	0,
	/* tp_clear */
	0,
	/* tp_richcompare */
	0,
	/* tp_weaklistoffset */
	0,
	/* tp_iter */
	(getiterfunc) pyfwsi_items_iter,
	/* tp_iternext */
	(iternextfunc) pyfwsi_items_iternext,
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
	(initproc) pyfwsi_items_init,
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

/* Creates a new items object
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_items_new(
           pyfwsi_item_list_t *item_list_object,
           PyObject* (*get_item_by_index)(
                        pyfwsi_item_list_t *item_list_object,
                        int item_index ),
           int number_of_items )
{
	pyfwsi_items_t *pyfwsi_items = NULL;
	static char *function        = "pyfwsi_items_new";

	if( item_list_object == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid item list object.",
		 function );

		return( NULL );
	}
	if( get_item_by_index == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid get item by index function.",
		 function );

		return( NULL );
	}
	/* Make sure the items values are initialized
	 */
	pyfwsi_items = PyObject_New(
	                struct pyfwsi_items,
	                &pyfwsi_items_type_object );

	if( pyfwsi_items == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize items.",
		 function );

		goto on_error;
	}
	if( pyfwsi_items_init(
	     pyfwsi_items ) != 0 )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize items.",
		 function );

		goto on_error;
	}
	pyfwsi_items->item_list_object  = item_list_object;
	pyfwsi_items->get_item_by_index = get_item_by_index;
	pyfwsi_items->number_of_items   = number_of_items;

	Py_IncRef(
	 (PyObject *) pyfwsi_items->item_list_object );

	return( (PyObject *) pyfwsi_items );

on_error:
	if( pyfwsi_items != NULL )
	{
		Py_DecRef(
		 (PyObject *) pyfwsi_items );
	}
	return( NULL );
}

/* Intializes an items object
 * Returns 0 if successful or -1 on error
 */
int pyfwsi_items_init(
     pyfwsi_items_t *pyfwsi_items )
{
	static char *function = "pyfwsi_items_init";

	if( pyfwsi_items == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid items.",
		 function );

		return( -1 );
	}
	/* Make sure the items values are initialized
	 */
	pyfwsi_items->item_list_object  = NULL;
	pyfwsi_items->get_item_by_index = NULL;
	pyfwsi_items->item_index        = 0;
	pyfwsi_items->number_of_items   = 0;

	return( 0 );
}

/* Frees an items object
 */
void pyfwsi_items_free(
      pyfwsi_items_t *pyfwsi_items )
{
	struct _typeobject *ob_type = NULL;
	static char *function       = "pyfwsi_items_free";

	if( pyfwsi_items == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid items.",
		 function );

		return;
	}
	ob_type = Py_TYPE(
	           pyfwsi_items );

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
	if( pyfwsi_items->item_list_object != NULL )
	{
		Py_DecRef(
		 (PyObject *) pyfwsi_items->item_list_object );
	}
	ob_type->tp_free(
	 (PyObject*) pyfwsi_items );
}

/* The items len() function
 */
Py_ssize_t pyfwsi_items_len(
            pyfwsi_items_t *pyfwsi_items )
{
	static char *function = "pyfwsi_items_len";

	if( pyfwsi_items == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid items.",
		 function );

		return( -1 );
	}
	return( (Py_ssize_t) pyfwsi_items->number_of_items );
}

/* The items getitem() function
 */
PyObject *pyfwsi_items_getitem(
           pyfwsi_items_t *pyfwsi_items,
           Py_ssize_t item_index )
{
	PyObject *item_object = NULL;
	static char *function = "pyfwsi_items_getitem";

	if( pyfwsi_items == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid items.",
		 function );

		return( NULL );
	}
	if( pyfwsi_items->get_item_by_index == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid items - missing get item by index function.",
		 function );

		return( NULL );
	}
	if( pyfwsi_items->number_of_items < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid items - invalid number of items.",
		 function );

		return( NULL );
	}
	if( ( item_index < 0 )
	 || ( item_index >= (Py_ssize_t) pyfwsi_items->number_of_items ) )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid invalid item index value out of bounds.",
		 function );

		return( NULL );
	}
	item_object = pyfwsi_items->get_item_by_index(
	               pyfwsi_items->item_list_object,
	               (int) item_index );

	return( item_object );
}

/* The items iter() function
 */
PyObject *pyfwsi_items_iter(
           pyfwsi_items_t *pyfwsi_items )
{
	static char *function = "pyfwsi_items_iter";

	if( pyfwsi_items == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid items.",
		 function );

		return( NULL );
	}
	Py_IncRef(
	 (PyObject *) pyfwsi_items );

	return( (PyObject *) pyfwsi_items );
}

/* The items iternext() function
 */
PyObject *pyfwsi_items_iternext(
           pyfwsi_items_t *pyfwsi_items )
{
	PyObject *item_object = NULL;
	static char *function = "pyfwsi_items_iternext";

	if( pyfwsi_items == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid items.",
		 function );

		return( NULL );
	}
	if( pyfwsi_items->get_item_by_index == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid items - missing get item by index function.",
		 function );

		return( NULL );
	}
	if( pyfwsi_items->item_index < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid items - invalid item index.",
		 function );

		return( NULL );
	}
	if( pyfwsi_items->number_of_items < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid items - invalid number of items.",
		 function );

		return( NULL );
	}
	if( pyfwsi_items->item_index >= pyfwsi_items->number_of_items )
	{
		PyErr_SetNone(
		 PyExc_StopIteration );

		return( NULL );
	}
	item_object = pyfwsi_items->get_item_by_index(
	               pyfwsi_items->item_list_object,
	               pyfwsi_items->item_index );

	if( item_object != NULL )
	{
		pyfwsi_items->item_index++;
	}
	return( item_object );
}

