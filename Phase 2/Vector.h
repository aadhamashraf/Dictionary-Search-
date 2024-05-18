// Vector.h

#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <string>

class Vector {
private:
    std::string* array;
    size_t size , capacity;

public:
    Vector();

    void display()const;
    void push_back(const std::string& item);
    std::string& operator[](size_t index);
    const std::string& operator[](size_t index) const;
    size_t getSize() const;

    ~Vector();

};

#endif // VECTOR_H
