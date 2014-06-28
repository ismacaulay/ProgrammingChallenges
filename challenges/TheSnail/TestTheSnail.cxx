
#include <gtest/gtest.h>
#include "TheSnail.h"

TEST(TestTheSnail, testSampleInput)
{
   EXPECT_EQ("success on day 3", doesTheNameMakeIt(6, 3, 1, 10));
   EXPECT_EQ("failure on day 4", doesTheNameMakeIt(10, 2, 1, 50));
   EXPECT_EQ("failure on day 7", doesTheNameMakeIt(50, 5, 3, 14));
   EXPECT_EQ("failure on day 68", doesTheNameMakeIt(50, 6, 4, 1));
   EXPECT_EQ("success on day 20", doesTheNameMakeIt(50, 6, 3, 1));
   EXPECT_EQ("failure on day 2", doesTheNameMakeIt(1, 1, 1, 1));
}

