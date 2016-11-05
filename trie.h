#ifndef TRIE_H
#define TRIE_H
#include <cstdint>
#include <map>
#include <vector>
#include <string>
#include <memory>

// Premature optimization is the root of all evil
// (Donald Knuth)

namespace Trie
{

	class Node
	{
		public:
			friend class Trie;
			Node(char data);

			char getData() const;
			//void printAllWords() const;

		private:
			char mData;
			bool mEndOfWord;
			// TODO: Change constructor to start vector with 26 nullptr's
			std::vector< std::unique_ptr<Node> > mChildren{26};


			//std::list<Node*> children;
	};


	class Trie
	{
		public:
			Trie();

			void insertWord(std::string& word);
			Node& findWord(std::string& word);
			std::map<char, size_t> mLetterToPos;


		private:
			size_t mWordCount;
			size_t mNodeCount;
			std::unique_ptr<Node> mRoot;
	};
	


}

#endif
