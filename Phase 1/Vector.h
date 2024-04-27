#pragma once
#include <iostream>


class Vector {
private:
    std::string * array{nullptr};
    int size{0};
    int capacity{0};

public:
    Vector();
    void push_back(const std::string& item);
    void display() const;
    ~Vector();

};

