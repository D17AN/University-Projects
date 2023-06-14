#!/bin/bash

if test $# -eq 0 ; then
    echo "At least 1 argument requiered!"
    exit 1
fi

dir=$1

if ! test -d "${dir}" ; then
    echo "The first argument must be a dir!"
    exit 1
fi

files=$(find "${dir}" -type f | grep "^.\+\.c$")
count=0
for file in ${files} ; do
    nrLines=$(cat "${file}" | wc -l)
    if test ${nrLines} -ge 500 ; then
        echo "${file}"
        count=$((${count} + 1))
    fi
    if test ${count} -eq 2 ; then
        break
    fi
done
echo "${count}"
