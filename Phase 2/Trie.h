#ifndef PHASE_2_TRIE_H
#define PHASE_2_TRIE_H

#include <iostream>
#define ALPHABET_SIZE 26

struct TrieNode {

    TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {for (int i = 0; i < ALPHABET_SIZE; ++i) {children[i] = nullptr;}}
};

class Trie {
private:
    TrieNode *root;

public:
    Trie();

    void insert(const std::string &word);

    bool search(const std::string &word);

    bool isEmpty(TrieNode *node);

    TrieNode* remove(TrieNode *node, const std::string &word, int depth = 0);

    void deleteWord(const std::string &word);
};

#endif //PHASE_2_TRIE_H
