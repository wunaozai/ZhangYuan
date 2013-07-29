/**** exampleprogram1.c****/
#include <curses.h>

int main(int argc,char *argv[])
{
    int x=10;
    int y=10;
    int directionx=1;
    int directiony=1;
    char ball='O';
    /*初始化*/
    initscr();
    crmode();
    noecho();

    while(true)
    {
	clear();
	mvaddch(y,x,ball);
	refresh();
	/*更新坐标*/
	x += directionx;
	y += directiony;
	/*变换方向*/
	if(x==COLS)
	{
	    directionx=-1;
	    x=COLS-1;
	    beep();
	}
	if(x<0)
	{
	    directionx=1;
	    x=0;
	    beep();
	}
	if(y==25)
	{
	    directiony=-1;
	    y=24;
	    beep();
	}
	if(y<0)
	{
	    directiony=1;
	    y=0;
	    beep();
	}
	usleep(50000);/*睡眠*/
    }
    endwin();
    return 0;
}
