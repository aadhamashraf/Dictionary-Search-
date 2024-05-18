#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include "Vector.h"

struct TrieNode {
    TrieNode *children[26]{};
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {
        for (auto &i : children) {
            i = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode *root;
    int wordcounter{0};

    Trie();
    bool insert(const std::string &word);
    bool search(const std::string &word);
    bool deleteWord(const std::string &word);
    void displayContent();
    int get_trie_size() const;

    Vector fuzzySearch(const std::string& prefix);
    Vector partialWordSearch(const std::string& suffix);
    Vector misspelledWordSearch(const std::string& word);

private:
    static char tolower(char c);
    bool isEmpty(TrieNode *node);
    bool remove(TrieNode* &node, const std::string &word, int depth);
    void displayContentHelper(TrieNode *node, const std::string& prefix);
    void gatherAllWords(TrieNode *node, const std::string& currentWord, Vector& allWords);
    void fuzzySearchRecursive(TrieNode* node, const std::string& currentPrefix, const std::string& targetPrefix, Vector& result);
    void misspelledWordSearchHelper(TrieNode* node, const std::string& word, const std::string& current, Vector& result);
    bool isOneEditDistance(const std::string& word1, const std::string& word2);
};

#endif // TRIE_H
