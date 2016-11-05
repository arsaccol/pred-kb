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
		Node* nodeIt = mRoot.get();


		for(auto ch : word)
		{
			// if letter not present
			if( nodeIt->mChildren[mLetterToPos.at(ch)].get() == nullptr )
			{
				// insert it in correct position in nodeIt->mChildren
				//nodeIt->mChildren[mLetterToPos.at(ch)].reset(new Node(ch));
				//auto insertingNode = nodeIt->mChildren[mLetterToPos.at(ch)].get();

			}



		}



	}



	char Node::getData() const
	{	return mData;	}


	// Likely to be correct...
/*	void Node::printAllWords() const
	{
		const Node* nodeIt = this;
		auto depth_first_traversal = [this]()
		{
			std::stack<const Node*> stack;
			stack.push(this);

			while(!stack.empty())
			{
				auto top = stack.top();
				stack.pop();

				if(top != nullptr)
				{
					std::cout << top->getData();

					for(auto& child : top->mChildren)
					stack.push(child.second.get());
				}

				else
					std::cout << std::endl;
			}
		};

		depth_first_traversal();

	} */

}
