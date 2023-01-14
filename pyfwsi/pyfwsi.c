/*
 * Python bindings module for libfwsi (pyfwsi)
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
#include <narrow_string.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( HAVE_WINAPI )
#include <stdlib.h>
#endif

#include "pyfwsi.h"
#include "pyfwsi_error.h"
#include "pyfwsi_extension_block.h"
#include "pyfwsi_extension_blocks.h"
#include "pyfwsi_file_entry.h"
#include "pyfwsi_file_entry_extension.h"
#include "pyfwsi_item.h"
#include "pyfwsi_item_list.h"
#include "pyfwsi_items.h"
#include "pyfwsi_libcerror.h"
#include "pyfwsi_libfwsi.h"
#include "pyfwsi_network_location.h"
#include "pyfwsi_python.h"
#include "pyfwsi_root_folder.h"
#include "pyfwsi_unused.h"
#include "pyfwsi_volume.h"

/* The pyfwsi module methods
 */
PyMethodDef pyfwsi_module_methods[] = {
	{ "get_version",
	  (PyCFunction) pyfwsi_get_version,
	  METH_NOARGS,
	  "get_version() -> String\n"
	  "\n"
	  "Retrieves the version." },

	/* Sentinel */
	{ NULL, NULL, 0, NULL }
};

/* Retrieves the pyfwsi/libfwsi version
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyfwsi_get_version(
           PyObject *self PYFWSI_ATTRIBUTE_UNUSED,
           PyObject *arguments PYFWSI_ATTRIBUTE_UNUSED )
{
	const char *errors           = NULL;
	const char *version_string   = NULL;
	size_t version_string_length = 0;

	PYFWSI_UNREFERENCED_PARAMETER( self )
	PYFWSI_UNREFERENCED_PARAMETER( arguments )

	Py_BEGIN_ALLOW_THREADS

	version_string = libfwsi_get_version();

	Py_END_ALLOW_THREADS

	version_string_length = narrow_string_length(
	                         version_string );

	/* Pass the string length to PyUnicode_DecodeUTF8
	 * otherwise it makes the end of string character is part
	 * of the string
	 */
	return( PyUnicode_DecodeUTF8(
	         version_string,
	         (Py_ssize_t) version_string_length,
	         errors ) );
}

#if PY_MAJOR_VERSION >= 3

/* The pyfwsi module definition
 */
PyModuleDef pyfwsi_module_definition = {
	PyModuleDef_HEAD_INIT,

	/* m_name */
	"pyfwsi",
	/* m_doc */
	"Python libfwsi module (pyfwsi).",
	/* m_size */
	-1,
	/* m_methods */
	pyfwsi_module_methods,
	/* m_reload */
	NULL,
	/* m_traverse */
	NULL,
	/* m_clear */
	NULL,
	/* m_free */
	NULL,
};

#endif /* PY_MAJOR_VERSION >= 3 */

/* Initializes the pyfwsi module
 */
#if PY_MAJOR_VERSION >= 3
PyMODINIT_FUNC PyInit_pyfwsi(
                void )
#else
PyMODINIT_FUNC initpyfwsi(
                void )
