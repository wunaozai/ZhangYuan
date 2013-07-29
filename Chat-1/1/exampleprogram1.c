/**** exampleprogram1.c****/
#include <curses.h>

int main(int argc,char *argv[])
{
    int x=10;
    int y=10;
    int direction=1;
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
	x += direction;
	/*变换方向*/
	if(x==COLS)
	{
	    direction=-1;
	    x=COLS-1;
	    beep();
	}
	if(x<0)
	{
	    direction=1;
	    x=0;
	    beep();
	}
	usleep(100000);/*睡眠*/
    }
    endwin();
    return 0;
}
