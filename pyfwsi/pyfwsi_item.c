/*
 * Python object wrapper of libfwsi_item_t
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
#include <narrow_string.h>
#include <types.h>

#if defined( HAVE_STDLIB_H )
#include <stdlib.h>
#endif

#include "pyfwsi_compressed_folder.h"
#include "pyfwsi_control_panel_category.h"
#include "pyfwsi_control_panel_item.h"
#include "pyfwsi_error.h"
#include "pyfwsi_extension_block.h"
#include "pyfwsi_extension_blocks.h"
#include "pyfwsi_file_entry.h"
#include "pyfwsi_file_entry_extension.h"
#include "pyfwsi_guid.h"
#include "pyfwsi_item.h"
#include "pyfwsi_item_list.h"
#include "pyfwsi_libcerror.h"
#include "pyfwsi_libclocale.h"
#include "pyfwsi_libfwsi.h"
#include "pyfwsi_network_location.h"
#include "pyfwsi_root_folder.h"
#include "pyfwsi_python.h"
#include "pyfwsi_unused.h"
#include "pyfwsi_users_property_view.h"
#include "pyfwsi_volume.h"

PyMethodDef pyfwsi_item_object_methods[] = {

	{ "copy_from_byte_stream",
	  (PyCFunction) pyfwsi_item_copy_from_byte_stream,
	  METH_VARARGS | METH_KEYWORDS,
	  "copy_from_byte_stream(byte_stream, ascii_codepage=cp1252)\n"
	  "\n"
	  "Copies the the item from the byte stream." },

	/* Functions to access the item data */

	{ "get_class_type",
	  (PyCFunction) pyfwsi_item_get_class_type,
	  METH_NOARGS,
	  "get_class_type() -> Integer\n"
	  "\n"
	  "Returns the class type." },

	{ "get_data_size",
	  (PyCFunction) pyfwsi_item_get_data_size,
	  METH_NOARGS,
	  "get_data_size() -> Integer\n"
	  "\n"
	  "Returns the size of the item data." },

	{ "get_delegate_folder_identifier",
	  (PyCFunction) pyfwsi_item_get_delegate_folder_identifier,
	  METH_NOARGS,
	  "get_delegate_folder_identifier() -> Unicode string or None\n"
	  "\n"
	  "Retrieves the delegate folder identifier." },

	/* Functions to access the extension blocks */

	{ "get_number_of_extension_blocks",
	  (PyCFunction) pyfwsi_item_get_number_of_extension_blocks,
	  METH_NOARGS,
	  "get_number_of_extension_blocks() -> Integer\n"
	  "\n"
	  "Retrieves the number of extension blocks." },

	{ "get_extension_block",
	  (PyCFunction) pyfwsi_item_get_extension_block,
	  METH_VARARGS | METH_KEYWORDS,
	  "get_extension_block(extension_block_index) -> Object\n"
	  "\n"
	  "Retrieves a specific extension block." },

	/* Sentinel */
	{ NULL, NULL, 0, NULL }
};

PyGetSetDef pyfwsi_item_object_get_set_definitions[] = {

	{ "class_type",
	  (getter) pyfwsi_item_get_class_type,
	  (setter) 0,
	  "The class type.",
	  NULL },

	{ "data_size",
	  (getter) pyfwsi_item_get_data_size,
	  (setter) 0,
	  "The size of the item data.",
	  NULL },

	{ "delegate_folder_identifier",
	  (getter) pyfwsi_item_get_delegate_folder_identifier,
	  (setter) 0,
	  "The delegate folder identifier.",
	  NULL },

	{ "number_of_extension_blocks",
	  (getter) pyfwsi_item_get_number_of_extension_blocks,
	  (setter) 0,
	  "The number of extension blocks.",
	  NULL },

	{ "extension_blocks",
	  (getter) pyfwsi_item_get_extension_blocks,
	  (setter) 0,
	  "The extension blocks",
	  NULL },

	/* Sentinel */
	{ NULL, NULL, NULL, NULL, NULL }
};

