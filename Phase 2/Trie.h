#include <iostream>
#include "Vector.h"

struct TrieNode {
    TrieNode * children[26];
    bool isEndOfWord;
    TrieNode() : isEndOfWord(false) { for(int i = 0; i < 26; i++) {children[i] = nullptr;}}
};

class Trie {
private:
    TrieNode* root;

public:

  Trie() : root(new TrieNode()) {}

    void insert(std::string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    void display(TrieNode* node, std::string str) {
        if (node->isEndOfWord) {
            std::cout << str << std::endl;
        }
        for (char ch = 'a'; ch <= 'z'; ch++) {
            TrieNode* nextNode = node->children[ch - 'a'];
            if (nextNode) {
                display(nextNode, str + ch);
            }
        }
    }

    void display() {
        display(root, "");
    }

    // std::vector<std::string> fuzzySearch(std::string pattern) {
    //     // Implement fuzzy search here
    // }

    // std::vector<std::string> misspelledWordSearch(std::string word) {
    //     // Implement misspelled word search here
    // }

    // std::vector<std::string> partialWordSearch(std::string suffix) {
    //     // Implement partial word search here
    // }
};
int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("apply");
    trie.insert("apples");
    trie.insert("loading");
    trie.insert("interesting");

    std::cout << "Displaying Trie:\n";
    trie.display();

    // Invoke other methods as needed
    // std::vector<std::string> results = trie.fuzzySearch("appl?");
    // results = trie.misspelledWordSearch("aple");
    // results = trie.partialWordSearch("ing");

    return 0;
}
