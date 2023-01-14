/*
 * Python object wrapper of libfwsi_item_list_t
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

#include <common.h>
#include <memory.h>
#include <narrow_string.h>
#include <types.h>

#if defined( HAVE_STDLIB_H )
#include <stdlib.h>
#endif

#include "pyfwsi_error.h"
#include "pyfwsi_file_entry.h"
#include "pyfwsi_item.h"
#include "pyfwsi_item_list.h"
#include "pyfwsi_items.h"
#include "pyfwsi_libcerror.h"
#include "pyfwsi_libclocale.h"
#include "pyfwsi_libfwsi.h"
#include "pyfwsi_network_location.h"
#include "pyfwsi_python.h"
#include "pyfwsi_root_folder.h"
#include "pyfwsi_unused.h"
#include "pyfwsi_volume.h"

PyMethodDef pyfwsi_item_list_object_methods[] = {

	{ "copy_from_byte_stream",
	  (PyCFunction) pyfwsi_item_list_copy_from_byte_stream,
	  METH_VARARGS | METH_KEYWORDS,
	  "copy_from_byte_stream(byte_stream, ascii_codepage=cp1252)\n"
	  "\n"
	  "Copies the the item list from the byte stream." },

	/* Functions to access the items */

	{ "get_number_of_items",
	  (PyCFunction) pyfwsi_item_list_get_number_of_items,
	  METH_NOARGS,
	  "get_number_of_items() -> Integer\n"
	  "\n"
	  "Retrieves the number of items." },

	{ "get_item",
	  (PyCFunction) pyfwsi_item_list_get_item,
	  METH_VARARGS | METH_KEYWORDS,
	  "get_item(item_index) -> Object\n"
	  "\n"
	  "Retrieves a specific item." },

	/* Sentinel */
	{ NULL, NULL, 0, NULL }
};

PyGetSetDef pyfwsi_item_list_object_get_set_definitions[] = {

	{ "number_of_items",
	  (getter) pyfwsi_item_list_get_number_of_items,
	  (setter) 0,
	  "The number of items.",
	  NULL },

	{ "items",
	  (getter) pyfwsi_item_list_get_items,
	  (setter) 0,
	  "The items",
	  NULL },

	/* Sentinel */
	{ NULL, NULL, NULL, NULL, NULL }
};

PyTypeObject pyfwsi_item_list_type_object = {
	PyVarObject_HEAD_INIT( NULL, 0 )

	/* tp_name */
	"pyfwsi.item_list",
	/* tp_basicsize */
	sizeof( pyfwsi_item_list_t ),
	/* tp_itemsize */
	0,
	/* tp_dealloc */
	(destructor) pyfwsi_item_list_free,
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
	0,
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
	Py_TPFLAGS_DEFAULT,
	/* tp_doc */
	"pyfwsi item_list object (wraps libfwsi_item_list_t)",
	/* tp_traverse */
	0,
	/* tp_clear */
	0,
	/* tp_richcompare */
	0,
	/* tp_weaklistoffset */
	0,
	/* tp_iter */
	0,
	/* tp_iternext */
	0,
	/* tp_methods */
	pyfwsi_item_list_object_methods,
	/* tp_members */
	0,
	/* tp_getset */
	pyfwsi_item_list_object_get_set_definitions,
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
	(initproc) pyfwsi_item_list_init,
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
	/* tp_subclasses */
	NULL,
	/* tp_weaklist */
	NULL,
	/* tp_del */
	0
};

/* Creates a new pyfwsi item list object
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_item_list_new(
           void )
{
	static char *function                = "pyfwsi_item_list_new";
	pyfwsi_item_list_t *pyfwsi_item_list = NULL;

	pyfwsi_item_list = PyObject_New(
	                    struct pyfwsi_item_list,
	                    &pyfwsi_item_list_type_object );

	if( pyfwsi_item_list == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize item list.",
		 function );

		goto on_error;
	}
	if( pyfwsi_item_list_init(
	     pyfwsi_item_list ) != 0 )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize item list.",
		 function );

		goto on_error;
	}
	return( (PyObject *) pyfwsi_item_list );

on_error:
	if( pyfwsi_item_list != NULL )
	{
		Py_DecRef(
		 (PyObject *) pyfwsi_item_list );
	}
	return( NULL );
}

/* Initializes an item list object
 * Returns 0 if successful or -1 on error
 */
