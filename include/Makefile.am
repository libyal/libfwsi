include_HEADERS = \
	libfwsi.h

pkginclude_HEADERS = \
	libfwsi/codepage.h \
	libfwsi/definitions.h \
	libfwsi/error.h \
	libfwsi/extern.h \
	libfwsi/features.h \
	libfwsi/types.h

EXTRA_DIST = \
	libfwsi.h.in \
	libfwsi/definitions.h.in \
	libfwsi/features.h.in \
	libfwsi/types.h.in

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f libfwsi.h
	/bin/rm -f libfwsi/definitions.h
	/bin/rm -f libfwsi/features.h
	/bin/rm -f libfwsi/types.h
	/bin/rm -f Makefile

