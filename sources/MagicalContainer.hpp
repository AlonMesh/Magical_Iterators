#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP
#include <iostream>
#include "AscendingIterator.hpp"

class MagicalContainer
{
private:
    int *elements;    // Pointer to the dynamic array
    int length;       // Current number of elements in the container
    int fullCapacity; // Current capacity of the dynamic array

public:
    MagicalContainer()
    {
        fullCapacity = 10; // Initial capacity of the container
        length = 0;        // Initially, the container is empty
        elements = new int[fullCapacity];
    }

    ~MagicalContainer()
    {
        delete[] elements;
    }

    // Add an element to the container
    void addElement(int element);

    // Remove an element from the container
    void removeElement(int element);

    // Get the size of the container
    int size() const;

    class AscendingIterator
    {
    public:
        // Default constructor
        AscendingIterator(MagicalContainer &container);

        // Copy constructor
        AscendingIterator(const AscendingIterator &other);

        // Destructor
        ~AscendingIterator();

        // Assignment operator
        bool operator=(const AscendingIterator &other);

        // Equality comparison
        bool operator==(const AscendingIterator &other);

        // Inequality comparison
        bool operator!=(const AscendingIterator &other);

        // GT comparison
        bool operator<(const AscendingIterator &other);

        // LT comparison
        bool operator>(const AscendingIterator &other);

        // Dereference operator
        int &operator*();

        // Pre-increment operator
        AscendingIterator &operator++();

        // begin(type)
        static AscendingIterator begin();

        // end(type)
        static AscendingIterator end();
    };
};

#endif