int pyfwsi_item_list_init(
     pyfwsi_item_list_t *pyfwsi_item_list )
{
	static char *function    = "pyfwsi_item_list_init";
	libcerror_error_t *error = NULL;

	if( pyfwsi_item_list == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid item list.",
		 function );

		return( -1 );
	}
	pyfwsi_item_list->item_list = NULL;

	if( libfwsi_item_list_initialize(
	     &( pyfwsi_item_list->item_list ),
	     &error ) != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_MemoryError,
		 "%s: unable to initialize item list.",
		 function );

		libcerror_error_free(
		 &error );

		return( -1 );
	}
	return( 0 );
}

/* Frees an item list object
 */
void pyfwsi_item_list_free(
      pyfwsi_item_list_t *pyfwsi_item_list )
{
	libcerror_error_t *error    = NULL;
	struct _typeobject *ob_type = NULL;
	static char *function       = "pyfwsi_item_list_free";
	int result                  = 0;

	if( pyfwsi_item_list == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid item list.",
		 function );

		return;
	}
	if( pyfwsi_item_list->item_list == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid item list - missing libfwsi item list.",
		 function );

		return;
	}
	ob_type = Py_TYPE(
	           pyfwsi_item_list );

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
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_item_list_free(
	          &( pyfwsi_item_list->item_list ),
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_MemoryError,
		 "%s: unable to free item list.",
		 function );

		libcerror_error_free(
		 &error );
	}
	ob_type->tp_free(
	 (PyObject*) pyfwsi_item_list );
}

/* Copies the item list from a byte stream
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_item_list_copy_from_byte_stream(
           pyfwsi_item_list_t *pyfwsi_item_list,
           PyObject *arguments,
           PyObject *keywords )
{
	PyObject *string_object       = NULL;
	libcerror_error_t *error      = NULL;
	static char *function         = "pyfwsi_item_list_copy_from_byte_stream";
	static char *keyword_list[]   = { "byte_stream", "ascii_codepage", NULL };
	const char *byte_stream       = NULL;
	char *codepage_string         = NULL;
	Py_ssize_t byte_stream_size   = 0;
	size_t codepage_string_length = 0;
	uint32_t feature_flags        = 0;
	int ascii_codepage            = LIBFWSI_CODEPAGE_WINDOWS_1252;
	int result                    = 0;

	if( pyfwsi_item_list == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid item list.",
		 function );

		return( NULL );
	}
	if( PyArg_ParseTupleAndKeywords(
	     arguments,
	     keywords,
	     "O|s",
	     keyword_list,
	     &string_object,
	     &codepage_string ) == 0 )
	{
		return( NULL );
	}
	PyErr_Clear();

#if PY_MAJOR_VERSION >= 3
	result = PyObject_IsInstance(
		  string_object,
		  (PyObject *) &PyBytes_Type );
#else
	result = PyObject_IsInstance(
		  string_object,
		  (PyObject *) &PyString_Type );
#endif
	if( result == -1 )
	{
		pyfwsi_error_fetch_and_raise(
	         PyExc_RuntimeError,
		 "%s: unable to determine if string object is of type string.",
		 function );

		return( NULL );
	}
	else if( result == 0 )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: unsupported string object type",
		 function );

		return( NULL );
	}
	if( codepage_string != NULL )
	{
		codepage_string_length = narrow_string_length(
		                          codepage_string );

		feature_flags = LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS;

		if( libclocale_codepage_copy_from_string(
		     &ascii_codepage,
		     codepage_string,
		     codepage_string_length,
		     feature_flags,
		     &error ) != 1 )
		{
			pyfwsi_error_raise(
			 error,
			 PyExc_RuntimeError,
			 "%s: unable to determine ASCII codepage.",
			 function );

			libcerror_error_free(
			 &error );

			return( NULL );
		}
	}
	PyErr_Clear();

#if PY_MAJOR_VERSION >= 3
	byte_stream = PyBytes_AsString(
	               string_object );

	byte_stream_size = PyBytes_Size(
	                    string_object );
#else
	byte_stream = PyString_AsString(
	               string_object );

	byte_stream_size = PyString_Size(
	                    string_object );
#endif
/* TODO size bounds check */

	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_item_list_copy_from_byte_stream(
	          pyfwsi_item_list->item_list,
	          (uint8_t *) byte_stream,
	          (size_t) byte_stream_size,
	          ascii_codepage,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to copy item list from byte stream.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	Py_IncRef(
	 Py_None );

	return( Py_None );
}

