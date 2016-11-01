#include <ncurses.h>
#include <iostream>
#include <cstdio>
#include <stdio_ext.h>
#include <string>
#include <sstream>

#include "trie.h"

int main()
{
	using std::cout; using std::endl;
	std::string str;
	std::stringstream string_buffer;
	Trie::Node dictionary(0);

	__fpurge(stdin);
	initscr();
	raw();
	keypad(stdscr, TRUE);
	//noecho();
	curs_set(0);
	//timeout(0);

	cbreak();
	char key = ' ';

	while(1)
	{

		__fpurge(stdin);
		key = getch();
		if(key == 'q')
		{
			break;
		}
		if(key == ' ')
		{
			//string_buffer << str;
			dictionary.insertWord(str);
			str.clear();
		}
		if(key == '\n')
		{
			key = ' ';
		}
		str.push_back(key);
		// This is wrong, 
		// should insert from stringstream instead
		dictionary.insertWord(str);


		//clear();
		// Draw
			//mvaddch(0, 0, key);
			//cout << str;
			
		refresh();
		
	}

	endwin();

	dictionary.printAllWords();
	cout << "Stream is: " << string_buffer.str() << endl;

	return 0;
}
