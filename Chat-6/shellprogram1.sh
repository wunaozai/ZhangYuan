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

dir=$1;shift #获取第一个参数 shift是舍去第一个参数
if [ -d $dir ] #判断输入的参数是否为一个目录
then
    cd $dir #进入$dir目录
    for name # in ` ls ` #用ls 遍历所有目录下的文件
    do
	echo $name
	if [ -f $name ] 
	then
	    cat $name #输出文件中的信息
	    echo "end of ${dir}/$name"
	else 
	    echo "invaild file name:${dir}/$name" #输出文件信息错误
	fi
    done
else
    echo "bad directory name:${dir}" #没有这个文件夹
fi
