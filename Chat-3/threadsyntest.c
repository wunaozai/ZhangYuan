/****************************************
 * Copyright (C) 2013-2013 All rights reserved.
 * @Version: 1.0
 * @Created: 2013-08-05 04:47
 * @Author: 林明晓 -- 563804489@qq.com
 * @Description: 
 * @GitHub: https://github.com/wunaozai/Linux_Zhanyuan
 *
 * @History: 
 ****************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

void * thread_function(void * arg);
pthread_mutex_t work_mutex; /*互斥量，保护工作区及额外变量 time_to_exit*/

#define WORK_SIZE 1024
char work_area[WORK_SIZE]; /*工作区*/
int time_to_exit=0;

int main()
{
    int res;
    pthread_t a_thread;
    void * thread_result;
    res=pthread_mutex_init(&work_mutex,NULL); /*初始化工作区*/
    if(res!=0)
    {
	perror("Mutex initialization failed\n");
	exit(EXIT_FAILURE);
    }
    res=pthread_create(&a_thread,NULL,thread_function,NULL); /*创建新线程*/
    if(res!=0)
    {
	perror("Thread creation failed\n");
	exit(EXIT_FAILURE);
    }
    /*主线程*/
    pthread_mutex_lock(&work_mutex);
    printf("Input some text. Enter 'end' to finish\n");
    while(!time_to_exit)
    {
	fgets(work_area,WORK_SIZE,stdin);
	pthread_mutex_unlock(&work_mutex);
	while(1)
	{
	    pthread_mutex_lock(&work_mutex);
	    if(work_area[0]!='\0')
	    {
		pthread_mutex_unlock(&work_mutex);
		sleep(1);
	    }
	    else
	    {
		break;
	    }
	}
    }
    pthread_mutex_unlock(&work_mutex);
    printf("\nWaiting for thread to finish...\n");
    res=pthread_join(a_thread,&thread_result);
    if(res!=0)
    {
	perror("Thread join failed\n");
	exit(EXIT_FAILURE);
    }
    printf("Thread joined\n");
    pthread_mutex_destroy(&work_mutex);
    exit(EXIT_SUCCESS);
    return 0;
}

/*新进程*/
void * thread_function(void * arg)
{
    sleep(1);
    pthread_mutex_lock(&work_mutex);
    while(strncmp("end",work_area,3)!=0)
    {
	printf("You input %d characters\n",strlen(work_area)-1);
	work_area[0]='\0';
	pthread_mutex_unlock(&work_mutex);
	sleep(1);
	pthread_mutex_lock(&work_mutex);
	while(work_area[0]=='\0')
	{
	    pthread_mutex_unlock(&work_mutex);
	    sleep(1);
	    pthread_mutex_lock(&work_mutex);
	}
    }
    time_to_exit=1;
    work_area[0]='\0';
    pthread_mutex_unlock(&work_mutex);
    pthread_exit(0);
}
