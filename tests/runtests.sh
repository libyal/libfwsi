#!/bin/sh
# Script to run tests
#
# Version: 20201121

if test -f ${PWD}/libfwsi/.libs/libfwsi.1.dylib && test -f ./pyfwsi/.libs/pyfwsi.so;
then
	install_name_tool -change /usr/local/lib/libfwsi.1.dylib ${PWD}/libfwsi/.libs/libfwsi.1.dylib ./pyfwsi/.libs/pyfwsi.so;
fi

make check CHECK_WITH_STDERR=1;
RESULT=$?;

if test ${RESULT} -ne 0 && test -f tests/test-suite.log;
then
	cat tests/test-suite.log;
fi
exit ${RESULT};

