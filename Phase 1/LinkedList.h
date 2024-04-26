#pragma once
#include<iostream>
#include"Vector.h"

struct Node {
	
	std::string val{ "" };
	Node* next  { nullptr };

	Node(std::string value) { val = value; }

};

class LinkedList
{
private:
	Node* head{};
public:
	LinkedList();
	void insert_at_end(std::string value);
	void display();
	bool search(const std::string& word);
	Vector start_with(const std::string& prefix);
	Vector end_with(const std::string& suffix);
	Vector find(const std::string& substring);
};

