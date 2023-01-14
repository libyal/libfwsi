/*
 * Python object definition of the libfwsi file entry item
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

#include "pyfwsi_datetime.h"
#include "pyfwsi_error.h"
#include "pyfwsi_file_entry.h"
#include "pyfwsi_integer.h"
#include "pyfwsi_item.h"
#include "pyfwsi_libcerror.h"
#include "pyfwsi_libfwsi.h"
#include "pyfwsi_python.h"
#include "pyfwsi_unused.h"

PyMethodDef pyfwsi_file_entry_object_methods[] = {

	{ "get_file_size",
	  (PyCFunction) pyfwsi_file_entry_get_file_size,
	  METH_NOARGS,
	  "get_file_size() -> Integer\n"
	  "\n"
	  "Retrieves the file size." },

	{ "get_modification_time",
	  (PyCFunction) pyfwsi_file_entry_get_modification_time,
	  METH_NOARGS,
	  "get_modification_time() -> Datetime\n"
	  "\n"
	  "Returns the modification date and time." },

	{ "get_modification_time_as_integer",
	  (PyCFunction) pyfwsi_file_entry_get_modification_time_as_integer,
	  METH_NOARGS,
	  "get_modification_time_as_integer() -> Integer\n"
	  "\n"
	  "Returns the modification date and time as a 32-bit integer containing a FAT date time value." },

	{ "get_file_attribute_flags",
	  (PyCFunction) pyfwsi_file_entry_get_file_attribute_flags,
	  METH_NOARGS,
	  "get_file_attribute_flags() -> Integer\n"
	  "\n"
	  "Retrieves the file attribute flags." },

	{ "get_name",
	  (PyCFunction) pyfwsi_file_entry_get_name,
	  METH_NOARGS,
	  "get_name() -> Unicode string or None\n"
	  "\n"
	  "Returns the name of the file entry." },

	/* Sentinel */
	{ NULL, NULL, 0, NULL }
};

PyGetSetDef pyfwsi_file_entry_object_get_set_definitions[] = {

	{ "file_size",
	  (getter) pyfwsi_file_entry_get_file_size,
	  (setter) 0,
	  "The file size.",
	  NULL },

	{ "modification_time",
	  (getter) pyfwsi_file_entry_get_modification_time,
	  (setter) 0,
	  "The modification date and time.",
	  NULL },

	{ "file_attribute_flags",
	  (getter) pyfwsi_file_entry_get_file_attribute_flags,
	  (setter) 0,
	  "The file attibute flags.",
	  NULL },

	{ "name",
	  (getter) pyfwsi_file_entry_get_name,
	  (setter) 0,
	  "The name of the file entry.",
	  NULL },

	/* Sentinel */
	{ NULL, NULL, NULL, NULL, NULL }
};

PyTypeObject pyfwsi_file_entry_type_object = {
	PyVarObject_HEAD_INIT( NULL, 0 )

	/* tp_name */
	"pyfwsi.file_entry",
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
	"pyfwsi file entry object (wraps libfwsi_item_t type LIBFWSI_ITEM_TYPE_FILE_ENTRY)",
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
	pyfwsi_file_entry_object_methods,
	/* tp_members */
	0,
	/* tp_getset */
	pyfwsi_file_entry_object_get_set_definitions,
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

/* Retrieves the file size
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_file_entry_get_file_size(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error = NULL;
	PyObject *integer_object = NULL;
	static char *function    = "pyfwsi_file_entry_get_file_size";
	uint32_t file_size       = 0;
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

	result = libfwsi_file_entry_get_file_size(
	          pyfwsi_item->item,
	          &file_size,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve file size.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	integer_object = pyfwsi_integer_unsigned_new_from_64bit(
	                  (uint64_t) file_size );

	return( integer_object );
}

/* Retrieves the modification date and time
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_file_entry_get_modification_time(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error   = NULL;
	PyObject *date_time_object = NULL;
	static char *function      = "pyfwsi_file_entry_get_modification_time";
	uint32_t fat_date_time     = 0;
	int result                 = 0;

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

	result = libfwsi_file_entry_get_modification_time(
	          pyfwsi_item->item,
	          &fat_date_time,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve modification time.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	date_time_object = pyfwsi_datetime_new_from_fat_date_time(
	                    fat_date_time );

	return( date_time_object );
}

/* Retrieves the modification date and time as an integer
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_file_entry_get_modification_time_as_integer(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error = NULL;
	PyObject *integer_object = NULL;
	static char *function    = "pyfwsi_file_entry_get_modification_time_as_integer";
	uint32_t fat_date_time   = 0;
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

	result = libfwsi_file_entry_get_modification_time(
	          pyfwsi_item->item,
	          &fat_date_time,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve modification time.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	integer_object = pyfwsi_integer_unsigned_new_from_64bit(
	                  (uint64_t) fat_date_time );

	return( integer_object );
}

/* Retrieves the file attribute flags
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_file_entry_get_file_attribute_flags(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error      = NULL;
	PyObject *integer_object      = NULL;
	static char *function         = "pyfwsi_file_entry_get_file_attribute_flags";
	uint32_t file_attribute_flags = 0;
	int result                    = 0;

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

	result = libfwsi_file_entry_get_file_attribute_flags(
	          pyfwsi_item->item,
	          &file_attribute_flags,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve file attribute flags.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	integer_object = pyfwsi_integer_unsigned_new_from_64bit(
	                  (uint64_t) file_attribute_flags );

	return( integer_object );
}

/* Retrieves the name
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_file_entry_get_name(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error = NULL;
	PyObject *string_object  = NULL;
	const char *errors       = NULL;
	uint8_t *name            = NULL;
	static char *function    = "pyfwsi_file_entry_get_name";
	size_t name_size         = 0;
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

	result = libfwsi_file_entry_get_utf8_name_size(
	          pyfwsi_item->item,
	          &name_size,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve name size.",
		 function );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	else if( ( result == 0 )
	      || ( name_size == 0 ) )
	{
		Py_IncRef(
		 Py_None );

		return( Py_None );
	}
	name = (uint8_t *) PyMem_Malloc(
	                    sizeof( uint8_t ) * name_size );

	if( name == NULL )
	{
		PyErr_Format(
		 PyExc_IOError,
		 "%s: unable to create name.",
		 function );

		goto on_error;
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_file_entry_get_utf8_name(
		  pyfwsi_item->item,
		  name,
		  name_size,
		  &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve name.",
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
			 (char *) name,
			 (Py_ssize_t) name_size - 1,
			 errors );

	PyMem_Free(
	 name );

	return( string_object );

on_error:
	if( name != NULL )
	{
		PyMem_Free(
		 name );
	}
	return( NULL );
}

