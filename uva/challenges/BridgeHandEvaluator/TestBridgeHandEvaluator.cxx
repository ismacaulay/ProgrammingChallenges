
#include <gtest/gtest.h>
#include "BridgeHandEvaluator.h"

TEST(TestBridgeHandEvaluator, testName)
{
   {
      msc cards;
      cards['S'] = { 'K', 'Q' };
      cards['H'] = { 'T', '8', '4' };
      cards['C'] = { 'A', 'Q', 'T', '5' };
      cards['D'] = { 'K', 'Q', 'J', '8' };

      EXPECT_EQ("BID D", placeBid(cards));
   }
   {
      msc cards;
      cards['S'] = { 'A', '7', '4' };
      cards['H'] = { 'A', '7', '5' };
      cards['C'] = { 'A', '3', '4' };
      cards['D'] = { 'A', 'T', '7', '5' };
      EXPECT_EQ("BID NO-TRUMP", placeBid(cards));
   }

   {
      msc cards;
      cards['S'] = { '2', '7', '4' };
      cards['H'] = { 'A', '7', '5' };
      cards['C'] = { 'A', '3', '4' };
      cards['D'] = { 'A', 'T', '7', '5' };
      EXPECT_EQ("PASS", placeBid(cards));
   }
}

TEST(TestBridgeHandEvaluator, testAllSuitsStopped)
{
   msc cards;
   cards['S'] = { 'A' };
   cards['H'] = { 'A' };
   cards['C'] = { 'A' };
   cards['D'] = { 'A' };

   EXPECT_TRUE(allSuitsStopped(cards));

   cards['S'] = { 'K', '2' };
   cards['H'] = { 'A' };
   cards['C'] = { 'A' };
   cards['D'] = { 'A' };

   EXPECT_TRUE(allSuitsStopped(cards));

   cards['S'] = { 'K', '2' };
   cards['H'] = { 'A' };
   cards['C'] = { 'Q', '3', '4' };
   cards['D'] = { 'A' };

   EXPECT_TRUE(allSuitsStopped(cards));

   cards['S'] = { 'K' };
   cards['H'] = { 'A' };
   cards['C'] = { 'Q', '3', '4' };
   cards['D'] = { 'A' };

   EXPECT_FALSE(allSuitsStopped(cards));

   cards['S'] = { 'K', '2' };
   cards['H'] = { 'A' };
   cards['C'] = { 'Q', '3' };
   cards['D'] = { 'A' };

   EXPECT_FALSE(allSuitsStopped(cards));
}

TEST(TestBridgeHandEvaluator, testCheckRule1)
{
   msc cards;
   cards['S'] = { 'A' };
   cards['H'] = { '2' };
   cards['C'] = { '2' };
   cards['D'] = { '2' };
   EXPECT_EQ(4, checkRule1(cards));

   cards['S'] = { '2' };
   cards['H'] = { '2' };
   cards['C'] = { '2' };
   cards['D'] = { 'K' };
   EXPECT_EQ(3, checkRule1(cards));

   cards['S'] = { 'T' };
   cards['H'] = { 'T' };
   cards['C'] = { 'J' };
   cards['D'] = { '7' };
   EXPECT_EQ(1, checkRule1(cards));

   cards['S'] = { '9' };
   cards['H'] = { '9' };
   cards['C'] = { '9' };
   cards['D'] = { '9' };
   EXPECT_EQ(0, checkRule1(cards));

   cards['S'] = { 'A' };
   cards['H'] = { 'K' };
   cards['C'] = { 'Q' };
   cards['D'] = { 'J' };
   EXPECT_EQ(10, checkRule1(cards));
}

TEST(TestBridgeHandEvaluator, testCheckRule2)
{
   msc cards;
   cards['S'] = { 'K' };
   cards['H'] = { '2' };
   cards['C'] = { '2' };
   cards['D'] = { '2' };
   EXPECT_EQ(-1, checkRule2(cards));

   cards['S'] = { 'K' };
   cards['H'] = { 'K' };
   cards['C'] = { 'K' };
   cards['D'] = { 'K' };
   EXPECT_EQ(-4, checkRule2(cards));

   cards['S'] = { 'A' };
   cards['H'] = { 'K', '2' };
   cards['C'] = { '2' };
   cards['D'] = { '2' };
   EXPECT_EQ(0, checkRule2(cards));
}

