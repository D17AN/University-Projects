#!/bin/bash

for user in $(cat who.fake | awk -F ' ' '{print $1}') ;
do
    occurences=$(cat ps.fake | awk -F ' ' -v user="${user}" '
        BEGIN{
            occurences = 0
        }
        $1 == user {
            occurences++
        }
        END{
            print occurences
        }
    ')
    
    echo "${user} ${occurences}"
done
