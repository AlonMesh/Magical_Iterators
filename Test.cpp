#include "doctest.h"
#include "sources/MagicalContainer.hpp"

TEST_CASE("Initialize MagicalContainer") {
    MagicalContainer container;

    // Check if the size of an empty container is 0
    CHECK_EQ(container.size(), 0);

    // more?
}

TEST_SUITE("Add elemetns") {
    MagicalContainer container;

    TEST_CASE("Adding elements increase container's size") {
        container.addElement(2);
        CHECK_EQ(container.size(), 1);

        container.addElement(4);
        CHECK_EQ(container.size(), 2);
    }

    TEST_CASE("Add a duplicate element") {
        container.addElement(2);

        //It should throw an exception and the size of the container should remain the same
        CHECK_THROWS_AS(container.addElement(2), std::invalid_argument);
        CHECK_EQ(container.size(), 1);
    }
}

TEST_SUITE("Remove elements") {
    MagicalContainer container;

    TEST_CASE("Remove an existing element") {
        // Add some elements to the container
        container.addElement(2);
        container.addElement(4);
        container.addElement(6);

        container.removeElement(4);

        // Check if the size has decreased and the element is removed
        CHECK_EQ(container.size(), 2);
    }

    TEST_CASE("Remove a non-existing element") {
        CHECK_THROWS_AS(container.removeElement(10), std::invalid_argument);

        // Check if the size remains the same
        CHECK_EQ(container.size(), 2);
    }
}

TEST_SUITE("ite") {
    MagicalContainer container;
    AscendingIterator asc(container);

    TEST_CASE("AscendingIterator initialize") {
        container.addElement(3);
        container.addElement(1);
        container.addElement(2);

        CHECK_EQ(asc, AscendingIterator::begin()); // Check if iterator is equal to begin()
        CHECK_EQ(*asc, 1); // Check the first element

        ++asc;
        CHECK_EQ(*asc, 2); // Check the second element
        
        ++asc;
        CHECK_EQ(*asc, 3); // Check the third element

        ++asc;
        CHECK_EQ(asc, AscendingIterator::end()); // Check if iterator reaches the end        
    }

    TEST_CASE("AscendingIterator - Copy Constructor") {
        container.addElement(3);
        container.addElement(1);
        container.addElement(2);

        AscendingIterator ascCopy(asc);

        // Copied iterator has the same state as the original iterator
        CHECK_EQ(*asc, *ascCopy);

        ++asc;
        ++ascCopy;

        CHECK_EQ(*asc, *ascCopy);

        // Modifying the original iterator does not affect the copied iterator
        ++asc;
        CHECK_NE(*asc, *ascCopy);
    }

    TEST_CASE("AscendingIterator - Assignment Operator") {
        container.addElement(3);
        container.addElement(1);
        container.addElement(2);

        MagicalContainer container2;
        container2.addElement(5);
        container2.addElement(4);
        AscendingIterator asc2(container2);

        asc2 = asc; // Assign 'asc' to 'asc2'

        // Assigned iterator has the same state as the source iterator
        CHECK_EQ(*asc, *asc2);

        ++asc;
        ++asc2;

        CHECK_EQ(*asc, *asc2);

        // Modifying the source iterator does not affect the assigned iterator
        ++asc;
        CHECK_NE(*asc, *asc2);
    }

    TEST_CASE("AscendingIterator - Equality, Inequality, Less Than and Great Than Comparison") {
        container.addElement(3);
        container.addElement(1);
        container.addElement(2);

        AscendingIterator asc2(container);
        
        // Equality comparison
        CHECK(asc == asc2);
        CHECK_FALSE(asc != asc2);

        // Move 'asc' to a different position within the container
        ++asc;

        // Inequality comparison
        CHECK(asc != asc2);
        CHECK_FALSE(asc == asc2);

        // Less Than comparison
        CHECK(asc2 < asc);
        CHECK_FALSE(asc < asc2);

        // Great Than comparison
        CHECK(asc > asc2);
        CHECK_FALSE(asc2 > asc);
    }

    //TODO: iterators of diffrent containers should be inequal. what about < > ? 

    


}


