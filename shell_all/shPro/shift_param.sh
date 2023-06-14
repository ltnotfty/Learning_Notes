#!/bin/bash
PATH=/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH


echo "The script name is ==> ${0}"
echo "Total parameter number is $#"
[ "$#" -lt "2" ] && echo "The number of parameter is less than 2. stop here" && exit 0

shift 2
echo "Your parameter is ==> '$@'"


echo "The 1st parameter ==> ${1}"
echo "The 2nd parameter ==> ${2}"



