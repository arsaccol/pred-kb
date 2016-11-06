#include "trie.h"
#include <iostream>
#include <functional>
#include <stack>

namespace Trie
{
	Trie::Trie()
		:	mWordCount(0)
		,	mNodeCount(0)
		,	mRoot(new Node(0))
	{
		// For 26 letters starting from 'a',
		// insert the letter on the map
		// with the current i as a key
		char currentChar = 'a';
		for(size_t i = 0; i < 26; ++i)
		{
			mLetterToPos[currentChar++] = i;
		}
	}

	Node::Node(char data)
		:	mData(data)
		,	mEndOfWord(false)
	{

	}

	void Trie::insertWord(std::string& word)
	{
		// That's right, a pointer to unique_ptr<Node>
		// For iteration and stuff
		std::unique_ptr<Node> *nodeIt = &mRoot;
		size_t wordIt = 0;

		// Walk through nodes that are already present
		while(wordIt < word.size())
		{
			char currChar = word[wordIt];
			if( (*nodeIt)->mChildren.at(mLetterToPos[currChar]).get() != nullptr )
			{
				nodeIt = &( (*nodeIt)->mChildren.at(mLetterToPos[currChar]) );
				++wordIt;

			}
			else
				break;
		}

		// Now we're at a letter/suffix which is not present
		// so we insert it (i.e. allocate and link it)
		while(wordIt < word.size())
		{
			char currChar = word[wordIt];

			(*nodeIt)->mChildren.at(mLetterToPos[currChar]).reset(new Node(currChar));
			nodeIt = &((*nodeIt)->mChildren.at(mLetterToPos[currChar]));
			++wordIt;
		}

	}



	char Node::getData() const
	{	return mData;	}


}
