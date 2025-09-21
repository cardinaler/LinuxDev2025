#include <ncurses.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#define DX 5
#define DY 1
int main(int argc, char *argv[]) {
        WINDOW *win, *frame;
        setlocale(LC_ALL, "");
	if(argc == 1)
	{
		printf("%s", "Not enought args\n");
		return 0;

	}
	FILE* fptr;
	fptr = fopen(argv[1], "r");
	if(fptr == NULL)
	{
		printf("The file in not opened");
		return 0;
	}
        initscr();
	noecho();
        cbreak();

	frame = newwin(LINES - 2*DY, COLS - 2*DX, DY, DX);
	
        box(frame, 0, 0);
        mvwaddstr(frame, 0, (int)((COLS - 2*DX - 5) / 2), argv[1]);
        wrefresh(frame);
	
	win = newwin(LINES - 2*DY - 2, COLS - 2*DX-2, DY+1, DX+1);
	
        keypad(win, TRUE);
        scrollok (win, TRUE);
	bool flag = true;
	int cnt = 0;
	int cn = 0;
	int c = 0;
	char line[256];
	do
	{
		if(c == 32)
		{
			cn++;
		}
		while(cnt < LINES - DX + cn && flag)
		{
			if(fgets(line, sizeof(line), fptr) != NULL)
			{
				wprintw(win, "%s", line);
				wrefresh(win);
				cnt++;
			}
			else
			{
				flag = false;
			}	
		}
		
	}while((c = wgetch(win)) != 27);
        delwin(win);
        endwin();
}
