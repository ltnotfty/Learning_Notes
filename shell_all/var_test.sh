#!/bin/bash


username=""
username=${username:-root}

echo $username

userage=""
userage=${userage:+as}

echo $userage

totalnum=""
usernum=10
usernum=${totalnum:=30}

echo $usernum


pagenum=
desknum=${pagenum?30}
echo $desknum


unset str; var=${str-root} && echo $var;
unset str; var=${str-root} && echo "var=${var}, str=${str}";
str=100; var=${str-root} && echo "var=${var}, str=${str}";
oldvar=100; var=${oldvar-newval} && echo "var=${var}, oldvar=${oldvar}";
oldvar=; var=${oldvar-newval} && echo "var=${var}, oldvar=${oldvar}";
unset oldvar; var=${oldvar-newval} && echo "var=${var}, oldvar=${oldvar}";
unset str;var=${str=pwd} && echo $var $str;
str="";var=${str=pwd} && echo $var $str;
str="";var=${str:="pwd"} && echo $var $str;
str="s";var=${str?"pwd"} && echo $var $str;
str="";var=${str:?"pwd"} && echo $var $str;
