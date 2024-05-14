#include "Trie.h"
#include "Vector.h"

Trie::Trie() { root = new TrieNode();}

void Trie::insert(const std::string &word) {
    TrieNode *current = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (!current->children[index]) {
            current->children[index] = new TrieNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = true;
}

bool Trie::search(const std::string &word) {
    TrieNode *current = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (!current->children[index]) { return false;}
        current = current->children[index];
    }
    return current && current->isEndOfWord;
}

bool Trie::isEmpty(TrieNode *node) {
    for (int i = 0; i < ALPHABET_SIZE; ++i) { if (node->children[i]) { return false;} }
    return true;
}

TrieNode* Trie::remove(TrieNode *node, const std::string &word, int depth) {
    
    if (!node) { return nullptr;}

    if (depth == word.size()) { if (node->isEndOfWord) { node->isEndOfWord = false;  }

        if (isEmpty(node)) {
            delete node;
            node = nullptr;
        }

        return node;
    }

    int index = word[depth] - 'a';
    node->children[index] = remove(node->children[index], word, depth + 1);

    if (isEmpty(node) && !node->isEndOfWord) {
        delete node;
        node = nullptr;
    }

    return node;
}

void Trie::deleteWord(const std::string &word) {remove(root, word);}
