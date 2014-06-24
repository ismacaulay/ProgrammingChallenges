
#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<double> vd;

void addDepreciation(vd& depreciations, int month, 
                     double lastDepreciation, double newDepreciation);
string determineNumberOfMonthsUntilOweLessThanValue(double owed, double value, 
                                                    double payment, vd depreciations);

#ifdef ONLINE_JUDGE
int main()
{
   while(1)
   {
      int duration, numRecords;
      double downPayment, amount;
      cin >> duration >> downPayment >> amount >> numRecords;

      if(duration < 0)
      {
         break;
      }

      double monthlyPayment = amount / duration;
      
      vd depreciations;
      double lastDepreciation = 0;
      for(int i = 0; i < numRecords; i++)
      {
         int month;
         double depreciation;
         cin >> month >> depreciation;

         addDepreciation(depreciations, month, lastDepreciation, depreciation);
         lastDepreciation = depreciation;
      }

      int initialValue = amount + downPayment;
      cout << determineNumberOfMonthsUntilOweLessThanValue(amount, initialValue, monthlyPayment, depreciations) << endl;
   }

   return 0;
}
#endif

void addDepreciation(vd& depreciations, int month, 
                     double lastDepreciation, double newDepreciation)
{
   while(depreciations.size() < month)
   {
      depreciations.push_back(lastDepreciation);
   }
   depreciations.push_back(newDepreciation);
}

string determineNumberOfMonthsUntilOweLessThanValue(double owed, double value, 
                                                    double payment, vd depreciations)
{
   int months = 0;
   value *= (1 - depreciations[0]);
   while(value < owed)
   {
      months++;
      double depreciation;
      if(months >= depreciations.size())
      {
         depreciation = depreciations[depreciations.size() - 1];
      }
      else
      {
         depreciation = depreciations[months];
      }

      value *= (1.0 - depreciation);
      owed -= payment;
   }

   if(months == 1)
   {
      return "1 month";
   }

   return to_string(months) + " months";
}
