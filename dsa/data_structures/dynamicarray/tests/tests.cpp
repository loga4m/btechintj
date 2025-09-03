#include "tests.h"
#include "../IntVec.h"
#include <mintest/assertions/headers.h>
#include <mintest/suit.h>
#include <vector>

void SizeT()
{
    IntVec myVec;
    std::vector<int> stdVec;

    EXPECT_EQ(stdVec.size(), myVec.size());

    // add some elements
    for (int i = 0; i < 10; i++)
    {
        myVec.push_back(i);
        stdVec.push_back(i);
    }
    EXPECT_EQ(stdVec.size(), myVec.size());

    // remove one element
    myVec.pop_back();
    stdVec.pop_back();
    EXPECT_EQ(stdVec.size(), myVec.size());
}

void CapacityT()
{
    IntVec myVec;
    std::vector<int> stdVec;

    EXPECT_EQ(stdVec.capacity(), myVec.capacity());

    // add one element
    myVec.push_back(10);
    stdVec.push_back(10);
    EXPECT_EQ(stdVec.capacity(), myVec.capacity());

    // add some elements
    for (int i = 0; i < 10; i++)
    {
        myVec.push_back(i);
        stdVec.push_back(i);
    }
    EXPECT_EQ(stdVec.capacity(), myVec.capacity());

    // remove one element
    myVec.pop_back();
    myVec.pop_back();
    EXPECT_EQ(stdVec.capacity(), myVec.capacity());
}

void DataT() {
    IntVec myVec;
    EXPECT_EQ(myVec.data(), static_cast<int*>(nullptr));
}



void register_tests(TestSuit &Ts)
{
    Ts.add_test("Test: .size()", SizeT);
    Ts.add_test("Test: .capacity()", CapacityT);
    Ts.add_test("Test: .data()", DataT);
}
