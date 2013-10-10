#!/bin/bash
##################################################
# Program: shellprogram1
# 
# History
# Created: 2013-10-10 08:15
# Author: 林明晓 
# Email: wunaozai@gmail.com
##################################################
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

dir=$1;shift
if [ -d $dir ]
then
    cd $dir
    for name in ` ls $1 `
    do
	echo $name
	if [ -f $name ] 
	then
	    cat $name 
	    echo "end of ${dir}/$name"
	else 
	    echo "invaild file name:${dir}/$name"
	fi
    done
else
    echo "bad directory name:${dir}"
fi
