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
    int server_sockfd;//服务器端套接字
    int client_sockfd;//客户端套接字
    int len;
    int ret;
    struct sockaddr_in my_addr;//服务器端地址结构体
    struct sockaddr_in remote_addr;//客户端网络地址结构体
    int sin_size;
    char buf[1024];//数据传输的缓冲区
    memset(&my_addr,0,sizeof(my_addr));//数据初始化
    my_addr.sin_family=AF_INET;//设置为IP通讯
    my_addr.sin_addr.s_addr=INADDR_ANY;//服务器IP地址--允许连接到所有本地地址上
    my_addr.sin_port=htons(8888);//服务器端口号

    /*创建套接字*/
    server_sockfd=socket(PF_INET,SOCK_STREAM,0);
    if(server_sockfd<0)
    {
	printf("socket() error%d\n",errno);
	return -1;
    }

    /*绑定地址和端口*/
    ret=bind(server_sockfd,(struct sockaddr *)&my_addr,sizeof(struct sockaddr));
    if(ret<0)
    {
	printf("bind() error\n");
	return -1;
    }

    /*建立套接字队列*/
    ret=listen(server_sockfd,5);//设置队列长度为5
    sin_size=sizeof(struct sockaddr_in);
    if(ret<0)
    {
	printf("listen() error!\n");
	return -1;
    }

    while(1)
    {
	/*等待客户请求到达*/
	client_sockfd=accept(server_sockfd,(struct sockaddr *)&remote_addr,&sin_size);
	if(ret<0)
	{
	    printf("accept() error!\n");
	    return -1;
	}
	printf("Accept client %s\n",inet_ntoa(remote_addr.sin_addr));
	len=send(client_sockfd,"Welcome to my server\n",21,0);//发送欢迎消息
	/*接收数据*/
	ret=recv(client_sockfd,buf,1024,0);
	if(ret<0)
	{
	    printf("recv() error!\n");
	    return -1;
	}
	printf("server read line:%s\n",buf);
	/*关闭连接*/
    }
    close(client_sockfd);
    close(server_sockfd);
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
