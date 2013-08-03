/****************************************
 * Copyright (C) 2013-2013 All rights reserved.
 * @Version: 1.0
 * @Created: 2013-08-04 06:11
 * @Author: 林明晓 -- 563804489@qq.com
 * @Description: 
 * @GitHub: https://github.com/wunaozai/Linux_Zhanyuan
 *
 * @History: 
 ****************************************/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid1;
    pid_t pid2;
    pid1 = fork();
    pid2 = fork();
    printf("pid1:%d, pid2:%d\n", pid1, pid2);
}
