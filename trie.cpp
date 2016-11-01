#include "trie.h"
#include <iostream>
#include <functional>
#include <stack>

namespace Trie
{
	void Trie::insertWord(std::string& word)
	{

	}

	void Node::insertWord(std::string& word)
	{
		size_t wordIt = 0;
		Node* nodeIt = this;

		// for each letter
		while(wordIt < word.size() && nodeIt != nullptr)
		{
			char current_letter = word[wordIt];

			// If letter is in current node
			if(nodeIt->mData == current_letter)
			{
				// We restart the loop for the next letter
				// with its corresponding node
				current_letter = word[++wordIt];
				nodeIt = mChildren[current_letter].get();
			}

			// If letter isn't in current node
			else
			{
				// letter is in children
				if( nodeIt->mChildren[current_letter].get() != nullptr )
					nodeIt = mChildren[current_letter].get();
				else
				{
					nodeIt->mChildren[current_letter] = std::make_unique<Node>(current_letter);
				}
			}

		}

	}

	char Node::getData() const
	{	return mData;	}


	// Likely to be correct...
	void Node::printAllWords() const
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

	}

}
