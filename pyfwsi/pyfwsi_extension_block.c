/*
 * Python object wrapper of libfwsi_extension_block_t
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

#if defined( HAVE_STDLIB_H )
#include <stdlib.h>
#endif

#include "pyfwsi_error.h"
#include "pyfwsi_extension_block.h"
#include "pyfwsi_item.h"
#include "pyfwsi_libcerror.h"
#include "pyfwsi_libfwsi.h"
#include "pyfwsi_python.h"
#include "pyfwsi_unused.h"

PyMethodDef pyfwsi_extension_block_object_methods[] = {

	/* Functions to access the extension block data */

	{ "get_signature",
	  (PyCFunction) pyfwsi_extension_block_get_signature,
	  METH_NOARGS,
	  "get_signature() -> Integer\n"
	  "\n"
	  "Returns the signature." },

	{ "get_data_size",
	  (PyCFunction) pyfwsi_extension_block_get_data_size,
	  METH_NOARGS,
	  "get_data_size() -> Integer\n"
	  "\n"
	  "Returns the size of the extension block data." },

#ifdef TODO
	{ "get_data",
	  (PyCFunction) pyfwsi_extension_block_get_data,
	  METH_NOARGS,
	  "get_data() -> String or None\n"
	  "\n"
	  "Returns the extension block data." },
#endif

	/* Sentinel */
	{ NULL, NULL, 0, NULL }
};

PyGetSetDef pyfwsi_extension_block_object_get_set_definitions[] = {

	{ "signature",
	  (getter) pyfwsi_extension_block_get_signature,
	  (setter) 0,
	  "The signature.",
	  NULL },

	{ "data_size",
	  (getter) pyfwsi_extension_block_get_data_size,
	  (setter) 0,
	  "The size of the extension block data.",
	  NULL },

#ifdef TODO
	{ "data",
	  (getter) pyfwsi_extension_block_get_data,
	  (setter) 0,
	  "The extension block data.",
	  NULL },
#endif

	/* Sentinel */
	{ NULL, NULL, NULL, NULL, NULL }
};

PyTypeObject pyfwsi_extension_block_type_object = {
	PyVarObject_HEAD_INIT( NULL, 0 )

	/* tp_name */
	"pyfwsi.extension_block",
	/* tp_basicsize */
	sizeof( pyfwsi_extension_block_t ),
	/* tp_itemsize */
	0,
	/* tp_dealloc */
	(destructor) pyfwsi_extension_block_free,
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
	"pyfwsi extension block object (wraps libfwsi_extension_block_t)",
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
	pyfwsi_extension_block_object_methods,
	/* tp_members */
	0,
	/* tp_getset */
	pyfwsi_extension_block_object_get_set_definitions,
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
	(initproc) pyfwsi_extension_block_init,
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

/* Creates a new pyfwsi extension block object
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_extension_block_new(
           PyTypeObject *type_object,
           libfwsi_extension_block_t *extension_block,
           PyObject *parent_object )
{
	pyfwsi_extension_block_t *pyfwsi_extension_block = NULL;
	static char *function                            = "pyfwsi_extension_block_new";

	if( extension_block == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid extension block.",
		 function );

		return( NULL );
	}
	pyfwsi_extension_block = PyObject_New(
	                          struct pyfwsi_extension_block,
	                          type_object );

	if( pyfwsi_extension_block == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize extension block.",
		 function );

		goto on_error;
	}
	pyfwsi_extension_block->extension_block = extension_block;
	pyfwsi_extension_block->parent_object   = parent_object;

	Py_IncRef(
	 (PyObject *) pyfwsi_extension_block->parent_object );

	return( (PyObject *) pyfwsi_extension_block );

on_error:
	if( pyfwsi_extension_block != NULL )
	{
		Py_DecRef(
		 (PyObject *) pyfwsi_extension_block );
	}
	return( NULL );
}

/* Initializes an extension block object
 * Returns 0 if successful or -1 on error
 */
int pyfwsi_extension_block_init(
     pyfwsi_extension_block_t *pyfwsi_extension_block )
{
	static char *function = "pyfwsi_extension_block_init";

	if( pyfwsi_extension_block == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid extension block.",
		 function );

		return( -1 );
	}
	/* Make sure libfwsi extension block is set to NULL
	 */
	pyfwsi_extension_block->extension_block = NULL;

	return( 0 );
}

