#!/bin/bash

# if then


if pwd 
then
	echo "it worked"
fi

usr=ltnoy


if grep $usr /etc/passwd; then
	ls /home/$usr/*.sh

elif ls -d /home/$usr; then
		echo "$usr not in group but dir exists"
else
	echo "$usr not in usergroup and /home/$usr dir not exists"
fi

