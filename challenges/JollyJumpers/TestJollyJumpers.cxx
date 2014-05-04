
#include <gtest/gtest.h>
#include "JollyJumpers.h"

TEST(TestJollyJumpers, testIsJolly)
{
   {
      std::vector<int> elements{1, 4, 2, 3};
      EXPECT_EQ(isJolly(elements), true);
   }
   {
      std::vector<int> elements{1, 4, 2, -1, 6};
      EXPECT_EQ(isJolly(elements), false);
   }
   {
      std::vector<int> elements{1, 1, 2, 3};
      EXPECT_EQ(isJolly(elements), false);
   }
}