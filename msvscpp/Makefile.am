MSVSCPP_FILES = \
	libcdata/libcdata.vcproj \
	libcerror/libcerror.vcproj \
	libcfile/libcfile.vcproj \
	libclocale/libclocale.vcproj \
	libcnotify/libcnotify.vcproj \
	libcstring/libcstring.vcproj \
	libcthreads/libcthreads.vcproj \
	libfdatetime/libfdatetime.vcproj \
	libfguid/libfguid.vcproj \
	libfole/libfole.vcproj \
	libfwps/libfwps.vcproj \
	libfwsi/libfwsi.vcproj \
	libuna/libuna.vcproj \
	pyfwsi/pyfwsi.vcproj \
	libfwsi.sln

SCRIPT_FILES = \
	scripts/vs2008_x64.sh \
	scripts/vs2008_x64_sln.sed \
	scripts/vs2008_x64_vcproj.sed \
	scripts/vs2010_x64.sh \
	scripts/vs2010_x64_sln.sed \
	scripts/vs2010_x64_vcxproj.sed

EXTRA_DIST = \
	$(MSVSCPP_FILES) \
	$(SCRIPT_FILES)

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

