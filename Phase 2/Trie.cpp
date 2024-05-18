#include "Trie.h"
#include "Vector.h"

char Trie::tolower(char c) { return  (c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c;}

Trie::Trie() { root = new TrieNode(); }

void Trie::insert(const std::string &word) {
    TrieNode *current = root;
    for (char ch : word) {
        ch = tolower(ch);
        int index = ch - 'a';
        if (!current->children[index]) {
            current->children[index] = new TrieNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = true;
    wordcoutner+=1;
}

int Trie::get_trie_size() {return wordcoutner;}

bool Trie::search(const std::string &word) {
    TrieNode *current = root;
    for (char ch : word) {
        ch = tolower(ch);
        int index = ch - 'a';
        if (!current->children[index]) { return false; }
        current = current->children[index];
    }
    return current && current->isEndOfWord;
}

bool Trie::isEmpty(TrieNode *node) {
    for (int i = 0; i < 26; ++i) { if (node->children[i]) { return false; } }
    return true;
}

TrieNode* Trie::remove(TrieNode *node, const std::string &word, int depth) {
    if (!node) { return nullptr; }

    if (depth == word.size()) {
        if (node->isEndOfWord) { node->isEndOfWord = false; }

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

void Trie::deleteWord(const std::string &word) { remove(root, word); }

void Trie::displayContentHelper(TrieNode* node, std::string prefix) {
    if (node->isEndOfWord) { std::cout << prefix << std::endl; }
    for (int i = 0; i < 26; ++i) { if (node->children[i]) { displayContentHelper(node->children[i], prefix + char('a' + i)); } }
}

void Trie::displayContent() { displayContentHelper(root, ""); }

void Trie::searchWords(TrieNode* node, const std::string& prefix, Vector &result) {
    if (!node) { return; }
    if (node->isEndOfWord) { result.push_back(prefix); }
    for (int i = 0; i < 26; ++i) { if (node->children[i]) { searchWords(node->children[i], prefix + char('a' + i), result); } }
}

Vector Trie::fuzzySearch(const std::string& prefix) {
    Vector result;
    TrieNode* current = root;
    std::string lowercasePrefix;

    for (char ch : prefix) {
        lowercasePrefix += tolower(ch);
        int index = ch - 'a';
        if (!current->children[index]) { return result; }
        current = current->children[index];
    }
    searchWords(current, lowercasePrefix, result);
    return result;
}

void Trie::partialWordSearchHelper(TrieNode* node, const std::string& suffix, const std::string& current, Vector& result, int maxLength) {
    if (!node) {
        return;
    }
    if (suffix.empty() && node->isEndOfWord) {
        result.push_back(current);
    }
    for (int i = 0; i < 26; ++i) {
        if (node->children[i]) {
            char ch = 'a' + i;
            std::string next = current + ch;
            if (suffix.empty() || suffix.find(next) == 0 && next.size() <= maxLength) {
                partialWordSearchHelper(node->children[i], suffix, next, result, maxLength);
            }
        }
    }
}

Vector Trie::partialWordSearch(const std::string& suffix) {
    Vector result;
    partialWordSearchHelper(root, suffix, "", result, suffix.size());
    return result;
}

void Trie::misspelledWordSearchHelper(TrieNode* node, const std::string& word, const std::string& current, Vector& result) {
    if (!node) {
        return;
    }
    if (word.empty() && node->isEndOfWord) {
        result.push_back(current);
    }
    for (int i = 0; i < 26; ++i) {
        if (node->children[i]) {
            char ch = 'a' + i;
            std::string next = current + ch;
            std::string nextWord = word;
            if (nextWord[0] == ch) {
                nextWord = nextWord.substr(1);
            }
            misspelledWordSearchHelper(node->children[i], nextWord, next, result);
        }
    }
}

Vector Trie::misspelledWordSearch(const std::string& word) {
    Vector result;
    misspelledWordSearchHelper(root, word, "", result);
    return result;
}
