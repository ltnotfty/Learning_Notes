#!/bin/bash

[ -d ~/bin ] || mkdir ~/bin
cd ~/bin
echo `pwd`

PATH=/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH
echo -e "hello world! \a \n"
exit 0

