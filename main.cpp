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
	Trie::Trie trieDict;

	__fpurge(stdin);
	initscr();
	raw();
	keypad(stdscr, TRUE);
	//noecho();
	curs_set(0);
	//timeout(0);

	cbreak();
	char key = 'a';

	while(1)
	{

		__fpurge(stdin);
		key = getch();
		if(key == 'q')
		{
			break;
		}
		if(key == '\n')
		{
			//key = ' ';
		}
		if(key == ' ')
		{
			str.clear();
			continue;
		}
		str.push_back(key);
		// This is wrong, 
		// should insert from stringstream instead


		trieDict.insertWord(str);


		//clear();
		// Draw
			//mvaddch(0, 0, key);
			//cout << str;
			
		refresh();
		
	}

	endwin();

	//dictionary.printAllWords();
	cout << "Stream is: " << string_buffer.str() << endl;

	for(auto& entry : (trieDict.mLetterToPos))
		std::cout << entry.first << " " << entry.second << std::endl;

	return 0;
}
