#!/bin/bash

echo

echo "using \$@ all : $@"

echo

echo "using \$* all : $*"


# process every item
for var in "$@" 
do
     echo $var
done



# process whole item
for var in "$*"
do
    echo $var
done



