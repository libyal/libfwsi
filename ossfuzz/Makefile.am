if HAVE_LIB_FUZZING_ENGINE
AM_CPPFLAGS = \
	-I../include -I$(top_srcdir)/include \
	-I../common -I$(top_srcdir)/common

bin_PROGRAMS = \
	extension_block_fuzzer \
	item_fuzzer \
	item_list_fuzzer

extension_block_fuzzer_SOURCES = \
	extension_block_fuzzer.cc \
	ossfuzz_libfwsi.h

extension_block_fuzzer_LDADD = \
	@LIB_FUZZING_ENGINE@ \
	../libfwsi/libfwsi.la

item_fuzzer_SOURCES = \
	item_fuzzer.cc \
	ossfuzz_libfwsi.h

item_fuzzer_LDADD = \
	@LIB_FUZZING_ENGINE@ \
	../libfwsi/libfwsi.la

item_list_fuzzer_SOURCES = \
	item_list_fuzzer.cc \
	ossfuzz_libfwsi.h

item_list_fuzzer_LDADD = \
	@LIB_FUZZING_ENGINE@ \
	../libfwsi/libfwsi.la
endif

DISTCLEANFILES = \
	Makefile \
	Makefile.in

splint-local:
	@echo "Running splint on extension_block_fuzzer ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(extension_block_fuzzer_SOURCES)
	@echo "Running splint on item_fuzzer ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(item_fuzzer_SOURCES)
	@echo "Running splint on item_list_fuzzer ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(item_list_fuzzer_SOURCES)