TEST(TestBridgeHandEvaluator, testCheckRule3)
{
   msc cards;
   cards['S'] = { 'Q' };
   cards['H'] = { '2' };
   cards['C'] = { '2' };
   cards['D'] = { '2' };
   EXPECT_EQ(-1, checkRule3(cards));

   cards['S'] = { 'K' };
   cards['H'] = { 'Q', '2' };
   cards['C'] = { 'K' };
   cards['D'] = { 'K' };
   EXPECT_EQ(-1, checkRule3(cards));

   cards['S'] = { 'Q' };
   cards['H'] = { 'Q', '2' };
   cards['C'] = { 'Q' };
   cards['D'] = { 'Q' };
   EXPECT_EQ(-4, checkRule3(cards));

   cards['S'] = { 'Q', '3', '4' };
   cards['H'] = { 'K', '2' };
   cards['C'] = { '2' };
   cards['D'] = { '2' };
   EXPECT_EQ(0, checkRule3(cards));
}

TEST(TestBridgeHandEvaluator, testCheckRule4)
{
   msc cards;
   cards['S'] = { 'J' };
   cards['H'] = { '2' };
   cards['C'] = { '2' };
   cards['D'] = { '2' };
   EXPECT_EQ(-1, checkRule4(cards));

   cards['S'] = { 'K' };
   cards['H'] = { 'J', '2' };
   cards['C'] = { 'K' };
   cards['D'] = { 'K' };
   EXPECT_EQ(-1, checkRule4(cards));

   cards['S'] = { 'Q' };
   cards['H'] = { 'J', '2', '5' };
   cards['C'] = { 'Q' };
   cards['D'] = { 'Q' };
   EXPECT_EQ(-1, checkRule4(cards));

   cards['S'] = { 'J' };
   cards['H'] = { 'J', '2' };
   cards['C'] = { 'J', '5', '6' };
   cards['D'] = { 'J' };
   EXPECT_EQ(-4, checkRule4(cards));

   cards['S'] = { 'Q', '3', '4' };
   cards['H'] = { 'K', '2' };
   cards['C'] = { '2' };
   cards['D'] = { 'J', '7', '8', 'T' };
   EXPECT_EQ(0, checkRule4(cards));
}

TEST(TestBridgeHandEvaluator, testCheckRule5)
{
   msc cards;
   cards['S'] = { 'J' };
   cards['H'] = { '2' };
   cards['C'] = { '2' };
   cards['D'] = { '2' };
   EXPECT_EQ(0, checkRule5(cards));

   cards['S'] = { 'K' };
   cards['H'] = { 'J', '2' };
   cards['C'] = { 'K' };
   cards['D'] = { 'K' };
   EXPECT_EQ(1, checkRule5(cards));

   cards['S'] = { 'Q' };
   cards['H'] = { 'J', '2' };
   cards['C'] = { 'Q', '6' };
   cards['D'] = { 'Q' };
   EXPECT_EQ(2, checkRule5(cards));

   cards['S'] = { 'J', '5' };
   cards['H'] = { 'J', '2' };
   cards['C'] = { 'J', '5' };
   cards['D'] = { 'J' };
   EXPECT_EQ(3, checkRule5(cards));

   cards['S'] = { 'J', '5' };
   cards['H'] = { 'J', '2' };
   cards['C'] = { 'J', '5' };
   cards['D'] = { 'J', 'T' };
   EXPECT_EQ(4, checkRule5(cards));

   cards['S'] = { 'Q', '3', '4' };
   cards['H'] = { 'K', '2' };
   cards['C'] = { '2' };
   cards['D'] = { 'J', '7', '8', 'T' };
   EXPECT_EQ(1, checkRule5(cards));
}

