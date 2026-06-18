AM_CPPFLAGS = \
	-I../include -I$(top_srcdir)/include \
	-I../common -I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCDATA_CPPFLAGS@ \
	@LIBCNOTIFY_CPPFLAGS@ \
	@LIBUNA_CPPFLAGS@ \
	@LIBFDATETIME_CPPFLAGS@ \
	@LIBFGUID_CPPFLAGS@ \
	@LIBFOLE_CPPFLAGS@ \
	@LIBFWPS_CPPFLAGS@ \
	@LIBFWSI_DLL_IMPORT@

BUILT_SOURCES = package.m4

check_AUTOTESTS = \
	test_library \
	test_manpages

if HAVE_PYTHON_TESTS
check_AUTOTESTS += test_python_module
endif

check_SCRIPTS = \
	pyfwsi_test_support.py

check_PROGRAMS = \
	fwsi_test_cdburn_values \
	fwsi_test_compressed_folder_values \
	fwsi_test_control_panel_category_values \
	fwsi_test_control_panel_cpl_file_values \
	fwsi_test_control_panel_item_values \
	fwsi_test_delegate_folder_values \
	fwsi_test_error \
	fwsi_test_extension_block \
	fwsi_test_extension_block_0xbeef0000_values \
	fwsi_test_extension_block_0xbeef0001_values \
	fwsi_test_extension_block_0xbeef0003_values \
	fwsi_test_extension_block_0xbeef0005_values \
	fwsi_test_extension_block_0xbeef0006_values \
	fwsi_test_extension_block_0xbeef000a_values \
	fwsi_test_extension_block_0xbeef0013_values \
	fwsi_test_extension_block_0xbeef0014_values \
	fwsi_test_extension_block_0xbeef0019_values \
	fwsi_test_extension_block_0xbeef0025_values \
	fwsi_test_file_entry_extension_values \
	fwsi_test_file_entry_values \
	fwsi_test_game_folder_values \
	fwsi_test_item \
	fwsi_test_item_list \
	fwsi_test_mtp_file_entry_values \
	fwsi_test_mtp_volume_values \
	fwsi_test_network_location_values \
	fwsi_test_notify \
	fwsi_test_root_folder_values \
	fwsi_test_support \
	fwsi_test_uri_values \
	fwsi_test_uri_sub_values \
	fwsi_test_users_property_view_values \
	fwsi_test_volume_values

fwsi_test_cdburn_values_SOURCES = \
	fwsi_test_cdburn_values.c \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h

fwsi_test_cdburn_values_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_compressed_folder_values_SOURCES = \
	fwsi_test_compressed_folder_values.c \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h

fwsi_test_compressed_folder_values_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_control_panel_category_values_SOURCES = \
	fwsi_test_control_panel_category_values.c \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h

fwsi_test_control_panel_category_values_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_control_panel_cpl_file_values_SOURCES = \
	fwsi_test_control_panel_cpl_file_values.c \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h

fwsi_test_control_panel_cpl_file_values_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_control_panel_item_values_SOURCES = \
	fwsi_test_control_panel_item_values.c \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h

fwsi_test_control_panel_item_values_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_delegate_folder_values_SOURCES = \
	fwsi_test_delegate_folder_values.c \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h

fwsi_test_delegate_folder_values_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_error_SOURCES = \
	fwsi_test_error.c \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_unused.h

fwsi_test_error_LDADD = \
	../libfwsi/libfwsi.la

fwsi_test_extension_block_SOURCES = \
	fwsi_test_extension_block.c \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h

fwsi_test_extension_block_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_extension_block_0xbeef0000_values_SOURCES = \
	fwsi_test_extension_block_0xbeef0000_values.c \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h

fwsi_test_extension_block_0xbeef0000_values_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_extension_block_0xbeef0001_values_SOURCES = \
	fwsi_test_extension_block_0xbeef0001_values.c \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h

fwsi_test_extension_block_0xbeef0001_values_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_extension_block_0xbeef0003_values_SOURCES = \
	fwsi_test_extension_block_0xbeef0003_values.c \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h

fwsi_test_extension_block_0xbeef0003_values_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_extension_block_0xbeef0005_values_SOURCES = \
	fwsi_test_extension_block_0xbeef0005_values.c \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h

fwsi_test_extension_block_0xbeef0005_values_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_extension_block_0xbeef0006_values_SOURCES = \
	fwsi_test_extension_block_0xbeef0006_values.c \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h

fwsi_test_extension_block_0xbeef0006_values_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_extension_block_0xbeef000a_values_SOURCES = \
	fwsi_test_extension_block_0xbeef000a_values.c \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h

fwsi_test_extension_block_0xbeef000a_values_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_extension_block_0xbeef0013_values_SOURCES = \
	fwsi_test_extension_block_0xbeef0013_values.c \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h

fwsi_test_extension_block_0xbeef0013_values_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_extension_block_0xbeef0014_values_SOURCES = \
	fwsi_test_extension_block_0xbeef0014_values.c \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h

