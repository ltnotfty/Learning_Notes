#!/bin/bash


totol_num=2000
num_per_folder=100


totol_num=$[ $totol_num + num_per_folder - 1 ]
totol_folder_num=$[ totol_num / $num_per_folder ]




for file in ./lc*.cpp
do
    IFS_OLD=$IFS
    IFS=$'c.'
    
    num=0
    cnt=0;
    for i in $file 
	  do
                cnt=$[ $cnt + 1 ]
	        if [ $cnt = 3 ];then
		    num=$i
		fi	
	  done
	  IFS=$IFS_OLD
     ed_num=$[ ( $num + 99)/100 * 100 ]
     bg_num=$[ $ed_num - 99 ]


    folder_name="lc""$bg_num""-""$ed_num"
    echo "$file in folder $folder_name"
    if [ -d "$folder_name" ] ; then
        mv $file $folder_name
    else 
        mkdir "$folder_name"
	mv $file $folder_name
    fi
      

done

