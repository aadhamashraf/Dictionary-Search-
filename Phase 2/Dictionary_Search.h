//
// Created by Ashraf on 16/05/2024.
//
#ifndef PHASE_2_DICTIONARY_SEARCH_H
#define PHASE_2_DICTIONARY_SEARCH_H

#include "Trie.h"
#include "Vector.h"
#include <iostream>
#include <fstream>
#include <chrono>

class Dictionary_Search {
public:
    Trie trie;

    Dictionary_Search();

    void indexCorpus(const std::string& filePath);

    Vector fuzzySearch(const std::string& searchTerm);

    Vector misspelledWordSearch(const std::string& searchTerm);

    Vector partialWordSearch(const std::string& searchTerm);

    Vector wildcardSearch(const std::string& searchTerm);

    void performSearch();
};


#endif //PHASE_2_DICTIONARY_SEARCH_H
