#!/bin/sh


#using sed delete 2-5 line
nl /etc/passwd | sed -e '2,5d'


#using sed delete 5 line to end
nl /etc/passwd | sed -e '5,$d'


#add new line after second line

nl /etc/passwd | sed -e '2a #this is self append \n two line!!!'

#add new line before second line

nl /etc/passwd | sed -e '2i #this is self insert \n two line!!!'


#override content of item

nl /etc/passwd | sed -e '2,5c #this is new 2-5line content'


#list 10-20 line using sed

nl /etc/passwd | sed -n -e '10,20p'


#get ip address of lo interface

/sbin/ifconfig lo | grep 'inet ' | sed -e 's/inet //g' | sed -e 's/ *netmask.*$//g'


#using sed change the content of regular_express.txt

sed -e 's/\!\!*$/\?/g' regular_express.txt


#using sed append the file 

sed -e '$a #newly  append \n hehe~' regular_express.txt

