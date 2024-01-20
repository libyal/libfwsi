/*
 * Python object definition of the libfwsi file entry extension block
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

#include "pyfwsi_datetime.h"
#include "pyfwsi_error.h"
#include "pyfwsi_extension_block.h"
#include "pyfwsi_file_entry_extension.h"
#include "pyfwsi_integer.h"
#include "pyfwsi_libcerror.h"
#include "pyfwsi_libfwsi.h"
#include "pyfwsi_python.h"
#include "pyfwsi_string.h"
#include "pyfwsi_unused.h"

PyMethodDef pyfwsi_file_entry_extension_object_methods[] = {

	{ "get_creation_time",
	  (PyCFunction) pyfwsi_file_entry_extension_get_creation_time,
	  METH_NOARGS,
	  "get_creation_time() -> Datetime\n"
	  "\n"
	  "Returns the creation date and time." },

	{ "get_creation_time_as_integer",
	  (PyCFunction) pyfwsi_file_entry_extension_get_creation_time_as_integer,
	  METH_NOARGS,
	  "get_creation_time_as_integer() -> Integer\n"
	  "\n"
	  "Returns the creation date and time as a 32-bit integer containing a FAT date time value." },

	{ "get_access_time",
	  (PyCFunction) pyfwsi_file_entry_extension_get_access_time,
	  METH_NOARGS,
	  "get_access_time() -> Datetime\n"
	  "\n"
	  "Returns the access date and time." },

	{ "get_access_time_as_integer",
	  (PyCFunction) pyfwsi_file_entry_extension_get_access_time_as_integer,
	  METH_NOARGS,
	  "get_access_time_as_integer() -> Integer\n"
	  "\n"
	  "Returns the access date and time as a 32-bit integer containing a FAT date time value." },

	{ "get_long_name",
	  (PyCFunction) pyfwsi_file_entry_extension_get_long_name,
	  METH_NOARGS,
	  "get_long_name() -> Unicode string or None\n"
	  "\n"
	  "Returns the long name of the file entry extension." },

	{ "get_localized_name",
	  (PyCFunction) pyfwsi_file_entry_extension_get_localized_name,
	  METH_NOARGS,
	  "get_localized_name() -> Unicode string or None\n"
	  "\n"
	  "Returns the localized name of the file entry extension." },

	{ "get_file_reference",
	  (PyCFunction) pyfwsi_file_entry_extension_get_file_reference,
	  METH_NOARGS,
	  "get_file_reference() -> Integer\n"
	  "\n"
	  "Returns the NTFS file reference of the file entry extension." },

	/* Sentinel */
	{ NULL, NULL, 0, NULL }
};

PyGetSetDef pyfwsi_file_entry_extension_object_get_set_definitions[] = {

	{ "creation_time",
	  (getter) pyfwsi_file_entry_extension_get_creation_time,
	  (setter) 0,
	  "The creation date and time.",
	  NULL },

	{ "access_time",
	  (getter) pyfwsi_file_entry_extension_get_access_time,
	  (setter) 0,
	  "The access date and time.",
	  NULL },

	{ "long_name",
	  (getter) pyfwsi_file_entry_extension_get_long_name,
	  (setter) 0,
	  "The long name of the file entry extension.",
	  NULL },

	{ "localized_name",
	  (getter) pyfwsi_file_entry_extension_get_localized_name,
	  (setter) 0,
	  "The localized name of the file entry extension.",
	  NULL },

	{ "file_reference",
	  (getter) pyfwsi_file_entry_extension_get_file_reference,
	  (setter) 0,
	  "The NTFS file reference.",
	  NULL },

	/* Sentinel */
	{ NULL, NULL, NULL, NULL, NULL }
};

