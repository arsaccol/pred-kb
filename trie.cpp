#include "trie.h"
#include <iostream>
#include <functional>
#include <stack>

namespace Trie
{
/*
================
Trie::Trie
================
*/
	Trie::Trie()
		:	mWordCount(0)
		,	mNodeCount(0)
		,	mRoot(new Node(0))
	{
		/*
			=======================================
			// Commented out since we're indexing
			// directly without a map.
			// The map can perhaps be useful if we
			// use a larger alphabet or something.
			=======================================

			// For 26 letters starting from 'a',
			// insert the letter on the map
			// with the current i as a key
			char currentChar = 'a';
			for(size_t i = 0; i < 26; ++i)
			{
				mLetterToPos[currentChar++] = i;
			}
		*/
	}


/*
================
Trie::Trie(std::initializer_list<std::string>)
================
*/
Trie::Trie(std::initializer_list<std::string> init_list)
	:	Trie()
{

	for(auto str : init_list)
		insert(str);
}

/*
================
Node::Node
================
*/
	Node::Node(char data)
		:	mData(data)
		,	mEndOfWord(false)
	{

	}


/*
================
Trie::insert
================
*/
	void Trie::insert(std::string& word)
	{
		// Test for invalid characters.
		// This should go elsewhere later on...
		for(auto ch : word)
			if(ch < 'a' || ch > 'z')
				return;
		// That's right, a pointer to unique_ptr<Node>
		// For iteration and stuff
		std::unique_ptr<Node> *nodeIt = &mRoot;
		size_t wordIt = 0;

		// Walk through nodes that are already present
		while(wordIt < word.size())
		{
			char currChar = word[wordIt];
			// Unwieldy-looking mLetterToPos maps characters to array indices
			// in O(lg 26) time, as it's implemented as a red-black tree.

			if( (*nodeIt)->mChildren.at(currChar - 'a').get() != nullptr )
			{
				nodeIt = &( (*nodeIt)->mChildren.at(currChar - 'a') );
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

			(*nodeIt)->mChildren.at(currChar - 'a').reset(new Node(currChar));
			nodeIt = &((*nodeIt)->mChildren.at(currChar - 'a'));
			++wordIt;

			// Not part of the algorithm but let's update
			// our node count while we're at it
			// This may or may not be correct
			++mNodeCount;
		}


		nodeIt->get()->mEndOfWord = true;

	}


/*
================
Trie::getLexicographicalSort
================
*/
/* std::vector<std::string> Trie::getLexicographicalSort()
{
	std::vector<std::string> sortedVec;

	std::function<void(Node*)> recursiveHelper;

	recursiveHelper = [this](Node* nodeIt)
	{
		if(nodeIt == nullptr)
			return;

		std::cout << nodeIt->mData << std::endl;
		//for(auto child : nodeIt->mChildren)

	};

} */


/*
================
Trie::printLexicographicalOrder()
================
*/
void Trie::printLexicographicalOrder()
{
	std::string prefix;

	std::function<void(Node*)> recursiveHelper;
	recursiveHelper = [this, &recursiveHelper, &prefix](Node* nodeIt)
	{
		if(nodeIt == nullptr)
			return;

		prefix += nodeIt->mData;
		if(nodeIt->mEndOfWord)
		{
			std::cout << prefix;
			std::cout << std::endl;
		}

		for(auto& child : (nodeIt->mChildren))
			recursiveHelper(child.get());
		prefix.pop_back();
	};

	recursiveHelper(mRoot.get());

}

/*
================
Node::getData
================
*/
	char Node::getData() const
	{	return mData;	}


}
