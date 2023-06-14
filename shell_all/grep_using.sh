#!/bin/sh


#@function: split the res line

split_res ( ) {
    echo "#####SPLIT#####"
    return 0
}


# print kernel info about 'tty'
dmesg | grep 'tty'

echo "#####SPLIT#####"
# print with line tag and auto color

dmesg | grep -n --color=auto 'tty' 

echo "#####SPLIT#####"

# add prev 2 line and next 3 line

dmesg | grep -n --color=auto -A3 -B2 'tty'
echo "#####SPLIT#####"

###
#using grep with regular_express.txt
###


#find line with 'the'
grep -n 'the' regular_express.txt
echo "#####SPLIT#####"

#find line without 'the'
grep -vn 'the' regular_express.txt

echo "#####SPLIT#####"
#ignore upper or lower with 'the'

grep -in 'the' regular_express.txt


#using [] to find some character

grep -n 't[ae]st' regular_express.txt
echo "#####SPLIT#####"


#don't want goo

grep -n '[^g]oo' regular_express.txt 
echo "#####SPLIT#####"


#don't want lower character before 'oo'


grep -n '[^[:lower:]]oo' regular_express.txt
echo '#####SPLIT#####'


#line head contains 'the'

grep -n '^the' regular_express.txt
echo '#####SPLIT#####'

#find character '^'

grep -n '\^' regular_express.txt

echo '#####SPLIT#####'


#find line ending with '.'

grep -n '\.$' regular_express.txt
echo '#####SPLIT#####'



#find character begin with `g` and end with `g`

grep -n 'g.*g' regular_express.txt
echo '#####SPLIT#####'


#limit character repeat time

grep -n 'go\{2,5\}g' regular_express.txt
echo '#####SPLIT#####'





