#!/bin/bash

dir="$1"
if test $# -eq 0 ; then
    echo "No directory passed, you need to provide at least argument"
    exit 1
fi

if ! test -d "${dir}" ; then
    echo "First argument must be a directory"
fi

for el in $(find "${dir}") ;
do
    if test -f "${el}" ; then
        isCextension=$(echo "${el}" | grep -c ".\+\.c")
        if test ${isCextension} -eq 1 ; then
            echo "${el}"
        fi
    fi
done
