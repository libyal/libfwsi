dnl Checks for libfwps required headers and functions
dnl
dnl Version: 20240526

dnl Function to detect if libfwps is available
dnl ac_libfwps_dummy is used to prevent AC_CHECK_LIB adding unnecessary -l<library> arguments
AC_DEFUN([AX_LIBFWPS_CHECK_LIB],
  [AS_IF(
    [test "x$ac_cv_enable_shared_libs" = xno || test "x$ac_cv_with_libfwps" = xno],
    [ac_cv_libfwps=no],
    [ac_cv_libfwps=check
    dnl Check if the directory provided as parameter exists
    dnl For both --with-libfwps which returns "yes" and --with-libfwps= which returns ""
    dnl treat them as auto-detection.
    AS_IF(
      [test "x$ac_cv_with_libfwps" != x && test "x$ac_cv_with_libfwps" != xauto-detect && test "x$ac_cv_with_libfwps" != xyes],
      [AX_CHECK_LIB_DIRECTORY_EXISTS([libfwps])],
      [dnl Check for a pkg-config file
      AS_IF(
        [test "x$cross_compiling" != "xyes" && test "x$PKGCONFIG" != "x"],
        [PKG_CHECK_MODULES(
          [libfwps],
          [libfwps >= 20240224],
          [ac_cv_libfwps=yes],
          [ac_cv_libfwps=check])
        ])
      AS_IF(
        [test "x$ac_cv_libfwps" = xyes],
        [ac_cv_libfwps_CPPFLAGS="$pkg_cv_libfwps_CFLAGS"
        ac_cv_libfwps_LIBADD="$pkg_cv_libfwps_LIBS"])
      ])

    AS_IF(
      [test "x$ac_cv_libfwps" = xcheck],
      [dnl Check for headers
      AC_CHECK_HEADERS([libfwps.h])

      AS_IF(
        [test "x$ac_cv_header_libfwps_h" = xno],
        [ac_cv_libfwps=no],
        [ac_cv_libfwps=yes

        AX_CHECK_LIB_FUNCTIONS(
          [libfwps],
          [fwps],
          [[libfwps_get_version],
           [libfwps_store_initialize],
           [libfwps_store_free],
           [libfwps_store_copy_from_byte_stream],
           [libfwps_store_get_number_of_sets],
           [libfwps_store_get_set_by_index],
           [libfwps_set_initialize],
           [libfwps_set_free],
           [libfwps_set_copy_from_byte_stream],
           [libfwps_record_free],
           [libfwps_record_get_utf8_entry_name_size],
           [libfwps_record_get_utf8_entry_name],
           [libfwps_record_get_utf16_entry_name_size],
           [libfwps_record_get_utf16_entry_name],
           [libfwps_record_get_entry_type],
           [libfwps_record_get_utf8_value_name_size],
           [libfwps_record_get_utf8_value_name],
           [libfwps_record_get_utf16_value_name_size],
           [libfwps_record_get_utf16_value_name],
           [libfwps_record_get_value_type],
           [libfwps_record_get_data],
           [libfwps_record_get_data_size],
           [libfwps_record_get_data_as_boolean],
           [libfwps_record_get_data_as_8bit_integer],
           [libfwps_record_get_data_as_16bit_integer],
           [libfwps_record_get_data_as_32bit_integer],
           [libfwps_record_get_data_as_64bit_integer],
           [libfwps_record_get_data_as_filetime],
           [libfwps_record_get_data_as_floating_point],
           [libfwps_record_get_data_as_utf8_string_size],
           [libfwps_record_get_data_as_utf8_string],
           [libfwps_record_get_data_as_utf16_string_size],
           [libfwps_record_get_data_as_utf16_string],
           [libfwps_record_get_data_as_utf8_path_string_size],
           [libfwps_record_get_data_as_utf8_path_string],
           [libfwps_record_get_data_as_utf16_path_string_size],
           [libfwps_record_get_data_as_utf16_path_string],
           [libfwps_record_get_data_as_guid]])

        ac_cv_libfwps_LIBADD="-lfwps"])
      ])

    AX_CHECK_LIB_DIRECTORY_MSG_ON_FAILURE([libfwps])
    ])

  dnl Check for debug functions
  AS_IF(
    [test "x$ac_cv_libfwps" = xyes && test "x$ac_cv_enable_debug_output" != xno],
    [AC_CHECK_LIB(
      fwps,
      libfwps_property_identifier_get_description,
      [ac_cv_libfwps_dummy=yes],
      [ac_cv_libfwps=no])

    AC_CHECK_LIB(
      fwps,
      libfwps_property_identifier_get_identifier,
      [ac_cv_libfwps_dummy=yes],
      [ac_cv_libfwps=no])
    ])

  AS_IF(
    [test "x$ac_cv_libfwps" = xyes],
    [AC_DEFINE(
      [HAVE_LIBFWPS],
      [1],
      [Define to 1 if you have the `fwps' library (-lfwps).])
    ])

  AS_IF(
    [test "x$ac_cv_libfwps" = xyes],
    [AC_SUBST(
      [HAVE_LIBFWPS],
      [1]) ],
    [AC_SUBST(
      [HAVE_LIBFWPS],
      [0])
    ])
  ])

dnl Function to detect if libfwps dependencies are available
AC_DEFUN([AX_LIBFWPS_CHECK_LOCAL],
  [dnl No additional checks.

  ac_cv_libfwps_CPPFLAGS="-I../libfwps -I\$(top_srcdir)/libfwps";
  ac_cv_libfwps_LIBADD="../libfwps/libfwps.la";

  ac_cv_libfwps=local
  ])

dnl Function to detect how to enable libfwps
AC_DEFUN([AX_LIBFWPS_CHECK_ENABLE],
  [AX_COMMON_ARG_WITH(
    [libfwps],
    [libfwps],
    [search for libfwps in includedir and libdir or in the specified DIR, or no if to use local version],
    [auto-detect],
    [DIR])

  dnl Check for a shared library version
  AX_LIBFWPS_CHECK_LIB

  dnl Check if the dependencies for the local library version
  AS_IF(
    [test "x$ac_cv_libfwps" != xyes],
    [AX_LIBFWPS_CHECK_LOCAL

    AC_DEFINE(
      [HAVE_LOCAL_LIBFWPS],
      [1],
      [Define to 1 if the local version of libfwps is used.])
    AC_SUBST(
      [HAVE_LOCAL_LIBFWPS],
      [1])
    ])

  AM_CONDITIONAL(
    [HAVE_LOCAL_LIBFWPS],
    [test "x$ac_cv_libfwps" = xlocal])
  AS_IF(
    [test "x$ac_cv_libfwps_CPPFLAGS" != "x"],
    [AC_SUBST(
      [LIBFWPS_CPPFLAGS],
      [$ac_cv_libfwps_CPPFLAGS])
    ])
  AS_IF(
    [test "x$ac_cv_libfwps_LIBADD" != "x"],
    [AC_SUBST(
      [LIBFWPS_LIBADD],
      [$ac_cv_libfwps_LIBADD])
    ])

  AS_IF(
    [test "x$ac_cv_libfwps" = xyes],
    [AC_SUBST(
      [ax_libfwps_pc_libs_private],
      [-lfwps])
    ])

  AS_IF(
    [test "x$ac_cv_libfwps" = xyes],
    [AC_SUBST(
      [ax_libfwps_spec_requires],
      [libfwps])
    AC_SUBST(
      [ax_libfwps_spec_build_requires],
      [libfwps-devel])
    ])
  ])

