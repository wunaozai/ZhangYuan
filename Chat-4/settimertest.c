/****************************************
 * Copyright (C) 2013-2013 All rights reserved.
 * @Version: 1.0
 * @Created: 2013-09-26 08:51
 * @Author: 林明晓 -- 563804489@qq.com
 * @Description: 课本80页
 * @GitHub: https://github.com/wunaozai/Zhanyuan
 *
 * @History: 
 ****************************************/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

int sec;
void sigroutine(int signo)
{
    switch(signo)
    {
	case SIGALRM:
	    printf("Catch a signal-SIGALRM\n");
	    break;
	case SIGVTALRM:
	    printf("Catch a signal-SIGVTALRM\n");
	    break;
    }
    return ;
}


int main()
{
    struct itimerval value,ovalue,value2;
    sec=5;
    printf("process id %d\n",getpid());
    signal(SIGALRM,sigroutine);
    signal(SIGVTALRM,sigroutine);
    value.it_value.tv_sec=1;
    value.it_value.tv_usec=0;
    value.it_interval.tv_sec=1;
    value.it_interval.tv_usec=0;
    setitimer(ITIMER_REAL,&value,&ovalue);
    value2.it_value.tv_sec=0;
    value2.it_value.tv_usec=500000;
    value2.it_interval.tv_sec=0;
    value2.it_interval.tv_usec=500000;
    setitimer(ITIMER_VIRTUAL,&value2,&ovalue);
    for(;;);
}
