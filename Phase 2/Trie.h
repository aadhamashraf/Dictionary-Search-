#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include "Vector.h"

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode() : isEndOfWord(false) {  for(int i = 0; i < 26; i++) { children[i] = nullptr; } }
};

class Trie {
private:

    TrieNode* root;
    void displayUtil(TrieNode* node, std::string str);

public:

    Trie();

    void insert(std::string word);

    void display();

    Vector fuzzySearch(std::string pattern);

    Vector misspelledWordSearch(std::string word);

    Vector partialWordSearch(std::string suffix);
};

#endif /* TRIE_H */
