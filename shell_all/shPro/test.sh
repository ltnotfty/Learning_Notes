#!/bin/bash

test_var_1="PATH is $PATH"
test_var_2='PATH is $PATH'

echo  $test_var_1
echo  $test_var_2


myname=linus\ tovald\\/
echo $myname

KER_VER=$(uname -r)
echo $KER_VER

unset myname
echo $myname



