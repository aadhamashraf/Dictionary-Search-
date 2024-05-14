#include "Vector.h"

Vector::Vector() : array(nullptr), size(0), capacity(0) {}

void Vector::push_back(const std::string& item) {
    if (size >= capacity) {
        capacity = (capacity == 0) ? 1 : capacity * 2;
        std::string* newArray = new std::string[capacity];
        for (int i = 0; i < size; ++i) { newArray[i] = array[i];}
        delete[] array;
        array = newArray;
    }

    array[size++] = item;
}

void Vector::display() const {
    std::cout << "[ ";
    for (int i = 0; i < size; ++i) { std::cout << array[i] << "  "; }
    std::cout << " ]" << std::endl;
}

Vector::~Vector() {
    delete[] array;
    array = nullptr;
}
