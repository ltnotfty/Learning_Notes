#!/bin/sh

# judge /tmp/abc exist; if exist ,modifile its m/atime. 
ls /tmp/abc && touch /tmp/abc

# judge /tmp/abc existence; if not exist,create it.
ls /tmp/abc || touch /tmp/abc

# rm dir
rm -r /tmp/abc

# test /tmp/abc exist? if not , make it.
ls /tmp/abc || mkdir -p /tmp/abc

# judge dir existence
ll -d /tmp/abc

# delete dir
rm -r /tmp/abc 

# want create /tmp/abc/new_file but don't want many operation.
ls /tmp/abc || mkdir -p /tmp/abc && touch /tmp/abc/new_file

# testing /tmp/vbirding existence 
ls /tmp/vbirding && echo "exist" || echo "not exist"

