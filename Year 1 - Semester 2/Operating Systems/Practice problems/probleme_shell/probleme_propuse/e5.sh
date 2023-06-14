#!/bin/bash

if test $# -eq 0 ; then
    echo "At least 1 argument requiered!"
    exit 1
fi

dir="$1"

if ! test -d ${dir} ; then
    echo "The first argument needs to be a directory"
    exit 1
fi

files=$(find "${dir}" -type f)

for file in ${files} ; do
    hasAllWritePermission=$(ls -l "${file}" | grep -c "^.\{8\}w.\ ")
    if test ${hasAllWritePermission} -eq 1 ; then
        echo $(ls -l "${file}")
        $(chmod a-w "${file}")
        echo $(ls -l "${file}")
        $(chmod a+w "${file}")
    fi
done
