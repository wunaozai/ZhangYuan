/****************************************
 * Copyright (C) 2013-2013 All rights reserved.
 * @Version: 1.0
 * @Created: 2013-09-26 08:20
 * @Author: 林明晓 -- 563804489@qq.com
 * @Description: 对应课本的77-78页
 * @GitHub: https://github.com/wunaozai/Zhanyuan
 *
 * @History: 
 ****************************************/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void sigroutine(int dunno)
{
    /*信号处理函数，其中dunno将会得到信号的值*/
    switch (dunno)
    {
	case 1:
	    printf("Get a signal-SIGHUP\n");
	    break;
	case 2:
	    printf("Get a signal-SIGINT\n");
	    break;
	case 3:
	    printf("Get a signal-SIGQUIT\n");
	    break;
    }
    return ;
}

int main()
{
    printf("process id is %d\n",getpid());
    signal(SIGHUP,sigroutine); /*下面设置3个信号量处理函数*/
    signal(SIGINT,sigroutine);
    signal(SIGQUIT,sigroutine);
    for(;;);//如果没有这个将会直接结束程序
}
