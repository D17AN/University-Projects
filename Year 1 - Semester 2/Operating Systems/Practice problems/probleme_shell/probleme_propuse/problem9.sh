#!/bin/bash

dir=$1
if test $# -eq 0 ; then
    echo "At least 1 argument needs provided!"
    exit 1
fi

dir="$1"

if ! test -d "${dir}" ; then
    echo "First argument needs to be a directory!"
    exit 1
fi
    
files=$(find dir -type f)

var=""

for file in ${files} ;
do
    res=$(md5sum "${file}")
    var="${var}${res}\n"    
done

codes="$(echo -e ${var} | awk '$0 != '\n' {print $0}' | cut -d ' ' -f 1 | sort | uniq -d)"

for code in ${codes} ; 
do
    output=$(echo -e ${var} | awk -F ' ' -v code="${code}" '
    BEGIN{
        print code
    }
    $1 == code{
        print $2
    }
    ')
    echo -e "${output}\n"
    
done

