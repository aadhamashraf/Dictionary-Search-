#ifndef WORDPROCESSOR_H
#define WORDPROCESSOR_H

#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "Vector.h"

class WordProcessor {

private:
    LinkedList big_disaster;
    std::string prefix{ "" }, suffix{ "" }, word_to_search{ "" }, answer_search{ "" }, substring{ "" };

public:
    WordProcessor(const std::string& filename);

    void showLinkedList();
    void searchWord();
    void startWithPrefix();
    void endWithSuffix();
    void findSubstring();
    void capabilitiesMenu();
};

#endif
