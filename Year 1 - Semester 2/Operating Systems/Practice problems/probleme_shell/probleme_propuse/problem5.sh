#!/bin/bash

dangerousPrograms=$@
./dummy.sh &

while true ;
do
    runningProcesses=$(ps | awk -F ' ' '{print $1, $4}')
    echo "Current running processes"
    echo "${runningProcesses}"
    while read p c ;
    do
        for danger in "${dangerousPrograms}" ; do
            if test "${danger}" == "${c}" ; then
                $(kill -9 "${p}")
                echo "Process with id ${p} having command ${c} was terminated."
            fi
        done
    done <<< "${runningProcesses}"
    sleep 3
done
