#!/bin/bash


cnt=1

while [ -n "$1" ]
do
    echo "$cnt: $1"
    cnt=$[ $cnt + 1 ]
    shift 
done
