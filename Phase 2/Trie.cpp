#include "Trie.h"
#include "Vector.h"

/* Basic Trie Implementations Functions */

Trie::Trie() {
    root = new TrieNode();
}

char Trie::tolower(char c) {
    return (c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c;
}

int Trie::get_trie_size() const {
    return wordcounter;
}

bool Trie::insert(const std::string &word) {
    TrieNode *current = root;
    for (char ch : word) {
        ch = tolower(ch);
        int index = ch - 'a';
        if (!current->children[index]) {
            current->children[index] = new TrieNode();
        }
        current = current->children[index];
    }

    if (current->isEndOfWord) {
        return false;
    }
    current->isEndOfWord = true;
    wordcounter++;
    return true;
}

bool Trie::search(const std::string &word) {
    TrieNode *current = root;
    for (char ch : word) {
        ch = tolower(ch);
        int index = ch - 'a';
        if (!current->children[index]) {
            return false;
        }
        current = current->children[index];
    }
    return current && current->isEndOfWord;
}

bool Trie::isEmpty(TrieNode* node) {
    for (auto &i : node->children) {
        if (i) {
            return false;
        }
    }
    return true;
}

bool Trie::remove(TrieNode* &node, const std::string &word, int depth) {
    if (!node) {
        return false;
    }

    if (depth == word.size()) {
        if (node->isEndOfWord) {
            node->isEndOfWord = false;
            if (isEmpty(node)) {
                delete node;
                node = nullptr;
            }
            wordcounter--;
            return true;
        }
        return false;
    }

    int index = word[depth] - 'a';
    bool removed = remove(node->children[index], word, depth + 1);

    if (removed && node->children[index] == nullptr && isEmpty(node) && !node->isEndOfWord) {
        delete node;
        node = nullptr;
    }

    return removed;
}

bool Trie::deleteWord(const std::string &word) {
    return remove(root, word, 0);
}

void Trie::displayContentHelper(TrieNode* node, const std::string& prefix) {
    if (node->isEndOfWord) {
        std::cout << prefix << std::endl;
    }
    for (int i = 0; i < 26; ++i) {
        if (node->children[i]) {
            displayContentHelper(node->children[i], prefix + char('a' + i));
        }
    }
}

void Trie::displayContent() {
    displayContentHelper(root, "");
}

/* Advanced Search Implementation */

Vector Trie::fuzzySearch(const std::string& prefix) {
    Vector result;
    TrieNode* current = root;
    std::string lowercasePrefix;

    for (char ch : prefix) {
        lowercasePrefix += tolower(ch);
    }

    fuzzySearchRecursive(current, "", lowercasePrefix, result);

    return result;
}

void Trie::fuzzySearchRecursive(TrieNode* node, const std::string& currentPrefix, const std::string& targetPrefix, Vector& result) {
    if (!node) {
        return;
    }

    if (targetPrefix.empty()) {
        if (node->isEndOfWord) {
            result.push_back(currentPrefix);
        }
        for (int i = 0; i < 26; ++i) {
            if (node->children[i]) {
                fuzzySearchRecursive(node->children[i], currentPrefix + char('a' + i), targetPrefix, result);
            }
        }
    } else {
        char ch = targetPrefix[0];
        if (ch == '?') {
            for (int i = 0; i < 26; ++i) {
                if (node->children[i]) {
                    fuzzySearchRecursive(node->children[i], currentPrefix + char('a' + i), targetPrefix.substr(1), result);
                }
            }
        } else {
            int index = ch - 'a';
            if (node->children[index]) {
                fuzzySearchRecursive(node->children[index], currentPrefix + ch, targetPrefix.substr(1), result);
            }
        }
    }
}

void Trie::gatherAllWords(TrieNode* node, const std::string& currentWord, Vector& allWords) {
    if (node->isEndOfWord) {
        allWords.push_back(currentWord);
    }
    for (int i = 0; i < 26; ++i) {
        if (node->children[i]) {
            gatherAllWords(node->children[i], currentWord + char('a' + i), allWords);
        }
    }
}

Vector Trie::partialWordSearch(const std::string& suffix) {
    Vector allWords, result;

    gatherAllWords(root, "", allWords);

    for (size_t i = 0; i < allWords.getSize(); ++i) {
        const std::string& word = allWords[i];
        if (word.size() >= suffix.size()) {
            bool matches = true;
            for (size_t j = 0; j < suffix.size(); ++j) {
                if (word[word.size() - suffix.size() + j] != suffix[j]) {
                    matches = false;
                    break;
                }
            }
            if (matches) {
                result.push_back(word);
            }
        }
    }

    return result;
}

void Trie::misspelledWordSearchHelper(TrieNode* node, const std::string& word, const std::string& current, Vector& result) {
    if (!node) {
        return;
    }
    if (word.empty() && node->isEndOfWord) {
        result.push_back(current);
    }
    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            char ch = 'a' + i;
            std::string next = current + ch;
            std::string nextWord = word;
            if (!nextWord.empty() && nextWord[0] == ch) {
                nextWord = nextWord.substr(1);
            }
            misspelledWordSearchHelper(node->children[i], nextWord, next, result);
        }
    }
}

Vector Trie::misspelledWordSearch(const std::string& word) {
    Vector result;
    Vector allWords;
    gatherAllWords(root, "", allWords);

    for (size_t i = 0; i < allWords.getSize(); ++i) {
        const std::string& dictWord = allWords[i];
        if (isOneEditDistance(word, dictWord) || word == dictWord) {
            result.push_back(dictWord);
        }
    }
    return result;
}

bool Trie::isOneEditDistance(const std::string& word1, const std::string& word2) {
    int m = word1.length(), n = word2.length();
    if (abs(m - n) > 1) return false;

    int i = 0, j = 0, mismatch = 0;
    while (i < m && j < n) {
        if (word1[i] != word2[j]) {
            mismatch++;
            if (mismatch > 1) return false;
            if (m > n) i++;
            else if (m < n) j++;
            else { i++; j++; }
        }
        else {
            i++; j++;
        }
    }
    if (i < m || j < n) mismatch++;
    return mismatch == 1;
}
