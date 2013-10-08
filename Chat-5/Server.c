/****************************************
 * Copyright (C) 2013-2013 All rights reserved.
 * @Version: 1.0
 * @Created: 2013-10-08 15:18
 * @Author: 林明晓 -- 563804489@qq.com
 * @Description: 
 * @GitHub: https://github.com/wunaozai/ZhangYuan
 *
 * @History: 
 ****************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

int readline(int fd,void *pbuf,int maxlen);

int main(int argc,char **argv)
{
    /*创建套接字*/
    if(ret<0)
    {
	printf("socket() error%d\n",errno);
	return -1;
    }
    /*绑定地址和端口*/
    if(ret<0)
    {
	printf("bind() error\n");
	return -1;
    }
    /*建立套接字队列*/
    if(ret<0)
    {
	printf("listen() error!\n");
	return -1
    }

    while(1)
    {
	/*等待客户请求到达*/
	/*接收数据*/
	printf("server read line:%s\n",buf);
	/*关闭连接*/
    }
    return 0;
}


int readline(int fd,void *pbuf,int maxlen)
{
    int n,ret;
    char c,*ptr;

    ptr=pbuf;
    for(n=1;n<maxlen;n++)
    {
again:
	ret=recv(fd,&c,1,0);
	if(ret==1)
	{
	    *ptr++=c;
	    if(c=='\n')
		break;//读结束
	}
	else if(ret==0)
	{
	    if(n==1)
		return 0;//文件结尾，未读到数据
	    else
		break;//文件结尾，读到部分数据
	}
	else
	{
	    if(errno == EINTR)
		goto again;
	    return -1;//出错
	}
    }
    *ptr=0;
}
