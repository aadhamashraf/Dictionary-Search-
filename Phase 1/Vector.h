#pragma once

#include <iostream>
#include <string>

class Vector {
private:
    std::string* array;
    int size;
    int capacity;

public:
    Vector();
    void push_back(const std::string& item);
    void display() const;
    ~Vector();

};

