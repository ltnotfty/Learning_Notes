#!/bin/bash
PATH=/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH


echo -e "This program will calculate pi value"
echo -e "You should input a float number to caculate pi value.\n"
read -p "The scale number (10-10000) ? " checking

num=${checking:-"10"}

echo -e "Starting calculate pi value. Be patient."

time echo "scale=${num}; 4*a(1)" | bc -lq