#!/bin/bash

split_str="######"

#stdout to list
find /home -name .bashrc > ~/list

echo $split_str

#stdout to list, error info to ~/list_err

find /home -name .bashrc > ~/list 2>~/list_err

echo $split_str
#stdout and errinfo to list

find /home -name .bashrc > ~/list 2>&1

echo $split_str
#stdout to list, discard error info

find /home -name .bashrc > ~/list 2>/dev/null

echo $split_str
#create a file
cat > ~/catfile

echo $split_str
#create a file from a specify file
cat > ~/catfile < ~/.bashrc

echo $split_str


