#!/bin/bash


for var in  one two three four
do
    echo $var
done



# with ' char arr


for var in i don\'t know this\'ll work
do
 	echo $var       
done




# with blackspace 


for var in "new york" "new iland"
do
	echo $var
done



# read from variables

list="air apple orange juice"
s_list=$list" hit"


for var in $s_list
do
	echo $var
done



# read from file
OLD_IFS=$IFS

IFS=$'\n'

state_txt=$(cat state.txt)


for var in $state_txt
do
    echo $var
done

IFS=$OLD_IFS



# tranverse HOME dir

if [ -d $HOME ];then
for file in $HOME/*
do
	if [ -f "$file" ];then
		echo "$file is a file"
	elif [ -d "$file" ];then
		echo "$file is a directory"
	else
		echo "$file is no file and direcotry"
	fi
done

fi



# for c like loop
echo "using c like loop in bash"
for (( i = 1, j = 10; i < 10; i++,j--))
do
    echo "$i-$j"
done




echo "using while loop in bash"
# while loop
val1=10
while [ $val1 -gt 0 ]
do
	echo $val1
	(( val1-- ))
done




echo "using until loop in bash"

until   echo $val1
	[ $val1 -eq 10 ]
do
    echo $val1
    (( val1++))
done



echo "using continue 2"
for i in `seq 1 10`
do
    echo "in seq $i"
    for j in `seq 2 10`
    do
        if [ $i -gt 3 ] && [ $i -lt 6 ];then
		continue 2
	fi
	echo "$i-$j"
    done
done


echo "using break 2"

for i in `seq 1 10`
do
	for j in `seq 1 10`
	do
		
		if (( $j > $i ));then
			break 2 
		fi
		echo "$i-$j"
	done
done




echo "loop output redirect"

for i in `seq 1 10`
do
	echo "cur val $i"
done >> echo.txt


echo "loop output redirect to pipeline"


for i in `seq 2 4`
do 
	echo "$i"
done | sort 

