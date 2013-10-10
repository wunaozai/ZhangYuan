#!/bin/bash
##################################################
# Program:
# 
# History
# Created: 2013-10-10 08:53
# Author: 无脑仔的小明 -- wunaozai@gmail.com
##################################################
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

if [ $#=3 ]
then
    case $2 in
	+) let z=$1+$3;;
	-) let z=$1-$3;;
	/) let z=$1/$3;;
	x|X) let z=$1*$3;;
	*) echo "Warning-$2 invalied operator, only +,-,x,/ "operator allowed.
	exit;;
    esac
    echo "Answer is $z"
else
    echo "Usage-$0 value1 operator value2."
fi
