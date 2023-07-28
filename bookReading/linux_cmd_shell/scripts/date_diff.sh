#!/bin/bash


date1="Jan 1, 2022"
date2="Jan 2, 2023"



val1=$(date -d "$date1" +%s)

val2=$(date -d "$date2" +%s)

diff=$[$val2 - $val1]


days=$[$diff/24/3600]
hours=$[$diff - days * 24 * 3600]
seconds=$[$hours%3600]
hours=$[$hours/3600]


echo $days
echo $hours
echo $seconds

    
