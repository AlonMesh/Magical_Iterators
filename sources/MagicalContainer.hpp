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
            virtual ~Iterator() = default;
            virtual int &operator*() = 0;
            virtual Iterator &operator++() = 0;
        };

        vector<int> elements;
        vector<Iterator*> iterators; // Collection of iterators

    public:
        MagicalContainer();

        ~MagicalContainer();

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
            ~AscendingIterator();

            AscendingIterator &operator=(const AscendingIterator &other);

            int &operator*() override;
            AscendingIterator &operator++() override;
            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;

            AscendingIterator begin();
            AscendingIterator end();
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
            ~SideCrossIterator();

            SideCrossIterator &operator=(const SideCrossIterator &other);

            int &operator*() override;
            SideCrossIterator &operator++() override;
            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;

            SideCrossIterator begin();
            SideCrossIterator end();
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
            ~PrimeIterator();

            PrimeIterator &operator=(const PrimeIterator &other);

            int &operator*() override;
            PrimeIterator &operator++() override;
            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;

            PrimeIterator begin();
            PrimeIterator end();
        };
    };
}
#endif