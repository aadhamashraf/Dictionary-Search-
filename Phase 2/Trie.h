#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include "Vector.h" 

struct TrieNode {
    TrieNode *children[26];
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode *root;

    char tolower(char c); 

    void searchWords(TrieNode* node, const std::string& prefix, Vector &result);

    void wildcardSearchHelper(TrieNode* node, const std::string& pattern, std::string word, Vector& result);

    void partialWordSearchHelper(TrieNode* node, const std::string& suffix, const std::string& current, Vector& result, int maxLength);

    void misspelledWordSearchHelper(TrieNode* node, const std::string& word, const std::string& current, Vector& result);

public:

    int wordcoutner {0};

    Trie();

    void insert(const std::string &word);

    bool search(const std::string &word);

    bool isEmpty(TrieNode *node);

    TrieNode* remove(TrieNode *node, const std::string &word, int depth = 0);

    void deleteWord(const std::string &word);

    void displayContent();

    Vector fuzzySearch(const std::string& prefix);

    Vector wildcardSearch(const std::string& pattern);

    Vector partialWordSearch(const std::string& suffix);

    Vector misspelledWordSearch(const std::string& word);

    void displayContentHelper(TrieNode *node, std::string prefix);

    int get_trie_size();
};

#endif // TRIE_H
