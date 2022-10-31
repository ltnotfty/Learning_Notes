#!/bin/bash

declare -x sum
export | grep sum

declare -i a=10
echo $a

declare -r a

declare +r a
# readonly attr can't cancel !!!
a=100

declare +x sum
export | grep sum

echo $a