/* Frees an extension block object
 */
void pyfwsi_extension_block_free(
      pyfwsi_extension_block_t *pyfwsi_extension_block )
{
	libcerror_error_t *error    = NULL;
	struct _typeobject *ob_type = NULL;
	static char *function       = "pyfwsi_extension_block_free";
	int result                  = 0;

	if( pyfwsi_extension_block == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid extension block.",
		 function );

		return;
	}
	if( pyfwsi_extension_block->extension_block == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid extension block - missing libfwsi extension block.",
		 function );

		return;
	}
	ob_type = Py_TYPE(
	           pyfwsi_extension_block );

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

	result = libfwsi_extension_block_free(
	          &( pyfwsi_extension_block->extension_block ),
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_MemoryError,
		 "%s: unable to free extension block.",
		 function );

		libcerror_error_free(
		 &error );
	}
	if( pyfwsi_extension_block->parent_object != NULL )
	{
		Py_DecRef(
		 (PyObject *) pyfwsi_extension_block->parent_object );
	}
	ob_type->tp_free(
	 (PyObject*) pyfwsi_extension_block );
}

/* Retrieves the signature
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_extension_block_get_signature(
           pyfwsi_extension_block_t *pyfwsi_extension_block,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error = NULL;
	static char *function    = "pyfwsi_extension_block_get_signature";
	uint32_t signature       = 0;
	int result               = 0;

	PYFWSI_UNREFERENCED_PARAMETER( arguments )

	if( pyfwsi_extension_block == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid extension block.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_extension_block_get_signature(
	          pyfwsi_extension_block->extension_block,
	          &signature,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve signature.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	return( PyLong_FromUnsignedLong(
	         (unsigned long) signature ) );
}

/* Retrieves the data size
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_extension_block_get_data_size(
           pyfwsi_extension_block_t *pyfwsi_extension_block,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error = NULL;
	static char *function    = "pyfwsi_extension_block_get_data_size";
	size_t data_size         = 0;
	int result               = 0;

	PYFWSI_UNREFERENCED_PARAMETER( arguments )

	if( pyfwsi_extension_block == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid extension block.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_extension_block_get_data_size(
	          pyfwsi_extension_block->extension_block,
	          &data_size,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve data size.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	return( PyLong_FromUnsignedLong(
	         (unsigned long) data_size ) );
}

#ifdef TODO
/* Retrieves the data
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_extension_block_get_data(
           pyfwsi_extension_block_t *pyfwsi_extension_block,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error = NULL;
	PyObject *string_object  = NULL;
	uint8_t *data            = NULL;
	static char *function    = "pyfwsi_extension_block_get_data";
	size_t data_size         = 0;
	int result               = 0;

	PYFWSI_UNREFERENCED_PARAMETER( arguments )

	if( pyfwsi_extension_block == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid extension block.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_extension_block_get_data_size(
	          pyfwsi_extension_block->extension_block,
	          &data_size,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve data size.",
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
	data = (uint8_t *) PyMem_Malloc(
	                    sizeof( uint8_t ) * data_size );

	if( data == NULL )
	{
		PyErr_Format(
		 PyExc_IOError,
		 "%s: unable to create data.",
		 function );

		goto on_error;
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_extension_block_get_data(
		  pyfwsi_extension_block->extension_block,
		  data,
		  data_size,
		  &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve data.",
		 function );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
#if PY_MAJOR_VERSION >= 3
	string_object = PyBytes_FromStringAndSize(
			 (char *) data,
			 (Py_ssize_t) data_size );
#else
	string_object = PyString_FromStringAndSize(
			 (char *) data,
			 (Py_ssize_t) data_size );
#endif
	PyMem_Free(
	 data );

	return( string_object );

on_error:
	if( data != NULL )
	{
		PyMem_Free(
		 data );
	}
	return( NULL );
}
#endif

