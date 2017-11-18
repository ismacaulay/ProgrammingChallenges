
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef std::vector<int> vi;

#ifdef ONLINE_JUDGE
int main()
{
   int cases;
   cin >> cases;

   for(int c = 1; c <= cases; c++)
   {
      int numCreatures;
      cin >> numCreatures;

      vi creatureSpeeds;
      for (int i = 0; i < numCreatures; ++i)
      {
         int speed;
         cin >> speed;
         creatureSpeeds.push_back(speed); 
      }

      sort(creatureSpeeds.begin(), creatureSpeeds.end());

      cout << "Case " << c << ": " << creatureSpeeds.back() << endl;
   }
   return 0;
}
#endif