PyTypeObject pyfwsi_item_type_object = {
	PyVarObject_HEAD_INIT( NULL, 0 )

	/* tp_name */
	"pyfwsi.item",
	/* tp_basicsize */
	sizeof( pyfwsi_item_t ),
	/* tp_itemsize */
	0,
	/* tp_dealloc */
	(destructor) pyfwsi_item_free,
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
	"pyfwsi item object (wraps libfwsi_item_t)",
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
	pyfwsi_item_object_methods,
	/* tp_members */
	0,
	/* tp_getset */
	pyfwsi_item_object_get_set_definitions,
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
	(initproc) pyfwsi_item_init,
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

/* Creates a new pyfwsi item object
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_item_new(
           PyTypeObject *type_object,
           libfwsi_item_t *item,
           PyObject *parent_object )
{
	pyfwsi_item_t *pyfwsi_item = NULL;
	static char *function      = "pyfwsi_item_new";

	if( item == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid item.",
		 function );

		return( NULL );
	}
	pyfwsi_item = PyObject_New(
	               struct pyfwsi_item,
	               type_object );

	if( pyfwsi_item == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize item.",
		 function );

		goto on_error;
	}
	pyfwsi_item->item          = item;
	pyfwsi_item->parent_object = parent_object;

	Py_IncRef(
	 (PyObject *) pyfwsi_item->parent_object );

	return( (PyObject *) pyfwsi_item );

on_error:
	if( pyfwsi_item != NULL )
	{
		Py_DecRef(
		 (PyObject *) pyfwsi_item );
	}
	return( NULL );
}

/* Initializes an item object
 * Returns 0 if successful or -1 on error
 */
int pyfwsi_item_init(
     pyfwsi_item_t *pyfwsi_item )
{
	libcerror_error_t *error = NULL;
	static char *function    = "pyfwsi_item_init";

	if( pyfwsi_item == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid item.",
		 function );

		return( -1 );
	}
	pyfwsi_item->item          = NULL;
	pyfwsi_item->parent_object = NULL;

	if( libfwsi_item_initialize(
	     &( pyfwsi_item->item ),
	     &error ) != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_MemoryError,
		 "%s: unable to initialize item.",
		 function );

		libcerror_error_free(
		 &error );

		return( -1 );
	}
	return( 0 );
}

/* Frees an item object
 */
void pyfwsi_item_free(
      pyfwsi_item_t *pyfwsi_item )
{
	libcerror_error_t *error    = NULL;
	struct _typeobject *ob_type = NULL;
	static char *function       = "pyfwsi_item_free";
	int result                  = 0;

	if( pyfwsi_item == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid item.",
		 function );

		return;
	}
	if( pyfwsi_item->item == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid item - missing libfwsi item.",
		 function );

		return;
	}
	ob_type = Py_TYPE(
	           pyfwsi_item );

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

	result = libfwsi_item_free(
	          &( pyfwsi_item->item ),
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_MemoryError,
		 "%s: unable to free item.",
		 function );

		libcerror_error_free(
		 &error );
	}
	if( pyfwsi_item->parent_object != NULL )
	{
		Py_DecRef(
		 (PyObject *) pyfwsi_item->parent_object );
	}
	ob_type->tp_free(
	 (PyObject*) pyfwsi_item );
}

/* Copies the item from a byte stream
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_item_copy_from_byte_stream(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments,
           PyObject *keywords )
{
	PyObject *string_object       = NULL;
	libcerror_error_t *error      = NULL;
	static char *function         = "pyfwsi_item_copy_from_byte_stream";
	static char *keyword_list[]   = { "byte_stream", "ascii_codepage", NULL };
	const char *byte_stream       = NULL;
	char *codepage_string         = NULL;
	Py_ssize_t byte_stream_size   = 0;
	size_t codepage_string_length = 0;
	uint32_t feature_flags        = 0;
	int ascii_codepage            = LIBFWSI_CODEPAGE_WINDOWS_1252;
	int result                    = 0;

#if PY_MAJOR_VERSION >= 3 && PY_MINOR_VERSION >= 9
	PyTypeObject *type_object     = NULL;
	int item_type                 = 0;
#endif

	if( pyfwsi_item == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid item.",
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

	result = libfwsi_item_copy_from_byte_stream(
	          pyfwsi_item->item,
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
		 "%s: unable to copy item from byte stream.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
#if PY_MAJOR_VERSION >= 3 && PY_MINOR_VERSION >= 9
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_item_get_type(
	          pyfwsi_item->item,
	          &item_type,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve item type.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	switch( item_type )
	{
		case LIBFWSI_ITEM_TYPE_COMPRESSED_FOLDER:
			type_object = &pyfwsi_compressed_folder_type_object;
			break;

		case LIBFWSI_ITEM_TYPE_CONTROL_PANEL_CATEGORY:
			type_object = &pyfwsi_control_panel_category_type_object;
			break;

		case LIBFWSI_ITEM_TYPE_CONTROL_PANEL_ITEM:
			type_object = &pyfwsi_control_panel_item_type_object;
			break;

		case LIBFWSI_ITEM_TYPE_FILE_ENTRY:
			type_object = &pyfwsi_file_entry_type_object;
			break;

		case LIBFWSI_ITEM_TYPE_NETWORK_LOCATION:
			type_object = &pyfwsi_network_location_type_object;
			break;

		case LIBFWSI_ITEM_TYPE_ROOT_FOLDER:
			type_object = &pyfwsi_root_folder_type_object;
			break;

		case LIBFWSI_ITEM_TYPE_USERS_PROPERTY_VIEW:
			type_object = &pyfwsi_users_property_view_type_object;
			break;

		case LIBFWSI_ITEM_TYPE_VOLUME:
			type_object = &pyfwsi_volume_type_object;
			break;

		case LIBFWSI_ITEM_TYPE_UNKNOWN:
		case LIBFWSI_ITEM_TYPE_CDBURN:
		case LIBFWSI_ITEM_TYPE_GAME_FOLDER:
		case LIBFWSI_ITEM_TYPE_URI:
		default:
			break;
	}
	if( type_object != NULL )
	{
		Py_SET_TYPE(
		 pyfwsi_item,
		 type_object );
	}
#endif /* PY_MAJOR_VERSION >= 3 && PY_MINOR_VERSION >= 9 */

	Py_IncRef(
	 Py_None );

	return( Py_None );
}

