
#include <gtest/gtest.h>
#include "CostCutting.h"

TEST(TestCostCutting, testKeep)
{
   EXPECT_EQ(1, keep(0, 1, 2));
   EXPECT_EQ(2, keep(4, 2, 0));
   EXPECT_EQ(3, keep(3, 7, 1));
   EXPECT_EQ(2, keep(2, 2, 2));
}

TEST(TestCostCutting, testSampleInput)
{
   EXPECT_EQ(2000, keep(1000, 2000, 3000));
   EXPECT_EQ(2500, keep(3000, 2500, 1500));
   EXPECT_EQ(1500, keep(1500, 1200, 1800));
}

