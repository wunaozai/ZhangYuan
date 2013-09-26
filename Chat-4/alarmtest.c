/****************************************
 * Copyright (C) 2013-2013 All rights reserved.
 * @Version: 1.0
 * @Created: 2013-09-26 09:05
 * @Author: 林明晓 -- 563804489@qq.com
 * @Description: 课本82页
 * @GitHub: https://github.com/wunaozai/Zhanyuan
 *
 * @History: 
 ****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void my_alarm_handle(int sign_no)
{
    if(sign_no == SIGALRM)
    {
	printf("I have been waken up.\n");
    }
}

int main()
{
    printf("sleep for 5s......\n");
    signal(SIGALRM,my_alarm_handle);
    alarm(5);
    pause();
    return 0;
}
