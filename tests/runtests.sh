#!/bin/sh
# Script to run tests
#
# Version: 20260714

if [ -f "${PWD}/libfwsi/.libs/libfwsi.1.dylib" ] && [ -f ./pyfwsi/.libs/pyfwsi.so ]
then
    install_name_tool -change /usr/local/lib/libfwsi.1.dylib "${PWD}/libfwsi/.libs/libfwsi.1.dylib" ./pyfwsi/.libs/pyfwsi.so
fi

make check-build > /dev/null

# shellcheck disable=SC2068
make check $@
RESULT=$?

if [ ${RESULT} -ne 0 ]
then
    find . -name \*.log -path \*.dir/\*/\*.log -print -exec cat {} \;
fi
exit ${RESULT}

