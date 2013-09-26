/****************************************
 * Copyright (C) 2013-2013 All rights reserved.
 * @Version: 1.0
 * @Created: 2013-09-26 16:28
 * @Author: 林明晓 -- 563804489@qq.com
 * @Description: 
 * @GitHub: https://github.com/wunaozai/ZhangYuan
 *
 * @History: 
 ****************************************/

/*popetest.c*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>

#define MAX_LINE 80

int main()
{
    int thePipe[2],ret;
    char buf[MAX_LINE+1];
    const char * testbuf = "a test string ";
    if(pipe(thePipe)==0)
    {
	if(fork()==0)
	{
	    ret = read(thePipe[0],buf,MAX_LINE);
	    buf[ret]=0;
	    printf("Child read %s\n",buf);
	}
	else
	{
	    ret = write(thePipe[1],testbuf,strlen(testbuf));
	    ret = wait(NULL);
	}
    }
    close(thePipe[0]);
    close(thePipe[1]);
    return 0;
}
