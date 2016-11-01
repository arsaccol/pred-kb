#ifndef TRIE_H
#define TRIE_H
#include <cstdint>
#include <map>
#include <string>
#include <memory>

// Premature optimization is the root of all evil
// (Donald Knuth)

namespace Trie
{
	void integerToLetter(uint8_t);


	class Node
	{
		public:
			Node(char data)
				:	mData(data)
				,	mEndOfWord(false)
			{}

			void insertWord(std::string& word);
			char getData() const;
			void printAllWords() const;

		private:
			char mData;
			bool mEndOfWord;
			std::map< char, std::unique_ptr<Node> > mChildren;

			//std::list<Node*> children;
	};


	class Trie
	{
		public:
			Trie()
				:	mRoot(new Node(0))
				,	mWordCount(0)
				,	mNodeCount(1)
			{}

			void insertWord(std::string& word);
			Node* findWord(std::string& word);


		private:
			size_t mWordCount;
			size_t mNodeCount;
			std::unique_ptr<Node> mRoot;
	};
	


}

#endif
