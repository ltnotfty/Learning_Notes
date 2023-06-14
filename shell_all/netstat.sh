#!/bin/bash
PATH=/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH


# echo user operation
echo "Now, I will detect your linux server's services!"
echo -e "The www, ftp, ssh, and mail (smtp) will be detect"

# some test task, echo some info

testfile=/dev/shm/netstat_cheking.txt

netstat -tuln > ${testfile}
testing=$(grep ":80" ${testfile})

if [ "${testing}" != "" ];then
	echo "WWW is running in your system. "
fi

testing=$(grep ":53" ${testfile})

if [ "${testing}" != "" ];then
	echo "DNS is running in your system. "
fi

testing=$(grep ":21" ${testfile})

if [ "${testing}" != "" ];then
	echo "FTP is running in your system. "
fi

testing=$(grep ":25" ${testfile})

if [ "${testing}" != "" ];then
	echo "Mail is running in your system. "
fi



