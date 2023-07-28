#!/bin/bash

mv="mv"

if test $mv;then
	echo "not empty"
else
	echo "empty"
fi


v1=10
v2=5
v3=5

# gt greater than
# ge greter equal
# lt less than
# le less equal
# eq equal
# ne not equal

if [ $v1 -gt $v2 ];then
	echo "$v1 greater than $v2"
fi

if [ $v2 -ge $v3 ];then
	echo "$v2 greater or equal $v3"
fi



str1='hello'
str2='hello'
str3='world'
str4=''

# > <
# n z length equal 0
# = != 

if [ $str1 = $str2 ];then
    echo "st1 = str2"
fi


if [ $str1 \< $str3 ];then
	echo "str1 < str3"
fi

if [ -z $str4 ];then
	echo "zero str4"
fi


# test and sort process char not equal





# file test
# -d is dir
# -e is exists
# -f is exists and is a file
# -s is exists and is empty
# -w is exists and is write
# -r is exists and is read
# -x is exists and is execute
# -O is exists and is current user
# -G is exists and have the same group as current user
# -nt new than
# -ot old than 

if [ -f "bash_arr.sh" ] && [ -f "echo_today.sh" ] && [ "bash_arr.sh" -ot "echo_today.sh" ];
then
	echo "bash_arr.sh is older than echo_today.sh"
fi


if ( cat /etc/PAW );then
    echo "SUBSHELL excute success"
else
    echo "SUBSHELL excute failed"
fi


# double bracket
# val++
# val--
# ++val
# --val
# ** pow(a,n)
# <<
# >> 
# |
# &
# && 
# || 
# !
# ~

str="hello"

echo ${str[*]}



v1=30
v2=200

if (( $v1 ** 2 < $v2 ));then
    echo "v1 pow 2 less than v2"
elif (( $v1 ** 2 > $v2 ));then
    echo "v1 pow 2 greater than v2"
else
    echo "v1 pow 2 equal v2"
fi


(( v3 = $v2 ** 2 ))
echo $v3


if [[ $BASH_VERSION == 5.* ]];then
    echo "you are using bash version 5: $BASH_VERSION"
fi



m_str="m_f1"

case $m_str in
	m_f*)
		echo "in first pattern";;
	*)
	   echo "other pattern";;
esac

