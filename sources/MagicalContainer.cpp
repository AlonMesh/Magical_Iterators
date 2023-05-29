#include "MagicalContainer.hpp"
#include <algorithm>

namespace ariel
{
    MagicalContainer::MagicalContainer()
    {
        elements = vector<int>();
        iterators = vector<Iterator*>();
    }

    MagicalContainer::~MagicalContainer()
    {
        // TODO: Implement
    }

    void MagicalContainer::addElement(int element_to_add)
    {
        for (auto it = elements.begin(); it != elements.end(); ++it)
        {
            if (*it == element_to_add)
            {
                throw invalid_argument("Can't add a duplicate element");
            }
        }
        elements.push_back(element_to_add);

        // TODO: alert iterators
    }

    void MagicalContainer::removeElement(int element_to_remove)
    {
        for (auto it = elements.begin(); it != elements.end(); ++it)
        {
            if (*it == element_to_remove)
            {
                elements.erase(it);
                return;
            }
        }

        throw invalid_argument("Can't remove a non-existing element");

        // TODO: alert iterators
    }

    int MagicalContainer::size() const
    {
        return elements.size();
    }

    vector<int> getSortedCopy(const vector<int> &inputVector)
    {
        vector<int> sortedVector(inputVector); // Create a copy of the inputVector

        sort(sortedVector.begin(), sortedVector.end()); // Sort the vector in ascending order

        return sortedVector;
    }

    MagicalContainer::AscendingIterator::AscendingIterator() : original_container(nullptr), currentElement(nullptr)
    {
        // TODO: Implement
    }

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
        : original_container(&container), sortedVec(getSortedCopy(container.elements))
    {
        if (!sortedVec.empty()) {
            currentElement = &sortedVec[0];
        } else {
            currentElement = nullptr;
        }
        container.iterators.push_back(this);
    }

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other)
        : original_container(other.original_container), sortedVec(other.sortedVec), currentElement(other.currentElement)
    {
        other.original_container->iterators.push_back(this);
    }

    MagicalContainer::AscendingIterator::~AscendingIterator()
    {
        // TODO: Implement
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
    {
        // TODO: Implement
        sortedVec = other.sortedVec;
        original_container = other.original_container;
        // There is no point to add it to original_container.iterators (this->sortedVec already there by other.sortedVec)
        return *this;
    }

    int& MagicalContainer::AscendingIterator::operator*()
    {
        if (currentElement == nullptr)
        {
            throw std::runtime_error("Iterator is not pointing to a valid element");
        }
        return *currentElement;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
    {
        if (currentElement == nullptr)
        {
            // If the iterator has reached the end, throw an exception or handle it according to your requirement.
            throw std::runtime_error("Iterator has reached the end");
        }

        ++currentElement; // Move to the next element

        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
    {
        // TODO: Implement and return default value
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
    {
        // TODO: Implement and return default value
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
    {
        // TODO: Implement and return default value
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
    {
        // TODO: Implement and return default value
        return false;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
    {
        // AscendingIterator beginIterator(*original_container); // Create an iterator for the beginning
        // beginIterator.currentElement = &(original_container->elements[0]); // Set the iterator to the first element
        // return beginIterator;
        return AscendingIterator();
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
    {
        // AscendingIterator endIterator(*original_container); // Create an iterator for the end
        // endIterator.currentElement = nullptr; // Set the iterator to null to indicate the end
        return AscendingIterator();
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator()
    {
        // TODO: Implement
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container)
    {
        // TODO: Implement
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other)
    {
        // TODO: Implement
    }

    MagicalContainer::SideCrossIterator::~SideCrossIterator()
    {
        // TODO: Implement
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
    {
        // TODO: Implement
        return *this;
    }

    int &MagicalContainer::SideCrossIterator::operator*()
    {
        if (currentElement == nullptr)
        {
            throw std::runtime_error("Iterator is not pointing to a valid element");
        }
        return *currentElement;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {
        // TODO: Implement
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
    {
        // TODO: Implement and return default value
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
    {
        // TODO: Implement and return default value
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
    {
        // TODO: Implement and return default value
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
    {
        // TODO: Implement and return default value
        return false;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
    {
        // TODO: Implement and return default value
        return SideCrossIterator();
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
    {
        // TODO: Implement and return default value
        return SideCrossIterator();
    }

    MagicalContainer::PrimeIterator::PrimeIterator()
    {
        // TODO: Implement
    }

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container)
    {
        // TODO: Implement
    }

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other)
    {
        // TODO: Implement
    }

    MagicalContainer::PrimeIterator::~PrimeIterator()
    {
        // TODO: Implement
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {
        // TODO: Implement
        return *this;
    }

    int &MagicalContainer::PrimeIterator::operator*()
    {
        if (currentElement == nullptr)
        {
            throw std::runtime_error("Iterator is not pointing to a valid element");
        }
        return *currentElement;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
        // TODO: Implement
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
    {
        // TODO: Implement and return default value
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
    {
        // TODO: Implement and return default value
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
    {
        // TODO: Implement and return default value
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
    {
        // TODO: Implement and return default value
        return false;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
    {
        // TODO: Implement and return default value
        return PrimeIterator();
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
    {
        // TODO: Implement and return default value
        return PrimeIterator();
    }
}