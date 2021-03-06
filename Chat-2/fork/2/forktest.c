/****************************************
 * Copyright (C) 2013-2013 All rights reserved.
 * @Version: 1.0
 * @Created: 2013-08-04 05:34
 * @Author: 林明晓 -- 563804489@qq.com
 * @Description: 
 * @GitHub: https://github.com/wunaozai/Zhanyuan
 *
 * @History: 
 ****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int i;
    pid_t pid=fork();
    if( pid == 0)
    {
	/*子进程程序*/
	for(i=1;i<3;i++)
	    printf("This is child process.\n");
    }
    else if(pid<0)
    {
	printf("fork new process error!\n");
	exit(-1);
    }
    else
    {
	/*父进程程序*/
	for(i=1;i<3;i++)
	    printf("This is parent process.\n");
    }
    return 0;
}
