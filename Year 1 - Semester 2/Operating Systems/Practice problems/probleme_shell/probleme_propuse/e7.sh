#!/bin/bash

if test $# -eq 0 ; then
    echo "At least 1 argument needs providing!"
    exit 1
fi

file="$1"

if ! test -f ${file} ; then
    echo "The first argument needs to be a file!"
    exit 1
fi

for line in $(cat "${file}") ; do
    while read arg ; do
        echo "${arg}"
    done <<< ${line}
done
