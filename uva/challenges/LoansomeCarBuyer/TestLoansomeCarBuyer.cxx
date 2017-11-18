
#include <gtest/gtest.h>
#include "LoansomeCarBuyer.h"

TEST(TestLoansomeCarBuyer, testAddDepreciation)
{
   vd depreciations;
   vd expectedDepreciations = { 0.1 };

   addDepreciation(depreciations, 0, 0, 0.1);
   EXPECT_EQ(expectedDepreciations, depreciations);

   expectedDepreciations = { 0.1, 0.2 };
   addDepreciation(depreciations, 1, 0.1, 0.2);
   EXPECT_EQ(expectedDepreciations, depreciations);

   addDepreciation(depreciations, 3, 0.2, 0.3);
   expectedDepreciations = { 0.1, 0.2, 0.2, 0.3 };
   EXPECT_EQ(expectedDepreciations, depreciations);
   
   addDepreciation(depreciations, 7, 0.3, 0.002);
   expectedDepreciations = { 0.1, 0.2, 0.2, 0.3, 0.3, 0.3, 0.3, 0.002 };
   EXPECT_EQ(expectedDepreciations, depreciations);
}

TEST(TestLoansomeCarBuyer, testSampleInput)
{
   vd depreciations;
   addDepreciation(depreciations, 0, 0, 0.10);
   addDepreciation(depreciations, 1, 0.10, 0.03);
   addDepreciation(depreciations, 3, 0.03, 0.002);

   EXPECT_EQ(determineNumberOfMonthsUntilOweLessThanValue(15000.0, 15500.0, 500.0, depreciations),
            "4 months");


   depreciations.clear();
   addDepreciation(depreciations, 0, 0, 0.05);
   addDepreciation(depreciations, 2, 0.05, 0.1);

   EXPECT_EQ(determineNumberOfMonthsUntilOweLessThanValue(9999.99, 10499.99, 833.3325, depreciations),
            "1 month");

   depreciations.clear();
   addDepreciation(depreciations, 0, 0, 0.2);
   addDepreciation(depreciations, 1, 0.2, 0.05);
   addDepreciation(depreciations, 12, 0.05, 0.025);

   EXPECT_EQ(determineNumberOfMonthsUntilOweLessThanValue(30000.0, 32400.0, 500.0, depreciations),
            "49 months");

   depreciations.clear();
   addDepreciation(depreciations, 0, 0, 0.9);
   EXPECT_EQ(determineNumberOfMonthsUntilOweLessThanValue(1, 1000.0, 500.0, depreciations),
            "0 months");
}