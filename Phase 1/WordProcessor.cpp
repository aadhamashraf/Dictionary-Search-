#include "WordProcessor.h"

WordProcessor::WordProcessor(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::cout << "File Opened Successfully .. Words Are Uploading Now " << std::endl;
        std::string word;
        while (getline(file, word)) {
            big_disaster.insert_at_end(word);
        }
        file.close();
    }
    else { std::cout << "Error while opening this (27 * 50 ) file ." << std::endl; }
}

void WordProcessor::showLinkedList() {
    big_disaster.display();
    std::cout << std::endl;
}

void WordProcessor::searchWord() {
    std::cout << "Enter the word you want to search for here : ";
    std::cin >> word_to_search;
    std::cout << std::endl;

    answer_search = (big_disaster.search(word_to_search)) ? "Founded elhamdulah " : "Not founded ";
    std::cout << "Our Case Here Will Be: " << answer_search << std::endl << std::endl;
}

void WordProcessor::startWithPrefix() {
    std::cout << "Enter Here The Prefix : ";
    std::cin >> prefix;
    std::cout << std::endl;

    Vector start_with_matching_words = big_disaster.start_with(prefix);
    std::cout << "Matching Words With The Passed Prefix : " << std::endl;
    start_with_matching_words.display();
    std::cout << std::endl;
}

void WordProcessor::endWithSuffix() {
    std::cout << "Enter Here The Suffix : ";
    std::cin >> suffix;
    std::cout << std::endl;

    Vector end_with_matching_words = big_disaster.end_with(suffix);
    std::cout << "Matching Words With The Passed Suffix : " << std::endl;
    end_with_matching_words.display();
    std::cout << std::endl;
}

void WordProcessor::findSubstring() {
    std::cout << "Enter Here The Substring : ";
    std::cin >> substring;
    std::cout << std::endl;

    Vector find_substring_matching_words = big_disaster.find(substring);
    std::cout << "Matching Words With The Passed Substring : " << std::endl;
    find_substring_matching_words.display();
    std::cout << std::endl;
}

void WordProcessor::capabilitiesMenu() {
    int choice{ -1 };

    while (true) {
        std::cout << "Menu Of Our Features : " << std::endl
            << "1) Show The Feeded Linked List " << std::endl
            << "2) Search For Word Exist " << std::endl
            << "3) Search For Words Matchy With Passed Prefix " << std::endl
            << "4) Search For Words Matchy With Passed Suffix " << std::endl
            << "5) Search For Words Matchy With Passed Substring " << std::endl
            << "6) Exit" << std::endl;

        std::cout << "Chocie : ";
        std::cin >> choice;
        std::cout << std::endl;

        switch (choice) {
        case 1:
            showLinkedList();
            break;
        case 2:
            searchWord();
            break;
        case 3:
            startWithPrefix();
            break;
        case 4:
            endWithSuffix();
            break;
        case 5:
            findSubstring();
            break;
        case 6:
            std::cout << "Bye Bye...." << std::endl;
            return;
        default:
            std::cout << "Invalid choice, please try again." << std::endl;
        }
    }
}
