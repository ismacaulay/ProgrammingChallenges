
#include <gtest/gtest.h>
#include "DivisionOfNlogonia.h"

TEST(TestDivisionOfNlogonia, testCheckQuery_divisa)
{
   EXPECT_EQ("divisa", checkQuery(0, 0, 0, 0));
   EXPECT_EQ("divisa", checkQuery(10, 14, 10, 0));
   EXPECT_EQ("divisa", checkQuery(10, 14, -23, 14));
   EXPECT_EQ("divisa", checkQuery(-23, 14, -23, 14));
   EXPECT_EQ("divisa", checkQuery(-23, -14, 23, -14));
}

TEST(TestDivisionOfNlogonia, testCheckQuery_NE)
{
   EXPECT_EQ("NO", checkQuery(-1, 1, 0, 0));
   EXPECT_EQ("NO", checkQuery(-23, 14, -21, 13));
}

TEST(TestDivisionOfNlogonia, testCheckQuery_NO)
{
   EXPECT_EQ("NE", checkQuery(1, 1, 0, 0));
   EXPECT_EQ("NE", checkQuery(23, 14, 21, 13));
}

TEST(TestDivisionOfNlogonia, testCheckQuery_SE)
{
   EXPECT_EQ("SO", checkQuery(-1, -1, 0, 0));
   EXPECT_EQ("SO", checkQuery(-23, -14, -21, -13));
}

TEST(TestDivisionOfNlogonia, testCheckQuery_SO)
{
   EXPECT_EQ("SE", checkQuery(1, -1, 0, 0));
   EXPECT_EQ("SE", checkQuery(23, -14, 21, -13));
}

TEST(TestDivisionOfNlogonia, testSampleQueries)
{
   EXPECT_EQ("NE", checkQuery(10, 10, 2, 1));
   EXPECT_EQ("divisa", checkQuery(-10, 1, 2, 1));
   EXPECT_EQ("NO", checkQuery(0, 33, 2, 1));
   EXPECT_EQ("divisa", checkQuery(-1000, -1000, -1000, -1000));
   EXPECT_EQ("NE", checkQuery(0, 0, -1000, -1000));
   EXPECT_EQ("SO", checkQuery(-2000, -10000, -1000, -1000));
   EXPECT_EQ("SE", checkQuery(-999, -1001, -1000, -1000));
}