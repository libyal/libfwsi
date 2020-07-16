dnl Checks for required headers and functions
dnl
dnl Version: 20190308

dnl Function to detect if libfwsi dependencies are available
AC_DEFUN([AX_LIBFWSI_CHECK_LOCAL],
  [dnl No additional checks.
  ])

dnl Function to check if DLL support is needed
AC_DEFUN([AX_LIBFWSI_CHECK_DLL_SUPPORT],
  [AS_IF(
    [test "x$enable_shared" = xyes],
    [AS_CASE(
      [$host],
      [*cygwin* | *mingw* | *msys*],
      [AC_DEFINE(
        [HAVE_DLLMAIN],
        [1],
        [Define to 1 to enable the DllMain function.])
      AC_SUBST(
        [HAVE_DLLMAIN],
        [1])

      AC_SUBST(
        [LIBFWSI_DLL_EXPORT],
        ["-DLIBFWSI_DLL_EXPORT"])

      AC_SUBST(
        [LIBFWSI_DLL_IMPORT],
        ["-DLIBFWSI_DLL_IMPORT"])
      ])
    ])
  ])

