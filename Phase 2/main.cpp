#include <iostream>
#include "Dictionary_Search.h"

int main() {

    std::string filePath = "C:\\Users\\Ashraf\\CLionProjects\\Phase 2\\corpus.txt";

    Dictionary_Search searchEngine;
    searchEngine.indexCorpus(filePath);
    searchEngine.performSearch();

    return 0;
}
