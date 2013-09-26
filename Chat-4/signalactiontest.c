/****************************************
 * Copyright (C) 2013-2013 All rights reserved.
 * @Version: 1.0
 * @Created: 2013-09-26 08:29
 * @Author: 林明晓 -- 563804489@qq.com
 * @Description: 课本78页
 * @GitHub: https://github.com/wunaozai/Zhanyuan
 *
 * @History: 
 ****************************************/
/*利用sigaction()函数捕捉用户从键盘按Ctrl+C组合键*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define PROMPT "你想终止程序吗?"
#define errno 5 /*错误提示信息*/
char * prompt=PROMPT;

void ctrl_c_op(int signo)
{
    write(STDERR_FILENO,prompt,strlen(prompt));
}

int main()
{
    struct sigaction act;
    act.sa_handler=ctrl_c_op;
    sigemptyset(&act.sa_mask);
    act.sa_flags=0;
    if(sigaction(SIGINT,&act,NULL)<0)
    {
	fprintf(stderr,"Install Signal Action Error:%s\n\a",strerror(errno));
	exit(1);
    }
    while(1);
}
