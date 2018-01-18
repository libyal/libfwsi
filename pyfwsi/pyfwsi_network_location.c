/*
 * Python object definition of the libfwsi network location item
 *
 * Copyright (C) 2010-2018, Joachim Metz <joachim.metz@gmail.com>
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

#include "pyfwsi_error.h"
#include "pyfwsi_item.h"
#include "pyfwsi_libcerror.h"
#include "pyfwsi_libfwsi.h"
#include "pyfwsi_network_location.h"
#include "pyfwsi_python.h"
#include "pyfwsi_unused.h"

PyMethodDef pyfwsi_network_location_object_methods[] = {

	{ "get_location",
	  (PyCFunction) pyfwsi_network_location_get_location,
	  METH_NOARGS,
	  "get_location() -> Unicode string or None\n"
	  "\n"
	  "Returns the location of the network location." },

	{ "get_description",
	  (PyCFunction) pyfwsi_network_location_get_description,
	  METH_NOARGS,
	  "get_description() -> Unicode string or None\n"
	  "\n"
	  "Returns the description of the network location." },

	{ "get_comments",
	  (PyCFunction) pyfwsi_network_location_get_comments,
	  METH_NOARGS,
	  "get_comments() -> Unicode string or None\n"
	  "\n"
	  "Returns the comments of the network location." },

	/* Sentinel */
	{ NULL, NULL, 0, NULL }
};

PyGetSetDef pyfwsi_network_location_object_get_set_definitions[] = {

	{ "location",
	  (getter) pyfwsi_network_location_get_location,
	  (setter) 0,
	  "The location of the network location.",
	  NULL },

	{ "description",
	  (getter) pyfwsi_network_location_get_description,
	  (setter) 0,
	  "The description of the network location.",
	  NULL },

	{ "comments",
	  (getter) pyfwsi_network_location_get_comments,
	  (setter) 0,
	  "The comments of the network location.",
	  NULL },

	/* Sentinel */
	{ NULL, NULL, NULL, NULL, NULL }
};

PyTypeObject pyfwsi_network_location_type_object = {
	PyVarObject_HEAD_INIT( NULL, 0 )

	/* tp_name */
	"pyfwsi.network_location",
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
	"pyfwsi network_location object (wraps libfwsi_item_t type LIBFWSI_ITEM_TYPE_NETWORK_LOCATION)",
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
	pyfwsi_network_location_object_methods,
	/* tp_members */
	0,
	/* tp_getset */
	pyfwsi_network_location_object_get_set_definitions,
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

/* Retrieves the location
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_network_location_get_location(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error = NULL;
	PyObject *string_object  = NULL;
	const char *errors       = NULL;
	uint8_t *location        = NULL;
	static char *function    = "pyfwsi_network_location_get_location";
	size_t location_size     = 0;
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

	result = libfwsi_network_location_get_utf8_location_size(
	          pyfwsi_item->item,
	          &location_size,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve location size.",
		 function );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	else if( ( result == 0 )
	      || ( location_size == 0 ) )
	{
		Py_IncRef(
		 Py_None );

		return( Py_None );
	}
	location = (uint8_t *) PyMem_Malloc(
	                        sizeof( uint8_t ) * location_size );

	if( location == NULL )
	{
		PyErr_Format(
		 PyExc_IOError,
		 "%s: unable to create location.",
		 function );

		goto on_error;
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_network_location_get_utf8_location(
		  pyfwsi_item->item,
		  location,
		  location_size,
		  &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve location.",
		 function );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	/* Pass the string length to PyUnicode_DecodeUTF8
	 * otherwise it makes the end of string character is part
	 * of the string
	 */
	string_object = PyUnicode_DecodeUTF8(
			 (char *) location,
			 (Py_ssize_t) location_size - 1,
			 errors );

	PyMem_Free(
	 location );

	return( string_object );

on_error:
	if( location != NULL )
	{
		PyMem_Free(
		 location );
	}
	return( NULL );
}

/* Retrieves the description
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_network_location_get_description(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error = NULL;
	PyObject *string_object  = NULL;
	const char *errors       = NULL;
	uint8_t *description     = NULL;
	static char *function    = "pyfwsi_network_location_get_description";
	size_t description_size  = 0;
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

	result = libfwsi_network_location_get_utf8_description_size(
	          pyfwsi_item->item,
	          &description_size,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve description size.",
		 function );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	else if( ( result == 0 )
	      || ( description_size == 0 ) )
	{
		Py_IncRef(
		 Py_None );

		return( Py_None );
	}
	description = (uint8_t *) PyMem_Malloc(
	                           sizeof( uint8_t ) * description_size );

	if( description == NULL )
	{
		PyErr_Format(
		 PyExc_IOError,
		 "%s: unable to create description.",
		 function );

		goto on_error;
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_network_location_get_utf8_description(
		  pyfwsi_item->item,
		  description,
		  description_size,
		  &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve description.",
		 function );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	/* Pass the string length to PyUnicode_DecodeUTF8
	 * otherwise it makes the end of string character is part
	 * of the string
	 */
	string_object = PyUnicode_DecodeUTF8(
			 (char *) description,
			 (Py_ssize_t) description_size - 1,
			 errors );

	PyMem_Free(
	 description );

	return( string_object );

on_error:
	if( description != NULL )
	{
		PyMem_Free(
		 description );
	}
	return( NULL );
}

/* Retrieves the comments
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_network_location_get_comments(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error = NULL;
	PyObject *string_object  = NULL;
	const char *errors       = NULL;
	uint8_t *comments        = NULL;
	static char *function    = "pyfwsi_network_location_get_comments";
	size_t comments_size     = 0;
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

	result = libfwsi_network_location_get_utf8_comments_size(
	          pyfwsi_item->item,
	          &comments_size,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve comments size.",
		 function );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	else if( ( result == 0 )
	      || ( comments_size == 0 ) )
	{
		Py_IncRef(
		 Py_None );

		return( Py_None );
	}
	comments = (uint8_t *) PyMem_Malloc(
	                        sizeof( uint8_t ) * comments_size );

	if( comments == NULL )
	{
		PyErr_Format(
		 PyExc_IOError,
		 "%s: unable to create comments.",
		 function );

		goto on_error;
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_network_location_get_utf8_comments(
		  pyfwsi_item->item,
		  comments,
		  comments_size,
		  &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve comments.",
		 function );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	/* Pass the string length to PyUnicode_DecodeUTF8
	 * otherwise it makes the end of string character is part
	 * of the string
	 */
	string_object = PyUnicode_DecodeUTF8(
			 (char *) comments,
			 (Py_ssize_t) comments_size - 1,
			 errors );

	PyMem_Free(
	 comments );

	return( string_object );

on_error:
	if( comments != NULL )
	{
		PyMem_Free(
		 comments );
	}
	return( NULL );
}

