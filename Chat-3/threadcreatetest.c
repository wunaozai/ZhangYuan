/****************************************
 * Copyright (C) 2013-2013 All rights reserved.
 * @Version: 1.0
 * @Created: 2013-08-05 04:27
 * @Author: 林明晓 -- 563804489@qq.com
 * @Description: 
 * @GitHub: https://github.com/wunaozai/Linux_Zhanyuan
 *
 * @History: 
 ****************************************/
#include <pthread.h>
#include <stdio.h>

void * create(void * arg)
{
    printf("new thread created...\n");
}

int main(int argc,char * argv[])
{
    pthread_t tidp;
    int error;
    error=pthread_create(&tidp,NULL,create,NULL);
    if(error!=0)
    {
	printf("pthread_create is created...\n");
	return -1;
    }
    printf("pthread_create is created...\n");
    return 0;
}