/* Retrieves the class type
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_item_get_class_type(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error = NULL;
	static char *function    = "pyfwsi_item_get_class_type";
	uint8_t class_type       = 0;
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

	result = libfwsi_item_get_class_type(
	          pyfwsi_item->item,
	          &class_type,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve class type.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	return( PyLong_FromUnsignedLong(
	         (unsigned long) class_type ) );
}

/* Retrieves the data size
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_item_get_data_size(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error = NULL;
	static char *function    = "pyfwsi_item_get_data_size";
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

	result = libfwsi_item_get_data_size(
	          pyfwsi_item->item,
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

/* Retrieves the delegate folder identifier
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_item_get_delegate_folder_identifier(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	uint8_t guid_data[ 16 ];

	PyObject *string_object  = NULL;
	libcerror_error_t *error = NULL;
	static char *function    = "pyfwsi_item_get_delegate_folder_identifier";
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

	result = libfwsi_item_get_delegate_folder_identifier(
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
		 "%s: unable to retrieve identifier.",
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

/* Retrieves the number of extension blocks
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_item_get_number_of_extension_blocks(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error       = NULL;
	PyObject *integer_object       = NULL;
	static char *function          = "pyfwsi_item_get_number_of_extension_blocks";
	int number_of_extension_blocks = 0;
	int result                     = 0;

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

	result = libfwsi_item_get_number_of_extension_blocks(
	          pyfwsi_item->item,
	          &number_of_extension_blocks,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve number of extension blocks.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
#if PY_MAJOR_VERSION >= 3
	integer_object = PyLong_FromLong(
	                  (long) number_of_extension_blocks );
#else
	integer_object = PyInt_FromLong(
	                  (long) number_of_extension_blocks );
#endif
	return( integer_object );
}

/* Retrieves a specific extension block by index
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_item_get_extension_block_by_index(
           PyObject *pyfwsi_item,
           int extension_block_index )
{
	libcerror_error_t *error                   = NULL;
	libfwsi_extension_block_t *extension_block = NULL;
	PyObject *extension_block_object           = NULL;
	PyTypeObject *type_object                  = NULL;
	static char *function                      = "pyfwsi_item_get_extension_block_by_index";
	uint32_t signature                         = 0;
	int result                                 = 0;

	if( pyfwsi_item == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid item.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_item_get_extension_block(
	          ( (pyfwsi_item_t *) pyfwsi_item )->item,
	          extension_block_index,
	          &extension_block,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve extension block: %d.",
		 function,
		 extension_block_index );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	Py_BEGIN_ALLOW_THREADS

	result = libfwsi_extension_block_get_signature(
	          extension_block,
	          &signature,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve extension block: %d signature.",
		 function,
		 extension_block_index );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	switch( signature )
	{
		case 0xbeef0004UL:
			type_object = &pyfwsi_file_entry_extension_type_object;
			break;

		default:
			type_object = &pyfwsi_extension_block_type_object;
			break;
	}
	extension_block_object = pyfwsi_extension_block_new(
	                          type_object,
	                          extension_block,
	                          pyfwsi_item );

	if( extension_block_object == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to create extension block object.",
		 function );

		goto on_error;
	}
	return( extension_block_object );

on_error:
	if( extension_block != NULL )
	{
		libfwsi_extension_block_free(
		 &extension_block,
		 NULL );
	}
	return( NULL );
}

/* Retrieves a specific extension block
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_item_get_extension_block(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments,
           PyObject *keywords )
{
	PyObject *extension_block_object = NULL;
	static char *keyword_list[]      = { "extension_block_index", NULL };
	int extension_block_index        = 0;

	if( PyArg_ParseTupleAndKeywords(
	     arguments,
	     keywords,
	     "i",
	     keyword_list,
	     &extension_block_index ) == 0 )
	{
		return( NULL );
	}
	extension_block_object = pyfwsi_item_get_extension_block_by_index(
	                          (PyObject *) pyfwsi_item,
	                          extension_block_index );

	return( extension_block_object );
}

/* Retrieves an extension blocks sequence and iterator object for the extension blocks
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_item_get_extension_blocks(
           pyfwsi_item_t *pyfwsi_item,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error          = NULL;
	PyObject *extension_blocks_object = NULL;
	static char *function             = "pyfwsi_item_get_extension_blocks";
	int number_of_extension_blocks    = 0;
	int result                        = 0;

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

	result = libfwsi_item_get_number_of_extension_blocks(
	          pyfwsi_item->item,
	          &number_of_extension_blocks,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyfwsi_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve number of extension blocks.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	extension_blocks_object = pyfwsi_extension_blocks_new(
	                           (PyObject *) pyfwsi_item,
	                           &pyfwsi_item_get_extension_block_by_index,
	                           number_of_extension_blocks );

	if( extension_blocks_object == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to create extension blocks object.",
		 function );

		return( NULL );
	}
	return( extension_blocks_object );
}