TEST(TestBridgeHandEvaluator, testCheckRule6)
{
   msc cards;
   cards['S'] = { 'J' };
   cards['H'] = { '2' };
   cards['C'] = { '2' };
   cards['D'] = { '2' };
   EXPECT_EQ(8, checkRule6(cards));

   cards['S'] = { 'K' };
   cards['H'] = { 'J', '2' };
   cards['C'] = { 'K' };
   cards['D'] = { 'K' };
   EXPECT_EQ(6, checkRule6(cards));

   cards['S'] = { 'Q' };
   cards['H'] = { 'J', '2' };
   cards['C'] = { 'Q', '6' };
   cards['D'] = { 'Q' };
   EXPECT_EQ(4, checkRule6(cards));

   cards['S'] = { 'J', '5' };
   cards['H'] = { 'J', '2' };
   cards['C'] = { 'J', '5' };
   cards['D'] = { 'J' };
   EXPECT_EQ(2, checkRule6(cards));

   cards['S'] = { 'J', '5' };
   cards['H'] = { 'J', '2' };
   cards['C'] = { 'J', '5' };
   cards['D'] = { 'J', 'T' };
   EXPECT_EQ(0, checkRule6(cards));

   cards['S'] = { 'Q', '3', '4' };
   cards['H'] = { 'K', '2' };
   cards['C'] = { '2' };
   cards['D'] = { 'J', '7', '8', 'T' };
   EXPECT_EQ(2, checkRule6(cards));
}

TEST(TestBridgeHandEvaluator, testCheckRule7)
{
   msc cards;
   cards['S'] = { };
   cards['H'] = { };
   cards['C'] = { };
   cards['D'] = { };
   EXPECT_EQ(8, checkRule7(cards));

   cards['S'] = { };
   cards['H'] = { 'J', '2' };
   cards['C'] = { };
   cards['D'] = { };
   EXPECT_EQ(6, checkRule7(cards));

   cards['S'] = { };
   cards['H'] = { 'J', '2' };
   cards['C'] = { 'Q', '6' };
   cards['D'] = { };
   EXPECT_EQ(4, checkRule7(cards));

   cards['S'] = { 'J', '5' };
   cards['H'] = { 'J', '2' };
   cards['C'] = { 'J', '5' };
   cards['D'] = { };
   EXPECT_EQ(2, checkRule7(cards));

   cards['S'] = { 'J', '5' };
   cards['H'] = { 'J', '2' };
   cards['C'] = { 'J', '5' };
   cards['D'] = { 'J', 'T' };
   EXPECT_EQ(0, checkRule7(cards));

   cards['S'] = { 'Q', '3', '4' };
   cards['H'] = { 'K', '2' };
   cards['C'] = { };
   cards['D'] = { 'J', '7', '8', 'T' };
   EXPECT_EQ(2, checkRule7(cards));
}

TEST(TestBridgeHandEvaluator, testBidSuit)
{
   msc cards;
   cards['S'] = { 'A' };
   cards['H'] = { 'A' };
   cards['C'] = { 'A' };
   cards['D'] = { 'A' };
   EXPECT_EQ("BID S", bidSuit(cards));

   cards['S'] = { };
   cards['H'] = { 'A' };
   cards['C'] = { 'A' };
   cards['D'] = { 'A' };
   EXPECT_EQ("BID H", bidSuit(cards));

   cards['S'] = { };
   cards['H'] = { };
   cards['C'] = { 'A' };
   cards['D'] = { 'A' };
   EXPECT_EQ("BID D", bidSuit(cards));

   cards['S'] = { };
   cards['H'] = { };
   cards['C'] = { 'A' };
   cards['D'] = { };
   EXPECT_EQ("BID C", bidSuit(cards));

   cards['S'] = { 'A' };
   cards['H'] = { 'A', '4' };
   cards['C'] = { 'A' };
   cards['D'] = { 'A' };
   EXPECT_EQ("BID H", bidSuit(cards));

   cards['S'] = { 'A' };
   cards['H'] = { 'A', '4' };
   cards['C'] = { 'A', '5', '7' };
   cards['D'] = { 'A' };
   EXPECT_EQ("BID C", bidSuit(cards));

   cards['S'] = { 'A' };
   cards['H'] = { 'A', '4' };
   cards['C'] = { 'A' };
   cards['D'] = { 'A', '5', '7' };
   EXPECT_EQ("BID D", bidSuit(cards));
}