#include "Trie.h"

Trie::Trie() : root(new TrieNode()) {}

void Trie::insert(std::string word) {
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

void Trie::displayUtil(TrieNode* node, std::string str) {
    if (node->isEndOfWord) {
        std::cout << str << std::endl;
    }
    for (char ch = 'a'; ch <= 'z'; ch++) {
        TrieNode* nextNode = node->children[ch - 'a'];
        if (nextNode) {
            displayUtil(nextNode, str + ch);
        }
    }
}

void Trie::display() {
    displayUtil(root, "");
}

Vector Trie::fuzzySearch(std::string pattern) {
}

Vector Trie::misspelledWordSearch(std::string word) {
}

Vector Trie::partialWordSearch(std::string suffix) {
}
