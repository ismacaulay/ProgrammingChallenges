
#include <gtest/gtest.h>
#include "BlowingFuses.h"

TEST(TestBlowingFuses, testToggleDevice)
{
   vb states = { true, false };
   vi consumptions = { 10, 20 };

   vb expectedStates = { false, false };
   toggleDevice(0, states, consumptions);
   EXPECT_EQ(expectedStates, states);
   
   expectedStates = { false, true };
   toggleDevice(1, states, consumptions);
   EXPECT_EQ(expectedStates, states);

   expectedStates = { true, true };
   toggleDevice(0, states, consumptions);
   EXPECT_EQ(expectedStates, states);

   expectedStates = { true, false };
    toggleDevice(1, states, consumptions);
   EXPECT_EQ(expectedStates, states);
}

TEST(TestBlowingFuses, testOperationBlowsFusesReturnsCorrectValue)
{
   vi consumptions = { 10, 20, 0, 2, 1 };
   
   {
      vb states = { false, false, false, false, false };
      int maxConsumption = 0;
      EXPECT_TRUE(operationBlowsFuse(1, states, consumptions, 
                                     10, maxConsumption));
   }
   {
      vb states = { false, false, false, false, false };
      int maxConsumption = 0;
      EXPECT_FALSE(operationBlowsFuse(0, states, consumptions, 
                                     10, maxConsumption));
   }
   {
      vb states = { true, false, false, false, false };
      int maxConsumption = 0;
      EXPECT_TRUE(operationBlowsFuse(4, states, consumptions, 
                                     10, maxConsumption));
   }
   {
      vb states = { true, false, false, false, false };
      int maxConsumption = 0;
      EXPECT_FALSE(operationBlowsFuse(2, states, consumptions, 
                                     10, maxConsumption));
   }
   {
      vb states = { false, false, false, false, false };
      int maxConsumption = 0;
      EXPECT_FALSE(operationBlowsFuse(2, states, consumptions, 
                                     21, maxConsumption));
   }
}

TEST(TestBlowingFuses, testOperationBlowsFusesSetsCorrectMaxValue)
{
   vi consumptions = { 10, 20, 0, 2, 1 };
   
   {
      vb states = { false, false, false, false, false };

      int maxConsumption = 0;
      operationBlowsFuse(1, states, consumptions, 
                         10, maxConsumption);
      EXPECT_EQ(20, maxConsumption);
   }
   {
      vb states = { false, false, false, false, false };

      int maxConsumption = 0;
      operationBlowsFuse(1, states, consumptions, 
                         10, maxConsumption);
      operationBlowsFuse(4, states, consumptions, 
                         10, maxConsumption);
      operationBlowsFuse(0, states, consumptions, 
                         10, maxConsumption);
      EXPECT_EQ(31, maxConsumption);
   }
   {
      vb states = { true, false, false, false, false };

      int maxConsumption = 10;
      operationBlowsFuse(3, states, consumptions, 
                         10, maxConsumption);
      EXPECT_EQ(12, maxConsumption);
      operationBlowsFuse(0, states, consumptions, 
                         10, maxConsumption);
      EXPECT_EQ(12, maxConsumption);
      operationBlowsFuse(1, states, consumptions,
                         10, maxConsumption);
      EXPECT_EQ(22, maxConsumption);
   }
}

TEST(TestBlowingFuses, testCalculateCurrentConsumption)
{
   vi consumptions = { 10, 20, 0, 2, 1 };

   {
      vb states = { false, false, false, false, false };
      EXPECT_EQ(0, calculateCurrentConsumption(states, consumptions));
   }
   {
      vb states = { true, false, false, false, false };
      EXPECT_EQ(10, calculateCurrentConsumption(states, consumptions));
   }
   {
      vb states = { false, true, false, true, false };
      EXPECT_EQ(22, calculateCurrentConsumption(states, consumptions));
   }
   {
      vb states = { true, false, false, false, true };
      EXPECT_EQ(11, calculateCurrentConsumption(states, consumptions));
   }
   {
      vb states = { true, true, true, true, true };
      EXPECT_EQ(33, calculateCurrentConsumption(states, consumptions));
   }

}

