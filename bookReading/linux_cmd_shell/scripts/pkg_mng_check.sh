#!/bin/bash

if ( which rpm &> /dev/null );then
	item_rpm=1
	echo "You have basic rpm utility"
else
	item_rpm=0
fi



if ( which flatpak &> /dev/null );then
	item_flatpak=1
	echo "You have flat pack container"
else
	item_flatpak=0
fi



if ( which dnf &> /dev/null );then
	item_dnfyum=1
	echo "You have dnf"
elif ( which yum &> /dev/null );then
	item_dnfyum=1
	echo "You have yum"
else
	item_dnfyum=0
fi



redhatscore=$[$item_rpm + $item_dnfyum + $item_flatpak]

echo "redhat scores: $redhatscore"


if ( which dpkg &> /dev/null );then
	item_dpkg=1
	echo "You have basic dpkg utility"
else
	item_dpkg=0
fi



if ( which apt-get &> /dev/null );then
	item_apt=1
	echo "You have apt-get"
else
	item_apt=0
fi


if ( which snap &> /dev/null );then
	item_snap=1
	echo "You have snap"
else
	item_snap=0
fi

debianscore=$[ $item_dpkg + $item_apt+ $item_snap ]

echo $debianscore 


if [ $debianscore -gt $redhatscore ];then
	echo "more like debian sys"
else
	echo "more like redhat sys"
fi

