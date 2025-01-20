// IntegerArray.cpp
#include "IntegerArray.h"
#include <algorithm>

// Constructor
IntegerArray::IntegerArray(size_t initialSize) : size(initialSize) {
    if (size == 0) {
        throw std::invalid_argument("Size cannot be zero");
    }
    data = new int[size] {}; // Initialize with zeros
}

// Copy constructor
IntegerArray::IntegerArray(const IntegerArray& other) : size(other.size) {
    data = new int[size];
    std::copy(other.data, other.data + size, data);
}

// Destructor
IntegerArray::~IntegerArray() {
    delete[] data;
}

// Access element by index
int& IntegerArray::operator[](size_t index) {
    validateIndex(index);
    return data[index];
}

// Resize the array
void IntegerArray::resize(size_t newSize) {
    if (newSize == 0) {
        throw std::invalid_argument("Size cannot be zero");
    }
    int* newData = new int[newSize] {};
    size_t copySize = std::min(size, newSize);
    std::copy(data, data + copySize, newData);
    delete[] data;
    data = newData;
    size = newSize;
}

// Insert an element at a specific index
void IntegerArray::insert(size_t index, int value) {
    if (index > size) {
        throw std::out_of_range("Index out of bounds");
    }
    resize(size + 1);
    for (size_t i = size - 1; i > index; --i) {
        data[i] = data[i - 1];
    }
    data[index] = value;
}

// Remove an element at a specific index
void IntegerArray::remove(size_t index) {
    validateIndex(index);
    for (size_t i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    resize(size - 1);
}

// Get the size of the array
size_t IntegerArray::getSize() const {
    return size;
}
