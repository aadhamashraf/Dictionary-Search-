#include<iostream>
#include<fstream>

#include"LinkedList.h"
#include"Vector.h"

int main() {

    LinkedList big_disaster ;
    std::string prefix{ "" }, suffix{ "" }, word_to_search{ "" }, answer_search{ "" } ,substring{ "" };

    //Access the test case file and feed the linked list with the words 
    std::ifstream file("testcase.txt");
    if (file.is_open()) 
    {
        std::cout << "File Opened Successfully .. Words Are Uploding Now " << std::endl;
        std::string word;
        while (getline(file, word)) { big_disaster.insert_at_end(word); }
        file.close();
    }

    else { std::cout << "Error while opening this (27 * 50 ) file ." << std::endl;  }
    
    std::cout << std::endl;
    big_disaster.display();
    std::cout << std::endl;
    
    
    /* First Required (Search Function:)  ~ Done */

    std::cout << "Enter the word you want to search for here : ";
    std::cin >> word_to_search;
    
    answer_search = (big_disaster.search(word_to_search)) ? "Founded elhamdulah " : "Not founded ";
    std::cout << "Our Case Here Wll Be: " << answer_search <<std::endl ;
  
    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - - - - - - - - - - - - - - - - - - - - -*/
    
    /* Second required (start with function:) ~ Done */

    std::cout << "Enter Here The Prefix : ";
    std::cin >> prefix;
    
    Vector start_with_matching_words = big_disaster.start_with(prefix);

    std::cout <<"Matchy Words With The Passed Prefix : " << std::endl;
    start_with_matching_words.display();
    std::cout << std::endl;

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - - - - - - - - - - - - - - - - - - - - -*/

    /* Third required (end with function:) 

    std::cout << "enter the suffix you want to search for: ";
    std::cin >> suffix;
    end_with_matching_words = big_disaster.end_with(suffix);
    std::cout << "words ending with '" << suffix << "': ";
    end_with_matching_words.display();
    std::cout << std::endl;

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - - - - - - - - - - - - - - - - - - - - -*/

    /* Fourth required (find function:) 
   
    std::cout << "enter the substring you want to find: ";
    std::cin >> substring;
    find_matching_words = big_disaster.find(substring);
    std::cout << "words containing '" << substring << "': ";
    find_matching_words.display();
   
   */
}