#endif
{
	PyObject *module           = NULL;
	PyGILState_STATE gil_state = 0;

#if defined( HAVE_DEBUG_OUTPUT )
	libfwsi_notify_set_stream(
	 stderr,
	 NULL );
	libfwsi_notify_set_verbose(
	 1 );
#endif

	/* Create the module
	 * This function must be called before grabbing the GIL
	 * otherwise the module will segfault on a version mismatch
	 */
#if PY_MAJOR_VERSION >= 3
	module = PyModule_Create(
	          &pyfwsi_module_definition );
#else
	module = Py_InitModule3(
	          "pyfwsi",
	          pyfwsi_module_methods,
	          "Python libfwsi module (pyfwsi)." );
#endif
	if( module == NULL )
	{
#if PY_MAJOR_VERSION >= 3
		return( NULL );
#else
		return;
#endif
	}
#if PY_VERSION_HEX < 0x03070000
	PyEval_InitThreads();
#endif
	gil_state = PyGILState_Ensure();

	/* Setup the item list type object
	 */
	pyfwsi_item_list_type_object.tp_new = PyType_GenericNew;

	if( PyType_Ready(
	     &pyfwsi_item_list_type_object ) < 0 )
	{
		goto on_error;
	}
	Py_IncRef(
	 (PyObject *) &pyfwsi_item_list_type_object );

	PyModule_AddObject(
	 module,
	 "item_list",
	 (PyObject *) &pyfwsi_item_list_type_object );

	/* Setup the item type object
	 */
	pyfwsi_item_type_object.tp_new = PyType_GenericNew;

	if( PyType_Ready(
	     &pyfwsi_item_type_object ) < 0 )
	{
		goto on_error;
	}
	Py_IncRef(
	 (PyObject *) &pyfwsi_item_type_object );

	PyModule_AddObject(
	 module,
	 "item",
	 (PyObject *) &pyfwsi_item_type_object );

	/* Setup the items type object
	 */
	pyfwsi_items_type_object.tp_new = PyType_GenericNew;

	if( PyType_Ready(
	     &pyfwsi_items_type_object ) < 0 )
	{
		goto on_error;
	}
	Py_IncRef(
	 (PyObject *) &pyfwsi_items_type_object );

	PyModule_AddObject(
	 module,
	 "items",
	 (PyObject *) &pyfwsi_items_type_object );

	/* Setup the root folder type object
	 */
	pyfwsi_root_folder_type_object.tp_new = PyType_GenericNew;

	if( PyType_Ready(
	     &pyfwsi_root_folder_type_object ) < 0 )
	{
		goto on_error;
	}
	Py_IncRef(
	 (PyObject *) &pyfwsi_root_folder_type_object );

	PyModule_AddObject(
	 module,
	 "root_folder",
	 (PyObject *) &pyfwsi_root_folder_type_object );

	/* Setup the volume type object
	 */
	pyfwsi_volume_type_object.tp_new = PyType_GenericNew;

	if( PyType_Ready(
	     &pyfwsi_volume_type_object ) < 0 )
	{
		goto on_error;
	}
	Py_IncRef(
	 (PyObject *) &pyfwsi_volume_type_object );

	PyModule_AddObject(
	 module,
	 "volume",
	 (PyObject *) &pyfwsi_volume_type_object );

	/* Setup the file entry type object
	 */
	pyfwsi_file_entry_type_object.tp_new = PyType_GenericNew;

	if( PyType_Ready(
	     &pyfwsi_file_entry_type_object ) < 0 )
	{
		goto on_error;
	}
	Py_IncRef(
	 (PyObject *) &pyfwsi_file_entry_type_object );

	PyModule_AddObject(
	 module,
	 "file_entry",
	 (PyObject *) &pyfwsi_file_entry_type_object );

	/* Setup the network location type object
	 */
	pyfwsi_network_location_type_object.tp_new = PyType_GenericNew;

	if( PyType_Ready(
	     &pyfwsi_network_location_type_object ) < 0 )
	{
		goto on_error;
	}
	Py_IncRef(
	 (PyObject *) &pyfwsi_network_location_type_object );

	PyModule_AddObject(
	 module,
	 "network_location",
	 (PyObject *) &pyfwsi_network_location_type_object );

	/* Setup the extension block type object
	 */
	pyfwsi_extension_block_type_object.tp_new = PyType_GenericNew;

	if( PyType_Ready(
	     &pyfwsi_extension_block_type_object ) < 0 )
	{
		goto on_error;
	}
	Py_IncRef(
	 (PyObject *) &pyfwsi_extension_block_type_object );

	PyModule_AddObject(
	 module,
	 "extension_block",
	 (PyObject *) &pyfwsi_extension_block_type_object );

	/* Setup the extension blocks type object
	 */
	pyfwsi_extension_blocks_type_object.tp_new = PyType_GenericNew;

	if( PyType_Ready(
	     &pyfwsi_extension_blocks_type_object ) < 0 )
	{
		goto on_error;
	}
	Py_IncRef(
	 (PyObject *) &pyfwsi_extension_blocks_type_object );

	PyModule_AddObject(
	 module,
	 "extension_blocks",
	 (PyObject *) &pyfwsi_extension_blocks_type_object );

	/* Setup the file entry extension type object
	 */
	pyfwsi_file_entry_extension_type_object.tp_new = PyType_GenericNew;

	if( PyType_Ready(
	     &pyfwsi_file_entry_extension_type_object ) < 0 )
	{
		goto on_error;
	}
	Py_IncRef(
	 (PyObject *) &pyfwsi_file_entry_extension_type_object );

	PyModule_AddObject(
	 module,
	 "file_entry_extension",
	 (PyObject *) &pyfwsi_file_entry_extension_type_object );

	PyGILState_Release(
	 gil_state );

#if PY_MAJOR_VERSION >= 3
	return( module );
#else
	return;
#endif

on_error:
	PyGILState_Release(
	 gil_state );

#if PY_MAJOR_VERSION >= 3
	return( NULL );
#else
	return;
#endif
}

