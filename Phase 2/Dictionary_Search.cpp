#include "Dictionary_Search.h"

Dictionary_Search::Dictionary_Search() = default;

void Dictionary_Search::indexCorpus(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string word;

    if (!file.is_open()) {
        std::cout << "Error opening file." << std::endl;
        return;
    }

    while (std::getline(file, word)) { trie.insert(word); }

    file.close();

    std::cout << "Corpus indexed successfully." << std::endl;
}

Vector Dictionary_Search::fuzzySearch(const std::string& searchTerm) { return trie.fuzzySearch(searchTerm); }

Vector Dictionary_Search::misspelledWordSearch(const std::string& searchTerm) { return trie.misspelledWordSearch(searchTerm); }

Vector Dictionary_Search::partialWordSearch(const std::string& searchTerm) { return trie.partialWordSearch(searchTerm); }

// Vector For The 4 Searches

void Dictionary_Search::performSearch() {
    while (true) {
        int choice{-1};
        std::string searchTerm{""};

        std::cout << "Menu : " << std::endl
                  << std::endl
                  << "1) Show The Trie Data Structure " << std::endl
                  << "2) Single Word Search "<<std::endl
                  << "3) Multiple Word Search "<<std::endl
                  << "4) Partial Word Search(Prefix) "<<std::endl
                  << "5) Fuzzy Search " << std::endl
                  << "6) Misspelled Word Search " << std::endl
                  << "7) Partial Word Search(Suffix) " << std::endl
                  << "8) Wildcard Search "<<std::endl
                  << "9) Exit The Program " << std::endl
                  << "Enter Your Choice Here: ";
        std::cin >> choice;

        auto start = std::chrono::high_resolution_clock::now();
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

        switch (choice) {
            case 1: {
                int choice_1{-1};
                std::cout << "Trie Capabilities Menu: " << std::endl
                          << "1.1) Display The Trie Data Structure " << std::endl
                          << "1.2) Add Single Element " << std::endl
                          << "1.3) Search for element existence " << std::endl
                          << "1.4) Delete element " << std::endl
                          << "Enter Your Choice: ";
                std::cin >> choice_1;

                switch (choice_1) {
                    case 1:{
                        start = std::chrono::high_resolution_clock::now();
                        std::cout<<"Here is the Trie Content : "<<std::endl;
                        trie.displayContent();
                        end = std::chrono::high_resolution_clock::now();
                        duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
                        std::cout << "Time taken by this function: " << duration.count() << " seconds" << std::endl;
                        std::cout << "Number of words inside the folder: " << trie.get_trie_size() << std::endl;
                        break;
                    }
                    case 2: {
                        std::string tempword{""};
                        std::cout << "Enter The Word You Want To Insert: ";
                        std::cin >> tempword;
                        std::cout<<std::endl;
                        bool success = trie.insert(tempword);
                        (success) ? std::cout << "Word inserted successfully" << std::endl : std::cout << "Word already exists" << std::endl;
                        break;
                    }
                    case 3: {
                        std::string tempword{""};
                        std::cout << "Enter the Word You Want to Search for: ";
                        std::cin >> tempword;
                        std::cout<<std::endl;
                        bool result = trie.search(tempword);
                        (result) ?std::cout<<"Word Founded Elhamdullah "<<std::endl : std::cout<<"Word Isn't Founded In The Corpus"<<std::endl;
                        break;
                    }
                    case 4: {
                        std::string tempword{""};
                        std::cout << "Enter the Word You Want to Delete: ";
                        std::cin >> tempword;
                        std::cout<<std::endl;
                        bool success = trie.deleteWord(tempword);
                        (success) ? std::cout << "Word deleted successfully" << std::endl : std::cout << "Word isn't founded aslun in the corpus " << std::endl;

                        break;
                    }
                    default:
                        std::cout << "Invalid choice. Try again." << std::endl;
                        std::cout<<std::endl;
                        break;
                }
                break;
            }

            //Case 2 => 4

            case 5: {
                std::cout << "Enter Your Input For The Fuzzy Search: ";
                std::cin >> searchTerm;
                std::cout<<std::endl;
                Vector fuzzysearchResult = fuzzySearch(searchTerm);
                fuzzysearchResult.display();
                std::cout<<std::endl;
                break;
            }

            case 6: {
                std::cout << "Enter Your Input For The Misspelled Word Search: ";
                std::cin >> searchTerm;
                std::cout<<std::endl;
                Vector misspelledsearchResult=misspelledWordSearch(searchTerm);
                misspelledsearchResult.display();
                std::cout<<std::endl;
                break;
            }

            case 7: {
                std::cout << "Enter Your Input For The Partial Word Search(Suffix): ";
                std::cin >> searchTerm;
                std::cout<<std::endl;
                Vector partialwordsearchResult = partialWordSearch(searchTerm);
                partialwordsearchResult.display();
                std::cout<<std::endl;
                break;
            }

            //Case 8

            case 9:{
                std::cout << "Bye Bye! Program Will Terminate Now." << std::endl;
                return;
            }
            default:{
                std::cout << "You have entered the wrong choice. Try again." << std::endl;
                break;
            }
        }

    }
}
