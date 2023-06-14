#!/bin/bash

if test $# -eq 0 ; then
    echo "At least 1 argument needs to be provided!"
    exit 1
fi

dir=$1

if ! test -d "${dir}" ; then
    echo "First argument needs to be a directory!"
    exit 1
fi

files=$(find "${dir}")

for file in ${files} ;
do
    if test -f "${file}" ; then
        permissions=$(ls -l "${file}" | grep -o "^.\{10\}")
        hasAllWritePermission=$(echo "${permissions}" | grep -c "^-.\{7\}w.$")
        if test ${hasAllWritePermission} -eq 1 ; then
            echo "Old permissions: ${permissions} ${file}"
            $(chmod a-w "${file}")
            permissions=$(ls -l "${file}" | grep -o "^.\{10\}")
            echo "New permissions: ${permissions} ${file}"
            $(chmod a+w "${file}") # just to be able to rerun the program again
        fi
    fi   
done
