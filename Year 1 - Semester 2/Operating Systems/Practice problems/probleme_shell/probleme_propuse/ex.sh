#!/bin/bash

if test $# -eq 0 ; then
    echo "At least 1 argumnent needs to be provided!"
    exit 1
fi

dir=$1

if ! test -d ${dir} ; then
    echo "The first argument needs to be a directory!"
    exit 1
fi

files=$(find "${dir}" -type f)

details=""

for file in ${files} ; do
    details="${details}$(sha1sum "${file}")\n"
done

#remove the endline from the end
details=$(echo -e "${details}" | sed "s/\(^$\)//gi")
codes=$(echo -e "${details}" | cut -d ' ' -f 1 | sort | uniq -d)

for code in ${codes} ; do
    output=$(echo -e "${details}" | awk -F ' ' -v code="${code}" '
        BEGIN{
            print code ":"
        }
        $1 == code {
            print $2
        }
    ')
    echo -e  "${output}\n"
done


