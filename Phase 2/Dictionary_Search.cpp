#include "Dictionary_Search.h"

Dictionary_Search::Dictionary_Search() = default;

void Dictionary_Search::indexCorpus(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string word;

    if (!file.is_open()) {
        std::cout << "Error opening file." << std::endl;
        return;
    }

    while ( std::getline(file, word) ) {
        trie.insert(word);
    }

    file.close();

    std::cout << "Corpus indexed successfully." << std::endl;
}

Vector Dictionary_Search::fuzzySearch(const std::string& searchTerm) {
    return trie.fuzzySearch(searchTerm);
}

Vector Dictionary_Search::misspelledWordSearch(const std::string& searchTerm) {
    return trie.misspelledWordSearch(searchTerm);
}

Vector Dictionary_Search::partialWordSearch(const std::string& searchTerm) {
    return trie.partialWordSearch(searchTerm);
}

Vector Dictionary_Search::wildcardSearch(const std::string& searchTerm) {
    return trie.wildcardSearch(searchTerm);
}

void Dictionary_Search::performSearch() {
    while (true) {
        int choice {-1};
        std::string searchTerm {""};
        Vector searchResult;

        std::cout << "Menu : " << std::endl
                  << "1) Show The Trie Data Structure " << std::endl
                  << "2) Fuzzy Search " << std::endl
                  << "3) Misspelled Word Search " << std::endl
                  << "4) Partial Word Search(Suffix) " << std::endl
                  << "5) Wildcard Search " << std::endl
                  << "6) Exit The Program " << std::endl
                  << "Enter Your Choice Here: ";
        std::cin >> choice;

        auto start = std::chrono::high_resolution_clock::now();
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

        switch (choice) {
            case 1: {
                int choice_1  {-1};
                std::cout << "Trie Capabilities Menu: " << std::endl
                          << "1.1) Display The Trie Data Structure " << std::endl
                          << "1.2) Add Single Element " << std::endl
                          << "1.3) Search for element existence " << std::endl
                          << "1.4) Delete element " << std::endl
                          << "Enter Your Choice: ";
                std::cin >> choice_1;

                switch (choice_1) {
                    case 1:
                        start = std::chrono::high_resolution_clock::now();
                        trie.displayContent();
                        end = std::chrono::high_resolution_clock::now();
                        duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
                        std::cout << "Time taken by this function: " << duration.count() << " seconds" << std::endl;
                        std::cout << "Number of words inside the folder: " << trie.get_trie_size() << std::endl;
                        break;
                    case 2: {
                        std::string tempword {""};
                        std::cout << "Enter The Word You Want To Insert: ";
                        std::cin >> tempword;
                        start = std::chrono::high_resolution_clock::now();
                        trie.insert(tempword);
                        end = std::chrono::high_resolution_clock::now();
                        duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
                        std::cout << "Time taken by this function: " << duration.count() << " seconds" << std::endl;
                        break;
                    }
                    case 3: {
                        std::string tempword{""};
                        std::cout << "Enter the Word You Want to Search for: ";
                        std::cin >> tempword;
                        start = std::chrono::high_resolution_clock::now();
                        bool result = trie.search(tempword);
                        end = std::chrono::high_resolution_clock::now();
                        duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
                        std::cout << (result ? "Existed" : "Not Existed") << std::endl;
                        std::cout << "Time taken by this function: " << duration.count() << " seconds" << std::endl;
                        break;
                    }
                    case 4: {
                        std::string tempword{""};
                        std::cout << "Enter the Word You Want to Delete: ";
                        std::cin >> tempword;
                        start = std::chrono::high_resolution_clock::now();
                        trie.deleteWord(tempword);
                        end = std::chrono::high_resolution_clock::now();
                        duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
                        std::cout << "Time taken by this function: " << duration.count() << " seconds" << std::endl;
                        break;
                    }
                    default:
                        std::cout << "Invalid choice. Try again." << std::endl;
                        break;
                }
                break;
            }
            case 2:
                std::cout << "Enter Your Input For The Fuzzy Search: ";
                std::cin >> searchTerm;
                start = std::chrono::high_resolution_clock::now();
                searchResult = fuzzySearch(searchTerm);
                end = std::chrono::high_resolution_clock::now();
                duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
                break;

            case 3:
                std::cout << "Enter Your Input For The Misspelled Word Search: ";
                std::cin >> searchTerm;
                start = std::chrono::high_resolution_clock::now();
                searchResult = misspelledWordSearch(searchTerm);
                end = std::chrono::high_resolution_clock::now();
                duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
                break;

            case 4:
                std::cout << "Enter Your Input For The Partial Word Search(Suffix): ";
                std::cin >> searchTerm;
                start = std::chrono::high_resolution_clock::now();
                searchResult = partialWordSearch(searchTerm);
                end = std::chrono::high_resolution_clock::now();
                duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
                break;

            case 5:
                std::cout << "Enter Your Input For The Wildcard Search: ";
                std::cin >> searchTerm;
                start = std::chrono::high_resolution_clock::now();
                searchResult = wildcardSearch(searchTerm);
                end = std::chrono::high_resolution_clock::now();
                duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
                break;

            case 6:
                std::cout << "Bye Bye! Program Will Terminate Now." << std::endl;
                return;

            default:
                std::cout << "You have entered the wrong choice. Try again." << std::endl;
                break;
        }

        if (choice != 1 && choice != 6) {
            std::cout << "Time taken by this function: " << duration.count() << " seconds" << std::endl;
            std::cout << "Your Result: " << std::endl;
            searchResult.display();
            std::cout << std::endl;
        }
    }
}