fwsi_test_extension_block_0xbeef0014_values_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_extension_block_0xbeef0019_values_SOURCES = \
	fwsi_test_extension_block_0xbeef0019_values.c \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h

fwsi_test_extension_block_0xbeef0019_values_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_extension_block_0xbeef0025_values_SOURCES = \
	fwsi_test_extension_block_0xbeef0025_values.c \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h

fwsi_test_extension_block_0xbeef0025_values_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_file_entry_extension_values_SOURCES = \
	fwsi_test_file_entry_extension_values.c \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h

fwsi_test_file_entry_extension_values_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_file_entry_values_SOURCES = \
	fwsi_test_file_entry_values.c \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h

fwsi_test_file_entry_values_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_game_folder_values_SOURCES = \
	fwsi_test_game_folder_values.c \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h

fwsi_test_game_folder_values_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_item_SOURCES = \
	fwsi_test_item.c \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h

fwsi_test_item_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_item_list_SOURCES = \
	fwsi_test_item_list.c \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h

fwsi_test_item_list_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_mtp_file_entry_values_SOURCES = \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_mtp_file_entry_values.c \
	fwsi_test_unused.h

fwsi_test_mtp_file_entry_values_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_mtp_volume_values_SOURCES = \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_mtp_volume_values.c \
	fwsi_test_unused.h

fwsi_test_mtp_volume_values_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_network_location_values_SOURCES = \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_network_location_values.c \
	fwsi_test_unused.h

fwsi_test_network_location_values_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_notify_SOURCES = \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_notify.c \
	fwsi_test_unused.h

fwsi_test_notify_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_root_folder_values_SOURCES = \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_root_folder_values.c \
	fwsi_test_unused.h

fwsi_test_root_folder_values_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_support_SOURCES = \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_support.c \
	fwsi_test_unused.h

fwsi_test_support_LDADD = \
	../libfwsi/libfwsi.la

fwsi_test_uri_values_SOURCES = \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h \
	fwsi_test_uri_values.c

fwsi_test_uri_values_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_uri_sub_values_SOURCES = \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h \
	fwsi_test_uri_sub_values.c

fwsi_test_uri_sub_values_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_users_property_view_values_SOURCES = \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h \
	fwsi_test_users_property_view_values.c

fwsi_test_users_property_view_values_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

fwsi_test_volume_values_SOURCES = \
	fwsi_test_libcerror.h \
	fwsi_test_libfwsi.h \
	fwsi_test_macros.h \
	fwsi_test_memory.c fwsi_test_memory.h \
	fwsi_test_unused.h \
	fwsi_test_volume_values.c

fwsi_test_volume_values_LDADD = \
	../libfwsi/libfwsi.la \
	@LIBCERROR_LIBADD@

AUTOM4TE = autom4te
AUTOTEST = $(AUTOM4TE) --language=autotest

SUFFIXES = .at

.at:
	$(AM_V_GEN)rm -f $@ $@.tmp; \
	$(AUTOTEST) -I '$(srcdir)' -o $@.tmp $< && \
	mv $@.tmp $@

atconfig: $(top_builddir)/config.status
	cd $(top_builddir) && $(SHELL) ./config.status tests/$@

check-build: $(check_PROGRAMS)

check-local: $(check_AUTOTESTS)
	@fail=0; \
	for test_suite in $(check_AUTOTESTS); do \
		$(AM_TESTS_ENVIRONMENT) $(SHELL) "./$$test_suite" $(TESTSUITEFLAGS) || fail=1; \
		echo ""; \
	done; \
	exit $$fail

clean-local:
	for test_suite in $(check_AUTOTESTS); do \
		test ! -f "$$test_suite" || $(SHELL) "./$$test_suite" --clean; \
	done

package.m4: $(top_srcdir)/configure.ac
	$(AM_V_GEN):; \
	{ \
	  echo 'm4_define([AT_PACKAGE_NAME], [$(PACKAGE_NAME)])' ; \
	  echo 'm4_define([AT_PACKAGE_TARNAME], [$(PACKAGE_TARNAME)])' ; \
	  echo 'm4_define([AT_PACKAGE_VERSION], [$(PACKAGE_VERSION)])' ; \
	  echo 'm4_define([AT_PACKAGE_STRING], [$(PACKAGE_STRING)])' ; \
	  echo 'm4_define([AT_PACKAGE_BUGREPORT], [$(PACKAGE_BUGREPORT)])' ; \
	} > $@

test_library: package.m4 test_library.at test_macros.at

test_manpages: package.m4 test_manpages.at

test_python_module: package.m4 test_python_module.at

EXTRA_DIST = \
	$(check_AUTOTESTS:=.at) \
	$(check_SCRIPTS) \
	package.m4 \
	test_macros.at

CLEANFILES = \
	$(check_AUTOTESTS) \
	*.exe \
	*.tmp \
	notify_stream.log \
	test_inputs_*.at

DISTCLEANFILES = \
	*.log \
	atconfig \
	Makefile \
	Makefile.in

