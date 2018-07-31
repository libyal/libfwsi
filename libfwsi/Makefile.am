AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCDATA_CPPFLAGS@ \
	@LIBCNOTIFY_CPPFLAGS@ \
	@LIBUNA_CPPFLAGS@ \
	@LIBFDATETIME_CPPFLAGS@ \
	@LIBFGUID_CPPFLAGS@ \
	@LIBFOLE_CPPFLAGS@ \
	@LIBFWPS_CPPFLAGS@ \
	@LIBFWSI_DLL_EXPORT@

lib_LTLIBRARIES = libfwsi.la

libfwsi_la_SOURCES = \
	libfwsi.c \
	libfwsi_cdburn_values.c libfwsi_cdburn_values.h \
	libfwsi_codepage.h \
	libfwsi_compressed_folder_values.c libfwsi_compressed_folder_values.h \
	libfwsi_control_panel_identifier.c libfwsi_control_panel_identifier.h \
	libfwsi_control_panel_values.c libfwsi_control_panel_values.h \
	libfwsi_control_panel_category_values.c libfwsi_control_panel_category_values.h \
	libfwsi_control_panel_cpl_file_values.c libfwsi_control_panel_cpl_file_values.h \
	libfwsi_debug.c libfwsi_debug.h \
	libfwsi_definitions.h \
	libfwsi_delegate_values.c libfwsi_delegate_values.h \
	libfwsi_error.c libfwsi_error.h \
	libfwsi_extern.h \
	libfwsi_extension_block.c libfwsi_extension_block.h \
	libfwsi_extension_block_0xbeef0000_values.c libfwsi_extension_block_0xbeef0000_values.h \
	libfwsi_extension_block_0xbeef0001_values.c libfwsi_extension_block_0xbeef0001_values.h \
	libfwsi_extension_block_0xbeef0003_values.c libfwsi_extension_block_0xbeef0003_values.h \
	libfwsi_extension_block_0xbeef0005_values.c libfwsi_extension_block_0xbeef0005_values.h \
	libfwsi_extension_block_0xbeef0006_values.c libfwsi_extension_block_0xbeef0006_values.h \
	libfwsi_extension_block_0xbeef000a_values.c libfwsi_extension_block_0xbeef000a_values.h \
	libfwsi_extension_block_0xbeef0013_values.c libfwsi_extension_block_0xbeef0013_values.h \
	libfwsi_extension_block_0xbeef0014_values.c libfwsi_extension_block_0xbeef0014_values.h \
	libfwsi_extension_block_0xbeef0019_values.c libfwsi_extension_block_0xbeef0019_values.h \
	libfwsi_extension_block_0xbeef0025_values.c libfwsi_extension_block_0xbeef0025_values.h \
	libfwsi_file_attributes.c libfwsi_file_attributes.h \
	libfwsi_file_entry.c libfwsi_file_entry.h \
	libfwsi_file_entry_extension.c libfwsi_file_entry_extension.h \
	libfwsi_file_entry_extension_values.c libfwsi_file_entry_extension_values.h \
	libfwsi_file_entry_values.c libfwsi_file_entry_values.h \
	libfwsi_game_folder_values.c libfwsi_game_folder_values.h \
	libfwsi_item.c libfwsi_item.h \
	libfwsi_item_list.c libfwsi_item_list.h \
	libfwsi_known_folder_identifier.c libfwsi_known_folder_identifier.h \
	libfwsi_libcdata.h \
	libfwsi_libcerror.h \
	libfwsi_libcnotify.h \
	libfwsi_libfdatetime.h \
	libfwsi_libfguid.h \
	libfwsi_libfole.h \
	libfwsi_libfwps.h \
	libfwsi_libuna.h \
	libfwsi_mtp_file_entry_values.c libfwsi_mtp_file_entry_values.h \
	libfwsi_mtp_volume_values.c libfwsi_mtp_volume_values.h \
	libfwsi_network_location.c libfwsi_network_location.h \
	libfwsi_network_location_values.c libfwsi_network_location_values.h \
	libfwsi_notify.c libfwsi_notify.h \
	libfwsi_root_folder.c libfwsi_root_folder.h \
	libfwsi_root_folder_values.c libfwsi_root_folder_values.h \
	libfwsi_shell_folder_identifier.c libfwsi_shell_folder_identifier.h \
	libfwsi_support.c libfwsi_support.h \
	libfwsi_types.h \
	libfwsi_unknown_0x74_values.c libfwsi_unknown_0x74_values.h \
	libfwsi_uri_values.c libfwsi_uri_values.h \
	libfwsi_uri_sub_values.c libfwsi_uri_sub_values.h \
	libfwsi_users_property_view_values.c libfwsi_users_property_view_values.h \
	libfwsi_unused.h \
	libfwsi_volume.c libfwsi_volume.h \
	libfwsi_volume_values.c libfwsi_volume_values.h

libfwsi_la_LIBADD = \
	@LIBCERROR_LIBADD@ \
	@LIBCDATA_LIBADD@ \
	@LIBCNOTIFY_LIBADD@ \
	@LIBUNA_LIBADD@ \
	@LIBFDATETIME_LIBADD@ \
	@LIBFGUID_LIBADD@ \
	@LIBFOLE_LIBADD@ \
	@LIBFWPS_LIBADD@

libfwsi_la_LDFLAGS = -no-undefined -version-info 1:0:0

EXTRA_DIST = \
	libfwsi_definitions.h.in \
	libfwsi.rc \
	libfwsi.rc.in

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f libfwsi_definitions.h
	/bin/rm -f libfwsi.rc
	/bin/rm -f Makefile

splint:
	@echo "Running splint on libfwsi ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(libfwsi_la_SOURCES)

