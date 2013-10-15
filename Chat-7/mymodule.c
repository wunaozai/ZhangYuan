/****************************************
 * Copyright (C) 2013-2013 All rights reserved.
 * @Version: 1.0
 * @Created: 2013-10-15 16:27
 * @Author: 林明晓 -- 563804489@qq.com
 * @Description: 
 * @GitHub: https://github.com/wunaozai/ZhangYuan
 *
 * @History: 
 ****************************************/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
MODULE_LICENSE("GPL");

static int hello_init(void)
{
    printk(KERN_ALERT"Hello World!\n");
    return 0;
}

static void hello_exit(void)
{
    printk(KERN_ALERT"Goodbye,world!\n");
}

module_init(hello_init);
module_exit(hello_exit);

