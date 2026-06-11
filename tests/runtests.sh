#!/bin/sh
# Script to run tests
#
# Version: 20260609

if test -f ${PWD}/libfwsi/.libs/libfwsi.1.dylib && test -f ./pyfwsi/.libs/pyfwsi.so
then
	install_name_tool -change /usr/local/lib/libfwsi.1.dylib ${PWD}/libfwsi/.libs/libfwsi.1.dylib ./pyfwsi/.libs/pyfwsi.so
fi

make check-build > /dev/null

make check $@
RESULT=$?

if test ${RESULT} -ne 0
then
	find . -name \*.log -path \*.dir/\*/\*.log -print -exec cat {} \;
fi
exit ${RESULT}

