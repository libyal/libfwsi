/*
 * Python object wrapper of libfwsi_item_t type LIBFWSI_ITEM_TYPE_USERS_PROPERTY_VIEW
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

#include <common.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( HAVE_WINAPI )
#include <stdlib.h>
#endif

#include "pyfwsi_error.h"
#include "pyfwsi_guid.h"
#include "pyfwsi_integer.h"
#include "pyfwsi_item.h"
#include "pyfwsi_libcerror.h"
#include "pyfwsi_libfwsi.h"
#include "pyfwsi_python.h"
#include "pyfwsi_unused.h"
#include "pyfwsi_users_property_view.h"

PyMethodDef pyfwsi_users_property_view_object_methods[] = {

	{ "get_known_folder_identifier",
	  (PyCFunction) pyfwsi_users_property_view_get_known_folder_identifier,
	  METH_NOARGS,
	  "get_known_folder_identifier() -> Unicode string or None\n"
	  "\n"
	  "Retrieves the known folder identifier." },

	{ "get_property_store_data",
	  (PyCFunction) pyfwsi_users_property_view_get_property_store_data,
	  METH_NOARGS,
	  "get_property_store_data() -> Bytes\n"
	  "\n"
	  "Retrieves the property store data." },

	/* Sentinel */
	{ NULL, NULL, 0, NULL }
};

PyGetSetDef pyfwsi_users_property_view_object_get_set_definitions[] = {

	{ "known_folder_identifier",
	  (getter) pyfwsi_users_property_view_get_known_folder_identifier,
	  (setter) 0,
	  "The known folder identifier.",
	  NULL },

	{ "property_store_data",
	  (getter) pyfwsi_users_property_view_get_property_store_data,
	  (setter) 0,
	  "The property store data.",
	  NULL },

	/* Sentinel */
	{ NULL, NULL, NULL, NULL, NULL }
};

PyTypeObject pyfwsi_users_property_view_type_object = {
	PyVarObject_HEAD_INIT( NULL, 0 )

	/* tp_name */
	"pyfwsi.users_property_view",
	/* tp_basicsize */
	sizeof( pyfwsi_item_t ),
	/* tp_itemsize */
	0,
	/* tp_dealloc */
	0,
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
	"pyfwsi users_property_view object (wraps libfwsi_item_t type LIBFWSI_ITEM_TYPE_USERS_PROPERTY_VIEW)",
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
	pyfwsi_users_property_view_object_methods,
	/* tp_members */
	0,
	/* tp_getset */
	pyfwsi_users_property_view_object_get_set_definitions,
	/* tp_base */
	&pyfwsi_item_type_object,
	/* tp_dict */
	0,
	/* tp_descr_get */
	0,
	/* tp_descr_set */
	0,
	/* tp_dictoffset */
	0,
	/* tp_init */
	0,
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

/* Retrieves the known folder identifier
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_users_property_view_get_known_folder_identifier(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	uint8_t guid_data[ 16 ];

	PyObject *string_object  = NULL;
	libcerror_error_t *error = NULL;
	static char *function    = "pyfwsi_users_property_view_get_known_folder_identifier";
	int result               = 0;

	PYFWSI_UNREFERENCED_PARAMETER( arguments )

	if( pyfwsi_item == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid item.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_users_property_view_get_known_folder_identifier(
	          pyfwsi_item->item,
	          guid_data,
	          16,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve known folder identifier.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	else if( result == 0 )
	{
		Py_IncRef(
		 Py_None );

		return( Py_None );
	}
	string_object = pyfwsi_string_new_from_guid(
	                 guid_data,
	                 16 );

	if( string_object == NULL )
	{
		PyErr_Format(
		 PyExc_IOError,
		 "%s: unable to convert GUID into Unicode object.",
		 function );

		return( NULL );
	}
	return( string_object );
}

/* Retrieves the property store data
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_users_property_view_get_property_store_data(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	PyObject *bytes_object   = NULL;
	libcerror_error_t *error = NULL;
	char *data               = NULL;
	static char *function    = "pyfwsi_users_property_view_get_property_store_data";
	size_t data_size         = 0;
	int result               = 0;

	PYFWSI_UNREFERENCED_PARAMETER( arguments )

	if( pyfwsi_item == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid item.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_users_property_view_get_property_store_data_size(
	          pyfwsi_item->item,
	          &data_size,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve property store data size.",
		 function );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	else if( ( result == 0 )
	      || ( data_size == 0 ) )
	{
		Py_IncRef(
		 Py_None );

		return( Py_None );
	}
	data = (char *) PyMem_Malloc(
	                 sizeof( char ) * data_size );

	if( data == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to create property store data.",
		 function );

		goto on_error;
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_users_property_view_copy_property_store_data(
	          pyfwsi_item->item,
	          (uint8_t *) data,
	          data_size,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to copy property store data.",
		 function );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	/* This is a binary string so include the full size
	 */
#if PY_MAJOR_VERSION >= 3
	bytes_object = PyBytes_FromStringAndSize(
	                data,
	                (Py_ssize_t) data_size );
#else
	bytes_object = PyString_FromStringAndSize(
	                data,
	                (Py_ssize_t) data_size );
#endif
	if( bytes_object == NULL )
	{
		PyErr_Format(
		 PyExc_IOError,
		 "%s: unable to convert data into Bytes object.",
		 function );

		goto on_error;
	}
	PyMem_Free(
	 data );

	return( bytes_object );

on_error:
	if( data != NULL )
	{
		PyMem_Free(
		 data );
	}
	return( NULL );
}
