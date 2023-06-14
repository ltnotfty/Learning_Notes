#!/bin/bash
PATH=/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH


#let user input filename


echo -e "Please input a filename, I will check the filename's type and permission. \n\n"
read -p "Input a filename: " filename

test -z ${filename} && echo "You Must input a filename" && exit 0

#judge file existence

test ! -e ${filename} && echo "The filename '${filename}' DO NOT exist!" && exit 0


#switch the file type and attribute


test -f ${filename} && filetype="regular file"
test -d ${filename} && filetype="directory"
test -r ${filename} && perm="readable"
test -w ${filename} && perm="${perm} writeable"
test -x ${filename} && perm="${perm} executable"


#echo info
echo "The filename: ${filename} is a ${filetype}"
echo "And the permission for you are : ${perm}"


