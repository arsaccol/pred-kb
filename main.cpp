#include <ncurses.h>
#include <iostream>
#include <cstdio>
#include <stdio_ext.h>

int main()
{
	__fpurge(stdin);
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	timeout(0);

	cbreak();
	char key = ' ';

	while(1)
	{
		key = getch();
		if(key == 'q')
			break;

		clear();
		// Draw
			mvaddch(0, 0, key);
		refresh();
		
	}

	endwin();

	return 0;
}
