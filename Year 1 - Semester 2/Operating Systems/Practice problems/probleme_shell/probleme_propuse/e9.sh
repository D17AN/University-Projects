#!/bin/bash

if test $# -eq 0 ; then
    echo "At least 1 argument needs provided!"
    exit 1
fi

dir=$1

if ! test -d "${dir}" ; then
    echo "The first argument needs to be a directory"
    exit 1
fi

files=$(find "${dir}" -type f)
info=""
for file in ${files} ; do
    info="${info}\n$(sha1sum "${file}")"
done
info=$(echo -e "${info}" | grep -v "^$")

codes=$(echo -e "${info}" | awk -F ' ' '
    {
        print $1
    }
    ' | sort | uniq -d)

output=""
for code in ${codes} ; do
    dups=$(echo -e "${info}" | awk -F ' ' -v code="${code}" '
    BEGIN{
        print code ":"
    }
    $1 == code{
        print $2
    }
    ')
    output="${output}\n$(echo -e "${dups}")"
done
echo -e "${output}"
