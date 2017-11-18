
#include <iostream>

using namespace std;

#ifdef ONLINE_JUDGE
int main()
{
   int numInputs;
   cin >> numInputs;

   for(int i = 0; i < numInputs; i++)
   {
      int first, second;
      cin >> first >> second;

      if(first == second)
      {
         cout << "=" << endl;
      }
      else if(first < second)
      {
         cout << "<" << endl;
      }
      else
      {
         cout << ">" << endl;
      }
   }

   return 0;
}
#endif
