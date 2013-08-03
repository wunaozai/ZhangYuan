/****************************************
 * Copyright (C) 2013-2013 All rights reserved.
 * @Version: 1.0
 * @Created: 2013-08-04 05:34
 * @Author: 林明晓 -- 563804489@qq.com
 * @Description: 
 * @GitHub: https://github.com/wunaozai/Linux_Zhanyuan
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
    int p_id;
    if( (p_id=fork()) == 0)
    {
	/*子进程程序*/
	for(i=1;i<3;i++)
	    printf("This is child process.\n");
    }
    else if(p_id==-1)
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
