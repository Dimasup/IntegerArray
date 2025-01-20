// main.cpp
#include "IntegerArray.h"
#include <iostream>

int main() {
    try {
        // Create an array of size 5
        IntegerArray arr(5);

        // Fill the array with values
        for (size_t i = 0; i < arr.getSize(); ++i) {
            arr[i] = static_cast<int>(i + 1);
        }

        // Print the initial array
        std::cout << "Initial array: ";
        for (size_t i = 0; i < arr.getSize(); ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        // Resize the array to a larger size
        arr.resize(7);
        arr[5] = 6;
        arr[6] = 7;
        std::cout << "After resizing (larger): ";
        for (size_t i = 0; i < arr.getSize(); ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        // Insert an element
        arr.insert(3, 99);
        std::cout << "After inserting 99 at index 3: ";
        for (size_t i = 0; i < arr.getSize(); ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        // Remove an element
        arr.remove(2);
        std::cout << "After removing element at index 2: ";
        for (size_t i = 0; i < arr.getSize(); ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
