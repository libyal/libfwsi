/*
 * Python object wrapper of libfwsi_item_t type LIBFWSI_ITEM_TYPE_NETWORK_LOCATION
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
	  "get_location() -> Unicode string\n"
	  "\n"
	  "Retrieves the location." },

	{ "get_description",
	  (PyCFunction) pyfwsi_network_location_get_description,
	  METH_NOARGS,
	  "get_description() -> Unicode string\n"
	  "\n"
	  "Retrieves the description." },

	{ "get_comments",
	  (PyCFunction) pyfwsi_network_location_get_comments,
	  METH_NOARGS,
	  "get_comments() -> Unicode string\n"
	  "\n"
	  "Retrieves the comments." },

	/* Sentinel */
	{ NULL, NULL, 0, NULL }
};

PyGetSetDef pyfwsi_network_location_object_get_set_definitions[] = {

	{ "location",
	  (getter) pyfwsi_network_location_get_location,
	  (setter) 0,
	  "The location.",
	  NULL },

	{ "description",
	  (getter) pyfwsi_network_location_get_description,
	  (setter) 0,
	  "The description.",
	  NULL },

	{ "comments",
	  (getter) pyfwsi_network_location_get_comments,
	  (setter) 0,
	  "The comments.",
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
	"pyfwsi network location object (wraps libfwsi_item_t type LIBFWSI_ITEM_TYPE_NETWORK_LOCATION)",
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
	PyObject *string_object  = NULL;
	libcerror_error_t *error = NULL;
	const char *errors       = NULL;
	static char *function    = "pyfwsi_network_location_get_location";
	char *utf8_string        = NULL;
	size_t utf8_string_size  = 0;
	int result               = 0;

	PYFWSI_UNREFERENCED_PARAMETER( arguments )

	if( pyfwsi_item == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid item.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_network_location_get_utf8_location_size(
	          pyfwsi_item->item,
	          &utf8_string_size,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to determine size of location as UTF-8 string.",
		 function );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	else if( ( result == 0 )
	      || ( utf8_string_size == 0 ) )
	{
		Py_IncRef(
		 Py_None );

		return( Py_None );
	}
	utf8_string = (char *) PyMem_Malloc(
	                        sizeof( char ) * utf8_string_size );

	if( utf8_string == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to create UTF-8 string.",
		 function );

		goto on_error;
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_network_location_get_utf8_location(
	          pyfwsi_item->item,
	          (uint8_t *) utf8_string,
	          utf8_string_size,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve location as UTF-8 string.",
		 function );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	/* Pass the string length to PyUnicode_DecodeUTF8 otherwise it makes
	 * the end of string character is part of the string
	 */
	string_object = PyUnicode_DecodeUTF8(
	                 utf8_string,
	                 (Py_ssize_t) utf8_string_size - 1,
	                 errors );

	if( string_object == NULL )
	{
		PyErr_Format(
		 PyExc_IOError,
		 "%s: unable to convert UTF-8 string into Unicode object.",
		 function );

		goto on_error;
	}
	PyMem_Free(
	 utf8_string );

	return( string_object );

on_error:
	if( utf8_string != NULL )
	{
		PyMem_Free(
		 utf8_string );
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
	PyObject *string_object  = NULL;
	libcerror_error_t *error = NULL;
	const char *errors       = NULL;
	static char *function    = "pyfwsi_network_location_get_description";
	char *utf8_string        = NULL;
	size_t utf8_string_size  = 0;
	int result               = 0;

	PYFWSI_UNREFERENCED_PARAMETER( arguments )

	if( pyfwsi_item == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid item.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_network_location_get_utf8_description_size(
	          pyfwsi_item->item,
	          &utf8_string_size,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to determine size of description as UTF-8 string.",
		 function );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	else if( ( result == 0 )
	      || ( utf8_string_size == 0 ) )
	{
		Py_IncRef(
		 Py_None );

		return( Py_None );
	}
	utf8_string = (char *) PyMem_Malloc(
	                        sizeof( char ) * utf8_string_size );

	if( utf8_string == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to create UTF-8 string.",
		 function );

		goto on_error;
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_network_location_get_utf8_description(
	          pyfwsi_item->item,
	          (uint8_t *) utf8_string,
	          utf8_string_size,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve description as UTF-8 string.",
		 function );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	/* Pass the string length to PyUnicode_DecodeUTF8 otherwise it makes
	 * the end of string character is part of the string
	 */
	string_object = PyUnicode_DecodeUTF8(
	                 utf8_string,
	                 (Py_ssize_t) utf8_string_size - 1,
	                 errors );

	if( string_object == NULL )
	{
		PyErr_Format(
		 PyExc_IOError,
		 "%s: unable to convert UTF-8 string into Unicode object.",
		 function );

		goto on_error;
	}
	PyMem_Free(
	 utf8_string );

	return( string_object );

on_error:
	if( utf8_string != NULL )
	{
		PyMem_Free(
		 utf8_string );
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
	PyObject *string_object  = NULL;
	libcerror_error_t *error = NULL;
	const char *errors       = NULL;
	static char *function    = "pyfwsi_network_location_get_comments";
	char *utf8_string        = NULL;
	size_t utf8_string_size  = 0;
	int result               = 0;

	PYFWSI_UNREFERENCED_PARAMETER( arguments )

	if( pyfwsi_item == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid item.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_network_location_get_utf8_comments_size(
	          pyfwsi_item->item,
	          &utf8_string_size,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to determine size of comments as UTF-8 string.",
		 function );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	else if( ( result == 0 )
	      || ( utf8_string_size == 0 ) )
	{
		Py_IncRef(
		 Py_None );

		return( Py_None );
	}
	utf8_string = (char *) PyMem_Malloc(
	                        sizeof( char ) * utf8_string_size );

	if( utf8_string == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to create UTF-8 string.",
		 function );

		goto on_error;
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_network_location_get_utf8_comments(
	          pyfwsi_item->item,
	          (uint8_t *) utf8_string,
	          utf8_string_size,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve comments as UTF-8 string.",
		 function );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	/* Pass the string length to PyUnicode_DecodeUTF8 otherwise it makes
	 * the end of string character is part of the string
	 */
	string_object = PyUnicode_DecodeUTF8(
	                 utf8_string,
	                 (Py_ssize_t) utf8_string_size - 1,
	                 errors );

	if( string_object == NULL )
	{
		PyErr_Format(
		 PyExc_IOError,
		 "%s: unable to convert UTF-8 string into Unicode object.",
		 function );

		goto on_error;
	}
	PyMem_Free(
	 utf8_string );

	return( string_object );

on_error:
	if( utf8_string != NULL )
	{
		PyMem_Free(
		 utf8_string );
	}
	return( NULL );
}

