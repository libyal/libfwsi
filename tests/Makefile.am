AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCSTRING_CPPFLAGS@ \
	@LIBCERROR_CPPFLAGS@ \
	@LIBFWSI_DLL_IMPORT@

if HAVE_PYTHON
TESTS_PYFWSI =
endif

TESTS = \
	$(TESTS_PYFWSI)

check_SCRIPTS = \
	test_runner.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

