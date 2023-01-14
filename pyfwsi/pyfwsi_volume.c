/*
 * Python object wrapper of libfwsi_item_t type LIBFWSI_ITEM_TYPE_VOLUME
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
#include "pyfwsi_guid.h"
#include "pyfwsi_item.h"
#include "pyfwsi_libcerror.h"
#include "pyfwsi_libfwsi.h"
#include "pyfwsi_python.h"
#include "pyfwsi_unused.h"
#include "pyfwsi_volume.h"

PyMethodDef pyfwsi_volume_object_methods[] = {

	{ "get_name",
	  (PyCFunction) pyfwsi_volume_get_name,
	  METH_NOARGS,
	  "get_name() -> Unicode string\n"
	  "\n"
	  "Retrieves the name." },

	{ "get_identifier",
	  (PyCFunction) pyfwsi_volume_get_identifier,
	  METH_NOARGS,
	  "get_identifier() -> Unicode string\n"
	  "\n"
	  "Retrieves the identifier." },

	{ "get_shell_folder_identifier",
	  (PyCFunction) pyfwsi_volume_get_shell_folder_identifier,
	  METH_NOARGS,
	  "get_shell_folder_identifier() -> Unicode string\n"
	  "\n"
	  "Retrieves the shell folder identifier." },

	/* Sentinel */
	{ NULL, NULL, 0, NULL }
};

PyGetSetDef pyfwsi_volume_object_get_set_definitions[] = {

	{ "name",
	  (getter) pyfwsi_volume_get_name,
	  (setter) 0,
	  "The name.",
	  NULL },

	{ "identifier",
	  (getter) pyfwsi_volume_get_identifier,
	  (setter) 0,
	  "The identifier.",
	  NULL },

	{ "shell_folder_identifier",
	  (getter) pyfwsi_volume_get_shell_folder_identifier,
	  (setter) 0,
	  "The shell folder identifier.",
	  NULL },

	/* Sentinel */
	{ NULL, NULL, NULL, NULL, NULL }
};

PyTypeObject pyfwsi_volume_type_object = {
	PyVarObject_HEAD_INIT( NULL, 0 )

	/* tp_name */
	"pyfwsi.volume",
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
	"pyfwsi volume object (wraps libfwsi_item_t type LIBFWSI_ITEM_TYPE_VOLUME)",
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
	pyfwsi_volume_object_methods,
	/* tp_members */
	0,
	/* tp_getset */
	pyfwsi_volume_object_get_set_definitions,
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

/* Retrieves the name
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_volume_get_name(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	PyObject *string_object  = NULL;
	libcerror_error_t *error = NULL;
	const char *errors       = NULL;
	static char *function    = "pyfwsi_volume_get_name";
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

	result = libfwsi_volume_get_utf8_name_size(
	          pyfwsi_item->item,
	          &utf8_string_size,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to determine size of name as UTF-8 string.",
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

	result = libfwsi_volume_get_utf8_name(
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
		 "%s: unable to retrieve name as UTF-8 string.",
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

/* Retrieves the identifier
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_volume_get_identifier(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	uint8_t guid_data[ 16 ];

	PyObject *string_object  = NULL;
	libcerror_error_t *error = NULL;
	static char *function    = "pyfwsi_volume_get_identifier";
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

	result = libfwsi_volume_get_identifier(
	          pyfwsi_item->item,
	          guid_data,
	          16,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve identifier.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
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

/* Retrieves the shell folder identifier
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_volume_get_shell_folder_identifier(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	uint8_t guid_data[ 16 ];

	PyObject *string_object  = NULL;
	libcerror_error_t *error = NULL;
	static char *function    = "pyfwsi_volume_get_shell_folder_identifier";
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

	result = libfwsi_volume_get_shell_folder_identifier(
	          pyfwsi_item->item,
	          guid_data,
	          16,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve shell folder identifier.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
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

