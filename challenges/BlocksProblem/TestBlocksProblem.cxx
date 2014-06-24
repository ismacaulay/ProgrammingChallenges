
#include <gtest/gtest.h>
#include "BlocksProblem.h"

TEST(TestBlocksProblem, validCommand)
{
   vvi blocks;
   EXPECT_FALSE(validCommand(blocks, 1, 1));

   blocks = { { 1, 2 } };
   EXPECT_FALSE(validCommand(blocks, 1, 2));

   blocks = { 
              {1},
              {},
              {2, 4, 3, 6}
            };
   EXPECT_FALSE(validCommand(blocks, 2, 3));
   EXPECT_FALSE(validCommand(blocks, 4, 3));
   EXPECT_FALSE(validCommand(blocks, 4, 6));

   blocks = { 
               {1}, 
               {2},
               {3}
            };
   EXPECT_TRUE(validCommand(blocks, 1, 2));
   EXPECT_TRUE(validCommand(blocks, 2, 3));
   EXPECT_TRUE(validCommand(blocks, 3, 1));
}

TEST(TestBlocksProblem, testPerformMoveOnto)
{
   {
      vvi blocks = { 
         {0}, 
         {1},
         {2}
      };
      vvi expectedBlockState = {
         {0, 2},
         {1},
         {}
      };
      performCommand(blocks, "move", 2, "onto", 0);
      EXPECT_EQ(expectedBlockState, blocks);

      expectedBlockState = {
         {0},
         {1, 2},
         {}
      };
      performCommand(blocks, "move", 2, "onto", 1);
      EXPECT_EQ(expectedBlockState, blocks);
   }
   {
      vvi blocks = { 
         {0}, 
         {1},
         {2},
         {3}
      };
      vvi expectedBlockState = {
         {0},
         {1, 3},
         {2},
         {}
      };
      performCommand(blocks, "move", 2, "onto", 1);
      performCommand(blocks, "move", 3, "onto", 1);
      EXPECT_EQ(expectedBlockState, blocks);
   }

   {
      vvi blocks = { 
         {}, 
         {1, 2, 0},
         {},
         {3}
      };
      vvi expectedBlockState = {
         {0},
         {1, 3},
         {2},
         {}
      };
      performCommand(blocks, "move", 3, "onto", 1);
      EXPECT_EQ(expectedBlockState, blocks);
   }
}

TEST(TestBlocksProblem, testPerformMoveOver)
{
   {
      vvi blocks = { 
         {}, 
         {1, 2},
         {},
         {3, 0}
      };
      vvi expectedBlockState = {
         {0},
         {1, 2, 3},
         {},
         {}
      };
      performCommand(blocks, "move", 3, "over", 1);
      EXPECT_EQ(expectedBlockState, blocks);
   }
   {
      vvi blocks = { 
         {0}, 
         {1, 3},
         {2},
         {}
      };
      vvi expectedBlockState = {
         {},
         {},
         {2, 1, 0},
         {3}
      };
      performCommand(blocks, "move", 1, "over", 2);
      performCommand(blocks, "move", 0, "over", 2);
      EXPECT_EQ(expectedBlockState, blocks);
   }
}

TEST(TestBlocksProblem, testPerformPileOnto)
{
   {
      vvi blocks = { 
         {0, 2}, 
         {1, 3},
         {},
         {}
      };
      vvi expectedBlockState = {
         {0, 1, 3},
         {},
         {2},
         {}
      };
      performCommand(blocks, "pile", 1, "onto", 0);
      EXPECT_EQ(expectedBlockState, blocks);
   }
   {
      vvi blocks = { 
         {0, 2}, 
         {1, 3},
         {},
         {}
      };
      vvi expectedBlockState = {
         {},
         {},
         {2, 0, 1, 3},
         {}
      };
      performCommand(blocks, "pile", 1, "onto", 0);
      performCommand(blocks, "pile", 0, "onto", 2);
      EXPECT_EQ(expectedBlockState, blocks);
   }
   {
      vvi blocks = { 
         {0}, 
         {1},
         {2},
         {3}
      };
      vvi expectedBlockState = {
         {0, 2, 3},
         {1},
         {},
         {}
      };
      performCommand(blocks, "pile", 1, "onto", 0);
      performCommand(blocks, "pile", 3, "onto", 2);
      performCommand(blocks, "pile", 2, "onto", 0);
      EXPECT_EQ(expectedBlockState, blocks);
   }
}

TEST(TestBlocksProblem, testPerformPileOver)
{
   {
      vvi blocks = { 
         {0, 1}, 
         {},
         {2, 3},
         {}
      };
      vvi expectedBlockState = {
         {0, 1, 2, 3},
         {},
         {},
         {}
      };
      performCommand(blocks, "pile", 2, "over", 0);
      EXPECT_EQ(expectedBlockState, blocks);
   }
   {
      vvi blocks = { 
         {0}, 
         {1},
         {2, 3},
         {}
      };
      vvi expectedBlockState = {
         {},
         {1, 0, 2, 3},
         {},
         {}
      };
      performCommand(blocks, "pile", 2, "over", 0);
      performCommand(blocks, "pile", 0, "over", 1);
      EXPECT_EQ(expectedBlockState, blocks);
   }
   {
      vvi blocks = { 
         {0}, 
         {1},
         {2},
         {3}
      };
      vvi expectedBlockState = {
         {},
         {},
         {},
         {3, 2, 1, 0}
      };
      performCommand(blocks, "pile", 2, "over", 3);
      performCommand(blocks, "pile", 0, "over", 1);
      performCommand(blocks, "pile", 1, "over", 2);
      EXPECT_EQ(expectedBlockState, blocks);
   } 
}

TEST(TestBlocksProblem, testPerformSampleCommands)
{
   vvi blocks = { 
         {0}, {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}
   };
   vvi expectedBlockState = {
         {0},
         {1, 9, 2, 4},
         {},
         {3},
         {},
         {5, 8, 7, 6},
         {},
         {},
         {},
         {}
      };

      performCommand(blocks, "move", 9, "onto", 1);
      performCommand(blocks, "move", 8, "over", 1);
      performCommand(blocks, "move", 7, "over", 1);
      performCommand(blocks, "move", 6, "over", 1);
      performCommand(blocks, "pile", 8, "over", 6);
      performCommand(blocks, "pile", 8, "over", 5);
      performCommand(blocks, "move", 2, "over", 1);
      performCommand(blocks, "move", 4, "over", 9);

      EXPECT_EQ(expectedBlockState, blocks);
}