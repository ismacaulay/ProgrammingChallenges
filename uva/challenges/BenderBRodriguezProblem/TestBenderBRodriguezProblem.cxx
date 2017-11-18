
#include <gtest/gtest.h>
#include "BenderBRodriguezProblem.h"

TEST(TestBenderBRodriguezProblem, testBendWire)
{
   EXPECT_EQ("+y", bendWire("+x", "+y"));
   EXPECT_EQ("-y", bendWire("+x", "-y"));
   EXPECT_EQ("+z", bendWire("+x", "+z"));
   EXPECT_EQ("-z", bendWire("+x", "-z"));
   
   EXPECT_EQ("-y", bendWire("-x", "+y"));
   EXPECT_EQ("+y", bendWire("-x", "-y"));
   EXPECT_EQ("-z", bendWire("-x", "+z"));
   EXPECT_EQ("+z", bendWire("-x", "-z"));
   
   EXPECT_EQ("-x", bendWire("+y", "+y"));
   EXPECT_EQ("+x", bendWire("+y", "-y"));
   EXPECT_EQ("+y", bendWire("+y", "+z"));
   EXPECT_EQ("+y", bendWire("+y", "-z"));

   EXPECT_EQ("+x", bendWire("-y", "+y"));
   EXPECT_EQ("-x", bendWire("-y", "-y"));
   EXPECT_EQ("-y", bendWire("-y", "+z"));
   EXPECT_EQ("-y", bendWire("-y", "-z"));

   EXPECT_EQ("+z", bendWire("+z", "+y"));
   EXPECT_EQ("+z", bendWire("+z", "-y"));
   EXPECT_EQ("-x", bendWire("+z", "+z"));
   EXPECT_EQ("+x", bendWire("+z", "-z"));

   EXPECT_EQ("-z", bendWire("-z", "+y"));
   EXPECT_EQ("-z", bendWire("-z", "-y"));
   EXPECT_EQ("+x", bendWire("-z", "+z"));
   EXPECT_EQ("-x", bendWire("-z", "-z"));

   EXPECT_EQ("+x", bendWire("+x", "No"));
   EXPECT_EQ("-x", bendWire("-x", "No"));
   EXPECT_EQ("+y", bendWire("+y", "No"));
   EXPECT_EQ("-y", bendWire("-y", "No"));
   EXPECT_EQ("+z", bendWire("+z", "No"));
   EXPECT_EQ("-z", bendWire("-z", "No"));
}

TEST(TestBenderBRodriguezProblem, testSampleInput)
{
   vs bends = { "+z", "-z" };
   EXPECT_EQ("+x", bendWire(bends));

   bends = { "+z", "+y" };
   EXPECT_EQ("+z", bendWire(bends));

   bends = { "+z" };
   EXPECT_EQ("+z", bendWire(bends));

   bends = { "+z", "+y", "+z" };
   EXPECT_EQ("-x", bendWire(bends));

   bends = { "No", "+z", "No", "No" };
   EXPECT_EQ("+z", bendWire(bends));
}

