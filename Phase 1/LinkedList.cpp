#include "LinkedList.h"

LinkedList::LinkedList(){ head = nullptr; }

void LinkedList::insert_at_end(std::string value)
{
	Node* newInserted = new Node(value);
	if (head == nullptr) { head = newInserted; }
	else 
	{
		Node* tempfetcher = head;
		while (tempfetcher->next != nullptr) { tempfetcher = tempfetcher->next; }
		tempfetcher->next = newInserted , newInserted->next = nullptr;
	}
}

void LinkedList::display()
{
	Node* temp = head;
	while (temp != nullptr) {
		if (temp->val != " ") { std::cout << temp->val << " -> "; }
		temp = temp->next;
	}
	std::cout << "nullptr" << std::endl;
}

bool LinkedList::search(const std::string& word)
{
	Node* temp = head;
	while (temp != nullptr) {
		if (temp->val == word) {return true;}
		temp = temp->next;
	}
	return false;
}

Vector LinkedList::start_with(const std::string& prefix) {
    Vector matchy;
    Node* current = head;

    while (current != nullptr) {
	bool Flag = true;
        for (size_t i = 0; prefix[i] != '\0'; ++i) {
            if (current->val[i] == '\0' || current->val[i] != prefix[i]) {
                Flag = false;
                break;
            }
        }
        if (Flag) { matchy.push_back(current->val);}
        current = current->next;
    }

    return matchy;
}



Vector LinkedList::end_with(const std::string& suffix) {
    Vector matchingWords;
    Node* current = head;

    while (current) {
        size_t suffixLength = 0;
        while (suffix[suffixLength] != '\0') {
            ++suffixLength;
        }

        size_t wordLength = 0;
        while (current->val[wordLength] != '\0') {
            ++wordLength;
        }

        if (wordLength >= suffixLength) {
            bool endsWith = true;
            for (size_t i = 0; i < suffixLength; ++i) {
                if (current->val[wordLength - suffixLength + i] != suffix[i]) {
                    endsWith = false;
                    break;
                }
            }
            if (endsWith) {
                matchingWords.pushbackV3(current->val);
            }
        }
        current = current->next;
    }
    return matchingWords;
}

Vector LinkedList::find(const std::string& substring) {
    Vector matchingWords;
    Node* current = head;

    while (current) {
        size_t substringLength = 0;
        while (substring[substringLength] != '\0') {
            ++substringLength;
        }

        size_t wordLength = 0;
        while (current->val[wordLength] != '\0') { ++wordLength; }

        for (size_t i = 0; i <= wordLength - substringLength; ++i) {
            bool found = true;
            for (size_t j = 0; j < substringLength; ++j) {
                if (current->val[i + j] != substring[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                matchingWords.pushbackV3(current->val);
               break; 
            }
        }
        current = current->next;
    }
    return matchingWords;
}
