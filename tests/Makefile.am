AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCSTRING_CPPFLAGS@ \
	@LIBCERROR_CPPFLAGS@ \
        @LIBCLOCALE_CPPFLAGS@ \
        @LIBCNOTIFY_CPPFLAGS@ \
        @LIBUNA_CPPFLAGS@ \
        @LIBCFILE_CPPFLAGS@ \
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

check_PROGRAMS =  \
	fwsi_test_item_list_copy_from_byte_stream

fwsi_test_item_list_copy_from_byte_stream_SOURCES = \
	fwsi_test_libcfile.h \
	fwsi_test_libcerror.h \
	fwsi_test_libcstring.h \
	fwsi_test_libfwsi.h \
	fwsi_test_item_list_copy_from_byte_stream.c

fwsi_test_item_list_copy_from_byte_stream_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCFILE_LIBADD@ \
	@LIBUNA_LIBADD@ \
	@LIBCNOTIFY_LIBADD@ \
	@LIBCLOCALE_LIBADD@ \
	@LIBCERROR_LIBADD@ \
	@LIBCSTRING_LIBADD@

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

