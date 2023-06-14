#!/bin/bash


if test $# -eq 0 ; then
    echo "At least 1 argument needs to be provided!"
    exit 1
fi

dir="$1"

if ! test -d "${dir}" ; then
    echo "The first argument must to be a directory!"
    exit 1
fi

files=$(find "${dir}")

for file in ${files} ;
do
    if test -f "${file}" ; then
        isLog=$(echo "${file}" | grep -c ".\+\.log")
        if test ${isLog} -eq 1 ; then
            echo "${file}"
            $(cat "${file}" | sort -o "${file}")
        fi
    fi
done

