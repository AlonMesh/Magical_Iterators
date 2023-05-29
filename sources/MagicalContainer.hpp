#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP
#include <iostream>
using namespace std;
#include <vector>

namespace ariel
{
    class MagicalContainer
    {
        class Iterator
        {
        public:
            int* currentElement;

            Iterator() : currentElement(nullptr) {} // Initialize currentElement to nullptr

            virtual ~Iterator() = default;
            virtual int &operator*() = 0;
            virtual Iterator &operator++() = 0;

            Iterator(const Iterator&) = delete; // Disable copy constructor
            Iterator& operator=(const Iterator&) = delete; // Disable copy assignment operator
            Iterator(Iterator&&) = delete; // Disable move constructor
            Iterator& operator=(Iterator&&) = delete; // Disable move assignment operator
        };

        vector<int> elements;
        vector<Iterator*> iterators; // Collection of iterators

    public:
        MagicalContainer();

        ~MagicalContainer();

        MagicalContainer(const MagicalContainer&) = default;
        MagicalContainer& operator=(const MagicalContainer&) = default;

        MagicalContainer(MagicalContainer&&) = default;
        MagicalContainer& operator=(MagicalContainer&&) = default;

        // Add an element to the container
        void addElement(int element);

        // Remove an element from the container
        void removeElement(int element);

        // Get the size of the container
        int size() const;

        class AscendingIterator : public Iterator
        {
        private:
            vector<int> sortedVec;
            MagicalContainer *original_container;
            int *currentElement;

        public:
            AscendingIterator();
            AscendingIterator(MagicalContainer &container);
            AscendingIterator(const AscendingIterator &other);
            ~AscendingIterator() override;

            AscendingIterator &operator=(const AscendingIterator &other);

            int &operator*() override;
            AscendingIterator &operator++() override;
            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;

            AscendingIterator begin();
            AscendingIterator end();

            AscendingIterator(const AscendingIterator&&) = delete; // Delete move constructor
            AscendingIterator& operator=(const AscendingIterator&&) = delete; // Delete move assignment operator
        };

        class SideCrossIterator : public Iterator
        {
        private:
            vector<int> sortedVec;
            MagicalContainer *original_container;
            int *currentElement;

        public:
            SideCrossIterator();
            SideCrossIterator(MagicalContainer &container);
            SideCrossIterator(const SideCrossIterator &other);
            ~SideCrossIterator() override;

            SideCrossIterator &operator=(const SideCrossIterator &other);

            int &operator*() override;
            SideCrossIterator &operator++() override;
            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;

            SideCrossIterator begin();
            SideCrossIterator end();

            SideCrossIterator(const SideCrossIterator&&) = delete; // Delete move constructor
            SideCrossIterator& operator=(const SideCrossIterator&&) = delete; // Delete move assignment operator
        };

        class PrimeIterator : public Iterator
        {
        private:
            vector<int> sortedVec;
            MagicalContainer *original_container;
            int *currentElement;

        public:
            PrimeIterator();
            PrimeIterator(MagicalContainer &container);
            PrimeIterator(const PrimeIterator &other);
            ~PrimeIterator() override;

            PrimeIterator &operator=(const PrimeIterator &other);

            int &operator*() override;
            PrimeIterator &operator++() override;
            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;

            PrimeIterator begin();
            PrimeIterator end();

            PrimeIterator(const PrimeIterator&&) = delete; // Delete move constructor
            PrimeIterator& operator=(const PrimeIterator&&) = delete; // Delete move assignment operator
        };
    };
}
#endif