#!/bin/bash

if test $# -eq 0 ; then
    echo "At least 1 argument needs provided!"
    exit 1
fi

dir=$1

if ! test -d "${dir}" ; then
    echo "First arguments needs to be a directory!"
    exit 1
fi

files=$(find -L "${dir}")

for file in ${files} ; 
do
    if ! test -e "${file}" ; then
        echo "${file} no longer exists!"
    fi
done
