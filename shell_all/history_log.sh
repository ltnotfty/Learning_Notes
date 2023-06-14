#!/bin/bash


#This bash shell record history command for current process



history | cut -c 8- > `pwd`/history_command
