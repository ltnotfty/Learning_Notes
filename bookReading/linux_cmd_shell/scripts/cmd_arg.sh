#!/bin/bash


fac=1;

if (( $# < 1 ));then
    echo "arg numbers $# not eq 2"
    exit 2
fi


for (( i = 1; i <= $1; i++))
do
	(( fac = $fac * $i ))
done

echo $fac





for (( i = 1; i <= $#; i++)) 
do
    echo ${i}
done

echo "$10 is ${10}"


