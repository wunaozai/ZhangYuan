/****************************************
 * Copyright (C) 2013-2013 All rights reserved.
 * @Version: 1.0
 * @Created: 2013-09-26 16:53
 * @Author: 林明晓 -- 563804489@qq.com
 * @Description: 
 * @GitHub: https://github.com/wunaozai/ZhangYuan
 *
 * @History: 
 ****************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#define FIFO_SERVER "/tmp/fifoserver"

int main(int argc,char ** argv)
{
    /**/
    int fd=0;
    char w_buf[4096*2];
    int real_wnum;
    memset(w_buf,0,4096*2);
    if((mkfifo(FIFO_SERVER,O_CREAT|O_EXCL)<0) && (errno!=EEXIST))
    {
	printf("cannot create fifoserver\n");
    }
    if(fd==-1)
    {
	if(errno==ENXIO)
	{
	    printf("open error;no reading process\n");
	}
	exit(-1);
    }
    /**/
    fd=open(FIFO_SERVER,O_WRONLY|O_NONBLOCK,0);
    //fd=open(FIFO_SERVER,O_WRONLY,0);

    real_wnum=write(fd,w_buf,2048);
    printf("%d\n",real_wnum);
    printf("Input:");
    scanf("%s",w_buf);
    if(real_wnum==-1)
    {
	if(errno==EAGAIN)
	{
	    printf("write to fifo error;try later\n");
	}
    }
    else
    {
	printf("real write num is %d\n",real_wnum);
    }
    real_wnum=write(fd,w_buf,5000);
    /**/
    if(real_wnum==-1)
    {
	if(errno==EAGAIN)
	{
	    printf("try later\n");
	}
    }
}
