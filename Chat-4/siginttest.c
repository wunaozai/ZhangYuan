/****************************************
 * Copyright (C) 2013-2013 All rights reserved.
 * @Version: 1.0
 * @Created: 2013-09-26 09:13
 * @Author: 林明晓 -- 563804489@qq.com
 * @Description: 课本83页
 * @GitHub: https://github.com/wunaozai/Zhanyuan
 *
 * @History: 
 ****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

/*自定义SIGINT的处理函数，如果按Ctrl+C键，则会打印提示，而不是默认的退出*/
void my_func(int sigo_num)
{
    printf("If you want to quit,please try 'ctrl+\\' \n");
}

int main()
{
    sigset_t set;
    struct sigaction action1,action2;
    /*初始化信号集为空*/
    if(sigemptyset(&set)<0)
    {
	perror("sigemptyset\n");
	exit(-1);
    }
    /*将相应的信号加入信号集*/
    if(sigaddset(&set,SIGQUIT)<0)
    {
	perror("sigaddset SIGINT\n");
	exit(-1);
    }
    /*设置信号屏蔽字*/
    if(sigprocmask(SIG_BLOCK,&set,NULL)<0)
    {
	perror("sigprocmask SIG_BLOCK\n");
	exit(1);
    }
    else
    {
	printf("blocked,and sleep for 5s...\n");
	sleep(5);
    }

    if(sigprocmask(SIG_UNBLOCK,&set,NULL)<0)
    {
	perror("sigprocmask SIG_UNBLOCK\n");
	exit(1);
    }
    else
    {
	printf("unblock\n");
	/*此处可以添加函数功能模块process()*/
	sleep(2);
	printf("If you want to quit this program,please try ...\n");
    }
    /*对相应的信号进行循环处理*/
    while(1)
    {
	if(sigismember(&set,SIGINT))
	{
	    sigemptyset(&action1.sa_mask);
	    action1.sa_handler=my_func;
	    sigaction(SIGINT,&action1,NULL);
	}
	else if(sigismember(&set,SIGQUIT))
	{
	    sigemptyset(&action2.sa_mask);
	    /*SIG_DFL 采用默认的方式处理*/
	    action2.sa_handler=SIG_DFL;
	    sigaction(SIGTERM,&action2,NULL);
	}
    }

    return 0;
}
