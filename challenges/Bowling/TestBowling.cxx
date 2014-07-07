
#include <gtest/gtest.h>
#include "Bowling.h"

TEST(TestBowling, testSampleInput)
{
   vc scoreCard = { 
      '1', '0', '1', '/', '2', '2', 'X', '3', '3', 'X', '1', '/', '3', '/', 'X', '1', '2' 
   };
   EXPECT_EQ(108, totalScore(scoreCard));

   scoreCard = {
      '1', '0', '1', '/', '2', '2', 'X', '3', '3', 'X', '1', '/', '3', '/', '1', '/', 'X', '8', '0' 
   };
   EXPECT_EQ(121, totalScore(scoreCard));

   scoreCard = {
      '1', '0', '1', '/', '2', '2', 'X', '3', '3', 'X', '1', '/', '3', '/', '1', '/', '8', '/', '9' 
   };
   EXPECT_EQ(120, totalScore(scoreCard));

   scoreCard = { 
      'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' 
   };
   EXPECT_EQ(300, totalScore(scoreCard));

   scoreCard = {
      '1', '/', '2', '/', '3', '/', '4', '/', '5', '/', '6', '/', '7', '/', '8', '/', '9', '/', '0', '/', '0'
   };
   EXPECT_EQ(144, totalScore(scoreCard));
}