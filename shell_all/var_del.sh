#!/bin/bash

echo "original $ PATH is"
echo $PATH


path=${PATH#/*local/bin:}

echo $path 

path1=${PATH##/*:}

echo $path1


path2=${PATH%%*bin}

echo $path2


path3=${PATH%*bin}

echo $path3


path4=${PATH/bin/BIN}

echo $path4


path5=${PATH//bin//woc_BIN}

echo $path5


