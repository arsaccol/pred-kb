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

	Trie::Trie trieDict { "bear", "bell", "bid", "bull",
		"buy", "sell", "stock", "stop", "candy", "can",
		"could", "count"};
/*
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
			trieDict.insert(str);
			str.clear();
			continue;
		}
		str.push_back(key);
		// This is wrong, 
		// should insert from stringstream instead




		//clear();
		// Draw
			//mvaddch(0, 0, key);
			//cout << str;
			
		refresh();
		
	}

	endwin();
*/
	//cout << "Stream is: " << string_buffer.str() << endl;

	auto sortedVec = trieDict.getLexicographicalSort();
	//trieDict.printLexicographicalOrder();
	for(auto& str : sortedVec)
		std::cout << str << std::endl;

	return 0;
}