PyTypeObject pyfwsi_file_entry_extension_type_object = {
	PyVarObject_HEAD_INIT( NULL, 0 )

	/* tp_name */
	"pyfwsi.file_entry_extension",
	/* tp_basicsize */
	sizeof( pyfwsi_extension_block_t ),
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
	"pyfwsi file entry extension object (wraps libfwsi_extension_block_t signature 0xbeef0004)",
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
	pyfwsi_file_entry_extension_object_methods,
	/* tp_members */
	0,
	/* tp_getset */
	pyfwsi_file_entry_extension_object_get_set_definitions,
	/* tp_base */
	&pyfwsi_extension_block_type_object,
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

/* Retrieves the creation date and time
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_file_entry_extension_get_creation_time(
           pyfwsi_extension_block_t *pyfwsi_extension_block,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error   = NULL;
	PyObject *date_time_object = NULL;
	static char *function      = "pyfwsi_file_entry_extension_get_creation_time";
	uint32_t fat_date_time     = 0;
	int result                 = 0;

	PYFWSI_UNREFERENCED_PARAMETER( arguments )

	if( pyfwsi_extension_block == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid extension block.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_file_entry_extension_get_creation_time(
	          pyfwsi_extension_block->extension_block,
	          &fat_date_time,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve creation time.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	date_time_object = pyfwsi_datetime_new_from_fat_date_time(
	                    fat_date_time );

	return( date_time_object );
}

/* Retrieves the creation date and time as an integer
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_file_entry_extension_get_creation_time_as_integer(
           pyfwsi_extension_block_t *pyfwsi_extension_block,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error = NULL;
	PyObject *integer_object = NULL;
	static char *function    = "pyfwsi_file_entry_extension_get_creation_time_as_integer";
	uint32_t fat_date_time   = 0;
	int result               = 0;

	PYFWSI_UNREFERENCED_PARAMETER( arguments )

	if( pyfwsi_extension_block == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid extension block.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_file_entry_extension_get_creation_time(
	          pyfwsi_extension_block->extension_block,
	          &fat_date_time,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve creation time.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	integer_object = pyfwsi_integer_unsigned_new_from_64bit(
	                  (uint64_t) fat_date_time );

	return( integer_object );
}

/* Retrieves the access date and time
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_file_entry_extension_get_access_time(
           pyfwsi_extension_block_t *pyfwsi_extension_block,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error   = NULL;
	PyObject *date_time_object = NULL;
	static char *function      = "pyfwsi_file_entry_extension_get_access_time";
	uint32_t fat_date_time     = 0;
	int result                 = 0;

	PYFWSI_UNREFERENCED_PARAMETER( arguments )

	if( pyfwsi_extension_block == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid extension block.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_file_entry_extension_get_access_time(
	          pyfwsi_extension_block->extension_block,
	          &fat_date_time,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve access time.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	date_time_object = pyfwsi_datetime_new_from_fat_date_time(
	                    fat_date_time );

	return( date_time_object );
}

/* Retrieves the access date and time as an integer
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_file_entry_extension_get_access_time_as_integer(
           pyfwsi_extension_block_t *pyfwsi_extension_block,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error = NULL;
	PyObject *integer_object = NULL;
	static char *function    = "pyfwsi_file_entry_extension_get_access_time_as_integer";
	uint32_t fat_date_time   = 0;
	int result               = 0;

	PYFWSI_UNREFERENCED_PARAMETER( arguments )

	if( pyfwsi_extension_block == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid extension block.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_file_entry_extension_get_access_time(
	          pyfwsi_extension_block->extension_block,
	          &fat_date_time,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve access time.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	integer_object = pyfwsi_integer_unsigned_new_from_64bit(
	                  (uint64_t) fat_date_time );

	return( integer_object );
}

/* Retrieves the long name
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_file_entry_extension_get_long_name(
           pyfwsi_extension_block_t *pyfwsi_extension_block,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error = NULL;
	PyObject *string_object  = NULL;
	uint8_t *utf8_string     = NULL;
	static char *function    = "pyfwsi_file_entry_extension_get_long_name";
	size_t utf8_string_size  = 0;
	int result               = 0;

	PYFWSI_UNREFERENCED_PARAMETER( arguments )

	if( pyfwsi_extension_block == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid extension blocks.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_file_entry_extension_get_utf8_long_name_size(
	          pyfwsi_extension_block->extension_block,
	          &utf8_string_size,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to determine size of long name as UTF-8 string.",
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
	utf8_string = (uint8_t *) PyMem_Malloc(
	                           sizeof( uint8_t ) * utf8_string_size );

	if( utf8_string == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to create long name.",
		 function );

		goto on_error;
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_file_entry_extension_get_utf8_long_name(
		  pyfwsi_extension_block->extension_block,
		  utf8_string,
		  utf8_string_size,
		  &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve long name as UTF-8 string.",
		 function );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
#if PY_MAJOR_VERSION >= 3 && PY_MINOR_VERSION >= 3
	string_object = pyfwsi_string_new_from_utf8_rfc2279(
			 (uint8_t *) utf8_string,
			 utf8_string_size );
#else
	/* Pass the string length to PyUnicode_DecodeUTF8
	 * otherwise it makes the end of string character is part
	 * of the string
	 */
	string_object = PyUnicode_DecodeUTF8(
	                 utf8_string,
	                 (Py_ssize_t) utf8_string_size - 1,
	                 NULL );
#endif
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

/* Retrieves the localized name
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_file_entry_extension_get_localized_name(
           pyfwsi_extension_block_t *pyfwsi_extension_block,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error   = NULL;
	PyObject *string_object    = NULL;
	uint8_t *localized_name    = NULL;
	static char *function      = "pyfwsi_file_entry_extension_get_localized_name";
	size_t localized_name_size = 0;
	int result                 = 0;

	PYFWSI_UNREFERENCED_PARAMETER( arguments )

	if( pyfwsi_extension_block == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid extension blocks.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_file_entry_extension_get_utf8_localized_name_size(
	          pyfwsi_extension_block->extension_block,
	          &localized_name_size,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve localized name size.",
		 function );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	else if( ( result == 0 )
	      || ( localized_name_size == 0 ) )
	{
		Py_IncRef(
		 Py_None );

		return( Py_None );
	}
	localized_name = (uint8_t *) PyMem_Malloc(
	                              sizeof( uint8_t ) * localized_name_size );

	if( localized_name == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to create localized name.",
		 function );

		goto on_error;
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_file_entry_extension_get_utf8_localized_name(
		  pyfwsi_extension_block->extension_block,
		  localized_name,
		  localized_name_size,
		  &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve localized name.",
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
			 (char *) localized_name,
			 (Py_ssize_t) localized_name_size - 1,
			 NULL );

	PyMem_Free(
	 localized_name );

	return( string_object );

on_error:
	if( localized_name != NULL )
	{
		PyMem_Free(
		 localized_name );
	}
	return( NULL );
}

/* Retrieves the NTFS file reference as an integer
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_file_entry_extension_get_file_reference(
           pyfwsi_extension_block_t *pyfwsi_extension_block,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error = NULL;
	PyObject *integer_object = NULL;
	static char *function    = "pyfwsi_file_entry_extension_get_file_reference";
	uint64_t file_reference  = 0;
	int result               = 0;

	PYFWSI_UNREFERENCED_PARAMETER( arguments )

	if( pyfwsi_extension_block == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid extension block.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_file_entry_extension_get_file_reference(
	          pyfwsi_extension_block->extension_block,
	          &file_reference,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve file reference.",
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
	integer_object = pyfwsi_integer_unsigned_new_from_64bit(
	                  file_reference );

	return( integer_object );
}

