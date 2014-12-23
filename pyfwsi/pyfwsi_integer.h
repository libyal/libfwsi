/*
 * Integer functions
 *
 * Copyright (c) 2010-2014, Joachim Metz <joachim.metz@gmail.com>
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

#if !defined( _PYFWSI_INTEGER_H )
#define _PYFWSI_INTEGER_H

#include <common.h>
#include <types.h>

#include "pyfwsi_libcerror.h"
#include "pyfwsi_python.h"

#if defined( __cplusplus )
extern "C" {
#endif

PyObject *pyfwsi_integer_signed_new_from_64bit(
           int64_t value_64bit );

PyObject *pyfwsi_integer_unsigned_new_from_64bit(
           uint64_t value_64bit );

int pyfwsi_integer_signed_copy_to_64bit(
     PyObject *integer_object,
     int64_t *value_64bit,
     libcerror_error_t **error );

int pyfwsi_integer_unsigned_copy_to_64bit(
     PyObject *integer_object,
     uint64_t *value_64bit,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif

