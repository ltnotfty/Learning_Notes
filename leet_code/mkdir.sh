#!/bin/bash


totol_num=2000
num_per_folder=100


totol_num=$[ $totol_num + num_per_folder - 1 ]
totol_folder_num=$[ totol_num / $num_per_folder ]



for i in `seq 1 $totol_folder_num`
do
    bg_num=$[ $i - 1 ]
    bg_num=$[ $bg_num * 100 + 1]

    ed_num=$[ $bg_num + 99 ]
   
    dir_name="lc""$bg_num""-""$ed_num"
    
   [ -d "$dir_name" ] || mkdir $dir_name 
          	

done


