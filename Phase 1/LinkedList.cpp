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
	Vector matchingWords; 
	Node* current = head; 

	while (current != nullptr) {
		const std::string& enterie = current->val;
		bool startsWithPrefix = true;

		for (size_t i = 0; i < prefix.size(); ++i) {
			if (enterie[i] != prefix[i] || i >= enterie.size()) {
				startsWithPrefix = false;
				break;
			}
		}
		if (startsWithPrefix) { matchingWords.push_back(word); }
		current = current->next; 
	}
	return matchingWords; 
}


Vector LinkedList::find(const std::string& substring)
{
	Vector matchingWords;
	Node* current = head;
	while (current) {
		if (current->val.find(substring) != std::string::npos) {matchingWords.push_back(current->val);}
		current = current->next;
	}
	return matchingWords;
}

Vector LinkedList::end_with(const std::string& suffix) {
	Vector matchingWords;
	Node* current = head;
	while (current) {
		if (current->val.length() >= suffix.length() &&
			current->val.compare(current->val.length() - suffix.length(), suffix.length(), suffix) == 0) {
			matchingWords.push_back(current->val);
		}
		current = current->next;
	}
	return matchingWords;
}
