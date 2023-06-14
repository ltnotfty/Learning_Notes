#!/bin/bash

PATH=/bin:/sbin:/usr/bin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

echo -e "You should input 2 numbers, I will multiplying them! \n"
read -p "first number: " firnum
read -p "second number: " secnum
total=$((${firnum}*${secnum}))
echo -e "\n The result of ${firnum} x ${secnum} = ${total}"

echo -n "192.2*2192.123="
echo "192.2*1231.233321238" | bc










