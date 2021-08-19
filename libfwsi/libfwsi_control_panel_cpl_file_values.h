/*
 * Control panel CPL file (shell item) values functions
 *
 * Copyright (C) 2010-2021, Joachim Metz <joachim.metz@gmail.com>
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

#if !defined( _LIBFWSI_CONTROL_PANEL_CPL_FILE_VALUES_H )
#define _LIBFWSI_CONTROL_PANEL_CPL_FILE_VALUES_H

#include <common.h>
#include <types.h>

#include "libfwsi_libcerror.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libfwsi_control_panel_cpl_file_values libfwsi_control_panel_cpl_file_values_t;

//original data struct define 
#pragma pack(push, 1)
struct libfwsi_control_panel_cpl_file_values_original
{
    /*offset 0*/
    uint16_t size;

    /*offset 2*/
    /*must be zero*/
    uint8_t class_type;
    
    /*offset 3*/
    /*seen as zero*/
    uint8_t unknown1;

    /*seen as follow
	*0x00000000
	*0xffffee79
	*0xfffff444
	*0xffffff36
	*0xffffff37
	*0xffffff38
	*0xffffff9a
	*0xffffff9c
	*0xffffffff
    */
    /*offset 4*/
    uint32_t signature;

    /*seen as zero*/
    /*offset 8*/
    uint32_t unknown2;

    /*0x00006a00*/
    /*offset 12*/
    uint32_t signature2;

    /*seen as zero*/
    /*offset 16*/
    uint32_t unknown3;

    /*offset 20*/
    uint16_t name_offset;
    /*offset 22*/
    uint16_t comments_offset;
    
    /*
    * bytes size = size - 0x18
    * .cpl file path
    * name string
    * comments string
    */
    /*offset 24*/
    uint16_t string[0];
};
#pragma pack(pop) 

struct libfwsi_control_panel_cpl_file_values
{

    uint16_t size;
    /*class_type must be zero*/
    uint8_t class_type;
    /*signature seen as 
    *0x00000000
    *0xffffee79
    *0xfffff444
    *0xffffff36
    *0xffffff37
    *0xffffff38
    *0xffffff9a
    *0xffffff9c
    *0xffffffff
    */
    uint32_t signature;
    uint32_t signature2; //seen as 0x00006a00

    uint16_t* string_buffer;
    uint16_t* cpl_path;
    uint16_t* name;
    uint16_t* comments;
};

int libfwsi_control_panel_cpl_file_values_initialize(
     libfwsi_control_panel_cpl_file_values_t **control_panel_cpl_file_values,
     libcerror_error_t **error );

int libfwsi_control_panel_cpl_file_values_free(
     libfwsi_control_panel_cpl_file_values_t **control_panel_cpl_file_values,
     libcerror_error_t **error );

int libfwsi_control_panel_cpl_file_values_read_data(
     libfwsi_control_panel_cpl_file_values_t *control_panel_cpl_file_values,
     const uint8_t *data,
     size_t data_size,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFWSI_CONTROL_PANEL_CPL_FILE_VALUES_H ) */

