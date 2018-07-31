if HAVE_PYTHON
AM_CFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCDATA_CPPFLAGS@ \
	@LIBCLOCALE_CPPFLAGS@ \
	@LIBUNA_CPPFLAGS@ \
	@LIBFGUID_CPPFLAGS@ \
	@LIBFWSI_DLL_IMPORT@

pyexec_LTLIBRARIES = pyfwsi.la

pyfwsi_la_SOURCES = \
	pyfwsi.c pyfwsi.h \
	pyfwsi_codepage.c pyfwsi_codepage.h \
	pyfwsi_datetime.c pyfwsi_datetime.h \
	pyfwsi_error.c pyfwsi_error.h \
	pyfwsi_extension_block.c pyfwsi_extension_block.h \
	pyfwsi_extension_blocks.c pyfwsi_extension_blocks.h \
	pyfwsi_file_entry.c pyfwsi_file_entry.h \
	pyfwsi_file_entry_extension.c pyfwsi_file_entry_extension.h \
	pyfwsi_guid.c pyfwsi_guid.h \
	pyfwsi_integer.c pyfwsi_integer.h \
	pyfwsi_item.c pyfwsi_item.h \
	pyfwsi_item_list.c pyfwsi_item_list.h \
	pyfwsi_items.c pyfwsi_items.h \
	pyfwsi_libcerror.h \
	pyfwsi_libclocale.h \
	pyfwsi_libfguid.h \
	pyfwsi_libfwsi.h \
	pyfwsi_network_location.c pyfwsi_network_location.h \
	pyfwsi_python.h \
	pyfwsi_root_folder.c pyfwsi_root_folder.h \
	pyfwsi_unused.h \
	pyfwsi_volume.c pyfwsi_volume.h

pyfwsi_la_LIBADD = \
	@LIBCERROR_LIBADD@ \
	../libfwsi/libfwsi.la \
	@LIBCDATA_LIBADD@ \
	@LIBCLOCALE_LIBADD@ \
	@LIBUNA_LIBADD@ \
	@LIBFGUID_LIBADD@

pyfwsi_la_CPPFLAGS = $(PYTHON_CPPFLAGS)
pyfwsi_la_LDFLAGS  = -module -avoid-version $(PYTHON_LDFLAGS)

endif

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

