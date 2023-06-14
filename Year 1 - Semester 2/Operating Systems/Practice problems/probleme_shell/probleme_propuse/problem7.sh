#!/bin/bash

fileContent=$(cat "usernames.txt" | sed "s/\(.\+\)/\1@scs.ubbcluj.ro/gi")

res=""
for user in ${fileContent} ;
do
    res="${res}${user},"
done

res=$(echo "${res}" | sed "s/\(.\+\),/\1/gi")
echo "${res}"
