
#include <gtest/gtest.h>
#include "3n+1Problem.h"

TEST(Test3n1Problem, testIsOddReturnsCorrectValue)
{
   EXPECT_EQ(isOdd(1), true);
   EXPECT_EQ(isOdd(2), false);
   EXPECT_EQ(isOdd(3), true);
   EXPECT_EQ(isOdd(4), false);
   EXPECT_EQ(isOdd(5), true);
   EXPECT_EQ(isOdd(6), false);
   EXPECT_EQ(isOdd(7), true);
   EXPECT_EQ(isOdd(8), false);
   EXPECT_EQ(isOdd(9), true);
	EXPECT_EQ(isOdd(10), false);
}

TEST(Test3n1Problem, testNumberOfCyclesReturnsCorrectValue)
{
   EXPECT_EQ(numberOfCycles(1), 1);
   EXPECT_EQ(numberOfCycles(2), 2);
   EXPECT_EQ(numberOfCycles(3), 8);
   EXPECT_EQ(numberOfCycles(4), 3);
   EXPECT_EQ(numberOfCycles(5), 6);
   EXPECT_EQ(numberOfCycles(6), 9);
   EXPECT_EQ(numberOfCycles(7), 17);
   EXPECT_EQ(numberOfCycles(8), 4);
   EXPECT_EQ(numberOfCycles(9), 20);
   EXPECT_EQ(numberOfCycles(10), 7);
}

TEST(Test3n1Problem, testMaxNumberReturnsCorrectValue)
{
   EXPECT_EQ(maxNumber(1,2), 2);
   EXPECT_EQ(maxNumber(2,1), 2);
   EXPECT_EQ(maxNumber(-1,1), 1);
   EXPECT_EQ(maxNumber(-1,-2), -1);
   EXPECT_EQ(maxNumber(1,1), 1);
}

TEST(Test3n1Problem, testMaxCyclesForRangeReturnsCorrectValue)
{
   EXPECT_EQ(maxCyclesForRange(1, 10), 20);
   EXPECT_EQ(maxCyclesForRange(10, 1), 20);
   EXPECT_EQ(maxCyclesForRange(100, 200), 125);
   EXPECT_EQ(maxCyclesForRange(200, 100), 125);
   EXPECT_EQ(maxCyclesForRange(201, 210), 89);
   EXPECT_EQ(maxCyclesForRange(210, 201), 89);
   EXPECT_EQ(maxCyclesForRange(1000, 900), 174);
   EXPECT_EQ(maxCyclesForRange(9, 9), 20);
}