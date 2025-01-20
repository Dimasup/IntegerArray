#pragma once
// IntegerArray.h
#ifndef INTEGER_ARRAY_H
#define INTEGER_ARRAY_H

#include <stdexcept>
#include <iostream>

class IntegerArray {
private:
    int* data;
    size_t size;

    void validateIndex(size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
    }

public:
    // Constructor
    IntegerArray(size_t initialSize);

    // Copy constructor
    IntegerArray(const IntegerArray& other);

    // Destructor
    ~IntegerArray();

    // Access element by index
    int& operator[](size_t index);

    // Resize the array
    void resize(size_t newSize);

    // Insert an element at a specific index
    void insert(size_t index, int value);

    // Remove an element at a specific index
    void remove(size_t index);

    // Get the size of the array
    size_t getSize() const;
};

#endif