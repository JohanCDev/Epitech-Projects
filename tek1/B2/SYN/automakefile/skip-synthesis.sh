#!/bin/bash
if [ $# != 1 ]
then
    echo "Bad number of arguments"
    exit 84;
else
    while read file_info_line
    do
        echo $file_info_line | \
        grep -v "^d" | \
        awk '{print $3,"\t",$9}' | \
        grep " $1"
    done
fi
exit 0