#ifndef TRIE_H
#define TRIE_H
#include <cstdint>
//#include <map>
#include <vector>
#include <string>
#include <memory>
#include <initializer_list>

// Premature optimization is the root of all evil
// (Donald Knuth)

namespace Trie
{
	class Node;

	class Trie
	{
		public:
			Trie();
			Trie(std::initializer_list<std::string>);

			void insert(std::string& word);
			Node& find(std::string& word);

		public:
			std::vector<std::string> getLexicographicalSort();
			size_t getWordCount() const;
			void printLexicographicalOrder();


		private:
			size_t mWordCount;
			size_t mNodeCount;
			std::unique_ptr<Node> mRoot;
	};

	class Node
	{
		public:
			friend class Trie;
			Node(char data);

			char getData() const;
			std::vector<std::string> getLexicographicalSort();

		private:
			char mData;
			bool mEndOfWord;
			std::vector< std::unique_ptr<Node> > mChildren{26};

	};
}

#endif
