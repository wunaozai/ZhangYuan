/****************************************
 * Copyright (C) 2013-2013 All rights reserved.
 * @Version: 1.0
 * @Created: 2013-10-08 14:41
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
    int fd;//client_sockfd;客户端套接字
    int len,ret;
    struct sockaddr_in remoteaddr;//服务器端网络地址结构体
    char data[1024];//数据传送的缓冲区
    /*设置远程地址参数*/
    memset(&remoteaddr,0,sizeof(remoteaddr));
    remoteaddr.sin_family=AF_INET;//设置为IP通讯
    remoteaddr.sin_addr.s_addr=inet_addr("127.0.0.1");//服务器IP地址
    remoteaddr.sin_port=htons(8888);//服务器端口号

    /*建立套接字*/
    fd=socket(PF_INET,SOCK_STREAM,0);
    if(fd<0)
    {
	printf("connect() error!\n");
	return -1;
    }

    /*发送数据到套接字*/
    ret=connect(fd,(struct sockaddr *)&remoteaddr,sizeof(struct sockaddr));
    if(ret<0)
    {
	printf("send() error!\n");
	return -2;
	//goto finish;
    }
    //从服务器端读取信息
    readline(fd,data,1024);

    printf("sent line:%s\n",data);
    printf("client exit.\n");

    /*关闭套接字*/
    close(fd);
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
