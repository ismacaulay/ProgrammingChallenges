
#include <iostream>
#include <climits>

using namespace std;

#ifdef ONLINE_JUDGE
int main()
{
   int numPeople, budget, numHotels, numWeekends;
   while(cin >> numPeople >> budget >> numHotels >> numWeekends)
   {
      int cost = INT_MAX;
      for (int i = 0; i < numHotels; ++i)
      {
         int amountPerPerson;
         cin >> amountPerPerson;

         int weekendCost = amountPerPerson * numPeople;
         if((weekendCost > budget) || (weekendCost > cost))
         {
            string tmp;
            getline(cin, tmp); // Get remainder of amountPerPerson line
            getline(cin, tmp); // Get next line
         }
         else
         {
            for (int j = 0; j < numWeekends; ++j)
            {
               int numBeds;
               cin >> numBeds;

               if(numBeds >= numPeople)
               {
                  cost = weekendCost;
                  string tmp;
                  getline(cin, tmp); // Found a weekend, so dump the rest of the line
                  break;
               }
            }
         }
      }

      if(cost == INT_MAX)
      {
         cout << "stay home" << endl;
      }
      else
      {
         cout << cost << endl;
      }
   }

   return 0;
}
#endif
