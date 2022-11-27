#include <iostream>

struct Node {
	Node* links[26];
	bool flag {false};

	bool containsKey(char ch) {
		return (links[ch - 'a'] != nullptr);
	}

	void put(char ch, Node* node) {
		links[ch - 'a'] = node;
	}

	Node* get(char ch) {
		return links[ch - 'a'];
	}

	void setEnd() {
		flag = true;
	}
};

class Trie {
private:
	Node* root;

public:
	Trie() {
		root = new Node();
	}

	void Insert(std::string word) {
		Node* node {root};
		for (size_t i {0}; i < word.length(); ++i) {
			if (!node ->containsKey(word[i])) {
				node ->put(word[i], new Node());
			}
			node = node ->get(word[i]);
		}

		node ->setEnd();
	}

	bool Search(std::string word) {
		Node* node {root};

		for (size_t i {0}; i < word.length(); ++i) {
			if (!node ->containsKey(word[i])) return false;
			node = node ->get(word[i]);
		}

		return node ->flag;
	}

	bool startsWith(std::string prefix) {
		Node* node {root};

		for (size_t i {0}; i < prefix.length(); ++i) {
			if (!node ->containsKey(prefix[i])) return false;
			node = node ->get(prefix[i]);
		}

		return true;
	}
};

int main()
{
	Trie t {Trie()};

	t.Insert("apple");
	t.Insert("apps");

	std::cout << t.Search("apple") << std::endl;
	std::cout << t.Search("apps") << std::endl;
	std::cout << t.Search("batman") << std::endl;

	std::cout << t.startsWith("ap") << std::endl;
	std::cout << t.startsWith("ba") << std::endl;

	return 0;
}