/* Retrieves the number of items
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_item_list_get_number_of_items(
           pyfwsi_item_list_t *pyfwsi_item_list,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error = NULL;
	PyObject *integer_object = NULL;
	static char *function    = "pyfwsi_item_list_get_number_of_items";
	int number_of_items      = 0;
	int result               = 0;

	PYFWSI_UNREFERENCED_PARAMETER( arguments )

	if( pyfwsi_item_list == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid item list.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_item_list_get_number_of_items(
	          pyfwsi_item_list->item_list,
	          &number_of_items,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve number of items.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
#if PY_MAJOR_VERSION >= 3
	integer_object = PyLong_FromLong(
	                  (long) number_of_items );
#else
	integer_object = PyInt_FromLong(
	                  (long) number_of_items );
#endif
	return( integer_object );
}

/* Retrieves a specific item by index
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_item_list_get_item_by_index(
           PyObject *pyfwsi_item_list,
           int item_index )
{
	libcerror_error_t *error  = NULL;
	libfwsi_item_t *item      = NULL;
	PyObject *item_object     = NULL;
	PyTypeObject *type_object = NULL;
	static char *function     = "pyfwsi_item_list_get_item_by_index";
	int item_type             = 0;
	int result                = 0;

	if( pyfwsi_item_list == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid item list.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_item_list_get_item(
	          ( (pyfwsi_item_list_t *) pyfwsi_item_list )->item_list,
	          item_index,
	          &item,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve item: %d.",
		 function,
		 item_index );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_item_get_type(
	          item,
	          &item_type,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve item: %d class type.",
		 function,
		 item_index );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	switch( item_type )
	{
		case LIBFWSI_ITEM_TYPE_FILE_ENTRY:
			type_object = &pyfwsi_file_entry_type_object;
			break;

		case LIBFWSI_ITEM_TYPE_NETWORK_LOCATION:
			type_object = &pyfwsi_network_location_type_object;
			break;

		case LIBFWSI_ITEM_TYPE_ROOT_FOLDER:
			type_object = &pyfwsi_root_folder_type_object;
			break;

		case LIBFWSI_ITEM_TYPE_VOLUME:
			type_object = &pyfwsi_volume_type_object;
			break;

		case LIBFWSI_ITEM_TYPE_UNKNOWN:
		case LIBFWSI_ITEM_TYPE_CDBURN:
		case LIBFWSI_ITEM_TYPE_CONTROL_PANEL:
		case LIBFWSI_ITEM_TYPE_DELEGATE:
		case LIBFWSI_ITEM_TYPE_GAME_FOLDER:
		case LIBFWSI_ITEM_TYPE_URI:
		case LIBFWSI_ITEM_TYPE_USERS_PROPERTY_VIEW:
		default:
			type_object = &pyfwsi_item_type_object;
			break;
	}
	item_object = pyfwsi_item_new(
	               type_object,
	               item,
	               pyfwsi_item_list );

	if( item_object == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to create item object.",
		 function );

		goto on_error;
	}
	return( item_object );

on_error:
	if( item != NULL )
	{
		libfwsi_item_free(
		 &item,
		 NULL );
	}
	return( NULL );
}

/* Retrieves a specific item
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_item_list_get_item(
           pyfwsi_item_list_t *pyfwsi_item_list,
           PyObject *arguments,
           PyObject *keywords )
{
	PyObject *item_object       = NULL;
	static char *keyword_list[] = { "item_index", NULL };
	int item_index              = 0;

	if( PyArg_ParseTupleAndKeywords(
	     arguments,
	     keywords,
	     "i",
	     keyword_list,
	     &item_index ) == 0 )
	{
		return( NULL );
	}
	item_object = pyfwsi_item_list_get_item_by_index(
	               (PyObject *) pyfwsi_item_list,
	               item_index );

	return( item_object );
}

/* Retrieves an items sequence and iterator object for the items
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_item_list_get_items(
           pyfwsi_item_list_t *pyfwsi_item_list,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error = NULL;
	PyObject *items_object   = NULL;
	static char *function    = "pyfwsi_item_list_get_items";
	int number_of_items      = 0;
	int result               = 0;

	PYFWSI_UNREFERENCED_PARAMETER( arguments )

	if( pyfwsi_item_list == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid item list.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_item_list_get_number_of_items(
	          pyfwsi_item_list->item_list,
	          &number_of_items,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve number of items.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	items_object = pyfwsi_items_new(
	                (PyObject *) pyfwsi_item_list,
	                &pyfwsi_item_list_get_item_by_index,
	                number_of_items );

	if( items_object == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to create items object.",
		 function );

		return( NULL );
	}
	return( items_object );
}

