#pragma once
#include <iostream>


class Vector {
private:
    std::string * array;
    int size;
    int capacity;

public:
    Vector();
    void push_back(const std::string& item);
    void display() const;
    ~Vector();

};

