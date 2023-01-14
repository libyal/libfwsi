/*
 * Codepage functions
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

#if !defined( _LIBFWSI_INTERNAL_CODEPAGE_H )
#define _LIBFWSI_INTERNAL_CODEPAGE_H

#include <common.h>
#include <types.h>

#if defined( __cplusplus )
extern "C" {
#endif

/* Define HAVE_LOCAL_LIBFWSI for local use of libfwsi
 * The definitions in <libfwsi/codepage.h> are copied here
 * for local use of libfwsi
 */
#if !defined( HAVE_LOCAL_LIBFWSI )

#include <libfwsi/codepage.h>

#else

/* The codepage definitions
 */
enum LIBFWSI_CODEPAGES
{
	LIBFWSI_CODEPAGE_ASCII		= 20127,

	LIBFWSI_CODEPAGE_ISO_8859_1	= 28591,
	LIBFWSI_CODEPAGE_ISO_8859_2	= 28592,
	LIBFWSI_CODEPAGE_ISO_8859_3	= 28593,
	LIBFWSI_CODEPAGE_ISO_8859_4	= 28594,
	LIBFWSI_CODEPAGE_ISO_8859_5	= 28595,
	LIBFWSI_CODEPAGE_ISO_8859_6	= 28596,
	LIBFWSI_CODEPAGE_ISO_8859_7	= 28597,
	LIBFWSI_CODEPAGE_ISO_8859_8	= 28598,
	LIBFWSI_CODEPAGE_ISO_8859_9	= 28599,
	LIBFWSI_CODEPAGE_ISO_8859_10	= 28600,
	LIBFWSI_CODEPAGE_ISO_8859_11	= 28601,
	LIBFWSI_CODEPAGE_ISO_8859_13	= 28603,
	LIBFWSI_CODEPAGE_ISO_8859_14	= 28604,
	LIBFWSI_CODEPAGE_ISO_8859_15	= 28605,
	LIBFWSI_CODEPAGE_ISO_8859_16	= 28606,

	LIBFWSI_CODEPAGE_KOI8_R		= 20866,
	LIBFWSI_CODEPAGE_KOI8_U		= 21866,

	LIBFWSI_CODEPAGE_WINDOWS_874	= 874,
	LIBFWSI_CODEPAGE_WINDOWS_932	= 932,
	LIBFWSI_CODEPAGE_WINDOWS_936	= 936,
	LIBFWSI_CODEPAGE_WINDOWS_949	= 949,
	LIBFWSI_CODEPAGE_WINDOWS_950	= 950,
	LIBFWSI_CODEPAGE_WINDOWS_1250	= 1250,
	LIBFWSI_CODEPAGE_WINDOWS_1251	= 1251,
	LIBFWSI_CODEPAGE_WINDOWS_1252	= 1252,
	LIBFWSI_CODEPAGE_WINDOWS_1253	= 1253,
	LIBFWSI_CODEPAGE_WINDOWS_1254	= 1254,
	LIBFWSI_CODEPAGE_WINDOWS_1255	= 1255,
	LIBFWSI_CODEPAGE_WINDOWS_1256	= 1256,
	LIBFWSI_CODEPAGE_WINDOWS_1257	= 1257,
	LIBFWSI_CODEPAGE_WINDOWS_1258	= 1258
};

#endif /* !defined( HAVE_LOCAL_LIBFWSI ) */

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFWSI_INTERNAL_CODEPAGE_H ) */

