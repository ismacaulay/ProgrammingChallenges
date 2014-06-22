
#include <gtest/gtest.h>
#include "Mapmaker.h"

TEST(TestMapmaker, testCalculateConstant)
{
   EXPECT_EQ(1, calculateConstant(1, 0, 0));
   EXPECT_EQ(0, calculateConstant(0, 100, 23));
   EXPECT_EQ(66, calculateConstant(3, 2, 23));
   EXPECT_EQ(40810, calculateConstant(154, 34, 298));
}

TEST(TestMapmaker, testCalculateInitialConstant)
{
   {
      vi constants = { 0, 0, 0 };
      vi lowerBounds = { 0, 0, 0 };
      int base = 1323;

      EXPECT_EQ(1323, calculateInitialConstant(base, constants, lowerBounds));
   }
   {
      vi constants = { 1, 2, 3 };
      vi lowerBounds = { 4, 5, 6 };
      int base = 125;

      EXPECT_EQ(93, calculateInitialConstant(base, constants, lowerBounds));
   }
   {
      vi constants = { 5, 3, 0 };
      vi lowerBounds = { 12, 4, 13 };
      int base = 562;

      EXPECT_EQ(490, calculateInitialConstant(base, constants, lowerBounds));
   }
   {
      vi constants = { 10, 2 };
      vi lowerBounds = { 0, 1 };
      int base = 1500;

      EXPECT_EQ(1498, calculateInitialConstant(base, constants, lowerBounds));
   }
   {
      vi constants = { 144, 24, 4};
      vi lowerBounds = { 1, 0, 5 };
      int base = 2000;

      EXPECT_EQ(1836, calculateInitialConstant(base, constants, lowerBounds));
   }
}

TEST(TestMapmaker, testCalculateAddress)
{
   {
      vi constants = { 1323, 0, 0, 0 };
      vi indexes = { 0, 0, 0 };

      EXPECT_EQ(1323, calculateAddress(constants, indexes));
   }
   {
      vi constants = { 125, 123, 34, 12 };
      vi indexes = { 2, 0, 10 };

      EXPECT_EQ(491, calculateAddress(constants, indexes));
   }
   {
      vi constants = { 1498, 10, 2 };
      vi indexes = { 2, 4 };

      EXPECT_EQ(1526, calculateAddress(constants, indexes));
   }
   {
      vi constants = { 1836, 144, 24, 4 };
      vi indexes = { 2, 0, 6 };

      EXPECT_EQ(2148, calculateAddress(constants, indexes));
   }
}