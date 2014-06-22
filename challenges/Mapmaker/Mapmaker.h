
#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

typedef vector<int> vi;

int calculateConstant(int nextConstant, int lowerBound, int upperBound);
int calculateInitialConstant(int base, vi constants, vi lowerBounds);
int calculateAddress(vi constants, vi indexes);

struct Array
{
   string name;
   vi constants;
};

#ifdef ONLINE_JUDGE
int main()
{
   int numArrays, numReferences;
   cin >> numArrays >> numReferences;

   map<string, Array> arrays;
   for(int i = 0; i < numArrays; i++)
   {
      Array a;
      cin >> a.name;

      int base, elementSize, dimensions;
      cin >> base >> elementSize >> dimensions;


      vi lowers, uppers;
      int lower, upper;
      for(int i = 0; i < dimensions; i++)
      {
         cin >> lower >> upper;

         lowers.push_back(lower);
         uppers.push_back(upper);
      }
 
      a.constants.push_back(elementSize);
      for(int i = lowers.size()-2; i >= 0; i--)
      {
         a.constants.insert(a.constants.begin(), 
                            calculateConstant(a.constants[0], 
                                              lowers[i+1], 
                                              uppers[i+1]));
      }

      a.constants.insert(a.constants.begin(), 
                         calculateInitialConstant(base, 
                                                  a.constants, 
                                                  lowers));
      arrays[a.name] = a;
   }

   for(int i = 0; i < numReferences; i++)
   {
      string name;
      cin >> name;

      Array a = arrays[name];
      vi indexes;
      for(int i = 0; i < a.constants.size()-1; i++)
      {
         int index;
         cin >> index;
         indexes.push_back(index);
      }

      cout << name << "[";
      for(int i = 0; i < indexes.size(); i++)
      {
         cout << indexes[i];
         if(i != indexes.size() - 1)
         {
            cout << ", ";
         }
      }
      cout << "] = " << calculateAddress(a.constants, indexes) << endl;
   }

   return 0;
}
#endif

int calculateConstant(int nextConstant, int lowerBound, int upperBound)
{
   return (nextConstant * (upperBound - lowerBound + 1));
}

int calculateInitialConstant(int base, vi constants, vi lowerBounds)
{
   int value = base;
   for(int i = 0; i < constants.size(); i++)
   {
      value -= (constants[i] * lowerBounds[i]);
   }

   return value;
}

int calculateAddress(vi constants, vi indexes)
{
   int value = constants[0];
   for(int i = 0; i < indexes.size(); i++)
   {
      value += (constants[i+1] * indexes[i]);
   }

   return value;
}